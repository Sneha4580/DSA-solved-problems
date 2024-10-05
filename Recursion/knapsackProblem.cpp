#include <iostream>
using namespace std;

int knapsack(int w, int wt[], int val[], int n){
  //base case
  if(n==0 || w==0) return false;

  if(wt[n-1]>w){
    return knapsack(w,wt,val,n-1);
    
  }
}