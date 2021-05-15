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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
int t,n;
int ls1[N<<2],rs1[N<<2],w1[N<<2],lw1[N<<2],rw1[N<<2],add1[N<<2];
int ls2[N<<2],rs2[N<<2],w2[N<<2],lw2[N<<2],rw2[N<<2],add2[N<<2];
char s[10];
void build1(int p,int l,int r) {
    ls1[p]=l,rs1[p]=r;
    if(l==r) {
        w1[p]=lw1[p]=rw1[p]=1;
        add1[p]=-1;
        return;
    }
    int mid=l+r>>1;
    build1(p<<1,l,mid);
    build1(p<<1|1,mid+1,r);
    w1[p]=lw1[p]=rw1[p]=rs1[p]-ls1[p]+1;
    add1[p]=-1;
}
void push_down1(int p) {
    if(add1[p]!=-1) {
        w1[p<<1]=lw1[p<<1]=rw1[p<<1]=(rs1[p<<1]-ls1[p<<1]+1)*add1[p];
        w1[p<<1|1]=lw1[p<<1|1]=rw1[p<<1|1]=(rs1[p<<1|1]-ls1[p<<1|1]+1)*add1[p];
        add1[p<<1]=add1[p<<1|1]=add1[p];
        add1[p]=-1;
    }
}
void update1(int p,int l,int r,int v) {
    if(ls1[p]>=l&&rs1[p]<=r) {
        w1[p]=lw1[p]=rw1[p]=(rs1[p]-ls1[p]+1)*v;
        add1[p]=v;
        return;
    }
    push_down1(p);
    int mid=(ls1[p]+rs1[p])>>1;
    if(l<=mid) update1(p<<1,l,r,v);
    if(r>mid) update1(p<<1|1,l,r,v);
    w1[p]=max({w1[p<<1],w1[p<<1|1],rw1[p<<1]+lw1[p<<1|1]});
    lw1[p]=(lw1[p<<1]==rs1[p<<1]-ls1[p<<1]+1?lw1[p<<1]+lw1[p<<1|1]:lw1[p<<1]);
    rw1[p]=(rw1[p<<1|1]==rs1[p<<1|1]-ls1[p<<1|1]+1?rw1[p<<1|1]+rw1[p<<1]:rw1[p<<1|1]);
}
int query1(int p,int l,int r,int k) {
    if(l==r) return w1[l]==1&&k==1?l:-1;
    push_down1(p);
    int mid=ls1[p]+rs1[p]>>1;
    if(r<=mid) return query1(p<<1,l,r,k);
    if(l>mid) return query1(p<<1|1,l,r,k);
    if(w1[p<<1]>=k) return query1(p<<1,l,mid,k);
    if(lw1[p<<1|1]+rw1[p<<1]>=k) return mid-rw1[p<<1]+1;
    else return query1(p<<1|1,mid+1,r,k);
}
void build2(int p,int l,int r) {
    ls2[p]=l,rs2[p]=r;
    if(l==r) {
        w2[p]=lw2[p]=rw2[p]=1;
        add2[p]=-1;
        return;
    }
    int mid=l+r>>1;
    build2(p<<1,l,mid);
    build2(p<<1|1,mid+1,r);
    w2[p]=lw2[p]=rw2[p]=rs2[p]-ls2[p]+1;
    add2[p]=-1;
}
void push_down2(int p) {
    if(add2[p]!=-1) {
        w2[p<<1]=lw2[p<<1]=rw2[p<<1]=(rs2[p<<1]-ls2[p<<1]+1)*add2[p];
        w2[p<<1|1]=lw2[p<<1|1]=rw2[p<<1|1]=(rs2[p<<1|1]-ls2[p<<1|1]+1)*add2[p];
        add2[p<<1]=add2[p<<1|1]=add2[p];
        add2[p]=-1;
    }
}
void update2(int p,int l,int r,int v) {
    if(ls2[p]>=l&&rs2[p]<=r) {
        w2[p]=lw2[p]=rw2[p]=(rs2[p]-ls2[p]+1)*v;
        add2[p]=v;
        return;
    }
    push_down2(p);
    int mid=(ls2[p]+rs2[p])>>1;
    if(l<=mid) update2(p<<1,l,r,v);
    if(r>mid) update2(p<<1|1,l,r,v);
    w2[p]=max({w2[p<<1],w2[p<<1|1],rw2[p<<1]+lw2[p<<1|1]});
    lw2[p]=(lw2[p<<1]==rs2[p<<1]-ls2[p<<1]+1?lw2[p<<1]+lw2[p<<1|1]:lw2[p<<1]);
    rw2[p]=(rw2[p<<1|1]==rs2[p<<1|1]-ls2[p<<1|1]+1?rw2[p<<1|1]+rw2[p<<1]:rw2[p<<1|1]);
}
int query2(int p,int l,int r,int k) {
    if(l==r) return w2[l]==1&&k==1?l:-1;
    push_down2(p);
    int mid=ls2[p]+rs2[p]>>1;
    if(r<=mid) return query2(p<<1,l,r,k);
    if(l>mid) return query2(p<<1|1,l,r,k);
    if(w2[p<<1]>=k) return query2(p<<1,l,mid,k);
    if(lw2[p<<1|1]+rw2[p<<1]>=k) return mid-rw2[p<<1]+1;
    else return query2(p<<1|1,mid+1,r,k);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        printf("Case %d:\n",cs);
        scanf("%d%d",&t,&n);
        build1(1,1,t);
        build2(1,1,t);
        for(int i=1;i<=n;i++) {
            scanf("%s",s);
            if(s[0]=='N') {
                int x;
                scanf("%d",&x);
                int res=query1(1,1,t,x);
                if(res!=-1) {
                    printf("%d,don't put my gezi\n",res);
                    update1(1,res,res+x-1,0);
                    update2(1,res,res+x-1,0);
                }
                else {
                    res=query2(1,1,t,x);
                    if(res!=-1) {
                        printf("%d,don't put my gezi\n",res);
                        update1(1,res,res+x-1,0);
                        update2(1,res,res+x-1,0);
                    }
                    else puts("wait for me");
                }
            }
            else if(s[0]=='D') {
                int x;
                scanf("%d",&x);
                int res=query1(1,1,t,x);
                if(res!=-1) {
                    printf("%d,let's fly\n",res);
                    update1(1,res,res+x-1,0);
                }
                else puts("fly with yourself");
            }
            else {
                int l,r;
                scanf("%d%d",&l,&r);
                update1(1,l,r,1);
                update2(1,l,r,1);
                puts("I am the hope of chinese chengxuyuan!!");
            }
        }
    }
    return 0;
}