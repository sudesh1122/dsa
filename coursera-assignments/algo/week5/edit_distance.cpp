/*#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  return 0;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minimum(int a, int b,int c)
{
	int min =a;
	if(min>b)
		min=b;
	if(min>c)
		min=c;
	return min;
}
int edit_distance(string s1,string s2,int i,int j)
{
	if(i==0)
		return j;
	else if(j==0)
		return i;
	else
	{
		if(s1[i-1]==s2[j-1])
		{
			return minimum(edit_distance(s1,s2,i-1,j-1),1+edit_distance(s1,s2,i-1,j),1+edit_distance(s1,s2,i,j-1));
		}
		else
			return minimum(1+edit_distance(s1,s2,i-1,j-1),1+edit_distance(s1,s2,i-1,j),1+edit_distance(s1,s2,i,j-1));
	}
}
/*std::vector<std::vector<int> >*/int edit_distance_eficient(string s1,string s2)
{
	vector<vector<int>> distances(s1.size()+1,vector<int>(s2.size()+1,0));
	for(int i=0;i<=s1.size();i++)
	{
		for(int j=0;j<=s2.size();j++)
		{
			if(i==0)
				distances[i][j]=j;
			else if(j==0)
				distances[i][j]=i;
			else
			{
				if(s1[i-1]==s2[j-1])
					distances[i][j] = minimum(distances[i-1][j-1],1+distances[i-1][j],1+distances[i][j-1]);
				else
					distances[i][j] = minimum(1+distances[i-1][j-1],1+distances[i-1][j],1+distances[i][j-1]);
			}

		}
	}
	return distances[s1.size()][s2.size()];//distances; 
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<edit_distance_eficient(s1,s2)<<endl;
	// vector<vector<int>> v = edit_distance_eficient(s1,s2);
	// for(int i=0;i<s1.size()+1;i++)
	// 	{
	// 		for(int j=0;j<s2.size()+1;j++)
	// 		{
	// 			cout<<v[i][j]<<" ";
	// 		}
	// 		cout<<endl;
	// 	}	
	return 0;	
}