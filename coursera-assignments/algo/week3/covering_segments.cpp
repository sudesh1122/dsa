#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
using namespace std;

using std::vector;

struct Segment {
  int start, end;
};  
vector<int> optimal_points(vector<pair<int,int>> &segments) {
  vector<int> points;
  int a,b,c,i,j;
  for(i=0;i<segments.size();i++)
  {
    a = segments[i].second;
    for(j=i+1;j<segments.size();j++)
    {
      b = segments[j].first;
      c = segments[j].second;
      if(b>a)
      { 
        j = segments.size();
      }
      else if(a>=b && a>c)
      {
        a = c;
        i++;
      }
      else
        i++;
    }
    points.push_back(a);
  }
  //cout<<"\n\n\n\n";
  /*for (auto i = 0; i < segments.size(); ++i) {
4    points.push_back(segments[i].end);
  }*/
  return points;
}

int main() {
  int n,a,b;
  std::cin >> n;
  /*vector<Segment> segments(n);
  for (auto i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

 
  /*vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }*/

  std::vector<pair <int,int>> segments;
  for(auto i=0;i<n;i++)
  {
    cin>>a>>b;
    segments.push_back(make_pair(a,b));
  }

  sort(segments.begin(),segments.end());
  /*cout<<"After sorting elements are: "<<endl;

  for(auto i=0;i<segments.size();i++)
  {
    cout<<segments[i].first<<" "<<segments[i].second<<endl;
  }
  cout<<"\n\n\n";*/
  vector<int> points = optimal_points(segments);
  set<int> set(points.begin(),points.end()); 
  /*for(const int &i: points)
    set.insert(i);*/
  std::cout << set.size() << "\n";
  for(const int &i: set)
    cout<<i<<" ";

   
}
