#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> height){
  int lp=0, rp = height.size()-1;
  int maxWater = 0;

  while(lp < rp){
    int wt = rp - lp;
    int ht  = min(height[lp], height[rp]);
    int area = wt*ht;

    maxWater = max(area, maxWater);

    height[lp] < height[rp] ? lp++ : rp--;
  }
  return maxWater;
}

int main(){
  vector<int> arr = {1,8,6,2,5,4,8,3,7};

  int ans = maxArea(arr);
  cout<<ans<<endl;

  return 0;
}