#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n);
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define clear(a) memset(a,0,sizeof(a))

#define debug() cout<<"BUG"<<endl

using namespace std;

char *formatdate(char *buff, time_t val)
{
    strftime(buff,200, "%d.%m.%Y %H:%M:%S", localtime(&val));
    return buff;
}
void stat(char *filename){
	
	struct stat file;
	int n;
	char p[30];
	if((n=stat(filename,&file))==-1){
		perror(filename);
		return ;
	}
	/*print file permissions*/
	else
	{
		printf( (S_ISDIR(file.st_mode)) ? "d" : "-");
		printf( (file.st_mode & S_IRUSR) ? "r" : "-");
		printf( (file.st_mode & S_IWUSR) ? "w" : "-");
		printf( (file.st_mode & S_IXUSR) ? "x" : "-");
		printf( (file.st_mode & S_IRGRP) ? "r" : "-");
		printf( (file.st_mode & S_IWGRP) ? "w" : "-");
		printf( (file.st_mode & S_IXGRP) ? "x" : "-");
		printf( (file.st_mode & S_IROTH) ? "r" : "-");
		printf( (file.st_mode & S_IWOTH) ? "w" : "-");
		printf( (file.st_mode & S_IXOTH) ? "x\t" : "-\t");
	
		/*print file details*/
		printf("%8d", file.st_uid);
		printf("%15d\t", file.st_gid);
		printf("%20ld\t", file.st_size);
		printf("%25s\t", formatdate(p,file.st_mtime));
		
		/*detect file type*/
		if(file.st_mode & S_IFREG){
			printf("Regular\t");
		}
		if(file.st_mode & S_IFDIR){
			printf("Directory\t");
		}
	}
}

int main(int argc, char *argv[])
{
	dirent *dir;
	DIR *dname;
	int allFlag=0,statFlag;
	
	if (argc < 2)
	{
		printf("Usage: ./<executable file> <directory>\n");
		exit(-1);
	}
	if((dname = opendir(argv[1])) == NULL)
	{
		perror(argv[1]);
		exit(-1);
	}
	for(int j=0;j<argc;j++){
		printf("%d %s\n",j,argv[j]);
	}
	if(strcmp("-a",argv[2])==0){
		allFlag=1;
	}
	if(argc==4){
		if(strcmp("-a",argv[3])==0)){
			
		}
			
	}
	if(strcmp("-l",argv[2])==0 || strcmp("-l",argv[3])==0){
		statFlag=1;
	}
	puts("Permissions\t User ID\t GroupID\t File Size(bytes)\t Last Modified\t\tFile/Dir\t Name\n");
	
	while(dir=readdir(dname))
		
		{
			char p[200];
			clear(p);
			strcat(p,argv[1]);
			strcat(p,dir->d_name);
			
			if(dir->d_name[0]=='.' && !allFlag){
				continue;
			}
			if(statFlag){
				stat(p);
			}
			
			printf("%20s\n", dir->d_name);
			clear(p);
		}
		closedir(dname);
	
	return 0;
}
