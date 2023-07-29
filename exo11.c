#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	if (fork() == execl("/bin/ls","ls",NULL));
	else
	{
		sleep(2);
		printf("Je suis le pire et je peux continuer");
	}
}