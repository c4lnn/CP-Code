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
#include<bitset>

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

const int N=9;

int ones[1<<9],m[1<<9];
int row[N],col[N],cell[3][3];
char s[100];

int lowbit(int x)
{
    return x&-x;
}
void init()
{
    for(int i=0;i<N;i++) row[i]=col[i]=(1<<N)-1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cell[i][j]=(1<<N)-1;
}
int get(int i,int j)
{
    return row[i]&col[j]&cell[i/3][j/3];
}
bool dfs(int cnt)
{
    if(!cnt) return true;
    int minn=10;
    int x,y;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(s[i*9+j]=='.')
            {
                int t=ones[get(i,j)];
                if(t<minn) minn=t,x=i,y=j;
            }
    for(int i=get(x,y);i;i-=lowbit(i))
    {
        int t=m[lowbit(i)];
        row[x]-=1<<t;
        col[y]-=1<<t;
        cell[x/3][y/3]-=1<<t;
        s[x*9+y]=t+'1';
        if(dfs(cnt-1)) return true;
        row[x]+=1<<t;
        col[y]+=1<<t;
        cell[x/3][y/3]+=1<<t;
        s[x*9+y]='.';
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    for(int i=0;i<N;i++) m[1<<i]=i;
    for(int i=0;i<=1<<9;i++)
    {
        int s=0;
        for(int j=i;j;j-=lowbit(j)) s++;
        ones[i]=s;
    }
    while(cin>>s&&s[0]!='e')
    {
        init();
        int cnt=0;
        for(int i=0,k=0;i<N;i++)
            for(int j=0;j<N;j++,k++)
            {
                if(s[k]!='.')
                {
                    int t=s[k]-'1';
                    row[i]-=1<<t;
                    col[j]-=1<<t;
                    cell[i/3][j/3]-=1<<t;
                }
                else cnt++;
            }
        dfs(cnt);
        cout<<s<<endl;
    }
    return 0;
}