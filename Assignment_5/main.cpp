/* 
 * File:   main.cpp
 * Author: SUSHMARAVI
 *
 * Created on October 31, 2014, 12:24 PM
 */

#include <cstdlib>
#include<iostream>
#include <queue>
#include <stack>


using namespace std;

class Graph{                //Graph class
private:
    int nvertices;       // # vertices
    bool **adjmatrix;    // V x V adjacency matrix
    char *Vertex;
    bool *Visited_DFS;      //pointer to array for checking visited nodes in DFS
    bool *Visited_BFS;      //pointer to array for checking visited nodes in BFS
public:
    Graph(int nvertices){               //create a graph with given no of vertices
        this->nvertices = nvertices;
        adjmatrix = new bool*[nvertices];   //adjacency matrix
        for(int i=0; i<nvertices; i++){
            adjmatrix[i] = new bool[nvertices];
            for(int j=0; j<nvertices; j++){
                adjmatrix[i][j] = false;    //Initialize matrix to all 0's
            }
        }
        Visited_DFS = new bool[nvertices];      //array to store visited nodes in DFS
        Visited_BFS = new bool[nvertices];      //array to store visited nodes in BFS
        Vertex = new char[nvertices];
        for(int i=0;i<nvertices; i++){
            Vertex[i] = (char)(i+(int)('A'));   //array to store vertices
        }
    }   
    void addEdge(int i, int j){                 //add an edge between given 2 vertices
        if((i>=0 && i<nvertices) && (j>=0 && j<nvertices)){
            adjmatrix[i][j] = true;
            adjmatrix[j][i] = true;
        }
    }
    bool isEdge(int i, int j){                  //check for an edge between given 2 vertices
        if((i>=0 && i<nvertices) && (j>=0 && j<nvertices)){
            return adjmatrix[i][j];
        }
        else
            return false;
    }
    void printMatrix(){                 //print the adjacency matrix
        cout<<"  ";
        for(int i=0; i<nvertices; i++){
            cout<<Vertex[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<nvertices; i++){
            cout<<Vertex[i]<<" ";
            for(int j=0; j<nvertices; j++){
                cout<<adjmatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int getindex(const char *array,char c){     //get the index of element in the array
        for(int i=0; i<nvertices; i++){
            if(array[i] == c)
                return i;
        }
    }
    void DFSearch(){            //depth first search 
        stack<char> S;
        S.push(Vertex[0]);      //push the first vertex into stack
        Visited_DFS[0] = true;       //visit the first vertex
        int i;
        while(!S.empty()){
            i = getindex(Vertex,S.top());       //get the index of top element of queue
           for(int j=0; j<nvertices; j++){
               if(isEdge(i,j) && Visited_DFS[j]!= true){  //if there is an edge to unvisited vertex
                   Visited_DFS[j] = true;               //visit the vertex
                   S.push(Vertex[j]);                   //push the vertex on stack
                   break;
               }
               else if(j == nvertices-1){               //checked all the given vertices
                    if(!S.empty()){
                        cout<<S.top()<<" ";             //print the top element and
                        S.pop();                        //pop
                    }
               }
           }
        }
    }
    void BFSearch(){
        queue<char> Q;
        Q.push(Vertex[0]);                  //enqueue the first element into queue
        while(!Q.empty()){           
            int i = getindex(Vertex,Q.front());     //get index of first element in queue
            cout<<Q.front()<<" ";                   //print the front element
            Q.pop();                                //dequeue
            for(int j=i; j<nvertices; j++){
                if(isEdge(i,j) && Visited_BFS[j]!=true){    //if there is an edge to unvisited vertex
                    Visited_BFS[j] = true;                  //visit the vertex
                    Q.push(Vertex[j]);                      //enqueue 
                }
            }
        }
    }
    ~Graph() {
       for (int i = 0; i < nvertices; i++)
            delete[] adjmatrix[i];
        delete[] adjmatrix;
      }
};
int main() {
    Graph G(8);         //create a graph with 8 vertices
    //Add 16 edges between 8 vertices
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,3);
    
    G.addEdge(1,2);
    G.addEdge(1,4);
    G.addEdge(1,5);
    
    G.addEdge(2,3);
    G.addEdge(2,5);
    G.addEdge(2,6);
    
    G.addEdge(3,6);
    G.addEdge(3,7);
    
    G.addEdge(4,5);
    G.addEdge(4,6);
    
    G.addEdge(5,6);
    G.addEdge(5,7);
    G.addEdge(6,7);
    
    cout<<"Adjacency Matrix is:"<<endl<<endl;   //print the adjacency matrix
    G.printMatrix();
    cout<<endl<<"DFS is"<<endl;                 //Depth first search
    G.DFSearch();
    cout<<endl<<"BFS is"<<endl;                 //Depth first search
    G.BFSearch();
    return 0;
}

