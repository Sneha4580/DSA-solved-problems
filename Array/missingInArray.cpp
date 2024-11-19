#include <iostream>
#include <vector>
using namespace std;

int missingElement(vector<int> nums){
  int n = nums.size()+1;
  vector<int> arr;

  int var = 0;
  
  for(int i=1; i<=n; i++){
    var ^= i;
  }

  for(int i=0; i<nums.size(); i++){
    var ^= nums[i];
  }
  
  return var;
}

int main(){
  vector<int> arr = {8, 2, 4, 5, 3, 7, 1};

  int res = missingElement(arr);
  cout<<"missing element is: "<<res<<endl;
  return 0;
}