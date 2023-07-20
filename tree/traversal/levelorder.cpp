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



/**
 * @brief time complexity - O(n)
 *         space - O(1)- best, O(n)- worst/avg
 *              
 **/
class node{
    public:
    int data;
    node* left;
    node* right;
};

void levelorder(node * root){
    if(root==NULL) return;
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        node* current=Q.front();
        cout<<current->data<<" ";
        if(current->left){
            Q.push(current->left);
        }
        if(current->right){
            Q.push(current->right);
        }
        Q.pop();
    }


}
int main(){

}

