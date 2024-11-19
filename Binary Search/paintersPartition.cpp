#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> arr, int n, int p, int maxAllowedUnits){
  int painters = 1, units = 0;


  for(int i=0; i<n; i++){
    if(arr[i] > maxAllowedUnits){
      return false;
    }
    if(arr[i] + units <= maxAllowedUnits){
      units += arr[i];
    }else{
      units = arr[i];
      painters++;
    }
  }

  return painters <= p ? true: false;
}

int paintersPartition(vector<int> arr, int n, int p){
  if(p > n) return false;

  int sum=0;
  for(int i=0; i<n; i++){
    sum += arr[i];
  }
  int st=0, end = sum;
  int ans = -1;
  while(st <= end){
    int mid = st + (end - st)/2;
    if(isValid(arr, n, p, mid)){
      ans=mid;
      end = mid-1;
    }else{
      st = mid+1;
    }
  }
  return ans;
}

int main(){
  vector<int> arr = {40,30,10,20};
  int ans = paintersPartition(arr, 4, 2);

  cout<<ans<<endl;
  return 0;
}