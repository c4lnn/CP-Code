#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

map<string,string>mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1,s2;
    for(int i=1;i<=3;i++) {
        cin>>s1>>s2;
        mp[s2]=s1;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string temp;
        cin>>temp;
        if(!mp.count(temp)) cout<<"Fake"<<endl;
        else cout<<mp[temp]<<endl;
    }
    return 0;
}