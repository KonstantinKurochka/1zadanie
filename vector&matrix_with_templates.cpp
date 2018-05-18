#include <iostream>
#include <math.h>

using namespace std;

template <typename T>

class Vector
{
public:
Vector(){}

virtual ~Vector(){}

Vector(T a, T b)
{
    x = a;
    y = b;
}

T getX() const
{
    return x;
}

T getY() const
{
    return y;
}

void setX(T x)
{
    this->x = x;
}

void setY(T y)
{
    this->y = y;
}

Vector operator+ (const Vector& v)
{
    T a = this->getX() + v.x;
    T b = this->getY() + v.y;
    return Vector(a, b);
}

Vector operator- (const Vector& v)
{
    T a = this->getX() - v.x;
    T b = this->getY() - v.y;
    return Vector(a, b);
}

Vector operator* (const T f)
{
    T a = (this->getX()) * f;
    T b = (this->getY()) * f;
    return Vector(a, b);
}
T operator* (const Vector& v)
{
    return (this->getX() * v.getX() + this->getY() * v.getY());
}

private:
    T x, y;
};

template <typename T>
Vector<T> operator* (T f, Vector<T> v)
{
    T a = f * v.getX();
    T b = f * v.getY();
    return Vector<T>(a, b);
}

template <typename T>
istream& operator>>(istream &is, Vector<T> &v)
{
    T a, b;
    is >> a >> b;
    v.setX(a);
    v.setY(b);
    return is;
}

template <typename T>
ostream& operator<< (ostream &os, Vector<T> &v)
{
    os << "[" <<v.getX() << ", " <<v.getY() << "] ";
    return os;
}

template <typename T>
class Matrix
{
public:
Matrix(){}

virtual ~Matrix(){}

Matrix(T n1, T n2, T n3, T n4)
{
    a = n1;
    b = n2;
    c = n3;
    d = n4;
}

T getA() const
{
    return a;
}

T getB() const
{
    return b;
}

T getC() const
{
    return c;
}

T getD() const
{
    return d;
}

void setA(T n)
{
    this->a = n;
}

void setB(T n)
{
    this->b = n;
}

void setC(T n)
{
    this->c = n;
}

void setD(T n)
{
    this->d = n;
}

Matrix operator+ (const Matrix& m)
{
    T a = this->getA() + m.a;
    T b = this->getB() + m.b;
    T c = this->getC() + m.c;
    T d = this->getD() + m.d;
    return Matrix(a, b, c, d);
}

Matrix operator- (const Matrix& m)
{
    T a = this->getA() - m.a;
    T b = this->getB() - m.b;
    T c = this->getC() - m.c;
    T d = this->getD() - m.d;
    return Matrix(a, b, c, d);
}

Matrix operator* (const T f)
{
    T a = this->getA() * f;
    T b = this->getB() * f;
    T c = this->getC() * f;
    T d = this->getD() * f;
    return Matrix(a, b, c, d);
}

Matrix operator* (const Matrix m)
{
    T a, b, c, d;
    a = this->a * m.a + this->b * m.c;
    b = this->a * m.b + this->b * m.d;
    c = this->c * m.a + this->d * m.c;
    d = this->c * m.b + this->d * m.d;
    return Matrix(a, b, c, d);
}

Vector <T> operator* (const Vector<T> v)
{
    T a = this->a * v.getX() + this->b * v.getY();
    T b = this->c * v.getX() + this->d * v.getY();
    return Vector<T> (a, b);
}

T determinant ()
{
    return this->a * this->d - this->b * this->c;
}

private:
    T a;
    T b;
    T c;
    T d;
};

template <typename T>
Matrix<T> operator* (double f, Matrix<T> &m)
{
    T a = f * m.getA();
    T b = f * m.getB();
    T c = f * m.getC();
    T d = f * m.getD();
    return Matrix<T>(a, b, c, d);
}

template <typename T>
istream& operator>>(istream &is, Matrix<T> &m)
{
    int a, b, c, d;
    is >> a >> b >> c >> d;
    m.setA(a);
    m.setB(b);
    m.setC(c);
    m.setD(d);
    return is;
}

template <typename T>
ostream& operator<< (ostream &os, Matrix<T> &m)
{
    os << "|" << m.getA() << " " << m.getB() << "|" << endl << "|" <<m.getC() << " " << m.getD() << "|" << endl;
    return os;
}

int main()
{
    cout << "=== Test vector ===" << endl;

    Vector<int> v1 (1, 1);
    Vector<int> v2 (2, 2);
    Vector<int> v3;

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

    Matrix<int> m1(0, 1, 1, 2);
    Matrix<int> m2(0, 1, 2, 2);
    Matrix<int> m3;

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

    Vector<int> v4 = m1 * v1;
    cout << v4 << endl;

    return 0;
}
