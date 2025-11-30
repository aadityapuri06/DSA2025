#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{int u,v,w;};

struct DSU{
    vector<int> p, r;
    DSU(int n):p(n),r(n,0){ for(int i=0;i<n;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; }
};

int main(){
    int n = 6;
    vector<Edge> edges = {
        {0,1,4},{0,2,3},{1,2,2},{1,3,5},{2,3,3},{2,4,4},{3,4,5},{3,5,1},{4,5,7}
    };

    sort(edges.begin(), edges.end(), [](const Edge&a,const Edge&b){return a.w < b.w;});
    DSU dsu(n);
    vector<Edge> mst;
    int total=0;
    for(auto &e: edges){ if(dsu.unite(e.u,e.v)){ mst.push_back(e); total+=e.w; } }

    cout<<"MST edges (u v w):\n";
    for(auto &e: mst) cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";
    cout<<"Total weight: "<<total<<"\n";

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
