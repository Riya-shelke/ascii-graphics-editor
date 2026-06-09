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
void drawTriangle(int row, int col, int height)
{
    int i;

    /* Left side */
    for(i = 0; i < height; i++)
    {
        canvas[row + i][col - i] = '*';
    }

    /* Right side */
    for(i = 0; i < height; i++)
    {
        canvas[row + i][col + i] = '*';
    }

    /* Base */
    drawHorizontalLine(row + height - 1,
                       col - (height - 1),
                       col + (height - 1));
}
void drawCircle(int centerRow, int centerCol, int radius)
{
    int x, y;

    for(x = -radius; x <= radius; x++)
    {
        for(y = -radius; y <= radius; y++)
        {
            if(x*x + y*y <= radius*radius)
            {
                canvas[centerRow + x][centerCol + y] = '*';
            }
        }
    }
}

 int main()
{
    int choice;

    initCanvas();

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Horizontal Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Canvas\n");
        printf("6. Clear Canvas\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                drawHorizontalLine(5, 10, 20);
                printf("Line Added\n");
                break;

            case 2:
                drawRectangle(2, 2, 12, 5);
                printf("Rectangle Added\n");
                break;

            case 3:
                drawTriangle(15, 20, 5);
                printf("Triangle Added\n");
                break;

            case 4:
                drawCircle(10, 20, 3);
                printf("Circle Added\n");
                break;

            case 5:
                displayCanvas();
                break;

            case 6:
                initCanvas();
                printf("Canvas Cleared\n");
                break;

            case 7:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}