#include <algorithm>
#include <bitset>
#include <cctype>
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
const int N=30;
const DB EPS=1e-9;
DB a[N][N],x[N]; // a 是增广矩阵，b 是解
bool free_x[N]; // 是否为自由变量
int sgn(DB x) {return fabs(x)<EPS?0:(x>0?1:-1);}
int gauss(int n,int m) { // n 个方程，m 个变量
    memset(x,0,sizeof x);
    memset(free_x,true,sizeof free_x);
    int r=0,c=0;
    while(r<n&&c<m) {
        int R=r;
        for(int i=r+1;i<n;i++) if(fabs(a[i][c])>fabs(a[R][c])) R=i;
        if(R!=r) for(int i=c;i<=m;i++) swap(a[r][i],a[R][i]);
        if(!sgn(a[r][c])) {a[r][c]=0;++c;continue;}
        for(int i=r+1;i<n;i++) {
            if(a[i][c]) {
                DB t=a[i][c]/a[r][c];
                for(int j=c;j<=m;j++) a[i][j]-=a[r][j]*t;
            }
        }
        ++r,++c;
    }
    for(int i=r;i<n;i++) if(sgn(a[i][m])) return -1;
    if(r<m) {
        for(int i=r-1;i>=0;i--) {
            int cnt=0,k=-1;
            for(int j=0;j<m;j++) if(sgn(a[i][j])&&free_x[j]) ++cnt,k=j;
            if(cnt>1) continue;
            DB s=a[i][m];
            for(int j=0;j<m;j++) if(sgn(a[i][j])&&j!=k) s-=a[i][j]*x[j];
            x[k]=s/a[i][k];
            free_x[k]=false;
        }
        return m-r; // 自由变量个数
    }
    for(int i=m-1;i>=0;i--) {
        DB s=a[i][m];
        for(int j=i+1;j<m;j++) s-=a[i][j]*x[j];
        x[i]=s/a[i][i];
    }
    return 0;
}
int solve(const string &s,int &i,DB *b) {
    int tot=0;
    for(;i<SZ(s);i++) {
        if(s[i]=='(') {
            DB tmp[27]={0};
            int t=solve(s,++i,tmp);
            for(int i=0;i<=26;i++) b[i]+=tmp[i]/t;
            ++tot;
        }
        else if(s[i]==')') return tot;
        else if(s[i]=='-'||isdigit(s[i])||islower(s[i])) {
            if(s[i]=='-'||isdigit(s[i])) {
                int d=0,t=1;
                if(s[i]=='-') t=-1,++i;
                while(isdigit(s[i])) d*=10,d+=s[i]-'0',++i;
                --i;
                d*=t;
                b[26]+=d;
            }
            else b[s[i]-'a']+=1.0;
            ++tot;
        }
    }
    return tot;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(int cs=1;;cs++) {
        int n;scanf("%d",&n);
        if(!n) break;
        getchar();
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++) {
            char c;
            string s="";
            while(~scanf("%c",&c))  {
                if(c=='\n') break;
                s+=c;
            }
            DB b[27]={0};
            int t=5;
            int tot=solve(s,t,b);
            a[i][s[0]-'a']-=tot;
            for(int j=0;j<n;j++) a[i][j]+=b[j];
            a[i][n]=-b[26];
        }
        printf("Game %d\n",cs);
        int t=gauss(n,n);
        for(int i=0;i<n;i++) {
            if(t==-1||t>0&&free_x[i]) printf("Expected score for %c undefined\n",'a'+i);
            else printf("Expected score for %c = %.3f\n",'a'+i,fabs(x[i])<EPS?0.0:x[i]);
        }
        puts("");
    }
    return 0;
}