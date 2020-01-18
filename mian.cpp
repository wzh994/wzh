//#include<algorithm>
//#include<fstream>
//#include<iostream>
//#include<cstdlib>
//#include<string>
#include"sudoku.h"
#include<time.h>
using namespace std;


//³õÊ¼»¯¾Å¹¬¸ñ
Sudoku::Sudoku()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11;j++)
		{
			range[i][j] = 0;
		}
	}
}

int main(int argc,char*argv[])
{
	//int argc;
	//char *argv[3];
	//cin >> argc;
	//scanf_s("%s %s %s", &*argv[0], &*argv[1], &*argv[2]);
	int n = 1000000;
	Sudoku w;
	Judge j;
	char q;
	q = j.judge(argc, argv);
	if (q == 'c')
	{
		int len = strlen(argv[2]);
		int num = 0;
		int flag = 0;
		for (int i = 0; i < len; i++)
		{
			argv[2][i] >= '0'&&argv[2][i] <= '9';
			num = num * 10 + (argv[2][i] - '0');
		}
		w.createSudoku(num);
	}
	else if (q == 's')
	{
		string path;
		path = argv[2];
		w.solveSudoku(path);
	}
	else if (q == 'e')
	{
		cout<<"ERROR1"<<endl;
	}
	else if (q == 'q')
	{
		cout << "123" << endl;
	}
	
}