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


int	main(int ac, char **av)
{
	t_binary		*bin;
	int total;
	int i = 0;
	total = 0;
	bin = malloc(sizeof(t_binary) * (ac - 1));
	if (!bin)
	{
		return (2);
	}
	
	while (++i < ac)
	{
		bin[i - 1].count = 0;
		bin[i - 1].filepath = av[i];
		pthread_create(&bin[i - 1].th_id, NULL, life_cycle, (void *)&bin[i - 1]);
		pthread_join(bin[i - 1].th_id, NULL);
	}

	i = 0;
	while (++i < ac)
	{
		total += bin[i - 1].count;
		pthread_detach(bin[i - 1].th_id);
	}
	printf("Total Number of Ones in All Files: %d\n", total);
	free(bin);
	return (0);
}
