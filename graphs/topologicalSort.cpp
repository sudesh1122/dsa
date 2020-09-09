#include <iostream>
#include <vector>
using namespace std;

vector<int> res;
bool topoLogicalSort(vector<vector<int>> &p,vector<bool> &vis,vector<bool>&rec,int t){
    vis[t]=true;
    rec[t]=true;
    for(auto i:p[t]){
        if(!vis[i] && topoLogicalSort(p,vis,rec,i))
            return true;
        else if(rec[i])
            return true;
    }
    res.push_back(t);
    rec[t]=false;
    return false;
}
vector<int> findOrder(int n, vector<vector<int>>& edges) {
    res.clear();
    vector<vector<int>> p(n);
    vector<bool> vis(n,false);
    vector<bool> rec(n,false);
    for(auto i:edges){
        p[i[0]].push_back(i[1]);    
    }
    for(int i=n-1;i>=0;i--){
        if(!vis[i] && topoLogicalSort(p,vis,rec,i))
            return {};
    }
    return res;
}


int main(){
    // {1,0} => 0 is  prerequisite for 1
    vector<vector<int>> pre = {{1,0},{2,0},{3,1},{3,2}};
    auto ans = findOrder(4,pre);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
}