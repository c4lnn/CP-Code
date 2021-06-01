#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
// head
const int DIR[4][2]={-1,0,1,0,0,-1,0,1};
string s,t;
PII pos[10];
map<string,bool> st;
map<string,int> dist;
struct R {
    int f;
    string s;
    R() {}
    R(int f,string s):f(f),s(s) {}
    bool operator < (const R &T) const {
        return f>T.f;
    }
};
bool valid(int x,int y) {
    if(x>=0&&x<3&&y>=0&&y<3) return true;
    return false;
}
int f(const string &x) {
    int ret=0;
    for(int i=0;i<9;i++) if(x[i]!='.') {
        int d=x[i]-'0';
        ret+=abs(i/3-pos[d].FI)+abs(i%3-pos[d].SE);
    }
    return ret;
}
int astar() {
    for(int i=0;i<9;i++) if(t[i]!='.') pos[t[i]-'0']=MP(i/3,i%3);
    priority_queue<R> q;
    q.push(R(f(s),s));
    dist[s]=0;
    while(SZ(q)) {
        R u=q.top();
        q.pop();
        if(st.count(u.s)) continue;
        st[u.s]=true;
        if(u.s==t) return dist[t];
        for(int i=0;i<9;i++) if(u.s[i]=='.') {
            int x=i/3,y=i%3,step=dist[u.s];
            for(int j=0;j<4;j++) {
                int tx=x+DIR[j][0],ty=y+DIR[j][1];
                if(!valid(tx,ty)) continue;
                string ss=u.s;
                swap(ss[i],ss[tx*3+ty]);
                if(!dist.count(ss)||dist[ss]>step+1) {
                    dist[ss]=dist[u.s]+1;
                    q.push(R(dist[ss]+f(ss),ss));
                }
            }
            break;
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>t;
    int cnt1=0,cnt2=0;
    for(int i=0;i<9;i++) if(s[i]!='.') {
        for(int j=0;j<9;j++) if(s[j]!='.') {
            if(s[i]>s[j]) ++cnt1;
        }
    }
    for(int i=0;i<9;i++) if(t[i]!='.') {
        for(int j=0;j<9;j++) if(t[j]!='.') {
            if(t[i]>t[j]) ++cnt2;
        }
    }
    if((cnt1+cnt2)&1) cout<<-1<<'\n';
    else cout<<astar()<<'\n';
    return 0;
}