﻿#ifndef SCANF_H
#define SCANF_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdarg.h>  //提供宏va_list、va_start、va_arg、va_end 
#include <ctype.h>   //提供isprint原型

/*自定义的数据录入函数，用于从文件fp中读取格式化的输入。
与fscanf不同之处在于此函数只会读取西文字符，对于中文字符，则会跳过。 
*/

int Scanf(FILE *fp, char * format, ...)
{
	int *i;
	char *ch, *s;
	float *f;
	int count, k, len, n;

	int temp;
	va_list ap;

	len = strlen(format);

	va_start(ap, format);

	for (count = 0, k = 2; k <= len; k += 2)
	{
		while ((temp = getc(fp)) != EOF) //跳过所有非西文字符 
		{
			if ((temp > 0 && temp <= 127))
			{
				ungetc(temp, fp);  //遇到首个西文字符，将此西文字符放入输入流 
				break;
			}
		}

		if (temp == EOF)
			break;

		if (format[k - 1] == 'c')  //读取字符   
		{
			ch = va_arg(ap, char*);

			if (temp != EOF)
				count += fscanf(fp, "%c", ch);
		}

		if (format[k - 1] == 'd')  //读取整型
		{
			i = va_arg(ap, int *);

			while ((temp = getc(fp)) != EOF)
			{
				if ((temp >= '0'&&temp <= '9') || temp == '-' || temp == '+')
				{
					ungetc(temp, fp);
					break;
				}
			}

			if (temp != EOF)
				count += fscanf(fp, "%d", i);
		}

		if (format[k - 1] = 'f')  //读取浮点型
		{
			f = va_arg(ap, float*);
			while ((temp = getc(fp)) != EOF)
			{
				if ((temp >= '0'&&temp <= '9') || temp == '-' || temp == '+' || temp == '.')
				{
					ungetc(temp, fp);
					break;
				}
			}

			if (temp != EOF)
				count += fscanf(fp, "%f", f);
		}

		if (format[k - 1] == 's')  //读取字符串
		{
			s = va_arg(ap, char*);
			while ((temp = getc(fp)) != EOF && (!isprint(temp) || temp == ' '));

			n = 0;
			if (!feof(fp))
			{
				ungetc(temp, fp);
				while ((temp = getc(fp)) != EOF)
				{
					if (isprint(temp) && temp != ' ')
						s[n++] = temp;
					else
						break;
				}
				ungetc(temp, fp);
			}

			s[n] = '\0';
			count++;
		}
	}
	va_end(ap);
	return count;
}

#endif // !SCANF_C

