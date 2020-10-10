// ArrayCheck.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

bool means_1(int Origin[],int OutArr[],int len);

bool means_2(int Origin[], int len, int Duplication[]);

bool means_3(int len, int Origin[]);
int Bina_treat(int Origin[], int len, int Head, int End);

int main()
{
    std::cout << "Hello World!\n";
    int a[7] = { 1,1,5,5,6,4,3 };
    int b[7] = { 0 };
    int c[7] = {0};
    int d[8] = { 1,2,3,3,4,5,6,2 };
    int len = sizeof(a)/sizeof(int);
    int lend = sizeof(d) / sizeof(int);
    means_1(a, b,len);
    means_2(a, len, c);
    means_3(lend, d);
}

bool means_1(int Origin[], int OutArr[],int len)
{
    //输入约束
    if (Origin == nullptr || sizeof(Origin)<= 0 )
    {
        cout << "Null Array" << endl;
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (Origin[i]<0 || Origin[i]>len - 1)
        {
            cout << "Invalid Array" << endl;
            return false;
        }
    }
    
    //辅助数组赋值
    int temp;
    for (int i = 0; i < len; i++)
    {
        temp = Origin[i];
        OutArr[temp] ++;
    }

    //输出重复数字
    for (int j = 0; j < len; j++)
    {
        if (OutArr[j] > 1)
        {
            cout << j << endl;
        }
    }

    //输出操作后的数组值
    cout << "after do mean1 Original: " << endl;
    for (int i = 0; i < len; i++)
    {
        cout << Origin[i] << "\t";
    }
    cout << endl;
    return true;
}

bool means_2(int Origin[], int len, int Duplication[])
{
    //输入约束
    if (Origin == nullptr || sizeof(Origin) <= 0)
    {
        cout << "Null Array" << endl;
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (Origin[i]<0 || Origin[i]>len - 1)
        {
            cout << "Invalid Array" << endl;
            return false;
        }
    }

    //输出重复数字
    cout << endl;
    for (int i = 0; i < len; i++)
    {
        while (Origin[i] != i)
        {
            if (Origin[i] == Origin[Origin[i]])
            {
                Duplication[Origin[i]]++;
                if (Duplication[Origin[i]] == 2)
                {
                    cout << Origin[i] << endl;
                    break;
                }
            }

            //swap position
            int temp = Origin[i];
            Origin[i] = Origin[temp];
            Origin[temp] = temp;
            continue;
        }
    }

    //输出改变后原始数组的值
    cout << "after do mean2 Original: " << endl;
    for (int i = 0; i < len; i++)
    {
        cout << Origin[i]<<"\t";
    }
    cout << endl;
    return true;
}

//二分法
bool means_3(int len, int Origin[])
{
    if (Origin == nullptr || sizeof(Origin) <= 0)
    {
        cout << "Null Array" << endl;
        return false;
    }

    int start = 1;
    int end = len - 1;
    while (end >= start)
    {
        int middle = ((end - start) >> 1) + start;//等价static_cast<int>( (end-start-0.5)/2 )+start      向下取整 ,这里使用移位运算更简便
        int count = Bina_treat(Origin, len, start, middle);

        if (end == start)//重复校验
        {
            if (count > 1)
            {
                cout<<endl<< start;
                break;
            }
            else
                break;
        }

        //边界修改
        if (count > (middle - start + 1))
        {
            end = middle;
        }
        else
            start = middle + 1;
    }

    return -1;
}
int Bina_treat(int Origin[], int len, int Head, int End)
{
    if (Origin == nullptr)
    {
        return false;
    }
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (Origin[i] >= Head && Origin[i] <= End)
        {
            ++count;
        }
    }
    return count;
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
