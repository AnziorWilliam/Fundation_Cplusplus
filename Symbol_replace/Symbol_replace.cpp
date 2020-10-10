
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Replace_symbol(string& str);

void replace_Symbol(string& str,int &Symbol_count);

int main()
{
    string Originary_str = "i have a dream";
    string Originary_str2 = "i have a dream";
    int symbol_num = 0;

    Replace_symbol(Originary_str);
    replace_Symbol(Originary_str2, symbol_num);
    cout << Originary_str << endl;
    cout << Originary_str2 << endl;
    return 0;
}

void Replace_symbol(string& str)
{
    auto StrEnd = str.end();
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            //str.insert(i+1, "%20");
            string temp;
            temp = str.substr(i+1, str.length() - 1);
            str.replace(i, str.length() - 1, "%20");
            str.append(temp);
        }
    }
}

void replace_Symbol(string& str, int& Symbol_count)
{
    for (auto i = str.begin(); i != str.end(); i++)
    {
        if (*i == ' ')
        {
            Symbol_count++;
        }
    }
    int ori = str.length();
    int newStrLen = str.length() + Symbol_count * 2;//三个字符 去除原本的空格 所以是2
    int new_index = newStrLen;
    str.resize(newStrLen);
    while (ori >= 0&& new_index>ori)
    {
         if (str[ori] == ' ')
        {
        str[new_index--] = '0';
        str[new_index--] = '2';
        str[new_index--] = '%';
        }
        else
        {
            str[new_index--] = str[ori];
        }
        --ori;
    }
}