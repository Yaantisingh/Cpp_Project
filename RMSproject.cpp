#include <iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<stdio.h>
#include<conio.h>
int main();
using namespace std;
class User {
    string username;
    string password;
public:			 
void login();
void register_();
void read()
	{
		ifstream fin;
		fin.open("user_login.txt");
		fin>>username;
		cout<<username<<endl;
		fin>>password;
		cout<<password<<endl;
		fin.close();
	}
};
void User ::login() {
	int count=0;
	string name;
	char pass[4];
	system("CLS");
    cout << "Enter your username: ";
    cin >> name;
    cout << "Enter your 4 digit password: ";
    for(int i=0; i<4; i++)
    {
    	pass[i]=getch();
    	printf("*");
	}
 ifstream fin;
 fin.open("user_login.txt",ios::app);
	while(fin>>username>>password)
	{
		if (username == name && password == pass) 
		{
			count=1;
		}
	}
    fin.close();
     if(count==1)
	 cout<<"\nLogin successfull\nWelcome "<<name<<endl;
	 else
	 {
	 	cout<<"\nInvalid username or password\nPlease try again\n";
	 	main();
	 }
	 
	 class train{
	int tno;
	char tname[20];
	char source[15];
	char des[15];
	char days[15];
	char Atime[15];
	char Dtime[15];
	public:
	void get()
	{
		cout<<"enter train num";
		cin>>tno;
		cin.ignore();
		cout<<"enter train name";
		cin.getline(tname,19);
		cout<<"enter source";
		cin.getline(source,14);
		cout<<"enter source station arrival time";
		cin.getline(Atime,14);
		cout<<"enter destination";
		cin.getline(des,14);
		cout<<"enter destination station arrival time";
		cin.getline(Dtime,14);
		cout<<"enter days";
		cin>>days;
	}
	void show()
	{   cout<<"________________________________________________________________________________________________________________\n";
	    cout<<"Train num |Train name      |Src station Arr Time|Des Station Arr Time|   Days\n";
		cout<<tno<<"     "<<tname<<"      "<<source<<" "<<Atime<<"         "<<des<<" "<<Dtime<<"       "<<days<<"\n";
		cout<<"________________________________________________________________________________________________________________\n";
	}
	void store()
{
	ofstream fout;
	fout.open("trains.txt",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
}
void reads()
{
	ifstream fin;
	fin.open("trains.txt",ios::app|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		show();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
void search(int t)
{
	int flag=0;
	ifstream fin;
	fin.open("trains.txt",ios::app|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(tno==t)
		{
			show();
		flag++;
		}
		fin.read((char*)this,sizeof(*this));
	}
		if(flag==0)
	cout<<"Train not found";
	fin.close();
}
void search(char *c)
{
	int flag=0;
	ifstream fin;
	fin.open("trains.txt",ios::app|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(c,tname))
		{
			show();
			flag++;
		}
		fin.read((char*)this,sizeof(*this));
	}
	if(flag==0)
	cout<<"Train not found";
	fin.close();
}
void search(char *s,char *d)
{
	int flag=0;
	ifstream fin;
	fin.open("trains.txt",ios::app|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(s,source)&&!strcmp(d,des))
		{
			show();
			flag++;
		}
		fin.read((char*)this,sizeof(*this));
	}
	if(flag==0)
	cout<<"Train not found\n";
	fin.close();
}
};
static int seat= 1000;
class customer{
	char name[20];
	int age;
	char gender;
	long long int mobile;
	int tno;
	char tname[20];
	char source[15];
	char des[15];
	char board[15];
	string date;
	char seatpre;
	public:
	void get()
	{
		cout<<"Enter your name";
		fflush(stdin);
		cin.getline(name,19);
		cout<<"Enter your age";
		cin>>age;
		cout<<"Enter your gender";
		cin>>gender;
		cout<<"Enter your mobile number";
		cin>>mobile;
		cout<<"enter train number";
		cin>>tno;
		cin.ignore();
		cout<<"enter train name";
		cin.getline(tname,19);
		cout<<"enter your source station";
		cin.getline(source,14);
		cout<<"enter your destination station";
		cin.getline(des,14);
		cout<<"Enter boarding station";
		cin.getline(board,14);
		cout<<"Enter journey date";
		cin>>date;
		cout<<"Enter seat preference";
	    cin>>seatpre;
	}
	void show()
	{
		int pnr=rand();
		cout.width(10);
		cout<<"PNR: seat: Name:           Age: Gender: Mobile number: tno:   tname:           from:    to:        boarding: jdate:\n";
		cout<<pnr<<"   "<<seatpre<<"     ";
		cout<<name<<"  ";
		cout<<age<<"   ";
		cout<<gender<<"       ";
		cout<<mobile<<"     ";
		cout<<tno<<"  "<<tname<<" "<<source<<"  "<<des<<"  "<<board<<"  "<<date<<"\n\n";
	}	
};
class Ticket
{
    protected:
      int pnrNo;
      int trainNumber,seatNo;
      
    public:
      Ticket()
      {}
    void acceptTicketDetails(int pnrNo,int trainNumber,int seatNo)
    {
        this->pnrNo=pnrNo;
        this->trainNumber=trainNumber;
        this->seatNo=seatNo;
    }
    void Display()
    {
       cout<<"PNR Number : "<<pnrNo<<" \t";
       cout<<"Train Number : "<<trainNumber<<" \t";
       cout<<"Seat Number : "<<seatNo<<endl;
    }
};
class Food
{
     protected:
        int foodType;
        string date;
      public:
        Food()
		  {}
       void acceptFoodDetails(int foodType,string date)
      {
           this->foodType=foodType;
           this->date=date;
      }
       void Display()
      {
           if(foodType==1)
              cout<<"Food Type : VEG"<<endl;
           else if(foodType==2)
              cout<<"Food Type : NON VEG"<<endl;
              cout<<"Date: "<<date;
      }
};
static int vprice=500;
static int nvprice=700;
class Order:public Ticket,public Food
{
    protected:
       float bill;
       int quantity;
    public:
        Order()
           {}
     void acceptOrderDetails(int pnrNo,int trainNumber,int seatNo,int foodType,string date)
    {
           acceptTicketDetails(pnrNo,trainNumber,seatNo);
           acceptFoodDetails(foodType,date);
    }
    void Calulate_Bill()
    {
        cout<<"Enter Total no. of Plates : ";
        cin>>quantity;
        if(foodType==1)
             bill=quantity*vprice;
        else if(foodType==2)
             bill=quantity*nvprice;
        else
        {
            cout<<"Invalid Food Type : \n";
             bill=0;
        }
    }
    void Display()
    {
        Ticket::Display();
        Food::Display();
        cout<<"\nPrice Details : "<<endl;
        if(foodType==1)
        {
            cout<<"Plate : "<<vprice<<endl;
        }
        else
            cout<<"Plate : "<<nvprice<<endl;
            cout<<"Total Bill : "<<bill<<endl;
            cout<<"----------------------------------------------------------------------------------\n";
    }
};
class PaymentMethod {
    public:
        virtual void pay(double amount)=0;                            //pure virtual function  
};

class CreditCard : public PaymentMethod {
    private:
        string cardNumber;
        string expirationDate;
        string cvv;

    public:
        CreditCard(string cardNum, string expDate, string cvvNum) {
            cardNumber = cardNum;
            expirationDate = expDate;
            cvv = cvvNum;
        }

        void pay(double amount) {
            cout << "\nPaying " << amount << " using credit card ending with " << cardNumber.substr(cardNumber.length()-4) << endl;
        }
};

class DebitCard : public PaymentMethod {
    private:
        string cardNumber;
        string expirationDate;
        string cvv;

    public:
        DebitCard(string cardNum, string expDate, string cvvNum) {
            cardNumber = cardNum;
            expirationDate = expDate;
            cvv = cvvNum;
        }

        void pay(double amount) {
            cout << "\nPaying " << amount << " using debit card ending with " << cardNumber.substr(cardNumber.length() - 4) << endl;
        }
};

class PayPal : public PaymentMethod {
    private:
        string email;
        char password[20];

    public:
        PayPal(string e, char p[]) {
            email = e;
        strcpy(password,p);
        }

        void pay(double amount) {
            cout << "\nPaying " << amount << " using PayPal account " << email << endl;
        }
};
int z,i;
	int n;
	 double amount;
    int choice;
    Order obj;
    string date;
    int pnrNo,trainNumber,seatNo,typeofFood;
	customer C[20];
    int t;
	char c[20],s[15],d[15];
	train t1;
	customer T[20];
	 int l,y;
	 if(count==1)
	 {
	 	do{
	 		cout<<"Enter your choice from below\n";
    cout << "1. Search Train" << endl;
    cout << "2. Book Tickets" << endl;
    cout << "3. Order Food" << endl;
    cout << "4. Make payment" << endl;
    cout << "5. Exit" << endl;
    cin>>l;
	 switch(l)
	 {
	 	
	 	case 1:
	 	system("CLS");
	 	do{
	 	cout<<"Enter your choice from the given options\n";
	 	cout<<"1.Search train by num\n2.Search train by name\n3.Search train by source and destination\n4.Go to main menu\n";
	cin>>y;
	switch(y)
	{
		case 1:
			cout<<"Enter train number ";
			cin>>t;
			t1.search(t);
			break;
		case 2:
		    cout<<"Enter train name ";
		    fflush(stdin);
		    cin.getline(c,19);
			t1.search(c);
			break;
		case 3:
		    cout<<"Enter train source ";
		    fflush(stdin);
		    cin.getline(s,14);
		    cout<<"Enter train destination ";
		    fflush(stdin);
		    cin.getline(d,14);
			t1.search(s,d);
			break;
		case 4:
		    cout<<"Go to main menu";
			break;		
	}
}while(y!=4);
	 	break;
	 	case 2:
	 	system("CLS");
	cout<<"Press 1 for General class Price=50\n";
	cout<<"Press 2 for Sleeper class Price=400\n";
	cout<<"Press 3 for Third AC Price=1000\n";
	cout<<"Press 4 for Second AC Price=2000\n";
	cout<<"Press 5 for First AC Price=3000\n";
	cout<<"Select ticket type";
	cin>>z;
	cout<<"Enter the number of tickets you want to book";
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		C[i].get();
    }
cout<<"__________________________________________________Ticket Details__________________________________________________\n";
cout<<n<<" Tickets Booked\n";
            for(int i=0; i<n; i++)
	{
		C[i].show();
		cout<<"___________________________________________________________________________________________________________________\n";
    }
    seat=seat-n;
    cout<<"Number of seats left "<<seat<<endl;
    if(seat==0)
    {
    	cout<<"\nSORRY, BOOKING FULL";
	}
		switch(z)
	{
		case 1:
			cout<<"general\nprice 50\n";
			cout<<"Total price is "<<50*n<<endl;
			break;
			case 2:
			cout<<"sleeper\nprice 400\n";
			cout<<"Total price is "<<400*n<<endl;
			break;
			case 3:
			cout<<"Third AC\nprice 1000\n";
			cout<<"Total price is "<<1000*n<<endl;
			break;
			case 4:
			cout<<"Second AC\nprice 2000\n";
			cout<<"Total price is "<<2000*n<<endl;
			break;
			case 5:
			cout<<"First AC\nprice 3000\n";
			cout<<"Total price is "<<3000*n<<endl;
			break;
			default:
                cout << "Invalid choice!" << endl;
                break;
	}
	 		break;
	 	case 3:
    system("CLS");
    cout<<"Order FOOD option\n";
    cout<<"-------------------------------------\n";
    cout<<"Enter pnr Number : ";
    cin>>pnrNo;
    cout<<"Enter Train Number : ";
    cin>>trainNumber;
    cout<<"Enter Seat Number : ";
    cin>>seatNo;
    cout<<"Enter Date : ";
    cin>>date;
       cout<<"Enter FOOD Type\n";
       cout<<"------------------\n";
       cout<<" 1.Veg\n2.Non Veg\n";
       cin>>typeofFood;
       if(typeofFood==1 || typeofFood==2)
          {}
       else
          cout<<"Please Select Valid Food Option\n";
       obj.acceptOrderDetails(pnrNo,trainNumber,seatNo,typeofFood,date);
       obj.Calulate_Bill();
       cout<<"Order Placed SuccessFully\n";
       cout<<"Your Order Details Are : \n";
       cout<<"----------------------------------------------------------------------\n";
       obj.Display();
    
		 break;	
		 case 4:
		 	system("CLS");
    cout << "Enter amount to pay: ";
    cin >> amount;
PaymentMethod *pm;
    cout << "\nChoose a payment method:" << endl;
    cout << "1. Credit Card" << endl;
    cout << "2. Debit Card" << endl;
    cout << "3. PayPal" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        string cardNum, expDate;
        char cvvNum[3];
        cout << "Enter credit card number: ";
        cin >> cardNum;
        cout << "Enter expiration date (mm/yy): ";
        cin >> expDate;
        cout << "Enter CVV number: ";
        for(int i=0; i<3; i++)
        {
        cvvNum[i]=getch();
        printf("*");
		}
        CreditCard c(cardNum, expDate, cvvNum);
        pm=&c;
		pm->pay(amount);
    } else if (choice == 2) {
        string cardNum, expDate; 
		char cvvNum[3];
        cout << "Enter debit card number: ";
        cin >> cardNum;
        cout << "Enter expiration date (mm/yy): ";
        cin >> expDate;
        cout << "Enter CVV number: ";
        for(int i=0; i<3; i++)
        {
        cvvNum[i]=getch();
        printf("*");
		}
        
        DebitCard d(cardNum, expDate, cvvNum);
        pm=&d;
		pm->pay(amount);
    } else if (choice == 3) {
        string email;
        char password[3];
        cout << "Enter PayPal email: ";
        cin >> email;
        cout << "Enter PayPal password: ";
        for(int i=0; i<3; i++)
        {
        password[i]=getch();
        printf("*");
		}
		PayPal p(email,password);
		pm=&p;
		pm->pay(amount);
    }
		 break;
		 case 5:
		 cout<<"Go to main menu\n";
		 main();
		 break;	
	}
}while(l!=5);
}
}
void User :: register_()
	{
		int s;
			system("CLS");
		cout<<"Enter username";
    	cin>>username;
    	cout<<"Enter password";
    	cin>>password;
		ofstream fout("user_login.txt",ios::app);
		fout<<username<<" ";
		fout<<password<<endl;
		cout<<"Registration successfull\n";
		cout<<"Press 1 to login and continue\n";
		cout<<"Press 0 to go to main menu\n";
		cin>>s;
		switch(s)
		{
			case 1:
			    login();
			    break;
			case 0:
				main();
				break;
		}
}

int main() {
	int ch,t;
	char c[20],s[15],d[15];
	User u;
	int n;
	cout<<"**********************************************************************************************************************";
	cout<<"*                                                                                                                    *";
	cout<<"*                                                                                                                    *";
	cout<<"*                                           WELCOME TO INDIAN RAILWAYS                                               *";
	cout<<"*                                                                                                                    *";
	cout<<"*                                                                                                                    *";
	cout<<"**********************************************************************************************************************\n";
        cout << "1. Login as existing user" << endl;
        cout << "2. Register if new user" << endl;
        cout << "3. Exit" << endl;
        
        cin >> ch;

        switch (ch) {
            case 1:
                u.login();
                break;
            case 2:
                u.register_();
                break;
            case 3:
                cout<<"Exit\n";
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    return 0;
}

