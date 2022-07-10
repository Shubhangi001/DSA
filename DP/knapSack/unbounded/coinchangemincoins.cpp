//https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/#

#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
    /**
     * @brief we've to find min no of coins which will sum up to V
     * unbounded knapsack; we can this as knapsack with weight and value array where all values are 1
     * as taking one coin of any denomination will have 1 value only, and since we've to take minimum
     * no. of coins, we're initialising not possible as INT_MAX.
     * @param coins denominations available
     * @param M size of coins array
     * @param V total cost
     * @return int 
     */
	int minCoins(int coins[], int M, int V) 
	{ 
	   vector<vector<int>> dp(M+1,vector<int>(V+1));
	   for(int i=0;i<M+1;i++)
	        dp[i][0]=0;
	   for(int i=0;i<V+1;i++)
	        dp[0][i]=INT_MAX-1;
	   for(int i=1;i<M+1;i++){
	       for(int j=1;j<V+1;j++){
                int nottake=dp[i-1][j];
                int take=INT_MAX;
                if(coins[i-1]<=j)
                    take=dp[i][j-coins[i-1]]+1;
                dp[i][j]=min(take,nottake);
	       }
	   }
	   return (dp[M][V]>=INT_MAX-1)?-1:dp[M][V];
	} 
	  
};

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;
        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
