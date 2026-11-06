#include "Matrix.h"
#include <cmath>
#include <iomanip>

double Matrix::determinant(const Matrix& matrix, size_t size)
{
	if (size == 1) return matrix.elements[0][0];
	double d = 0;
	Matrix sub_m(matrix.row, matrix.col);
	if (size == 2) {
		return matrix.elements[0][0] * matrix.elements[1][1] - matrix.elements[0][1] * matrix.elements[1][0];
	}
	for (size_t x = 0; x < size; x++) {
		size_t sub_i = 0;
		for (size_t i = 1; i < size; i++) {
			size_t sub_j = 0;
			for (size_t j = 0; j < size; j++) {
				if (j == x) continue;
				sub_m.elements[sub_i][sub_j] = matrix.elements[i][j];
				sub_j++;
			}
			sub_i++;
		}
		d = d + std::pow(-1, x) * matrix.elements[0][x] * determinant(sub_m, size - 1);
	}
	return d;
}

Matrix::Matrix()
{
	row = 2;
	col = 2;
	elements = new double* [row];
	for (size_t i = 0; i < row; i++) {
		elements[i] = new double [col] {};
	}
}

Matrix::Matrix(size_t rows, size_t columns, double fill)
{
	row = rows;
	col = columns;
	elements = new double* [row];
	for (size_t i = 0; i < row; i++) {
		elements[i] = new double [col] {};
		for (size_t j = 0; j < col; j++) {
			elements[i][j] = fill;
		}
	}
}

Matrix::Matrix(const Matrix& m)
{
	row = m.row;
	col = m.col;
	elements = new double* [row];
	for (size_t i = 0; i < row; i++) {
		elements[i] = new double [col] {};
		for (size_t j = 0; j < col; j++) {
			elements[i][j] = m.elements[i][j];
		}
	}
}

Matrix::~Matrix()
{
	if (elements) {
		for (size_t i = 0; i < row; i++)
			delete[] elements[i];

		delete[] elements;
		elements = nullptr;
	}
}

size_t Matrix::size(const Matrix& m, size_t dim)
{
	if (dim == 1) return m.row;
	if (dim == 2) return m.col;
}

Matrix Matrix::transpose(const Matrix& m)
{
	Matrix mat(m.col, m.row);
	for (size_t i = 0; i < m.row; i++) {
		for (size_t j = 0; j < m.col; j++)
			mat.elements[j][i] = m.elements[i][j];
	}
	return mat;
}

double Matrix::det(const Matrix& m)
{
	if (m.row == 1) {
		return m.elements[0][0];
	}
	return determinant(m, m.row);
}

Matrix Matrix::inv(const Matrix& m)
{
	if (m.row != m.col) throw std::invalid_argument("Matrix must be square");

	size_t n = m.row;

	double det = determinant(m, n);
	if (std::abs(det) < 1e-9) throw std::runtime_error("det = 0, there no inverted matrix");

	if (n == 1) {
		Matrix result(1, 1);
		result.elements[0][0] = 1.0 / m.elements[0][0];
		return result;
	}

	Matrix inverse_m(n, n);
	Matrix sub_m(n, n);

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			size_t sub_i = 0;
			for (size_t r = 0; r < n; r++) {
				if (r == i) continue;

				size_t sub_j = 0;
				for (size_t c = 0; c < n; c++) {
					if (c == j) continue;

					sub_m.elements[sub_i][sub_j] = m.elements[r][c];
					sub_j++;
				}
				sub_i++;
			}

			double adj_element = std::pow(-1, i + j) * determinant(sub_m, n - 1);
			inverse_m.elements[j][i] = adj_element / det;
		}
	}
	return inverse_m;
}

Matrix Matrix::mult(const Matrix& m1, const Matrix& m2)
{
	if (m1.col != m2.row) throw std::invalid_argument("Invalid dimensions for matrix multiplication");
	Matrix result(m1.row, m2.col);
	for (size_t i = 0; i < m1.row; i++) {
		for (size_t j = 0; j < m2.col; j++) {
			for (size_t k = 0; k < m1.col; k++) {
				result.elements[i][j] += m1.elements[i][k] * m2.elements[k][j];
			}
		}
	}
	return result;
}

Matrix Matrix::operator+(const Matrix& m)
{
	if (row != m.row || col != m.col) throw std::invalid_argument("Dimensions mismatch for addition");
	Matrix result(row, col);
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			result.elements[i][j] = elements[i][j] + m.elements[i][j];
	return result;
}

Matrix Matrix::operator-(const Matrix& m)
{
	if (row != m.row || col != m.col) throw std::invalid_argument("Dimensions mismatch for subtraction");
	Matrix result(row, col);
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			result.elements[i][j] = elements[i][j] - m.elements[i][j];
	return result;
}

Matrix Matrix::operator*(const Matrix& m)
{
	if (row != m.row || col != m.col) throw std::invalid_argument("Dimensions mismatch for multiplication");
	Matrix result(row, col);
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			result.elements[i][j] = elements[i][j] * m.elements[i][j];
	return result;
}

Matrix Matrix::operator/(const Matrix& m)
{
	if (row != m.row || col != m.col) throw std::invalid_argument("Dimensions mismatch for  division");
	Matrix result(row, col);
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			if (m.elements[i][j] == 0) throw std::runtime_error("Division by zero");
			result.elements[i][j] = elements[i][j] / m.elements[i][j];
		}
	}
	return result;
}

double& Matrix::operator[](size_t ind)
{
	if (ind >= row * col) throw std::out_of_range("INdex out of range");
	return elements[ind / col][ind % col];
}

const double& Matrix::operator[](size_t ind) const
{
	if (ind >= row * col) throw std::out_of_range("Index out of range");
	return elements[ind / col][ind % col];
}

std::istream& operator>>(std::istream& in, Matrix& m)
{
	for (size_t i = 0; i < m.col; i++)
	{
		for (size_t j = 0; j < m.row; j++)
		{
			in >> m.elements[i][j];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
	for (size_t i = 0; i < m.col; i++)
	{
		for (size_t j = 0; j < m.row; j++)
		{
			out << std::setw(12) << m.elements[i][j];
		}
		out << std::endl;
	}
	return out;
}
