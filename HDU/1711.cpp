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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e6+5;
int s[N],t[N],n,m,nxt[N];
void get_next() {
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<m) {
        if(j==-1||t[i]==t[j]) {
            ++i,++j;
            if(t[i]==t[j]) nxt[i]=nxt[j];
            else nxt[i]=j;
        }
        else j=nxt[j];
    }
}
int kmp() {
    get_next();
    int i=0,j=0;
    while(i<n) {
        if(j==-1||s[i]==t[j]) {
            ++i,++j;
            if(j==m) return i-j+1;
        }
        else j=nxt[j];
    }
    return -1;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&s[i]);
        for(int i=0;i<m;i++) scanf("%d",&t[i]);
        printf("%d\n",kmp());
    }
    return 0;
}