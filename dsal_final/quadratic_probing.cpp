//Quadratic probing with number of comparisions.
#include<iostream>
#define MAX 10
using namespace std;

class Hash {
    long int arr[MAX];
    int comparisons[MAX]; // To store comparisons for each key

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
        int i = 0, comp = 1;

        // Check if the initial bucket is empty
        if (arr[index] == 0) {
            arr[index] = num;
            comparisons[index] = comp;
            return;
        }

        // If not, use quadratic probing to find the next empty slot
        while (arr[(index + i * i) % MAX] != 0) {
            comp++;
            i++;
            if (i == MAX) {
                cout << "Hash table is full" << endl;
                return;
            }
        }

        arr[(index + i * i) % MAX] = num;
        comparisons[(index + i * i) % MAX] = comp; // Store total comparisons for this key
    }

    void displayComparisons() {
        int totalComparisons = 0;
        for (int i = 0; i < MAX; i++) {
            if (arr[i] != 0) {
                cout << "Key " << arr[i] << " required " << comparisons[i] << " comparisons." << endl;
                totalComparisons += comparisons[i];
            }
        }
        cout << "Total comparisons for all keys: " << totalComparisons << endl;
    }

    void display() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i] == 0)
                cout << i << " ------> NULL" << endl;
            else
                cout << i << " ------> " << arr[i] << endl;
        }
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













/*Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 1
Enter the number: 11

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 1
Enter the number: 22

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 1
Enter the number: 21

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 1
Enter the number: 31

Menu:
1. Insert
2. Display
3. Display Comparisons
0. Exit
Enter your choice: 2
0 ------> 31
1 ------> 11
2 ------> 22
3 ------> NULL
4 ------> NULL
5 ------> 21
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
Key 31 required 4 comparisons.
Key 11 required 1 comparisons.
Key 22 required 1 comparisons.
Key 21 required 3 comparisons.
Total comparisons for all keys: 9*/
