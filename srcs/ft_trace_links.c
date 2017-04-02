#include <fdf.h>

int		trace_l_to_r(t_fdf_env *env, int *xytab, int clrxy, int clrxY1)
{
	int save;

	if (X1 == X2 || Y1 == Y2)
		return (0);
	save = X1;
	while (save++ < X2)
		PXL(MLX,WIN,save,Y1 + ((Y2 - Y1) * (save - X1)) / (X2 - X1), ft_handle_pixel_color(clrxy,clrxY1,100 * (X2 - save)/(X2 - X1)));
	save = X2;
	while (save++ < X1)
		PXL(MLX,WIN,save,Y1 + ((Y2 - Y1) * (save - X1)) / (X2 - X1), ft_handle_pixel_color(clrxy,clrxY1,100 * (X1 - save)/(X2 - X1)));
	save = Y2;
	while (save++ < Y1)
		PXL(MLX, WIN, X1 + ((X2 - X1) *	(save - Y1)) / (Y2 - Y1), save, 0xFFFFFF);
	save = Y2;
	while (save++ < Y1)
		PXL(MLX, WIN, X1 + ((X2 - X1) *	(save - Y1)) / (Y2 - Y1), save, 0xFFFFFF);
	return (0);
}

static	int		trace_r_to_l2(t_fdf_env *env, int *xytab/*, int clrxy, int clrxY1*/)
{
	int save;


	save = X2;
	while (save++ < X1)
		PXL(MLX,WIN,save,Y1 + ((Y2 - Y1) * (save - X1)) / (X2 - X1), 0xFFFFFF);
	save = Y2;
	while (save++ < Y1)
		PXL(MLX, WIN, X1 + ((X2 - X1) *	(save - Y1)) / (Y2 - Y1), save, 0xFFFFFF);
	save = X1;
	while (save++ < X2)
		PXL(MLX,WIN,save,Y1 + ((Y2 - Y1) * (save - X1)) / (X2 - X1), 0xFFFFFF);
	save = Y1;
	while (save++ < Y2)
		PXL(MLX, WIN, X1 + ((X2 - X1) *	(save - Y1)) / (Y2 - Y1), save, 0xFFFFFF);
	return (0);	
}

int		trace_r_to_l(t_fdf_env *env, int *xytab/*, int clrxy, int clrxY1*/)
{
	int save;

	save = Y1;
	while (X1 == X2 && Y1++ != Y2)
		PXL(MLX,WIN,X1,Y1,0xFFFFFF);
	Y1 = save;
	save = X1;
	while (X1++ != X2 && (Y1) == Y2)
		PXL(MLX,WIN,X1,Y1,0xFFFFFF);
	X1 = save;
	trace_r_to_l2(env,xytab/*, CLR[I + 1][J], CLR[I][J]*/);
	return (0);
}

void	ft_trace_links(t_fdf_env *env)
{
	I = -1;
	J = -1;
	while (++I < env->line_nb)
	{
		while (++J < SIZE)
        {
        	if ((J + 1) < SIZE || ((J + 1) < SIZE && (I + 1) < env->line_nb))
			{
				trace_l_to_r(env, BIG_TAB[I][J + 1], CLR[I][J], CLR[I][J + 1]);
				trace_r_to_l(env, BIG_TAB[I][J + 1]/*, CLR[I][J], CLR[I][J + 1]*/);
			}
			if ((I + 1) < env->line_nb || ((I + 1) < env->line_nb && (J + 1) < SIZE))
			{
				trace_r_to_l(env, BIG_TAB[I + 1][J]/*, CLR[I + 1][J], CLR[I][J]*/);
				trace_l_to_r(env, BIG_TAB[I + 1][J], CLR[I + 1][J], CLR[I][J]);
			}
        }
        J = -1;
	}
}
