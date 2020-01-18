#include"sudoku.h"
#include<fstream>

void Sudoku::DFS(int count)
{
	//fprintf(file2, "%d\n",count);
	if (count == 81)
	{
		//fprintf(file2, "456");
		for (int i = 0; i < 9; ++i)
		{
			//problemfile << range[i][0] - '0'<<" "<<range[i][1] - '0' <<" "<< range[i][2] - '0' << " " << range[i][3] - '0' << " " << range[i][4] - '0' << " " << range[i][5] - '0' << " " << range[i][6] - '0' << " " << range[i][7] - '0' << " " << range[i][8]-'0'<<"\n";
			fprintf(file2,"%c %c %c %c %c %c %c %c %c\n", range[i][0], range[i][1], range[i][2], range[i][3], range[i][4], range[i][5], range[i][6], range[i][7], range[i][8]);
		}
		//problemfile << "\n";
		fputs("\n",file2);
		return;
	}
	int row = count / 9;   //position对应的x坐标
	int col = count % 9;  //position对应的y坐标
	if (range[row][col] == '0')
	{
		for (int i = 1; i <= 9; i++)//尝试对这一点进行1~9的赋值
		{
			range[row][col] = i + '0';

			int flag = 1;
			int j;
			for (j = 0; j < 9; j++)     //同一行
			{
				if (range[row][j] == range[row][col] && j != col)
					flag = 0;
			}
			for (j = 0; j < 9; j++)     //同一列
			{
				if (range[j][col] == range[row][col] && j != row)
					flag = 0;
			}
			int baseRow = row / 3 * 3;
			int baseCol = col / 3 * 3;
			for (j = baseRow; j < baseRow + 3; j++)   //同一宫
			{
				for (int k = baseCol; k < baseCol + 3; k++)
				{
					if (range[j][k] == range[row][col] && (j != row || k != col))
						flag = 0;
				}
			}

			if (flag)//可以放
			{
				DFS(count + 1);//进入下一层
			}

		}
		range[row][col] = '0';//回溯
	}
	else
		DFS(count + 1);
}
void Sudoku::solveSudoku(string path)
{
	ifstream problemfile(path);
	//string q;
	//getline(problemfile, q);
	//cout << q;
	//problemfile.open(path, ios::app | ios::out | ios::in);
	//fopen_s用法:，须定义另外一个变量errno_t err，然后err = fopen_s(&fp, filename, "w")。
		errno_t err;
		err = fopen_s(&file2, "sudoku.txt", "w+");
		cout << "打开写文件sudoku.txt" << endl;
	//openfile("sudoku.txt");
	//file2 = fopen(path, "w+");
	if (problemfile)
	{
		int total = 0;
		string temp[9];
		string str;
		int line = 0;
		bool exc = false;     // 识别在problemfile有没有错误输入
		while (total < 1000000 && getline(problemfile, str))
		{
			temp[line] = str;  //从problemfile中读取一行到temp中
			line++;
			if (line == 9)   //每读入9行进行一次处理
			{
				for (int i = 0; i < 9; i++)
					for (int j = 0; j < 9; j++)
					{
						range[i][j] = temp[i][2 * j];  //跳过空格将一个数独问题装入range中
						if (range[i][j] < '0' || range[i][j] > '9')
						{
							exc = true;
							break;
						}

					}
				getline(problemfile, str);//读入一个题目后的空行
				line = 0;
				total++;
				// solve sudoku
				long count = 0;
				DFS(0);
			}
		}
	}
	else
		cout << "Can't find such file:" <<path << endl;

}