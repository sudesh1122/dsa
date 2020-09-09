#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <map>
#include <algorithm>
using namespace std;

// without heap

int getVertex(vector<bool> &vis,vector<int> &dis,int &n){
    int res = -1;
    for(int i=1;i<=n;i++){
        if(!vis[i]&& (res==-1|| dis[i]<dis[res]))
        {
            res =i;    
        }
    }
    return res;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> g(n+1);
    for(auto i:times){
        g[i[0]].emplace_back(i[1],i[2]);    
    }
    vector<bool> vis(n+1,false);
    vector<int> dis(n+1,INT_MAX);
    dis[k] = 0;
    for(int i=0;i<n;i++){
        int j = getVertex(vis,dis,n);
        if(j==-1)
            break;
        vis[j]=true;
        if(dis[j]==INT_MAX)
            continue;
        for(auto k:g[j]){
            int dist = dis[j]+k.second;
            dis[k.first] = min(dis[k.first],dist);
        }
    }
    dis[0]=-1;
    int ans = -1;
    for(auto &i:dis)
        ans = max(i,ans);
    if(ans==INT_MAX)
        return -1;
    return ans;
}


// using priority_queue
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> g(n+1);
    for(auto i:times){
        g[i[0]].emplace_back(i[1],i[2]);    
    }
    vector<int> dis(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dis[k]=0;
    pq.emplace(0,k);
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        if(p.first==INT_MAX)
            continue;
        for(auto i:g[p.second]){
                int d = p.first+i.second;
                if(dis[i.first]>d){
                    dis[i.first] = d;
                    pq.emplace(d,i.first);
                }
        }
    }
    
    int ans = *max_element(dis.begin()+1,dis.end());
    if(ans ==INT_MAX)
        return -1;
    return ans;
}


int main(){
 vector<vector<int>> graph = {};

}