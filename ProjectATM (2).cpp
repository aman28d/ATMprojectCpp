#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include<conio.h>
#include <windows.h>



using namespace std;


class ATM{

  private:
      const int NumACC = 5;
      string FName[5], LName[5], AccNum [5], CardNum [5], PINnum [5];
      int Cash [5], cash, ATMcash;

      string Card, NewPIN1, NewPIN2, ACCNum;
      char PIN[5], NewPIN[5], choice, YN, BC, LN;
      int  Check =0, NumTry=1, BeforeW, AfterW ;

  public:

    void Introdution();
    void Wait ();
    void Transactions (string ,int, string);
    void Success ();
    void Fail ();
    void Choice ();
    void HidePIN (char pin[5]);
    void Amount ();
    void Withdrawal (int &);
    void CusInfo ();
    int GoBack ();
    void Language ();
    void Logs (string, string);


};

int main()
{
   ATM atm;
   system ("color 5e");

   atm.CusInfo();


    return 0;
}



void ATM::Introdution(){

    cout<<"\n\n\n\n";
    cout<<"                   ********************************************************************************************** "<<endl;
    cout<<"                   * WELCOME TO CBE AUTOMATED TELLER MACHINE (ATM)                                              * "<<endl ;
    cout<<"                   *                                                                                            * "<<endl;
    cout<<"                   * PLEASE INSERT YOUR ATM (OR ENTER THE LAST FOUR NUMBERS OF YOUR CARD NUMBER)                * "<<endl ;
    cout<<"                   ********************************************************************************************** "<<endl;


    }
void ATM::Wait (){

   for (int i=0; i<3; i++){
         cout<<"\n\n\n";
         cout<<setw(40)<<"Please wait";
      for (int j=0; j<3; j++){
        Sleep(700);
        cout<<".";

        }

        Sleep (700);
        system ("cls");

     }
     }
void ATM::Transactions (string CardNUM, int CASH, string CHOICE){


     SYSTEMTIME X;
    GetLocalTime(&X);
    ofstream Output;

    Output.open("Transactions.txt", ios::app);
    Output<<X.wDay<<"/"<<X.wMonth<<"/"<<X.wYear<<endl;
    Output<<X.wHour<<":";
    if(X.wMinute<10){ Output<<"0";}
    Output<<X.wMinute<<endl;
    Output<<CardNUM<<endl;
    Output<<CHOICE<<" ";
    Output<<CASH<<endl<<endl;
    Output.close();


    }
void ATM::Success (){
       system ("cls");
       cout<<"\n\n\n"<<setw(45)<<"Success \n\n Thanks for banking with us ! \t\t\t\t";
       getch ();
     }
void ATM::Fail (){
       system ("cls");
       cout<<"\n\n\n"<<setw(45)<<"Fail\n\t\t\t\t";
       getch ();
    }
void ATM::Choice (){

    cout<<"\n\n\n";
    cout<<setw(60)<<"1  Deposit            Withdrawal  4\n";
    cout<<setw(60)<<"2  Transfer           Balance     5\n";
    cout<<setw(60)<<"                      PIN Change  6\n";
    cout<<setw(60)<<"3  Fast Cash                       \n";
    cout<<setw(60)<<"     100                           \n";

    }
void ATM::HidePIN (char pin[5]){


    for (int i=0; i<4; i++){
                pin[i]=getch();

                 while (pin[i]<48||pin[i]>57){
                 pin[i]=getch();


                 }
                 cout<<"*";
                 }
                 pin[4]={0};


    }
void ATM::Amount (){
    cout<<"\n\n\n";
    cout<<setw(60)<<"1  100               2000  5\n";
    cout<<setw(60)<<"2  200               3000  6\n";
    cout<<setw(60)<<"3  500               4000  7\n";
    cout<<setw(60)<<"4  1000      Other Amount  8\n";

    }
