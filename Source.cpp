#include "user.h"
#include "types.h"
#include "stat.h"



void head(int lins, int fd, char *name)
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
		head(0, "",10);
		exit();
	}

	else if(argc==2)
	{
		int fd = open(argv[1], 0);
		if((fd >= 0)
		{
			head(10,fd,argv[1]);
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
		arg[1]++;
		int lines= atoi(arg[1]);
		int fd = open(argv[2], 0);
		if(fd >= 0)
		{
			head(atoi(arg[1]),fd,argv[2]);
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
