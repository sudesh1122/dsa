#include <iostream>
#include <vector>
#include <set>
using namespace std;




void dfs(vector<vector<int>> &v,int t,vector<bool> &vis,vector<int> &ans){
    vis[t]=true;
    for(auto i:v[t]){
        if(!vis[i])
         dfs(v,i,vis,ans);
    }
    ans.push_back(t);
    
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>());
    while(m--){
        int a,b;
        cin>>a>>b;
        v[b].push_back(a);
    }
    vector<bool> vis(n+1,false);
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(v,i,vis,ans);
    }

    for(auto i:ans)
        cout<<i<<" ";
    return 0 ;
}

// 4 3
// 1 2
// 4 1
// 3 1

// 5 7
// 2 1
// 3 2
// 3 1
// 4 3
// 4 1
// 5 2
// 5 3