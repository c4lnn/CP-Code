#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
  return a>b?1:0;
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        int a[n],b[n],sum=0,a_end=n,b_end=n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        for(int i=0,j=0;i<a_end&&j<b_end;i++,j++)
        {    
            if(i==a_end-1&&j==b_end-1)
            {
                if(a[i]>b[j])
                    sum+=200;
                else if(a[i]<b[j])
                    sum-=200;
                continue;
            }
            if(a[i]>b[j])
                sum+=200;
            else if(a[i]<b[j])
            {
                sum-=200;
                --a_end; 
                --i;
            }
            else if(a[i]==b[j])
            {
                if(a[a_end-1]>b[b_end-1])
                {
                    sum+=200;
                    a_end--;
                    b_end--;
                    i--;
                    j--;
                }
                else if(a[a_end-1]<=b[b_end-1])
                {
                    if(a[a_end-1]<b[j])
                        sum-=200;
                    a_end--;
                    i--;
                    
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
