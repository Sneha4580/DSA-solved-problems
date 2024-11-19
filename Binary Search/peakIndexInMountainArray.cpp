#include <iostream>
#include <vector>
using namespace std;

int peakIndex(vector<int> arr, int st, int end){
  while(st <= end){
    int mid = st + (end - st)/2;
    if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
      return mid;
    }else if(arr[mid] < arr[mid+1]){
      st = mid+1;
    }else{
      end = mid-1;
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {0,3,8,9,5,2};
  int st = 1, end = arr.size()-2;
  int ans = peakIndex(arr, st, end);
  cout<<ans<<endl;
}