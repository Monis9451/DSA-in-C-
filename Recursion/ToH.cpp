#include <iostream>
using namespace std;

void Toh(int n, char A, char B, char C)
{
    if (n > 0)
    {
        Toh(n - 1, A, C, B);
        cout << "Move disk " << n << " from " << A << " to " << C << endl;
        Toh(n - 1, B, A, C);
    }
}
int main()
{


    return 0;
}