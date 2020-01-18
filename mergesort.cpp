#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void merge(vector<int> &v,int l,int m, int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	vector<int> L(n1),R(n2);
	for(i=0;i<n1;i++)
		L[i]=v[l+i];
	for(i=0;i<n2;i++)
		R[i]=v[m+1+i];
	i=0;
	j=0;
	k=l;
	;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			v[k]=L[i];
			i++;
		}
		else
		{
			v[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		v[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		v[k]=R[j];
		j++;
		k++;
	}
}
void merge_sort(vector<int> &v,int l, int r)
{
	if(l>=r)
		return;
	int m = l+(r-l)/2;
	merge_sort(v,l,m);
	merge_sort(v,m+1,r);
	merge(v,l,m,r);
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto i=0;i<n;i++)
		cin>>v[i];
	merge_sort(v,0,n-1);
	for(auto i = 0;i<n;i++)
		cout<<v[i]<<" ";
	return 0;
}