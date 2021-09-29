////Longest increasing Subsequence 
//Q) you are given an array . Find the length of longest increasing subsequence.
///////######Tabulation######

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  vector<int> dp(n,1);
  int ans=0;
  for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
              if(a[i]>a[j]){
                  dp[i] = max(dp[i], 1+dp[j]);
              }
        }
        ans = max(ans,dp[i]);
  }
  cout<<ans;
  return 0;
}


// input:
// 9
// 10 22 9 33 21 50 52 60 80
// output:
// 7