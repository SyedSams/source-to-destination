#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#define MAX 1024

int main(int argc , char *argv[])
{

struct dirent *files;
DIR *dir;
DIR *target;

dir = opendir(argv[1]);

if(!dir)
printf("error");

else
{
	int n=0;

	while (files = readdir(dir))
	{

	if ( n == 0)
	n = errno;

	struct stat st_buf;
	stat ( files->d_name ,& st_buf);

		if (S_ISDIR (st_buf.st_mode))
		{
		continue;
		}

		else if(S_ISREG (st_buf.st_mode))
		{

		FILE *f1 =fopen( files->d_name , "r");

		if(f1)
		{
		char f2[MAX] ={0};
		sprintf(f2 , "%s/%s",argv[2],files->d_name);

		FILE *f3 =fopen( f2 , "w");

			if(f3)
			{
			char buffer[MAX] ={0}; 

			while(fgets(buffer,MAX, f1))
			{
			fputs(buffer,f3);
			}

			fclose(f3);
			}

			else
			{
			printf("%s" ,f2);
			}

			fclose(f1);
			}
		}

		else
		{
		printf("error occur");
		}

if(n != errno)
printf("error occur");

else
printf("....finished successfully....\n");

}
}
}


