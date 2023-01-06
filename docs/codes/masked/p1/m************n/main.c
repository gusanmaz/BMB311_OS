#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	int id1 = fork();
	int id2 = fork();
	int id3 = fork();
	int id4 = fork();
	int id5 = fork();
	int id6 = fork();
	int id7 = fork();
	int id8 = fork();
	int id9 = fork();
	int id10 = fork();

	wait(&id1);
	wait(&id2);
	wait(&id3);
	wait(&id4);
	wait(&id5);
	wait(&id6);
	wait(&id7);
	wait(&id8);
	wait(&id9);
	wait(&id10);
	
	exit(0);
}
