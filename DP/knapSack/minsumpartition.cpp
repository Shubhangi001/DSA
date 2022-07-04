#include <bits/stdc++.h>
using namespace std;
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
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
        int start=0,mn=sum;
        for(int i=0;i<sum/2+1;i++){
            if(dp[n][i]==1){
                int x=sum-i;
                mn=min(mn,abs(x-i));
                
                
            }
        }
        return mn;
	} 
};

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  