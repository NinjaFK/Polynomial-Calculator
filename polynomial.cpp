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

polynomial::~polynomial()
{
    delete[] polyExpr;
}

polynomial polynomial::operator*(const polynomial &rhs) const
{
    polynomial result;
    result.degree = this->degree + rhs.degree;
    result.polyExpr = new int[result.degree + 1];
    for (int i = 0; i < result.degree + 1; i++)
    {
        result.polyExpr[i] = 0;
    }
    // foil
    for (int i = 0; i < this->degree + 1; i++)
    {
        for (int j = 0; j < rhs.degree + 1; j++)
        {
            result.polyExpr[i + j] += this->polyExpr[i] * rhs.polyExpr[j];
        }
    }
    return result;
}

polynomial polynomial::operator*(int rhs) const
{
    polynomial result;
    result.degree = this->degree;
    result.polyExpr = new int[this->degree + 1];
    result = this->operator*(polynomial(rhs));
    return result;
}

polynomial polynomial::operator+(const polynomial &rhs) const
{
    polynomial result;
    if (this->degree > rhs.degree)
    {
        result.degree = this->degree;
    }
    else
    {
        result.degree = rhs.degree;
    }
    result.polyExpr = new int[result.degree + 1];
    for (int i = 0; i < result.degree + 1; i++)
    {
        result.polyExpr[i] = 0;
    }
    // two for loops
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

polynomial polynomial::operator+(int rhs) const
{
    polynomial result;
    result.degree = this->degree;
    result.polyExpr = new int[this->degree + 1];
    result = this->operator+(polynomial(rhs));
    return result;
}

const polynomial &polynomial::operator=(const polynomial &rhs)
{
    this->degree = rhs.degree;
    if (this->polyExpr != nullptr)
    {
        delete[] this->polyExpr;
    }
    this->polyExpr = new int[rhs.degree + 1];
    for (int i = 0; i < this->degree + 1; i++)
    {
        this->polyExpr[i] = rhs.polyExpr[i];
    }
    return *this;
}

const polynomial &polynomial::operator=(int rhs)
{
    this->degree = 0;
    this->polyExpr = new int[1];
    this->polyExpr[0] = rhs;
    return *this;
}

polynomial polynomial::operator-() const
{
    for (int i = 0; i < this->degree + 1; i++)
    {
        this->polyExpr[i] = this->polyExpr[i] * -1;
    }
    return *this;
}

polynomial polynomial::operator-(const polynomial &rhs) const
{
    polynomial result;
    if (this->degree > rhs.degree)
    {
        result.degree = this->degree;
    }
    else
    {
        result.degree = rhs.degree;
    }
    result.polyExpr = new int[result.degree + 1];
    for (int i = 0; i < result.degree + 1; i++)
    {
        result.polyExpr[i] = 0;
    }
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

polynomial polynomial::operator-(int rhs) const
{
    polynomial result;
    result.degree = this->degree;
    result.polyExpr = new int[this->degree + 1];
    result = this->operator-(polynomial(rhs));
    return result;
}

std::ostream &operator<<(std::ostream &out, const polynomial &rhs)
{
    if (abs(rhs.polyExpr[rhs.degree]) != 1 || rhs.degree == 0)
    {
        out << rhs.polyExpr[rhs.degree];
    }
    if (rhs.polyExpr[rhs.degree] == -1)
    {
        out << '-';
    }
    if (rhs.degree > 1)
    {
        out << "x^" << rhs.degree << " ";
    }
    if (rhs.degree == 1)
    {
        out << "x ";
    }
    for (int i = 1; i < rhs.degree + 1; i++)
    {
        // std::cout << "\nrhs poly: " << rhs.polyExpr[rhs.degree - i - 1] << "\n";
        if (rhs.polyExpr[rhs.degree - i] == 0)
        {
            continue;
        }
        if (rhs.polyExpr[rhs.degree - i] < 0)
        {
            out << "- ";
        }
        else
        {
            out << "+ ";
        }
        if (abs(rhs.polyExpr[rhs.degree - i]) != 1 || rhs.degree - i == 0)
        {
            out << abs(rhs.polyExpr[rhs.degree - i]);
        }
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

polynomial operator+(int lhs, const polynomial &rhs)
{
    return (polynomial(lhs)).operator+(rhs);
}

polynomial operator*(int lhs, const polynomial &rhs)
{
    return (polynomial(lhs)).operator*(rhs);
}

polynomial operator-(int lhs, const polynomial &rhs)
{
    return (polynomial(lhs)).operator-(rhs);
}