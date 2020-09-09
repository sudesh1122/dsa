#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;
vector<vector<int>> ans;
void solve1(vector<vector<int>> &v,vector<bool>&vis,int a){
    vis[a]=true;
    for(auto i:v[a]){
        if(!vis[i]){
            solve1(v,vis,i);
        }
    }
    st.push(a);
}
void solve2(vector<vector<int>> &rv,vector<bool> &vis,int a){
    ans.back().push_back(a);
    vis[a]=true;
    for(auto i:rv[a]){
        if(!vis[i]){
            solve2(rv,vis,i);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>());
    vector<vector<int>> rv(n+1,vector<int>());
    while(m--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        rv[b].push_back(a); 
    }
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i])
            solve1(v,vis,i);
    }
    
    vis = vector<bool>(n+1,false);
    while(!st.empty()){
            int t = st.top();
            if(!vis[t]){
                ans.emplace_back();
                solve2(rv,vis,t);
            }
            st.pop();
    }
    // for(auto scnt:ans){
    //     for(auto ttt:scnt)
    //         cout<<ttt<<" ";
    //     cout<<endl;
    // }
    cout<<ans.size();
    return 0;
    
}

// 5 7
// 2 1
// 3 2
// 3 1
// 4 3
// 4 1
// 5 2
// 5 3


// 4 4
// 1 2
// 4 1
// 2 3
// 3 1