#include <iostream>
#include <string>
using namespace std;

struct Booking{
    string Name;
    char Class;
    double Price;
};

  //Variables  For Admin
        bool KeepRunning=true;
        int classNum=3,MoveNum=3;
        char ClassArr[100]="ABC";
        string MoviesArr[100]={"Speed","Tede","Room 2007"};
        double PriceArr[100]={200,100,50};
    //Variable For User
        int NumberOfTickets=0;
        Booking ChairArr[500];

void AdminPanal();// This function runs when user chose to login as admin

void UserPanal();// This function runs when user chose to login as Basic user

void  EdditingClasses(); // This function for adding new Classes to your Theater

void EdditingMovies();// This function for adding new movies to your Theater

void bookingSystem();// this function for booking tickets and payment

void calcInformation();// this function calculating number of chairs left and income

void printTicketsIformation();//this function to print user information for admin


//To show The classes and movies u add

void printClasses();

void printMovies();


//this function to draw sets

void draw(char a);
int countclasschair(char a);//this is a helper function to calc number of taken sets in every class


int main()
{
    int Choice;
    while(KeepRunning==true){
        system("CLS");
		cout<<"\n\t\t-------------------------------------------";
		cout<<"\n\t\tWelcome To Theater Ticket management System";
		cout<<"\n\t\t-------------------------------------------";
		cout<<"\n\t\t\t login as admin or user !";
		cout<<"\n\n\t\t\t<1>For admin";
		cout<<"\n\t\t\t<2>For User";
		cout<<"\n\t\t\t<3>Logout ";
		cout<<"\n\n\t\t\t Enter Your Choice :"<<"\t";
		cin>>Choice;
    if(Choice==1){
        AdminPanal();
    }
    else if(Choice==2){
        UserPanal();
    }else if(Choice==3){
        KeepRunning=false;
    }
    else {
        //documentation here  stackoverflow.com/questions/68069674/how-to-control-input-in-c
        cin.clear();
        cin.ignore(100,'\n');//This line cuz.. if user enterd a different type of information
        cout <<"\n\n -- This is not a choice!! --\n\n"<<endl;
        //KeepRunning=false;
        system("pause");
    }

    }//end while
    return 0;
}
/*
    important!

    - all while loops u will find in functions its for keep Function runing until user Exit
    - n variable

*/
void AdminPanal(){
    bool KeepAdminPanalRuning=true;
    string nUsername="Admin",nPassword = "m5533";
    int n=0;
                system("CLS");
		cout<<"\n\t\t----------------------------------";
		cout<<"\n\t\t Welcome To Admin panal";
		cout<<"\n\t\t----------------------------------";
		cout<<"\n\t\t\t plaease Enter Your Username: ";
        cin >> nUsername;
        cout<<"\n\t\t\t  plaease Enter Your Password: ";
        cin >> nPassword;
        while(KeepAdminPanalRuning==true){
        if (nPassword=="m5533" && nUsername=="Admin"){
                system("CLS");
        cout<<"\n\t\t----------------------------------";
		cout<<"\n\t\t---------- Admin panal -----------";
		cout<<"\n\t\t----------------------------------";
		cout<<"\n\t\t\t Chose what to be edited?";
		cout<<"\n\n\t\t\t<1>To Edit Movielist";
		cout<<"\n\t\t\t<2>To Edit Classes";
		cout<<"\n\t\t\t<3>To Edit All";
		cout<<"\n\t\t----------------------------------";
		cout<<"\n\t\t\t Chose what to Print? \n\n";
		cout<<"\n\t\t\t<4>To Print all calculations";
		cout<<"\n\t\t\t<5>To Print List of Ticket Information";
		cout<<"\n\t\t----------------------------------";
        cout<<"\n\t\t\t<6>To Show Sets";
		cout<<"\n\n\n\t\t\t<0>logout admin panal";
		cout<<"\n\n\t\t\t Enter Your Choice :"<<"\t";
		cin >>n;
		cin.clear();
            if (n==1){
                EdditingMovies();
            }else if(n==2){
                EdditingClasses();
            }else if (n==3){
                EdditingMovies();
                EdditingClasses();
            }else if(n==4){
                calcInformation();
                system("pause");
            }else if(n==5){
                printTicketsIformation();
                system("pause");
            }else if(n==0){
                KeepAdminPanalRuning=false;
            }

            else if(n==6){
                    KeepAdminPanalRuning=true;
            while(KeepAdminPanalRuning==true){
                    int selection;
                system("cls");
                cout<<"Choose class to draw"<<endl;
                printClasses();
                cout<<"0. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>> selection;
                if(selection==0){
                   break;
                }
                draw(ClassArr[selection-1]);
                system("pause");
            }
            }


            else {
                cout << "This is not a Choice!! \n\n"<<endl;
                KeepAdminPanalRuning=false;
                system("pause");
            }

        }

        else {
        cout <<"Wrong Username or Password \n\n"<<endl;
        KeepAdminPanalRuning=false;
        system("pause");
        }
        }//end while
}



