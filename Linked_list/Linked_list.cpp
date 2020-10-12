#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
    char m_value;
    BinaryTreeNode* LNext;
    BinaryTreeNode* RNext;
};

BinaryTreeNode* ConstructBitree(vector<char>InorderList, vector<char>PreorderList,int lenth);
BinaryTreeNode* ReConstruct(vector<char>InorderList,int InTag, vector<char>PreorderList,int PreTag);
int  do_out(BinaryTreeNode* root);
int main()
{
    vector<char>InorderList(9);
    vector<char>PreorderList(9);
    InorderList = { 'd','b','e','a','h','f','i','c','g'};
    PreorderList = { 'a','b','d','e','c','f','h','i','g' };
    BinaryTreeNode* myroot;
    myroot = ConstructBitree(InorderList, PreorderList, 9);
    while (myroot != nullptr)
    {
        int i  = do_out(myroot);
        if (i == 1)
        {
            break;
        }
    }
}

BinaryTreeNode* ConstructBitree(vector<char>InorderList, vector<char>PreorderList, int lenth)
{
    BinaryTreeNode* Root = new BinaryTreeNode();
    Root->LNext = nullptr;
    Root->RNext = nullptr;
    if (InorderList.size() == 0 || PreorderList.size() == 0)
    {
        cout << "invalid input,Null tree" << endl;
        throw exception("null tree");
    }
    if (InorderList.size() == 1 && PreorderList.size() == 1)
    {
        if (InorderList[0] = PreorderList[0])
        {
            Root->m_value = PreorderList[0];
            return Root;
        }
        else
        {
            cout << "invalid input,can't restruct tree " << endl;
            throw exception("invalid input,can't restruct tree");
        }
    }
    return (ReConstruct( InorderList, 9, PreorderList, 9));
}
BinaryTreeNode* ReConstruct(vector<char>InorderList, int InTag, vector<char>PreorderList, int PreTag)
{
    
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_value = PreorderList[0];
    root->LNext = root->RNext = nullptr;

    auto i = find(InorderList.begin(), InorderList.end(), root->m_value);
//
    if (i == InorderList.end())
    {
        cout << "invalid input,can't found tree root " << endl;
        throw exception("invalid input,can't found tree root ");
    }
    else if (i!= InorderList.end()&&i!= InorderList.begin())
    {
        int PosRoot = distance(InorderList.begin(), i);
        //cout << InTag << "\t Intag" << endl;
       // cout << PosRoot << endl<<endl;
        //递归处理树
        //中序拆分左右
        vector<char> Left;
        vector<char> Right;
        vector<char> LeftPre;
        vector<char> RightPre;

        if(PosRoot>0) Left.resize(PosRoot);
        if (PosRoot == 0) Left.resize(1);

        if(InTag >1)Right.resize(InTag - PosRoot-1);
        if (InTag == 1)Right.resize(1);

        if(PosRoot>0) LeftPre.resize(PosRoot);
        if (PosRoot ==  0) LeftPre.resize(1);
        if (InTag > 1)RightPre.resize(InTag - PosRoot-1);
        if (InTag == 1)RightPre.resize(1);

        if (PosRoot > 0)
        {
            Left.assign(InorderList.begin(), InorderList.begin() + PosRoot);
            LeftPre.assign(PreorderList.begin() + 1, PreorderList.begin() + PosRoot + 1);

            Right.assign(InorderList.begin() + PosRoot + 1, InorderList.end());
            RightPre.assign(PreorderList.begin() + PosRoot + 1, PreorderList.end());
        }
        if (PosRoot == 0)
        {
            Left.assign(InorderList.begin(), InorderList.end());
            LeftPre.assign(PreorderList.begin() , PreorderList.end());

            Right.assign(InorderList.begin() + PosRoot , InorderList.end());
            RightPre.assign(PreorderList.begin() + PosRoot , PreorderList.end());
        }
        if (PosRoot > 0)
        {
            root->LNext = ReConstruct(Left, PosRoot, LeftPre, PosRoot);
        }
        if (PosRoot < sizeof(PreorderList))
        {
            root->RNext = ReConstruct(Right, sizeof(Right), RightPre, sizeof(RightPre));
       }
    }
    return root;
}
int do_out(BinaryTreeNode* root)//后序遍历
{
    BinaryTreeNode* root1;
    root1 = root;
    if(root1->LNext!=nullptr)do_out(root1->LNext);
    else if (root1->LNext == nullptr)return 1;
    if(root1->RNext!=nullptr)do_out(root1->RNext);
    else if (root1->RNext == nullptr)return 1;
    cout << root1->m_value << endl;
}