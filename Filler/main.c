#include "filler.h"
#include <stdio.h>

void    init_filler(t_filler *f) 
{
    int     ret;
    char    *line;
    int     len;

    ret = 1;
    while (ret > 0)
    {
        f->map_x = 0;
        ret = get_next_line(STDIN_FILENO, &line);
        len = ft_strlen(line);
        write(2, line, len);
        write(2, "\n", 1);
    }
}

int main(void) 
{
    t_filler f;

    init_filler(&f);
    return (0);
}