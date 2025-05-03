#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct Node{
    char label[60];
    int chcount;
    Node*child[50];
}*root;

class general{
    public:
    void insert();
    void display();
    general(){
        root=NULL;
    }
};

void general::insert(){
    root=new Node();
    cout<<"Enter the name of book:";
    cin>>root->label;
    cout<<"Enter the no. of chapters:";
    cin>>root->chcount;
    
    for(int i =0 ;i<root->chcount;i++){
        root->child[i]= new Node();
        cout<<"Enter the name of chapter:";
        cin>>root->child[i]->label;
        cout<<"Enter the no. of sections:";
        cin>>root->child[i]->chcount;
        
        for(int j=0; j<root->child[i]->chcount;j++){
            root->child[i]->child[j]= new Node();
            cout<<"Enter name of sections:"<<endl;
            cin>>root->child[i]->child[j]->label;
            cout<<"Enter the no. of subsections:";
            cin>>root->child[i]->child[j]->chcount;
            
            for(int k=0;k<root->child[i]->child[j]->chcount;k++){
                root->child[i]->child[j]->child[k]=new Node();
                cout<<"Enter the name of subsection:"<<endl;
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }

    }
}

   void general:: display(){
    cout<<"*****Book Hiererchy*****"<<endl;
    cout<<"Book name is:"<<root->label<<endl;
    
    for(int i=0;i<root->chcount;i++){
        cout<<"Chapter:"<<root->child[i]->label<<endl;

        for(int j =0;j<root->child[i]->chcount;j++){
            cout<<"Section:"<<root->child[i]->child[j]->label<<endl;

            for(int k=0;k<root->child[i]->child[j]->chcount;k++){
                cout<<"Subsection:"<<root->child[i]->child[j]->child[k]->label<<endl;
            }
        }
    }
   } 

int main(){
    general g;
    int ch;
    do{
        cout<<"1.Insert"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"Enter the choice:";
        cin>>ch;

        switch(ch){
            case 1:g.insert();
            break;
            case 2:g.display();
            break;


        }
    }while(ch<3);
    return 0;
}

