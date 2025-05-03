#include <iostream>
using namespace std;

struct Node {
    int key, value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    static const int SIZE = 10;
    Node* table[SIZE];

    int hash(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; ++i)
            table[i] = nullptr;
    }

    void insert(int key, int value) {
        int index = hash(key);
        Node* head = table[index];

        Node* curr = head;
        while (curr) {
            if (curr->key == key) {
                curr->value = value; // Update
                return;
            }
            curr = curr->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = head;
        table[index] = newNode;
        cout << "Inserted (" << key << ", " << value << ") at index " << index << endl;
    }

    int find(int key) {
        int index = hash(key);
        Node* curr = table[index];
        while (curr) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next;
        }
        return -1; // Not found
    }

    void remove(int key) {
        int index = hash(key);
        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev)
                    prev->next = curr->next;
                else
                    table[index] = curr->next;
                delete curr;
                cout << "Deleted key " << key << " from index " << index << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Key " << key << " not found." << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; ++i) {
            cout << i << ": ";
            Node* curr = table[i];
            while (curr) {
                cout << "(" << curr->key << ", " << curr->value << ") -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }

    ~HashTable() {
        for (int i = 0; i < SIZE; ++i) {
            Node* curr = table[i];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(1, 10);
    ht.insert(11, 20);  // Collision with key 1
    ht.insert(21, 30);  // Collision with key 1 and 11

    cout << "Find key 11: " << ht.find(11) << endl;

    ht.remove(11);
    cout << "Find key 11 after deletion: " << ht.find(11) << endl;

    ht.display();

    return 0;
}