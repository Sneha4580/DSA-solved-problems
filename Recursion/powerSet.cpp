#include <iostream>
#include <math.h>
using namespace std;

// void powerSet(string s, int n){
//   for(int i=0; i<=(pow(2,n)-1); i++){
//    string sub ="";
//     for(int j=0; j<=n-1; j++){
//       if(i&(1<<j)){
//         sub += s[j];
//       }
//     }
//     cout << sub << endl;
//   }
// }

// time conplexity --> O(2^n x n)

// by recursion 

void powerSet(string str, int index, string sub = ""){
  int size = str.length();

  //base case
  if(index == size){
    cout<<sub<<endl;
    return;
  }

  //recursive relation

  //Exclude the current character and proceed to the next
  powerSet(str, index + 1, sub);

  //Include the current character in the current subsequence and proceed to the next
  powerSet(str, index + 1, sub + str[index]);
}

int main(){
  string str = "abc";
  powerSet(str, 0, "");

  return 0;
}