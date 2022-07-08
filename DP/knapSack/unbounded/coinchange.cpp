// https://practice.geeksforgeeks.org/problems/coin-change2448/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  /**
   * @brief combo of subset sum and unbounded knapsack
   * 
   * @param S coin denominations present
   * @param n size of array
   * @param m cents to make
   * @return long long int 
   */
    long long int count(int S[], int n, int m) {
        vector<vector<long long int>> dp(n+1,vector<long long int>(m+1));
        for(int i=0;i<m+1;i++)
            dp[0][i]=0;                   //if the size of array is 0 then we can't make cents more than 0
        for(int i=0;i<n+1;i++)
            dp[i][0]=1;                   //we can always make cent of zero (empty set)
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                long long int nottake=dp[i-1][j];
                long long int take=0;
                if(S[i-1]<=j){
                    take=dp[i][j-S[i-1]];
                }
                dp[i][j]=take+nottake;
            }
        }
        return dp[n][m];
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
} 