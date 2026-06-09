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
void drawVerticalLine(int col, int startRow, int endRow)
{
    int i;

    for(i = startRow; i <= endRow; i++)
    {
        canvas[i][col] = '*';
    }
}
void drawRectangle(int row, int col, int width, int height)
{
    drawHorizontalLine(row, col, col + width - 1);

    drawHorizontalLine(row + height - 1,
                       col,
                       col + width - 1);

    drawVerticalLine(col,
                     row,
                     row + height - 1);

    drawVerticalLine(col + width - 1,
                     row,
                     row + height - 1);
}

int main()
{
    initCanvas();
    drawRectangle(5, 10, 15, 6);
    displayCanvas();

    return 0;
}