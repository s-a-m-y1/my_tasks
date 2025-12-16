#include<iostream>///////////////////test date//
#include<string>
#include<limits>
#include<iomanip>
#include<vector>
#include<fstream>
using namespace std;
const string Bank = "C:/My_project_main/Data_Bank.txt";

//-----------------------------------------------------Data--------------------------------------------------//
struct St_Definitions_Data_Bank
{
    string Account_number ;
    string pin_code;
    string Full_name;
    string phone;
    double Account_balance;
    bool Mark = false;//By_defold 
};
enum EN_Record { Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Tranacthions = 6, Exit = 7, };
enum EN_Record_Tranacthions {Deposit_1 = 1  , Winthdraw_1 = 2 , toala_balances = 3 , Main_menu = 4 };
//---------------------------------------------Start---------------------------------------------------------//
/// Note ! The Functhion this is Delete Spaces From Line //
vector<string>Split_Line(string Word , string Dlimter )
{
    string Add_Word_data;//this the var is a add Date clients // 
    short Index_pos = 0 ; // this is a to set the index Dilmter //
    vector<string>Data ; //Each word is returned//
    while ((Index_pos = Word.find(Dlimter)) != std::string::npos)//search delimter and var indexing //
    {
      Add_Word_data = Word.substr(0 , Index_pos);//Here we return the character to the variable via the substring by storing the index number.//
      if (!Add_Word_data.empty())//here check in the string is empty or not 
      {
       Data.push_back(Add_Word_data);//here push Word To vector // 
      }
      Word.erase(0,Index_pos+Dlimter.length());//here Delete Index Dlemter //
    }
    if (! Word.empty())
    {
       Data.push_back(Word);
    }
    return Data;
}
//------------------------------------------End----------------------------------------------------------//

//-----------------------------------------------Start-------------------------------------------------------//

St_Definitions_Data_Bank Add_data_To_struct(string Line , string Delimter = "/")
{
vector<string>S_v;

St_Definitions_Data_Bank Data_bank;

S_v = Split_Line(Line , Delimter);
if (S_v.size()>=5)
{
 Data_bank.Account_number = S_v[0];

Data_bank.pin_code =S_v[1];

Data_bank.Full_name =S_v [2];

Data_bank.phone = S_v[3];

Data_bank.Account_balance = stod(S_v[4]); 
}

return Data_bank;
}

//----------------------------------------------------End--------------------------------------------------------//

//---------------------------------------------------Add_Data-----------------------------------------------------//
vector<St_Definitions_Data_Bank>Read_file_And_Add_data_in_file_to_Vectoe(const string& Loc_file)
{
    fstream Read_F;//A variable through which we open the file//
    vector<St_Definitions_Data_Bank>Ref;//A struct variable to return a vector from data//
    Read_F.open(Loc_file , ios::in);//Open the file in read mode//
    if (Read_F.is_open())//Confirmation that the file has been opened//
    {
          string line_add;//A variable containing the text, including spaces.//
         St_Definitions_Data_Bank Data;//A variable of type struct to store new data.//
        while (getline(Read_F , line_add))//Here we read each line and take the variable. Note that we did not perform the basic operation.//
        {
           Data = Add_data_To_struct(line_add );//Here we add the data to the variable we created earlier. This is how a variable of type struct contains all the data.//
           Ref.push_back(Data);//Here we upload the data to a variable of type struct data//
        }
       Read_F.close();//After completing the task, we close the file.//
    }
    return Ref;//We return the vector filled with a vector data structure.//
}

//-----------------------------------------END---------------------------------------------------------------------------//

//-----------------------------------------SHow_client--------------------------------------------------------------------//
void Pritn_data_Record(St_Definitions_Data_Bank client)//data client is  a vector data struct //
{
	
	system("Color 0A");
	cout << "| " << setw(15) << client.Account_number;
	cout << "| " << setw(10) << client.pin_code;
	cout << "| " << setw(40) << client.Full_name;
	cout << "| " << setw(12) << client.phone;
	cout << "| " << setw(12) << client.Account_balance;
}
void Pritn_data_For_vectorst(vector<St_Definitions_Data_Bank>client)
{
	system("Color 0A");

	cout << "\n\t\t\t\t\t client List(" << client.size() << ")Client(s)" << endl;

	cout << "\n=================================================================================================*\n" << endl;
	cout << "| " << left << setw(15) << " Accout Number ";
	cout << "| " << left << setw(10) << " Pin Code ";
	cout << "| " << left << setw(40) << " Client Name ";
	cout << "| " << left << setw(12) << " Phone ";
	cout << "| " << left << setw(12) << " Balance ";
	cout << "\n=================================================================================================*\n" << endl;
	for (St_Definitions_Data_Bank One_client : client)
	{
		Pritn_data_Record(One_client);
		cout << endl;
	}
	cout << "\n=================================================================================================*\n" << endl;

}

