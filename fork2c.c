//header files inclusion
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
//main function starts here
int main()
{
  int n;
  printf("in parent process, PID=%d\n",getpid());
  printf("creating child A\n");
  child_a=fork();
  if(child_a<0)
      printf("failed to create child process\n");
  else
  {  
    if(child_a==0)
    {//child A
      printf("in child A, before sleep, PID=%d, PPID=%d\n",getpid(),getppid());
      sleep(3);
      printf("in child A, after sleep, PID=%d, PPID=%d\n",getpid(),getppid());
      printf("child A died\n");
    }
    else
    {//parent
      printf("in parent process, creating child B\n");
      child_b=fork();
      if(child_b<0)
        printf("failed to create child process\n");
      else
      {
        if(child_b==0)
        {//child B
          printf("in child B, before sleep, PID=%d, PPID=%d\n",getpid(),getppid());
          sleep(5);
          printf("in child B, after sleep, PID=%d, PPID=%d\n",getpid(),getppid());
          printf("child B died\n");
        }
        else
        {//parent
          printf("in parent process, waiting for completion for child processes\n");
          while(wait(NULL)!=1);
          printf("all child processes died\n");
          printf("parent process died\n");
        }
      }
    }
  }
  return 0;   
} 
