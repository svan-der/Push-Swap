#include "../includes/printf/ft_printf.h"
#include <stdio.h>

int     main(void)
{
    int number = 450;

    ft_printf("this is going to be fixed: %i\n", number);
    printf("this is going to be fixed: %i\n", number);
    return (0);
}