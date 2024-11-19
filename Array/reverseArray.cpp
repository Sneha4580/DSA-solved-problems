#include <iostream>
#include <stack>
using namespace std;

// 1) two pointer apporach

void reverseArrayUsingTwoPointer(int arr[], int n){
  int s = 0;
  int e = n-1;

  while(s<=e){
    swap(arr[s],arr[e]);
    s++;
    e--;
  }
}
int main(){
  int arr[5] = {1,2,3,4,5};
  reverseArrayUsingTwoPointer(arr, 5);

  for(int i =0; i<5; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}

// 2) loop 

void reverseArrayUsingLoop(int arr[], int n){
  for(int i = n-1; i>=0; i--){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main(){
  int arr[5] = {1,2,3,4,5};
  reverseArrayUsingLoop(arr, 5);
}

// 3) recursion

void reverseArrayUsingRecursion(int arr[], int s, int e){
  //base case
  if(s>=e){
    return;
  }
  swap(arr[s],arr[e]);
  return reverseArrayUsingRecursion(arr, s+1, e-1);
}

int main(){
  int arr[] ={1,2,3,4,5};
  int n = 5;
  reverseArray(arr, 0, n-1);

  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// 4) using stacks

int reverseArrayUsingStacks(int arr[], int n){
  stack<int> s;

  for(int i=0; i<n; i++){
    s.push(arr[i]);
  }

  for(int i=0; i<n; i++){
    arr[i] = s.top(); //s.top(): This fetches the top element of the stack s without removing it
    s.pop(); //s.pop(): This removes the top element from the stack s after its value has been assigned to the array arr[]
  }
}

int main(){
  int arr[] = {1,2,3,4,5};

  reverseArrayUsingStacks(arr, 5);

  for(int i=0; i<5; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}