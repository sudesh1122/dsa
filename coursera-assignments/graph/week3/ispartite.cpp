#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
    
    
vector<int> vis;
bool solve(int n,vector<vector<int>> &g){
    queue<pair<int,int>> q;
    q.push({n,1});
    while(!q.empty()){
        int t = q.front().first;
        int c =q.front().second;
        q.pop();
        if(vis[t]){
            if(vis[t]!=c)
                return false;
            continue;
        }
        vis[t]=c;
        for(auto i:g[t])
            q.push({i,-c});
    }
    return true;
}
bool isBipartite(vector<vector<int>>& g) {
    if(g.empty())
        return false;
    vis = vector<int>(g.size(),0);
    for(int i=0;i<g.size();i++)
        if(!vis[i] && !solve(i,g))
            return false;
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>());
    while(m--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<isBipartite(v);
    return 0;
}

// 4 4
// 1 2
// 4 1
// 2 3
// 3 1

// 5 4
// 5 2
// 4 2
// 3 4
// 1 4