#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(const vector<int> &v, int t) {
    deque<pair<int,int>> dq;
    int i=0;
    for(;i<t-1;i++){
        while(!dq.empty() && dq.back().first<=v[i]){
            dq.pop_back();
        }
        dq.push_back({v[i],i});
    }
    vector<int> ans;
    for(;i<v.size();i++){
        while(!dq.empty() && dq.back().first<=v[i])
            dq.pop_back();
        dq.push_back({v[i],i});
        ans.push_back(dq.front().first);
        if(dq.front().second<=i-t+1)
            dq.pop_front();
    }
    return ans;
}

int main() {
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto ans = slidingMaximum(v,k);
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
}