void ATM::Withdrawal (int &CASH){
      char a;
        cout<<"\n\t\t\t\t";
         a =getch ();

          while (a<49||a>56){
           a=getch();
          }
         system ("cls");
         switch (a){
   case '1':
   CASH-=100;
   break;
     case '2':
   CASH-=200;
   break;
    case '3':
   CASH-=500;
   break;
     case '4':
   CASH-=1000;
   break;
    case '5':
   CASH-=2000;
   break;
     case '6':
   CASH-=3000;
   break;
    case '7':
   CASH-=4000;
   break;
     case '8':
   system ("cls");

    cout<<"\n\n\n"<<setw(45)<<"Enter Amount in multiple of 50\n\t\t\t\t";

   cin>>cash;
    while (cash%50!=0){
        system ("cls");
    cout<<"\n\n\n"<<setw(45)<<"Enter Amount in multiple of 50\n\t\t\t\t";
   cin>>cash;


     }
   while (cash>4000){
    system ("cls");
    cout<<"\n\n\n"<<setw(45)<<"Enter Amount less than or equal to 4000\n\t\t\t\t";
    cin>>cash;

    while (cash%50!=0){
    system ("cls");
    cout<<"\n\n\n"<<setw(45)<<"Enter Amount in multiple of 50\n\t\t\t\t";
   cin>>cash;
    }
   }
   CASH-=cash;
   break;
    }



    }
