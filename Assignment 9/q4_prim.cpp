#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main(){
    int n = 6;
    const int INF = 1e9;
    vector<vector<int>> w = {
        {0,4,3,INF,INF,INF},
        {4,0,2,5,INF,INF},
        {3,2,0,3,4,INF},
        {INF,5,3,0,5,1},
        {INF,INF,4,5,0,7},
        {INF,INF,INF,1,7,0}
    };

    vector<bool> used(n,false);
    vector<int> minE(n, INF), sel(n,-1);
    minE[0]=0;
    vector<pair<int,int>> mst;

    for(int i=0;i<n;i++){
        int v=-1;
        for(int j=0;j<n;j++) if(!used[j] && (v==-1 || minE[j]<minE[v])) v=j;
        if(minE[v]==INF) break;
        used[v]=true;
        if(sel[v]!=-1) mst.push_back({sel[v], v});
        for(int to=0; to<n; to++) if(w[v][to] < minE[to]){ minE[to]=w[v][to]; sel[to]=v; }
    }

    cout<<"Prim MST edges (u v):\n";
    for(auto &p: mst) cout<<p.first<<" "<<p.second<<"\n";

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
