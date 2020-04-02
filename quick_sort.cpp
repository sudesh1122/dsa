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

// implementation of quick sort algorithm,an in-line algorithm
// average time complexity is O(nlog(n))   //in-line sorting algo -> no need of any auxiliary vector/array.
// worst case time complexity is O(n^2)
// merge-sort algo is not in-line algo

int partition(std::vector<int> &v,int l,int r)
{
	int pivot = v[r]; // choose a random pivot element
	int pi=l;
	for(int i=l;i<r;i++)
	{
		if(v[i]<pivot)
		{	
			// swapping
			int temp = v[i];
			v[i] = v[pi];
			v[pi] = temp;
			pi++;
		}
	}

	int temp = v[pi];
	v[pi] = pivot;
	v[r] = temp;
	return pi;
}



void quickSort(std::vector<int> &v,int l,int r)
{
	if(l<r)
	{
		int p = partition(v,l,r);
		quickSort(v,l,p-1);
		quickSort(v,p+1,r);
	}
	else return;
}


main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n;
	cin>>n;
	std::vector<int> v(n);
	for(auto i=0;i<n;i++)
		cin>>v[i];
	debvec(v);
	quickSort(v,0,n-1);
	debvec(v);
}