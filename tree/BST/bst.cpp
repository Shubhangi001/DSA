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
 * @brief bst- binary search tree, 3 operations search, insert, remove all takes O(logn) time
 *  where as in array if we do binary search, search takes O(logn) but insert and remove takes O(n)
 * 
 * BST is a binary tree in which for each node, value of all nodes in the left subtree is lesser or equal and value of all
 * nodes in right subtree is greater 
 * 
 * We can implement bst (a) using dynamically created nodes (which will be created in heaps)
 *                      (b) using arrays (where left child will have index 2i+1 and right child 2i+2 for any node)
 * 
 *  
 */
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
int32_t main()
 {
    node * root=NULL;  //creating an empty bst
    root=insert(root,15);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,12);
    int num;
    cout<<"No. to be searched: ";
    cin>>num;
    if(search(root,num))
        cout<<"Found";
    else
        cout<<"Not Found";                                          //        15
                                                                    //    12      20
                                                                    //               25                                                                        

    
    return 0;
}