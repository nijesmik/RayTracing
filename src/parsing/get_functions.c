#include "parsing.h"

double	ft_atof(char *str)
{
	double	res;
	double	decimal;
	int		sign;
	double	divisor;

	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	res = 0.0;
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		divisor = 10.0;
		decimal = 0.0;
		while (ft_isdigit(*str))
		{
			decimal += (*str++ - '0') / divisor;
			divisor *= 10;
		}
	}
	return (res + decimal) * sign;
}

t_color get_rgb(const char *rgb_string)
{
	char	*token;
	char	*tmp;
    int     r;
    int     g;
    int     b;

	tmp = ft_strdup(rgb_string);
	token = ft_strtok(tmp, ",");
	r = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	g = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	b = ft_atoi(token);
	free(tmp);
    /* rgb valid check fucntion */
	return (new_color(r, g, b));
}

t_vector	get_vector(const char *vec_string)
{
	char	*token;
	char	*tmp;
    double  x;
    double  y;
    double  z;

	tmp = ft_strdup(vec_string);
	token = ft_strtok(tmp, ",");
	x = ft_atof(token);
	token = ft_strtok(NULL, ",");
	y = ft_atof(token);
	token = ft_strtok(NULL, ",");
    z = ft_atof(token);
	free(tmp);
	return (new_vector(x, y, z));
}