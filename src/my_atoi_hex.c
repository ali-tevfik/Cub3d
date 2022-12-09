/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:16:12 by ydemura           #+#    #+#             */
/*   Updated: 2022/12/09 12:45:00 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	is_valid_unsigned_int_part(char c)
{
	if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	str_has_unsigned_int_part(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 1 || str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

void	fill_table(int *table, int i)
{
	while (i < 256)
	{
		table[i] = -1;
		i++;
	}
	i = '0';
	while (i <= '9')
	{
		table[i] = i - '0';
		i++;
	}
	i = 'a';
	while (i <= 'f')
	{
		table[i] = i - 'a' + 10;
		i++;
	}
	i = 'A';
	while (i <= 'F')
	{
		table[i] = i - 'A' + 10;
		i++;
	}
}

unsigned	int	my_atoi_hex(char *str)
{
	int				i;
	unsigned int	res;
	int				table[256];

	i = 0;
	fill_table(table, i);
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 14))
		i++;
	res = 0;
	i += 2;
	while (str[i] != '\0')
	{
		if (table[(int)str[i]] == -1)
			return (-1);
		res = (res << 4) + (table[(int)str[i]]);
		i++;
	}
	return (res);
}
