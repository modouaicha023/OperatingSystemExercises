#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pid_t status;
    status =fork() ;   
    switch(status){
        case -1:
            perror("Error dans l'appel fork"); return -1;
        case 0:
            switch(fork()){
                case -1:
                    perror("Erreur de la creation de processus intermediaire\n"); return -1;
                case 0:
                    printf("Petit Fils :processus [%d], Mon Pere est [%d] \n",getpid(),getppid());
                    sleep(5);
                    printf("Petit Fils :processus [%d], Mon Pere est [%d] \n",getpid(),getppid());
                    break;
                default :
                    sleep(1);                
                    printf("Pere :processus [%d], Mon Pere est [%d] \n",getpid(),getppid());
                    return 0;
            };
        break;
        default:
        printf("Grand Pere : processus [%d],Mon Pere : [%d]\n",getpid(),getppid());
        wait(&status);break;
    };
    exit(EXIT_SUCCESS);
}