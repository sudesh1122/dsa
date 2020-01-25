/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
std::vector<> v;

int main() 
{
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

std::vector<pair<int,vector<int>>> noStep(int n)
{
  std::vector<pair<int,vector<int>>> rsteps(0,make_pair((long long)0,std::vector<int>((long long) 0)));
  std::vector<int> v;
  rsteps.push_back(make_pair(0,v));
  rsteps[0].first=0;
  rsteps[0].second.push_back(0);
  for(int i=1;i<=n;i++)
  {
    rsteps.push_back(make_pair(0,v));
    int minSteps=0;
    if(i%3==0)
    {
      minSteps = min(1+ rsteps[i/3].first,1+rsteps[i-1].first);
      if(minSteps == 1+rsteps[i/3].first)
      {
        for(auto x:rsteps[i/3].second)
          rsteps[i].second.push_back(x);
        rsteps[i].second.push_back(3);
      }    
      else 
      {
        for(auto x:rsteps[i-1].second)
          rsteps[i].second.push_back(x);
      }
    }
    else if(i%2==0)
    {
      minSteps=min(1+rsteps[i/2].first,1+rsteps[i-1].first);
      if(minSteps==1+rsteps[i/2].first)
      {
        for(auto x:rsteps[i/2].second)
          rsteps[i].second.push_back(x);
        rsteps[i].second.push_back(2);
      }
      else
      {
        for(auto x:rsteps[i-1].second)
          rsteps[i].second.push_back(x);
        rsteps[i].second.push_back(1);
      }
    }
    else
    {
      minSteps = min(1+ rsteps[i-1].first,2+rsteps[i-2].first);
      if(minSteps==1+rsteps[i-1].first)
      {
        for(auto x:rsteps[i-1].second)
          rsteps[i].second.push_back(x);
        rsteps[i].second.push_back(1);
      }
      else
      {
        for(auto x:rsteps[i-2].second)
          rsteps[i].second.push_back(x);
        rsteps[i].second.push_back(1);
        rsteps[i].second.push_back(1);
      }
    }
    rsteps[i].first = minSteps;
  }
  return rsteps;
}
int main()
{
  int n;
  cin>>n;
  std::vector<pair<int,vector<int>>> outputs = noStep(n);
  //cout<< noStep(n,outputs)-1<<endl;
  cout<<outputs[n].first-1<<endl;
  // for(auto x:outputs[outputs.size()-1].second)
  //   cout<<x<<" ";
  // cout<<endl;
  std::vector<int> final;
  int k=1;
  final.push_back(1);
  vector<int> f= outputs[outputs.size()-1].second;
  for(auto i=2;i<f.size();i++)
  {
    auto x = f[i];
    if(x==1)
    {
      k++;
      final.push_back(k);
    }
    else if(x==2)
    {
      k*=2;
      final.push_back(k);
    }
    else
    {
      k*=3;
      final.push_back(k);
    }
  }
  for(auto x:final)
    cout<<x<<" ";
  cout<<endl;
  return 0;

}

