#include <iostream>
using namespace std;

//Problem Statement -- You are given a set of non-negative integers and a value sum. Your task is to count how many subsets of the given set have a sum of elements equal to the given sum. 

int countSubsets(int arr[], int n, int sum){
  //base case
  if (n == 0) return (sum == 0) ? 1 : 0; 

  return countSubsets(arr, n-1, sum) + countSubsets(arr, n-1, sum - arr[n-1]);
}

int main(){
  int arr[] = {10, 5, 2, 3, 6};
  int sum = 8;
  int n = sizeof(arr)/sizeof(arr[0]);

  int res = countSubsets(arr, n, sum);
  cout<<res<<endl;
}