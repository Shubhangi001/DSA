#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void ynans(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
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
#define vll vector<ll>
#define vvi vector < vi >
#define pll pair<ll, ll>
#define ff first
#define ss second
#define casePrint(x,y) cout<<"Case #"<<x<<": "<<y;
#define all(c) c.begin(),c.end()
ll digitsum(ll n)
{
    ll ret = 0;
    while (n)
    {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}
void fnc()
{
    int n;
    cin>>n;
    cout<<fact(n);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n=1;
    // cin>>n;
    while(n--)
    {
        fnc();
        cout<<"\n";
    }
}