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
vi dis(mx);

void bfs(int n){
    dis[n]=0;
    queue<int> q;
    q.push(n);
    vis[n]=1;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto i:adj[top]){
            if(!vis[i])
            {
                dis[i]=dis[top]+1;
                q.push(i);
                vis[i]=1;
                
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
    dis.assign(n+1,0);
    bfs(1);
    rep(i,1,n+1){
        cout<<dis[i]<<" ";
    }
}
// 6 7
// 1 2
// 1 5
// 1 3
// 2 5
// 2 4
// 6 3
// 6 4
// 0 1 1 2 1 2