//---------------------------------------------------END------------------------------------------------------------//

// Functhion Is Record //
void Show_data(const string& Loc ,  vector<St_Definitions_Data_Bank>&data )
{
   data = Read_file_And_Add_data_in_file_to_Vectoe(Loc);
    system("cls");

	cout << "=============================" << endl;
	cout << "\t Show Data\t" << endl;
	cout << "=============================" << endl;

    Pritn_data_For_vectorst(data);

}
//--------END---------//

//------------------------------------Check_Account_number_----------------------------------------------------------//

bool Check_if_the_account_number_exists_or_noteck( string Account_number_User  , vector<St_Definitions_Data_Bank>&Data )
{
    
//    Data =Read_file_And_Add_data_in_file_to_Vectoe(Loca);
    if (Data.empty())return false;
    for(St_Definitions_Data_Bank&Client:Data)
    {
        if (Client.Account_number == Account_number_User)
        {
          return true;
        }
    }
return false;
}

/// --------------------------------------------------------END---------------------------------------------------------//

//------------------------------------------------------Read-------------------------------------------------------------//

St_Definitions_Data_Bank Read_Data(vector<St_Definitions_Data_Bank>&Data_cli  , bool Read_Account_number = false)
{
    St_Definitions_Data_Bank data;

    //-------------check_Account_number------------//
    if (!Read_Account_number)
    {
       getline(cin>>ws,data.Account_number);
    while (Check_if_the_account_number_exists_or_noteck(data.Account_number   ,Data_cli ))
    {
     cout<<"Sory ): Invaled Account Number ["<<data.Account_number<<"] :: Enter Account Number : ";
    getline(cin>>ws,data.Account_number);
    }
    }
    else
    cout<<"Enter A Account Number : ";
    getline(cin>>ws,data.pin_code);

    cout<<"Enter A Full Name : ";
     getline(cin>>ws,data.Full_name);

     cout<<"Enter A Phone : ";
     getline(cin>>ws,data.phone);
    
     cout<<"Enter A Account Balance : ";
     cin>>data.Account_balance;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
return data;
}

//-------------------------------------------------END----------------------------------------------------------------------//

//_---------------------------------------Add _data To File--------------------------------------//

void Add_data_To_File(const string& loc  , string line )
{
    fstream Add_mod;
    Add_mod.open(loc,ios::out|ios::app);//
    if (Add_mod.is_open())
    {
        Add_mod<<line<<endl;
        Add_mod.close();
    }
}
 
//---------------------------------------ENd__-------------------------------------------//

//_____________________________________start_Oneline____________________________________//

string Add_date_To_one_line_and_Delmter(St_Definitions_Data_Bank Data , string Delimter  = "/")
{
    string Line ;
    return Line =  Data.Account_number + Delimter+Data.pin_code+Delimter+Data.Full_name+Delimter+Data.phone+Delimter+to_string(Data.Account_balance)+Delimter;  
}

//_____________________________________End________________________________//


//______________________________Add_More________________________________//

void Add_more_data(vector<St_Definitions_Data_Bank>&data1)
{
    St_Definitions_Data_Bank Add;
    char What = 'N';
    do
    {
        Add = Read_Data(data1);

       Add_data_To_File(Bank , Add_date_To_one_line_and_Delmter(Add ));

       cout<<"Do You Add More [Y / N ] : ";

       cin>>What;

       cin.ignore(numeric_limits<streamsize>::max(), '\n');

      	cout << "\t\tAdd New Data :-) \n";

       
    } while (toupper(What)=='Y');

}

//________________________________End_______________________________//

//_______________________________Call-Add_____________________________//


