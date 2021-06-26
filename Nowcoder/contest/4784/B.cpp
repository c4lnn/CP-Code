#include<bits/stdc++.h>

using namespace std;


const int N=100010;

int tot;
int p[N],cnt[N];

void Divide(int x) {
    tot=0;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) {
            p[++tot]=i;
            cnt[tot]=0;
            while(x%i==0) {
                cnt[tot]++;
                x/=i;
            }
        }
    }
    if(x>1) p[++tot]=x,cnt[tot]=1;
}
int check(int x) {
    for(int i=1;i<=tot;i++) {
        int temp=x,t=0;
        while(temp) t+=temp/p[i],temp/=p[i];
        if(t<cnt[i]) return false;
    }
    return true;
}
int BinarySearch(int x) {
    int l=1,r=x;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        int x;
        cin>>x;
        Divide(x);
        cout<<BinarySearch(x)<<endl;;
    }
    return 0;
}