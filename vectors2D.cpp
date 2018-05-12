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
    return (this->getX() * v.getX() + this->getY() * v.getY()) / (sqrt(this->getX() * this->getX() + this->getY() * this->getY()) * sqrt(v.getX() * v.getX() + v.getY() * v.getY()));
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

int main ()
{
    Vector A, B;
    int num = 5;
    cin >> A >> B;
    Vector C = A + B;
    Vector D = A - B;
    Vector E = A * num;
    double F = A * B;
    cout << C << D << E << F;
    return 0;
}
