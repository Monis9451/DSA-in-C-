#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrivalTimes[] = {120, 45, 300, 150, 90};
    int n = sizeof(arrivalTimes) / sizeof(arrivalTimes[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arrivalTimes[i] << " ";
    }
    cout << endl;

    selectionSort(arrivalTimes, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arrivalTimes[i] << " ";
    }
    cout << endl;

    return 0;
}