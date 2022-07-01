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
/*Union by size or rank along with path compression-> nearly constant time*/
/*Union by size or rank along without path compression-> O(logn)*/

/*here we'll keep track of size of subset and while union, root will be the root of the bigger subset , this is to decrease traversal
ex:
   4             8               4
  / \           /     ->       / \ \           
 5  6          9              5   6 8                  
    \                              \ \          
    7                               7 9
    
  not this:                                                  
                                 8
                                 /\
   4             8              4  9 
  / \           /     ->       / \           
 5  6          9              5   6                  
    \                              \           
    7                               7

*/
/*we can also do by rank, i.e., depth of the tree, this will have same complexity as that of size*/

void initialise(vi &v,int n,vi &s){
    for(int i=1;i<n+1;i++){
        v[i]=i;
        s[i]=1;
    }
}
int root(vi &parent,int x){
    if(parent[x]==x)
        return x;
    return parent[x]=root(parent,parent[x]);
}
void union_(vi &v,vi &size,int x,int y){
    int rx=root(v,x);
    int ry=root(v,y);
    if(size[rx]>size[ry]){
        v[ry]=rx;
        size[rx]+=size[ry];
    }
    else{

        v[rx]=ry;
        size[ry]+=size[rx];

    }
}
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
    vi v(n+1),s(n+1);
    initialise(v,n,s);
    union_(v,s,1,2);
    union_(v,s,3,4);
    union_(v,s,4,5);
    union_(v,s,1,3);
    cout<<find(v,1,5);

}