void Adding_New_Data(vector<St_Definitions_Data_Bank>&add)
{
	system("cls");

	cout << "=============================" << endl;
	cout << "\t Add Data \t" << endl;
	cout << "=============================" << endl;

	Add_more_data(add);
}

//_______________________________End_______________________________//

//_______________________________show_______________________________//

void show_data1(St_Definitions_Data_Bank data)
{
	
	cout << "======================" << endl;
	cout << " Account Number: " << data.Account_number << endl;

	cout << " Pin code      : " << data.pin_code << endl;

	cout << " Full Name     : " << data.Full_name << endl;

	cout << " Phone         : " << data.phone << endl;

	cout << "Account Balance: " << data.Account_balance << endl;
	cout << "======================" << endl;
}

//_______________________________End_______________________________//

//______________________________Find_______________________________///

string Read_account_unmber()
{
    string A;
    cout<<"Enter A Account Number :";
    cin>>A;
    return A;

}
bool Find_Client( string Account_number,  vector<St_Definitions_Data_Bank>&data , St_Definitions_Data_Bank & New_data)
{
for(St_Definitions_Data_Bank&client : data)
{
    if (client.Account_number == Account_number)
    {
      New_data = client;

      return true;
    }
}
   return false;
}
//______________________________END__________________________.//

//____________________________mark___________________________//

bool Check_account_number_and_marking(vector<St_Definitions_Data_Bank>&data  , string Account_number)
{
    for(St_Definitions_Data_Bank& A:data)
    {
        if (A.Account_number == Account_number)
        {
          A.Mark = true;
          return true;
        }
        
    }
    return false;
}

//_________________________________end/_____________________///

//________________________________Delete_______________________________///

vector<St_Definitions_Data_Bank> Delete_data_In_file(const string&loc , vector<St_Definitions_Data_Bank>&REf)
 {
    fstream IS_delete;
    IS_delete.open(loc,ios::out);//Delete Mod / 
    if (IS_delete.is_open())
    {
       for(St_Definitions_Data_Bank&LOOP:REf)
       {
        if (!LOOP.Mark)
        {
           IS_delete<<Add_date_To_one_line_and_Delmter(LOOP);
        }
        
       }
       IS_delete.close();
    }
     return REf;
 }

 //_________________________________end/_____________________///

 //________________________________Delete More _______________________________///

 bool More_Delete(string Account_number,vector<St_Definitions_Data_Bank>&data)
 {
    St_Definitions_Data_Bank data1;
    char USer ='N';
    if (Find_Client(Account_number , data ,data1 ))
    {
        show_data1(data1);
        cout<<"Are You Sure Delete : ";
        cin>>USer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       if (toupper(USer)=='Y')
       {
        Check_account_number_and_marking(data,Account_number);
        Delete_data_In_file(Bank , data);
        data = Read_file_And_Add_data_in_file_to_Vectoe(Bank);
        return true;
       }
       else
       {
        cout<<"\nDeletion cancelled by user."<<endl;
        return false;
       }
    }
    else
      while (!Find_Client(Account_number , data ,data1 ))
      {
      cout << "\n Client with Account Number " << Account_number << "Is Not Found ! ";
      cout<<"Enter A Account Number ";
      cin>>Account_number;
   }

		return false;
 }

  //_________________________________end/_____________________///
  
  //____________________________Show_____________________///

   void Show_delete_data(vector<St_Definitions_Data_Bank>& New_data)
 {
	 system("cls");

	 cout << "=============================" << endl;
	 cout << "\t  Delete Data \t" << endl;
	 cout << "=============================" << endl;

	// New_data =Read_file_And_Add_data_in_file_to_Vectoe(Bank);//Note ! Here we used a struct variable for `by reference` to load the data inside the file and transfer it to the variable. Note that this variable is considered native.//
	 string user_input = Read_account_unmber();//variable Account Number  
	if (More_Delete(user_input , New_data)) cout<<"Verified......Scanned[✅]"<<endl;//Here we check whether the scan was successful or not//
    else
    cout<<"Verification failed![🐞]"<<endl;    
 }
//______________________________END____________________________.////

//______________________________Update_data____________________///

