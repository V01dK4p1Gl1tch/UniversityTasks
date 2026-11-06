#include <iostream>
#include <iomanip>
#include "Matrix.h"

int main()
{
    std::cout << std::fixed << std::setprecision(4);

    try {
        // ==========================================
        // 2x2 Matrix Section
        // ==========================================
        std::cout << "--- 2x2 Matrix Section ---" << std::endl;
        Matrix matrix2x2(2, 2);
        std::cout << "Enter 4 elements for 2x2 matrix:" << std::endl;
        std::cin >> matrix2x2;
        std::cout << "Original 2x2 matrix:\n" << matrix2x2 << std::endl;

        std::cout << "Determinant:" << std::endl;
        std::cout << Matrix::det(matrix2x2) << std::endl << std::endl;

        std::cout << "Rows: " << Matrix::size(matrix2x2, 1)
            << ", Cols: " << Matrix::size(matrix2x2, 2) << std::endl << std::endl;

        std::cout << "Addition (+):" << std::endl;
        std::cout << (matrix2x2 + matrix2x2) << std::endl;

        std::cout << "Subtraction (-):" << std::endl;
        std::cout << (matrix2x2 - matrix2x2) << std::endl;

        std::cout << "Multiplication (*):" << std::endl;
        std::cout << (matrix2x2 * matrix2x2) << std::endl;

        std::cout << "Division (/):" << std::endl;
        std::cout << (matrix2x2 / matrix2x2) << std::endl;

        std::cout << "Element at index 3:" << std::endl;
        std::cout << matrix2x2[3] << std::endl << std::endl;

        std::cout << "Transpose:" << std::endl;
        Matrix trans2x2 = Matrix::transpose(matrix2x2);
        std::cout << trans2x2 << std::endl;

        std::cout << "Inverse matrix:" << std::endl;
        Matrix inv2x2 = Matrix::inv(matrix2x2);
        std::cout << inv2x2 << std::endl;

        std::cout << "Mathematical multiplication (A * A^-1):" << std::endl;
        Matrix mult2x2 = Matrix::mult(matrix2x2, inv2x2);
        std::cout << mult2x2 << std::endl;


        // ==========================================
        // 3x3 Matrix Section
        // ==========================================
        std::cout << "--- 3x3 Matrix Section ---" << std::endl;
        Matrix matrix3x3(3, 3);
        std::cout << "Enter 9 elements for 3x3 matrix:" << std::endl;
        std::cin >> matrix3x3;
        std::cout << "Original 3x3 matrix:\n" << matrix3x3 << std::endl;

        std::cout << "Determinant:" << std::endl;
        std::cout << Matrix::det(matrix3x3) << std::endl << std::endl;

        std::cout << "Transpose:" << std::endl;
        Matrix trans3x3 = Matrix::transpose(matrix3x3);
        std::cout << trans3x3 << std::endl;

        std::cout << "Inverse matrix:" << std::endl;
        Matrix inv3x3 = Matrix::inv(matrix3x3);
        std::cout << inv3x3 << std::endl;

        std::cout << "Mathematical multiplication (A * A^-1):" << std::endl;
        Matrix mult3x3 = Matrix::mult(matrix3x3, inv3x3);
        std::cout << mult3x3 << std::endl;


        // ==========================================
        // 4x4 Matrix Section
        // ==========================================
        std::cout << "--- 4x4 Matrix Section ---" << std::endl;
        Matrix matrix4x4(4, 4);
        std::cout << "Enter 16 elements for 4x4 matrix:" << std::endl;
        std::cin >> matrix4x4;
        std::cout << "Original 4x4 matrix:\n" << matrix4x4 << std::endl;

        std::cout << "Determinant:" << std::endl;
        std::cout << Matrix::det(matrix4x4) << std::endl << std::endl;

        std::cout << "Transpose:" << std::endl;
        Matrix trans4x4 = Matrix::transpose(matrix4x4);
        std::cout << trans4x4 << std::endl;

        std::cout << "Inverse matrix:" << std::endl;
        Matrix inv4x4 = Matrix::inv(matrix4x4);
        std::cout << inv4x4 << std::endl;

        std::cout << "Mathematical multiplication (A * A^-1):" << std::endl;
        Matrix mult4x4 = Matrix::mult(matrix4x4, inv4x4);
        std::cout << mult4x4 << std::endl;

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}