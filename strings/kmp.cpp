#include <bits/stdc++.h>
using namespace std;


class KMP{
private:
    string str;
    vector<int> lps;
public:
    KMP(string s) {
        this->str = s;
    }

    vector<int> getLps(string s) {
        vector<int> lps(s.size(),0);
        int i=1; //always walks forword
        int j =0; //tracks prefix that matches suffix
        
        while(i<s.length()){
            if(s[i]==s[j]){
                j++;
                lps[i]=j;
                i++;
            }
            else {
                if(!j) {
                    // if its at 0 then leave this char, move forword
                    lps[i]=0;
                    i++;
                } else {
                    // backtrack j to check previous matching prefix
                    j = lps[j-1];
                }
            }
        }
        return lps;
    }

    vector<int> searchPattern(string s){
            vector<int> lps = getLps(s);
            vector<int> inds;
            int i=0;
            int j=0;
            while(i<str.length()) {
                if(str[i]==s[j]){
                    i++;
                    j++;
                    if(j==s.length()){
                        // store the index
                        inds.push_back(i-j);
                        // backtrack
                        j = lps[j-1];
                    }
                }
                else {
                    if(j==0) {
                        i++;
                    }
                    else {
                        j = lps[j-1];
                    }
                }
            }
            return inds;
    }
};

int main() {
    string s,p;
    cin>>s>>p;

    KMP obj(s);
    auto v = obj.searchPattern(p);
    for(auto i:v){
        cout<<i<<" ";
    };
    cout<<endl;
}