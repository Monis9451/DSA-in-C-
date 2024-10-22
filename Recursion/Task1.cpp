#include <iostream>
using namespace std;

void print(int n)
{
    if (n > 0) {
        print(n - 1);
        cout << n << " ";
    }
    return;
}


void printR(int n)
{
    if (n > 0) {
        cout << n << " ";
        printR(n - 1);
    }
    return;
}

int main()
{
    int n = 10;
    print(n);
    cout << endl;
    printR(n);
    return 0;
}
