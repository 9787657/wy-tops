#include <stdio.h>
#include <string.h>

int main()
{
    char num[20001];

    scanf("%s", num);

    int k = strlen(num);
    int human = 0;
    int i = 0;

    while (i < k)
    {
        if (num[i] == '0')
        {
            if (i == 0 && num[1] != '1')
            {
                human += 1;
                num[0] = '1';
            }
            else if (i == (k - 1) && num[k - 2] != '1')
            {
                human += 1;
                num[k - 1] = '1';
            }
            else if (num[i + 1] == '0' && num[i - 1] == '0')
            {
                human += 1;
                num[i] = '1';
            }
        }
        i++;
    }
    printf("%d", human);

    return 0;


}