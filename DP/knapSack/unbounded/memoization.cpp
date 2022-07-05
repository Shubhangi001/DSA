
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
     int ks(int n, int w, int val[], int wt[],vector<vector<int>> &dp){
        if(n-1==0)
            return (w/wt[0])*val[0];
        if(dp[n][w]!=-1)
            return dp[n][w];
        int nottake=ks(n-1,w,val,wt,dp);
        int take=INT_MIN;
        if(wt[n-1]<=w)
            take=val[n-1]+ks(n,w-wt[n-1],val,wt,dp);
        return dp[n][w]=max(take,nottake); 
     }
    
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
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
}  