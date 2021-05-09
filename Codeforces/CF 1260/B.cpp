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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--)
    {
    	int a,b;
    	cin>>a>>b;
    	if((a+b)%3==0&&max(a,b)<=min(a,b)*2) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    }
    return 0;
}