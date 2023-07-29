#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int glob =1;
int main(){
    pid_t pid;
    int status;
    pid =fork() ;   
    switch(pid)
    {
        case -1:
            perror("Error dans l'appel fork");
            exit(1);
        case 0:
            printf("Processus Fils [%d] : mon pere est %d \n",getpid(),getppid());
            exit(2);
        default :
        printf(" Pere [%d] : a cree processus[%d] \n",getpid(),pid);
        wait(&status);
        if (WIFEXITED(status))
        {
            printf("Le fils termine normalement: status =%d\n",WEXITSTATUS(status));
        }
        else
            printf("Fils termine anormalemennt");
    }
}