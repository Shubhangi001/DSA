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
vector<pll> adj[mx];
vi vis(mx);   
vi dis(mx);
void djikstra(int src){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0,src});
    vis[src]=1;
    dis[src]=0;
    while(!q.empty()){
        pll top=q.top();
        q.pop();
        int n=top.second;
        vis[n]=1;
        for(auto i:adj[n]){    
            int disN_to_I=i.second;                     
            int nodeI=i.first;                     
            if(!vis[i.first])
            {
                int disI_to_src=dis[n]+disN_to_I;
                if(dis[nodeI]>disI_to_src){
                    dis[nodeI]=disI_to_src;
                    q.push({disI_to_src,nodeI});
                }
                
            }
        }
    }
}
int main(){
    ll n,m;
    n=5;
    rep(i,0,n+1){
        adj[i].clear();
    }
    dis.assign(n+1,INT_MAX);
    vis.assign(n+1,0);
    adj[1] = { {2,4},{5,20} };
    adj[2] = { {1,4},{3,5},{4,3} };
    adj[3] = { {2,5},{5,6} };
    adj[4] = { {2,3},{5,15} };
    adj[5] = { {1,20},{4,15},{3,6} };
    rep(i,1,6)
        dis[i]=INT_MAX;

    djikstra(1);
    rep(i,1,6)
    cout<<dis[i]<<" ";
    
}