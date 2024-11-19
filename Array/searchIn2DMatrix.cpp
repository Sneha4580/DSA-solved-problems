#include <iostream>
#include <vector>
using namespace std;

bool searchInRow(vector<vector<int>> mat, int target, int row){
  int m = mat[0].size();
  int s = 0, end = m-1;

  while(s <= end){
    int mid = s+(end-s)/2;

    if(target == mat[row][mid]){
      return true;
    }else if(target > mat[row][mid]){
      s = mid+1;
    }else{
      end = mid-1;
    }
  }
  return false;
}

bool searchInMatrix(vector<vector<int>> mat, int target){
  int n = mat.size(); //no. of rows
  int m = mat[0].size(); //no. of col

  int sR = 0, eR = n-1;
  while(sR <= eR){
    int mid = sR + (eR-sR)/2;
    if(mat[mid][0] <= target && target <= mat[mid][m-1]){
      //binary search
      return searchInRow(mat, target, mid);
    }else if(target > mat[mid][m-1]){
      sR = mid+1;
    }else{
      eR = mid-1;
    }
  }
  return false;
}

int main(){
  vector<vector<int>> grid = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  int target = 23;
  bool res = searchInMatrix(grid, target);
  cout<<res<<endl;
}