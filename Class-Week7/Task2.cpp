#include <iostream>
using namespace std;

int Power(int base, int exp)
{
    if(exp==0)
    {
        return 1;
    }
    else
    {
        return base * Power(base, exp-1);
    }
}

int main()
{
    cout << Power(2, 3) << endl;

    return 0;
}