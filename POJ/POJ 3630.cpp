#include<cstdio>
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
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int N=1e5+5;

int trie[N*10][10];
int num[N];
int cnt;
int f;

void insert(string &s)
{
    int pre=0;
    for(int i=0;i<s.size();i++)
    {
        int now=s[i]-'0';
        if(num[trie[pre][now]]||i==s.size()-1&&trie[pre][now]){f=1;break;}
        if(!trie[pre][now]) trie[pre][now]=++cnt;
        pre=trie[pre][now];
    }
    num[pre]++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int T;cin>>T;
    while(T--)
    {
        f=0;
        mem(trie,0);
        mem(num,0);
        cnt=0;
        int n;
        cin>>n;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            insert(s);
        }
        if(f) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}