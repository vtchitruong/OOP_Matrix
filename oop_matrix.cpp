#include <iostream>

using namespace std;

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


int main()
{

    return 0;
}