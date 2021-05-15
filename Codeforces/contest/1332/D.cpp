#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

int a[10][10];
int f[10][10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>k;
    int t=(int)(log(k+1)/log(2));
    int n=(1<<(t+1))-1;
    int m=(1<<(t+2))-1;
    cout<<3<<" "<<4<<endl;
    cout<<m<<" "<<n<<" "<<n<<" "<<0<<endl;
    cout<<n+1<<" "<<0<<" "<<n<<" "<<n-k<<endl;
    cout<<m<<" "<<m<<" "<<m<<" "<<n<<endl;
    return 0;
}