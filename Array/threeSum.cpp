#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> arr){
  int n = arr.size();
  vector<vector<int>> ans;

  sort(arr.begin(), arr.end());

  for(int i=0; i<n; i++){
    if(i > 0 && arr[i] == arr[i-1]) continue;

    int lo = i+1, hi = n-1;
    
    while(lo<hi){
      int current = arr[i] + arr[lo] + arr[hi];

      if(current == 0){

        ans.push_back({arr[i], arr[lo], arr[hi]});

        while(lo<hi && arr[lo] == arr[lo+1]) lo++;
        while(lo<hi && arr[hi] == arr[hi-1]) hi--;

        lo++;
        hi--;
      }
      else if(current < 0){
        lo++;
      }else{
        hi--;
      }
    }
  }
  return ans;
}

int main(){
  vector<int> arr = {-1,0,1,2,-1,-4};
  vector<vector<int>> ans = threeSum(arr);
  
  for (const auto& triplet : ans) {
    for (int num : triplet) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}