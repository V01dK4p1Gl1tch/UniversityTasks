#include "Matrix.h"
#include <cmath>

double Matrix::determinant(const Matrix& matrix, size_t size)
{
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
