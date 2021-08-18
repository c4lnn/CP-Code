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
// head
const int N=1e7+5;
int l[N],r[N],pos[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;cin>>q;
    int x=0,sum=0,head=0,tail=0,mid=0;
    int ll=1,rr=0;
    for(int i=1;i<=q;i++) {
        char c;cin>>c;
        if(c=='L') {
            ++sum;
            ++x;
            l[head]=x;
            r[x]=head;
            head=x;
            if(sum==1) tail=mid=head;
            else if(sum%2==1) mid=l[mid];
            pos[x]=--ll;
        }
        else if(c=='R') {
            ++sum;
            ++x;
            r[tail]=x;
            l[x]=tail;
            tail=x;
            if(sum==1) head=mid=tail;
            else if(sum%2==0) mid=r[mid];
            pos[x]=++rr;
        }
        else if(c=='G') {
            int x;cin>>x;
            r[l[x]]=r[x];
            l[r[x]]=l[x];
            if(head==x) head=r[x];
            if(tail==x) tail=l[x];
            if(sum%2==0&&pos[x]>=pos[mid]) mid=l[mid];
            else if(sum%2==1&&pos[x]<=pos[mid]) mid=r[mid];
            --sum;
        }
        else cout<<mid<<'\n';
    }
    return 0;
}