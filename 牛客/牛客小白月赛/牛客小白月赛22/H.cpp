#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n,m;
int b[N];
struct node {
    int l,r,d;
    bool operator < (const node &a) const {
        return d==a.d?l<a.l:d<a.d;
    }
}a[N];
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i].l>>a[i].r>>a[i].d;
    sort(a+1,a+1+m);
    int st=a[1].l,ed=a[1].r;
    for(int i=2;i<=m;i++) {
        if(a[i].d==a[i-1].d&&a[i].l<=ed) ed=max(ed,a[i].r);
        else b[st]++,b[ed+1]--,st=a[i].l,ed=a[i].r;
    }
    b[st]++,b[ed+1]--;
    pair<int,int>res(0,0);
    int sum=0;
    for(int i=1;i<=n;i++) {
        sum+=b[i];
        if(res.first<sum) res.first=sum,res.second=i;
    }
    cout<<res.second<<endl;
    return 0;
}