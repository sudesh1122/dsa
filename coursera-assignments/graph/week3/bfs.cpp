#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int solve(vector<vector<int>> &v,int s,int e){
    if(s==e)
        return 0;
    queue<int>q;
    vector<int> dis(v.size(),INT_MAX);
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int t = q.front();q.pop();
        for(auto i:v[t]){
            if(dis[i]>dis[t]+1)
            {   
                dis[i]= dis[t]+1;
                q.push(i);
            }
        }
    }
    // for(int i=1;i<=v.size();i++)
    //     cout<<dis[i]<<" ";
    // cout<<endl;
    if(dis[e]==INT_MAX)
        return -1;
    return dis[e];
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
    int s,e;
    cin>>s>>e;
    cout<<solve(v,s,e);
    return 0;
}

// 4 4
// 1 2
// 4 1
// 2 3
// 3 1
// 2 4

// 5 4
// 5 2
// 1 3
// 3 4
// 1 4
// 3 5