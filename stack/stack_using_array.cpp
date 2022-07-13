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
/**
 * @brief LIFO - push, pop, top, isempty, isfull, operations
 * 
 * @return int32_t 
 */
class Stack{

    public:
        ll top=-1;
        ll a[mx];
        ll peek(){
            return a[top];
        }
        void push(int val){
            if(isfull())
                cout<<"Full";
            else{
                top++;
                a[top]=val;

            }
        }
        void pop(){
            if(isempty())
                cout<<"Empty";
            else
                top--;
        }
        bool isempty(){
            return top==-1;

        }
        bool isfull(){
            return top==mx;

        }
};
int32_t main()
 {
    Stack s;
    s.push(10);
    s.push(1);
    s.push(15);
    cout<<s.isempty();
    cout<<s.isfull();
    s.pop();
    cout<<s.peek();
    s.pop();
    s.pop();
    s.pop();

     
    return 0;
}