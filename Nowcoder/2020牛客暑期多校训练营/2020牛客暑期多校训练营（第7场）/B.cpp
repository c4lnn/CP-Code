#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,cnt,sum;
pair<int,int> a[N];
void solve(int n,int m) {
    if(n==0) return;
    a[++cnt]=make_pair(m/n*n,n);
    sum+=m/n*n;
    solve(m%n,n);
}
bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.first>b.first||a.first==b.first&&a.second>b.second;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        if(n>m) swap(n,m);
        sum=cnt=0;
        solve(n,m);
        sort(a+1,a+1+cnt,cmp);
        printf("%d\n",sum);
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=a[i].first;j++)
                printf("%d ",a[i].second);
        puts("");
    }
    return 0;
}