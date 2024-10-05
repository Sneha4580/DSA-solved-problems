#include <iostream>
using namespace std;

bool equalPartition(int arr[], int n, int sum){
    //base case
    if(sum == 0) return true ;
    if(n == 0) return false;
    
    //current element is greater than the target sum
    if(arr[n-1] > sum){
        return equalPartition(arr, n-1, sum);
    }
    
    return equalPartition(arr, n-1, sum) || equalPartition(arr, n-1, sum - arr[n-1]);
}

bool canPartition(int arr[], int n){
    int totalSum = 0;
    
    for(int i=0; i<n; i++){
        totalSum += arr[i];
    }
    
    if(totalSum % 2 != 0){
        return false;
    }else{
        return equalPartition(arr, n , totalSum/2);
    }
}

int main(){
    int arr[] = {1,5,5,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bool res = canPartition(arr, n);
    
    // to print values as true or false
    if(res){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

}