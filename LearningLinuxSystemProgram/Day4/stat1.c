//stat函数测试: 获取文件类型和权限
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	//int stat(const char *pathname, struct stat *buf);
	//获取文件属性
	struct stat sb;
	stat(argv[1], &sb);

	//获取文件类型
	//st_mode是十六位二进制，0-2是其他人权限，3-5是所属组权限，6-8是所属用户权限，12-15是文件类型
	//S_IFMT是文件类型掩码，具体是： 001111
	//这里为什么需要先和掩码做&，然后判断是否相等？ 因为文件类型只可能是一种！
	if ((sb.st_mode & S_IFMT) == S_IFREG) 
 	{
		printf("普通文件\n");
	}	
	else if((sb.st_mode & S_IFMT) ==S_IFDIR)
	{
		printf("目录文件\n");
	}
	else if((sb.st_mode & S_IFMT) ==S_IFLNK)
	{
		printf("连接文件\n");
	}
	

	if (S_ISREG(sb.st_mode)) 
	{
	 	printf("普通文件\n");
	}
	else if(S_ISDIR(sb.st_mode))
	{
		printf("目录文件\n");
	}
	else if(S_ISLNK(sb.st_mode))
	{
		printf("连接文件\n");
	}

	//判断文件权限
	//这里为什么可以直接做&，因为某个用户可能同时拥有这三个权限！
	if(sb.st_mode & S_IROTH)
	{
		printf("---R----");
	}

	if(sb.st_mode & S_IWOTH)
	{
		printf("---W----");
	}
	
	if(sb.st_mode & S_IXOTH)
	{
		printf("---X----");
	}

	printf("\n");

	return 0;
}
