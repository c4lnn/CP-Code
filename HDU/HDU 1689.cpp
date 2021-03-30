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
char s[N],t[N];
int nxt[N];
void get_next() {
    int len=strlen(t);
    nxt[0]=-1;
    int i=0,j=-1;
    while(i<len) {
        if(j==-1||t[i]==t[j]) {
            ++i,++j;
            if(t[i]!=t[j]) nxt[i]=j;
            else nxt[i]=nxt[j];
        }
        else j=nxt[j];
    }
}
int kmp() {
    get_next();
    int len_s=strlen(s),len_t=strlen(t);
    int i=0,j=0,res=0;
    while(i<len_s) {
        if(j==-1||s[i]==t[j]) {
            ++i,++j;
            if(j==len_t) {
                res++;
                j=nxt[j];
            }
        }
        else j=nxt[j];
    }
    return res;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%s%s",t,s);
        printf("%d\n",kmp());
    }
    return 0;
}