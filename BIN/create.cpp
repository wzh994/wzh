#include"sudoku.h"
#include<time.h>
using namespace std;

char field[200000000];
void Sudoku::openfile(const char* name)
{
	errno_t err;
	err = fopen_s(&file1, name, "w+");
	cout << "打开写文件sudoku.txt" << endl;
}

//生成数独终局
void Sudoku::createSudoku(int n)
{

	openfile("sudoku.txt");
	int trans[9] = { 0,3,6,1,4,7,5,2,8 };//每一行的移动情况
	int flag = 0;//当前生成的终局个数
	int m = 0;
	for (int i = 0; i < 6; i++)//4到6行的六种排列方式
	{
		if (flag >= n)
		{
			break;
		}
		if (i)
		{
			//交换4到6行
			next_permutation(trans + 3, trans + 6);     //全排列函数,输出所有比当前排列大的排列，顺序是从小到大。
			trans[6] = 2, trans[7] = 5, trans[8] = 8;
		}
		for (int j = 0; j < 6; j++)//7到9行的六种排列方式
		{
			if (flag >= n)
				break;
			if (j)
				//交换7到9行
				next_permutation(trans + 6, trans + 9);   //全排列函数

			char row[10] = "412356789";
			//先生成第一种情况
			for (int k = 0; k < 40320; k++)//第一行的8！种排列方式
			{
				if (flag >= n)
					break;
				if (k)
					next_permutation(row + 1, row + 9);//第一个数字不能换

				//生成一个终局
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						field[m + flag] = row[(j + trans[i]) % 9];
						m += 1;
					}
					field[(m - 1) + flag] = '\n';
				}
				field[m + flag] = '\n';
				flag++;
			}
		}
	}	
	fputs(field, file1);
	printf("\n用时：%.2lfs", (double)clock() / CLOCKS_PER_SEC);//调用clock（）函数得出运行时间
}
