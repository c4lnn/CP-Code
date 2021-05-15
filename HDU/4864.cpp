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
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int N=1e5+5;

pii machines[N];
pii tasks[N];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++) scanf("%d%d",&machines[i].first,&machines[i].second);
        for(int i=0;i<m;i++) scanf("%d%d",&tasks[i].first,&tasks[i].second);
        sort(machines,machines+n);
        sort(tasks,tasks+m);
        int cnt=0;
        ll res=0;
        multiset<int>s;
        for(int i=m-1,j=n-1;i>=0;i--)
        {
            while(j>=0&&machines[j].first>=tasks[i].first) s.insert(machines[j--].second);
            multiset<int>::iterator it=s.lower_bound(tasks[i].second);
            if(it!=s.end()) 
            {
                cnt++,res+=500*tasks[i].first+2*tasks[i].second;    
                s.erase(it);
            }
        }
        printf("%d %lld\n",cnt,res);
    }

    return 0;
}