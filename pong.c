#include <stdio.h>

void render_play_field(int x_min, int x_max, int y_min, int y_max, int r1x1, int r1y1, int r1y2, int r1y3, int r2x1, int r2y1, int r2y2, int r2y3, int bx, int by, int coord_net_1, int coord_net_2);
int get_is_racket_coords(int x, int y, int x1, int y1, int y2, int y3);
void print_current_player(int player);
// void clear_display(void)
// {
//     printf("\033[2J");
//     printf("\033[0;0f");
// }

int main()
{
    int x_min = 1;
    int x_max = 80;
    int y_min = 1;
    int y_max = 25;
    int coord_net_1 = 39;
    int coord_net_2 = 40;
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
    int player_1 = 0;
    int player_2 = 1;
    int current_player = player_1;
    int score_player_1 = 0;
    int score_player_2 = 0;

    render_play_field(x_min, x_max, y_min, y_max, racket_p1_x, racket_p1_y_1, racket_p1_y_2, racket_p1_y_3, racket_p2_x, racket_p2_y_1, racket_p2_y_2, racket_p2_y_3, ball_x, ball_y, coord_net_1, coord_net_2);
    print_current_player(current_player);

    while (score_player_1 < 21 || score_player_2 < 21)
    {
        char action = getchar();

        if (action == '\n' || action == '\t')
        {
            continue;
        }

        if (!(action == 'A' || action == 'a' || action == 'Z' || action == 'z' || action == 'K' || action == 'k' || action == 'M' || action == 'm' || action == ' '))
        {
            continue;
        }

        if (current_player == player_1)
        {
            if (action == 'A' || action == 'a')
            {
                if (racket_p1_y_1 > 1)
                {
                    racket_p1_y_1 -= 1;
                    racket_p1_y_2 -= 1;
                    racket_p1_y_3 -= 1;
                }
            }

            if (action == 'Z' || action == 'z')
            {
                if (racket_p1_y_3 < 25)
                {
                    racket_p1_y_1 += 1;
                    racket_p1_y_2 += 1;
                    racket_p1_y_3 += 1;
                }
            }

            if (action == ' ')
            {
            }
        }
        else
        {
            if (action == 'K' || action == 'k')
            {
                if (racket_p2_y_1 > 1)
                {
                    racket_p2_y_1 -= 1;
                    racket_p2_y_2 -= 1;
                    racket_p2_y_3 -= 1;
                }
            }

            if (action == 'M' || action == 'm')
            {
                if (racket_p2_y_3 < 25)
                {
                    racket_p2_y_1 += 1;
                    racket_p2_y_2 += 1;
                    racket_p2_y_3 += 1;
                }
            }

            if (action == ' ')
            {
            }
        }

        // printf("%c\n", action);

        score_player_1 += 1;
        if (score_player_1 % 2 == 0)
        {
            current_player = player_1;
        }
        else
        {
            current_player = player_2;
        }

        render_play_field(x_min, x_max, y_min, y_max, racket_p1_x, racket_p1_y_1, racket_p1_y_2, racket_p1_y_3, racket_p2_x, racket_p2_y_1, racket_p2_y_2, racket_p2_y_3, ball_x, ball_y, coord_net_1, coord_net_2);
        print_current_player(current_player);
    }
}

void render_play_field(int x_min, int x_max, int y_min, int y_max, int r1x1, int r1y1, int r1y2, int r1y3, int r2x1, int r2y1, int r2y2, int r2y3, int bx, int by, int coord_net_1, int coord_net_2)
{
    for (int i = y_min; i <= y_max; i++)
    {
        for (int j = x_min; j <= x_max; j++)
        {
            if (get_is_racket_coords(j, i, r1x1, r1y1, r1y2, r1y3) == 1 || get_is_racket_coords(j, i, r2x1, r2y1, r2y2, r2y3) == 1)
            {
                printf("|");

                continue;
            }
            if (j == bx && i == by)
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

int get_is_racket_coords(int x, int y, int x1, int y1, int y2, int y3)
{
    if (x == x1 && (y == y1 || y == y2 || y == y3))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_current_player(int player)
{
    if (player == 0)
    {
        printf("Player: 1\n");
    }
    else
    {
        printf("Player: 2\n");
    }
}
