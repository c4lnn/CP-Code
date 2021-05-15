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
const int N=100;
int MOD,a[N][N],x[N]; // a 是增广矩阵，b 是解
int LCM(int a,int b) {
    return a/__gcd(a,b)*b;
}
LL get_inv(LL a,LL m) {
    if(a==1) return 1;
    return get_inv(m%a,m)*(m-m/a)%m;
}
int gauss(int n,int m) { // n 个方程，m 个变量
    memset(x,0,sizeof x);
    int r=0,c=0;
    while(r<n&&c<m) {
        int R=r;
        for(int i=r+1;i<n;i++) if(abs(a[i][c])>abs(a[R][c])) R=i;
        if(R!=r) for(int j=c;j<=m;j++) swap(a[r][j],a[R][j]);
        if(!a[r][c]) {++c;continue;}
        for(int i=r+1;i<n;i++) {
            if(a[i][c]) {
                int lcm=LCM(a[i][c],a[r][c]);
                int ta=lcm/a[i][c],tb=lcm/a[r][c];
                for(int j=c;j<=m;j++) a[i][j]=(a[i][j]*ta%MOD-a[r][j]*tb%MOD+MOD)%MOD;
            }
        }
        ++r,++c;
    }
    for(int i=m-1;i>=0;i--) { // 必有唯一解
        int s=a[i][m];
        for(int j=i+1;j<m;j++) s=(s-a[i][j]*x[j]%MOD+MOD)%MOD;
        x[i]=s*get_inv(a[i][i],MOD)%MOD;
    }
    return 0;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    string s;
    while(T--) {
        cin>>MOD>>s;
        int n=SZ(s);
        for(int i=0;i<n;i++) a[i][n]=(s[i]=='*'?0:s[i]-'a'+1);
        for(int i=0;i<n;i++) {
            a[i][0]=1;
            for(int j=1;j<n;j++) a[i][j]=a[i][j-1]*(i+1)%MOD;
        }
        gauss(n,n);
        for(int i=0;i<n;i++) cout<<x[i]<<" \n"[i==n-1];
    }
    return 0;
}