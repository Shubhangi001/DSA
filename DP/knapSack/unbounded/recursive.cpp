
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        if(n-1==0)
            return (W/wt[0])*val[0];     
        int nottake=knapSack(n-1,W,val,wt);
        int take=INT_MIN;
        if(wt[n-1]<=W)
            take=val[n-1]+knapSack(n,W-wt[n-1],val,wt);  //calling 'n' again, as can be more than one
        return max(take,nottake);
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