#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pid_t status;
    status = fork();
    switch(status)
    {
        case -1:
            perror("creation de processus");
        return -1;
        case 0:
            printf("[%d] Je viens de naitre \n",getpid());
            printf("[%d] Mon pere %d\n",getpid(),getppid());
        break;
        default :
            printf("[%d] J'ai engendre \n",getpid());
            printf("[%d] Mon fils est %d\n",getpid(),status); 

    }
    printf("[%d] Je termine\n",getpid()); 
    exit(EXIT_SUCCESS);
    
}