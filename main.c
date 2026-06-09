#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawHorizontalLine(int row, int startCol, int endCol)
{
    int i;

    for(i = startCol; i <= endCol; i++)
    {
        canvas[row][i] = '*';
    }
}

int main()
{
    initCanvas();
    drawHorizontalLine(5, 10, 20);
    displayCanvas();

    return 0;
}