#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
\func void doxygen(FILE *F)
*/
void doxygen(FILE *F)
{
	bool func = true;
	bool end = false;
	bool comment_begun = false;
	int  func_num = 0;
	char sym = '\0';
	char sym1 = '\0';
	char sym2 = '\0';
	char c[5] = { 'f', 'u', 'n', 'c', '\0' }; // c == '\func'
	char ch = '\0';
	char ch1 = '\0';
	rewind(F);
	while (!feof(F))
	{
		sym = fgetc(F);
		switch (sym)
		{
		case '/':
			sym1 = fgetc(F);
			sym2 = fgetc(F);
			if ((sym1 == '*') && (sym2 == '*')) //если видим /**
			{
				while (fgetc(F) != '\\');
				func = true;
				for (int i = 0; i < 4; i++) //проверка, будет ли сейчас написано описание функции
				{
					if (fgetc(F) != c[i])
					{
						func = false;
					}
				}
			}
			while (func == true) //если было встречено /**  \func 
			{
				func_num++;
				printf_s("\n%d)", func_num); //выводим номер описываемой функции
				end = false;
				while (end == false)
				{
					ch = fgetc(F);
					if (ch == '*')
					{
						ch1 = fgetc(F);
						if (ch1 == '/') //если конец комментария
						{
							end = true;
							func = false;
						}
						else
						{
							printf_s("%c%c", ch, ch1);
							end = false;
						}
					}
					else if (ch == '\n')
					{
						end = true;
						func = false;
					}
					else
					{
						printf_s("%c", ch);
						end = false;
					}
				}
				break;
			}
			break;
		default:
			break;
		}//конец switch
	}
	return;
}

/** \func int main(int argc, char *argv[]) */
int main(int argc, char *argv[])
{
	FILE *pF;
	char ch = '\0';
	pF = fopen(argv[1], "r");

	doxygen(pF);
	/**
	\func lvjkl ergh eriii
	*/
	return 0;
}