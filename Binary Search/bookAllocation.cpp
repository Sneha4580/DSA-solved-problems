#include <iostream>
#include <vector>
using namespace std;

bool isPossi(vector<int> arr, int n, int m, int maxAllowedPages){ //time complexity O(n)
  int stu = 1, pages = 0;
  
  for(int i=0; i<n; i++){
    if(arr[i] > maxAllowedPages){
      return false;
    }
    if(arr[i] + pages <= maxAllowedPages){
      pages += arr[i];
    }else{
      pages = arr[i];
      stu++;
    }
  }

  return stu > m ? false:true;
}

int bookAllocation(vector<int> nums, int n, int m){//time complexity O(logn)
  if(m>n) return -1;

  int sum = 0;

  //calculating sum
  for(int i=0; i<n; i++){
    sum += nums[i];
  }
  int st=0, end = sum;
  int ans = -1;
  while(st<=end){
    int mid = st+(end-st)/2;
    if(isPossi(nums,n,m,mid)){
      ans = mid;
      end = mid-1;
    }else{
      st = mid+1;
    }
  }
  return ans;
}

int main(){
  vector<int> arr = {2,1,3,4};
  
  int ans = bookAllocation(arr, 4, 2);
  cout<<ans<<endl;

  return 0;
}