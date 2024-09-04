#include <iostream>
using namespace std;

void display5(int *arr)
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
void display6(int *arr)
{
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
void insertInArray(int *&arr, int valueToInsert, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a value to insert in 1st array: ";
        cin >> valueToInsert;
        arr[i] = valueToInsert;
    }
    display5(arr);
}
void insertInStart(int *&arr, int *&arr2, int valueToInsert, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    display6(arr);
    cout << "Now enter a number to add in the 0th index of new array: ";
    cin >> valueToInsert;
    for (int i = size; i >= 0; i--)
    {
        arr2[i + 1] = arr2[i];
    }
    display6(arr2);
    cout << "Value inserted in the 1st" << endl;
    arr2[0] = valueToInsert;
    display6(arr2);
}
void insertInLast(int *&arr, int *&arr3, int valueToInsert, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr3[i] = arr[i];
    }
    display6(arr);
    cout << "Now enter a number to add in the last index of new array: ";
    cin >> valueToInsert;
    arr3[5] = valueToInsert;
    display6(arr3);
    cout << "Value inserted in the last" << endl;
}
// void remove()
int main()
{
    int *arr = new int[5];
    int size = 5;
    int firstValue;
    int valueToInsert;
    insertInArray(arr,valueToInsert, size);
    // next array with 1+ size to insert in start
    int *arr2 = new int[6];
    insertInStart(arr, arr2,valueToInsert, size);
    delete[] arr2;

    // next array with 1+ size to insert in last
    int *arr3 = new int[6];
    insertInLast(arr, arr3 ,valueToInsert, size);

    //remove a value
    // remove(arr2);

    return 0;
};