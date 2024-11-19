#include <iostream>
#include <vector>
#include <map>
using namespace std;

string arraySubset(vector<int> a1, vector<int> a2, int n, int m){
  map<int, int> freq;

  for(int i=0; i<n; i++){
    freq[a1[i]]++;
  }
  for(int i=0; i<m; i++){
    if(freq.find(a2[i]) != freq.end() && freq[a2[i]] > 0){
      freq[a2[i]]--;
    }else{
      return "No";
    }
  }
  return "Yes";
}

int main(){
  vector<int> a1 = {1, 2, 3, 4, 4, 5, 6};
  vector<int> a2 = {1, 2, 4};

  cout<<arraySubset(a1, a2, 7, 3)<<endl;
  return 0;
}