void UserPanal(){
         int n=0;
        bool KeepUserpanalRunning=true;
    while(KeepUserpanalRunning==true){
             system("CLS");
        cout<<"\n\t\t----------------------------------";
		cout<<"\n\t\t----------- User panal -----------";
		cout<<"\n\t\t----------------------------------";
		cout<<"\n\n\t\t\t<1>For Movies";
		cout<<"\n\t\t\t<2>For Classes";
		cout<<"\n\t\t\t<3>For print all";
		cout<<"\n\t\t\t<4>Book A Ticket";
		cout<<"\n\t\t\t<5>Logout user panal";
		cout<<"\n\n\t\t\t Enter Your Choice :"<<"\t";
		cin>>n;
		   if(n==2){
            printClasses();
            } else if (n==1){
            printMovies();
            }else if (n==3){
            printMovies();
            printClasses();
            }else if(n==4){
                bookingSystem();
            }else if(n==5){
                KeepUserpanalRunning=false;
            }
            else {
                    cin.clear();   //documentation here  stackoverflow.com/questions/68069674/how-to-control-input-in-c
                    cin.ignore(100,'\n');//This line cuz.. if user enterd a different type of info
                    cout <<"Wrong Choice!!"<<endl;
            }

            system("pause");
    }
}
/// start classes
void  EdditingClasses(){
    system("CLS");
    char Alpha[]="ABCDEFGHI";
    cout <<"How Many classes in your theater? "<<endl;
    cin >>classNum;
    if(classNum<=9){
    for(int i=0;i<classNum;i++){
        cout <<"Enter Class "<<Alpha[i]<<" Price : ";
        ClassArr[i]=Alpha[i];
        cin >> PriceArr[i];
    }}
    else{
            cout <<"Error So many classes!!"<<endl;
            system("pause");

    }
}

void printClasses(){
        for(int i=0;i<classNum;i++){
            cout<<i+1<<". Class "<< ClassArr[i] <<" Price "<<PriceArr[i]<<"$"<<endl;
            }
}
/// End Classes

/// Start Movies
void EdditingMovies(){

    system("CLS");
    char x;
    cout<<"Do u want to edit Movielist ?(y/n)"<<endl;
    cin>>x;
    if(x=='y'||x=='Y'){
        cout <<"How many movies to add ?"<<endl;
        cin >> MoveNum;
        cin.ignore(100, '\n');// there is a newline remaining then the newline will be assigned to MoviesArr[0]
        for(int i=0;i<MoveNum;i++){
            cout<<"Enter move number "<< i+1 <<" : "<<endl;
            getline(cin,MoviesArr[i]);
        }

    }else if(x=='n'||x=='N'){
        cout <<"Ok Lets continue "<<endl;
        system("pause");
    }else {
        cout <<"Wrong Choice!!";
        system("pause");
    }
}

void printMovies(){
        for(int i=0;i< MoveNum;i++){
            cout <<"Movie "<<i+1<<" Is "<<MoviesArr[i]<<endl;
            }
}
/// End Movies