void ATM::CusInfo (){

    ifstream Input;

    Input.open("ATM Status.txt");

     Input >>ATMcash;

     Input.close();

     if (ATMcash>0){


      Input.open ("CustomerInfo.txt");

       if (!Input.is_open())
       {
    //Displays error message if file does not open
           cout<<"Error opening file\n";
           exit (EXIT_FAILURE);
           Fail();
       }
       int i=0;
       while (Input){

        Input>>FName[i]>>LName[i]>>AccNum[i]>>CardNum[i]>>PINnum[i]>>Cash[i];
        //Assigns Variables in the file in the following order
        i++;
       }
        Input.close();

        Introdution();
           cout<<"\n\t\t\t\t";
    //Asks user to Enter last Four digits of his/her Number
        cin>>Card;
        system ("cls");

        for (int i=0; i<NumACC; i++){
            if (Card== CardNum[i].substr (8, 4)){
                Check =1;
                Language();
                cout<<"\n\n\n"<<setw(45)<<"Enter PIN\n\t\t\t\t";

                HidePIN(PIN);



                while (PIN!=PINnum[i]){
                    system ("cls");
                    cout<<"\n\n\n"<<setw(45)<<"Incorrect PIN\n\t\t\t\t";
                    HidePIN(PIN);

                 NumTry++;
                if (NumTry==3){
                  Fail();
                  Logs (CardNum[i], "Fail");
                  while (1){

                   system("cls");
                   CusInfo();

                  }


                 }
                }
            Afterpin:
             system ("cls");
             cout<<"\n\n\n"<<setw(40)<<"Welcome "<<FName[i]<<" "<<LName[i]<<"\n\t\t\t\t";
             Choice ();

             cout<<"\n\t\t\t\t";

             choice=getch ();
              while (choice<49||choice>54){
               choice=getch();


                 }
             system ("cls");

    switch (choice){
        case '1':
            Acc1:
            cout<<"\n\n\n"<<setw(20)<<"Enter Account Number "<<"\n\t\t\t";
            cout<<"\n\n\n\n"<<setw(25)<<"1  Back"<<setw(40)<<"Cancel  2\n";
            for (int i=0; i<5; i++){
            //Makes Cursor move up 5 lines
             cout<<"\e[A  ";
            }
            cin>>ACCNum;

            if (ACCNum =="1") {goto Afterpin;}
            else if (ACCNum =="2") {goto End;}
            for (int i=0; i<NumACC; i++){

                if (ACCNum==AccNum[i]){
                Check=2;

                system("cls");
                cout<<"\n\n\n"<<setw(40)<<"Deposit to "<<FName[i]<<" "<<LName[i]<<endl<<endl;
                cout<<setw(50)<<"1  Yes                 No  2\n";
                cout<<"\n\t\t\t\t";
                  YN=getch();
                while (YN!='1'&&YN!='2'){
                    YN=getch ();
                }
                switch (YN){
            case '1':
                 system("cls");
                 cout<<"\n\n\n"<<setw(20)<<"Enter the Amount you want to deposit "<<"\n\t\t\t";
                 cin>>cash;
                 Cash[i]+=cash;
                 ATMcash+=cash;
            system ("cls");
            Wait();
            Transactions (CardNum [i], cash, "Deposit");
            Logs (CardNum[i], "Success");
            Success ();
                 break;
            case '2' :
                 system("cls");
                 goto Acc1;
                 break;


                }



                }


            }
               if (Check==1){
                system ("cls");
                goto Acc1;
               }


            break;

            case '2':

            Acc2:
            cout<<"\n\n\n"<<setw(20)<<"Enter Account Number "<<"\n\t\t\t";
            cout<<"\n\n\n\n"<<setw(25)<<"1  Back"<<setw(40)<<"Cancel  2\n";
            for (int i=0; i<5; i++){
            //Makes Cursor move up 5 lines
             cout<<"\e[A  ";
            }
            cin>>ACCNum;
            if (ACCNum =="1") {goto Afterpin;}
            else if (ACCNum =="2") {goto End;}

            for (int j=0; j<NumACC; j++){

                if (ACCNum==AccNum[j]){
               Check=2;
                system("cls");
                cout<<"\n\n\n"<<setw(40)<<"Transfer to "<<FName[j]<<" "<<LName[j]<<endl<<endl;
                cout<<setw(50)<<"1  Yes                 No  2\n";
              cout<<"\n\t\t\t\t";
                  YN=getch();
                while (YN!='1'&&YN!='2'){
                    YN=getch ();
                }
                switch (YN){
            case '1':
                 system("cls");
                 cout<<"\n\n\n"<<setw(20)<<"Enter the Amount you want to transfer "<<"\n\t\t\t";
                 cin>>cash;
                 if (Cash[i]>=cash){
                    Cash[i]-=cash;
                    Cash[j]+=cash;
                  Transactions (CardNum [i], cash, "Transfer");
                  Logs (CardNum[i], "Success");
                   system ("cls");
                   Wait ();
                  Success ();
                   }
                 else {
                 system ("cls");
                 Wait ();
                 Logs (CardNum[i], "Fail");
                cout<<"\n\n\n"<<setw(40)<<"         You don't have enough money for this Transaction\n\t\t\t\t";
                getch();
                 }

                 break;
            case '2' :
                 system("cls");
                 goto Acc2;
                 break;


                }



                }


            }
           if (Check==1){
                system ("cls");
                goto Acc2;
               }



            break;


            case '3':
                 if (ATMcash>=100&&Cash[i]>=100){

                Cash[i]-=100;
                ATMcash-=100;
                Transactions (CardNum [i], 100, "Withdrawal");
                 Logs (CardNum[i], "Success");
                Wait ();
                 Success ();
               }
            else {
               Wait ();
               Logs (CardNum[i], "Fail");
               Fail();
            }
            break;

            case '4':

               Amount ();
               BeforeW= Cash [i];
               //BeforeW is the value of the cash before withdrawal
               Withdrawal(Cash [i]);
               AfterW=Cash [i];
               //AfterW is the value of the cash after withdrawal
               if (ATMcash-(BeforeW-AfterW)<0){

                Cash[i]=BeforeW;
                system ("cls");
                Wait ();
                 Logs (CardNum[i], "Fail");
                cout<<"\n\n\n"<<setw(45)<<"ATM is Out of Cash\n\t\t\t\t";
                getch();
               }
            else if (AfterW<0){

                Cash[i]=BeforeW;
                system ("cls");
                Wait();
                 Logs (CardNum[i], "Fail");
                cout<<"\n\n\n"<<setw(40)<<"         You don't have enough money for this Transaction\n\t\t\t\t";
                getch();
               }
               else {
                system ("cls");
                Wait ();

                Transactions (CardNum [i], BeforeW-AfterW, "Withdrawal");
                 Logs (CardNum[i], "Success");
                ATMcash-=(BeforeW-AfterW);
                Success();
               }


            break;

            case '5':
                Wait ();
                cout<<"\n\n\n"<<setw(20)<<"Available Balance "<<"\n\t\t\t";
                cout<<Cash[i]<<endl;

                if (GoBack ()==0)  goto Afterpin;
                else { goto End; }

            break;

            case '6' :
                cout<<"\n\n\n"<<setw(45)<<"Enter New PIN\n\t\t\t\t";
                string a,b;
                HidePIN (NewPIN);
                NewPIN1=NewPIN;
                system ("cls");

                cout<<"\n\n\n"<<setw(40)<<"Confirm\n\t\t\t\t";

                HidePIN(NewPIN);
                NewPIN2=NewPIN;
                int o=1;
                while (NewPIN2!=NewPIN1){
                system ("cls");

                cout<<"\n\n\n"<<setw(40)<<"Incorrect\n\t\t\t\t";

               HidePIN (NewPIN);
                NewPIN2=NewPIN;
                o++;
                system ("cls");
                 if (o==3){goto Afterpin;}
                 }
                 system ("cls");
                 Wait ();
             cout<<"\n\n\n"<<setw(45)<<"PIN Changed\n\t\t\t\t";
             PINnum[i]=NewPIN1;

             if (GoBack ()==0)  goto Afterpin;
              else { goto End; }



            break;
         }



            }


        }
       if (Check==0){
            system ("cls");
            CusInfo();

        }
    End:
       ofstream Output;
       Output.open ("CustomerInfo.txt");

       if (!Output.is_open())
       {
    //Displays error message if file does not open
           cout<<"Error opening file\n";
           exit (EXIT_FAILURE);
       }
       for (int i=0; i<NumACC;i++)
      {
        Output<<FName[i]<<" "<<LName [i]<<endl;
        Output<<AccNum[i]<<endl;
        Output<<CardNum[i]<<endl;
        Output<<PINnum[i]<<endl;
        Output<<Cash[i]<<endl<<endl;


       }
        Output.close();

        Output.open("ATM Status.txt");

        Output<<ATMcash;

        Output.close();
     }
     else {

        cout<<"\n\n\n\n"<<setw(40)<<"ATM Is Out Of Cash "<<"\n\t\t\t";
        getch();
        exit (EXIT_FAILURE);

     }


               while (1){
                   system("cls");
                   CusInfo();

                  }

       }
