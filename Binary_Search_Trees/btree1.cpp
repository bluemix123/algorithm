#include <iostream>
#include <cstdlib>
#include<string>

using namespace std;

class btree

{
    private:
        struct tree_node
        {
           
           tree_node* right;
	   tree_node* left;
           string value;
        };
        tree_node* root;
   
    public:
        btree()

        {
           root = NULL;
        }

        bool isEmpty() const { return root==NULL; }
        void print_postorder();
        void postorder(tree_node*);
        void insert(string);
};

void btree::insert(string d)

{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->value = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
   
    if(isEmpty()) root = t;
    else
    {
        tree_node* leaf;
        leaf = root;
        while(leaf)
        {
            parent = leaf;
            if(t->value > leaf->value)
            leaf = leaf->right;
            else
            leaf = leaf->left;
        }
        if(t->value < parent->value)
        parent->left = t;
        else
        parent->right = t;
    }
}

void btree::print_postorder()
{
    postorder(root);
}

void btree::postorder(tree_node* p)

{
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout << p->value << endl;
    }
    else return;
}

int main()
{
    btree b;

    string temp;
    string stop = "ENDINSERT";

    while(temp != stop)
    {
        cin >> temp;
        if(temp != stop)
        {
            b.insert(temp);
        }
    }

    b.print_postorder();
}


