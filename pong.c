#include <stdio.h>

int ball_x = 40;
int ball_y = 13;

int main()
{
    int x_max = 80;
    int y_max = 25;
    for (int i = 0; i < 82; i++)
    {
        printf("_");
    }
    printf("\n");

    for (int y = y_max; y >= 1; y--)
    {
        printf("|");
        for (int x = 1; x <= x_max; x++)
        {
            if (ball_x == x && ball_y == y)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("|\n");
    }
    for (int i = 0; i < 82; i++)
    {
        printf("_");
    }
}
