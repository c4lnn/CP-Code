#include<bits/stdc++.h>
 
using namespace std;
 
const int N=55;

int n,k;
int a[55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("in.txt","r",stdin);

    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int key=a[k]?a[k]:1;
    for(int i=1;i<=n;i++)
    {
    	if(a[i]<key)
    	{
    		cout<<i-1<<endl;
    		return 0;
    	}
    }
    cout<<n<<endl;
    return 0;
}