#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
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
int a[150][150];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x=i*2,y=x+1,d=4*(n-i+1)+1;
        a[x][y]=1,a[x+1][y]=1,a[x+1][y-1]=1;
        y-=2;
        for(int j=1;j<=d;j++) a[++x][y]=1;
        a[x][y+1]=1,a[x][y+2]=1,a[x+1][y+2]=1;
        x+=2,++y;
        for(int j=1;j<=d;j++) a[x][++y]=1;
        a[x-1][y]=1,a[x-2][y]=1,a[x-2][y+1]=1;
        --x,y+=2;
        for(int j=1;j<=d;j++) a[--x][y]=1;
        a[x][y-1]=1,a[x][y-2]=1,a[x-1][y-2]=1;
        x-=2,--y;
        for(int j=1;j<=d;j++) a[x][--y]=1;
    }
    int x=3+2*n,y=3+2*n;
    a[x][y]=1;
    a[x-1][y]=1,a[x-2][y]=1;
    a[x+1][y]=1,a[x+2][y]=1;
    a[x][y-1]=1,a[x][y-2]=1;
    a[x][y+1]=1,a[x][y+2]=1;
    for(int i=1;i<=4*n+5;i++) {
        for(int j=1;j<=4*n+5;j++) {
            cout<<(a[i][j]?'$':'.');
        }
        cout<<'\n';
    }
    return 0;
}