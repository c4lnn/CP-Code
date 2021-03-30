#include<cstdio>
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vll;

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    priority_queue<int,vi,greater<int> >q;
    for(int i=1;i<=n;i++)
    {
        int val;
        scanf("%d",&val);
        q.push(val);
    }
    ll res=0;
    for(int i=1;i<n;i++)
    {

        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        res+=a+b;
        q.push(a+b);
    }
    printf("%lld\n",res);
    return 0;
}
