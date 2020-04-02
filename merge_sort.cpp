#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define ii pair<int,int>
#define lli pair<ll,ll>
#define pii pair<int,int>
#include<limits>
#define deb(x) cout<<#x<<'='<<(x)<<endl
#define deb2(x,y) cout<<'['<<#x<<'='<<(x)<<','<<#y<<'='<<(y)<<']'<<endl
#define debarr(a,n) {cout<<#a<<'='; for(int i=0;i<n;i++) cout << a[i] << ' '; cout<<endl;}
#define debvec(v) {cout<<#v<<'=';for(auto itr=v.begin();itr!=v.end();itr++)cout<<*itr<<' ';cout<<endl;}
#define INF numeric_limits<int>::max()
#define NINF numeric_limits<int>::min()
#define endl "\n"
#define mp make_pair
using namespace std;


// Merge Sort Algorithm implementation
// worst case time complexity is O(nlog(n))

void merge(std::vector<int> &v,int l,int m,int r)
{
	int i,j;i=j=0;
	int k = l;
	std::vector<int> v1(m-l+1);
	std::vector<int> v2(r-m);
	for(int p =0;p<m-l+1;p++) v1[p] = v[l+p];
	for(int q=0;q<r-m;q++) v2[q] = v[m+1+q];

	while(l+i<=m && m+1+j<=r)
	{
		if(v1[i]<=v2[j])
		{
			v[k]=v1[i];
			k++;
			i++;
		}

		else
		{
			v[k]=v2[j];
			k++;
			j++;
		}
	}

	
	while(i+l<=m) 
		{
			v[k] = v1[i];
			k++;
			i++;
		}
	
	while(m+1+j<=r) 
		{
			v[k] = v2[j];
			k++;
			j++;
		}
	

}
void mergeSort(std::vector<int> &v,int l,int r)
{
	if(l>=r) return ;
	else 
	{
		int m = l+(r-l)/2;  
		mergeSort(v,l,m);
		mergeSort(v,m+1,r);
		merge(v,l,m,r);
	}
}

main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n;cin>>n;
	vector<int> v(n);
	for(auto i=0;i<n;i++) cin>>v[i];
	debvec(v);
	mergeSort(v,0,v.size()-1);
	debvec(v);
}