bool Update_data(  string Account_number , vector<St_Definitions_Data_Bank>&Data_New)
{
    St_Definitions_Data_Bank Showing;
    char User ='N';
    if (Find_Client(Account_number ,Data_New , Showing ))
    {
        show_data1(Showing);
        cout<<"Are You Sure IS Updata Data  [ Y / N ] :";
        cin>>User;  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (toupper(User)=='Y')
        {
            for ( St_Definitions_Data_Bank & Itr :Data_New )//
            {
                if (Itr.Account_number==Account_number)
                {
                   Itr = Read_Data(Data_New , true) ;
                 break;
                }
            }

               Delete_data_In_file(Bank , Data_New);
              return true;
        }
    }
      else
    {
        while (!Find_Client(Account_number , Data_New ,Showing ))
      {
      cout << "\n Client with Account Number " << Account_number << "Is Not Found ! ";
      cout<<"Enter A Account Number ";
      cin>>Account_number;
        
     }
    }
  
    return false;
}

//_________________________________________END___________________________________//

//_____________________________________SHOW________________________________________//

 void Show_update_Data(vector<St_Definitions_Data_Bank>&data)
{
  system("cls");

 cout << "=============================" << endl;
 cout << "\t  Update Data \t" << endl;
cout << "=============================" << endl;

// data = Read_file_And_Add_data_in_file_to_Vectoe(Bank);
 string user_input = Read_account_unmber();

 if (Update_data (user_input, data))  cout<<"Verified......Scanned[✅]"<<endl;
  else
    cout<<"Verification failed![🐞]"<<endl;    
 }

//_________________________________________END___________________________________//

//_____________________________________SHOW________________________________________//
void Show_Data_find(vector<St_Definitions_Data_Bank>&Data )
{
   
     St_Definitions_Data_Bank data1 ;
    cout << "=============================" << endl;
	 cout << "\t  Find Data \t" << endl;
	 cout << "=============================" << endl;
     string Account  = Read_account_unmber();
if (Find_Client( Account,Data , data1))
{
cout<<"Verified......Scanned[✅]"<<endl;
     show_data1(data1);
}
else

cout<<"Verification failed![🐞] Account Number Is Not True ["<<Account<<']'<<endl;    

}

//_________________________________________END___________________________________//

//_____________________________________Add_BAlances________________________________________//

bool Add_Balances(string Account_number , vector<St_Definitions_Data_Bank>&Data)
{
    St_Definitions_Data_Bank data1;
    double Add_Balances =0;
    char User ='N';
    if (Find_Client(Account_number , Data , data1))
    {
       show_data1(data1);
       do
       {
        cout<<"Pleade Enter Deposit Amount : ";
        cin>>Add_Balances;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         if (Add_Balances <= 0)
         {
            cout << "Invalid amount! Please enter a positive number:🐞";
         }
        
       } while (Add_Balances<=0);
       cout<<"Are You Sure  You want Perfrom this transacthion [ Y / N ] :";
       cin>>User;
       if (toupper(User)=='Y')
       {
        for(St_Definitions_Data_Bank&Balance:Data)
        {
            if (Balance.Account_number==Account_number)
            {
              Balance.Account_balance+=Add_Balances;
              cout<<"New Deposit : "<<Balance.Account_balance<<endl;
              break;
            }
        }
        Delete_data_In_file(Bank , Data);
        return true;
       }
    }
    else
    {
        while (!Find_Client(Account_number , Data ,data1 ))
      {
      cout << "\n Client with Account Number " << Account_number << "Is Not Found ! ";
      cout<<"Enter A Account Number ";
      cin>>Account_number;
        
     }
    }
    return false;
}


//_________________________________________END___________________________________//

//_____________________________________SHOW________________________________________//

 void Show_Deposit(vector<St_Definitions_Data_Bank>&data_TO_vector)
 {
	 string Accout_number = Read_account_unmber();
	//  data_TO_vector = Read_file_And_Add_data_in_file_to_Vectoe(Bank);
	 system("cls");
	 cout << "=============================" << endl;
	 cout << "\t    Deposit   \t" << endl;
	 cout << "=============================" << endl;
	if (Add_Balances( Accout_number , data_TO_vector ))
{
cout<<"Verified......Scanned[✅]"<<endl;
    Pritn_data_For_vectorst(data_TO_vector);
}
else

cout<<"Verification failed![🐞] Account Number Is Not True ["<<Accout_number<<']'<<endl;    
 }

