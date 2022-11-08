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
// deepy copy consuctor
polynomial::polynomial(const polynomial &poly)
{
    this->degree = poly.degree;
    this->polyExpr = poly.polyExpr;
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