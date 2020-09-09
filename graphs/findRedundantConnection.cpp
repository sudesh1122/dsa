#include <bits/stdc++.h>
using namespace std;



int getParent(vector<int>&p,int n){
    if((p[n])==n )
        return n;
    return getParent(p,p[n]);
}
vector<int> findRedundantConnection(vector<vector<int>> v) {
    vector<int> p(v.size()+1);
    for(int i=0;i<p.size();i++)
        p[i] = i;
    vector<int> ans(2,0);
    for(auto i:v){
        int a = i[0];
        int b = i[1];
        int p1 = getParent(p,a);
        int p2 = getParent(p,b);
        if(p1!=p2){
            p[p2]=p1;
        } else {
            
            ans[0]=a;
            ans[1]=b;
        }
        
    }
    return ans;
}

int main(){
    const vector<vector<int>> v = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    auto res = findRedundantConnection(v);
    cout<<res[0]<<" "<<res[1]<<endl;

}