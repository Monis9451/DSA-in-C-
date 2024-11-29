#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int const size = 10;
    int arr[size] = {44, 23, 59, 20, 19, 67, 72, 83, 52, 38};
    cout << "Orignal sequence: " << endl;
    display(arr, size);
    cout << endl;
    selectionSort(arr, size);
    cout << "Sorted sequence: " << endl;
    display(arr, size);

    return 0;
}