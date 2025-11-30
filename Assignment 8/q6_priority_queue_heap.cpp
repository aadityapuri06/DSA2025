#include <iostream>
#include <vector>
using namespace std;

struct MinHeap {
    vector<int> a;
    void push(int v){ a.push_back(v); int i = a.size()-1; while(i>0){ int p = (i-1)/2; if(a[p]<=a[i]) break; swap(a[p], a[i]); i = p; } }
    int top(){ return a.empty()? -1 : a[0]; }
    void pop(){ if(a.empty()) return; a[0]=a.back(); a.pop_back(); int n=a.size(); int i=0; while(true){ int l=2*i+1; int r=2*i+2; int smallest=i; if(l<n&&a[l]<a[smallest]) smallest=l; if(r<n&&a[r]<a[smallest]) smallest=r; if(smallest==i) break; swap(a[i],a[smallest]); i=smallest; } }
    bool empty(){return a.empty();}
};

struct MaxHeap {
    vector<int> a;
    void push(int v){ a.push_back(v); int i=a.size()-1; while(i>0){ int p=(i-1)/2; if(a[p]>=a[i]) break; swap(a[p],a[i]); i=p; } }
    int top(){ return a.empty()? -1 : a[0]; }
    void pop(){ if(a.empty()) return; a[0]=a.back(); a.pop_back(); int n=a.size(); int i=0; while(true){ int l=2*i+1; int r=2*i+2; int largest=i; if(l<n&&a[l]>a[largest]) largest=l; if(r<n&&a[r]>a[largest]) largest=r; if(largest==i) break; swap(a[i],a[largest]); i=largest; } }
    bool empty(){return a.empty();}
};

int main(){
    MinHeap minh;
    minh.push(5); minh.push(1); minh.push(7); minh.push(3);
    cout<<"Min-heap top sequence: ";
    while(!minh.empty()){ cout<<minh.top()<<" "; minh.pop(); } cout<<"\n";

    MaxHeap maxh;
    maxh.push(5); maxh.push(1); maxh.push(7); maxh.push(3);
    cout<<"Max-heap top sequence: ";
    while(!maxh.empty()){ cout<<maxh.top()<<" "; maxh.pop(); } cout<<"\n";

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
