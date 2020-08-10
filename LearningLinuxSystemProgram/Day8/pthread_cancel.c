//创建子线程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

//线程执行函数
void *mythread(void *arg)
{
	while(1)
	{
		int a;
		int b;

		//设置取消点
		//pthread_testcancel();

		printf("-----\n");  //printf会调用write系统调用！ 会到达取消点！
	}
}

int main()
{
	//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                      void *(*start_routine) (void *), void *arg);
	//创建子线程
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if(ret!=0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		return -1;
	}
	printf("main thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());

	//取消子线程
	pthread_cancel(thread);

	pthread_join(thread, NULL);  //一直阻塞等待子线程退出！
	return 0;
}
