#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const char d[]="0FEDCBAGFE";
char b[5010];
bool st[5010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=n;j++) {
            char c;
            cin>>c;
            if(c=='o') b[j]=d[i];
            if(c=='|') st[j]=true;
        }
    }
    for(int i=1;i<=n;i++) {
        if(st[i]) cout<<"|";
        else cout<<b[i];
    }
    cout<<endl;
    return 0;
}