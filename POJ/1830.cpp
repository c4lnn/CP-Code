#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
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
int n,m,a[N][N],x[N];
int gauss() {
    memset(x,0,sizeof x);
    int r=0,c=0;
    while(r<n&&c<m) {
        int R=r;
        for(int i=r+1;i<n;i++) if(a[i][c]>a[R][c]) R=i;
        if(R!=r) for(int j=c;j<=m;j++) swap(a[r][j],a[R][j]);
        if(!a[r][c]) {++c;continue;}
        for(int i=r+1;i<n;i++) {
            if(a[i][c]) {
                int t=a[i][c]^a[r][c];
                for(int j=c;j<=m;j++) a[i][j]^=a[r][j]^t;
            }
        }
        ++r,++c;
    }
    for(int i=r;i<n;i++) if(a[i][m]) return -1;
    return m-r;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        memset(a,0,sizeof a);
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i][n];
        for(int i=0;i<n;i++) {
            int t;
            cin>>t;
            a[i][n]^=t;
            a[i][i]=1;
        }
        int i,j;
        while(cin>>i>>j) {
            if(!i&&!j) break;
            a[j-1][i-1]=1;
        }
        m=n;
        int res=gauss();
        if(res!=-1) cout<<(1<<gauss())<<'\n';
        else cout<<"Oh,it's impossible~!!"<<'\n';
    }
    return 0;
}