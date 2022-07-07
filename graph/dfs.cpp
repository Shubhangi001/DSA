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
vi vis(mx);
/**
 * @brief  * DFS revolves around searching children of a nodes completely then backtracking back to
 * the parent node again to explore further non-visited children.
 * 
 * To do this, simply start the dfs from a source marking it as visited inside the dfs
 * function. Now loop over all the children of the node and do a dfs if not visited.
 * 
 * @param n 
 */
void dfs(int n){
    cout<<n<<" ";
    vis[n]=1;
    for(auto i:adj[n]){
        if(!vis[i]){
            dfs(i);
        }
    }
} 
int main()
{
    int n,m;
    cin>>n>>m; //nodes, edges
    rep(i,1,n+1){
        adj[i].clear();

    }
    vis.assign(n+1,0);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    return 0;
}