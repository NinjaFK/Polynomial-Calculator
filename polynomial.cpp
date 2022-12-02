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
    this->polyExpr = new node;
    node *temp = this->polyExpr;
    node *temp2 = poly.polyExpr;
    // this->polyExpr = new int[poly.degree];
    for (int i = 0; i < this->degree; i++)
    {
        temp->data = temp2->data;
        temp->link = new node;
        temp = temp->link;
        temp2 = temp2->link;
    }
    temp->data = temp2->data;
    temp->link = nullptr;
    delete temp;
    delete temp2;
}
// assign new poly to current
polynomial::polynomial(int *p, int degree)
{
    this->degree = degree;
    this->polyExpr = new node;
    node *temp = this->polyExpr;
    for (int i = 0; i < this->degree; i++)
    {
        temp->data = p[i];
        temp->link = new node;
        temp = temp->link;
    }
    temp->data = p[degree];
    temp->link = nullptr;
    temp = nullptr;
}
// reset poly degree and reset poly to s
polynomial::polynomial(int s)
{
    this->degree = 0;
    this->polyExpr = new node;
    this->polyExpr->data = s;
    this->polyExpr->link = nullptr;
}
// deallocate the array
polynomial::~polynomial()
{
    node *temp = polyExpr;
    while (temp != nullptr)
    {
        temp = temp->link;
        delete polyExpr;
        polyExpr = temp;
    }
}
// Polynomial multiplication with an polynomial
polynomial polynomial::operator*(const polynomial &rhs) const
{
    polynomial result;
    result.degree = this->degree + rhs.degree;
    node *temp = this->polyExpr;
    node *temp2 = this->polyExpr;
    node *temp3 = rhs.polyExpr;

    if (result.polyExpr != nullptr)
    {
        while (temp != nullptr)
        {
            temp->data = 0;
            temp = temp->link;
        }
    }
    else
    {
        result.polyExpr = new node;
        temp = result.polyExpr;
        for (int i = 0; i < result.degree; i++)
        {
            temp->data = 0;
            temp->link = new node;
            temp = temp->link;
        }
        temp->data = 0;
        temp->link = nullptr;
    }

    temp = result.polyExpr;
    temp2 = this->polyExpr;

    for (int i = 0; i < this->degree + 1; i++)
    {
        for (int l = 0; l < i; l++)
        {
            temp = temp->link;
        }
        for (int j = 0; j < rhs.degree + 1; j++)
        {
            temp->data += temp2->data * temp3->data;
            temp3 = temp3->link;
            temp = temp->link;
        }
        temp3 = rhs.polyExpr;
        temp2 = temp2->link;
        temp = result.polyExpr;
    }
    return result;
}
// polynomail multiplication with an int
polynomial polynomial::operator*(int rhs) const
{
    return this->operator*(polynomial(rhs));
}
// addition with a polynomial
polynomial polynomial::operator+(const polynomial &rhs) const
{
    polynomial result;
    node *temp = this->polyExpr;
    node *temp2 = this->polyExpr;
    node *temp3 = rhs.polyExpr;
    // changes the degree on the larger degree
    if (this->degree > rhs.degree)
    {
        result.degree = this->degree;
    }
    else
    {
        result.degree = rhs.degree;
    }

    if (result.polyExpr != nullptr)
    {
        while (temp != nullptr)
        {
            temp->data = 0;
            temp = temp->link;
        }
    }
    else
    {
        result.polyExpr = new node;
        temp = result.polyExpr;
        for (int i = 0; i < result.degree; i++)
        {
            temp->data = 0;
            temp->link = new node;
            temp = temp->link;
        }
        temp->data = 0;
        temp->link = nullptr;
    }
    temp = result.polyExpr;
    temp2 = this->polyExpr;
    for (int i = 0; i < this->degree + 1; i++)
    {
        temp->data += temp2->data;
        temp = temp->link;
        temp2 = temp2->link;
    }
    temp = result.polyExpr;
    for (int i = 0; i < rhs.degree + 1; i++)
    {
        temp->data += temp3->data;
        temp = temp->link;
        temp3 = temp3->link;
    }
    return result;
}
// addition with an int
polynomial polynomial::operator+(int rhs) const
{
    return this->operator+(polynomial(rhs));
}
// sets the this to the rhs as deep copy
const polynomial &polynomial::operator=(const polynomial &rhs)
{
    this->degree = rhs.degree;
    node *temp = this->polyExpr;
    node *temp2 = this->polyExpr;
    // if polyExpr is not null dellalocate it
    if (this->polyExpr != nullptr)
    {
        while (temp != nullptr)
        {
            temp = temp->link;
            delete temp2;
            temp2 = temp;
        }
    }

    this->polyExpr = new node;
    temp = this->polyExpr;
    temp2 = rhs.polyExpr;
    // this->polyExpr = new int[poly.degree];
    for (int i = 0; i < this->degree; i++)
    {
        temp->data = temp2->data;
        temp->link = new node;
        temp = temp->link;
        temp2 = temp2->link;
    }
    temp->data = temp2->data;
    temp->link = nullptr;
    temp = nullptr;
    temp2 = nullptr;
    return *this;
}
// set this to an int
const polynomial &polynomial::operator=(int rhs)
{
    this->degree = 0;
    this->polyExpr = new node;
    this->polyExpr->data = rhs;
    this->polyExpr->link = nullptr;
    return *this;
}
// flips the sign for each coefficient of the polynomia
polynomial polynomial::operator-() const
{
    polynomial result;
    result.degree = this->degree;
    result.polyExpr = new node;
    node *temp = this->polyExpr;
    node *temp2 = result.polyExpr;
    while (temp->link != nullptr)
    {
        temp2->data = temp->data * -1;
        temp2->link = new node;
        temp2 = temp2->link;
        temp = temp->link;
    }
    temp2->data = temp->data * -1;
    temp2->link = nullptr;
    temp = nullptr;
    temp2 = nullptr;
    return result;
}
// implements the polynomial subtraction operator
polynomial polynomial::operator-(const polynomial &rhs) const
{
    return this->operator+(-rhs);
}
// implements the polynomial subtraction operator with an int
polynomial polynomial::operator-(int rhs) const
{
    return this->operator-(polynomial(rhs));
}
// output operator, outputs the
// polynomial in its natural form
std::ostream &operator<<(std::ostream &out, const polynomial &rhs)
{
    node *temp = rhs.polyExpr;
    while (temp->link != nullptr)
    {
        temp = temp->link;
    }
    if (abs(temp->data) != 1 || rhs.degree == 0)
    {
        out << temp->data;
    }
    if (rhs.degree > 1)
    {
        out << "x^" << rhs.degree << " ";
    }
    if (rhs.degree == 1)
    {
        out << "x ";
    }

    // for loop
    for (int i = 1; i < rhs.degree + 1; i++)
    {
        temp = rhs.polyExpr;
        for (int j = i; j < rhs.degree; j++)
        {
            temp = temp->link;
        }
        if (temp->data == 0)
        {
            continue;
        }
        else if (temp->data < 0)
        {
            out << "- ";
        }
        else
        {
            out << "+ ";
        }
        if (abs(temp->data) != 1 || rhs.degree - i == 0)
        {
            out << abs(temp->data);
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
// makes lhs a polynomial and use the appropriate operator
polynomial operator+(int lhs, const polynomial &rhs)
{
    return rhs + lhs;
}
// makes lhs a polynomial and use the appropriate operator
polynomial operator*(int lhs, const polynomial &rhs)
{
    return rhs * lhs;
}
// makes lhs a polynomial and use the appropriate operator
polynomial operator-(int lhs, const polynomial &rhs)
{
    return -rhs + lhs;
}