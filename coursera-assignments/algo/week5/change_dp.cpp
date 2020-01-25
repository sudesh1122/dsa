#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	int val;
	cin>>val;
	std::vector<int> coins(3);
	coins={1,3,4};
	std::vector<int> values;
	values.push_back(0);
	bool possible = false;
	for(int money=1;money<=val;money++)
	{	
		int min = INT_MAX;
		for(int j=0;j<3;j++)
		{
			if(money>=coins[j])
			{
				if(min>1+values[money-coins[j]] && values[money-coins[j]]!=-1) //also check non-changeable condition 
				{
					min= 1+ values[money-coins[j]];
					possible = true;
				}
			}
		}
		if(possible==false)
			values.push_back(-1);//If it's not possible to change then value is -1
		else
			values.push_back(min);
	}
	cout<<values[val]<<endl;
	return 0;
}