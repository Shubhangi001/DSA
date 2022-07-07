#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
     int ks(int n, int w, int val[], int wt[],vector<vector<int>> &dp){
        
        for(int i=1;i<=n;i++)
            for(int j=0;j<=w;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(wt[i-1]<=j)
                    take=val[i-1]+dp[i][j-wt[i-1]];
                dp[i][j]=max(take,nottake);
            }
          
        return dp[n][w]; 
     }
    
     int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        for(int i=0;i<=w;i++)
            dp[0][i]=0;
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        return ks(n, w, val, wt,dp);
        
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends