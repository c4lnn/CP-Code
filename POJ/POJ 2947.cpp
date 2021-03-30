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
const int MOD=7;
const int N=305;
int a[N][N],x[N]; // a 是增广矩阵，b 是解
int get(const string &s) {
    if(s=="MON") return 1;
    if(s=="TUE") return 2;
    if(s=="WED") return 3;
    if(s=="THU") return 4;
    if(s=="FRI") return 5;
    if(s=="SAT") return 6;
    return 7;
}
int LCM(int a,int b) {
    return a/__gcd(a,b)*b;
}
LL get_inv(LL a,LL m) {
    if(a==1) return 1;
    return get_inv(m%a,m)*(m-m/a)%m;
}
int gauss(int n,int m) {
// n 个方程，m 个变量
// 返回自由变量个数，-1 无解，0 存在唯一解
    memset(x,0,sizeof x);
    memset(free_x,true,sizeof free_x);
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
    for(int i=r;i<n;i++) if(a[i][m]) return -1; // 无解
    if(r<m) return m-r; // 自由变量个数
    for(int i=m-1;i>=0;i--) {
        int s=a[i][m];
        for(int j=i+1;j<m;j++) s=(s-a[i][j]*x[j]%MOD+MOD)%MOD;
        x[i]=s*get_inv(a[i][i],MOD)%MOD;
        if(x[i]<=2) x[i]+=7;
    }
    return 0;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m) {
        if(!n&&!m) break;
        memset(a,0,sizeof a);
        for(int i=0;i<m;i++) {
            int t;
            string s1,s2;
            cin>>t>>s1>>s2;
            int t1=get(s1),t2=get(s2);
            a[i][n]=((t2-t1+1)%MOD+MOD)%MOD;
            for(int j=1;j<=t;j++) {
                int x;
                cin>>x;
                a[i][x-1]=(a[i][x-1]+1)%MOD;
            }
        }
        int res=gauss(m,n);
        if(res==-1) cout<<"Inconsistent data."<<'\n';
        else if(res!=0) cout<<"Multiple solutions."<<'\n';
        else for(int i=0;i<n;i++) cout<<x[i]<<" \n"[i==n-1];
    }
    return 0;
}