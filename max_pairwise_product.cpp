#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

/*int MaxPairwiseProduct_naive(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}*/
long long MaxPairwiseProduct(const vector<int>& numbers)
{
    long long i,index1 = -1,index2 =-1;
    long long max_product;
    for(i=0;i<numbers.size();i++)
    {
        if(numbers[i]>numbers[index1])
            index1 = i;
    }

    for(i=0;i<numbers.size();i++)
    {
        if(numbers[i]>numbers[index2] && i!= index1)
            index2 = i;
    }
    //cout<<index1<<" "<<index2<<endl;
    max_product =(long long) numbers[index1]*numbers[index2];
    return max_product;
}
/*long long MaxPairwiseProduct_sorting(vector<int> numbers)
{
    
    sort(numbers.begin(), numbers.end(), greater<int>()); 
   
    return (long long)numbers[0]*numbers[1];
    
}*/


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    //cout << MaxPairwiseProduct_sorting(numbers) << "\n";
    return 0;
}
