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


vector<int> insertionSort(std::vector<int> &v)
{
	int n =v.size();
	for(int i=1;i<n;i++)
	{
		int value = v[i];
		int j =i;
		// deb(i);
		while(j>0 && v[j-1]>value)
		{
			v[j] = v[j-1];
			j--;
			// deb(j);
			// deb(v[j]);
		}
		// deb(j);
		v[j]=value;
		// deb(v[j]);
	}
	return v;
}

main()
{
	int n;
	cin>>n;
	std::vector<int> v(n);
	for(auto i=0;i<n;i++) cin>>v[i];
	v = insertionSort(v);
	for(auto i:v) cout<<i<<" ";
	cout<<endl;
}