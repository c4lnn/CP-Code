#include<bits/stdc++.h>
using namespace std;
#define int long long 
priority_queue<int>q;
signed main()
{
    int T;
    scanf("%lld",&T);
    int n,k;
    int a;
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        int cnt=1;
        for(int i=0;i<n;i++) 
        {
            scanf("%lld",&a);    
            cnt+=a/k;
            a%=k;
            if(a) q.push(a);
        }
        
        int ans=cnt*k;
        if(cnt>=n)
        {
            while(!q.empty()) ans+=q.top(),q.pop();
        }
        else 
        {
            while(cnt<n&&!q.empty()) cnt++,ans+=k,q.pop();
            while(!q.empty()) ans+=q.top(),q.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}