//_________________________________________END___________________________________//

//_____________________________________Windraw________________________________________//

bool Withdraw(string Account_number , vector<St_Definitions_Data_Bank>&Data)
{
    St_Definitions_Data_Bank data1;
    double Withdraw =0;
    char User ='N';
    if (Find_Client(Account_number , Data , data1))
    {
       show_data1(data1);
       do
       {
         cout << "Please Enter Withdraw Amount : ";
        cin>>Withdraw;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         if (Withdraw>=data1.Account_balance)
         {
             cout << "Amount exceeds balance! You can withdraw up to: " << data1.Account_balance << endl;
         }

       } while (Withdraw >= data1.Account_balance);
       cout<<"Are You Sure  You want Perfrom this withdraw [ Y / N ] :";
       cin>>User;
       if (toupper(User)=='Y')
       {
        for(St_Definitions_Data_Bank&Withdraw1:Data)
        {
            if (Withdraw1.Account_number==Account_number)
            {
              Withdraw1.Account_balance-=Withdraw;
              cout<<"New Deposit : "<<Withdraw1.Account_balance<<endl;
              break;
            }
        }
        Delete_data_In_file(Bank , Data);
        return true;
       }
    }
    else
    {
        while (!Find_Client(Account_number , Data ,data1 ))
      {
      cout << "\n Client with Account Number " << Account_number << "Is Not Found ! ";
      cout<<"Enter A Account Number ";
      cin>>Account_number;
        
     }
    }
    return false;
}

//________________________________________________END_______________________________________________//


//_____________________________________SHOW________________________________________//

 void Show_Withdraw( vector<St_Definitions_Data_Bank>&data_TO_vector)
 {
	 string user_input = Read_account_unmber();
	//  data_TO_vector = Read_file_And_Add_data_in_file_to_Vectoe(Bank);
	 system("cls");
	 cout << "=============================" << endl;
	 cout << "\t    Withdraw   \t" << endl;
	 cout << "=============================" << endl;
		if (Withdraw( user_input , data_TO_vector ))
     {
    cout<<"Verified......Scanned[✅]"<<endl;
     Pritn_data_For_vectorst(data_TO_vector);
    }
   else
 
    cout<<"Verification failed![🐞] Account Number Is Not True ["<<user_input<<']'<<endl;  
}
 
//________________________________________________END_______________________________________________//

//_________________________________________________Shows__________________________________________//
 void print_data_B(St_Definitions_Data_Bank client)
 {

	 system("Color 0A");
	 cout << "| " << setw(15) << client.Account_number;
	 cout << "| " << setw(40) << client.Full_name;
    cout << "| " << setw(12) << client.Account_balance; }
 void print_data_B1(vector<St_Definitions_Data_Bank>client)
 {
	 double total_balance = 0;
	 system("Color 0A");

	 cout << "\n\t\t\t\t\t client List(" << client.size() << ")Client(s)" << endl;

	 cout << "\n=================================================================================================*\n" << endl;
	 cout << "| " << left << setw(15) << " Accout Number ";
	 cout << "| " << left << setw(40) << " Client Name ";
	 cout << "| " << left << setw(12) << " Balance ";
	 cout << "\n=================================================================================================*\n" << endl;
	 for (St_Definitions_Data_Bank One_client : client)
	 {
		 print_data_B(One_client);
		 cout << endl;
		 total_balance += One_client.Account_balance;
	 }
	 cout << "\n\t\t\t\t\t TOtal Balances : " << total_balance << endl;
	 cout << "\n=================================================================================================*\n" << endl;

 }


 
  
  void Show_balance( vector<St_Definitions_Data_Bank>&New_data)
 {
	//  New_data = Read_file_And_Add_data_in_file_to_Vectoe(Bank);
	 system("cls");
	 print_data_B1(New_data);
 }

  void Exit_Program()
 {
	 system("cls");
	 cout << "=============================" << endl;
	 cout << "\t   Thank  :)   \t" << endl;
	 cout << "=============================" << endl;
	
 }
  void Print_menu(vector<St_Definitions_Data_Bank>&data);
 void GO_back_end(vector<St_Definitions_Data_Bank>&data)
 {
	 cout << "\n\nPress any key to go back to Main Menue..." << endl;
	 system("pause>0");
	    Print_menu(data);
 }
 void Print_Menu_Tranacthions(vector<St_Definitions_Data_Bank>&data) ;
 void main_menu_back(vector<St_Definitions_Data_Bank>&data)
 {
	 cout << "\n\nPress any key to go back to Main Menue..." << endl;
	 system("pause>0");
       Print_Menu_Tranacthions(data);

 }

