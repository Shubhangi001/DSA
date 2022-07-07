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
vi size(mx);
/**
 * @brief 
 * height of node is the number of edges on longest path from node to a leaf
 * @param n node
 * @param p parent
 * @return int height
 */
int dfs(int n,int p){
    int height=0; //if it has no children, then height is 0
    for(auto i:adj[n]){
        if(i!=p){
            height=max(height,dfs(i,n));   //height is max of height of its subtree/children
        }
    }
    cout<<n<<" "<<height<<"\n";
    return height+1;
} 
int main()
{
    int n;
    cin>>n; //nodes
    rep(i,1,n+1){
        adj[i].clear();

    }
    size.assign(n+1,1);
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    return 0;
}