#include <bits/stdc++.h>
using namespace std;


// Disjoint Set
class Node {
public:
    int data;
    int rank;
    Node *parent;
};

class DisjointSet {
    
    map<int,Node*> m;
public:

    void makeSet(int k) {
        auto *node = new Node();
        node->data = k;
        node->rank = 0;
        node->parent = node;
        m[k] = node;
    }

    Node* getParent(Node* node) {
        while(node->parent!=node)
            node= node->parent;
        return node;
    }

    // returns false if parents of both nodes are same
    bool unionOf(int a ,int b) {
        auto node1 = m[a];
        auto node2 = m[b];
        auto parent1 = getParent(node1);
        node1->parent = parent1;
        auto parent2 = getParent(node2);
        node2->parent = parent2;
        if(parent1==parent2)return false;
        
        if(parent1->rank>=parent2->rank) {
            if(parent1->rank==parent2->rank) {
                parent1->rank++;
            }
            parent2->parent =parent1;
        }
        else {
            parent1->parent = parent2;
        }
        return true;
    }

    Node* findSet(int k) {
        auto node = m[k];
        if(node == node->parent)
        return node;
        auto temp = node;
        while(temp != temp->parent)
            temp = temp->parent;
        node->parent =temp;
        return temp;
    }

};



// using dfs
bool dfs(vector<vector<int>> &p,int t,vector<bool>&vis,vector<bool>&rec){
        vis[t]=true;
        rec[t]=true;
        
        for(auto j:p[t]){
            if(!vis[j] && dfs(p,j,vis,rec))
                return true;
            else if(rec[j])
                return true;
        }
    rec[t]=false;
    return false;
    
}

bool solve(int n, vector<vector<int>> &edges){
        vector<bool> vis(n,false);
        vector<bool> rec(n,false);
        vector<vector<int>> p(n);
        for(auto i:edges){
            p[i[0]].push_back(i[1]);    
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i] && dfs(p,i,vis,rec))
                return true;
        }
        return false;

}


int main() {
    auto ds = new DisjointSet();
    (*ds).makeSet(1);
    ds->makeSet(2);
    ds->makeSet(3);
    ds->makeSet(4);
    ds->makeSet(5);
    ds->makeSet(6);
    ds->makeSet(7);
    ds->unionOf(1, 2);
    ds->unionOf(2, 3);
    ds->unionOf(4, 5);
    ds->unionOf(6, 7);
    ds->unionOf(5, 6);
    ds->unionOf(3, 7);
    // if parent of two vertices is same before taking the union of them then there must be a cycle in the graph 
    // for(int i=1;i<8;i++)
    //     cout<<ds->findSet(i)->data;

}


