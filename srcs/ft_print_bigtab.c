
#include <fdf.h>

void    ft_print_bigtab_vanilla(t_fdf_env *env)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < env->line_nb)
	{
		while (++j < env->most_values_into_one_line)
				PXL(MLX, WIN, BIG_TAB[i][j][0], BIG_TAB[i][j][1], 0xFFFFFF);
		j = -1;
	}
}

void    ft_print_bigtab(t_fdf_env *env)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < env->line_nb)
	{
		while (++j < env->most_values_into_one_line)
		{
			if (env->colors[i][j] != 0)
				PXL(MLX, WIN, BIG_TAB[i][j][0], BIG_TAB[i][j][1], env->colors[i][j]);
			else
				PXL(MLX, WIN, BIG_TAB[i][j][0], BIG_TAB[i][j][1], 0xFFFFFF);
		}
		j = -1;
	}
}