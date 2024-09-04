#include <iostream>
using namespace std;

void display(int *&arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
void insertInArray(int *&arr, int size)
{
    int valueToInsert;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a value to insert in 1st array: ";
        cin >> valueToInsert;
        arr[i] = valueToInsert;
    }
}
void insertInStart(int *&arr, int &size)
{
    cout << "Extending 1 index" << endl;
    int valueToInsert;
    int *arr2 = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    size++;
    display(arr, size);
    cout << "Now enter a number to add in the 0th index of new array: ";
    cin >> valueToInsert;
    for (int i = size - 1; i >= 0; i--)
    {
        arr2[i + 1] = arr2[i];
    }
    display(arr2, size);
    cout << "Value inserted in the 1st" << endl;
    arr2[0] = valueToInsert;
    arr = arr2;
}
void insertInLast(int *&arr, int &size)
{
    int valueToInsert;
    int *arr3 = new int[size + 1];
    cout << "Now to insert value in the last" << endl;
    for (int i = 0; i < size; i++)
    {
        arr3[i] = arr[i];
    }
    size++;
    display(arr3, size);
    cout << "Now enter a number to add in the last index of new array: ";
    cin >> valueToInsert;
    arr3[size - 1] = valueToInsert;
    arr = arr3;
    display(arr3, size);
    cout << "Value inserted in the last" << endl;
}
void remove(int *&arr, int &size)
{
    int value;
    int curr;
    cout << "Enter the value to remove from the array: ";
    cin >> value;
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] == value)
        {
            curr = i;
            for (int j = i; j <= size; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
    size--;
    display(arr, size);
    cout << "Entered value remove!" << endl;
}
void update(int *&arr, int size)
{
    int value, index;
    cout << "Enter the value you want to enter: ";
    cin >> value;
    cout << "Enter the index you want to update b/w 0-" << size-1 << " :";
    cin >> index;
    arr[index] = value;
    cout << "Value updated" << endl;
}
bool find(int *&arr, int size)
{
    int value, found = 0;
    cout << "Enter the value to find: ";
    cin >> value;
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] == value)
        {
            found = 1;
            return true;
        }
    }
    if (found == 0)
    {
        return false;
    }
}
void back(int *&arr, int size)
{
    int index;
    cout << "Enter an index to access, if you access -1 you'll get an error";
    cin >> index;
    if (index < 0)
    {
        cout << "Index does't exist" << endl;
    }
    else
    {
        cout << "This is the index value: " << arr[index] << endl;
    }
}
void front(int *&arr, int size)
{

    int index;
    cout << "Enter an index to access, if you access greater index than " << size << " you'll get an error: ";
    cin >> index;
    if (index > size)
    {
        cout << "Index does't exist" << endl;
    }
    else
    {
        cout << "This is the index value: " << arr[index] << endl;
    }
}
void index_at(int *&arr, int size)
{
    int index;
    cout << "Enter an index to access the value: ";
    cin >> index;
    cout << "The value of index " << index << " is :" << arr[index] << endl;
}
int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int *arr = new int[size];
    // int firstValue;
    // int valueToInsert;

    // inserting value in ---------------------------------------------Task1
    insertInArray(arr, size);
    display(arr, size);
    // next array with 1+ size to insert in start ---------------------Task2
    insertInStart(arr, size);
    display(arr, size);

    // next array with 1+ size to insert in last ----------------------Task3
    insertInLast(arr, size);

    // remove a value -------------------------------------------------Task4
    remove(arr, size);

    // Current displayed data in array --------------------------------Task5
    cout << "This is the current display" << endl;
    display(arr, size);

    // Update the entered index----------------------------------------Task6
    update(arr, size);
    display(arr, size);

    // Find the enterd value ------------------------------------------Task7
    bool ifFind = find(arr, size);
    if (ifFind)
    {
        cout << "Found the value in array" << endl;
    }
    else
    {
        cout << "Can't find the value in array" << endl;
    }

    // Back function ---------------------------------------------------Task8
    back(arr, size);

    // Front function --------------------------------------------------Task9
    front(arr, size);

    // index_at function-------------------------------------------------Task10
    index_at(arr, size);
    display(arr, size);
    cout << "All functions end here" << endl;

    return 0;
};