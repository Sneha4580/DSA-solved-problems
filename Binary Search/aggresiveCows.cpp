#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> arr, int c, int stals, int minAllowedDist){
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int cows = 1; 
  int lastStalPosition = arr[0];

  for(int i=1; i<n; i++){
    if(arr[i] - lastStalPosition >= minAllowedDist){
      cows++;
      lastStalPosition = arr[i];
    }
    if(cows == c) return true;
  }
  return false;
}

int aggresiveCows(vector<int> arr, int c, int stals){
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int st = arr[0], end = arr[n-1]-arr[0];
  int ans = -1;

  while(st <= end){
    int mid = st + (end - st)/2;
    if(isPossible(arr, c, stals, mid)){//go to right side
      ans = mid;
      st = mid+1;
    }else{
      end = mid-1;
    }
  }
  return ans;
}

int main(){
  vector<int> arr = {1,2,8,4,9};
  int ans = aggresiveCows(arr,3,5);
  cout<<ans<<endl;

  return 0;
}