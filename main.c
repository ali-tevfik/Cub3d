#include <stdio.h>
#include "cub3d.h"

t_map	find_info_maps(char **argv)
{
	char	*read_data;
	int		step;
	int		fd;
	t_map	map_info;

	fd = open(argv[1], O_RDONLY);
	step = 0;
	map_info.line = 0;
	if (fd == -1)
		exit(0);
	while (get_next_line(fd, &read_data) > 0)
	{
		if (!read_data)
			exit(0);
		map_info.len = ft_strlen(read_data);
		free (read_data);
		map_info.line++;
	}
	free(read_data);
	return (map_info);
}

void	clean_old_data(char **new_data)
{
	int	i;

	i = 0;
	while (new_data[i])
	{
		free(new_data[i]);
		i++;
	}
	if (new_data)
		free(new_data);
	exit(0);
}

int match_str(char *txt, char *find)
{
    if (txt[0] == find[0])
    {
        if (txt[1] == find[1])
            return (TRUE);
    }
    return (FALSE);
}

char	**load_data(char **argv, t_map map_info)
{
	char	**new_data;
	char	*read_data;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	new_data = (char **)malloc(sizeof(new_data) * (map_info.line + 2));
	if (!new_data)
		exit(0);
	i = 0;
	while (get_next_line(fd, &read_data) > 0)
	{
		if (!read_data)
			clean_old_data(new_data);
        if (!match_str(read_data, "SO") || !match_str(read_data, "NO") || !match_str(read_data, "WE") || !match_str(read_data, "EA") || !ft_strchr(read_data, 'F') || !ft_strchr(read_data, 'C'))
		{
		    new_data[i] = ft_strdup(read_data);
			i++;
		}
		if (!new_data)
			clean_old_data(new_data);
		free(read_data);
	}
	free(read_data);
	new_data[i] = NULL;
	return (new_data);
}



int main(int argc, char* argv[])
{
    t_map maps;

     (void ) argc;
    maps = find_info_maps(argv);
    maps.maps = load_data(argv, maps);
	for (int i = 0; maps.maps[i] ; i++)
	    printf("line %s \n", maps.maps[i]);
}