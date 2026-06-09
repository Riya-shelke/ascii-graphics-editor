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
void clearArea(int row, int col, int width, int height)
{
    int i, j;

    for(i = row; i < row + height; i++)
    {
        for(j = col; j < col + width; j++)
        {
            canvas[i][j] = '_';
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
        printf("7. Clear Area\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int row, startCol, endCol;

                printf("Enter Row: ");
                scanf("%d", &row);

                printf("Enter Start Column: ");
                scanf("%d", &startCol);

                printf("Enter End Column: ");
                scanf("%d", &endCol);

                drawHorizontalLine(row, startCol, endCol);

                printf("Line Added\n");
                break;
            }

            case 2:
            {
                int row, col, width, height;

                printf("Enter Row: ");
                scanf("%d", &row);

                printf("Enter Column: ");
                scanf("%d", &col);

                printf("Enter Width: ");
                scanf("%d", &width);

                printf("Enter Height: ");
                scanf("%d", &height);

                drawRectangle(row, col, width, height);

                printf("Rectangle Added\n");
                break;
            }

            case 3:
            {
                int row, col, height;

                printf("Enter Top Row: ");
                scanf("%d", &row);

                printf("Enter Center Column: ");
                scanf("%d", &col);

                printf("Enter Height: ");
                scanf("%d", &height);

                drawTriangle(row, col, height);

                printf("Triangle Added\n");
                break;
            }

            case 4:
            {
                int row, col, radius;

                printf("Enter Center Row: ");
                scanf("%d", &row);

                printf("Enter Center Column: ");
                scanf("%d", &col);

                printf("Enter Radius: ");
                scanf("%d", &radius);

                drawCircle(row, col, radius);

                printf("Circle Added\n");
                break;
            }

            case 5:
                displayCanvas();
                break;

            case 6:
                initCanvas();
                printf("Canvas Cleared\n");
                break;

            case 7:
            {
                int row, col, width, height;

                printf("Enter Row: ");
                scanf("%d", &row);

                printf("Enter Column: ");
                scanf("%d", &col);

                printf("Enter Width: ");
                scanf("%d", &width);

                printf("Enter Height: ");
                scanf("%d", &height);

                clearArea(row, col, width, height);

                printf("Area Cleared\n");
                break;
            }

            case 8:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}