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
	int row = count / 9;   //position��Ӧ��x����
	int col = count % 9;  //position��Ӧ��y����
	if (range[row][col] == '0')
	{
		for (int i = 1; i <= 9; i++)//���Զ���һ�����1~9�ĸ�ֵ
		{
			range[row][col] = i + '0';

			int flag = 1;
			int j;
			for (j = 0; j < 9; j++)     //ͬһ��
			{
				if (range[row][j] == range[row][col] && j != col)
					flag = 0;
			}
			for (j = 0; j < 9; j++)     //ͬһ��
			{
				if (range[j][col] == range[row][col] && j != row)
					flag = 0;
			}
			int baseRow = row / 3 * 3;
			int baseCol = col / 3 * 3;
			for (j = baseRow; j < baseRow + 3; j++)   //ͬһ��
			{
				for (int k = baseCol; k < baseCol + 3; k++)
				{
					if (range[j][k] == range[row][col] && (j != row || k != col))
						flag = 0;
				}
			}

			if (flag)//���Է�
			{
				DFS(count + 1);//������һ��
			}

		}
		range[row][col] = '0';//����
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
	//fopen_s�÷�:���붨������һ������errno_t err��Ȼ��err = fopen_s(&fp, filename, "w")��
		errno_t err;
		err = fopen_s(&file2, "sudoku.txt", "w+");
		cout << "��д�ļ�sudoku.txt" << endl;
	//openfile("sudoku.txt");
	//file2 = fopen(path, "w+");
	if (problemfile)
	{
		int total = 0;
		string temp[9];
		string str;
		int line = 0;
		bool exc = false;     // ʶ����problemfile��û�д�������
		while (total < 1000000 && getline(problemfile, str))
		{
			temp[line] = str;  //��problemfile�ж�ȡһ�е�temp��
			line++;
			if (line == 9)   //ÿ����9�н���һ�δ���
			{
				for (int i = 0; i < 9; i++)
					for (int j = 0; j < 9; j++)
					{
						range[i][j] = temp[i][2 * j];  //�����ո�һ����������װ��range��
						if (range[i][j] < '0' || range[i][j] > '9')
						{
							exc = true;
							break;
						}

					}
				getline(problemfile, str);//����һ����Ŀ��Ŀ���
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