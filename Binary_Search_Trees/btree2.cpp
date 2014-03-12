#include <iostream>
#include <cstdlib>
#include<string>

using namespace std;

class btree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
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
    void remove(string);
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

void btree::remove(string d)
{
  
    bool found = false;
    if(isEmpty())
    {
        //cout<<" This Tree is empty! "<<endl;
        return;
    }
    
    tree_node* curr;
    tree_node* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->value == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d > curr->value) 
		{
		//cout <<"right" <<endl;
		curr = curr->right;
		}
             else 
		{
		//cout <<"left" <<endl;
		curr = curr->left;
		}
         }
    }
    if(found == false)
    {
        //cout<<" value not found! "<<endl;
        return;
    }


         // 3 cases :
    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL))
    {

    cout << "node with single child" << endl;
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {

          //cout << "node with single child left" << endl;
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

         //We're looking at a leaf node
         if( curr->left == NULL && curr->right == NULL)
    {
	//cout << "leaf node" << endl;
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
                  delete curr;
                  return;
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
	//cout << "node with 2 children" << endl;
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr->value = chkr->value;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
	//cout << "node's right child has a left child Move all the way down left to locate smallest element" << endl;
            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
        curr->value = lcurr->value;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->value = tmp->value;
           curr->right = tmp->right;
               delete tmp;
           }

        }
         return;
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
    string RemoveItem;
    string stop = "ENDINSERT";
    string d = "ENDDELETE";

    while(temp != stop)
    {
        cin >> temp;
        if(temp != stop)
        {
            b.insert(temp);
        }
    }


    while(RemoveItem != d)
    {
        cin >> RemoveItem;
        if(RemoveItem != d)
            b.remove(RemoveItem);
    }

    b.print_postorder();
}
