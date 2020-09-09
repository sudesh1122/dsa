#include <bits/stdc++.h>
using namespace std;



class Graph {
    int n;
    list<int> *adj;
public:
    Graph(int n){
        this->n= n;
        adj = new list<int>[n];
    }
    void addEdge(int a ,int b) {
        adj[a].push_back(b);
    }
    void bfs( int k) {
        vector<bool> v(n,false);
        list<int> q;
        q.push_back(k);
        v[k]  = true;
        while(!q.empty()) {
            k = q.front();
            cout<<k<<" ";
            q.pop_front();
            for(auto i = adj[k].begin();i!=adj[k].end();i++)
            {
                if(!v[*i]) {
                    v[*i] = true;
                    q.push_back(*i);
                }
            }
        }
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
    g.bfs(2);
    return 0; 
}