void bookingSystem(){
    int NumOFClass=0,Current_Ticket=0,i=0,Counter=0;
    double mony=0,TotalPrice;
    bool GetError;
    string TicketName[500];
        system("CLS");
        cout<<"\n\t\t----------------------------------";
        cout<<"\n\t\t--------- Booking system ---------";
        cout<<"\n\t\t----------------------------------";
        cout<<"\n\n\t\t\tChose a Class \n\n";
        printClasses();
        cout<<"\n\n\t\t\t Enter Your Choice :"<<"\t";
        cin>>NumOFClass;
        if(NumOFClass<=classNum){

             GetError=true;
            while(GetError==true){
            cout<<"\n\t Enter Number of Tickets u want :";
            cin>>Current_Ticket;
            if(Current_Ticket>10){
                cout<<"You can't take more that 10 sets once"<<endl;
            }else{GetError=false;}
            }


            TotalPrice= Current_Ticket*PriceArr[NumOFClass-1];//total price user have to pay
            cout<<"You will pay "<< TotalPrice<<"$ :  ";
            cin >>mony;
            if(mony>=TotalPrice){

                    if(mony>TotalPrice){
                        cout<<"Thank you and here is your change "<<mony-TotalPrice<<"$ \n\n"<<endl;
                    }else{
                        cout<<"Thank you\n\n"<<endl;
                    }


            cin.ignore(100,'\n');// to clear line before the next loop cin


            for(int j=0;j<Current_Ticket;j++){

                 GetError=true;

                  while(GetError==true)  //This for Keep asking for the right name
                  {

                cout <<"Enter Name For Ticket "<<j+1<<" : ";
                getline(cin,TicketName[j]);

                if( TicketName[j][3]=='\0' ){

                    cout <<"\n Please enter a valid name \n"<<endl;

                }
                else{

                    GetError=false;

                }

                  }


            }
            for(i=NumberOfTickets;i<(Current_Ticket+NumberOfTickets);i++){
                    ChairArr[i].Name=TicketName[Counter];
                    ChairArr[i].Class=ClassArr[NumOFClass-1];
                    ChairArr[i].Price=PriceArr[NumOFClass-1];
                    Counter++;
            }
            NumberOfTickets+=Current_Ticket;
            draw(ClassArr[NumOFClass-1]);
        }else{
            cout<<"not enough! please try again"<<endl;
             cin.clear();
             cin.ignore(100,'\n');
        }
        }
        else{
            cout<<"This is not a choice!!"<<endl;
            cin.clear();
            cin.ignore(100,'\n');
        }

}

void printTicketsIformation(){
    if(NumberOfTickets==0){
            cout<<"There is No Tickets for Today To Print! "<<endl;

    }else if(NumberOfTickets>0){
        for(int i=0;i<NumberOfTickets;i++){
                cout<<i+1<<". Name: "<<ChairArr[i].Name<<endl;
                cout<<"   Class: "<<ChairArr[i].Class<<endl;
                cout<<"   Price: "<<ChairArr[i].Price<<"\n---------------------------------\n";
            }
    }
}

void calcInformation(){
    double sumOfTickets;
    if(NumberOfTickets==0){
            cout<<"There is No Tickets for Today! "<<endl;
    }
    else if(NumberOfTickets>0){
    for(int i=0;i<NumberOfTickets;i++){
        sumOfTickets+=ChairArr[i].Price;
    }
        cout<<"\n\t\t----------------------------------";
        cout<<"\n\t\t------- Ticket Information -------";
        cout<<"\n\t\t----------------------------------";
        cout<<"\n\n\t\t\t --Total income: "<<sumOfTickets<<"$\n";
        cout<<"\n\n\t\t\t --Number Of Taken Chairs: "<<NumberOfTickets<<"\n";
        cout<<"\n\n\t\t\t --Number Of Chairs Available: "<<500-NumberOfTickets<<"\n\n";
    }
}

void draw(char a){
    int counter=0;
    cout<<"\n\tClass "<<a<<" Sets \t\t\t\t\t\n\n"<<endl;
    int taken_sets= countclasschair(a);//to calculate number of taken sets in single class
    for (int i=0;i<(500/classNum);i++){
            if( counter==10 ){
                cout<<"\n";
                counter=0;
            }
            if(i<taken_sets){
                cout<<" X ";
            }
            else {
                cout<<" O ";
            }
            counter++;
    }
    cout<<"\n\n";
}
int countclasschair(char a){

int counter_class=0;

for(int i=0;i<NumberOfTickets;i++){

    if(ChairArr[i].Class==a){
        counter_class++;
    }

}
return counter_class;
}
