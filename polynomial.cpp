/*
    Name: Brian Nieh, 5008139573, 1005, 6
    Description: Polynomial Calculator
    Input: polynomials in main to calculate polynomials
    Output: Result polynomial
*/
#include "polynomial.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
// normal constuctor set ptr to null and degree to -1
polynomial::polynomial()
{
    degree = -1;
    polyExpr = nullptr;
}
// deepy copy constuctor
polynomial::polynomial(const polynomial &poly)
{
    this->degree = poly.degree;
    this->polyExpr = new int[poly.degree];
    // for loop to deep copy each part
    for (int i = 0; i < this->degree + 1; i++)
    {
        this->polyExpr[i] = poly.polyExpr[i];
    }
}
// assign new poly to current
polynomial::polynomial(int *p, int degree)
{
    this->degree = degree;
    this->polyExpr = new int[degree + 1];
    // for loop to copy from the passed array
    for (int i = 0; i < degree + 1; i++)
    {
        this->polyExpr[i] = p[i];
    }
}
// reset poly degree and reset poly to s
polynomial::polynomial(int s)
{
    this->degree = 0;
    this->polyExpr = new int[1];
    this->polyExpr[0] = s;
}
// deallocate the array
polynomial::~polynomial()
{
    delete[] polyExpr;
}
// Polynomial multiplication with an polynomial
polynomial polynomial::operator*(const polynomial &rhs) const
{
    polynomial result;
    result.degree = this->degree + rhs.degree;
    result.polyExpr = new int[result.degree + 1];
    // for loop to set the array to zero
    for (int i = 0; i < result.degree + 1; i++)
    {
        result.polyExpr[i] = 0;
    }
    // foil
    for (int i = 0; i < this->degree + 1; i++)
    {
        for (int j = 0; j < rhs.degree + 1; j++)
        {
            // this addes it and moves up after it addeds the multipli of the coefficient
            result.polyExpr[i + j] += this->polyExpr[i] * rhs.polyExpr[j];
        }
    }
    return result;
}
// polynomail multiplication with an int
polynomial polynomial::operator*(int rhs) const
{
    polynomial result;
    result.degree = this->degree;
    result.polyExpr = new int[this->degree + 1];
    // call operator* with int as a polynomial
    result = this->operator*(polynomial(rhs));
    return result;
}
// addition with a polynomial
polynomial polynomial::operator+(const polynomial &rhs) const
{
    polynomial result;
    // changes the degree on the larger degree
    if (this->degree > rhs.degree)
    {
        result.degree = this->degree;
    }
    else
    {
        result.degree = rhs.degree;
    }
    result.polyExpr = new int[result.degree + 1];
    // for loop to set the array to zero
    for (int i = 0; i < result.degree + 1; i++)
    {
        result.polyExpr[i] = 0;
    }
    // These loops add each of the polynomials to result
    for (int i = 0; i < this->degree + 1; i++)
    {
        result.polyExpr[i] += this->polyExpr[i];
    }
    for (int i = 0; i < rhs.degree + 1; i++)
    {
        result.polyExpr[i] += rhs.polyExpr[i];
    }
    return result;
}
// addition with an int
polynomial polynomial::operator+(int rhs) const
{
    polynomial result;
    result.degree = this->degree;
    result.polyExpr = new int[this->degree + 1];
    // calls operator+ with the int as a polynomial
    result = this->operator+(polynomial(rhs));
    return result;
}
// sets the this to the rhs as deep copy
const polynomial &polynomial::operator=(const polynomial &rhs)
{
    this->degree = rhs.degree;
    // if polyExpr is not null dellalocate it
    if (this->polyExpr != nullptr)
    {
        delete[] this->polyExpr;
    }
    this->polyExpr = new int[rhs.degree + 1];
    // deep copy rhs to this
    for (int i = 0; i < this->degree + 1; i++)
    {
        this->polyExpr[i] = rhs.polyExpr[i];
    }
    return *this;
}
// set this to an int
const polynomial &polynomial::operator=(int rhs)
{
    this->degree = 0;
    this->polyExpr = new int[1];
    this->polyExpr[0] = rhs;
    return *this;
}
// flips the sign for each coefficient of the polynomia
polynomial polynomial::operator-() const
{
    for (int i = 0; i < this->degree + 1; i++)
    {
        this->polyExpr[i] = this->polyExpr[i] * -1;
    }
    return *this;
}
// implements the polynomial subtraction operator
polynomial polynomial::operator-(const polynomial &rhs) const
{
    polynomial result;
    // changes the degree on the larger degree
    if (this->degree > rhs.degree)
    {
        result.degree = this->degree;
    }
    else
    {
        result.degree = rhs.degree;
    }
    result.polyExpr = new int[result.degree + 1];
    // for loop to set the array to zero
    for (int i = 0; i < result.degree + 1; i++)
    {
        result.polyExpr[i] = 0;
    }
    // These loops add each of the polynomials to result
    for (int i = 0; i < this->degree + 1; i++)
    {
        result.polyExpr[i] += this->polyExpr[i];
    }
    for (int i = 0; i < rhs.degree + 1; i++)
    {
        result.polyExpr[i] -= rhs.polyExpr[i];
    }
    return result;
}
// implements the polynomial subtraction operator with an int
polynomial polynomial::operator-(int rhs) const
{
    polynomial result;
    result.degree = this->degree;
    result.polyExpr = new int[this->degree + 1];
    // calls the operator- with rhs as a polynomial
    result = this->operator-(polynomial(rhs));
    return result;
}
// output operator, outputs the
// polynomial in its natural form
std::ostream &operator<<(std::ostream &out, const polynomial &rhs)
{
    // prints first value if its not -1 or 1
    if (abs(rhs.polyExpr[rhs.degree]) != 1 || rhs.degree == 0)
    {
        out << rhs.polyExpr[rhs.degree];
    }
    // prints - if the first value is neg
    if (rhs.polyExpr[rhs.degree] == -1)
    {
        out << '-';
    }
    // prints the format based on its degree
    if (rhs.degree > 1)
    {
        out << "x^" << rhs.degree << " ";
    }
    if (rhs.degree == 1)
    {
        out << "x ";
    }
    // for loop for longer polynomial
    for (int i = 1; i < rhs.degree + 1; i++)
    {
        // checks if the coefficient is zero
        if (rhs.polyExpr[rhs.degree - i] == 0)
        {
            continue;
        }
        // print the sign
        if (rhs.polyExpr[rhs.degree - i] < 0)
        {
            out << "- ";
        }
        else
        {
            out << "+ ";
        }
        // print if coefficient not 1 or -1
        // or the degree is 0 (whole number)
        if (abs(rhs.polyExpr[rhs.degree - i]) != 1 || rhs.degree - i == 0)
        {
            out << abs(rhs.polyExpr[rhs.degree - i]);
        }
        // based on degree print what is needed
        if (rhs.degree - i > 1)
        {
            out << "x^" << rhs.degree - i << " ";
        }
        if (rhs.degree - i == 1)
        {
            out << "x ";
        }
    }
    return out;
}
// makes lhs a polynomial and use the appropriate operator
polynomial operator+(int lhs, const polynomial &rhs)
{
    return (polynomial(lhs)).operator+(rhs);
}
// makes lhs a polynomial and use the appropriate operator
polynomial operator*(int lhs, const polynomial &rhs)
{
    return (polynomial(lhs)).operator*(rhs);
}
// makes lhs a polynomial and use the appropriate operator
polynomial operator-(int lhs, const polynomial &rhs)
{
    return (polynomial(lhs)).operator-(rhs);
}