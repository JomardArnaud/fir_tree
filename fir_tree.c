#include <stdio.h>
#include <errno.h>   
#include <limits.h>  
#include <stdlib.h> 
#include <unistd.h> 

//to do 

void draw_char(char c, int len)
{
    for (int i = 0; i < len; i++) {
        write(1, &c, 1);
    }
}

//get the lenght of the first half of the last tree's line 
int    get_max_lenght(int size) 
{
    int nb_star_add = 3;
    int max_half_size = 0;
    while (size > 0) {
        for (int i = 0; i < 2; i++) {
            max_half_size += nb_star_add;
            size--;
            if (size < 1) {
                return max_half_size;
            }
        }
        nb_star_add++;
    }
    return max_half_size;
}

void    print_thorns(int size, int max_half_size)
{
    int nb_star_line = 0;
    int nb_line_per_block = 4;
    int nb_block = 1;
    // the number of star which be subtract on the begin of next block
    int star_to_sub = 2;

    while (size > 0) {
        for (int line = 0; line < nb_line_per_block; line++) {
            // calcul for knowing the number of space needed before and after the stars
            const int nb_space = (max_half_size - nb_star_line);
            draw_char(' ', nb_space);
            draw_char('*', 1 + (nb_star_line * 2));
            draw_char(' ', nb_space);
            draw_char('\n', 1);
            nb_star_line += 1;
        }
        nb_line_per_block++;
        nb_star_line -= star_to_sub;
        star_to_sub += (nb_block % 2 == 0);
        nb_block++;
        size--;
    }
}
void    print_trunc(int size, int max_half_size)
{
    const int size_trunc = (size / 2) * 2 + 1;
    const int nb_space = max_half_size - size_trunc / 2;
    while (size-- > 0) {
        draw_char(' ', nb_space);
        draw_char('|', size_trunc);
        draw_char(' ', nb_space);
        draw_char('\n', 1);
    }
}

int     main(int argc, char **argv) 
{
    char *p;
    int num;

    errno = 0;
    if (argc == 1)
        return 0;
    long conv = strtol(argv[1], &p, 10);

    // Check for errors: e.g., the string does not represent an integer
    // or the integer is larger than int
    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
        return (errno != 0 ? errno : -1);
    } else {
        // No error
        num = conv;
        if (num <= 0) 
            return 0;
        const int max_half_size = get_max_lenght(num);    
        print_thorns(num, max_half_size);
        print_trunc(num, max_half_size);
        
    }
    
    return 0;
}