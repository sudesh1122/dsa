#include <iostream>
#include <vector>
#include <set>
using namespace std;

int parent(vector<int>&p,int n)
{
    if(p[n]==n)
        return n;
    return p[n]=parent(p,p[n]);
}
void join(int a, int b,vector<int>& p){
    if(a>b)
    swap(a,b);
    int p1 = parent(p,a);
    int p2 = parent(p,b);
    p[p1]=p2;
}
int reach(vector<vector<int> > &adj,int n) {
  vector<int> p(n+1);
  for(int i=0;i<=n;i++)
    p[i]=i;

    for(auto k:adj){
        join(k[0],k[1],p);
    }
    set<int> s;
    for(int i=1;i<=n;i++)
        s.insert(parent(p,i));
    return s.size();
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj;
    for(int i=0;i<m;i++){
        vector<int> t(2);
        cin>>t[0]>>t[1];
        adj.push_back(t);
    }
  int x, y;
  std::cout << reach(adj,n);
}