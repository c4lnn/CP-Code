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
struct SAM {
    int len,link;
    unordered_map<int,int> nxt;
}sam[N<<1];
int n,sz,last;
void sam_init() {
    sam[0].len=0;
    sam[0].link=-1;
    sz=0;
    last=0;
}
void sam_extend(int x) {
    int cur=++sz;
    sam[cur].len=sam[last].len+1;
    int p=last;
    while(p!=-1&&!sam[p].nxt.count(x)) {
        sam[p].nxt[x]=cur;
        p=sam[p].link;
    }
    if(p==-1) sam[cur].link=0;
    else {
        int q=sam[p].nxt[x];
        if(sam[p].len+1==sam[q].len) sam[cur].link=q;
        else {
            int t=++sz;
            sam[t].len=sam[p].len+1;
            sam[t].nxt=sam[q].nxt;
            sam[t].link=sam[q].link;
            while(p!=-1&&sam[p].nxt[x]==q) sam[p].nxt[x]=t,p=sam[p].link;
            sam[q].link=sam[cur].link=t;
        }
    }
    last=cur;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    LL sum=0;
    sam_init();
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        sam_extend(x);
        sum+=sam[last].len-sam[sam[last].link].len;
        cout<<sum<<'\n';
    }
    return 0;
}