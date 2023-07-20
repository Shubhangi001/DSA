// You are given number of nodes, N, and number of edges, M, of a undirected connected graph. After adding each edge,
// print the size of all the connected components (in increasing order).
// Input:
// First line contains two integers, N and M, number of nodes and number of edges.
// Next M lines contains two integers each, X and Y, denoting that there is an edge between X and Y.
// Output:
// For each edge, print the size of all the connected components (in increasing order) after adding that edge.
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
void initialise(vi &v,int n,vi &s){
    for(int i=1;i<n+1;i++){
        v[i]=i;
        s[i]=1;
    }
}
int root(vi &v,int x){
    if(x==v[x])
        return x;
    return root(v,v[x]);

}
void union_(vi &v,vi &s,int x,int y){
    int rx=root(v,x);
    int ry=root(v,y);
    if(s[rx]>s[ry]){
        v[ry]=rx;
        s[rx]+=s[ry];
    }
    else{
        v[rx]=ry;
        s[ry]+=s[rx];
    }
}

void printsize(vi &v,vi &s,int n){

    set<int> o;
    for(int i=0;i<n;i++)
    {
        int pr = root(v,i+1);
        if(o.find(pr)==o.end()){
            o.insert(pr);
        }
        
    }
    vi ans;
    for(auto i:o) ans.pb(s[i]);
    sort(all(ans));

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
} 

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> parent(n+1);
	vector<int> s(n+1);
	initialise(parent,n,s);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
        union_(parent,s,x,y);

	}
    printsize(parent,s,n);

}