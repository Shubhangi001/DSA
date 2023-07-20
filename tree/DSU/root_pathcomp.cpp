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
/*tells if an element belongs to a particular subset, using the concept of trees,
 the root of the tree being the representative of the subset and the leaves as the elements*/

//here in parent array, each element will contain root of the subset it belongs to
 
/*sets the root as self initially*/
void initialise(vi &v,int n){
    for(int i=1;i<n+1;i++){
        v[i]=i;
    }
}
/*put two subsets (having one or more elements) together by setting the root of all the elements of one subset as the root of the other*/
int root(vi &parent,int v) {
    if (v == parent[v])
        return v;
    return parent[v] = root(parent,parent[v]);
}

void union_(vi &parent,int x,int y){
    int a=root(parent,parent[x]);
    int b=root(parent,parent[y]);
    parent[b]=a;
}
bool find(vi &v,int x,int y){   //if root is same, then belongs to same subset
    if(v[x]==v[y]){
        return 1;
    }
    return 0;
}
/*as we can see it's changing the value or root of all elements of subset by iterating through the whole vector, thus union function itself 
taking O(n) time and thus for total time complexity of program becomes O(n^2) in worst case if perform union for all elements */
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;  //number of edges 
    vi parent(n);
    initialise(parent,n);
    union_(parent,1,2);
    union_(parent,3,4);
    union_(parent,4,5);
    cout<<find(parent,1,5);

}