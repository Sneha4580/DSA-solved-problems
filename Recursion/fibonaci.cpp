#include <iostream>
using namespace std;

int fibonacci(int n){
  //base case
  if(n == 0 || n == 1){
    return n;
  }
  // recursive relation
  return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;

  int result = fibonacci(n);
  cout<<result<<endl;

  return 0;
}