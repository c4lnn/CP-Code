#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt1,cnt2,p[N],sz[N];
bool vis[N];
struct bign {
    int len;
    int num[1005];
    bign() {
        len=1;
        memset(num,0,sizeof num);
    }
    bool operator == (const bign &a) const {
        for(int i=1;i<=len;i++) if(num[i]!=a.num[i]) return false;
        return true;
    }
    bool operator > (const bign &a) const {
        if(len>a.len) return true;
        else if(len<a.len) return false;
        else {
            for(int i=len;i>=1;i--) {
                if(num[i]>a.num[i]) return true;
                else if(num[i]<a.num[i]) return false;
            }
        }
        return false;
    }
    bool operator < (const bign &a) const {
        if(len>a.len) return false;
        else if(len<a.len) return true;
        else {
            for(int i=len;i>=1;i--) {
                if(num[i]>a.num[i]) return false;
                else if(num[i]<a.num[i]) return true;
            }
        }
        return false;
    }
    bool operator >= (const bign &a) const {
        if(len>a.len) return true;
        else if(len<a.len) return false;
        else {
            for(int i=len;i>=1;i--) {
                if(num[i]>a.num[i]) return true;
                else if(num[i]<a.num[i]) return false;
            }
        }
        return true;
    }
    bool operator <= (const bign &a) const {
        if(len>a.len) return false;
        else if(len<a.len) return true;
        else {
            for(int i=len;i>=1;i--) {
                if(num[i]>a.num[i]) return false;
                else if(num[i]<a.num[i]) return true;
            }
        }
        return true;
    }
};
bign get(int n) {
    bign res;
    while(n) {
        res.num[res.len++]=n%10;
        n/=10;
    }
    res.len--;
    return res;
}
void print(bign a) {
    for(int i=a.len;i;i--) printf("%d",a.num[i]);
    puts("");
}
bign operator - (bign a,bign b) {  //a>b
    bign res;
    res.len=max(a.len,b.len);
    for(int i=1;i<=res.len;i++) {
        if(a.num[i]<b.num[i]) {
            a.num[i+1]--;
            a.num[i]+=10;
        }
        res.num[i]=a.num[i]-b.num[i];
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator * (bign a,int b) {
    bign res;
    int x=0;
    for(int i=1;i<=a.len;i++) {
        x+=a.num[i]*b;
        res.num[res.len++]=x%10;
        x/=10;
    }
    while(x) {
        res.num[res.len++]=x%10;
        x/=10;
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator / (bign a,bign b) {
    bign res,x;
    res.len=a.len;
    for(int i=a.len;i>=1;i--) {
        x=x*10;//bign * int
        x.num[1]=a.num[i];
        while(x>=b) {
            x=x-b;//bign - bign
            res.num[i]++;
        }
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator % (bign a,bign b) {
    bign res;
    for(int i=a.len;i>=1;i--) {
        res=res*10;//bign * int
        res.num[1]=a.num[i];
        while(res>=b) res=res-b;//bign - bign
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign gcd(bign a,bign b) {
    bign c;
    return !(b==c)?gcd(b,a%b):a;
}
void find_cycle(int u) {
    if(vis[u]) return;
    vis[u]=true;
    cnt1++;
    find_cycle(p[u]);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        cnt1=0;
        find_cycle(i);
        if(cnt1>1) sz[++cnt2]=cnt1;
    }
    if(cnt2==0) {puts("1");return 0;}
    bign res=get(sz[1]);
    for(int i=2;i<=cnt2;i++) res=res*sz[i]/gcd(res,get(sz[i]));
    print(res);
    return 0;
}