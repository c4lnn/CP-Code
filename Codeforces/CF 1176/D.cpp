#include<bits/stdc++.h>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int N=3e6+5;

int prime[N];
int vis[N];
int s[N];
int b[N];
int d[N];
int mp[N];
vi res;
int cnt;

void primes()
{
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prime[++cnt]=i;
            mp[i]=cnt;
            vis[i]=i;
        }
        for(int j=1;j<=cnt;j++)
        {
            if(prime[j]>vis[i]||prime[j]>N/i) break;
            vis[prime[j]*i]=prime[j];
            d[prime[j]*i]=i;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    primes();
    int n;cin>>n;
    n*=2;
    for(int i=1;i<=n;i++) cin>>b[i],s[b[i]]++;
    sort(b+1,b+1+n);
    for(int i=n;i>=1;i--)
    {
        if(!s[b[i]]) continue;
        if(mp[b[i]]) res.push_back(mp[b[i]]),s[mp[b[i]]]--,s[b[i]]--;
        else res.push_back(b[i]),s[d[b[i]]]--,s[b[i]]--;
    }
    for(auto x:res) cout<<x<<" ";
    return 0;
}