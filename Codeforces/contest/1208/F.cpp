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
const int N=1e6+5;
int a[N];
PII mx[N<<2];
void update(int x,int y) {
    if(mx[x].SE&&mx[y].SE) {
        if(mx[y].FI>mx[x].SE) mx[x]=mx[y];
        else if(mx[y].SE>mx[x].SE&&mx[x].SE>mx[y].FI) mx[x]=MP(mx[x].SE,mx[y].SE);
        else if(mx[x].SE>mx[y].SE&&mx[y].SE>mx[x].FI) mx[x]=MP(mx[y].SE,mx[x].SE);
    }
    else if(mx[x].SE&&mx[y].FI) {
        if(mx[y].FI>mx[x].SE) mx[x]=MP(mx[x].SE,mx[y].FI);
        else if(mx[y].FI>mx[x].FI) mx[x]=MP(mx[y].FI,mx[x].SE);
    }
    else if(mx[x].FI&&mx[y].SE) {
        if(mx[x].FI>mx[y].SE) mx[x]=MP(mx[y].SE,mx[x].FI);
        else if(mx[x].FI>mx[y].FI) mx[x]=MP(mx[x].FI,mx[y].SE);
        else mx[x]=mx[y];
    }
    else if(mx[x].FI&&mx[y].FI) mx[x]=MP(min(mx[x].FI,mx[y].FI),max(mx[x].FI,mx[y].FI));
    else if(mx[y].FI) mx[x]=mx[y];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(!mx[a[i]].FI) mx[a[i]].FI=i;
        else if(!mx[a[i]].SE) mx[a[i]].SE=i;
        else mx[a[i]]=MP(mx[a[i]].SE,i);
    }
    for(int i=0;i<21;i++) {
        for(int j=(1<<21)-1;~j;j--) if(j&(1<<i)) {
            update(j^(1<<i),j);
        }
    }
    int res=0;
    for(int i=1;i<=n-2;i++) {
        int bit=0,t=0;
        for(int j=20;~j;j--) {
            if(a[i]&(1<<j)) bit|=(1<<j);
            else if(mx[t|(1<<j)].FI>i&&mx[t|(1<<j)].SE>i) bit|=(1<<j),t|=(1<<j);
        }
        res=max(res,bit);
    }
    cout<<res<<'\n';
    return 0;
}