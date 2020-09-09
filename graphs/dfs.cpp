#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    list<int> *adj;
    void dfsHelper(int k, vector<bool> &v) {
        v[k]=true;
        cout<<k<<" ";
        for(auto i = adj[k].begin();i!=adj[k].end();i++)
        {
            if(!v[*i]) {
                dfsHelper(*i,v);
            }
        } 
    }
public:
    Graph(int n)
    {
        this->n=n;
        adj = new list<int>[n];
    }
    void addEdge(int a, int b) {
        adj[a].push_back(b);
    }

    void dfs(int k) {
        vector<bool> v(n,false);
        dfsHelper(k,v);
        cout<<endl;
    }


};

int main() {
    Graph g(4);
  g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.dfs(2); 
    return 0;
}  
