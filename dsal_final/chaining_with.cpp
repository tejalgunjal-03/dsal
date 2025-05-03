#include<iostream>
#include<string.h>
#define max 10
using namespace std;
struct node {
    char name[10];
    long int mn;
    int chain;
    node() {
        mn = 0;
        chain = -1;
        strcpy(name, "-----");
    }
};
class telephone {
public:
    node ht[max];
    int count;
    telephone() { count = 0; }

    int hashfun(long int);
    void insert();
    void find();
    void delno();
    void display();
};

int telephone::hashfun(long int num) {
    return (num % 10);
}

void telephone::insert() {
    node s;
    int index;
    cout <<"Enter name: \n";
    cin >> s.name;
    cout <<"Enter telephone number:\n";
    cin >> s.mn;
    index = hashfun(s.mn);
    cout << "Index= " << index << endl;

    if (ht[index].mn == 0) {
        ht[index] = s;
        count++;
    } else if (hashfun(ht[index].mn) == index) {
        int prev = index;
        while (ht[index].mn != 0) {
            if (ht[index].chain != -1)
                index = ht[index].chain;
            else {
                while (ht[index].mn != 0)
                    index = (index + 1) % max;
                ht[prev].chain = index;
            }
        }
        ht[index] = s;
        count++;
    } else {
        int newIndex = index;
        while (ht[newIndex].mn != 0)
            newIndex = (newIndex + 1) % max;
        
        node temp = ht[index];
        ht[newIndex] = temp;
        ht[index] = s;
        
        int tempIndex = hashfun(temp.mn);
        while (ht[tempIndex].chain != index)
            tempIndex = ht[tempIndex].chain;
        ht[tempIndex].chain = newIndex;

        ht[index].chain = -1;
        count++;
    }
}

void telephone::find() {
    long int num;
	int cnt=0;
    cout << "Enter the telephone number to search: ";
    cin >> num;
    int index = hashfun(num);

    while (index != -1) {
cnt++;       
if (ht[index].mn == num) {
            cout <<"Record Found!\n";
            cout <<"Name: " << ht[index].name<<endl;
            cout<< "Phone: " << ht[index].mn<<endl; 
            cout<<"found at index: "<<index<<endl;
            cout<<"comparison: "<<cnt<<endl;

            return;
        }
        index = ht[index].chain;
    }
    cout << "Record Not Found!\n";
}

void telephone::delno() {
    long int num;
    cout << "Enter the telephone number to delete: ";
    cin >> num;
    int index = hashfun(num);
    int prev = -1;
    
    while (index != -1) {
        if (ht[index].mn == num) {
            cout << "Record Deleted!\n";
            ht[index].mn = 0;
            strcpy(ht[index].name, "-----");
            if (prev != -1)
                ht[prev].chain = ht[index].chain;
            ht[index].chain = -1;
            return;
        }
        prev = index;
        index = ht[index].chain;
    }
    cout << "Record Not Found!\n";
}

void telephone::display() {
    for (int i = 0; i < max; i++) {
        cout << i << "\t" << ht[i].name << "\t" << ht[i].mn << "\t" << ht[i].chain << endl;
    }
}

int main() {
    telephone t;
    int ch;
    char ans;
    do {
        cout << "Enter your choice" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Display" << endl;
        cout << "3.Search" << endl;
        cout << "4.Delete" << endl;
        cin >> ch;
        switch (ch) {
            case 1: t.insert(); 
            break;
            case 2: t.display();
            break;
            case 3: t.find(); 
            break;
            case 4: t.delno(); 
             break;
            default: cout << "Invalid choice!!";
        }
        cout << "Do you want to continue? (1/0)";
        cin >> ans;
    } while (ans == '1');
    return 0;
}

 

  
