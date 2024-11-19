#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

double medianOfArrays(vector<int>& nums1, vector<int>& nums2){

  if(nums1.size() > nums2.size()){
    return medianOfArrays(nums2, nums1);
  }
  int m = nums1.size();
  int n = nums2.size();
  
  int l=0, h=m;
  while(l <= h){
    int Px = l+(h-l)/2; //mid - for nums1
    int Py = (m+n+1)/2 - Px; //mid - for nums2

    //left half nums
    int x1 = (Px == 0) ? INT8_MIN : nums1[Px-1];
    int x2 = (Py == 0) ? INT8_MIN : nums2[Py-1];

    //right half nums
    int x3 = (Px == m) ? INT8_MAX : nums1[Px];
    int x4 = (Py == n) ? INT8_MAX : nums2[Py];

    if(x1 <= x4 && x2 <= x3){
      if((m+n)%2 == 1){
        return max(x1, x2);
      }
      return (max(x1, x2)+min(x3,x4))/2.0;
    }
    if(x1>x4){
      h = Px -1;
    }else{
      l = Px + 1;
    }
  }
  return -1;
}

int main(){
  vector<int> num1 = {1,4,6,7};
  vector<int> num2 = {9,11,15};

  double ans = medianOfArrays(num1, num2);
  cout<<ans<<endl;

  return 0;
}