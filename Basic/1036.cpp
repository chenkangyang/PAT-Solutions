#include <cstdio>

int main()
{
    int n, col, row;
    char c;
    scanf("%d %c", &n, &c);
    col = n;
    row = n % 2 ? col/2 + 1 : col / 2;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || i == row - 1)
            {
                printf("%c", c);
            }
            else
            {
                if (j != 0 && j != col - 1)
                    printf(" ");
                else
                {
                    printf("%c", c);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
