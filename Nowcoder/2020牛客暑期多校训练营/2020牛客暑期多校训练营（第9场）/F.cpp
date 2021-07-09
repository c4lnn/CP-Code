#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=2e6+4;
int b[N],st[N],cnt;
pii a[N];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        int p;
        scanf("%d",&p);
        for(int j=1;j<=p;j++) {
            int x;
            scanf("%d",&x);
            a[++cnt]=mp(x,i);
        }
    }
    sort(a+1,a+1+cnt);
    for(int i=1;i<=cnt;i++) b[i]=a[i].fi-a[i-1].fi;
    b[1]=0;
    int t=0,tot=0,res=0x3f3f3f3f;
    for(int i=1,j=1;i<=cnt;i++) {
        if(!st[a[i].se]) tot++;
        t+=b[i];
        st[a[i].se]++;
        if(tot==m) {
            res=min(res,t);
            while(1) {
                st[a[j].se]--;
                t-=b[j+1];
                if(st[a[j].se]==0) {j++;break;}
                else res=min(res,t);
                j++;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}