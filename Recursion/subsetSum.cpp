#include <iostream>
using namespace std;

//Subset Sum Problem

bool isSubsetSum(int arr[], int size, int target){
  //base case
  if( size == 0) return false;
  if( target == 0) return true;

  if( arr[size-1] > target){
    return isSubsetSum(arr, size-1, target);
  }

  return isSubsetSum(arr, size-1, target) || isSubsetSum(arr, size-1, target-arr[size-1]);
}

//driver code

int main(){
  int arr[] = {3, 34, 4, 12, 5, 2};
  int size = sizeof(arr)/sizeof(arr[0]);
  int target = 9;

  bool result = isSubsetSum(arr, size, target);
  cout<<result<<endl;
}