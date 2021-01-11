#include <bits/stdc++.h>
using namespace std;

class Fenwick{
	public:
	Fenwick(vector<int> &nums){
		v = createTree(nums);
        this->nums = nums;
    }
	
	int getsumquery(int i,int j){
        return getSum(v,j)-getSum(v,i-1);
    }
    
    void updateVal(int ind,int val){
        int diff = val-nums[ind];
        nums[ind]=val;
        update(v,ind+1,diff);
    }
	private:
	vector<int> v,nums;	
	
	vector<int> createTree(vector<int> &nums){
    vector<int> v(nums.size()+1,0);
	    for(int i=0;i<nums.size();i++){
	        update(v,i+1,nums[i]);
	    }
	    return v;
	}
	
	void update(vector<int> &v,int ind,int val){
	    while(ind<v.size()){
	        v[ind]+=val;
	        ind = getNext(ind);
	    }
	}
	
	int getSum(vector<int> &v,int ind){
	    int res=0;
	    ind++;
	    while(ind>0){
	        res+=v[ind];
	        ind = getParent(ind);
	    }
	    return res;
	}
	
	/* function to get next index:
    next index = index+ (index & 2's complement)
	*/
	int getNext(int ind){
	    return ind+(ind&-ind);
	}
	
	/* function to get parent index:
	    next index = index- (index & 2's complement)
	*/
	int getParent(int ind){
	    return ind-(ind&-ind);
	}
};