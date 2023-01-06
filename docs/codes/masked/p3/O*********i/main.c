#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


typedef struct s_binary
{
	pthread_t		th_id;
	int				count;
	char			*filepath;
}				t_binary;


void	*life_cycle(void *arg)
{
	t_binary	*bin;
    FILE *fp;

	bin = (t_binary *)arg;
	if ((fp = fopen (bin->filepath, "r")) == NULL) {
		bin->count = 0;
		return (NULL);
	}
	while (!feof(fp))
	{
		if(fgetc(fp) == '1')
			bin->count++;
	}
	fclose(fp);
	return (NULL);
}

