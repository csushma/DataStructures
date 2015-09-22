/* 
 * File:   main.cpp
 * Author: SUSHMARAVI
 *
 * Created on November 29, 2014, 12:24 PM
 */

#include <cstdlib>
#include<iostream>

#define infinity 9999
using namespace std;

class Graph{                //Graph class   
public:
    int nvertices;       // # vertices
    int **adjmatrix;    // V x V adjacency matrix
    Graph(){
        
    }
    Graph(int nvertices){               //create a graph with given no of vertices
        this->nvertices = nvertices;
        adjmatrix = new int*[nvertices];   //adjacency matrix
        for(int i=0; i<nvertices; i++){
            adjmatrix[i] = new int[nvertices];
            for(int j=0; j<nvertices; j++){
                adjmatrix[i][j] = 0;    //Initialize matrix to all 0's
            }
        }
    }   
    void addEdge(int i, int j,int key){                 //add an edge between given 2 vertices
        if((i>=0 && i<nvertices) && (j>=0 && j<nvertices)){
            adjmatrix[i][j] = key;
            adjmatrix[j][i] = key;
        }
    }
    void printEdges(){                 //print the edges
        cout<<"Edge   Weight"<<endl;
        for(int i=0; i<nvertices; i++){
            for(int j=i; j<nvertices; j++){
                if(adjmatrix[i][j] != 0)
                    cout<<i<<" - "<<j<<"  "<<adjmatrix[i][j]<<endl;
            }
        }
    }
    ~Graph() {
       for (int i = 0; i < nvertices; i++)
            delete[] adjmatrix[i];
        delete[] adjmatrix;
      }
};
class PrimAlgo{
private:
    int nVertices;
    int **adjm_graph;
public:
    //constructor to initialize member variables of class
    PrimAlgo(int** adjmatrix,int n){            
        nVertices = n;
        adjm_graph = adjmatrix;
    }
    //Function to find minimum element in given array
    int minKey(int key[], bool mstSet[])
    {
        int min = infinity;
        int min_index; 
        for (int v = 0; v < nVertices; v++){
            if (mstSet[v] == false && key[v] < min){
                min = key[v]; min_index = v;
            }
        }
        return min_index;
    }
    //Prim ALgorithm to find MST
    void primMST()
    {   
        int parent[nVertices]; // Array to store predecessor of a vertex
        int key[nVertices];   // Key values used to pick minimum weight edge
        bool mstSet[nVertices];  // To represent set of vertices not yet included in MST
        
        // Initialize all keys as INFINITE
        for (int i = 0; i < nVertices; i++){
            key[i] = infinity;
            mstSet[i] = false;
        }

        key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
        parent[0] = -1; // First node is always root of MST 
    
        // The MST will have all vertices of graph
        for (int i = 0; i < nVertices; i++)
        {
           // Pick the minimum key vertex from the set of vertices
           // not yet included in MST
           int u = minKey(key, mstSet);
           // Add the picked vertex to the MST Set
           mstSet[u] = true;

           // Update key value and parent index of the adjacent vertices of
           // the picked vertex. Consider only those vertices which are not yet
           // included in MST
           for (int v = 0; v < nVertices; v++)
           {
              // adjm_graph[u][v] is non zero only for adjacent vertices of u
              // mstSet[v] is false for vertices not yet included in MST
              // Update the key only if adjm_graph[u][v] is smaller than key[v]
             if (adjm_graph[u][v] && mstSet[v] == false && (adjm_graph[u][v] <  key[v])){
               parent[v]  = u;
               key[v] = adjm_graph[u][v];
             }
           }
        }
        //Print the MST obtained
        cout<<"Edge   Weight"<<endl;
        for (int i = 1; i < nVertices; i++){
           cout<<parent[i]<<" - "<<i<<"  "<<key[i]<<endl;
       }
    }
};
int main() {
    Graph G(10);         //create a graph with 10 vertices
    
    //add 15 edges
    G.addEdge(0,1,4);
    G.addEdge(0,8,7);
    
    G.addEdge(1,2,8);
    G.addEdge(1,8,11);
    
    G.addEdge(2,3,7);
    G.addEdge(2,6,4);
    G.addEdge(2,9,2);
    
    G.addEdge(3,4,9);
    G.addEdge(3,6,14);
    
    G.addEdge(4,5,6);
    
    G.addEdge(5,6,10);
    
    G.addEdge(6,7,2);
    
    G.addEdge(7,8,1);
    G.addEdge(7,9,6);
    
    G.addEdge(8,9,7);
    
    //Print all the edges of graph
    cout<<"Edges of the graph are:"<<endl<<endl;   
    G.printEdges();
    
    //Find MST of graph using Prim Algorithm
    PrimAlgo PA(G.adjmatrix,G.nvertices);
    cout<<endl<<"MST of given graph is "<<endl;
    PA.primMST();
    
    return 0;
}