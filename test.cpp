#include <iostream>
#include "polynomial.h"

int main()
{
    int p1[] = {3, 2, 5, -2};
    int p2[] = {6, -2, 8};

    polynomial poly1(p1, 3);
    polynomial poly2(p2, 2);
    polynomial result;

    result = poly1 * poly2;
    std::cout << "result = " << result << "\n";

    return 0;
}