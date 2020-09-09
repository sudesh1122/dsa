#include <bits/stdc++.h>
using namespace std;


// refer https://cp-algorithms.com/data_structures/segment_tree.html
class segmentTree{
private:
    vector<int> sg;
    int n;
public:
    segmentTree(vector<int> &v){
        n = v.size();
        sg= vector<int>(4*n+1);

    }
    void build(vector<int>&v,int t,int l,int r){
        if(l==r)
            sg[t]=v[l];
        else{
            int m = l+(r-l)/2;
            build(v,t*2,l,m);
            build(v,t*2+1,m+1,r);
            sg[t]= sg[t*2]+sg[t*2+1];
        }
    }
    int sum(int t,int tl,int tr,int l,int r) {
        if(l>r)
            return 0;
        if(l==tl && r==tr)
            return sg[t];
        int m = tl+(tr-tl)/2;
        return sum(t*2,tl,m,l,min(r,m)) + sum(t*2+1,m+1,r,max(l,m+1),r);    
    }

    void update(int t,int tl,int tr,int &pos, int &val){
        if(tl==tr){
            sg[t]=val;
        }  else {
            int m = tl+(tr-tl)/2;
            if(pos<=m)
                update(t*2,tl,m,pos,val);
            else
                update(t*2+1,m+1,tr,pos,val);
            sg[t]=sg[t*2]+sg[t*2+1];
            
        }

    }

};

int main(){
    
}