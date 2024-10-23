#include <iostream>
using namespace std;

int Multiply(int a, int b)
{
    if( a < b)
    {
        return Multiply(b, a);
    }
    else if(b != 0)
    {
        return a + Multiply(a, b-1);
    }
    else 
    {
        return 0;
    }
}

int main()
{
    int a, b;
    a = 4;
    b = 5;
    cout << Multiply(a, b) << endl;

    return 0;
}