#include <iostream>
#include <vector>
using namespace std;

vector<int> sortZeroesOnesTwos(vector<int>& arr){
  int count0 = 0, count1 = 0, count2 = 0;
  for(int i=0; i<arr.size(); i++){
    if(arr[i] == 0) count0++;
    else if(arr[i] == 1) count1++;
    else if(arr[i] == 2) count2++;
  }

  int idx = 0;
  for(int i=0; i<count0; i++){
    arr[idx++] = 0;
  }
  for(int i=0; i<count1; i++){
    arr[idx++] = 1;
  }
  for(int i=0; i<count2; i++){
    arr[idx++] = 2;
  }

  return arr;
}

void DNFmethod(vector<int>& arr){ //time complexity O(n) , space = O(1)
  int n = arr.size();
  int low = 0, mid = 0, high = n-1;

  while(mid <= high){
    if(arr[mid] == 0){
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    }
    else if(arr[mid] == 1){
      mid++;
    }
    else if(arr[mid] == 2){
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

int main(){
  vector<int> ans = {2,0,2,1,1,0};
  //vector<int> result = sortZeroesOnesTwos(ans);

  // for(int i: ans){
  //   cout<<i<<" ";
  // }cout<<endl;

  DNFmethod(ans);

  for(int i:ans){
    cout<<i<<" ";
  }cout<<endl;

  return 0;
}