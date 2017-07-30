#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

struct date
{
int d;
int m;
int y;
};


class account
{
  int acno,age;
  char g,gen,name[50],addr[50],numb[10];
  long deposit;
  char type;
  date dob;
public:
	void create_account(); //function to get data from user
	void show_account(); //function to show data on screen
	void modify(); //function to get new data from user
	void dep(int); //function to accept amount and add to balance amount
	void draw(int); //function to accept amount and subtract from balance amount
	void report(); //function to show data in tabular format
	int retacno(); //function to return account number
	int retdeposit();//function to return balance amount
	char rettype(); //function to return type of account
	int acntcheck(int);//function to check if account already exist
}b1;


void account::create_account()
{
	lb5:  cout<<"\nEnter The account No.:";
	     cin>>acno;

	     if(b1.acntcheck(acno)==0)
	      goto lb5;
	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(name);
       lba:cout<<"\n\nEnter The Age of The account Holder : ";
	cin>>age;
	if(age<5)
	{
	cout<<"sorry age criterion not match!\nperson should be above 5 years of age";
	goto lba;
	}

	cout<<"\n\nEnter The Address of The account Holder : ";
	gets(addr);
	ln:cout<<"\n\nEnter The Gender of The account Holder : ";
	cout<<"\n\n() Male (m) \n\n ()Female(f) ";
	cin>>(gen);
	g=toupper(gen);
	if(g=='M'|| g=='F')
	{
	if(g=='M')
	cout<<"\n\n(*) Male (m) \n\n()Female(f) ";
	else
	cout<<"\n\n() Male (m) \n\n (*)Female(f) ";
	}
	else goto ln;
       p:cout<<"\n\nEnter The Phone Number of The account Holder : ";
	gets(numb) ;
       if(isdigit(numb[0]))
       {}
       else
       {cout<<"invalid phone number!!";
       goto p;
       }
       cout<<"\n\t\t ENTER DATE OF BIRTH(dd/mm/yy) :";
int c=0;
while(!c)
{
cout<<"\n\t\t\t\t\t day : ";
cin>>dob.d;
if((dob.d>31)||(this->dob.d<1))
{
cout<<"\n\n THIS DATE DOES NOT EXIST,TRY AGAIN!!  ";
c=0;
}
else
c=1;
}
c=0;
while(!c)
{
cout<<"\n\t\t\t\t\t month : ";
cin>>dob.m;
if((dob.m>12)||(this->dob.m<1))
{
cout<<"\n\n THIS MONTH DOES NOT EXIST,TRY AGAIN!!  ";
c=0;continue;
}
else
c=1;

if((dob.d==31) &&((dob.m==2) || (dob.m==4) ||( dob.m==6) ||(dob.m==9) || (dob.m==11)))
{
cout<<"\n THIS MONTH DOES NOT HAVE 31 DAYS \n TRY AGAIN !!  ";
c=0;
}
else
c=1;
}

cout<<"\n\t\t\t\t\t year(in 4 digits) : ";
cin>>dob.y;

	lb3:cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	if(!(type=='S'||type=='C'))
	     goto lb3;
       lb:cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	if((deposit<500 && type=='S')||(deposit<1000 && type=='C'))
	goto lb;
	cout<<"\n\n\nAccount Created..";
}
int n_check (char arr[])
{
	int i=0;
	while (arr[i]!='\0')
	{
		if (((arr[i]>64)&&(arr[i]<92))||((arr[i]>95)&&(arr[i]<124))
		||(arr[i]==' '))
		{
			cout<<"\nINCORRECT INPUT. TRY AGAIN !!\n ";
			return 0;
		}
		else
		{i++;
		continue;

		}
	 }
	 return 1;
}
int account::acntcheck(int b)
{
	fstream  file;int a;
	int check=0;
	file.open("account.dat",ios::in|ios::ate);
	int q=file.tellg();
	int size=q/sizeof(account);
	file.seekg(0,ios::beg);
	for(int i=0;i<size;i++)
	{
		file.read((char*)this,sizeof(account));
		a=acno;
		if(b==a)
		{
			check+=1;
			break;
		}
	}
	if(check==0)
		{return(10);}
	else
	{
		cout<<"\n ACCOUNT ALREADY EXISTS!! "<<endl;

		return(0);
	}
	file.close();
}


