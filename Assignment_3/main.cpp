/* 
 * File:   main.cpp
 * Author: SUSHMARAVI
 *
 * Created on September 25, 2014, 9:09 PM
 */

#include <cstdlib>
#include<iostream>
#include<queue>

using namespace std;
struct Node{                
    int value;                  //data item
    Node *left;                 //pointer to left child
    Node *right;                //pointer to right child
};

class BSTree{
public:
    Node* deleteNode(Node *,int);           //function to delete node
    Node *insert(int key, Node *root);      //function to insert node in the tree
    Node *Minval(Node *node);               //function to find the minimum value in the tree
    void BFS(Node* root);                   //BFS to print values in tree
    void freeNode(Node*);                   //free memory of given node
    BSTree();                               //constructor
    ~BSTree();                              //destructor

    queue<Node *> Q;                        //Queue containing nodes used for BFS
    Node *root;                             //root of tree
};

BSTree::BSTree(){
    root = NULL;                    //initialize root value
}

BSTree::~BSTree(){
    freeNode(root);                 //free the root node
}

void BSTree::freeNode(Node* node){           
    if(node != NULL){
        freeNode(node->left);
        freeNode(node->right);
        delete node;
    }
}

Node *BSTree::insert(int key, Node *node)
{
    if(node == NULL){                       //when root is NULL
        node = new Node;                    //create a new node
        node->value = key;                  //assign key to new node's value
        node->left = NULL;                  //make left child null
        node->right = NULL;                 //make right child null
    }
    else{
        if(key < node->value)                           //if key is less than node value
            node->left = insert(key, node->left);       //recursive function to insert left child
        else                                            //if key is greater than or equal to node value
            node->right = insert(key, node->right);     //recursive function to insert right child
      }
    return node;                     
}

Node* BSTree::Minval(Node* node){                //function to find min value in tree
    if(node != NULL){                            //if node is not null
        if(node->left != NULL)                   //if left child of node is not null
            return Minval(node->left);           //recursive function to find min value of left subtree
        else                        
            return node;                        //else return the node
    }
}
void BSTree::BFS(Node* root){
    if(root != NULL){                       //check root is not null
        Q.push(root);                       //push the first element in queue
        while(!Q.empty()){                  //loop for queue is not empty
            Node *n = Q.front();            //a temp node to store top of queue
            Q.pop();                        //dequeue the top element
            cout<<n->value<<" ";            //print the node value
            if(n->left != NULL)
                Q.push(n->left);            //Enqueue left child
            if(n->right != NULL)    
                Q.push(n->right);           //Enqueue right child
        }
    }
}
Node *BSTree::deleteNode(Node* root, int key){
    Node *temp;                         //temporary node used in function 
    
    if(root == NULL)                    //if node to be deleted is null then return null
        return NULL;
    else{                               //if node is not null
        if(key < root->value)           //if key is less than root value
            root->left = deleteNode(root->left, key);   //recursive function to traverse thru left subtree till we find key
        else if(key > root->value)       //if key is greater than root value
            root->right = deleteNode(root->right, key);     //recursive function to traverse thru right subtree till we find key
        else{                           //if we found the node to be deleted
            //case 1: No children
            if(root->left == NULL && root->right == NULL){
                delete root;                //delete the root 
                root = NULL;
            }
            //case 2 : One child- RIGHT
            else if(root->left == NULL){
                temp = root;                //store root in temp node
                root = root->right;         //store the right child in root
                delete temp;                //delete the temp node
            }
            //case 3: One child - LEFT
            else if(root->right == NULL){
                temp = root;
                root = root->left;          //store the left child in root
                delete temp;
            }
            //case 4: both children
            else {
                temp = Minval(root->right);         //get min value of right sub tree and store in temp
                root->value = temp->value;          //replace the root value with min value of right subtree
                root->right = deleteNode(root->right, temp->value);     //delete the min value node
            }
        }
        return root;                        //return root
    }
}
int main() {
    BSTree bt;
    //12 54 34 76 46 2 18 38 23 11 9 87 33 65
    bt.root = bt.insert(12,bt.root);        //insert node
    bt.insert(54,bt.root);                  //insert other values
    bt.insert(34,bt.root);
    bt.insert(76,bt.root);
    bt.insert(46,bt.root);
    bt.insert(2,bt.root);
    bt.insert(18,bt.root);
    bt.insert(38,bt.root);
    bt.insert(23,bt.root);
    bt.insert(11,bt.root);
    bt.insert(9,bt.root);
    bt.insert(87,bt.root);
    bt.insert(33,bt.root);
    bt.insert(65,bt.root);
    
    cout<<"Tree values before deleting: "<<endl;
    bt.BFS(bt.root);                    //BFS to print values
    cout<<endl<<"Tree values after deleting: "<<endl;
    bt.deleteNode(bt.root, 54);         //function call to delete given node
    bt.BFS(bt.root);                    //BFS to print new tree values
    
    return 0;
}

