#pragma once
//#include"stdafx.h"
#include<algorithm>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Sudoku
{
public:
	Sudoku();//¹¹Ôìº¯Êý
	void createSudoku(int n);
	void openfile(const char* name);
	// judge(int argc, char* argv[]);
	void DFS(int count);
	void solveSudoku(string path);
	int range[20][20];
	string path;
	FILE *file1;
	FILE *file2;
};

class Judge
{
public:
	//Judge(int argc, char *argv[]);
	char judge(int argc,char *argv[]);
	int argc;
	char **argv;
	
};




