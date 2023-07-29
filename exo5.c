#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    printf("Before  Fork \n");
    fork();
    printf("After Fork\n");
    return 0;
}