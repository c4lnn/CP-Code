#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
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
//head
const int N=25;
int a[N][N],x[N]; // a 是增广矩阵，x 是解
VI free_x;
int gauss(int n,int m) { // n 个方程，m 个变量
    memset(x,0,sizeof x);
    free_x.clear();
    int r=0,c=0;
    while(r<n&&c<m) {
        int R=r;
        for(int i=r+1;i<n;i++) if(a[i][c]>a[R][c]) R=i;
        if(R!=r) for(int j=c;j<=m;j++) swap(a[r][j],a[R][j]);
        if(!a[r][c]) {free_x.PB(c),++c;continue;}
        for(int i=r+1;i<n;i++) {
            if(a[i][c]) {
                int t=a[i][c]^a[r][c];
                for(int j=c;j<=m;j++) a[i][j]^=a[r][j]^t;
            }
        }
        ++r,++c;
    }
    for(int i=r;i<n;i++) if(a[i][m]) return INT_MAX; // 无解
    int mn=INT_MAX;
    // 自由变量个数为 m - r 个
    for(int i=0;i<1<<(m-r);i++) { //枚举变元
        int cnt=0,idx=i;
        for(int j=0;j<m-r;j++) {
            x[free_x[j]]=idx&1;
            if(x[free_x[j]]) ++cnt;
            idx>>=1;
        }
        for(int j=r-1;j>=0;j--) {
            int k=j;
            while(!a[j][k]) ++k;
            x[k]=a[j][m];
            for(int l=k+1;l<m;l++) x[k]^=a[j][l]&x[l];
            if(x[k]) ++cnt;
        }
        mn=min(mn,cnt);
    }
    return mn; // 最小操作数
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<20;i++) {
        cin>>a[i][20];
        a[i][i]=1;
        if(i-1>=0) a[i-1][i]=1;
        if(i+1<20) a[i+1][i]=1;
    }
    cout<<gauss(20,20)<<'\n';
    return 0;
}