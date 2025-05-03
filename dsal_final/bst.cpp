#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

class Bst {
public:
    node *root;
    void create();
    void insert(node*, node*);
    void dis();
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void min(node*);
    void minval(node *);
    void maxval(node *);
    int height(node *);
    bool search(node *); 
    void mirror(node *);
    int leafcount(node *);
    Bst() {
        root = NULL;
    }
};

void Bst::min(node *root) {
    node *temp = root;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    if(temp) {
        cout << "Min node: " << temp->data << endl;
    }
}

void Bst::create() {
    char ch;
    do {
        node *nn = new node;
        cout << "Enter data for node: ";
        cin >> nn->data;
        nn->left = NULL;
        nn->right = NULL;
        if (root == NULL) {
            root = nn;
        } else {
            insert(root, nn);
        }
        cout << "Do you want to add more nodes (y/n)? ";
        cin >> ch;
    } while (ch == 'y');
}

void Bst::insert(node *root, node *nn) {
    if (nn->data < root->data) {
        if (root->left == NULL) {
            root->left = nn;
        } else {
            insert(root->left, nn);
        }
    } else {
        if (root->right == NULL) {
            root->right = nn;
        } else {
            insert(root->right, nn);
        }
    }
}

void Bst::inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void Bst::preorder(node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void Bst::postorder(node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void Bst::dis() {
    cout << "Inorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << endl;
}

void Bst::minval(node* root) {
    node *temp = root;
    while(temp && temp->left != NULL) {
        temp = temp->left;
    }
    if(temp) {
        cout << "Min value in the BST is: " << temp->data << endl;
    }
}

void Bst::maxval(node* root) {
    node *temp = root;
    while(temp && temp->right != NULL) {
        temp = temp->right;
    }
    if(temp) {
        cout << "Max value in the BST is: " << temp->data << endl;
    }
}

int Bst::height(node *root) {
    if(root == NULL) {
        return 0;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    return (hr > hl ? hr : hl) + 1;
}

bool Bst::search(node *root){
    int n;
    cout<<"enter the node to be search";
    cin>>n;
    node *temp = root;
    while (temp != NULL) {
        if (n == temp->data) {
            return true;
        } else if (n < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}
void Bst::mirror(node *root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
int Bst::leafcount(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return leafcount(root->left) + leafcount(root->right);
}
int main() {
    Bst o;
    int choice;
    char ch;
    do {
        cout << "1. Insert\n2. Display\n3. Find Min\n4. Find Max\n5. Height\n6. Search\n7. Mirror\n8. Leaf Count\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                o.create();
                break;
            case 2:
                o.dis();
                break;
            case 3:
                o.minval(o.root);
                break;
            case 4:
                o.maxval(o.root);
                break;
            case 5:
                cout << "Height of the BST is: " << o.height(o.root) << endl;
                break;
            case 6:
                if (o.search(o.root)) {
                    cout << "Node found.\n";
                } else {
                    cout << "Node not found.\n";
                }
                break;
            case 7:
                o.mirror(o.root);
                cout << "Tree mirrored successfully.\n";
                break;
            case 8:
                cout << "Leaf count: " << o.leafcount(o.root) << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout << "Do you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}


