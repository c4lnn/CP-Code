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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
int nxt[N],extend[N];
void get_next(const string &t) {
    int l=0,r=0;
    int len=t.length();
    nxt[0]=len;
    for(int i=1;i<len;i++) {
        if(i>r||i+nxt[i-l]>=r) {
            if(i>r) r=i;
            while(r<len&&t[r]==t[r-i]) r++;
            nxt[i]=r-i;
            l=i;
        }
        else nxt[i]=nxt[i-l];
    }
}
void get_extend(const string &s,const string &t) {
    get_next(t);
    int l=0,r=0;
    int len_s=s.length(),len_t=t.length();
    for(int i=0;i<len_s;i++) {
        if(i>r||i+nxt[i-l]>=r) {
            if(i>r) r=i;
            while(r<len_s&&r-i<len_t&&s[r]==t[r-i]) r++;
            extend[i]=r-i;
            l=i;
        }
        else extend[i]=nxt[i-l];
    }
}
int main() {
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t;
    cin>>s>>t;
    get_extend(t,s);
    int mn=min(SZ(s),SZ(t));
    LL res=0;
    for(int i=0;i<mn;i++) {
        if(s[i]==t[i]) res+=extend[i+1];
        else break;
    }
    cout<<res<<'\n';
    return 0;
}