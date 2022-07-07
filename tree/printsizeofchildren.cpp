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
const int mx=2e5+5;
vi adj[mx];           
/**
 * @brief 
 * size of the tree means the number of nodes in it 
 * @param n node
 * @param p parent
 * @return int size
 */
int dfs(ll n,ll p){                                       
    int size=1;              //node itself means size 1
    for(auto i:adj[n]){
        if(i!=p){
            int s=dfs(i,n);  //size returned by its children
            size+=s;           
        }
    }
    cout<<n<<" "<<size<<"\n";
    return size;
}
int main()
{
    ll n;
    cin>>n;
    rep(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int ans=dfs(1,0);
   
//     6
// 1 2
// 1 3 
// 3 4 
// 3 5
// 4 6
    
}