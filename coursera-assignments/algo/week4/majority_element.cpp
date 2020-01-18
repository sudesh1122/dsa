#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here

  return -1;
}*/
int get_majority_element(std::vector<long long > &a)
{
  std::vector<long long > v;
  long long current,k=1;
  for(int i=0;i<a.size();i++)
  {
    current = a[i];
    if(current==a[i+1])
    {
      k++;
    }
    else
    {
      v.push_back(k);
      k=1;
    }
  }
  int result=0;
  for(int i=0;i<v.size();i++)
  {
    if(v[i]>(a.size())/2)
    {
      result = 1;
      break;
    }
  }
  return result;

}
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(),a.end());  
  cout<<get_majority_element(a);
  return 0;
}
