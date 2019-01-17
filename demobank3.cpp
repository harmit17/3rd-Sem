#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
using namespace std;


class Bank{

protected :

    char name[20];
    char acc_type[15];
    long double amount;
    long long acc_num;

public :

    void getdata(){                                                             //function for create Account...

        ofstream f1("bank.txt",ios ::out |  ios :: app);
        ifstream f2("bank.txt",ios::in |  ios :: app);
        cout << endl;
        f1.seekp(0,ios::beg);
        f1 << endl;
        cout << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << " Creating Account " << endl;
        cout << endl;
        cout << endl;
        cout << "\t" << "\t" << "\t" << "\t" << "Enter Account Number(14 Digit) : " ;
        //cout << endl;
        x:
        cin >> acc_num;
        if(acc_num < 0)
        {
            cout << endl;
            cout << "\t" << "\t" << "\t" << "\t" << "Entered account number incorrectly..." << endl;
            cout << "enter it again:";
            cout << endl;
            goto x;
        }

        else if(acc_num <= 9999999999999 ){

            cout << "\t" << "\t" << "\t" << "\t" << "Enter Account Number Again..." << endl;
            cout << "\t" << "\t" << "\t" << "\t" << "Enter it again:";
            goto x;
        }

        else if( acc_num > 99999999999999){

            cout << "\t" << "\t" << "\t" << "\t" << "Enter Account Number Again..." << endl;
            cout << "\t" << "\t" << "\t" << "\t" << "Enter it again:";
            goto x;
        }

long long t;
        while(f2 >> t ){

            if(t == acc_num ){

                cout << "\t" << "\t" << "\t" << "\t" << "This account is already occupied..." << endl;
                goto x;
            }
            else{

                f1 << acc_num << "\t";
            }
        }
       // f1 << acc_num << "\t";
        cout << "\t" << "\t" << "\t" << "\t" << "Enter Your name : ";
        cin >> name;
        f1 << name << "\t";
        cout << "\t" << "\t" << "\t" << "\t" << "Which type of account you want to open:(Savings/Current) : ";
        cin >> acc_type;
        f1 << acc_type << "\t";
        C:
        cout << "\t" << "\t" << "\t" << "\t" << "Enter Minimum amount in your account(>2000) : ";
        cin >> amount;
        if(amount < 2000){

            cout << "\t" << "\t" << "\t" << "\t" << "Your Minimum Amount Must be Greater than 2000...." << endl;
            goto C;
        }
        else{

        f1 << amount << "\t";
        }
        cout << endl;
        cout << endl;
        cout << "\t" << "\t" << "\t" << "\t" << "Your account is successfully created ......" << endl;
        cout << endl;
        cout << endl;
    }

     void putdata(){                                                                //function for show Account...

        long long temp;
        cout<<"enter account no."<<endl;
        cin>>temp;
        ifstream f1("bank.txt",ios ::in| ios :: app);
        f1.seekg(0);
        while (f1 >> acc_num >> name >> acc_type >> amount){

            if(acc_num == temp){

                cout << "Account Number:" << acc_num << endl;
                cout << "Account Holder:" << name << endl;
                cout << "Account type  :"  << acc_type << endl;
                cout << "Amount        :"  << amount << endl;
            }

        }

    }

    void withdraw(){                                                                //function for withdraw Amount...

        ofstream f2("bank.txt",ios::out  | ios :: app);
        ifstream f1("bank.txt",ios::in |  ios :: app);
        fstream f3("bank1.txt",ios::out  | ios :: app | ios :: in);
       // fstream f4("bank2",ios::out  | ios :: app | ios :: in);

        f1.seekg(0);
        long long a_num;
        long double w_amount;

        cout << "Enter Account Number :" << endl;
        cin  >> a_num;
        Bank ac;

        while (f1 >> acc_num >> name >> acc_type >> amount){

            if(acc_num == a_num){

                cout << "Name         :" << name << endl;
                cout << "Account type :" << acc_type << endl;
                cout << "balance      :" << amount << endl;

                cout << "Enter withdraw amount : " << endl;
                cin  >> w_amount;
                amount = amount - w_amount;
                cout << "Balance :" << amount << endl;

                f3 << acc_num << "\t" ;
                f3 << name << "\t" ;
                f3 << acc_type << "\t" ;
                f3 << amount <<  "\t";
                f3 << "\n";
        }

        if(acc_num != a_num){

                f3 << acc_num << "\t" ;
                f3 << name << "\t" ;
                f3 << acc_type << "\t" ;
                f3 << amount <<  "\t";
                f3 << "\n";
        }
    }

          f3.close();
          f1.close();
          f2.close();
          int p=remove("G:\\Code block\\bank.txt");

          char oldname[] = "G:\\Code block\\bank1.txt";
          char newname[] = "G:\\Code block\\bank.txt";
          rename(oldname, newname);
    }

