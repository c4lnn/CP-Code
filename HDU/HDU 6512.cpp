#include<bits/stdc++.h>
using namespace std;
int a[6000000];
int main()
{
    int n;
    while(cin>>n)
    {
        int flag=0;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(n<94)
        {
            sort(a,a+n);
            for(int i=0;i<n-2;i++)    
                if(a[i+1]>a[i+2]-a[i])
                {
                    flag=1;
                    break;
                }
        }
        else
            flag=1;
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
} 