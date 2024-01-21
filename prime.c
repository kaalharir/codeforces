#include <stdio.h>
#include <stdlib.h>

boolean prime(int n)
{
    int count=0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            count++;
        }
        if(count==2)
            return true;
        else
            return false;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int res=prime(n);
    printf("Result ",res);
}
