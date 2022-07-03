//https://codeforces.com/contest/1516/problem/C
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void ynans(bool x){if(x) cout<<"YES";else cout<<"NO";}
#define vi vector<int>
#define rep(i,k,n) for(ll i=k;i<n;i++)
#define rof(i,k,n) for(ll i=k;i>n;i--)
#define pb(x) push_back(x)
#define sp(x,y) fixed<<setprecision(y)<<x
int sum() { return 0; }
template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vll vector<ll>
#define vvi vector < vi >
#define pll pair<ll, ll>
#define ff first
#define ss second
#define casePrint(x,y) cout<<"Case #"<<x<<": "<<y;
#define all(c) c.begin(),c.end()
class Solution
{
     public:
    void solve() 
    { 
        ll n,sm=0,ans=-1;
        cin>>n;
        vll a(n);
        rep(i,0,n){
            cin>>a[i];
            sm+=a[i];
            if(a[i]%2!=0)
                ans=i;
        }
        if(sm%2){
            cout<<0;
            return;
        }
        else{
            sm/=2;
            vvi dp(n+1,vi(sm+1,-1));
            rep(i,0,sm+1)
            dp[0][i]=0;
            rep(i,0,n+1)
                dp[i][0]=1;
            rep(i,1,n+1){
                rep(j,1,sm+1){
                    if(a[i-1]<=j)
                        dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
            if(dp[n][sm]){
                if(ans!=-1)
                cout<<1<<"\n"<<ans+1;
                else{
                    int ans=-1;
                    while(1){
                        rep(i,0,n){
                            a[i]/=2;
                            if(a[i]%2!=0){
                                ans=i;
                                // break;
                            }
                            // ok=1;
                        }
                        if(ans!=-1)
                            break;
                    }
                    cout<<1<<"\n"<<ans+1;

                }
            }
            else
                cout<<0;
            
            
        }
        
    }
};      
int main()
 {
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    // cin>>t;
    while(t--)
    {
       
        Solution ob;
        ob.solve();
        cout<<endl;
        
    }
    return 0;
}