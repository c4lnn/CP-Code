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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int nx,ny,d,n;cin>>nx>>ny>>d>>n;
        for(int i=1;i<=n;i++) {
            int x,y;cin>>x>>y;
            if(d==0) {
                if(ny<=y) {
                    for(int j=ny;j<y;j++) cout<<'f';
                    if(nx<x) {
                        cout<<'c';
                        for(int j=nx;j<x;j++) cout<<'f';
                        d=1;
                    }
                    else if(nx>x) {
                        cout<<'u';
                        for(int j=x;j<nx;j++) cout<<'f';
                        d=3;
                    }
                }
                else {
                    if(nx<x) {
                        cout<<'c';
                        for(int j=nx;j<x;j++) cout<<'f';
                        cout<<'c';
                    }
                    else if(nx>x) {
                        cout<<'u';
                        for(int j=x;j<nx;j++) cout<<'f';
                        cout<<'u';
                    }
                    d=2;
                    for(int j=y;j<ny;j++) cout<<'f';
                }
            }
            else if(d==1) {
                if(nx<=x) {
                    for(int j=nx;j<x;j++) cout<<'f';
                    if(ny<y) {
                        cout<<'u';
                        for(int j=ny;j<y;j++) cout<<'f';
                        d=0;
                    }
                    else if(ny>y) {
                        cout<<'c';
                        for(int j=y;j<ny;j++) cout<<'f';
                        d=2;
                    }
                }
                else {
                    if(ny<y) {
                        cout<<'u';
                        for(int j=ny;j<y;j++) cout<<'f';
                        cout<<'u';
                    }
                    else if(ny>y) {
                        cout<<'c';
                        for(int j=y;j<ny;j++) cout<<'f';
                        cout<<'c';
                    }
                    d=3;
                    for(int j=x;j<nx;j++) cout<<'f';
                }
            }
            else if(d==2) {
                if(ny>=y) {
                    for(int j=y;j<ny;j++) cout<<'f';
                    if(nx<x) {
                        cout<<'u';
                        for(int j=nx;j<x;j++) cout<<'f';
                        d=1;
                    }
                    else if(nx>x) {
                        cout<<'c';
                        for(int j=x;j<nx;j++) cout<<'f';
                        d=3;
                    }
                }
                else {
                    if(nx<x) {
                        cout<<'u';
                        for(int j=nx;j<x;j++) cout<<'f';
                        cout<<'u';
                    }
                    else if(nx>x) {
                        cout<<'c';
                        for(int j=x;j<nx;j++) cout<<'f';
                        cout<<'c';
                    }
                    d=0;
                    for(int j=ny;j<y;j++) cout<<'f';
                }
            }
            else {
                if(nx>=x) {
                    for(int j=x;j<nx;j++) cout<<'f';
                    if(ny<y) {
                        cout<<'c';
                        for(int j=ny;j<y;j++) cout<<'f';
                        d=0;
                    }
                    else if(ny>y) {
                        cout<<'u';
                        for(int j=y;j<ny;j++) cout<<'f';
                        d=2;
                    }
                }
                else {
                    if(ny<y) {
                        cout<<'c';
                        for(int j=ny;j<y;j++) cout<<'f';
                        cout<<'c';
                    }
                    else if(ny>y) {
                        cout<<'u';
                        for(int j=y;j<ny;j++) cout<<'f';
                        cout<<'u';
                    }
                    d=1;
                    for(int j=nx;j<x;j++) cout<<'f';
                }
            }
            nx=x,ny=y;
        }
        cout<<'\n';
    }
    return 0;
}