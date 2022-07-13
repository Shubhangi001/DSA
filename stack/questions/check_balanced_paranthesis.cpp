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
#define int ll
const int mx=2e5+5;
class Solution
{
     public:
     bool check(string str){
        stack<char> s;
        map<char,char> m;
        m['(']=')';
        m['{']='}';
        m['[']=']';
        ll i=0;
        while(str[i]!='\0'){
            if(str[i]=='('||str[i]=='{'||str[i]=='['){
                s.push(str[i]);
            }
            if(str[i]==')'||str[i]=='}'||str[i]==']'){
                if(s.empty())
                    return 0;
                if(m[s.top()]==str[i])
                    s.pop();
                else
                    return 0;
            }
            i++;
        }
        if(s.empty())
            return 1;
        else
            return 0;
     }
    void solve() 
    { 
        
        string s;
        cin>>s;
        cout<<check(s);
    }
};      
int32_t main()
 {
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>>t;
    while(t--)
    {
       
        Solution ob;
        ob.solve();
        cout<<endl;
        
    }
    return 0;
}