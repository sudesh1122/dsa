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


// Bubble Sort Algo
// Time Complexity is O(n^2)


vector<int> bubbleSort(vector<int> v)
{
	int n = v.size();
	for(int i=0;i<n;i++)
	{
		bool flag = true;
		for(int j=1;j<n-i;j++)
			if(v[j-1]>v[j]) 
				{
					int temp =v[j];
					v[j]=v[j-1];
					v[j-1]=temp;
					flag = false;
				}	
		if(flag) break;
	}
	return v;
}

main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n;cin>>n;
	vector<int> v(n);
	for(auto i=0;i<n;i++) cin>>v[i];
	debvec(v);
	v= bubbleSort(v);
	debvec(v);
}