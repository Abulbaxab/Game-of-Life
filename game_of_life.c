#include<stdio.h>
#include<stdlib.h>
#include "windows.h"



int count_nbr(int grid[20][20], int i, int j, int size);

int main(void)
{
    const int size = 20;
    int grid[20][20] = {
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    int neighbour_count[20][20];
    int i, j, steps;

    for (steps = 0; steps < 100; ++steps)
    {
        system("clear");
        for (i = 0; i < size; ++i)
        {
            printf("\n");
            for (j = 0; j < size; ++j)
            {
                if (grid[i][j] == 1)
                    printf("*");
                else
                    printf(".");
                neighbour_count[i][j] = count_nbr(grid, i, j, size);
            }
        }

        for (i = 0; i < size; ++i)
        {
            for (j = 0; j < size; ++j)
            {
                if (grid[i][j] >= 1)
                {
                    if (neighbour_count[i][j] <= 1 || neighbour_count[i][j] >= 4)
                        grid[i][j] = 0;
                }
                else
                    if (neighbour_count[i][j] == 3)
                        grid[i][j] = 1;
            }
        }

        printf("\n\n");
        Sleep(50);
    }

    return 0;
}

int count_nbr(int grid[20][20], int i, int j, int size)
{
    int n_count = 0;
    if (i - 1 >= 0 && j - 1 >= 0)
    {
        if (grid[i - 1][j - 1] >= 1)
            n_count++;
    }

    if (i - 1 >= 0)
    {
        if (grid[i - 1][j] >= 1)
            n_count++;
    }

    if (i - 1 >= 0 && j + 1 < size)
    {
        if (grid[i - 1][j + 1] >= 1)
            n_count++;
    }

    if (j - 1 >= 0)
    {
        if (grid[i][j - 1] >= 1)
            n_count++;
    }

    if (j + 1 < size)
    {
        if (grid[i][j + 1] >= 1)
            n_count++;
    }

    if (i + 1 < size && j - 1 >= 0)
    {
        if (grid[i + 1][j - 1] >= 1)
            n_count++;
    }

    if (i + 1 < size)
    {
        if (grid[i + 1][j] >= 1)
            n_count++;
    }

    if (i + 1 < size && j + 1 < size)
    {
        if (grid[i + 1][j + 1] >= 1)
            n_count++;
    }

    return n_count;
}
