#include <iostream>
using namespace std;

int countWays(int arr[], int n, int sum){
  //base case
  if(sum == 0) return true;
  if(sum<0) return false;

  if( n == 0 && sum >0) return false;

  //recursive relation
  return  countWays(arr, n-1, sum) + countWays(arr, n, sum-arr[n-1]);
}

int main(){
  int arr[] = {1,2,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int sum = 4;

  int res = countWays(arr, n , sum);
  cout<<res<<endl;
}