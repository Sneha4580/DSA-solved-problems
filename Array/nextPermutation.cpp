#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums){
  int n = nums.size();
  int pivot = -1;

  //finding pivot
  for(int i=n-2; i>=0; i--){
    if(nums[i] < nums[i+1]){
      pivot = i;
      break;
    }
  }

  if(pivot == -1){
    reverse(nums.begin(), nums.end());
    return;
  }

  //finding larger value then pivot in right side
  for(int i=n-1; i>pivot; i--){
    if(nums[i]>nums[pivot]){
      swap(nums[i], nums[pivot]);
      break;
    }
  }

  //reverse the array from pivot + 1 to n-1
  int i = pivot+1, j=n-1;
  while(i<=j){
    swap(nums[i++], nums[j--]);
  }
}

int main(){
  vector<int> arr = {1,2,3};
  nextPermutation(arr);

  for(int i: arr){
    cout<<i<<" ";
  }cout<<endl;

  return 0;
}