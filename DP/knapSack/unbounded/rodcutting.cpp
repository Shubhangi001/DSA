// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> length(n);
        for(int i=1;i<n+1;i++)
            length[i-1]=i;
        vector<vector<int>> dp(length.size()+1,vector<int>(n+1));
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                int nottake=dp[i-1][j];
                int take=INT_MIN;
                if(length[i-1]<=j)
                    take=dp[i][j-length[i-1]]+price[i-1];
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[n][n];
            
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends