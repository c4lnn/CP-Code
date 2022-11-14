#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n,m,k;
vector<int>square[60];
bool st[65];

bool check(int x) {
    vector<int> &sq=square[x];
    for(int i=0;i<sq.size();i++) if(st[sq[i]]) return false;
    return true;
}
int f() {
    int res=0;
    bool temp[65];
    memcpy(temp,st,sizeof st);
    for(int i=0;i<m;i++)
        if(check(i)) {
            res++;
            vector<int> &sq=square[i];
            for(int j=0;j<sq.size();j++) st[sq[j]]=true;
        }
    memcpy(st,temp,sizeof temp);
    return res;
}
bool dfs(int depth,int max_depth) {
    int t=f();
    if(t==0) return true;
    if(t+depth>max_depth) return false;
    for(int i=0;i<m;i++) {
        if(check(i)) {
            vector<int> &sq=square[i];
            for(int j=0;j<sq.size();j++) {
                st[sq[j]]=true;
                if(dfs(depth+1,max_depth)) return true;
                st[sq[j]]=false;
            }
            return false;
        }
    }
    return true;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        cin>>n;
        m=0;
        int d=2*n+1;
        for(int len=1;len<=n;len++)
            for(int x=1;x+len-1<=n;x++)
                for(int y=1;y+len-1<=n;y++) {
                    vector<int> &sq=square[m];
                    sq.clear();
                    for(int i=0;i<len;i++) {
                        sq.push_back(y+(x-1)*d+i);
                        sq.push_back(y+(x-1+len)*d+i);
                        sq.push_back(y+(x-1)*d+n+d*i);
                        sq.push_back(y+(x-1)*d+n+d*i+len);
                    }
                    m++;
                }
        cin>>k;
        memset(st,false,sizeof st);
        for(int i=1;i<=k;i++) {
            int num;
            cin>>num;
            st[num]=true;
        }
        for(int i=0;;i++) {
            if(dfs(0,i)) {
                cout<<i<<endl;
                break;
            }
        }
    }
     return 0;
}