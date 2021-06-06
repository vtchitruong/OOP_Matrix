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
    Vector operator*(Vector v); // multiplying method
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


int main()
{

    return 0;
}