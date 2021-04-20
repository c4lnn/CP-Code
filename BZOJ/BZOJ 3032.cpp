#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int n,m,t;
int x,y;
ll row[maxn],col[maxn];
ll s_row[maxn],s_col[maxn];
ll med;
ll res_row,res_col;
int main() {
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=t;i++) {
        scanf("%d%d",&x,&y);
        row[x]++,col[y]++;
    }
    if(t%n==0) {
        for(int i=1;i<=n;i++) s_row[i]=row[i]+s_row[i-1]-t/n;
        sort(s_row+1,s_row+1+n);
        med=s_row[(1+n)>>1];
        for(int i=1;i<=n;i++) res_row+=abs(s_row[i]-med);
    }
    if(t%m==0) {
        for(int i=1;i<=m;i++) s_col[i]=col[i]+s_col[i-1]-t/m;
        sort(s_col+1,s_col+1+m);
        med=s_col[(1+m)>>1];
        for(int i=1;i<=m;i++) res_col+=abs(s_col[i]-med);
    }
    if(res_row&&res_col) printf("both %lld\n",res_row+res_col);
    else if(res_row) printf("row %lld\n",res_row);
    else if(res_col) printf("column %lld\n",res_col);
    else puts("impossible");
    return 0;
}