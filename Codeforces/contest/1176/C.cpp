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
 
int res;
int vis[10];
int mp[50];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    mp[4]=0,mp[8]=1,mp[15]=2,mp[16]=3,mp[23]=4,mp[42]=5;
    int n;cin>>n;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        t=mp[t];
        if(!t) vis[t]++;
        else if(vis[t-1])
        {
            vis[t-1]--;
            vis[t]++;
        }
    }
    cout<<n-vis[5]*6;
    return 0;
}