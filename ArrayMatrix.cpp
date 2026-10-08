/*
How the Single-Index Hack Works

When you write mat[r][c], the compiler parses it from
left to right as (mat[r])[c].mat[r] triggers your
overloaded operator[](size_t row), which performs
bounds checking on the row and returns a memory address
(T*) pointing exactly to the first element of that row.
The remaining [c] evaluates natively against that
returned pointer using standard C++ pointer arithmetic
(pointer + c), shifting right to the correct column.
Note: While elegant, a downside to this raw-pointer
method is that the secondary [c] step bypasses your
class logic, meaning column-level bounds checking cannot
be safely handled at runtime.
*/
//Name : Jesus Resendiz
// section : CS210-05
//Date: October 8, 2026
#include "ArrayMatrix.h"
#include <iostream>
int main() {
    // TODO: Create matrices to demonstrate use of ALL
    //       methods in ArrayMatrix class.
    try {
        ArrayMatrix<int> mat1(2, 3, 0);

        mat1[0][0] = 1;
        mat1[0][1] = 2;
        mat1[0][2] = 3;

        mat1[1][0] = 4;
        mat1[1][1] = 5;
        mat1[1][2] = 6;

        std::cout << "Matrix 1:\n";
        mat1.print();

         // 2 rows and columns 
        std::cout << "\nRows: " << mat1.rows() << "\n";
        std::cout << "Columns: " << mat1.cols() << "\n";

         // 3.  This is the copy constructor
        ArrayMatrix<int> copiedMatrix(mat1);

        std::cout << "Copy:\n";
        copiedMatrix.print();

        // 4. this is the copy assignment operator
        ArrayMatrix<int> assignedMatrix(2, 3);
        assignedMatrix = mat1;

        std::cout << "Assigned matrix:\n";
        assignedMatrix.print();

        // 5. this is the constant version of operator[]
        const ArrayMatrix<int>& readOnlyMatrix = mat1;

        std::cout << "Value from constant matrix: ";
        std::cout << readOnlyMatrix[0][1] << "\n";

           // 6. this is the matrix addition
        ArrayMatrix<int> sum = mat1 + copiedMatrix;
        

        std::cout << "Addition result:\n";
        sum.print();

        // 7. this is the matrix multiplication
        ArrayMatrix<int> leftMatrix(2, 3);

        leftMatrix[0][0] = 1;
        leftMatrix[0][1] = 2;
        leftMatrix[0][2] = 3;
        leftMatrix[1][0] = 4;
        leftMatrix[1][1] = 5;
        leftMatrix[1][2] = 6;

        ArrayMatrix<int> rightMatrix(3, 2);

        rightMatrix[0][0] = 1;
        rightMatrix[0][1] = 2;
        rightMatrix[1][0] = 3;
        rightMatrix[1][1] = 4;
        rightMatrix[2][0] = 5;
        rightMatrix[2][1] = 6;

        ArrayMatrix<int> product = leftMatrix * rightMatrix;

        std::cout << "Multiplication result:\n";
        product.print();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Use streams to init and output
    // Create a 2x3 matrix for user input
    ArrayMatrix<int> mat(2, 3);

    // Prompt user input using standard stream extraction (cin)
    std::cout << "Enter 6 integer values for a 2x3 matrix (separated by spaces or newlines):\n";
    // TODO: cin statement
    std::cin >> mat;

    // Output the matrix formatting cleanly via custom insertion stream
    std::cout << "\nYou entered the following matrix:\n";
    // TODO: cout statement
    std::cout << mat;

    return 0;
}
