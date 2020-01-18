#include"sudoku.h"
#include<time.h>
using namespace std;

char field[200000000];
void Sudoku::openfile(const char* name)
{
	errno_t err;
	err = fopen_s(&file1, name, "w+");
	cout << "��д�ļ�sudoku.txt" << endl;
}

//���������վ�
void Sudoku::createSudoku(int n)
{

	openfile("sudoku.txt");
	int trans[9] = { 0,3,6,1,4,7,5,2,8 };//ÿһ�е��ƶ����
	int flag = 0;//��ǰ���ɵ��վָ���
	int m = 0;
	for (int i = 0; i < 6; i++)//4��6�е��������з�ʽ
	{
		if (flag >= n)
		{
			break;
		}
		if (i)
		{
			//����4��6��
			next_permutation(trans + 3, trans + 6);     //ȫ���к���,������бȵ�ǰ���д�����У�˳���Ǵ�С����
			trans[6] = 2, trans[7] = 5, trans[8] = 8;
		}
		for (int j = 0; j < 6; j++)//7��9�е��������з�ʽ
		{
			if (flag >= n)
				break;
			if (j)
				//����7��9��
				next_permutation(trans + 6, trans + 9);   //ȫ���к���

			char row[10] = "412356789";
			//�����ɵ�һ�����
			for (int k = 0; k < 40320; k++)//��һ�е�8�������з�ʽ
			{
				if (flag >= n)
					break;
				if (k)
					next_permutation(row + 1, row + 9);//��һ�����ֲ��ܻ�

				//����һ���վ�
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
	printf("\n��ʱ��%.2lfs", (double)clock() / CLOCKS_PER_SEC);//����clock���������ó�����ʱ��
}