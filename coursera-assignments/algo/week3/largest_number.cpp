#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string maxdigit(string a,string b)
{
  
  if(a+b>b+a)
    return a;
  else
    return b;
}
string  largest_number(vector<string> a) {
  string digit;
  string maxnumber="";
  while(a.size()!=0)
  {
    digit= "0";
    for(int i=0;i<a.size();i++)
    {
      digit = maxdigit(digit,a[i]);
    }
    maxnumber.append(digit);
    std::vector<string>::iterator it = std::find(a.begin(),a.end(), digit);
    a.erase(it);
    //a.erase(std::remove(a.begin(), a.end(), digit), a.end());
  }
  return maxnumber;
}
int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (auto i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
  return 0;

}