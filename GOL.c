#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define X 80
#define Y 25

int run(int** a, int** b);
int iter(int** a, int** b);
int check_neighbor(int** arr, int y, int x);
void render(int** a);

int main(int argc, char const *argv[]) {

    int** a = (int**)malloc(Y * sizeof(int*));
    int** b = (int**)malloc(Y * sizeof(int*));
    for (int i = 0; i < Y; i++) {
        a[i] = (int*)malloc(X * sizeof(int));
        b[i] = (int*)malloc(X * sizeof(int));
    }
    for (int i = 0; i < Y; i++)
        for (int j = 0; j < X; j++)
            a[i][j] = 0;
    int num;
    printf("%d", argc);
    if (isatty(0) != 0) {
        int i, j;
        while (!feof(stdin)) {
            scanf("%d%d", &i, &j);
            a[i][j] = 1;
        }
    }
    else {
        srand((unsigned)time(NULL));
        for (int i = 0; i < Y; i++)
            for (int j = 0; j < X; j++)
            {
                num = rand() % 11;
                if (num == 1)
                    a[i][j] = 1;
                else a[i][j] = 0;
            }
    }
    run(a, b);
}

int run(int** a, int** b) {
    int flag = 0;
    double speed = 1;
    render(a);
    while (1) {
        initscr();
        noecho();
        cbreak();        
        // timeout(500);
        int c = 0;
            int c = getch();
            switch (c)
            {
            case '+':
                speed += 0.2;
                break;
            case '-':
                speed -= 0.2;
                break;
            case 'q':
                return 0;
            default:
                break;
        if (flag == 0) {
            iter(a, b);
            render(b);
            flag = 1;
        }
        else {
            iter(b, a);
            render(a);
            flag = 0;
        }
        usleep(speed * 100000);
    }
    return 0;
}

int iter(int** a, int** b) {
    int n;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            n = check_neighbor(a, i, j);
            if (a[i][j] == 0) {
                if (n == 3) {
                    b[i][j] = 1;
                }
                else {
                    b[i][j] = 0;
                }
            }
            else {
                if (n < 2 || n > 3) {
                    b[i][j] = 0;
                }
                else {
                    b[i][j] = 1;
                }
            }
        }
    }
    return 0;
}

int check_neighbor(int** a, int y, int x) {
    int neighbor = 0;
    int m, n;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            m = y + i;
            n = x + j;
            if (m < 0) {
                m = Y + m;
            }
            else if (m > Y - 1) {
                m = m - Y;
            }
            if (n < 0) {
                n = X + n;
            }
            else if (n > X - 1) {
                n = n - X;
            }
            if (a[m][n] == 1) {
                neighbor++;
            }
        }
    }
    return neighbor;
}

void render(int** a) {
    system("clear");
    for (int i = 0; i < Y; i++) {
        printf("\n");
        for (int j = 0; j < X; j++) {
            if (a[i][j] == 0) {
                printf(".");
            }
            else {
                printf("#");
            }

        }
    }
    printf("\n");
}
