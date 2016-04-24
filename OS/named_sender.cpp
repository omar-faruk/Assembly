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
int main()
{
    int fd;
    char * myfifo = "myfifo";
    fd = open(myfifo, O_WRONLY);
    cout<<fd<<endl;
    freopen("sender.cpp","r",stdin);
    
    char c;
    while(cin>>c){
		write(fd,&c,sizeof(c));
	}
    close(fd);

    return 0;
}
