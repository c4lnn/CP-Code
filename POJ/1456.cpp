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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ull,ull> pull;
//head
const int N=1e4+5;
pii a[N];
bool cmp(pii a,pii b){return a.second<b.second;}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);
        sort(a,a+n,cmp);
        priority_queue<int,vector<int>,greater<int> >q;
        for(int i=0;i<n;i++)
        {
            if(q.size()<a[i].second) q.push(a[i].first);
            else if(q.size()==a[i].second&&a[i].first>q.top()) q.pop(),q.push(a[i].first);
        }
        int res=0;
        while(!q.empty()) res+=q.top(),q.pop();
        printf("%d\n",res);
    }
    return 0;
}