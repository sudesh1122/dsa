#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct node
{
	int m1;
	int m2;
};
int partition2(vector<int> &v,int l,int r)
{
	int t= v[l];
	int j = l;
	for(int i=l+1;i<=r;i++)
	{
		if(v[i]<=t)
		{
			j++;
			swap(v[i],v[j]);
		}
	}
	swap(v[l],v[j]);
	
	
	return j;
}
node partition3(std::vector<int> &v,int l,int r)
{
	int t = v[l];
	int j = l;
	int m1=l;
	int i =l;
	int m2=r;
	while(i<=m2)
	{
		if(v[i]<t)
		{
			swap(v[i],v[m1]);
			m1++;
			i++;
		}
		else if(v[i]==t)
		{
			i++;
		}
		else
		{
			swap(v[i],v[m2]);
			m2--;
		}
	}
	struct node output = {m1,m2};
	return output;

}
void quick_sort(vector<int> &v,int l,int r)
{
	if(l>=r)
		return;
	int k = l+rand()%(r-l+1);
	swap(v[l],v[k]);
	struct node values = partition3(v,l,r);
	int m1 = values.m1;
	int m2 = values.m2;
	quick_sort(v,l,m1-1);
	quick_sort(v,m2+1,r);
}
int main()
{
	int n;
	cin>>n;
	std::vector<int> v(n);
	for(auto i=0;i<n;i++)
	{
		cin>>v[i];
	}
	quick_sort(v,0,v.size()-1);
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";

	return 0;
}