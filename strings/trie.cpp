#include <bits/stdc++.h>
using namespace std;

class Trie{
    public:
    Trie* children[26];
    bool isEndOfWord;
};

Trie* getNode() {
    Trie*  node = new Trie();
    node->isEndOfWord=false;
    for(int i=0;i<26;i++) {
        node->children[i]=NULL;
    }
    return node;
}

void insert(Trie* root, string s){
    auto node = root;
    for(int i=0;i<s.size();i++){
        int ind = s[i]-'a';
        if(!node->children[ind]){
            node->children[i] = getNode();
        }
        node = node->children[ind];
    }
    node->isEndOfWord=true;
}

bool search(Trie* root,string s){
    
    auto node = root;
    for(int i=0;i<s.length();i++) {
        int ind = s[i]-'a';
        if(!node->children[ind])
        return false;
        node = node->children[ind];       
    }
    return (node && node->isEndOfWord);
}

