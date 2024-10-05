#include <iostream>
using namespace std;

//Stair Case problem

//problem statement: --> Stair Case problem --> You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

int stairCase(int n){
  //base case 
  if(n == 0) return 1;
  if( n < 0) return 0;

  // recursive relation
  return stairCase(n-1) + stairCase(n-2);
}

//driver code
int main(){
  int n ;
  cout<<"Enter the number of stairs(n): ";
  cin>>n;

  int result = stairCase(n);
  cout<<result<<endl;

  return 0;
}