/*#include <stdio.h>
#include <string.h>

int main()
{

    char s[500001];
    fgets(s, 500001, stdin);

    int k = strlen(s);
    int num = 0;
    int lenth = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'o')
            num++;
    }
    if ((num % 2) == 0)
    {
        lenth = k;
    }
    else
    {
        lenth = k - 1;
    }

    printf("%d", lenth);

}
*/