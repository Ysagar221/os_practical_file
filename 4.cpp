#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    struct stat fs;
    stat(argv[1],&fs); //two arguments are passed to start , first is the file name(enter by user)
    //and second is pointer to structure sta(ie fs)
    cout<<argv[1];
    cout<<fs.st_gid;
    cout<<"\n user id is :"<<fs.st_uid;
    cout<<"\n group id is :"<<fs.st_gid;
    cout<<"\n id of device containing files :"<<fs.st_dev;
    cout<<"\n inode number is :"<<fs.st_ino;
    cout<<"\n file type and mode is :"<<fs.st_mode;
    cout<<"\n numbers of hard links :"<<fs.st_nlink;
    cout<<"\n device id is :"<<fs.st_rdev;
    cout<<"\n total size in bytes is :"<<fs.st_size;
    cout<<"\n block size for file system I/O is :"<<fs.st_blksize;
    cout<<"\n number of 5128 blocks allocated is :"<<fs.st_blocks;
    cout<<"\n acess permission are :"<<fs.st_mode;
    int c = fs.st_mode & 07777;
    cout<<"\n acess permination are :octal";
    cout<<std::oct<<c;
    cout<<"\n Access time is :"<<ctime(&fs.st_atime);
    
    cout<<"\n Time of last access is: "<<ctime(&fs.st_atime);
    cout<<"\n Time of last modification is: "<<ctime(&fs.st_mtime);
    cout<<"\n Time of last status change is: "<<ctime(&fs.st_ctime);
    
exit(0);

}
