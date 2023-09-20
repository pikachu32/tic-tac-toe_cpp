#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void afisare(char cuv[][10])
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j <= 2; j++)
			cout << cuv[i][j] << "  ";
		cout << endl;
		cout << endl;
	}
}
int verificare(char cuv[][10])
{
	int k = 0;
	//orizontal
	if (strcmp(cuv[1], "xxx") == 0 || strcmp(cuv[2], "xxx") == 0 || strcmp(cuv[3], "xxx") == 0)
		k = 1;
	if (strcmp(cuv[1], "000") == 0 || strcmp(cuv[2], "000") == 0 || strcmp(cuv[3], "000") == 0)
		k = 2;
	//vertical
	if ((cuv[1][0] == 'x') && (cuv[2][0] == 'x') && (cuv[3][0] == 'x'))
		k = 1;
	if ((cuv[1][1] == 'x') && (cuv[2][1] == 'x') && (cuv[3][1] == 'x'))
		k = 1;
	if ((cuv[1][2] == 'x') && (cuv[2][2] == 'x') && (cuv[3][2] == 'x'))
		k = 1;
	if ((cuv[1][0] == '0') && (cuv[2][0] == '0') && (cuv[3][0] == '0'))
		k = 2;
	if ((cuv[1][1] == '0') && (cuv[2][1] == '0') && (cuv[3][1] == '0'))
		k = 2;
	if ((cuv[1][2] == '0') && (cuv[2][2] == '0') && (cuv[3][2] == '0'))
		k = 2;
	//diagonal
	if ((cuv[1][0] == 'x') && (cuv[2][1] == 'x') && (cuv[3][2] == 'x'))
		k = 1;
	if ((cuv[1][0] == '0') && (cuv[2][1] == '0') && (cuv[3][2] == '0'))
		k = 2;
	return k;
}
int main()
{
	int i, j, x, s = 0;
	char cuv[10][10];
	strcpy_s(cuv[1], "123");
	strcpy_s(cuv[2], "456");
	strcpy_s(cuv[3], "789");
	afisare(cuv);
	while (s < 9 && verificare(cuv) == 0)
	{
		cin >> x;
		x = x + 48;
		system("cls");
		for (i = 1; i <= 3; i++)
		{
			for (j = 0; j <= 2; j++)
				if (cuv[i][j] == char(x))
				{
					if (s % 2 == 1) {
						cuv[i][j] = 'x';
						s = s + 1;
					}else
					{
						cuv[i][j] = '0';
						s = s + 1;
					}

				}
		}
		afisare(cuv);
	}
	if (verificare(cuv) == 1)
		cout << "jucatorul 1 castiga";
	if (verificare(cuv) == 2)
		cout << "jucatorul 2 castiga";
	if (verificare(cuv) == 0)
		cout << "remiza";
}
