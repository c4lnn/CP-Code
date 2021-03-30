#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl
#define mem(str,val) memset(str,val,sizeof str)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int N=1e3+5;

int n,m;
int h[N][N],l[N],r[N];


void cal(int a[],int left[])
{
    stack<int>s;
    s.push(0);
    a[0]=-1;
    for(int i=1;i<=m;i++)
    {
        while(a[s.top()]>=a[i]) s.pop();
        left[i]=s.top();
        s.push(i);
    }
}
int work(int a[])
{
    int res=0;
    cal(a,l);
    reverse(a+1,a+1+m);
    cal(a,r);
    reverse(a+1,a+1+m);
    for(int i=1;i<=m;i++)
    {
        int d=m-r[m-i+1]+1-l[i]-1;
        res=max(res,d*a[i]);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int T;cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='F') h[i][j]=h[i-1][j]+1;
                else h[i][j]=0;
            }
        int res=0;
        for(int i=1;i<=n;i++) res=max(res,work(h[i]));
        cout<<3*res<<endl;
    }
    return 0;
}