#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,st[N],cnt;
int prime[N],m;
bool vis[N];
void primes(int n) {
    for(int i=2;i<=n;i++) {
        if(vis[i]==false) prime[++m]=i;
        for(int j=1;j<=m;j++) {
            if(prime[j]*i>n) break;
            vis[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}
int main() {
    primes(200000);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) st[i]=0;
        cnt=0;
        int x=0;
        while(prime[x+1]*2<=n) ++x;
        for(int i=x;i>=1;i--) {
            int p=prime[i];
            int a=0;
            for(int j=1;j*p<=n;j++) {
                if(st[p*j]) continue;
                if(!a) a=j*p;
                else {
                    st[a]=j*p;
                    st[j*p]=a;
                    a=0;
                    cnt++;
                }
            }
            if(a) {
                int t=st[p*2];
                st[p*2]=0;
                st[t]=a;
                st[a]=t;
            }
        }
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++)
            if(i<st[i])
                printf("%d %d\n",i,st[i]);
    }
    return 0;
}