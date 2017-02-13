#include "types.h"
#include "stat.h"
#include "user.h"



void head(int LineNum, int fd)
{
	char buf[200];
	int line = 0;
	int n = read(fd, buf, sizeof(buf));

	while(n > 0 && line < LineNum)
	{
		for(int i = 0;i <= n && line < LineNum; i++)
		{
			if(buf[i]!='\n')
			{
				printf(1,"%c",buf[i]);
			}		
			else
			{
				printf(1,"\n");
				line++;
			}   
		}
		n = read(fd, buf, sizeof(buf));
	}
	if(n < 0)
	{
		printf(1, "ERROR");
		exit();
	}
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		head(10,0);
		exit();
	}

	else if(argc==2)
	{
		int fd = open(argv[1], 0);
		if(fd >= 0)
		{
			head(10,fd);
		}
		else
		{
			exit();
		}
		close(fd);
	}
	else if(argc==3)
	{
		if(argv[1][0] != '-')
		{
			printf(1,"ERROR");
			exit();
		}
		char temp[20];
		strcpy(temp,argv[1]);
		char* num = temp;
		num = num + 1;
		int fd = open(argv[2],0);
		if(fd >= 0)
		{
			head(atoi(num),fd);
		}
		else
		{
			exit();
		}
		
		close(fd);
	}
	else
	{
		printf(1,"ERROR");
	}
	exit();
}
