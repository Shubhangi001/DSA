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
/**
 * @brief djikstra - to find single source shortest path,
 * here in contrast to queue used in bfs for finding shortest dist in an unweighted graph,
 *  we're using priority queue, coz in unweighted graph all connected node to a node had distance as 1,
 * but here the connected nodes have different weights/distances, so we use min priority queue, putting min
 * distance at the top, and then finding the min distance from source
 * 
 * 
 * @param src 
 */
void djikstra(int src){
    priority_queue<pll, vector<pll>, greater<pll>> q; //the pair contains {weight, node},putting weight as first index to sort based on weight
    q.push({0,src}); 
    vis[src]=1;
    dis[src]=0;
    while(!q.empty()){
        int top=q.top().second;
        q.pop();
        vis[top]=1;    //only when we pop it, we're marking vis as 1 in contrast to unweighted as in unweighted, the node when visited for first time 
                       //will calculate the shortest path, but in weighted graph, the distance can be smaller when we cover more edges
                        //1-2-3-4 taking same example, if 1-4 is connected and weight b/w them is 10, but weights b/w 1-2,2-3,3-4 are 2 each then
                        //smallest distance will be 8


        for(auto i:adj[top]){    
            int disTop_to_I=i.second;                     
            int nodeI=i.first;                     
            if(!vis[i.first])
            {
                int disI_to_src=dis[top]+disTop_to_I;
                if(dis[nodeI]>disI_to_src){
                    dis[nodeI]=disI_to_src;
                    q.push({dis[nodeI],nodeI});
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
    cout<<dis[i]<<" ";     //dis[5]= 15   =   min( 4+5+6 , 20 , 4+3+15 )
    
}
//                  The Graph is represented as follows

//
//                               4          5                         
//                           1--------2---------3 
//                            \       |        /
//                             \      | 3     / 
//                              \     |      /
//                            20 \    4     /
//                                \   |    / 6
//                                 \  |15 /  
//                                  \ |  /
//                                   \| /
//                                    5                                            