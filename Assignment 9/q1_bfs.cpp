#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    // simple graph as adjacency list
    vector<vector<int>> g = {
        {1,2},    // 0
        {0,3,4},  // 1
        {0,5},    // 2
        {1},      // 3
        {1,5},    // 4
        {2,4}     // 5
    };

    int start = 0;
    vector<bool> seen(g.size(), false);
    queue<int> q;

    seen[start] = true;
    q.push(start);

    cout << "BFS order starting from node " << start << ": ";
    while(!q.empty()){
        int v = q.front(); q.pop();
        cout << v << " ";
        for(int to : g[v]){
            if(!seen[to]){ seen[to] = true; q.push(to); }
        }
    }
    cout << "\n\nPress Enter to exit...";
    cin.ignore(); cin.get();
    return 0;
}
