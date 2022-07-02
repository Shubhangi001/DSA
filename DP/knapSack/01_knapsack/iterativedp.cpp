#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        for(int i=0;i<n+1;i++){   //initialisation--> analogous to base condition in recursion
            for(int j=0;j<w+1;j++)
                if(i==0||j==0)
                    dp[i][j]=0;
        } 
        for(int i=1;i<n+1;i++){  //filling dp table
            for(int j=1;j<w+1;j++){   //dp[i][j] denotes max profit for j weight while only considering i items
                if(wt[i-1]<=j){                  //if weight of current item less than max weight at that point
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);  //max of (current value+dp max value when item not considered)
                }                                                           //dp value for that max weight when item not considered 
                else  //else for that max weight, it will be same as dp value calculated when we didn't consider current item
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w];
    }
};

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 