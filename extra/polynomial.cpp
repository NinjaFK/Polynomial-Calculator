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
    head = nullptr;
}
// deepy copy constuctor
polynomial::polynomial(const polynomial &poly)
{
    this->degree = poly.degree;
    this->head = new node;
    node *temp = this->head;
    node *temp2 = poly.head;
    // this->head = new int[poly.degree];
    for (int i = 0; i < this->degree; i++)
    {
        temp->coefficient = temp2->coefficient;
        temp->link = new node;
        temp = temp->link;
        temp2 = temp2->link;
    }
    temp->coefficient = temp2->coefficient;
    temp->link = nullptr;
    delete temp;
    delete temp2;
}
// assign new poly to current
polynomial::polynomial(int *p, int degree)
{
    this->degree = degree;
    this->head = new node;
    node *temp = this->head;
    for (int i = 0; i < this->degree; i++)
    {
        temp->coefficient = p[i];
        temp->link = new node;
        temp = temp->link;
    }
    temp->coefficient = p[degree];
    temp->link = nullptr;
    temp = nullptr;
}
// reset poly degree and reset poly to s
polynomial::polynomial(int s)
{
    this->degree = 0;
    this->head = new node;
    this->head->coefficient = s;
    this->head->link = nullptr;
}
// deallocate the array
polynomial::~polynomial()
{
    node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->link;
        delete head;
        head = temp;
    }
}
// Polynomial multiplication with an polynomial
polynomial polynomial::operator*(const polynomial &rhs) const
{
    polynomial result;
    result.degree = this->degree + rhs.degree;
    node *temp = this->head;
    node *temp2;
    node *temp3 = rhs.head;

    if (result.head != nullptr)
    {
        while (temp != nullptr)
        {
            temp->coefficient = 0;
            temp = temp->link;
        }
    }
    else
    {
        result.head = new node;
        temp = result.head;
        for (int i = 0; i < result.degree; i++)
        {
            temp->coefficient = 0;
            temp->link = new node;
            temp = temp->link;
        }
        temp->coefficient = 0;
        temp->link = nullptr;
    }

    temp = result.head;
    temp2 = this->head;

    for (int i = 0; i < this->degree + 1; i++)
    {
        for (int l = 0; l < i; l++)
        {
            temp = temp->link;
        }
        for (int j = 0; j < rhs.degree + 1; j++)
        {
            temp->coefficient += temp2->coefficient * temp3->coefficient;
            temp3 = temp3->link;
            temp = temp->link;
        }
        temp3 = rhs.head;
        temp2 = temp2->link;
        temp = result.head;
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
    node *temp = this->head;
    node *temp2;
    node *temp3 = rhs.head;
    // changes the degree on the larger degree
    if (this->degree > rhs.degree)
    {
        result.degree = this->degree;
    }
    else
    {
        result.degree = rhs.degree;
    }

    if (result.head != nullptr)
    {
        while (temp != nullptr)
        {
            temp->coefficient = 0;
            temp = temp->link;
        }
    }
    else
    {
        result.head = new node;
        temp = result.head;
        for (int i = 0; i < result.degree; i++)
        {
            temp->coefficient = 0;
            temp->link = new node;
            temp = temp->link;
        }
        temp->coefficient = 0;
        temp->link = nullptr;
    }
    temp = result.head;
    temp2 = this->head;
    for (int i = 0; i < this->degree + 1; i++)
    {
        temp->coefficient += temp2->coefficient;
        temp = temp->link;
        temp2 = temp2->link;
    }
    temp = result.head;
    for (int i = 0; i < rhs.degree + 1; i++)
    {
        temp->coefficient += temp3->coefficient;
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
    node *temp = this->head;
    node *temp2 = this->head;
    // if head is not null dellalocate it
    if (this->head != nullptr)
    {
        while (temp != nullptr)
        {
            temp = temp->link;
            delete temp2;
            temp2 = temp;
        }
    }

    this->head = new node;
    temp = this->head;
    temp2 = rhs.head;
    // this->head = new int[poly.degree];
    for (int i = 0; i < this->degree; i++)
    {
        temp->coefficient = temp2->coefficient;
        temp->link = new node;
        temp = temp->link;
        temp2 = temp2->link;
    }
    temp->coefficient = temp2->coefficient;
    temp->link = nullptr;
    temp = nullptr;
    temp2 = nullptr;
    return *this;
}
// set this to an int
const polynomial &polynomial::operator=(int rhs)
{
    this->degree = 0;
    this->head = new node;
    this->head->coefficient = rhs;
    this->head->link = nullptr;
    return *this;
}
// flips the sign for each coefficient of the polynomia
polynomial polynomial::operator-() const
{
    polynomial result;
    result.degree = this->degree;
    result.head = new node;
    node *temp = this->head;
    node *temp2 = result.head;
    while (temp->link != nullptr)
    {
        temp2->coefficient = temp->coefficient * -1;
        temp2->link = new node;
        temp2 = temp2->link;
        temp = temp->link;
    }
    temp2->coefficient = temp->coefficient * -1;
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
    polynomial::node *temp = rhs.head;
    while (temp->link != nullptr)
    {
        temp = temp->link;
    }
    if (abs(temp->coefficient) != 1 || rhs.degree == 0)
    {
        out << temp->coefficient;
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
        temp = rhs.head;
        for (int j = i; j < rhs.degree; j++)
        {
            temp = temp->link;
        }
        if (temp->coefficient == 0)
        {
            continue;
        }
        else if (temp->coefficient < 0)
        {
            out << "- ";
        }
        else
        {
            out << "+ ";
        }
        if (abs(temp->coefficient) != 1 || rhs.degree - i == 0)
        {
            out << abs(temp->coefficient);
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