int ATM::GoBack(){

cout<<"\n\n\n\n"<<setw(25)<<"1  Back"<<setw(40)<<"Cancel  2\n";
                BC=getch();
                while (BC!='1'&&BC!='2'){
                BC=getch ();
                }
          switch (BC){

       case '1':
          system("cls");
          return 0;
          break;

       case '2' :
         system("cls");
           return 1;
         break;

         }
}
void ATM::Language(){
    cout<<"\n\n"<<endl;
cout<<"         *********************************************************"<<endl;
cout<<"         *PLEASE SELECT THE LANGUGE OF YOU CHOICE                *"<< endl;
cout<<"         *                                                       *"<<endl;
cout<<"         *1. ENGLISH                                   2.AMHARIC *"<<endl;
cout<<"         *********************************************************"<<endl;


LN=getch();


while (LN!= '1'&& LN!='2'){
        LN=getch();
    }
system ("cls");
switch (LN){
case '1':
    cout<<"\n\n\n\n"<<setw(40)<<"YOUR SELECTED LANGUAGE IS CHANGED TO ENGLISH. \n\n\n PRESS ANY KEY TO CONTINUE."<<"\n\t\t\t";

    break;

case '2' :
    cout<<"\n\n\n\n"<<setw(40)<<"AMHARIC IS NOT CURRENTLY SUPPORTED SO THE DEFAULT LANGUAGE IS SELECTED.\n\n\n PRESS ANY KEY TO CONTINUE."<<"\n\t\t\t";

    break ;

}
getch();
system ("cls");
}
void ATM::Logs(string CardNUM, string Outcome){

 SYSTEMTIME X;
    GetLocalTime(&X);
    ofstream Output;

    Output.open("logs.txt", ios::app);
    Output<<Outcome<<endl;
    Output<<X.wDay<<"/"<<X.wMonth<<"/"<<X.wYear<<endl;
    Output<<X.wHour<<":";
    if(X.wMinute<10){ Output<<"0";}
    Output<<X.wMinute<<endl;
    Output<<CardNUM<<endl<<endl;
    Output.close();

}
