#include<iostream>
#include<queue>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl
#define mem(str,val) memset(str,val,sizeof str)

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int N=3e4+5;

int a[N];
int u[N];
priority_queue<int,vi,greater<int> >q1;
priority_queue<int>q2;
int cnt=1;
int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>u[i];
    for(int i=1;i<=m;i++)
    {
        if(q1.empty()||a[i]>q1.top()) q1.push(a[i]);
        else q2.push(a[i]);
        while(cnt<=m&&i==u[cnt])
        {
            t++,cnt++;
            while(q2.size()<t-1) q2.push(q1.top()),q1.pop();
            while(q2.size()>t-1) q1.push(q2.top()),q2.pop();
            cout<<q1.top()<<endl;
        }
    }
    return 0;
}