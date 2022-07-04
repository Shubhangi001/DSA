// https://leetcode.com/problems/target-sum/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {  //exactly same as subsetdiff, as we can just group the minus ones together, so s1-s2
         int sum=0,n=arr.size();
        for(int i=0;i<n;i++) 
            sum+=arr[i];
        if((target+sum)%2!=0||abs(target)>sum)
            return 0;
        sum=(target+sum)/2;  //s1+s2=sum, s1-s2=d
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<n+1;i++){                   //initialisation
            for(int j=0;j<sum+1;j++){
                if(i==0)                    //if no value taken in array, then no sum possible except 0
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;           //sum 0 is always possible, empty subset
                
            }
        }
    long long x=1e9+7;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j)                 //if current element is less than the sum which we're currently forming
                    dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%x;   //if any of one is true, i.e., taking the element or not taking then true
                else
                    dp[i][j]=dp[i-1][j]%x;   //if element more, than can't take for sure, so true or false depends on when we didn't consider the element
            }
        }
        return dp[n][sum]%x;
    }
};