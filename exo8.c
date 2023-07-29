#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    switch(fork())
    {
        case -1:
            perror("Creation de processus"); return 1;
        case 0:
            printf("[%d] Pere : %d\n",getpid(),getppid());
            sleep(5);
            printf("[%d] Pere : %d\n",getpid(),getppid());            
            exit(0);
        default :
            sleep(1);
            printf("[%d] fin du Pere \n",getpid());
            exit(0);

    }
}