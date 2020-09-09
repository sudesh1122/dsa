#include <bits/stdc++.h>
using namespace std;

// maxHeap
void heapify(vector<int> &v,int i){
    int n = v.size();
    int left = 2*i+1;
    int right = 2*i+2;
    int ind = i;

    if(left<n && v[left]>v[ind])
        ind = left;
    if(right<n && v[right]>v[ind])
        ind = right;
    
    if(ind!=i){
        swap(v[i],v[ind]);
        heapify(v,ind);
    }
}

void heapSort(vector<int> &v){
    int n = v.size();
    for(int i=n-1;i>=0;i--){
        heapify(v,i);
    }
}


signed main(){
    int n; cin>>n;
    vector<int> v(n);
    
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    heapSort(v);
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
}