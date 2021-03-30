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
const int N=3e5+5;
int len[N<<1],pos,res;
char s[N],t[N<<1];
void manacher(const string &s) {
    t[0]='$';
    int l=SZ(s),k=0;
    for(int i=0;i<l;i++) t[++k]='#',t[++k]=s[i];
    t[++k]='#';
    len[0]=0;
    int id=0,mx=0;
    res=0;
    for(int i=1;i<=k;i++) {
        len[i]=i<mx?min(mx-i,len[2*id-i]):1;
        while(i-len[i]>=0&&i+len[i]<=k&&t[i-len[i]]==t[i+len[i]]) ++len[i];
        if(len[i]+i>mx) {
            mx=len[i]+i;
            id=i;
            if(len[i]-1>res) {
                res=len[i]-1;
                pos=i-len[i]>>1;
            }
        }
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    char c;
    while(~scanf(" %c",&c)) {
        int t=c-'a';
        scanf("%s",s);
        for(int i=0;s[i];i++) {
            s[i]=(s[i]-'a'-t+26)%26+'a';
        }
        manacher(s);
        if(res<2) puts("No solution!");
        else {
            printf("%d %d\n",pos,pos+res-1);
            for(int i=pos;i<pos+res;i++) printf("%c",s[i]);
            puts("");
        }
    }
    return 0;
}