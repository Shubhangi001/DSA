#include<bits/stdc++.h>
using namespace std;
class Solution
{
     public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        static vector<vector<int>> t(n+1,vector<int>(W+1,-1));
        if(W==0||n==0)  //minimum input condition, either max weight is 0 or array has no weights
            return 0;
            //choice diagram
        if(t[n][W]!=-1)
            return t[n][W];
        else if(wt[n-1]<=W)
            return t[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1)); //max between taking that weight and not taking
        else
            return t[n][W]=knapSack(W,wt,val,n-1); //if it's greater than max weight, can't take
        
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