    void deposit(){                                                             //function for deposit Amount...

        fstream f2("bank.txt",ios::out  | ios :: app);
        fstream f1("bank.txt",ios::in |  ios :: app);
        fstream f3("bank1.txt",ios::out  | ios :: app | ios :: in);
        //fstream f4("bank2",ios::out  | ios :: app | ios :: in);


        f1.seekg(0);
        long long a_num;
        long double d_amount;

        cout << "Enter Account Number :" << endl;
        cin  >> a_num;
        Bank ac;

        while (f1 >> acc_num >> name >> acc_type >> amount){

            if(acc_num == a_num){

                cout << "Name         :" << name << endl;
                cout << "Account type :" << acc_type << endl;
                cout << "balance      :" << amount << endl;

                cout << "Enter deposit amount : " << endl;
                cin  >> d_amount;
                amount = amount + d_amount;
                cout << "Balance :" << amount << endl;

                f3 << acc_num << "\t" ;
                f3 << name << "\t" ;
                f3 << acc_type << "\t" ;
                f3 << amount <<  "\t";
                f3 << "\n";
            }
                if(acc_num != a_num){

                    f3 << acc_num << "\t" ;
                    f3 << name << "\t" ;
                    f3 << acc_type << "\t" ;
                    f3 << amount <<  "\t";
                    f3 << "\n";

                }


                }
                f3.close();
                f1.close();
                f2.close();
                 int p=remove("G:\\Code block\\bank.txt");

                 char oldname[] = "G:\\Code block\\bank1.txt";
                 char newname[] = "G:\\Code block\\bank.txt";
                 rename(oldname, newname);

            }



    void deleting(){                                                        //function for delete Account...

        long long num;
          string line;
          cout << "Please Enter the account you want to delete: ";
          cin >> num;
          ifstream myfile("bank.txt",ios::in);
          ofstream temp;
          temp.open("temp.txt",ios::app| ios::out);
          while (myfile >> acc_num >> name >> acc_type >> amount)
          {
            if (num != acc_num)
              temp << acc_num << "\t" << name << "\t" << acc_type <<"\t" << amount <<"\t" <<endl;
          }
          cout << "The record with the name " << num << " has been deleted if it exsisted" << endl;
          myfile.close();
          temp.close();

          int p=remove("G:\\Code block\\bank.txt");

          char oldname[] = "G:\\Code block\\temp.txt";
          char newname[] = "G:\\Code block\\bank.txt";
          rename(oldname, newname);
    }

};




int main()
{

    Bank ca1;
    int i;
b:
    cout << endl;
    cout << endl;
    cout << "\t" << "\t" << "\t" << "\t" <<  "....Banking System...." << "\t" << "\t" << "\t" << "\t" << endl;
    cout << endl;
    cout << endl;

    string pass ="";
    string username;
    char ch1;

    cout<<"Enter Username  ";
    cin>>username;
    cout << "Enter pass      ";
    ch1 = _getch();
    while(ch1 != 13) //character 13 is enter
    {
        pass.push_back(ch1);
        cout << '*';
        ch1 = _getch();
    }

     if((username=="Harmit" && pass == "harmit07")||(username=="Shivam" && pass == "shivam08")||(username=="Sid" && pass == "sid19"))
    {
        system("cls");
        char ch;
        fstream fp;

        do
        {


        A :
        //system("CLS");
        cout << "\t" << "\t" << "\t" << "\t" << "Enter Choice :" << endl;
        cout << endl;
        cout << endl;
        cout  << "\t" << "\t" << "\t" << "\t" << "1)Create Account   :" << endl;
        cout << endl;
        cout <<  "\t" << "\t" << "\t" << "\t" << "2)Show Account     :" << endl;
        cout << endl;
        cout << "\t" << "\t" << "\t"  << "\t" << "3)Withdraw amount  :" << endl;
        cout << endl;
        cout << "\t" << "\t" << "\t" << "\t" << "4)Deposit amount  :" << endl;
        cout << endl;
        cout << "\t" << "\t" << "\t" << "\t" << "5)Delete amount  :" << endl;
        cout << endl;
        cout << "\t" << "\t" << "\t"  << "\t" << "6)Exit             :" << endl;
        cout << endl;
        cin >> i;

        switch(i){

                case 1:
                      system("CLS");
                      ca1.getdata();
                      cout << "\n";
                      goto A;
                      break;
                case 2:
                      system("CLS");
                      ca1.putdata();
                      cout << "\n";
                      goto A;
                      break;
                case 3:
                      system("CLS");
                      ca1.withdraw();
                      cout << "\n";
                      goto A;
                      break;
                case 4:
                      system("CLS");
                      ca1.deposit();
                      cout << "\n";
                      goto A;
                      break;
                case 5:
                      system("CLS");
                      ca1.deleting();
                      cout << "\n";
                      goto A;
                      break;
                case 6:
                      system("CLS");
                      goto B;
                      break;
        }

         }
        while(ch!='8');
    }
    else
    {
        system("cls");
        cout<<"\nSomething wrong...\n";
        cout << "Incorrect PassWord Or Username..." << endl;
        pass="";
        goto B;
    }

    B :
    return 0;
}

