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
    for (int i = 0; i < this->degree; i++)
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
    delete this->polyExpr;
    this->polyExpr = new int[1];
    this->polyExpr[0] = s;
}

polynomial::~polynomial()
{
}

polynomial polynomial::operator*(const polynomial &rhs) const
{
    polynomial result;
    result.degree = this->degree + rhs.degree;
    result.polyExpr = new int[this->degree + rhs.degree + 1];
    // foil
    for (int i = 0; i < this->degree; i++)
    {
        for (int j = 0; j < rhs.degree; j++)
        {
            result.polyExpr[j] += this->polyExpr[i] * rhs.polyExpr[j];
        }
    }
    for (int i = 0; i < result.degree; i++)
    {
        std::cout << result.polyExpr[i] << '\n';
    }
}

polynomial polynomial::operator*(int rhs) const
{
}

polynomial polynomial::operator+(const polynomial &rhs) const
{
}

polynomial polynomial::operator+(int rhs) const
{
}

const polynomial &polynomial::operator=(const polynomial &rhs)
{
}

const polynomial &polynomial::operator=(int rhs)
{
}

polynomial polynomial::operator-() const
{
}

polynomial polynomial::operator-(const polynomial &rhs) const
{
}

polynomial polynomial::operator-(int rhs) const
{
}

std::ostream &operator<<(std::ostream &out, const polynomial &rhs)
{
    for (int i = 0; i < rhs.degree; i++)
    {
        out << rhs.polyExpr[rhs.degree - i] << "x^" << rhs.degree << " ";
    }
    return out;
}

polynomial operator+(int lhs, const polynomial &rhs)
{
}

polynomial operator*(int lhs, const polynomial &rhs)
{
}

polynomial operator-(int lhs, const polynomial &rhs)
{
}