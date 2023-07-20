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
#define int ll
const int mx=2e5+5;
vi prime_factors(int n){
  vi v;
   for(int i = 2; i <= sqrt(n); i++){
      if(n%i == 0){
          while(n%i == 0){
              v.push_back(i);
              n = n/i;
          }
      }
  }
  if(n > 1) v.push_back(n);
  return v;
}
class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int n){
            val = n;
            left = NULL;
            right = NULL;
        }
        
};
class Solution
{
     public:
    void solve(ll testcase) 
    { 
        TreeNode *root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->right = new TreeNode(1);
        TreeNode *
        
    }
};      
int32_t main()
 {
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1,i=1;
    // cin>>t;
    while(t--)
    {
       
        Solution ob;
        ob.solve(i);
        i++;        
        cout<<endl;
        
    }
    return 0;
}