#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
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
};