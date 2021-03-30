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
char s[N];
int nxt[N],len;
int get_min() {
    int k=0,i=0,j=1;
    while(k<len&&i<len&&j<len) {
        if(s[(i+k)%len]==s[(j+k)%len]) ++k;
        else {
            s[(i+k)%len]>s[(j+k)%len]?i=i+k+1:j=j+k+1;
            if(i==j) ++i;
            k=0;
        }
    }
    return min(i,j);
}
int get_max() {
    int k=0,i=0,j=1;
    while(k<len&&i<len&&j<len) {
        if(s[(i+k)%len]==s[(j+k)%len]) ++k;
        else {
            s[(i+k)%len]<s[(j+k)%len]?i=i+k+1:j=j+k+1;
            if(i==j) ++i;
            k=0;
        }
    }
    return min(i,j);
}
void get_next() {
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<len) {
        if(j==-1||s[i]==s[j]) {
            ++i,++j;
            nxt[i]=j;
        }
        else j=nxt[j];
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%s",s)) {
        len=strlen(s);
        int pos1=get_min();
        int pos2=get_max();
        get_next();
        int t=len%(len-nxt[len])?1:len/(len-nxt[len]);
        printf("%d %d %d %d\n",pos1+1,t,pos2+1,t);
    }
    return 0;
}