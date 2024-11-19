#include <iostream>
#include <vector>
using namespace std;

vector<int> repeatedAndMissingElement(vector<vector<int>>& grid){
  int n = grid.size()*grid.size();
  vector<int> freq(n+1, 0);
  int repeated = -1;
  int missing = -1;

  vector<int> ans;

  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid[0].size(); j++){
      freq[grid[i][j]]++;
    }
  }

  for(int i=0; i<n; i++){
    if(freq[i]==2){
      repeated = i;
    }else if(freq[i] == 0){
      missing = i;
    }
  }
  ans.push_back(repeated);
  ans.push_back(missing);

  return ans;
}

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
  int n = grid.size();
  long long N = n*n;
  vector<int> ans;

  long long expectedSum = N*(N+1)/2;
  long long expectedSquareSum = N*(N+1)*(2*N+1)/6;

  long long actualSum = 0;
  long long actualSquareSum = 0;

  for(const auto& row : grid){
      for(int num:row){
          actualSum += num;
          actualSquareSum += (long long)num*num;
      }
  }

  long long deltaSum = actualSum - expectedSum;
  long long deltaSquareSum = actualSquareSum - expectedSquareSum;

  long long sumOfRepeateMissing = deltaSquareSum/deltaSum;

  int repeated = (deltaSum + sumOfRepeateMissing)/2;
  int missing = repeated - deltaSum;

  ans.push_back(repeated);
  ans.push_back(missing);

  return ans;
}

int main(){
  vector<vector<int>> grid = {
    {1, 2, 3},
    {4, 6, 6},
    {7, 8, 9}
  };

  //vector<int> result = repeatedAndMissingElement(grid);
  vector<int> result = findMissingAndRepeatedValues(grid);
  
  for(int i:result){
    cout<<i<<" ";
  }cout<<endl;
}