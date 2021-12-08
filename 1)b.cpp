#include<stdio.h>
#include<unistd.h> 
#include<stdlib.h>
int main()
{ 
    int pid; 
    pid=fork(); 
    if(pid<0) 
    { 
        printf("\n Error in creating duplicate process !!!"); 
        exit(1);
    } 
    else if(pid==0)
    {
        printf("\n This is inside  the child process ");
        printf("\n Process ID of child  pid is : %d ",getpid());
        exit(0);
        } 
        else 
        { 
            printf("\n This is inside  the parent process ");
            printf("\n Process ID of parent pid is : %d \n ",getpid()); 
            exit(1); 
        } 
}
