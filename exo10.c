#include <stdio.h>
#include <unistd.h>

int main()
{
	execl("/bin/ls","ls",NULL);
	printf("Je suis pas mort\n");
	return 0;
}