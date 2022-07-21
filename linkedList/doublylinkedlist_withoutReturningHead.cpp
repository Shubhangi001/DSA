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
class node{
    public:
    int data;
    node* next;
    node* prev;
};
//playing with pointers
void append(node **addr,int data){
    node* newnode=new node();
    newnode->data=data;
    newnode->prev=(*addr);
    (*addr)->next=newnode;
    (*addr)=newnode;

}
void display(node *temp){
    if(temp==NULL){
        cout<<"Empty";
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
int32_t main()
{
    node *head=new node();
    node* headcopy=head;
    head->data=5;
    head->next=NULL;
    head->prev=NULL;
    append(&head,5);
    append(&head,6);
    append(&head,7);
    append(&head,8);
    append(&head,9);
    append(&head,10);
    display(headcopy);





}