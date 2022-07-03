//Given an array of non-negative integers, and a value sum, 
//determine if there is a subset of the given set with sum equal to given sum. 
#include<bits/stdc++.h> 
using namespace std; 
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){  //bhery similar to knapsack
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        for(int i=0;i<n+1;i++){                   //initialisation
            for(int j=0;j<sum+1;j++){
                if(i==0)                    //if no value taken in array, then no sum possible except 0
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;           //sum 0 is always possible, empty subset
                
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j)                 //if current element is less than the sum which we're currently forming
                    dp[i][j]=(dp[i-1][j-arr[i-1]]||dp[i-1][j]);   //if any of one is true, i.e., taking the element or not taking then true
                else
                    dp[i][j]=dp[i-1][j];   //if element more, than can't take for sure, so true or false depends on when we didn't consider the element
            }
        }
        return dp[n][sum];
    }
    
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  