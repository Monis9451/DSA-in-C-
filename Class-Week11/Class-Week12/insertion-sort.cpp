#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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