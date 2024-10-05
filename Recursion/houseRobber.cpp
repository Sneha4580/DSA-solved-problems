#include <iostream>
#include <limits.h>
using namespace std;

// House Robber

//Problem Statement: --> House Robber <-- automatically contact the police if two adjacent houses are broken into on the same night.  

int solve(int arr[], int size, int index){
  //base case
  if(index>=size) return 0; 

  //chori karo
  int opt1 = arr[index] + solve(arr, size, index+2);
  //chori mat karo
  int opt2 = 0 + solve(arr, size, index+1);

  int ans = max(opt1, opt2);
  return ans;

}

int main(){
  int arr[] = {1,2,3,1};
  int size = sizeof(arr) / sizeof(arr[0]);

  int res = solve(arr, size, 0);
  cout<<"max amount that can be robbed: "<< res <<endl;

  return 0;
}