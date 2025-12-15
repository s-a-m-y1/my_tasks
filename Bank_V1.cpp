#include<iostream>///////////////////test date//
#include<string>
#include<vector>
#include<fstream>
using namespace std;
const string Bank = "C:/My_project_main/Data_Bank.txt";
string Fi(string msg)
{
    cout<<msg;
    string Add;
    cin>>Add;
    return Add;
}
void Adding_data_(string File_name , string  New_line)
{
    fstream My_Data;
    My_Data.open(File_name , ios::out);// The Mod Add Data And Not Delete BEfore Data //
if (My_Data.is_open())
{
    cout<<"Yes The file Is open :";
    My_Data<<New_line<<endl;
    My_Data.close();
    cout<<"The File Is Close ";
}

}

int main()
{
    Adding_data_(Bank , Fi("Please Enter A Data : "));
    return 0;
}
