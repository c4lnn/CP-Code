#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
int a[4][4],c[4][4],res;
bool st[10];
VPII b;
bool check() {
    int t=-1;
    for(int i=1;i<=3;i++) {
        int sum=a[i][1]+a[i][2]+a[i][3];
        if(sum>=100) continue;
        if(t==-1) t=sum;
        else if(t!=sum) return false;
    }
    for(int i=1;i<=3;i++) {
        int sum=a[1][i]+a[2][i]+a[3][i];
        if(sum>=100) continue;
        if(t==-1) t=sum;
        else if(t!=sum) return false;
    }
    int sum=a[1][1]+a[2][2]+a[3][3];
    if(sum<100) {
        if(t==-1) t=sum;
        else if(t!=sum) return false;
    }
    sum=a[3][1]+a[2][2]+a[1][3];
    if(sum<100) {
        if(t==-1) t=sum;
        else if(t!=sum) return false;
    }
    return true;
}
bool dfs(int x) {
    if(x==SZ(b)) {
        ++res;
        if(res>=2) return false;
        for(int i=1;i<=3;i++) {
            for(int j=1;j<=3;j++) {
                c[i][j]=a[i][j];
            }
        }
        return true;
    }
    for(int i=1;i<=9;i++) if(!st[i]) {
        st[i]=true;
        a[b[x].FI][b[x].SE]=i;
        if(!check()) {
            a[b[x].FI][b[x].SE]=100;
            st[i]=false;
            continue;
        }
        if(!dfs(x+1)) return false;
        a[b[x].FI][b[x].SE]=100;
        st[i]=false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            cin>>a[i][j];
            if(a[i][j]==0) {
                a[i][j]=100;
                b.PB(MP(i,j));
            }
        }
    }
    if(!dfs(0)) cout<<"Too Many"<<'\n';
    else {
        for(int i=1;i<=3;i++) {
            for(int j=1;j<=3;j++) {
                cout<<c[i][j]<<" \n"[j==3];
            }
        }
    }
    return 0;
}