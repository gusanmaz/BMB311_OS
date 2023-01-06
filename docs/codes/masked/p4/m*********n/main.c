#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

char k[20];
char *get_Uid(const pid_t pid) {
	char buffer[1024];
	sprintf(buffer, "/proc/%d/status", pid);
	FILE* fp = fopen(buffer, "r");
    int i = 0;
    int j = 0;
    if(fp == NULL){
		printf("NULL\n");
		exit(1);
	}
	if (fp)
	{
	fread(buffer, sizeof (char), sizeof (buffer), fp);
    while (buffer[i] != '\0')
    {
        if (buffer[i] == 'U' && buffer[i+1] == 'i' && buffer[i+2] == 'd')
		{
            i +=5;
			while (buffer[i] != 'G')
            {
                k[j] = buffer[i];
                i++;
                j++;
            }
            k[j] = '\0';
		}
		i++;
    }
    fclose(fp);
	}
}


int main(int argc, char *argv[])
{
    struct passwd   *pwd;
    int pid  = atoi(argv[1]);
	get_Uid(pid);
    uid_t uid = atoi(k);
    pwd = getpwuid(uid);
    printf("%s\n", pwd->pw_name);

}
