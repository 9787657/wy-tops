/*#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, k;
    scanf("%d %d", &n, &m);

    //��������
    k = (int)(ceil((n * 1.0) / m));

    //�С���
    int mar[m][k];

    //����
    int x = 0, y = 0;
    //��ʼ��mar
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
            mar[i][j] = 0;
    }


    //��n�����������������
    int step = 1;

    while (step <= n)
    {
        //��������
        while (mar[x][y] == 0 && y < k && step <= n)
        {
            mar[x][y++] = step++;
        }
        //
        y--;
        //
        x++;

        while (mar[x][y] == 0 && x < m && step <= n)
        {
            mar[x++][y] = step++;
        }
        x--;
        y--;
        while (mar[x][y] == 0 && y >= 0 && step <= n)
        {
            mar[x][y--] = step++;
        }
        y++;
        x--;
        while (mar[x][y] == 0 && x >= 0 && step <= n)
        {
            mar[x--][y] = step++;
        }
        y++;
        x++;
    }
    int i, j;
    //��ӡ
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (mar[i][j] == 0)
                printf("*");
            else
                printf("%d", mar[i][j]);

            if (j < k - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
*/