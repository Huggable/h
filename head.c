#include "types.h"
#include "stat.h"
#include "user.h"



void head(int x, int fd, char *name,char *buf)
{
  int i, n;
  int l, w, c;

  l = w = c = 0;

  while((n = read(fd, buf, sizeof(buf))) > 0 && l<x)
  {
  	
    for(i=0;i<=n && l<x;i++)
    {
      if(buf[i]!='\n')
      {
      	printf(1,"%c",buf[i]);
      }		
      else
      {
      	printf(1,"\n");
      	l++;
      }
      
      
      
    }
    // printf(1,"hey there : %d\n",l);

  }
  if(n < 0)
  {
    printf(1, "head: read error\n");
    exit();
  }
  // printf(1, "%d %d %d %s\n", l, w, c, name);
}

int main(int argc, char *argv[])
{
	char buf[2000];

	if(argc == 1)
	{
		head(10,0,"",buf);
		exit();
	}

	else if(argc==2)
	{
		int fd = open(argv[1], 0);
		if(fd >= 0)
		{
			head(10,fd,argv[1],buf);
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
			head(atoi(num),fd,argv[2],buf);
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
