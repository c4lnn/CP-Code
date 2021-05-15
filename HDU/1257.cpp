#include<bits/stdc++.h>
using namespace std;
int a[3000000]; 
int main()
{
    int n;
    while(cin>>n&&n)
    {
        int now_h;
        int sum=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            if(a[i])
            {
                sum++;
                now_h=a[i];
                for(int j=i+1;j<n;j++)
                    if(a[j]&&a[j]<=now_h)
                    {
                        now_h=a[j];
                        a[j]=0;
                    }
            }
        }    
        cout<<sum<<endl;
    }
    return 0;
}