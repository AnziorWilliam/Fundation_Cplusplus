
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Replace_symbol(string& str);
int main()
{
    string Originary_str = "i have a dream";
    Replace_symbol(Originary_str);
    cout << Originary_str << endl;
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