#include <iostream>
#include <string>
using namespace std;

struct Book {
    int bookNumber;
    string title;
};

void bubbleSort(Book books[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (books[j].bookNumber > books[j + 1].bookNumber) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

void printBooks(const Book books[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Book Number: " << books[i].bookNumber << ", Title: " << books[i].title << endl;
    }
}

int main() {
    Book books[] = {
        {3, "The Catcher in the Rye"},
        {1, "To Kill a Mockingbird"},
        {2, "1984"}
    };
    int n = sizeof(books) / sizeof(books[0]);

    cout << "Books before sorting:" << endl;
    printBooks(books, n);

    bubbleSort(books, n);

    cout << "\nBooks after sorting:" << endl;
    printBooks(books, n);

    return 0;
}