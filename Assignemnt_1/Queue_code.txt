/* 
 * File:   main.cpp
 * Author: SUSHMARAVI
 *
 * Created on September 14, 2014, 5:03 PM
 */

#include <cstdlib>
#include<string>
#include<iostream>

using namespace std;

struct Node{            
    int value;          //data item
    Node *next;         //pointer to next node
};

class Queue_LL{          //List of Queue elements
public:
    Queue_LL();          //constructor
    void enqueue(int);      //function to insert elements in Queue
    void dequeue();         //function to remove elements from Queue
    int size();             //Size of Queue
    void display();         //Display all elements in Queue
private:
    Node *root;             //Top element of Queue
    Node *current;          //pointer node to traverse through Queue
    int top;                //counter to obtain size of Queue
    int capacity;           //maximum number of elements in Queue
};

Queue_LL::Queue_LL(){       //constructor
    root = NULL;
    top = -1;
    capacity = 10;
}
void Queue_LL::enqueue(int n){      //insert elements in Queue
    if(top < 0){                    //when the Queue is empty, update the 1st element i.e. root
        root = new Node();
        root->next = 0;
        root->value = n;
        top++;
    }
    else                            //when Queue is not empty, traverse till the last node
    {
    current = root;
    if(current != NULL){                //there is at least one element in Queue
        while(current->next != 0){      //when current node is not last node
            current = current->next;        //update current node to next node
        }
    }    
    try{
        if(top == capacity-1){                  //if there are max elements in Queue,
            throw string ("Queue is overflowing");      //throw an exception that Queue is full
        }
        else{                                 //if there is space in Queue
            current->next = new Node();         //create a new node
            current = current->next;
            current->next = 0;                  //insert node at tail
            current->value = n;                 //assign the value passed
            top++;                              //increment the counter
        }
    }catch(string e) {                  //catch the exception
        cout<<e<<endl;                  //print the exception
    }
    }
}

void Queue_LL::dequeue()            //function to remove the elements
{
    Node *tmp;                      //take a temporary node
    int ret_data;
    if (top >= 0){                  //when queue is not empty
        tmp = root;
        ret_data = root->value;         //return the dequeue node value
        root = root->next;              //update the head to next node
        delete tmp;                     //delete the node
        top--;                          //decrement the counter
        cout<<"Dequeue element is "<<ret_data<<endl;
    }
    else{
        cout<<"Queue is Empty"<<endl;        //else print queue is empty
    }
}
void Queue_LL::display(){
    current = root;
    if(current != 0){
        cout<<"Elements in Queue are:"<<endl;
        while(current != 0){            //traverse through the elements in LL
            cout<<current->value<<endl;
            current = current->next;        //update the pointer to next node
        }
    }
    else{
        cout<<"There are no elements in Queue"<<endl;
    }    
}
int Queue_LL::size(){
    int count = 0;
        current = root;
     if(current != 0){              //if Queue is not empty
        while(current != 0){
            count++;                    //increment the counter for each node
            current = current->next;
        }
    } 
        return count;               //return the size of Queue
}
int main() {
    Queue_LL Q;
    
    Q.enqueue(5);           //enqueue 1 element
    Q.display();            //display to make sure 1st element is inserted
    
    Q.dequeue();            //dequeue the first element
    Q.dequeue();            //displays Queue is empty
    
    Q.enqueue(10);          //Enqueue 4 elements
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.display();            //Display to make sure elements are inserted
    
    Q.dequeue();            //Dequeue 2 elements
    Q.dequeue();
    cout<<"Size of Queue is: "<<Q.size()<<endl;       //obtain final size of Queue
    
    return 0;
}

