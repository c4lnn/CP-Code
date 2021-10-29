#include <stdio.h>
int main() {
    int a,b;scanf("%d%d",&a,&b);
    int i=1,sum=0;
    for(;a+i-1<=b;i++) {
        printf("%5d",a+i-1);
        if(a+i-1==b||i%5==0) putchar('\n');
        sum+=a+i-1;
    }
    printf("Sum = %d\n",sum);
    return 0;
}