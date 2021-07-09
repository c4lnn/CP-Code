#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],mn[N];
long long s[N];
pair<long long,int> c[N];
void print(__int128 x) {
    if(!x) return;
    if(x<0) putchar('-'),x=-x;
    print(x/10);
    putchar(x%10+'0');
}
bool cmp (pair<long long,int> a,pair<long long,int> b) {
    return a.first>b.first||a.first==b.first&&a.second<b.second;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int k=1;k<=T;k++) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i],c[i]=make_pair(s[i],i);
        b[0]=0x3f3f3f3f;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),mn[i]=(b[i]<b[mn[i-1]]?i:mn[i-1]);
        sort(c+1,c+1+n,cmp);
        __int128 res=0;
        int l=n+1,cnt=0;
        for(int i=1;i<=n;i++) {
            long long &w=c[i].first;
            int &idx=c[i].second;
            if(mn[idx]>=l||b[mn[idx]]<=cnt) continue;
            res+=(__int128)w*(b[mn[idx]]-cnt);
            l=mn[idx];
            cnt=b[mn[idx]];
        }
        printf("Case #%d: %d ",k,b[1]);
        print(res);
        puts("");
    }
    return 0;
}