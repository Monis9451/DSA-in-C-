#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < size ; j++)
        {
            if (arr[j] < arr[minimum])
                minimum = j;
        }
        swap(arr[i], arr[minimum]);
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