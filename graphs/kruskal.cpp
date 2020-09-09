#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}

int get(vector<int>& p,int n){
    if(p[n]==n)
        return n;
    return p[n] = get(p,p[n]);
}

bool join(int a, int b, vector<int> &p){
    int p1 = get(p,a);
    int p2 = get(p,b);
    // return false if there is a cycle
    if(p1==p2)
    return false;
    p[p1]=p2;
    return true;
}
// edges = {{from,to,weight},{...}}  //undirected

int kruskal(int n, vector<vector<int> > &edges) {
    if(edges.empty())
        return 0;
    sort(edges.begin(),edges.end(),comp);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++)
        parent[i]=i;
        
    int ans=0;
    int k = n-1;
    for(int i=0;i<edges.size() && k>0;i++){
        int a = edges[i][0];
        int b = edges[i][1];
        int w = edges[i][2];
        if(a>b)
            swap(a,b);
        if(join(a,b,parent)){
            ans+=w;
            k--;
        }
    }
    return ans;
}

