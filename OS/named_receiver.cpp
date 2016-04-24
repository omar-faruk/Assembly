#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n);
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define clear(a) memset(a,0,sizeof(a))
using namespace std;
#define MAX_BUF 1

int main()
{
    int fd;
    char * myfifo = "myfifo";
    unlink(myfifo);
    mkfifo(myfifo, 0666);
    char buf[MAX_BUF];

    fd = open(myfifo, O_RDONLY);
    while(read(fd,&buf, MAX_BUF) > 0){
		printf("%s", buf);
	}
	

    close(fd);
	unlink(myfifo);
    return 0;
}
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n);
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define clear(a) memset(a,0,sizeof(a))
using namespace std;
#define MAX_BUF 1

int main()
{
    int fd;
    char * myfifo = "myfifo";
    unlink(myfifo);
    mkfifo(myfifo, 0666);
    char buf[MAX_BUF];

    fd = open(myfifo, O_RDONLY);
    while(read(fd,&buf, MAX_BUF) > 0){
		printf("%s", buf);
	}
	

    close(fd);
	unlink(myfifo);
    return 0;
}
