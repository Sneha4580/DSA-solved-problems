#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target){
  vector<int> ans;
  int n = nums.size();
  int s = 0, e = n-1;
  
  while (s<e)
  {
    if(nums[s] + nums[e] < target){
      s++;
    }else if(nums[s] + nums[e] > target){
      e--;
    }else{
      ans.push_back(s);
      ans.push_back(e);
      return ans;
    }
  }
  return ans;
}

int main(){
  vector<int> arr = {2,7,11,15};

  vector<int> result = pairSum(arr, 26);
  cout<<result[0]<<", "<<result[1]<<endl;

  return 0;
}