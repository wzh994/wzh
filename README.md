# wzh
creat.cpp用来生成1e6以内的数独
solveSudoku.cpp用来解数独
judge.cpp用来判断输入


生成终局：sudoku.exe -c N
          （N为生成终局的个数，N<=1000000）


求解数独：sudoku.exe -s PATH  （PATH为数独问题存放路径）

终局格式为：数与数之间用空格分开，终局与终局之间空一行，行末无空格

求解数独格式与终局格式相同，0代表空格