void account::show_account()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nAge:"<<age;
	cout<<"\nAddress : ";puts(addr);
	cout<<"\nDate of Birth (dd/mm/yyyy) : "<<dob.d<<"/"<<dob.m<<"/"<<dob.y;
	cout<<"\nGender:";

     {
	if(g=='M')
	{
	cout<<"\n\n(*) Male (m) \n\n()Female(f) ";
	}
	else
	cout<<"\n\n() Male (m) \n\n (*)Female(f) ";

      }
	 cout<<"\n\nEnter The Phone Number of The account Holder : ";
       puts(numb) ;

	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}
void account::modify()
{
	cout<<"\nThe account No."<<acno;
	cout<<"\n\nEnter The Name of The account Holder ";
	gets(name);
	lba:cout<<"\n\nEnter The Age of The account Holder : ";
	cin>>age;
	if(age<5)
	{
	cout<<"sorry age criterion not match!\nperson should be above 5 years of age";
	goto lba;
	}

	cout<<"\n\nEnter The Address of The account Holder : ";
	gets(addr);
	ln:cout<<"\n\nEnter The Gender of The account Holder : ";
	cout<<"\n\n() Male (m) \n\n ()Female(f) ";
	cin>>(gen);
	g=toupper(gen);
	if(g=='M'|| g=='F')

       {
	if(g=='M')
	cout<<"\n\n(*) Male (m) \n\n()Female(f) ";
	else
	cout<<"\n\n() Male (m) \n\n (*)Female(f) ";
	}
	else goto ln;

       p:cout<<"\n\nEnter The Phone Number of The account Holder : ";
	gets(numb) ;
       if(isdigit(numb[0]))
       {}
       else
       {cout<<"invalid phone number!!";
       goto p;
       }
       cout<<"\n\t\t ENTER DATE OF BIRTH(dd/mm/yy) :";
int c=0;
while(!c)
{
cout<<"\n\t\t\t\t\t day : ";
cin>>dob.d;
if((dob.d>31)||(this->dob.d<1))
{
cout<<"\n\n THIS DATE DOES NOT EXIST,TRY AGAIN!!  ";
c=0;
}
else
c=1;
}
c=0;
while(!c)
{
cout<<"\n\t\t\t\t\t month : ";
cin>>dob.m;
if((dob.m>12)||(this->dob.m<1))
{
cout<<"\n\n THIS MONTH DOES NOT EXIST,TRY AGAIN!!  ";
c=0;continue;
}
else
c=1;

if((dob.d==31) &&((dob.m==2) || (dob.m==4) ||( dob.m==6) ||(dob.m==9) || (dob.m==11)))
{
cout<<"\n THIS MONTH DOES NOT HAVE 31 DAYS \n TRY AGAIN !!  ";
c=0;
}
else
c=1;
}

cout<<"\n\t\t\t\t\t year(in 4 digits) : ";
cin>>dob.y;

	lb4: cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	if(!(type=='S'||type=='C'))
	     goto lb4;
	lb2:cout<<"\nEnter The amount : ";
	cin>>deposit;
	if((deposit<500 && type=='S')||(deposit<1000 && type=='C'))
	goto lb2;
}
void account::dep(int x)
{
	deposit+=x;
}
void account::draw(int x)
{
	deposit-=x;
}
void account::report()
{
	cout<<acno<<setw(19)<<" "<<name<<setw(15)<<" "<<type<<setw(20)<<deposit<<endl;
}
int account::retacno()
{
	return acno;
}
int account::retdeposit()
{
	return deposit;
}
char account::rettype()
{
	return type;
}
void write_account(); //function to write record in binary file
void display_sp(int); //function to display account details given by user
void modify_account(int); //function to modify record of file
void delete_account(int); //function to delete record of file
void display_all(); //function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro(); //introductory screen function
int main()
{
	char ch; int num;char feed[12];char pword[12];
	clrscr();

       lb1:cout<<"\n\n\n\t ENTER YOUR USERNAME:"<<"\t" ;
	gets(feed);
	if(strcmpi("admin",feed)!=0)
	   goto lb1;
	cout<<"\n\t ENTER PASSWORD:"<<"\t";
	gets(pword);
	if(strcmpi("csproject",pword)!=0)
	  goto lb1;
	clrscr();
	intro();


	do
	{
		clrscr();
		cout<<"\n\n\n\nMAIN MENU";
		cout<<"\n\n\t01. CREATE NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT TO YOUR ACCOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT FROM YOUR ACCOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY OF YOUR ACCOUNT";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\t09. REDIRECT TO WELCOME PAGE";
		cout<<"\n\n\tSelect Your Option (1-9) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
			case '1': write_account();
				  break;

			case '2':
				 cout<<"\n\n\tEnter The account No. : ";
				 cin>>num;
				 deposit_withdraw(num, 1);
				 break;
			case '3':
				 cout<<"\n\n\tEnter The account No. : ";
				 cin>>num;
				 deposit_withdraw(num, 2);
				 break;
			case '4':
				 cout<<"\n\n\tEnter The account No. : ";
				 cin>>num;
				 display_sp(num);
				 break;
			case '5':
				 display_all();
					 break;
			case '6':
				 cout<<"\n\n\tEnter The account No. : ";
				 cin>>num;
				 delete_account(num);
				 break;
			case '7': cout<<"\n\n\tEnter The account No. : ";
				 cin>>num;
				 modify_account(num);
				 break;
			case '8': cout<<"\n\n\t\t\tThanks for using bank managemnt system";
				  break;
			case '9':goto lb1;
			default :cout<<"\a";
			}
			getch();
		}while(ch!='8');
		return 0;
}
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary | ios::app);
	ac.create_account();
	outFile.write((char *)&ac, sizeof(account));
	outFile.close();
}
void display_sp(int n)
{
	account ac;
	int flag=0;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
	cout<<"File could not be open !! Press any Key...";
	}

	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			cout<<"\nBALANCE DETAlLS\n";
			ac.show_account();
			flag=1;
		}
		inFile.close();
	}

	if(flag==0)
	  cout<<"\n\nAccount number does not exist";


}
void modify_account(int n)
{
	int found=0;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary | ios::in | ios::out);
	if(!File)
		cout<<"File could not be open !! Press any Key...";
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of Account : "<<endl;
			ac.modify();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	int flag=0;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
		cout<<"File could not be open N Press any Key...";
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char*)&ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		   {	outFile.write((char *) &ac,sizeof(account));


		    }
		 if(ac.retacno()==n)
		  {  cout<<"\n\t Record Deleted ";
		     flag=1;
		  }
	}

	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	if(flag==0)
	 cout<<"\n\t Record Not Found";


}
void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
		cout<<"File could not be open l! Press any Key...";
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"================================================================\n";
	cout<<"A/c no. 	    NAME      		Type        	Balance \n";
	cout<<"================================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{	ac. report();
	}
	inFile.close();
}
void deposit_withdraw(int n, int option)
{
	int amt;
	int found=0;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if(!File)
	 cout<<"File could not be open !! Press any Key...";
	while(File.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{

			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t TO DEPOSITE AMOUNT : ";
				cout<<"\n\n\tEnter the Amount to be Deposited : ";
				cin>>amt;
				ac.dep(amt);
				cout<<"\n\n\t Record Updated";
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT : ";
				cout<<"\n\nEnter the Amount to be Withdraw : ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"\n\t\tInsufficient Balance!!";
				else
				     {	ac.draw(amt);
					cout<<"\n\n\t Record Updated";
				     }
			}
			int pos=(-1)*sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *)&ac, sizeof(account));

			found=1;
		}
	}
	File.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
}
void intro()
{
	cout<<"\n\n\n\t\tTOPIC: BANK MANAGEMENT SYSTEM";

	cout<<"\n\n\n\n\t\tMADE BY :Kartik Ahuja";
	cout<<"\n\n\t\tClass:12";
	cout<<"\n\n\t\tRoll No.:25";
	cout<<"\n\n\t\tSCHOOL :DELHI PUBLIC SCHOOL";
	getch();
}
