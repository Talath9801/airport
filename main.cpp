﻿#include <iostream>
#include <fstream> //定义读写已命名文件的类型
#include <vector>
#include <sstream> //多定义的类型则用于读写存储在内存中的string对象
#include <adjlist.h>
using namespace std;

int main()
{
    //读文件C:\Users\lenovo\Desktop
    ifstream inFile("C:\\Users\\lenovo\\Desktop\\data.csv",ios::in);//inFile来自fstream,ifstream为输入文件流(从文件读入)
    string lineStr;
    vector<vector<string>> strArray;
    while(getline(inFile,lineStr)) //getline来自sstream
    {
        //存成二维表结构
        stringstream ss(lineStr);//来自sstream
        string str;
        vector<string> lineArray;
        //按照逗号分隔
        while(getline(ss,str,','))
        {
            lineArray.push_back(str);//一行数据以vector保存
        }
        strArray.push_back(lineArray);//每一行vector数据都放到strArray中去
    }

    //输出结果
//    cout<<strArray.size()<<endl<<strArray[1].size()<<endl;
//          2347行，1到2347有信息            每行11个
//    for(int i=1;i<strArray.size();i++)
//    {
//        for(int j=0;j<strArray[i].size();j++)
//            cout<<strArray[i][j]<<"  ";
//       cout<<endl;
//    }

    AdjList mylist;
    CreateAdjList(mylist,strArray);//构建邻接表

}
