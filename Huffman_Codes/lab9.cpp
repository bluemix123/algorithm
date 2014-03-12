#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct node
{
    
    
    node * leftChild;
    node * rightChild;
    double frequency;
    char value;
    string code;
    
    
};

vector<node> nodeArray;

void printR(node *curr)
{
    
    if(curr == NULL)
    {
        return;
    }
    
    if((curr->value  < 'A') || (curr->value > 'F')) 
    {
        printR(curr->leftChild);
        printR(curr->rightChild);
    }
    else 
    {
        cout << curr->value  << " " << curr->frequency << endl;
    }
    
}


node  extractMin() // getting the smallest values
{ 
    double temp = (double) 9999999;
    vector<node>::iterator i1,pos;
    for(i1 = nodeArray.begin();i1!=nodeArray.end();i1++)
    {
        
        if(temp>(*i1).frequency)
        {
            pos = i1;
            temp = (*i1).frequency;
        }
    }
    
    node tempNode = (*pos);
    nodeArray.erase(pos); 
    
    return tempNode;
}

void btree(node * temproot,string s)
{
    node * root1 = new node;
    root1 = temproot;
    
    root1->code = s;
    if(root1 == NULL)
    {
        
    }
    else if(root1->leftChild == NULL && root1->rightChild == NULL)
    {
        cout<< root1->value<< " " << root1->frequency << endl;
    }
    else
    {
        
        root1->leftChild->code = s.append("0");
        s.erase(s.end()-1);
        root1->rightChild->code = s.append("1");
        s.erase(s.end()-1);
        
        
        btree(root1->leftChild,s.append("0"));
        s.erase(s.end()-1);
        btree(root1->rightChild,s.append("1"));
        s.erase(s.end()-1);
    }
    
}


node getHuffmanTree()
{

    while(!nodeArray.empty())
    {
 
        node * tempNode = new node;   
        node * tempNode1 = new node;
        node * tempNode2 = new node;
        *tempNode1 = extractMin(); //getting the 1st min
        *tempNode2 = extractMin(); //getting the 2nd min  
        
        tempNode->leftChild = tempNode1;
        tempNode->rightChild = tempNode2;
        tempNode->frequency = tempNode1->frequency+tempNode2->frequency;
        nodeArray.push_back(*tempNode);
        if(nodeArray.size() == 1)//only the root node exsits
        {
            break;
        }
    }
    return nodeArray[0];
}






int main ()
{

    char input;
    int p, bt, ct, dt, ec, fc;
        
    vector<char> letters;
    for( int i=0; i < 6; i++ ) {
        letters.push_back( i + 65 );
    }
    vector< int>  num ;
    for( int i=0; i < 6; i++ ) {
        num.push_back(0);
    }
    
    cin >> input;

    do{
        
        if (input == 'Z') {
            break;
        }
        
        if (input == 'A') {
            p = p + 1;
            num[0] = num[0] + 1;
        }
        
        if (input == 'B') {
            bt = bt + 1;
            num[1] = num[1] + 1;
        }
        
        if (input == 'C') {
            ct = ct + 1;
            num[2] = num[2] + 1;
        }
        
        if (input == 'D') {
            dt = dt + 1;
            num[3] = num[3] + 1;
        }

        if (input == 'E') {
            ec = ec + 1;
            num[4] = num[4] + 1;
        }
        
        if (input == 'F') {
            fc = fc + 1;
            num[5] = num[5] + 1;
        }

        cin >> input;
    }while (input != 'Z'); 
 
    for(int i = 0;i<6;i++)
    {
        node tempNode;

        tempNode.frequency = num[i];
        tempNode.value = letters[i];
        tempNode.leftChild = NULL;
        tempNode.rightChild = NULL;
        nodeArray.push_back(tempNode);
    }
    

    node root = getHuffmanTree();    
    
    btree(&root,"");
    

    

}

