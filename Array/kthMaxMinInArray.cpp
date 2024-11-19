#include <iostream>
#include <algorithm>
using namespace std;

// K’th Smallest Element in Unsorted Array

int kthSmallest(int arr[], int n, int k){
  sort(arr, arr + n); //{1,2,3,4,7,9}
  return arr[k-1];
}
int kthLargest(int arr[], int n, int k){
  sort(arr, arr + n); //{1,2,3,4,7,9}
  return arr[n-k];
}
int main(){
  int arr[] = {1,3,2,9,7,4};
  int ans1 = kthSmallest(arr, 6, 3);
  int ans2 = kthLargest(arr, 6, 3);

  cout<<"kth smallest element is: "<<ans1<<endl;
  cout<<"kth lagest element is: "<<ans2<<endl;

  return 0;
}