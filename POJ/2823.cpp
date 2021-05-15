#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
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

const int N=1e6+5;

int n,k;
int a[N];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    deque<int>q;
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&i-q.front()+1>k) q.pop_front();
        while(!q.empty()&&a[q.back()]>=a[i]) q.pop_back();
        q.push_back(i);
        if(i>=k) cout<<a[q.front()]<<" ";
    }
    cout<<endl;
    q.clear();
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&i-q.front()+1>k) q.pop_front();
        while(!q.empty()&&a[q.back()]<=a[i]) q.pop_back();
        q.push_back(i);
        if(i>=k) cout<<a[q.front()]<<" ";
    }
    return 0;
}