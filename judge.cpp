#include "sudoku.h"


char Judge::judge(int argc, char* argv[])
{
	cout << argv[1] << endl;
	this->argc = argc;
	this->argv = argv;
	if (argc != 3)//�������
	{
		return 'e';
	}
	else
	{
		if (strcmp(argv[1], "-c") == 0)
		{
			return 'c';
		}
		else if (strcmp(argv[1], "-s") == 0)
		{
			cout << "???";
			return 's';
		}
		else
		{
			return 'q';
		}
	}
}
