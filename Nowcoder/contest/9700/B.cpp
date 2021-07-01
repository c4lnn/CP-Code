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
const int N=1e5+5;
int nxt[N],ed=-1;
bool st[N];
void get_next(const string &t) {
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<SZ(t)) {
        if(j==-1||t[i]==t[j]) {
            ++i,++j;
            if(t[i]!=t[j]) nxt[i]=j;
            else nxt[i]=nxt[j];
        }
        else j=nxt[j];
    }
}
void kmp(const string &s,const string &t) {
    get_next(t);
    int i=0,j=0;
    while(i<SZ(s)) {
        if(j==-1||s[i]==t[j]) {
            ++i,++j;
            if(j==SZ(t)) ed=i-SZ(t),st[i-SZ(t)]=true,j=nxt[j];
        }
        else j=nxt[j];
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    kmp(s,"NowCoder");
    LL res=0;
    for(int i=ed,t;i>=0;i--) {
        if(st[i]) t=i+7;
        res+=SZ(s)-t;
    }
    cout<<res<<'\n';
    return 0;
}