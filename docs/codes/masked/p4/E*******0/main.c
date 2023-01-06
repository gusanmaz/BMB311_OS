#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *join(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result)
    {
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}

int main(int argc, char const *argv[])
{
	if(argc != 2)
		return 0;

    FILE *fp;
	char *path;
	char *temp;
    int id;
	temp = join("/proc/", argv[1]);
	path = join(temp,"/comm");
	free(temp);
	if ((fp = fopen (path, "r")) == NULL) {
		printf("NULL\n");
		return (1);
	}
    while ((id=fgetc(fp))!= EOF) {
       printf("%c", id);
    }
	free(path);
	fclose(fp);
	return (1);
}
