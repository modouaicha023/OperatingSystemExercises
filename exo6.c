#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int glob =1;
int main(){
    pid_t id = 0;
    printf("Processus pere [%d]\n",getpid());
    if(fork()==0)
    {
        printf("Processus Enfant [%d] : mon pere est %d \n",getpid(),getppid());
        exit(0);
    }
    id = wait(NULL);
    printf("Processus pere [%d] : mon Enfant %d est mort \n",getpid(),id);
    return 0;    
}