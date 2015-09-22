/* 
 * File:   main.cpp
 * Author: SUSHMARAVI
 *
 * Created on September 20, 2014, 8:23 PM
 */

#include <cstdlib>
#include<iostream>
#include <queue>

using namespace std;

struct Node{                
    int value;                  //data item
    Node *left;                 //pointer to left child
    Node *right;                //pointer to right child
};

class BTree_BFS{
public:
    Node *root;                     
    queue<Node *> Q;                        //Queue of Nodes
    void BFS(Node *N);                      //Function to traverse Bread first
    Node *insert(int key, Node *root);      //insert elements in Tree
    void freeNode(Node *node);              //delete node
    BTree_BFS();                            //constructor
    ~BTree_BFS();                           //Destructor
};

BTree_BFS::BTree_BFS(){
    root = NULL;
}

BTree_BFS::~BTree_BFS(){ 
    freeNode(root);
}

void BTree_BFS::freeNode(Node* node){           
    if(node != NULL){
        freeNode(node->left);
        freeNode(node->right);
        delete node;
    }
}
void BTree_BFS::BFS(Node* root){
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
Node *BTree_BFS::insert(int key, Node *node)
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

int main() {
    
    BTree_BFS bfs;                              //create an object
    bfs.root = bfs.insert(10,bfs.root);         //insert the root node first
    bfs.insert(5,bfs.root);                     //build the tree 
    bfs.insert(7,bfs.root);
    bfs.insert(12,bfs.root);
    bfs.insert(9,bfs.root);
    bfs.insert(11,bfs.root);
    bfs.insert(6,bfs.root);
    bfs.insert(4,bfs.root);
    bfs.insert(14,bfs.root);
    bfs.insert(17,bfs.root);

    bfs.BFS(bfs.root);                          //traversing bread first
    return 0;
}

