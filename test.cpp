#include <iostream>
#include "polynomial.h"

int main()
{
    int p1[] = {3, 2, 5, -2};
    int p2[] = {6, -2, 8};

    polynomial poly1(p1, 3);
    polynomial poly2(p2, 2);
    polynomial result;

    result = poly2 - 4;

    /* std::cout << "i: " << i << '\n';
            std::cout << "j: " << j << '\n';
            std::cout << "This poly " << this->polyExpr[i] << '\n';
            std::cout << "Rhs poly " << rhs.polyExpr[j] << '\n';
            std::cout << "Result :";
            for (int l = 0; l < result.degree + 1; l++)
            {
                std::cout << '[' << result.polyExpr[l] << "] ";
            }
            std::cout << '\n'
                      << '\n'; */
    std::cout << "result = " << result << "\n";

    return 0;
}