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
const int N=10;
class Queue
{  
    public:
        int front=-1;
        int rear=-1;
        int arr[N];
        bool isFull(){
            return ((rear+1)%N==front);
        }
        bool isEmpty(){
            return (front==-1) && (rear==-1);
        }
        int peek(){
            if(isEmpty())
                cout<<"empty";
            else
                return arr[front];

        }
        void enqueue(int val){

            if(isFull())
                cout<<"Full";
            else{
                if(isEmpty())
                    front=rear=0;
                else
                    rear=(rear+1)%N;
                arr[rear]=val;
            }
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Empty";
            }
            else if(front==rear) //queue has only one element
            front=rear=-1;
            else{
                front=(front+1)%N;

            }
        }


    
};      
int32_t main()
 {
    Queue q;
    q.enqueue(13);
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(12);
    q.enqueue(4);
    cout<<q.peek();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    return 0;
}