//________________________________________________END_______________________________________________//

//_________________________________________CALLS1_______________________________________//
void Calls_1(EN_Record calls_Records  , vector<St_Definitions_Data_Bank>&data)
{
    switch (calls_Records)
    {
    case EN_Record::Show :
        system("cls");
       Show_data(Bank , data);
        GO_back_end(data);
        break;

    case EN_Record::Add :
        system("cls");
        Adding_New_Data(data);
        GO_back_end(data);
        break;

     case EN_Record::Delete:
     Show_delete_data( data);   
    GO_back_end(data);
    break;

    case EN_Record::Update:
     system("cls");
    Show_update_Data(data);
    GO_back_end(data);
    break;

    case EN_Record::Find:
     system("cls");
    Show_Data_find( data);
    GO_back_end(data);
    break;

    case EN_Record::Tranacthions:
     system("cls");
    Print_Menu_Tranacthions(data);
    break;

    case EN_Record::Exit:
     system("cls");
    Exit_Program();
    break;
    default:
    return;
    }

}

//________________________________________________END_______________________________________________//


//_________________________________________CALLS1_______________________________________//


void Calls_2(EN_Record_Tranacthions Call2 , vector<St_Definitions_Data_Bank>&Data)
{

    switch (Call2)
    {
    case  EN_Record_Tranacthions::Deposit_1 :
    	 system("cls");
         Show_Deposit(Data);
         main_menu_back(Data);
        break;
     case EN_Record_Tranacthions::Winthdraw_1:
       system("cls");
       Show_Withdraw(Data);
        main_menu_back(Data);
        break;
     case EN_Record_Tranacthions::toala_balances:
       system("cls");
       Show_balance(Data);
        main_menu_back(Data);
       break;
     case EN_Record_Tranacthions::Main_menu:  
      Print_menu(Data);
    default:
     return;
    }
}


//________________________________________________END_______________________________________________//

//________________________________________________prints__________________________________________//

short read____()
 {
	 short data;
	 cout << "Choose what Do you  Want To Do :[ 1 To 4 ] : ";
	 cin >> data;
	 cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 return data;
 }

void Print_Menu_Tranacthions(vector<St_Definitions_Data_Bank>&data)
 {
	 system("cls");
	 system("Color 0A");
	 cout << "===============================================" << endl;
	 cout << "\t\t Tranacthions Menu Screen " << endl;
	 cout << "===============================================" << endl;
	 cout << "\t Deposit         [1] . " << endl;
	 cout << "\t withdraw        [2] . " << endl;
	 cout << "\t Total Balances  [3] . " << endl;
	 cout << "\t Main Menue      [4] . " << endl;
	 cout << "===============================================" << endl;
	 Calls_2( (EN_Record_Tranacthions)  read____() , data);
 }

short raed()
{
	short r;
	cout << "Enter a Number [  1 To 7 ] :";
	cin >> r;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return r;
}

void Print_menu(vector<St_Definitions_Data_Bank>&data)
{
	system("cls");
	system("Color 0A");
	cout << "===============================================" << endl;
	cout << "\t\t Main Menu Screen " << endl;
	cout << "===============================================" << endl;
	cout << "\t Show Client List [1] : " << endl;
	cout << "\t Add  New Client  [2] : " << endl;
	cout << "\t Delete Client    [3] : " << endl;
	cout << "\t Update Client    [4] : " << endl;
	cout << "\t Find Client      [5] : " << endl;
	cout << "\t Tranacthions     [6] : "  << endl;
	cout << "\t Exit             [7] : " << endl;
	cout << "===============================================" << endl;
	Calls_1((EN_Record)raed() , data );
}
//________________________________________________END_______________________________________________//


int main()
{
     vector<St_Definitions_Data_Bank>data=Read_file_And_Add_data_in_file_to_Vectoe(Bank );
     Print_menu(data);

	system("pause>0");
    return 0;
}
