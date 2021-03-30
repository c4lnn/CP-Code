#include<stdio.h>
#include<string.h>
#include<math.h>
char a[1000001];
int c;
int b[100];
int t;
int i,j,k;
int main()
{
    scanf("%s",a);
    int len=strlen(a);
    for(i=0;i<len;i+=3)
    {
        t=0;    
          for(j=0;j<3;j++) 
            for(k=0;k<8;k++)
                {
                    b[t++]=a[i+j]&1;
                a[i+j]>>=1;
            }        
        for(j=0;j<4;j++)
        {
            c=0;
            for(k=j*6;k<6*(j+1);k++)
            {
                c<<=1;
                c|=b[k];
            }
            printf("%d ",c);
        }
    }    
    return 0;
}