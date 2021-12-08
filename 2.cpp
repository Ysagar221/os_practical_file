#include<iostream>
using namespace std;

int main() 
{
cout<<"----Displaying CPU information----";
cout<<"\nThe kernel version is : \n";
cout<<system("cat /proc/sys/kernel/osrelease")<<endl;
cout<<"CPU type and model : \n";
cout<<system("cat /proc/cpuinfo | awk 'NR=5' ");
cout<<endl;
return(0) ;
}
