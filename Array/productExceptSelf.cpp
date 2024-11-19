#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> arr){
  int n = arr.size();
  vector<int> ans;
  int prod = 1;

  //find product of array
  for(int i=0; i<n; i++){
    prod *= arr[i];
  }
  //calculating array 
  for(int i=0; i<n; i++){
    ans.push_back(prod/arr[i]);
  }
  return ans;
}

vector<int> method2(vector<int> arr){
  int n = arr.size();
  vector<int> ans(n,1);

  for(int i=0; i<n; i++){
    int prod = 1;
    for(int j=0; j<n; j++){
      if(i!=j){
        prod *= arr[j];
      }
    }
    ans[i] = prod;
  }
  return ans;
}

vector<int> optimizedMethod(vector<int>& nums){
  int n = nums.size();
  vector<int> ans(n,1);
  vector<int> prefix(n,1);
  vector<int> suffix(n,1);

  //prefix array
  for(int i=1; i<n; i++){
    prefix[i] = prefix[i-1]*nums[i-1];
  }
  //suffix array
  for(int i=n-2; i>=0; i--){
    suffix[i] = suffix[i+1]*nums[i+1];
  }

  //multiply both the array
  for(int i=0; i<n; i++){
    ans[i] = prefix[i]*suffix[i];
  }
  return ans;
}

int main(){
  vector<int> ans = {1,2,3,4};

  //vector<int> result = productExceptSelf(ans);
  //vector<int> result = method2(ans);
  vector<int> result = optimizedMethod(ans);

  for(int i:result){
    cout<<i<<" ";
  }cout<<endl;
}