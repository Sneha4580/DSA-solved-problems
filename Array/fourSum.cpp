#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& arr, int target) {
  int n = arr.size();
  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());

 for(int i=0; i<n; i++){
  if(i > 0 && arr[i] == arr[i-1]) continue;
    for(int j=i+1; j<n; j++){
      if(j > i+1 && arr[j] == arr[j-1]) continue;

        int low = j+1, high=n-1;

        while(low < high){
          long long current = (long long)arr[i] + arr[j] + arr[low] + arr[high];
          if(current == target){
            ans.push_back({arr[i], arr[j], arr[low], arr[high]});

            while(low<high && arr[low] == arr[low+1]) low++;
            while(low<high && arr[high] == arr[high-1]) high--;

            low++;
            high--;
          }
          else if(current < target){
            low++;
          }else{
            high--;
          }
        }
      }
    }
  return ans;
}

int main(){
  vector<int> arr = {1,0,-1,0,-2,2};
  vector<vector<int>> result = fourSum(arr,0);
  
  for (const auto& quadruplets : result) {
    for (int num : quadruplets) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}