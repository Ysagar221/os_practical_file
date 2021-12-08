
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

int main() 
{
    int pid , p;
    p = fork();
    pid = getpid();
    
    if(p<0)
    {
        printf("\n FORK Failed !!!");
        return 1;
    }
    printf("Output of the fork ID : %d \n",p);
    printf(" Process ID is :  %d\n",pid);
    return 0;
}
