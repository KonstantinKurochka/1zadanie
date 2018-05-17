#include <iostream>
#include <math.h>

using namespace std;

class Vector
{
public:
Vector(){}

virtual ~Vector(){}

Vector(double a, double b)
{
    x = a;
    y = b;
}

double getX() const
{
    return x;
}

double getY() const
{
    return y;
}

void setX(double x)
{
    this->x = x;
}

void setY(double y)
{
    this->y = y;
}

Vector operator+ (const Vector& v)
{
    double a = this->getX() + v.x;
    double b = this->getY() + v.y;
    return Vector(a, b);
}

Vector operator- (const Vector& v)
{
    double a = this->getX() - v.x;
    double b = this->getY() - v.y;
    return Vector(a, b);
}

Vector operator* (const double f)
{
    double a = (this->getX()) * f;
    double b = (this->getY()) * f;
    return Vector(a, b);
}

double operator* (const Vector v)
{
    return (this->getX() * v.getX() + this->getY() * v.getY());
}

private:
    double x, y;
};

Vector operator* (double f, Vector& v)
{
    double a = f * v.getX();
    double b = f * v.getY();
    return Vector(a, b);
}

istream& operator>>(istream &is, Vector &v)
{
    int a, b;
    is >> a >> b;
    v.setX(a);
    v.setY(b);
    return is;
}

ostream& operator<< (ostream &os, Vector &v)
{
    os << "[" <<v.getX() << ", " <<v.getY() << "] ";
    return os;
}

class Matrix
{
public:
Matrix(){}

virtual ~Matrix(){}

Matrix(double n1, double n2, double n3, double n4)
{
    a = n1;
    b = n2;
    c = n3;
    d = n4;
}

double getA() const
{
    return a;
}

double getB() const
{
    return b;
}

double getC() const
{
    return c;
}

double getD() const
{
    return d;
}

void setA(double n)
{
    this->a = n;
}

void setB(double n)
{
    this->b = n;
}

void setC(double n)
{
    this->c = n;
}

void setD(double n)
{
    this->d = n;
}

Matrix operator+ (const Matrix& m)
{
    double a = this->getA() + m.a;
    double b = this->getB() + m.b;
    double c = this->getC() + m.c;
    double d = this->getD() + m.d;
    return Matrix(a, b, c, d);
}

Matrix operator- (const Matrix& m)
{
    double a = this->getA() - m.a;
    double b = this->getB() - m.b;
    double c = this->getC() - m.c;
    double d = this->getD() - m.d;
    return Matrix(a, b, c, d);
}

Matrix operator* (const double f)
{
    double a = this->getA() * f;
    double b = this->getB() * f;
    double c = this->getC() * f;
    double d = this->getD() * f;
    return Matrix(a, b, c, d);
}

Matrix operator* (const Matrix m)
{
    double a, b, c, d;
    a = this->a * m.a + this->b * m.c;
    b = this->a * m.b + this->b * m.d;
    c = this->c * m.a + this->d * m.c;
    d = this->c * m.b + this->d * m.d;
    return Matrix(a, b, c, d);
}

Vector operator* (const Vector v)
{
    double a = this->a * v.getX() + this->b * v.getY();
    double b = this->c * v.getX() + this->d * v.getY();
    return Vector (a, b);
}

double determinant ()
{
    return this->a * this->d - this->b * this->c;
}

private:
    int a;
    int b;
    int c;
    int d;
};

Matrix operator* (double f, Matrix& m)
{
    double a = f * m.getA();
    double b = f * m.getB();
    double c = f * m.getC();
    double d = f * m.getD();
    return Matrix(a, b, c, d);
}

istream& operator>>(istream &is, Matrix &m)
{
    int a, b, c, d;
    is >> a >> b >> c >> d;
    m.setA(a);
    m.setB(b);
    m.setC(c);
    m.setD(d);
    return is;
}

ostream& operator<< (ostream &os, Matrix &m)
{
    os << "|" << m.getA() << " " << m.getB() << "|" << endl << "|" <<m.getC() << " " << m.getD() << "|" << endl;
    return os;
}

int main()
{
    cout << "=== Test vector ===" << endl;

    Vector v1 (1, 1);
    Vector v2 (2, 2);
    Vector v3;

    v3 = (v1 + v2);
    cout << v3 << endl;

    v3 = (v1 - v2);
    cout << v3 << endl;

    v3 = v1 * 5;
    cout << v3 << endl;

    v3 = -5 * v2;
    cout << v3 << endl;

    cout << v1 << endl;
    cout << v2 << endl;

    cout << v1 * v2 << endl;

    Matrix m1(0, 1, 1, 2);
    Matrix m2(0, 1, 2, 2);
    Matrix m3;

    cout << "=== Test matrix ===" << endl;

    m3 = m1 + m2;
    cout << m3 << endl;

    m3 = m1 - m2;
    cout << m3 << endl;

    m3 = m1 * 5;
    cout << m3 << endl;

    m3 = -5 * m2;
    cout << m3 << endl;

    cout << m1 << endl;
    cout << m2 << endl;

    m3 = m1 * m2;
    cout << m3 << endl;

    cout << m1.determinant() << endl;

    cout << "=== Cross test vector and matrix ===" << endl;

    v3 = m1 * v1;
    cout << v3 << endl;

    return 0;
}
