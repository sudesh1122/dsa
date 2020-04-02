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


// Selection Sort algo
// Time complexity is O(n^2)

std::vector<int> selectionSort(std::vector<int> &v)
{
	int n = v.size();
	for(auto i=0;i<n;i++)
	{
		int imin =i;
		for(int j=i+1;j<n;j++)
			if(v[j]<v[imin]) imin = j;
		// swapping
		int temp =v[i];
		v[i] = v[imin];
		v[imin] =temp;
	}
	return v;
}

main()
{
	int n;
	cin>>n;
	std::vector<int> v(n);
	for(auto i=0;i<n;i++)
		cin>>v[i];
	debvec(v);
	v = selectionSort(v);
	debvec(v);
}
