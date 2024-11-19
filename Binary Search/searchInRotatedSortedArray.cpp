#include <iostream>
#include <vector>
using namespace std;

int  rotatedSortedArray(vector<int> arr, int key, int st, int end){
  while(st<=end){
    int mid = st + (end-st)/2;
    if(arr[mid] == key){
      return mid;
    }
    if(arr[st] < arr[mid]){//left part sorted
      if(arr[st] <= key && key <= arr[mid]){
        end = mid-1;
      }else{
        st = mid+1;
      }
    }else{
      if(arr[mid] <= key && key <= arr[end]){
        st = mid+1;
      }else{
        end = mid-1;
      }
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {4,5,6,1,2,3};

  int res = rotatedSortedArray(arr,5 , 0, 5);
  cout<<res<<endl;
}