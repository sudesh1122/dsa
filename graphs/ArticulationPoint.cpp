#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/critical-connections-in-a-network/
class Solution {
public:
    vector<int> rank,lowest;
    vector<vector<int>> g;  // graph
    vector<vector<int>> res; // edges to remove
    int solve(int node,int depth,int parent){
        
        if(rank[node]>=0)
            return rank[node];
        rank[node]=depth;
        int ans = depth;
        for(auto neibr:g[node]){

            if(parent==neibr)
                continue;
            int back_depth = solve(neibr,depth+1,node);

            if(back_depth>depth){
                res.push_back({node,neibr});
            }
            ans = min(ans,back_depth);
        }
        rank[node]=ans;
        return ans;
    }


};