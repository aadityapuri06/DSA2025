#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>>& g, int v, vector<bool>& seen){
    seen[v] = true;
    cout << v << " ";
    for(int to : g[v]) if(!seen[to]) dfs(g, to, seen);
}

int main(){
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
    cout << "DFS order starting from node " << start << ": ";
    dfs(g, start, seen);
    cout << "\n\nPress Enter to exit...";
    cin.ignore(); cin.get();
    return 0;
}
