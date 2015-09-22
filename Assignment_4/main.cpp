/* 
 * File:   main.cpp
 * Author: SUSHMARAVI
 *
 * Created on October 9, 2014, 9:09 PM
 */

#include <cstdlib>
#include<iostream>

using namespace std;

class Heap{
public:
    void print(int *a,int n);
    void buildheap(int *a,int n);
    void heapify(int *a,int i,int n);
    void heapsort(int *a, int n);
      
};
void Heap::buildheap(int* a, int n){
    for(int i=n/2; i>0; i--){
        heapify(a,i,n);
    }
}
void Heap::heapify(int* a, int i, int n){
    int temp;
    int j = 2*i;
    while(j<=n){
        if((j+1) <= n && a[j+1] > a[j])
            j = j+1;
        if(a[i] < a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        i = j;
        j = 2*j;
    }
    return;
}

void Heap::heapsort(int *a, int n){
    int temp;
    for(int i=n; i>1; i--){
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        heapify(a,1,i-1);
    }
}
void Heap::print(int* a,int n){
    for(int i=1;i<=n;i++){
        cout<<a[i]<< " ";
    }
}
int main() {
    int n;
    int a[15];
    Heap h;
    
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    cout<<"Enter elements in random order"<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } 
    cout<<"Elements before heapify are: "<<endl;
    h.print(a,n);
    
    h.buildheap(a,n);
    
    cout<<endl<<"Elements after heapify are: "<<endl;
    h.print(a,n);
    
    h.heapsort(a,n);
    cout<<endl<<"Elements after heap sorting"<<endl;
    h.print(a,n);
    
    return 0;
}

