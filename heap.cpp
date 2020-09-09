#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v,int t){
    int mx = t;
    int l = mx*2+1;
    int r = mx*2+2;
    if(l<v.size() && v[l]>v[mx])
        mx = l;
    if(r<v.size() && v[r]>v[mx])
        mx = r;
    if(mx!=t){
        swap(v[mx],v[t]);
        heapify(v,mx);
    }
}

void buildHeap(vector<int> &v){
    int n = v.size();
    int startInd = n/2-1;
    for(int i=startInd;i>=0;i--){
        heapify(v,i);
    }
}
int main() {
    vector<int> v = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
    buildHeap(v);
    for(auto i:v)
        cout<<i<<" ";
    cout<<"\n";
}