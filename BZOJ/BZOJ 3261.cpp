#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int N=600005;
int tr[N*24][2],mx[N*24];
int s[N],rt[N],n,m,cnt;
void insert(int id,int pos,int p,int q) {
    if(pos<0) {mx[q]=id;return;}
    int c=s[id]>>pos&1;
    if(p) tr[q][c^1]=tr[p][c^1];
    tr[q][c]=++cnt;
    insert(id,pos-1,tr[p][c],tr[q][c]);
    mx[q]=max(mx[tr[q][0]],mx[tr[q][1]]);
}
int query(int now,int w,int pos,int t) {
    if(pos<0) return s[mx[now]]^w;
    int c=w>>pos&1;
    if(mx[tr[now][c^1]]>=t) return query(tr[now][c^1],w,pos-1,t);
    else return query(tr[now][c],w,pos-1,t);
}
int main() {
    scanf("%d%d",&n,&m);
    mx[0]=-1;
    rt[0]=++cnt;
    insert(0,23,0,1);
    for(int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]^x;
        rt[i]=++cnt;
        insert(i,23,rt[i-1],rt[i]);
    }
    for(int i=1;i<=m;i++) {
        char c;
        scanf(" %c",&c);
        if(c=='A') {
            int x;
            scanf("%d",&x);
            rt[++n]=++cnt;
            s[n]=s[n-1]^x;
            insert(n,23,rt[n-1],rt[n]);
        }
        else {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",query(rt[r-1],s[n]^x,23,l-1));
        }
    }
    return 0;
}