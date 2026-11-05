#include <iostream>
#include "Matrix.h"

int main()
{
    try {
        Matrix matrix1(3, 3);
        std::cin >> matrix1;
        std::cout << matrix1;

        std::cout << std::endl;

        std::cout << Matrix::det(matrix1) << std::endl;
        std::cout << std::endl;
        std::cout << (matrix1 + matrix1) << std::endl;
        std::cout << std::endl;
        std::cout << (matrix1 / matrix1) << std::endl;
        std::cout << std::endl;
        std::cout << matrix1[3] << std::endl;
        std::cout << std::endl;
        return 0;
    }
    catch (const std::exception& e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}