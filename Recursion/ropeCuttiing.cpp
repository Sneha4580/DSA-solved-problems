#include <iostream>
#include <limits.h>
using namespace std;

//Maximize The Cut Segments

//Problem Statement: --> Maximize The Cut Segments --> Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers. After performing all the cut operations, your total number of cut segments must be maximum. 
//Note: if no segment can be cut then return 0. 

int ropeCutting(int n, int x, int y, int z){
  //base case
  if(n==0) return 0;
  if(n<0) return INT_MIN;

  int a = ropeCutting(n-x, x, y, z) + 1;
  int b = ropeCutting(n-y, x, y, z) + 1;
  int c = ropeCutting(n-z, x, y, z) + 1;

  //recursive relation

  int ans = max(a, max(b,c));
  return ans;
}

//Driver code

int main(){
  int n = 8;
  int x = 1, y = 4, z = 4;

  int result = ropeCutting(n,x,y,z);
  if(result<0){ //agar result neg mai aa rha hai toh
    cout<<"no valid cutts possible"<<endl;
  }else {
    cout<<"cutts possible: "<<result<<endl;
  }
}