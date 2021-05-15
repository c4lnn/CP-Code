#include<bits/stdc++.h>

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

ll solve(ll n)
{
    ll cnt=0;
    while(1)
    {
        if(n%2==0) cnt+=1,n/=2;
        else if(n%3==0) cnt+=2,n/=3;
        else if(n%5==0) cnt+=3,n/=5;
        else break;
    }
    if(n==1) return cnt;
    else return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int T;cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}