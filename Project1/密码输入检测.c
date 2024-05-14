#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char stror[5000];

    gets(stror);

    int length = strlen(stror);

    char strnew[5000] = {0};

    int stack_size = 0;

    int top = 0;
    int low = 0;
    int num = 0;
    int el = 0;


    for (int i = 0; i < length; i++)
    {
        int val;
        char key;

        //退出入栽
        if (stror[i] == '<')
        {
            if (stack_size > 0)//避免首位出现
            {

                //出宅操作，向前移动一位
                stack_size--;
                //同时删除计数
                key = strnew[stack_size];
                val = -1;
            }
            else { continue; }
        }
        //入宅
        else
        {
            strnew[stack_size] = stror[i];
            key = stror[i];
            stack_size++;
            val = 1;
        }

        //判断密码安全要求

        //大写判断
        if (key >= 'A' && key <= 'Z')
        {
            top += val;
        }
        //小写判断
        else if (key >= 'a' && key <= 'z')
        {
            low += val;
        }
        else if (key >= '0' && key <= '9')
        {
            num += val;
        }
        else {
            el += val;
        }

    }

 
    int m = strlen(strnew);
    strnew[stack_size] = '\0';
    char s[8];
    if (m >= 8 && top > 0 && low > 0 && num > 0 && el > 0)
    {
        strcat(strnew, ",true");
    }
    else {
        strcat(strnew, ",false");
    }

    puts(strnew);

}