#include<bits/stdc++.h>
 
using namespace std;

const int N=22;
 
int n,m;
string s[N],t[N];
int q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
 	cin>>n>>m;
 	for(int i=0;i<n;i++) cin>>s[i];
 	for(int i=0;i<m;i++) cin>>t[i];
 	cin>>q;
 	for(int i=1;i<=q;i++)
 	{
 		int x;
 		cin>>x;
 		x--;
 		cout<<s[x%n]<<t[x%m]<<endl;
 	}
    return 0;
}