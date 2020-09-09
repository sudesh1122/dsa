#include <iostream>
#include <vector>
#include <set>
using namespace std;




bool dfs(vector<vector<int>> &v,int t,vector<bool> &vis,vector<bool>& rec){
    vis[t]=true;
    rec[t]=true;
    for(auto i:v[t]){
        if(!vis[i] && dfs(v,i,vis,rec))
            return true;
        else if(rec[i])
            return true;
    }
    rec[t]=false;
    return false;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>());
    while(m--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    vector<bool> vis(n+1,false);
    vector<bool> rec(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i] && dfs(v,i,vis,rec)){
            cout<<1;
            return 0;
        }
    }

    cout<<0;
    return 0 ;
}

// 4 4
// 1 2
// 4 1
// 2 3
// 3 1

// 5 7
// 1 2
// 2 3
// 1 3
// 3 4
// 1 4
// 2 5
// 3 5