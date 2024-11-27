#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size, int &exchangeCount) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                exchangeCount++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(int arr[], int size, int &exchangeCount) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            exchangeCount++;
        }
    }
}

int main() {
    const int SIZE = 10;
    int arr1[SIZE] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 45};
    int arr2[SIZE] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 45};

    int bubbleExchangeCount = 0;
    int selectionExchangeCount = 0;

    bubbleSort(arr1, SIZE, bubbleExchangeCount);
    selectionSort(arr2, SIZE, selectionExchangeCount);

    cout << "Bubble Sort Exchange Count: " << bubbleExchangeCount << endl;
    cout << "Selection Sort Exchange Count: " << selectionExchangeCount << endl;

    return 0;
}