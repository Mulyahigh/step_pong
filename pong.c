#include <stdio.h>

// константы
#define x_min 1
#define x_max 80
#define y_min 1
#define y_max 25
#define coord_net_1 39
#define coord_net_2 40

// глобальные переменные
int racket_p1_x = 1;
int racket_p1_y_1 = 11;
int racket_p1_y_2 = 12;
int racket_p1_y_3 = 13;
int racket_p2_x = 80;
int racket_p2_y_1 = 11;
int racket_p2_y_2 = 12;
int racket_p2_y_3 = 13;
int ball_x = 24;
int ball_y = 12;

void render_play_field(void);
int get_is_racket_p1_coords(int x, int y);
int get_is_racket_p2_coords(int x, int y);

int main()
{
    render_play_field();
}

void render_play_field()
{
    for (int i = y_min; i <= y_max; i++)
    {
        for (int j = x_min; j <= x_max; j++)
        {
            if (get_is_racket_p1_coords(j, i) == 1 || get_is_racket_p2_coords(j, i) == 1)
            {
                printf("|");

                continue;
            }
            if (j == ball_x && i == ball_y)
            {
                printf("*");

                continue;
            }
            if (j == coord_net_1 || j == coord_net_2)
            {

                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int get_is_racket_p1_coords(int x, int y)
{
    if (x == racket_p1_x && (y == racket_p1_y_1 || y == racket_p1_y_2 || y == racket_p1_y_3))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_is_racket_p2_coords(int x, int y)
{
    if (x == racket_p2_x && (y == racket_p2_y_1 || y == racket_p2_y_2 || y == racket_p2_y_3))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
