#include  <bits/stdc++.h>
#define ll long long
using namespace std;

ll computeStringHash(string &s) {
    ll hash_val = 0;
    ll p=31;
    ll p_pow = 1;
    ll m = 1e9+7;
    for(auto i:s){
        hash_val = (hash_val+(i-'a'+1)*p_pow)%m;
        p_pow = (p_pow*p)%m;
    }
    return hash_val;
}

vector<vector<string>> group_identical_strings(vector<string> &v){
    int n = v.size();
    vector<pair<ll,ll>> hashes(n);
    for(ll i=0;i<n;i++){
        hashes[i]={computeStringHash(v[i]),i};
        cout<<hashes[i].first<<endl;
    }
    sort(hashes.begin(),hashes.end());
    vector<vector<string>> groups;
    for(int i=0;i<n;i++){
        if(i==0 || hashes[i].first!=hashes[i-1].first){
            groups.emplace_back();
        }
        groups.back().emplace_back(v[hashes[i].second]);
    }
    return groups;
}

// hash(s[i…j])*p^i =hash(s[0…j])−hash(s[0…i−1])%m

int main(){
    ll n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    auto ans = group_identical_strings(v);
    for(auto i:ans){
        for(auto j:i) cout<<j<<" ";
        cout<<endl; 
    }
}