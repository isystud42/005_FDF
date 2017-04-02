
#include <fdf.h>

int		ft_handle_pixel_color(int clrxy, int clrxy1, int progress)
{
    int comp;
    int red;
    int green;
    int blue;

    red = (clrxy >>= 16);
    comp = (clrxy1 >>= 16);
    red = red + (comp - red * progress);
    green = (clrxy >>= 16);
    comp = (clrxy1 >>= 16);
    green = green + (comp - green * progress);
    blue = (clrxy >>= 16);
    comp = (clrxy1 >>= 16);
    blue = blue + (comp - blue * progress);
    red <<= 16;
    green <<= 8;
    printf("clr1 = %d, clr2 = %d, progress = %d, couleur = %d + %d + %d \n",clrxy,clrxy1,progress,red,green,blue);
    return (red + green + blue);
}
