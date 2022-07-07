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
 * @brief breadth wise traversal
 * 
 * BFS is basically exploring the graph breadth by breadth. Simply put, it is like a circle growing in
 * radius or water spreading from a point source.
 * @param src source
 */
void bfs(int src){
    queue<int> q;          
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        cout<<top<<" ";        
        for(auto i:adj[top]){  //iterating over all connected nodes
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;             //once we push in the queue, it's visited
                
            }
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    rep(i,0,n+1){
        adj[i].clear();
    }
    rep(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vis.assign(n+1,0);
    bfs(1);
}