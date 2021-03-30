#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;
const int N=105;
int n,len,sum,maxn,val[N];
bool st[N];
bool dfs(int cnt,int now,int pre) {
    if(!cnt) return true;
    if(now==len) return dfs(cnt-1,0,1);
    int fail=0;
    for(int i=pre;i<=n;i++)
        if(!st[i]&&now+val[i]<=len&&val[i]!=fail) {
            st[i]=true;
            if(dfs(cnt,now+val[i],i+1)) return true;
            fail=val[i];
            st[i]=false;
            if(now==0||now+val[i]==len) return false;
        }
    return false;
}
int main() {
    while(~scanf("%d",&n)&&n) {
        sum=maxn=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&val[i]);
            sum+=val[i];
            maxn=max(maxn,val[i]);
        }
        sort(val+1,val+1+n,greater<int>());
        for(len=maxn;len<=sum;len++)
            if(sum%len==0) {
                int cnt=sum/len;
                memset(st,false,sizeof st);
                if(dfs(cnt,0,1)) break;
            }
        printf("%d\n",len);
    }
    return 0;
}