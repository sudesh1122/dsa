#include <bits/stdc++.h>
using namespace std;
// implementation of Trie data structure



//Using map

class Trie {

private:
    map<char,Trie*> m;
    bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
        Trie* node =this;
        for(int i=0;i<s.size();i++)
        {
            if(node->m.find(s[i])==node->m.end())
            {
                auto temp = new Trie();
                node->m[s[i]] = temp;
                node=temp;
            }
            else
            {
                node = node->m[s[i]];
            }
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s) {
        
        Trie* node = this;
        for(int i=0;i<s.size();i++)
        {
            if(node->m.find(s[i])==node->m.end())
                return false;
            else node = node->m[s[i]];
        }
        if(node->isEnd==true) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        
        Trie* node = this;
        for(int i=0;i<s.size();i++)
        {
            if(node->m.find(s[i])==node->m.end())
                return false;
            else node = node->m[s[i]];
        }
        return true;
    }

    void deleteWord(string s)
    {
    	deletion(this,s,0);
    }

    // delete a word, returns true if parent should delete the mapping 
    bool deletion(Trie* node ,string s, int i)
    {
    	// if i is the last index then if isEnd then set it to false and check if m is empty or not
    	if(i==(int)s.size())
    	{
    		if(!node->isEnd)
    			return false;
    		node->isEnd=false;
    		return node->m.size()==0;
    	}

    	// if the char not found then simply return 
    	if(node->m.find(s[i])==node->m.end())
    		return false;

    	// check if next node can be deleted or not
    	bool shouldDeleteCur = deletion(node->m[s[i]],s,i+1);

    	// if yes then erase the key from current node->m
    	if(shouldDeleteCur)
    	{
    		node->m.erase(s[i]);
    		return node->m.size()==0;
    	}
    	
    	return false;

    }

};


int main()
{
	Trie* t = new Trie();
	cout<<t->search("add")<<endl;
	t->insert("add");
	cout<<t->search("add")<<endl;
	t->deleteWord("add");
	cout<<t->search("add")<<endl;

}
