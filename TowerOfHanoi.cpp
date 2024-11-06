// #include <iostream>
// using namespace std;

// void towerOfHanoi(int n, int start, int end) {
//     if (n == 0) return;

//     int aux = 6 - start - end; // Sum of rods is 6 (1 + 2 + 3), so this gives the auxiliary rod.
    
//     towerOfHanoi(n - 1, start, aux);  // Move n-1 disks from start to auxiliary
//     cout << "Move disk " << n << " from rod " << start << " to rod " << end << endl;
//     towerOfHanoi(n - 1, aux, end);    // Move n-1 disks from auxiliary to end
// }

// int main() {
//     int n;
//     cout << "Enter the number of disks: ";
//     cin >> n;
//     towerOfHanoi(n, 1, 3); // 1 is the starting rod, 3 is the ending rod
//     return 0;
// }


// #include <iostream>
// #include <climits>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int value) : data(value), next(nullptr) {}
// };

// int findMax(Node* head) {
//     // Base case: if the list is empty, return the smallest integer as a default
//     if (head == nullptr) {
//         return INT_MIN;
//     }
//     // Recursive case: find the maximum in the rest of the list
//     int maxInRest = findMax(head->next);
    
//     // Return the maximum of the current node's data and the max in the rest
//     return max(head->data, maxInRest);
// }

// int main() {
//     // Example linked list creation
//     Node* head = new Node(1);
//     head->next = new Node(3);
//     head->next->next = new Node(5);
//     head->next->next->next = new Node(2);

//     int maxValue = findMax(head);
//     cout << "The greatest value in the list is: " << maxValue << endl;

//     return 0;
// }

// C++ program for decimal to binary
// conversion using recursion
#include <iostream>
using namespace std;

// Decimal to binary conversion
// using recursion
int find(int decimal_number)
{
	if (decimal_number == 0) 
		return 0; 
	else
		return (decimal_number % 2 + 10 * 
				find(decimal_number / 2));
}

// Driver code 
int main()
{
	int decimal_number = 10;
	cout << find(decimal_number);
	return 0;
}
// This code is contributed by shivanisinghss2110
