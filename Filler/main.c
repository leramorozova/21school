#include "filler.h"
#include "stdio.h"

void    init_filler(t_filler *f) 
{
    int     ret;
    char    *line;

    ret = 1;
    while (ret > 0)
    {
        f->map_x = 0;
        ret = get_next_line(STDIN_FILENO, &line);
        printf("lalal %s\n", line);
    }
}

int main(void) 
{
    t_filler f;

    init_filler(&f);
    return (0);
}