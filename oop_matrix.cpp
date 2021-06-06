#include <iostream>

using namespace std;

class Order;
class Matrix;
class Vector;

class Order
{
private:
    static int n;
public:
    void Input()
    {
        cout << "Current value of n is " << n << endl;
        cout << "Input n: ";
        cin >> n;
    }

    int getn()
    {
        return n;
    }
};

int Order::n = 0;

class Matrix : public Order
{
private:
    double m[20][20];

public:
    void Input();
    void Output();
    Vector operator*(Vector vec); // multiplying method
};

class Vector : public Order
{
private:
    double v[20];
    
public:
    friend class Matrix;
    void Input();
    void Output();
};

//--------------------------------
void Matrix::Input()
{
    int n;
    n = this->getn();
    if (n == 0)
    {
        this->Order::Input();
        n = this->getn();        
    }

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            cout << "m[" << r << "," << c << "] = ";
            cin >> m[r][c];
        }
    }
}

void Matrix::Output()
{
    int n;
    n = this->getn();
    if (n)
    {        
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                cout << m[r][c] << " ";
            }
            cout <<  endl;
        }
    }
}

Vector Matrix::operator*(Vector vec)
{
    Vector res;
    int n;
    n = this->getn();

    for (int r = 0; r < n; ++r)
    {
        res.v[r] = 0;

        for (int c = 0; c < n; ++c)
        {
            res.v[r] += m[r][c] * vec.v[c];
        }
    }

    return res;
}

void Vector::Input()
{
    int n;
    n = this->getn();
    if (n == 0)
    {
        this->Order::Input();
        n = this->getn();
    }
    for (int i = 0; i < n; ++i)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
}

void Vector::Output()
{
    int n;
    n = this->getn();
    if (n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Matrix mat;
    Vector v1, v2;

    cout << "Input the matrix:" << endl;
    mat.Input();

    cout << "Input Vector 1:" << endl;
    v1.Input();

    v2 = mat * v1;

    cout << "The matrix:" << endl;
    mat.Output();

    cout << "Vector 1:" << endl;
    v1.Output();

    cout << "Vector 2 = Matrix * Vector 1" << endl;
    v2.Output();

    return 0;
}