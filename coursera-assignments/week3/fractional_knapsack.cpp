#include <iostream>
#include <vector>
#include <utility>
#include <algorithm> 
#include <iomanip>
using namespace std;

struct data
{
  int weight;
  int value;
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  int n = values.size(),k=0,a;
  std::vector<data> v(n);
  vector<pair <double,int> > ratio;
  for(int i=0;i<n;i++)
  {
    ratio.push_back(make_pair((double)values[i]/weights[i],i));
  }
  sort(ratio.begin(),ratio.end());
  /*for(int i=0;i<n;i++)
  {
    cout<<ratio[i].first<<" ";
    cout<<ratio[i].second<<endl;
  }*/
  for(int i=0;i<n;i++)
  {
    int j = ratio[i].second;
    struct data Temp = {weights[j],values[j]};
    v.insert(v.begin(),Temp);
  }
  /*for(int i=0;i<n;i++)
  {
    cout<<v[i].value<<" ";
    cout<<v[i].weight<<endl;
  }*/
  while(k<n)
  {
    if(capacity==0)
      break;
    a = min(v[k].weight,capacity);
    capacity-=a;
    value +=(double)a*(v[k].value)/(v[k].weight);
    v[k].weight-=a;
    k++;
  }
  return value;

}
int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = (double)get_optimal_value(capacity, weights, values);
  std::cout.precision(7);
  cout << fixed << setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
