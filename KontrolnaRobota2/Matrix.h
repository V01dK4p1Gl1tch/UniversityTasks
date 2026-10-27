#pragma once
#include <iostream>

class Matrix {
private:
	size_t row;
	size_t col;
	double** elements;

	static double determinant(const Matrix& matrix, size_t size);

public:

	Matrix();
	Matrix(size_t rows, size_t columns, double fill = 0.0);
	Matrix(const Matrix& m);
	~Matrix();
	static size_t size(const Matrix& m, size_t dim);
	static Matrix transpose(const Matrix& m);
	static double det(const Matrix& m);
	static Matrix inv(const Matrix& m);
	static Matrix mult(const Matrix& m1, const Matrix& m2);

	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix operator/(const Matrix& m);

	double& operator[](size_t ind);
	const double& operator[](size_t ind) const;

	friend std::istream& operator>>(std::istream& in, Matrix& m);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
};