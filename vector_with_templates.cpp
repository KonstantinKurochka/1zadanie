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

int main ()
{
    Vector <double> A, B;
    int num = 5;
    cin >> A >> B;
    Vector <double> C = A + B;
    Vector <double> D = A - B;
    Vector <double> E = A * num;
    double F = A * B;
    cout << A << B << C << D << E << F;
    return 0;
}
