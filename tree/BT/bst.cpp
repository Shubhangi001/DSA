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
struct node{
    node * left;
    node * right;
    int data;
};
node* createnode(int data){
    node * newnode=new node();
    newnode->data=data;   //same as (*newnode).data=data
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insert(node * root, int data){        
    if(root==NULL){
        root=createnode(data);
        return root;
    }
    else if(data<=root->data){                     
        root->left=insert(root->left,data);              //if data is less than root data insert in left subtree
    }
    else{
        root->right=insert(root->right,data);            //if data is greater than root data insert in right subtree
    }
    return root;
}
bool search(node* root, int val){
    if(root==NULL)
        return false;
    if(val==root->data)
        return true;
    if(val<=root->data){
        return search(root->left,val);
    }
    else
        return search(root->right,val);
}
void preorder(node* root){
    if(root == NULL)    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root == NULL)    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
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

int32_t main()
 {
    node * root=NULL;  //creating an empty bst
    while(1){
        int n;
        cin>>n;
        if(n == 0)  break;
        root = insert(root,n);
    }
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    levelorder(root);
    return 0;
}