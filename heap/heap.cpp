#include <bits/stdc++.h>
using namespace std;


void heapifyTopDown(vector<int> &v,int i){
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
        heapifyTopDown(v,ind);
    }
}
void heapifyBottomUp(vector<int> &v,int i){
    if(i==0)
        return;
    int n = v.size();
    int parent = (i-1)/2;
    if(v[parent]<v[i]){
        swap(v[parent],v[i]);
        heapifyBottomUp(v,parent);
    }
}

void insert(vector<int> &v,int item){
    v.push_back(item);
    heapifyBottomUp(v,v.size()-1);
}

int pop(vector<int> &v){
    if(v.empty())
        return -1;
    int popped = v.front();
    swap(v[0],v.back());
    v.pop_back();
    heapifyTopDown(v,0);
    return popped;
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int> maxHeap;

    for(auto i:v)
        insert(maxHeap,i);
    for(auto i:maxHeap)
        cout<<i<<" ";
    
    cout<<"pop elements: "<<"\n";
    cout<<pop(maxHeap)<<endl;
    cout<<pop(maxHeap)<<endl;
    cout<<"new heap: \n";
    for(auto i:maxHeap)
        cout<<i<<" ";
    cout<<endl;
}