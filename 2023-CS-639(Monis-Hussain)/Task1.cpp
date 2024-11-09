#include <iostream>
using namespace std;

int sumOfDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return (num % 10) + sumOfDigits(num / 10);
}

int main()
{
    int number = 56459;
    cout << "Sum of digits of " << number << " is: " << sumOfDigits(number) << endl;
    return 0;
}
