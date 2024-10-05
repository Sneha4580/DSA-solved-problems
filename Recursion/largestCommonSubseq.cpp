#include <iostream>
using namespace std;

int lcs(string L1, string L2, int m, int n){
  if(m == 0 || n == 0){
    return 0;
  }
  if( L1[m-1] == L2[n-1]){
    return 1 + lcs(L1, L2, m-1, n-1);
  }else{
    return max(lcs(L1, L2, m-1, n), lcs(L1, L2, m, n-1));
  }
}

int main(){
  string L1 = "ABCDGH";
  string L2 = "AEDFHR";

  int m = L1.length();
  int n = L2.length();

  int res = lcs(L1, L2, m, n);
  cout<<res<<endl;
}