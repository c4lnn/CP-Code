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
string s;
int nxt[N];
bool st[N];
void get_next1(const string &t) {
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<SZ(t)) {
        if(j==-1||s[i]==s[j]) {
            ++i,++j;
            nxt[i]=j;
        }
        else j=nxt[j];
    }
}
void get_next2(const string &t) {
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<SZ(t)) {
        if(j==-1||s[i]==s[j]) {
            ++i,++j;
            if(s[i]!=s[j]) nxt[i]=j;
            else nxt[i]=nxt[j];
        }
        else j=nxt[j];
    }
}
bool kmp(const string &s,const string &t) {
    get_next2(t);
    int i=0,j=0;
    while(i<SZ(s)) {
        if(j==-1||s[i]==t[j]) {
            ++i,++j;
            if(j==SZ(t)) return true;
        }
        else j=nxt[j];
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        cin>>s;
        for(int i=0;i<SZ(s);i++) st[i]=false;
        get_next1(s);
        int res=0;
        for(int i=nxt[SZ(s)];i>=1;i--) {
            if(s.substr(0,i)==s.substr(SZ(s)-i,i)&&kmp(s.substr(i,SZ(s)-i-i),s.substr(0,i))) {
                res=i;
                break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}