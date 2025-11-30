#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int main(){
    int n=6;
    const int INF = 1e9;
    vector<vector<pair<int,int>>> g(n);
    // edges: node -> (to, weight)
    g[0].push_back({1,7}); g[0].push_back({2,9}); g[0].push_back({5,14});
    g[1].push_back({0,7}); g[1].push_back({2,10}); g[1].push_back({3,15});
    g[2].push_back({0,9}); g[2].push_back({1,10}); g[2].push_back({3,11}); g[2].push_back({5,2});
    g[3].push_back({1,15}); g[3].push_back({2,11}); g[3].push_back({4,6});
    g[4].push_back({3,6}); g[4].push_back({5,9});
    g[5].push_back({0,14}); g[5].push_back({2,2}); g[5].push_back({4,9});

    int src = 0;
    vector<int> dist(n, INF); dist[src]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();
        int d = cur.first;
        int v = cur.second;
        if(d>dist[v]) continue;
        for(auto &e : g[v]){
            int to=e.first, w=e.second;
            if(dist[to] > dist[v]+w){ dist[to] = dist[v]+w; pq.push(make_pair(dist[to], to)); }
        }
    }

    cout << "Shortest distances from node "<<src<<":\n";
    for(int i=0;i<n;i++) cout << i << ": " << dist[i] << "\n";

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
