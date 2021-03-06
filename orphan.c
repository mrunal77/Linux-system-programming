//header files inclusion
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
//main function starts here
int main()
{
  int n;
  n=fork();
  switch(n)
  {
    case -1:
      //failure case
      printf("failed to create child process\n");
      break;
  case 0:
      //child process since fork returns 0 to the child process 
      printf("In child process, before sleep, PID=%d PPID=%d\n", getpid(),getppid());
      sleep(10);
      printf("In child process, after sleep, PID=%d PPID=%d\n", getpid(),getppid());//to demonstrate orphan process
      printf("child process died\n");
      break;
  case default:
      //parent process since fork returs PID of the child process 
      printf("In parent process, before sleep, PID=%d PPID=%d\n", getpid(),getppid());
      sleep(5);
      printf("In parent process, after sleep, PID=%d PPID=%d\n", getpid(),getppid());
      printf("parent process died\n");
      break;
  }
  return 0;
}   
