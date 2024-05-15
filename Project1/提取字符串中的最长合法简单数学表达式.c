#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//判断字符串的合法性
int is_vaild(char str[],int start,int end)
{
	if (start == end)					return 0;//字符串只有一个值
	else if (!isdigit(str[start]))		return 0;//首字符非数字错误
	for (int i = start+1; i <end; i++)
	{
		//是否未要求字符
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*')
			return 0;
		//是否未连续运算符
		else if (!isdigit(str[i]) && !isdigit(str[i -1]))
			return 0;
	}

	return 1;
}

int callength(char* str, int length)
{
	char ch;
	int result = 0;
	int num = 0;
	char op = '+';
	for (int i = 0; i <= length; i++)
	{
		ch = *(str + i);
		if (isdigit(ch))
		{
			num = num * 10 + (ch - '0');
		}
		else
		{
			switch(op){
				case '+':
					result += num;
					break;
				case '-':
					result -= num;
					break;
				case '*':
					result *= num;
					break;
			}
			op = ch;
			num = 0;
		}
	}
	return result;
}

int find(const char *str)
{
	int k = strlen(str);
	//定义开头、结尾指针
	int start = 0;
	int end = 0;
	int temp_len = 0;
	int max_len = 0;
	char* strnew=NULL;

	//遍历字符串
	while (end < k)
	{
		//判断是否满足表达式定义条件,
		if (isdigit(str[end]) || str[end] == '+' || str[end] == '-' || str[end] == '*')
		{
			// 满足扩展窗口以包含当前字符
			end++;
		}
		else
		{
			// 不满足，判断当前窗口是否合法
			if (is_vaild(str, start, end))
			{
				//合法，判断是否为最长字符
				temp_len= end - start;
				//判断temp_len与max_len那个大
				if (temp_len > max_len)
				{
					max_len = temp_len;
					strnew = str + start;
				}
			}
			
				//起始字符移动一位，尾字符到首字符
				start++;
				end = start;
		}
	}
	if (strnew == NULL) return 0;

	return  callength(strnew, max_len);
}

int main()
{
	char str[5000];
	gets(str);

	//求解最长数组
	int num=find(str);
	printf("%d",num);
	return 0;
}