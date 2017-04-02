
#include <fdf.h>

int     ***ft_malloc_triple_int_tab(int tabsize_1, int tabsize_2)
{
    int i;
    int j;
    int ***bigtab;

    i = -1;
    j = -1;
    bigtab = (int***)malloc(sizeof(int**) * tabsize_1);
    while (++i < tabsize_1)
        bigtab[i] = (int**)malloc(sizeof(int*) * tabsize_2);
    return(bigtab);
}