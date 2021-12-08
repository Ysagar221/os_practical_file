#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
using namespace std;

#define size 200

int main(int argc, char * argv[])
{
    char *source, *destination;
    cout<<"\nThe source file from which you want to read: ";
    cout<<argv[1];
    cout<<"\n The destination file in which you want to write : ";
    cout<<argv[2];

    source = argv[1];
    destination = argv[2];
    cout<<"\nSource file is : "<<source<<"\nDestination file is : "<<destination;
 
    int fd1 = open(source , O_RDONLY , S_IRWXU | S_IRWXG | S_IRWXO);
    int fd2 = open(destination , O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO) ;

    if(fd1 == -1)
    {
        cout<<"\nError : source file does not exists!!";
        return 0;
    }         
    if(fd2 == -1)
    {
        cout<<"\nError : destination file does not exists!!";
        return 0;
    }  

    int r1 , r2;
    char buff[size];
    do
    {
        r1 = read(fd1, (void*)buff , size);
        if(r1 == -1)
        {
              cout<<"\nError in reading source file!! ";
              return 0;
        }
        
        r2 = write(fd2 , (void*)buff , r1);
        if(r2 == -1)
        {
            cout<<"\nError in writing at destination file!! ";
            return 0;
        }
    }while(r1 != 0);

    cout<<"\n Successfully read from source file!! ";
    cout<<"\n Successfully written to destination file !!.";

    close(fd1);
    close(fd2);

    fd1 = open(destination , O_RDONLY);
    while(r1 != 0)
    {
        r1 = read(fd1 , (void*)buff , size-1);
        if(r1 == -1)
        {
            cout<<"\nError file can't be open!!";
        }
        buff[r1] = '\0';
        cout<<buff<<"\n";
    }
  return 0;
}

