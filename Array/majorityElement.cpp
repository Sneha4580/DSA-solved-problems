#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> nums, int n){
  for(int val:nums){
    int freq = 0;
    for(int el: nums){
      if(val == el){
        freq++;
      }
    }
    if(freq > n/2){
      return val;
    }
  }
}

int method2(vector<int> nums){
  int n = nums.size();
  int freq = 1;
  int ans = nums[0];

  for(int i=1; i<n; i++){
    if(nums[i] == nums[i-1]){
      freq++;
    }else{
      freq = 1;
      ans = nums[i];
    }
  }
  return ans;
}

int mooresMethod(vector<int> arr){
  int n = arr.size();
  int freq = 0, ans = 0;
  for(int i=0; i<arr.size(); i++){
    if(freq == 0){
      ans = arr[i];
    }
    if(ans == arr[i]){
      freq++;
    }else{
      freq--;
    }
  }
  
  int count = 0;
  for(int i : arr){
    if(ans == arr[i]){
      count ++;
    }
  }

  if(count > n/2){
    return ans;
  }else{
    return -1;
  }

  return ans;
}

int main(){
  vector<int> ans = {2,3,4,5,6,6,6,6};
  //int res = majorityElement(ans, 3);

  int res = mooresMethod(ans);
  cout<<"majority element is: "<<res<<endl;

  return 0;
}