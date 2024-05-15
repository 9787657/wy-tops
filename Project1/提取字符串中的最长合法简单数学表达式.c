#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//�ж��ַ����ĺϷ���
int is_vaild(char str[],int start,int end)
{
	if (start == end)					return 0;//�ַ���ֻ��һ��ֵ
	else if (!isdigit(str[start]))		return 0;//���ַ������ִ���
	for (int i = start+1; i <end; i++)
	{
		//�Ƿ�δҪ���ַ�
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*')
			return 0;
		//�Ƿ�δ���������
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
	//���忪ͷ����βָ��
	int start = 0;
	int end = 0;
	int temp_len = 0;
	int max_len = 0;
	char* strnew=NULL;

	//�����ַ���
	while (end < k)
	{
		//�ж��Ƿ�������ʽ��������,
		if (isdigit(str[end]) || str[end] == '+' || str[end] == '-' || str[end] == '*')
		{
			// ������չ�����԰�����ǰ�ַ�
			end++;
		}
		else
		{
			// �����㣬�жϵ�ǰ�����Ƿ�Ϸ�
			if (is_vaild(str, start, end))
			{
				//�Ϸ����ж��Ƿ�Ϊ��ַ�
				temp_len= end - start;
				//�ж�temp_len��max_len�Ǹ���
				if (temp_len > max_len)
				{
					max_len = temp_len;
					strnew = str + start;
				}
			}
			
				//��ʼ�ַ��ƶ�һλ��β�ַ������ַ�
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

	//��������
	int num=find(str);
	printf("%d",num);
	return 0;
}