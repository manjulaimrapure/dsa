/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
using namespace std;

struct node {
    int data;
    node *L;
    node *R;
};

class bst {
public:
    void create();
    void insert(node*, node*);
    void disin(node*);
    void dispre(node*);
    void dispost(node*);
    void search(node*, int);
    int height(node*);
    void mirror(node*);
    void min(node*);
    bst() {
        root = NULL;
        Count = 0;
    }
// private:
    node *root, *temp;
    int Count, key;
};

void bst::create() {
    char ans;
    do {
        temp = new node;
        cout << "Enter the data: ";
        cin >> temp->data;
        temp->L = temp->R = NULL;
        if (root == NULL)
            root = temp;
        else
            insert(root, temp);
        cout << "Do you want to insert more value: ";
        cin >> ans;
        Count++;
    } while (ans == 'y');
    cout << "The Total no.of nodes are: " << Count;
}

void bst::insert(node* root, node* temp) {
    if (temp->data > root->data) {
        if (root->R == NULL)
            root->R = temp;
        else
            insert(root->R, temp);
    } else {
        if (root->L == NULL)
            root->L = temp;
        else
            insert(root->L, temp);
    }
}

void bst::disin(node* root) {
    if (root != NULL) {
        disin(root->L);
        cout << root->data << "\t";
        disin(root->R);
    }
}

void bst::dispre(node* root) {
    if (root != NULL) {
        cout << root->data << "\t";
        dispre(root->L);
        dispre(root->R);
    }
}

void bst::dispost(node* root) {
    if (root != NULL) {
        dispost(root->L);
        dispost(root->R);
        cout << root->data << "\t";
    }
}

// void bst::search(node* root, int key) {
//     int flag = 0;
//     cout << "\nEnter your key: ";
//     cin >> key;
//     temp = root;
//     while (temp != NULL) {
//         if (key == temp->data) {
//             cout << "KEY FOUND\n";
//             flag = 1;
//             break;
//         }
//         node* parent = temp;
//         if (key > parent->data)
//             temp = temp->R;
//         else
//             temp = temp->L;
//     }
//     if (flag == 0)
//         cout << "KEY NOT FOUND\n";
// }




void bst::search(node * root,int key)
{
    int flag=0;
    cout<<"\nEnter your key : "<<endl; 
    cin>>key;
    temp=root;
    while(temp!=NULL)
    {
        if(key==temp->data)
        {
            cout<<"           KEY FOUND           \n"; 
            flag=1; 
            break;  
        } 
        node *parent=temp; 
        if(key>parent->data)
        {
            temp=temp->R;
        }
        else
        {
            temp=temp->L;
        }
    }
    if(flag==0)
    {
        cout<<"            KEY NOT FOUND              "<<endl; 
    
    } 
} 






int bst::height(node* root) {
    if (root == NULL)
        return 0;
    else if (root->L == NULL && root->R == NULL)
        return 1;
    int hl = 1 + height(root->L);
    int hr = 1 + height(root->R);
    return (hl > hr) ? hl : hr;
}

void bst::min(node* root) {
    temp = root;
    while (temp->L != NULL)
        temp = temp->L;
    cout << temp->data;
}

void bst::mirror(node* root) {
    if (root != NULL) {
        mirror(root->L);
        mirror(root->R);
        temp = root->L;
        root->L = root->R;
        root->R = temp;
    }
}

int main() {
    bst t;
    int ch;
    char ans;
    do {
        cout << "\n1) Insert new node 2) Number of nodes in longest path 3) Minimum 4) Mirror 5) Search 6) Inorder 7) Preorder 8) Postorder" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                t.create();
                break;
            case 2:
                cout << "\nNumber of nodes in longest path: " << t.height(t.root);
                break;
            case 3:
                cout << "\nThe min element is: ";
                t.min(t.root);
                break;
            case 4:
                t.mirror(t.root);
                cout << "\nThe mirror of tree is: ";
                t.disin(t.root);
                break;
            case 5:
                t.search(t.root, t.key);
                break;
            case 6:
                cout << "\n***************INORDER**************" << endl;
                t.disin(t.root);
                break;
            case 7:
                cout << "\n***************PREORDER**************" << endl;
                t.dispre(t.root);
                break;
            case 8:
                cout << "\n*******************POSTORDER**************" << endl;
                t.dispost(t.root);
                break;
        }
        cout << "\nDo you want to continue: ";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}
