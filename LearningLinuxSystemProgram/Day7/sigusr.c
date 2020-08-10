//使用SIGUSR1和SIGUSR2在父子进程间交替数数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

int num = 0;
int flag;    //全局变量，对于父子进程，不是共享的，读时共享，写时复制

void func1(int signo)
{
	printf("F:[%d]\n", num);
	num += 2;
	flag = 0;
	sleep(1);
}

void func2(int signo)
{
	printf("C:[%d]\n", num);
	num += 2;
	flag = 0;
	sleep(1);
}

int main(int argc, char *argv[])
{
	int ret;
	pid_t pid;
	
	pid = fork();
	if(pid<0)
	{
		perror("fork error");
		return -1;
	}
	else if(pid>0)   //父进程
	{
		num=0;
		flag  = 1;  //开始等于1
		signal(SIGUSR1, func1);	 //注册SIGUSR1的回调

		while(1)
		{
			if(flag==0) //等于0才会执行，所以一开始不会执行！ 回调函数触发的时候会把flag设置为0，就可以执行了！
			{
				kill(pid, SIGUSR2);  //给子进程发送SIGUSR2信号
				flag = 1;
			}
		}
	}
	else if(pid==0)   //子进程
	{
		num=1;
		flag = 0;  //开始等于0
		signal(SIGUSR2, func2);   //注册SIGUSR2的回调

		while(1)
		{
			if(flag==0)  //等于0就会执行，所以一开始就会执行
			{
				kill(getppid(), SIGUSR1);  //给父进程发送SIGUSR1信号！
				flag = 1;  //设置为1，等待父进程唤醒它！
			}
		}
	}
}

