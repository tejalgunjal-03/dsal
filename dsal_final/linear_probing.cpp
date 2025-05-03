//Linear probing with number of comparisions
#include <iostream>
#define MAX 10
using namespace std;

class Hash {
    long int arr[MAX];
    int comparisons[MAX]; // To store the number of comparisons for each key

public:
    Hash() {
        for (int i = 0; i < MAX; i++) {
            arr[i] = 0;
            comparisons[i] = 0;
        }
    }

    int hashFun(long int num) {
        return num % MAX; // Simple hash function
    }

    void insert() {
        long int num;
        cout << "Enter the number: ";
        cin >> num;

        int index = hashFun(num);
        int start = index;
        int comp = 1; // Initial comparison to check the first slot

        if (arr[index] == 0) {
            // If bucket is empty, insert directly
            arr[index] = num;
            comparisons[index] = comp;
            cout << "Number " << num << " inserted with " << comp << " comparisons." << endl;
            return;
        }

        // Collision handling using linear probing
        while (arr[index] != 0) {
            index = (index + 1) % MAX;
            comp++;
            if (index == start) {
                cout << "Hash table is full. Unable to insert " << num << endl;
                return;
            }
        }

        arr[index] = num;
        comparisons[index] = comp; // Store comparisons for this key
        cout << "Number " << num << " inserted with " << comp << " comparisons." << endl;
    }

    void display() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i] == 0)
                cout << i << " ------> NULL" << endl;
            else
                cout << i << " ------> " << arr[i] << endl;
        }
    }

    void displayComparisons() {
        int totalComparisons = 0;

        cout << "\nComparisons for each key:" << endl;
        for (int i = 0; i < MAX; i++) {
            if (arr[i] != 0) {
                cout << "Key " << arr[i] << " required " << comparisons[i] << " comparisons." << endl;
                totalComparisons += comparisons[i];
            }
        }
        cout << "Total comparisons: " << totalComparisons << endl;
    }
};

int main() {
    int choice;
    Hash h;

    do {
        cout << "\nMenu:\n1. Insert\n2. Display\n3. Display Comparisons\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.displayComparisons();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

/*
Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 1
Enter the number: 11
Number 11 inserted with 1 comparisons.

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 1
Enter the number: 22
Number 22 inserted with 1 comparisons.

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 1
Enter the number: 21
Number 21 inserted with 3 comparisons.

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 1
Enter the number: 31
Number 31 inserted with 4 comparisons.

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 2
0 ------> NULL
1 ------> 11
2 ------> 22
3 ------> 21
4 ------> 31
5 ------> NULL
6 ------> NULL
7 ------> NULL
8 ------> NULL
9 ------> NULL

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 3

Comparisons for each key:
Key 11 required 1 comparisons.
Key 22 required 1 comparisons.
Key 21 required 3 comparisons.
Key 31 required 4 comparisons.
Total comparisons: 9
*/