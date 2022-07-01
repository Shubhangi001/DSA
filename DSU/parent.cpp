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
/*parent array will contain direct parent of each element*/
//initially parent of itself
void initialise(vi &v,int n){
    for(int i=1;i<n+1;i++){
        v[i]=i;
    }
}
//find the root by keep checking parent, so need not check all elements of the vector but in worst case, i.e.,
// in case of skewed tree this will also take O(n) time making the complexity of program as O(n^2)
int root(vi &parent,int x){
    if(parent[x]==x)
        return x;
    return root(parent,parent[x]);
}
//put two subset together by setting root of one subset as the other
void union_(vi &v,int x,int y){
    int rx=root(v,x);
    int ry=root(v,y);
    v[rx]=ry;
}
//if root equals then same subset
bool find(vi &v,int x,int y){
    if(root(v,x)==root(v,y)){
        return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi v(n);
    initialise(v,n);
    union_(v,1,2);
    union_(v,3,4);
    union_(v,4,5);
    // union_(v,1,3);
    cout<<find(v,1,5);

}