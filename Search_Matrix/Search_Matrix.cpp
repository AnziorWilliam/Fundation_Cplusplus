// Search_Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

#define MAXRow 100
#define MAXCol 100

void find(int a[10][10],int val,int rows,int cols);

int main()
{
	int a[10][10];
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 10; col++)
		{
			a[row][col] = row >= col ? row+col : row+col;
		}
	}
	int cols = sizeof(a[0])/sizeof(int);
	int rows = sizeof(a) / sizeof(int);
	rows /= cols;

	find(a, 7,rows,cols);
	return 0;
}

void find(int a[10][10], int val, int rows, int cols)
{
	bool flag = false;
	if (a != nullptr && rows > 0 && cols > 0)
	{
		int StartRow = 0;
		int StartCol = cols - 1;
		while (StartRow < rows && StartCol >= 0)
		{
			if (a[StartRow][StartCol] == val)
			{
				flag = true;
				cout << "value " << val << "\t exsist" << endl;
				break;
			}
			else if (a[StartRow][StartCol] > val)
			{
				--StartCol;
			}
			else
				++StartRow;
		}
	}
	if (!flag)
	{
		cout << "value " << val << "\t not exsist" << endl;
	}
	return;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
