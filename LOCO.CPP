/*---------------------------------------------------------------------------
		LOCO : CAB BOOKING AND MANAGEMENT SYSTEM

	THIS PROGRAM HAS BEEN DEVELOPED BY HEMANG SINHA	AS THE A COMPUTER 
	SCIENCE PROJECT FOR CLASS XII UNDER THE SUPERVISION OF MY RESPECTED
	TEACHERS Mr. ASHOK KUMAR GOEL AND Mrs. KARUNA AMIT KUNDU.
----------------------------------------------------------------------------*/
					//ESSENTIAL HEADER FILES
#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>

#define locality_no_del 5

					 //PROTOTYPE OF FUNCTIONS USED
void loading_scr (void);
int username_chk (char[], int);
int password_chk (char[], int);
void passwordinput (char[]);
void mobinput (int[]);
void admin_entry (void);
int  intro_scr (void);
void feedback (void);
char bookcab (void);
void contact_us (void);
void create_acc (void);
void about_us (void);
int mobcompare (int [], int []);
void admin (void);
void user (void);
void info (int, int);
int  ret_no (char);
void locality_name (void);
void carcd (int, int);
int  delhi (void);
int  mumbai (void);
					 //STRUCTURES, CLASSES AND OBJECTS USED
ofstream fout;
ifstream fin;
fstream f;

struct date today;
struct time today_time;

struct address
{
	char add_l1[20], add_l2[20];
	char city[20], state[20];
};

struct ride
{
	date ridedate;
	int flag;
	char pick[3], drop[3];
};

class driver
{
	private:
		char name[20], cabno[12], gender, code[6];
		int mob[10];
		address dvr_add;

	public:
		char* retcode ()
		{
			return code;
		}
		char* retcodeuser ();
		void show ();
		void showuser ();
		void newdriver (void)
		{
			clrscr();
			gotoxy(20, 10);
			cout<<"ENTER DRIVER NAME : ";
			gotoxy(20, 11);
			cout<<"ENTER DRIVER CODE : ";
			gotoxy(20, 12);
			cout<<"GENDER (M / F) : ";
			gotoxy(20, 13);
			cout<<"ENTER DRIVER'S CONTACT NUMBER (MOBILE) : ";
			gotoxy(20, 14);
			cout<<"DRIVER'S ADDRESS INFORMATION";
			gotoxy(25, 15);
			cout<<"ADDRESS LINE 1 : ";
			gotoxy(25, 16);
			cout<<"ADDRESS LINE 2 : ";
			gotoxy(25, 17);
			cout<<"CITY : ";
			gotoxy(25, 18);
			cout<<"STATE : ";
			gotoxy(25, 19);
			cout<<"ENTER CAB NUMBER : ";

			gotoxy(40, 10);
			gets(name);
			gotoxy(40, 11);
			gets(code);
			gotoxy(37, 12);
			cin>>gender;
			gotoxy(57, 13);
			mobinput(mob);
			gotoxy(42, 15);
			gets(dvr_add.add_l1);
			gotoxy(42, 16);
			gets(dvr_add.add_l2);
			gotoxy(32, 17);
			gets(dvr_add.city);
			gotoxy(33, 18);
			gets(dvr_add.state);
			gotoxy(43, 19);
			gets(cabno);
		}

		void showtable (int ctr)
		{
			gotoxy(15, ctr+1);
			cout<<ctr;
			gotoxy(21, ctr+1);
			puts(name);
			gotoxy(38, ctr+1);
			puts(cabno);
		}
}dvr1;

void driver :: showuser ()
{
	clrscr();
	gotoxy(35, 12);
	cout<<"DRIVER INFORMATION";
	gotoxy(35, 13);
	cout<<"==================";
	gotoxy(30, 15);
	cout<<"NAME : ";
	gotoxy(30, 16);
	cout<<"MOBILE NO. : ";
	gotoxy(30, 17);
	cout<<"CAR NUMBER : ";

	gotoxy(37, 15);
	puts(name);
	gotoxy(43, 16);
	for(int i=0;i<10;i++)
		cout<<mob[i]-48;
	gotoxy(43, 17);
	puts(cabno);
	getch();
}

void driver :: show ()
{
	gotoxy(20, 10);
	cout<<"DRIVER NAME : ";
	gotoxy(20, 11);
	cout<<"DRIVER CODE : ";
	gotoxy(20, 12);
	cout<<"GENDER : ";
	gotoxy(20, 13);
	cout<<"DRIVER'S CONTACT NUMBER (MOBILE) : ";
	gotoxy(20, 14);
	cout<<"DRIVER'S ADDRESS INFORMATION";
	gotoxy(25, 15);
	cout<<"ADDRESS LINE 1 : ";
	gotoxy(25, 16);
	cout<<"ADDRESS LINE 2 : ";
	gotoxy(25, 17);
	cout<<"CITY : ";
	gotoxy(25, 18);
	cout<<"STATE : ";
	gotoxy(20, 19);
	cout<<"CAB NUMBER : ";

	gotoxy(38, 10);
	puts(name);
	gotoxy(47, 11);
	cout<<code;
	gotoxy(37, 12);
	cout<<gender;
	gotoxy(57, 13);
	for(int i=0;i<10;i++)
		cout<<mob[i]-48;
	gotoxy(42, 15);
	puts(dvr_add.add_l1);
	gotoxy(42, 16);
	puts(dvr_add.add_l2);
	gotoxy(32, 17);
	puts(dvr_add.city);
	gotoxy(33, 18);
	puts(dvr_add.state);
	gotoxy(33, 19);
	puts(cabno);
}

char* driver :: retcodeuser ()
{
	randomize();
	fin.open("drivers.dat", ios::binary|ios::in);
	int m = random(5)*sizeof(dvr1);
	fin.seekg(m);
	fin.read((char *)&dvr1, sizeof(dvr1));
	fin.close();
	return dvr1.retcode();
}

class users
{
	private:
		char name[20], username[20];
		char dvrcode[6];
		char password[20], confpassword[20];
		int mob[10];
		ride lastride;

	public:
		users()
		{
			lastride.flag=0;
		}
		int ret_ride_flag()
		{
			return lastride.flag;
		}
		void get_ride_flag(int t)
		{
			lastride.flag=t;
		}
		char* retusername()
		{
			return username;
		}
		void getmob (char ch, int m)
		{
			mob[m]=ch;
		}
		char* retpass()
		{
			return password;
		}
		void getdvrcode ()
		{
			strcpy(dvrcode, dvr1.retcodeuser());
		}
		char* retdvrcode ()
		{
			return dvrcode;
		}
		int* retmob (void)
		{
			return mob;
		}
		void updatepass(char pass[])
		{
			strcpy(password, pass);
		}
		void show();
		void showtable (int);
		void newuser (void)
		{
			clrscr();
			gotoxy(20, 10);
			cout<<"ENTER YOUR NAME : ";
			gotoxy(20, 11);
			cout<<"ENTER YOUR CONTACT NUMBER (MOBILE) : ";
			gotoxy(20, 12);
			cout<<"ENTER A USERNAME : ";
			gotoxy(20, 13);
			cout<<"ENTER A PASSWORD : ";
			gotoxy(20, 14);
			cout<<"CONFIRM PASSWORD : ";

			gotoxy(38, 10);
			gets(name);
			gotoxy(57, 11);
			mobinput(mob);
			gotoxy(39, 12);
			gets(username);
			gotoxy(39, 13);
			passwordinput(password);
			gotoxy(39, 14);
			passwordinput(confpassword);
			if(strcmp(password, confpassword))
			{
				clrscr();
				gotoxy(20, 20);
				cout<<"PASSWORD AND CONFIRMATION";
				cout<<" PASSWORD DONOT MATCH!";
				delay(2000);
				newuser();
			}
		}

		void get_ride(int d, int m, int y)
		{
			lastride.ridedate.da_day=d;
			lastride.ridedate.da_mon=m;
			lastride.ridedate.da_year=y;
		}

		void ret_ride()
		{
			gotoxy(30, 12);
			cout<<"JOURNY DATE : ";
			cout<<int(lastride.ridedate.da_day)<<"/ ";
			cout<<int(lastride.ridedate.da_mon)<<"/ ";
			cout<<lastride.ridedate.da_year<<endl;
			gotoxy(30, 14);
			cout<<"PICK UP LOCATION : "<<lastride.pick;
			gotoxy(30, 15);
			cout<<"DROP LOCATION : "<<lastride.drop;
		}

		void getlocation(char p[], char d[])
		{
			strcpy(lastride.pick, p);
			strcpy(lastride.drop, d);
		}
}usr1;

void users::showtable (int ctr)
{
	gotoxy(15, ctr+1);
	cout<<ctr;
	gotoxy(21, ctr+1);
	puts(name);
	gotoxy(38, ctr+1);
	for(int i=0;i<10;i++)
		cout<<mob[i]-48;
}

void users::show ()
{
	clrscr();
	gotoxy(20, 10);
	cout<<"NAME : ";
	gotoxy(20, 11);
	cout<<"CONTACT NUMBER (MOBILE) : ";
	gotoxy(20, 12);
	cout<<"USERNAME : ";
	gotoxy(20, 20);
	gotoxy(27, 10);
	puts(name);
	gotoxy(46, 11);
	for(int i=0;i<10;i++)
		cout<<mob[i]-48;
	gotoxy(31, 12);
	puts(username);
}

class employee
{
	private:
		char name[20], gender, username[20];
		char password[20], confpassword[20];
		unsigned long long code;
		int mob[10];
		address emp_add;

	public:
		unsigned long long retcode (void)
		{
			return code;
		}
		char* retusername()
		{
			return username;
		}
		char* retpassword()
		{
			return password;
		}
		int* retmob (void)
		{
			return mob;
		}
		void updatepass(char pass[])
		{
			strcpy(password, pass);
		}
		void show();
		void newemp (void)
		{
			clrscr();
			gotoxy(20, 10);
			cout<<"ENTER YOUR NAME : ";
			gotoxy(20, 11);
			cout<<"ENTER YOUR EMPLOYEE CODE : ";
			gotoxy(20, 12);
			cout<<"GENDER (M / F) : ";
			gotoxy(20, 13);
			cout<<"ENTER YOUR CONTACT NUMBER (MOBILE) : ";
			gotoxy(20, 14);
			cout<<"ADDRESS INFORMATION";
			gotoxy(25, 15);
			cout<<"ADDRESS LINE 1 : ";
			gotoxy(25, 16);
			cout<<"ADDRESS LINE 2 : ";
			gotoxy(25, 17);
			cout<<"CITY : ";
			gotoxy(25, 18);
			cout<<"STATE : ";
			gotoxy(20, 19);
			cout<<"ENTER A USERNAME : ";
			gotoxy(20, 20);
			cout<<"ENTER A PASSWORD : ";
			gotoxy(20, 21);
			cout<<"CONFIRM PASSWORD : ";

			gotoxy(38, 10);
			gets(name);
			gotoxy(47, 11);
			cin>>code;
			gotoxy(37, 12);
			cin>>gender;
			gotoxy(57, 13);
			mobinput(mob);
			gotoxy(42, 15);
			gets(emp_add.add_l1);
			gotoxy(42, 16);
			gets(emp_add.add_l2);
			gotoxy(32, 17);
			gets(emp_add.city);
			gotoxy(33, 18);
			gets(emp_add.state);
			gotoxy(39, 19);
			gets(username);
			gotoxy(39, 20);
			passwordinput(password);
			gotoxy(39, 21);
			passwordinput(confpassword);
			if(strcmp(password, confpassword))
			{
				clrscr();
				gotoxy(20, 20);
				cout<<"PASSWORD AND CONFIRMATION";
				cout<<" PASSWORD DONOT MATCH!";
				getch();
				newemp();
			}
			clrscr();
		}

		void showtable (int ctr)
		{
			gotoxy(15, ctr+1);
			cout<<ctr;
			gotoxy(21, ctr+1);
			puts(name);
			gotoxy(38, ctr+1);
			cout<<code;
		}
}emp1;

void employee::show ()
{
	gotoxy(20, 10);
	cout<<"NAME : ";
	gotoxy(20, 11);
	cout<<"EMPLOYEE CODE : ";
	gotoxy(20, 12);
	cout<<"GENDER : ";
	gotoxy(20, 13);
	cout<<"CONTACT NUMBER (MOBILE) : ";
	gotoxy(20, 14);
	cout<<"ADDRESS INFORMATION";
	gotoxy(25, 15);
	cout<<"ADDRESS LINE 1 : ";
	gotoxy(25, 16);
	cout<<"ADDRESS LINE 2 : ";
	gotoxy(25, 17);
	cout<<"CITY : ";
	gotoxy(25, 18);
	cout<<"STATE : ";
	gotoxy(20, 19);
	gotoxy(27, 10);
	puts(name);
	gotoxy(36, 11);
	cout<<code;
	gotoxy(29, 12);
	cout<<gender;
	gotoxy(46, 13);
	for(int i=0;i<10;i++)
	cout<<mob[i]-48;
	gotoxy(42, 15);
	puts(emp_add.add_l1);
	gotoxy(42, 16);
	puts(emp_add.add_l2);
	gotoxy(32, 17);
	puts(emp_add.city);
	gotoxy(33, 18);
	puts(emp_add.state);
}

struct city
{
	char locality[4];
	int available;
	int carcd;
}del_city[locality_no_del][locality_no_del];

					 //GLOBAL VARIABLES TO BE USED
char username[30], password[30], testpassword[30]="hemang", bookadd[4];
int jdate, jhr1, jhr2, jhr, jmin;
int user_choice, user_flag=0, admin_flag=0, lflag, flag, mob[10];

void main()
{
	clrscr();

	int menu_choice;
	char user_return, admin_return, abt_return, feeb_return, cacc_return;
	textcolor(GREEN);
	loading_scr();                    //LOADING SCREEN APPEARS

	getch();

	menu_ch:clrscr();
		menu_choice = intro_scr();
		switch(menu_choice)
		{
			case 1: user_flag=1;
				admin_entry();
				if(username_chk(username, 1) == 1&& password_chk(password, 1) == 1)
					user();
				else
				{
					clrscr();
					gotoxy(30, 12);
					cout<<"INVALID USERNAME / PASSWORD.";
					delay(2500);
					goto menu_ch;
				}
				user_return = 'y';
			break;

			case 2: admin_flag = 1;
				admin_entry();
				if((username_chk(username, 2) == 1) && password_chk(password, 2) == 1)
					admin();
				else
				{
					clrscr();
					gotoxy(30, 12);
					cout<<"INVALID USERNAME / PASSWORD.";
					delay(2500);
					goto menu_ch;
				}
				admin_return = 'y';
			break;
						    //SWITCH CASE FOR USER'S CHOICE
			case 3: create_acc();
				cacc_return = 'y';
			break;

			case 4: feedback();
				feeb_return = 'y';
			break;

			case 5: about_us();
				abt_return = 'y';
			break;

			case 6: clrscr();
				exit(0);

			default:gotoxy(34, 20);
				cout<<"INVALID INPUT!";
				delay(2500);
				goto menu_ch;
		}
		if(user_return=='y'||admin_return=='y'||abt_return=='y'||feeb_return=='y'||cacc_return=='y')
		{
			user_return = admin_return = 'n';
			abt_return = feeb_return = cacc_return = 'n';
			goto menu_ch;
		}
	getch();
}

void loading_scr ()                                 //LOADING SCREEN FUNCTION
{
	textcolor(GREEN);
	int x=0;
						    //LOGO PRINTING

	cout<<"                                *........* "<<endl;
	cout<<"                         	.......... "<<endl;
	cout<<"                         	..      .. "<<endl;
	cout<<"                         	..^^    .. "<<endl;
	cout<<"                         	..^^    .. "<<endl;
	cout<<"                         	..^^    .. "<<endl;
	cout<<"                         	..^^    .. "<<endl;
	cout<<"                         	..^^^^^^.. "<<endl;
	cout<<"                         	..^^^^^^.. "<<endl;
	cout<<"                         	.......... "<<endl;
	cout<<"                                *........* "<<endl;
	cout<<endl<<"                                    LOCO"<<endl;
	cout<<"                       A CAB BOOKING AND MANAGEMENT SYSTEM";
	delay(2500);
	clrscr();

	gotoxy(30,13);
	cout<<"LOADING...";

	for(int i=1; i<=10; i++)
	{
		gotoxy(30+x,14);
		delay(500);

		cout<<"__";
		x+=2;

		gotoxy(52,14);
		cout<<i*10<<"%";
	}

	gotoxy(35,17);
	cout<<"COMPLETE!";

	gotoxy(50,21);
	cout<<"PRESS ANY KEY TO CONTINUE";

}

int username_chk (char usn[20], int mode)
{
	int flag;
	if(mode == 1)
	{
		fin.open("users.dat", ios::binary | ios::in);
		fin.seekg(0, ios::end);
		if(fin.tellg()==0)
		{
			fin.close();
			return 0;
		}
		fin.seekg(0, ios::beg);
		while(fin.read((char *)&usr1, sizeof(usr1)))
		{
			if(strcmp(usr1.retusername(), usn)==0)
			{
				flag = 1;
				break;
			}
			else
				flag = 0;
		}
		fin.close();

		if(flag == 0)
			return 0;
		else
			return 1;
	}
	else
	{
		fin.open("employees.dat", ios::binary | ios::in);
		fin.seekg(0, ios::end);
		if(fin.tellg()==0)
		{
			fin.close();
			return 0;
		}
		fin.seekg(0, ios::beg);
		while(fin.read((char *)&emp1, sizeof(emp1)))
		{
			if(strcmp(emp1.retusername(), usn)==0)
			{
				flag = 1;
				break;
			}
			else
				flag = 0;
		}
		fin.close();

		if(flag == 0)
			return 0;
		else
			return 1;
	}
}

int password_chk (char pass[20], int mode)
{
	int flag;
	if(mode == 1)
	{
		if(strcmp(usr1.retpass(), pass)==0)
		{
			flag = 1;
		}
		else
			flag = 0;

		if(flag == 0)
			return 0;
		else
			return 1;
	}
	else
	{
		if(strcmp(emp1.retpassword(), pass)==0)
		{
			flag = 1;
		}
		else
			flag = 0;

		if(flag == 0)
			return 0;
		else
			return 1;
	}
}

void passwordinput (char pass[20])
{
	char ch;
	int i=0;

	while(1)
	{
		ch = getch();

		if(ch == 13) //ASCII VALUE (ENTER)
		{
			pass[i]='\0';
			break;
		}

		if(ch == 8)//ASCII VALUE (BACKSPACE)
			if(i>0)
			{
				i--;
				cout<<"\b \b";
			}

		if (ch == 9 || ch == 32)//ASCII VALUE (TAB || SPACE)
			continue;
		else
			if(isalpha(ch) || isdigit(ch) || isalnum(ch))
			{
				cout<<"*";
				pass[i] = ch;
				i++;
			}
	}

}

void mobinput (int mob[10])
{
	for(int i=0; i<10; i++)
	{
		while(1)
		{
			char ch = getch();
			if(ch == 13) //ASCII VALUE (ENTER)
			{
				mob[i]='\0';
				break;
			}
			if(ch == 8)//ASCII VALUE (BACKSPACE)
				if(i>0)
				{
					i--;
					cout<<"\b \b";
				}
			if (ch == 9 || ch == 32)//ASCII VALUE (TAB || SPACE)
				continue;
			else
				if(isdigit(ch))
				{
					cout<<ch;
					mob[i] = ch;
					usr1.getmob(ch, i);
					i++;
				}
		}
	}
}

void bookmobinput (int mob[10])
{
	mob_no:
	clrscr();
	gotoxy(16, 10);
	cout<<"PLEASE ENTER YOUR MOBILE NUMBER : +91 - ";
	for(int i=0; i<10; i++)
	{
		while(1)
		{
			char ch = getch();
			if(ch == 13) //ASCII VALUE (ENTER)
			{
				mob[i]='\0';
				break;
			}
			if(ch == 8)//ASCII VALUE (BACKSPACE)
				if(i>0)
				{
					i--;
					cout<<"\b \b";
				}
			if (ch == 9 || ch == 32)//ASCII VALUE (TAB || SPACE)
				continue;
			else
				if(isdigit(ch))
				{
					cout<<ch;
					mob[i] = ch;
					usr1.getmob(ch, i);
					i++;
				}
		}
	}
	cout<<endl;
	if(mob[0]=='0')
	{
		gotoxy(30, 12);
		cout<<"INVALID INPUT";
		delay(1500);
		goto mob_no;
	}

	if(!(i==11))
	{
		gotoxy(30, 12);
		cout<<"INVALID INPUT";
		delay(1500);
		goto mob_no;
	}
}

void admin_entry()                          //FUNCTION FOR USERNAME AND PASSWORD
{
	char ch;
	int i=0;

	clrscr();

	gotoxy(30, 12);
	cout<<"USERNAME : ";

	gotoxy(30, 13);
	cout<<"PASSWORD : ";

	gotoxy(41, 12);
	gets(username);

	gotoxy(41, 13);
	while(1)
	{
		ch = getch();

		if(ch == 13) //ASCII VALUE (ENTER)
		{
			password[i]='\0';
			break;
		}

		if(ch == 8)//ASCII VALUE (BACKSPACE)
			if(i>0)
			{
				i--;
				cout<<"\b \b";
			}

		if (ch == 9 || ch == 32)//ASCII VALUE (TAB || SPACE)
			continue;

		else
			if(isalpha(ch) || isdigit(ch) || isalnum(ch))
			{
				cout<<"*";
				password[i] = ch;
				i++;
			}
	}

}

int intro_scr(void)                                 //INTRODUCTION SCREEN FUNCTION
{
	clrscr();
	int choice;

	gotoxy(38, 9);
	cout<<"MENU";
	gotoxy(37, 10);
	cout<<"^^^^^^";
	gotoxy(30, 11);
	cout<<"1. USER LOGIN";
	gotoxy(30, 12);
	cout<<"2. ADMINISTRATIVE LOGIN";
	gotoxy(30, 13);
	cout<<"3. CREATE NEW ACCOUNT";
	gotoxy(30, 14);
	cout<<"4. FEEDBACK";
	gotoxy(30, 15);
	cout<<"5. ABOUT US";
	gotoxy(30, 16);
	cout<<"6. EXIT";
	gotoxy(30, 18);
	cout<<"ENTER YOUR CHOICE : ";
	cin>>choice;

	return choice;

}

void feedback ()                                    //FEEDBACK FUNCTION
{
	clrscr();
	mob_no:
	char name[30], comments[2000];
	int mob[10];
	gotoxy(30, 1);
	cout<<"FEEDBACK";
	gotoxy(20, 5);
	cout<<"NAME : ";
	gotoxy(20, 7);
	cout<<"CONTACT NUMBER : ";
	gotoxy(20, 9);
	cout<<"COMMENTS : ";
	gotoxy(27, 5);
	gets(name);
	gotoxy(37, 7);
	mobinput(mob);
	if(mob[0]=='0')
	{
		gotoxy(30, 12);
		cout<<"INVALID INPUT";
		delay(1500);
		clrscr();
		goto mob_no;
	}
	gotoxy(31, 9);
	gets(comments);
}

void contact_us (void)                              //CONTACT US FUNCTION
{
	clrscr();
	gotoxy(30, 1);
	cout<<"CONTACT US";
	gotoxy(20, 7);
	cout<<"E-MAIL : support@loco.com";
	gotoxy(20, 9);
	cout<<"PHONE : 1800 1603 18";
	gotoxy(20, 11);
	cout<<"ADDRESS : LOCO Pvt. Ltd., INDUSTRIAL PARK, NEW DELHI";
	gotoxy(20, 12);
	cout<<"		 NEAR CYBER CITY";
}

void create_acc (void)                                 //CREATE ACCOUNT FUNCTION
{
	clrscr();

	int choice;

	gotoxy(35, 2);
	cout<<"CREATE ACCOUNT";
	gotoxy(30, 10);
	cout<<"CREATE YOUR ACCOUNT AS : ";
	gotoxy(30, 11);
	cout<<"1. AN EMPLOYEE";
	gotoxy(30, 12);
	cout<<"2. A USER";
	gotoxy(24, 13);
	cout<<"ENTER YOUR CHOICE : ";
	gotoxy(44, 13);
	cin>>choice;

	switch(choice)
	{
		case 1: clrscr();
			fout.open("employees.dat", ios::binary | ios::app|ios::out);
			fout.seekp(0, ios::end);
			emp1.newemp();
			fout.write((char *) &emp1, sizeof(emp1));
			fout.close();
		break;

		case 2: clrscr();
			fout.open("users.dat", ios::binary | ios::app|ios::out);
			fout.seekp(0, ios::end);
			usr1.newuser();
			fout.write((char *) &usr1, sizeof(usr1));
			fout.close();
		break;

		default:clrscr();
			gotoxy(12, 30);
			cout<<"INVALID INPUT! PRESS ANY KEY TO CONTINUE.";
			getch();
			create_acc();
	}
}

void about_us (void)                                //ABOUT US FUNCTION
{
	clrscr();
	gotoxy(35, 5);
	cout<<"ABOUT US"<<endl<<endl<<endl;
	cout<<"THIS PROJECT IS BASED ON THE CONCEPT OF CAB BOOKING AND ";
	cout<<"USER AND EMPLOYEE "<<endl<<"MANAGEMENT SYSTEM."<<endl<<endl;
	cout<<"THE PROJECT IMPLIMENTS THE CONCEPTS OF STRUCTURES, FUNCTIONS, ";
	cout<<"CLASSES AND OBJECTS, DATA FILE HANDLING, ARRAYS AND POINTERS ";
	cout<<"OF C++."<<endl<<endl;
	cout<<"THE PROGRAM HAS BEEN ASSIGNED A NAME - 'LOCO' AND HAS A USER ";
	cout<<"FRIENDLY INTERFACE WHICH WILL HELP THE USER IN BOOKING A CAB ";
	cout<<"IN THE CITY OF DELHI OR MUMBAI AS PER HIS PREFERENCE."<<endl<<endl;
	cout<<"IT IS INTERESTING TO NOTE THAT THE PROGRAMMING HAS BEEN DONE IN";
	cout<<" SUCH A WAY THAT NEW CITIES CAN BE ADDED INTO THE SYSTEM VERY ";
	cout<<"EASILY AS PER ONE’s REQUIREMENT."<<endl<<endl;
	cout<<"ALSO MODULAR PROGRAMMING HAS BEEN EXTENSIVELY USED TO INCREASE ";
	cout<<"THE READABILITY"<<endl<<"AND UNDERSTANDABILITY OF THE PROGRAM."<<endl<<endl;
	cout<<"IT IS IMPORTANT TO HIGHLIGHT THE FACT THAT SPECIAL EMPHASIS HAS ";
	cout<<"BEEN GIVEN TO"<<endl<<"THE CONCEPT OF DATA SECURITY IN THIS PROGRAM."<<endl;
	getch();
}

int mobcompare (int a[10], int b[10])
{
	int flag;
	for(int i=0; i<10; i++)
	{
		if(!(a[i]==b[i]))
		{
			flag = 0;
			break;
		}
		else
			flag = 1;
	}
	return flag;
}

void admin (void)                                   //ADMINISTATIVE SETTINGS FUNCTION
{
	char info_return, chngpass_return;

	admin_ch:clrscr();
		gotoxy(20, 11);
		cout<<"1. ACCESS EMPLOYEE / DRIVER ";
		cout<<"/ USER INFORMATION";
		gotoxy(20, 12);
		cout<<"2. CHANGE PASSWORD";
		gotoxy(20, 13);
		cout<<"3. GO TO MAIN MENU";
		gotoxy(20, 14);
		cout<<"4. EXIT";
		gotoxy(30, 16);
		cout<<"ENTER YOUR CHOICE : ";
		gotoxy(50, 16);
		cin>>user_choice;
		switch(user_choice)
		{
				    //SWITCH CASE FOR ADMIN SETTINGS
			case 1: info_return = 'y';
				mode_input:
				int mode, ch;
				clrscr();
				gotoxy(30, 11);
				cout<<"1. EMPLOYEE";
				gotoxy(30, 12);
				cout<<"2. USER";
				gotoxy(30, 13);
				cout<<"3. DRIVER";
				gotoxy(30, 16);
				cout<<"ACCESS INFORMATION OF : ";
				gotoxy(54, 16);
				cin>>mode;
				if(mode<=3 || mode>=1)
				{
					clrscr();
					gotoxy(30, 9);
					cout<<"1. CHECK EXISTING RECORD";
					gotoxy(30, 10);
					cout<<"2. MODIFY AN EXISTING RECORD";
					gotoxy(30, 11);
					cout<<"3. DELETE AN EXISTING RECORD";
					gotoxy(30, 12);
					cout<<"4. ADD A RECORD";
					gotoxy(30, 13);
					cout<<"5. SEARCH FROM EXISTING RECORDS";
					gotoxy(30, 15);
					cout<<"ENTER YOUR CHOICE : ";
					gotoxy(50, 15);
					cin>>ch;
					info(mode, ch);
				}
				else
				{
					clrscr();
					gotoxy(30, 12);
					cout<<"INVALID INPUT!";
					delay(2500);
					goto mode_input;
				}
			break;

			case 2: clrscr();
				char testpassword[10], password[10];
				chngpass_return='y';
				gotoxy(30,12);
				cout<<"ENTER YOUR OLD PASSWORD : ";
				passwordinput(testpassword);
				if(strcmp(emp1.retpassword(), testpassword)==0)
				{
					gotoxy(30,14);
					cout<<"ENTER NEW PASSWORD : ";
					passwordinput(password);
					delay(1000);
					emp1.updatepass(password);
					f.open("employees.dat", ios::binary|ios::out|ios::in);
					employee temp;
					int pos;
					while(f.read((char *)&temp, sizeof(temp)))
					{
						pos=f.tellg();
						if(temp.retcode()==emp1.retcode())
						{
							f.seekg((pos-sizeof(temp)));
							f.write((char *)&emp1, sizeof(emp1));
							break;
						}
					}
					f.close();
					gotoxy(30,16);
					cout<<"PASSWORD RESET SUCCESSFUL";
					getch();
				}
				else
				{
					gotoxy(30,14);
					cout<<"INCORRECT PASSWORD ENTERED!";
					delay(1000);
					goto admin_ch;
				}

			case 3:
			break;

			case 4: clrscr();
				exit(0);

			default:gotoxy(30, 17);
			cout<<"INVALID INPUT!";
			delay(2500);
			goto admin_ch;
		}
		if(info_return == 'y' || chngpass_return == 'y')
		{
			info_return = chngpass_return = 'n';
			goto admin_ch;
		}
}

char bookcab()
{
	char city_choice;
	users temp;
	int pos;

	booking:
	clrscr();
	gotoxy(30, 5);
	cout<<"BOOK CAB";
	gotoxy(30, 9);
	cout<<"AVAILABLE CITIES";
	gotoxy(30, 10);
	cout<<"1. DELHI";
	gotoxy(30, 11);
	cout<<"2. MUMBAI";
	gotoxy(30, 14);
	cout<<"ENTER YOUR CHOICE : ";
	gotoxy(30, 16);
	cout<<"ENTER Q TO EXIT";
	gotoxy(30, 17);
	cout<<"ENTER B TO GO BACK TO USER MENU";
	gotoxy(50,14);
	cin>>city_choice;
	switch(city_choice)
	{
		case '1': lflag=1;
			  locality_name();
			  int fr = delhi();
			  int fare = 24 * fr;
			  gotoxy(30, 20);
			  cout<<"BASE FARE : "<<fare-10<<" to "<<fare+5;

			  booking_date:
				  clrscr();

				  gotoxy(20, 17);
				  cout<<"NOTE : ENTER THE TIME IN 24 HOUR FORMAT";
				  gotoxy(20, 18);
				  cout<<"       THE JOURNEY DATE SHOULD BE WITHIN 24 - HOURS ONLY";
				  gotoxy(30, 12);
				  cout<<"ENTER JOURNEY DATE :   /  /    ";
				  gotoxy(30, 14);
				  cout<<"ENTER PICK UP TIME (24 hr. format) :    -  ";

				  getdate(&today);

				  int damon = today.da_mon;
				  gotoxy(54, 12);
				  cout<<damon;
				  gotoxy(57, 12);
				  cout<<today.da_year;

				  gotoxy(51, 12);
				  cin>>jdate;

				  if((jdate<today.da_day) || (jdate>(today.da_day+1)))
				  {
					gotoxy(30, 16);
					cout<<"INVALID INPUT !";
					delay(1500);
					goto booking_date;
				  }

				  gotoxy(67, 14);
				  jhr1 = getche();
				  jhr2 = getche();
				  jhr1 = ret_no(jhr1);
				  jhr2 = ret_no(jhr2);
				  jhr = (10 * jhr1) + jhr2;
				  gotoxy(71, 14);
				  cin>>jmin;

				  gettime(&today_time);
				  getdate(&today);

				  int timin, tihour;
				  timin = today_time.ti_min;
				  tihour = today_time.ti_hour;

				  if(jdate==(today.da_day+1))
				  {
					if((jhr>23) || (jmin>59))
					{
						gotoxy(30, 16);
						cout<<"INVALID INPUT !";
						delay(1500);
						goto booking_date;
					}
					if((jhr == tihour))
					{
						if((jmin > timin))
						{
							gotoxy(30, 16);
							cout<<"INVALID INPUT !";
							delay(1500);
							goto booking_date;
						}
					}
				  }
				  else if(today.da_day == jdate)
				  {
					if((jhr<tihour))
					{
						gotoxy(30, 16);
						cout<<"INVALID INPUT !"<<today_time.ti_hour<<" ; "<<today_time.ti_min;
						delay(1500);
						goto booking_date;
					}
					else if ((jhr>23))
					{
						gotoxy(30, 16);
						cout<<"INVALID INPUT !";
						delay(1500);
						goto booking_date;
					}
					else if (jmin > 60)
					{
						gotoxy(30, 16);
						cout<<"INVALID INPUT !"<<today_time.ti_hour<<" ; "<<today_time.ti_min;
						delay(1500);
						goto booking_date;
					}
				  }
				  usr1.get_ride(jdate,today.da_mon,today.da_year);
				  bookmobinput(mob);
				  clrscr();
				  gotoxy(35, 12);
				  cout<<"BOOKING SUCCESSFUL!";
				  delay(2000);
				  usr1.getdvrcode();
				  fin.open("drivers.dat", ios::binary|ios::in);
				  clrscr();
				  gotoxy(20, 12);
				  while(fin.read((char *)&dvr1, sizeof(dvr1)))
					if(strcmp(dvr1.retcode(),usr1.retdvrcode())==0)
						dvr1.showuser();
				  fin.close();
				  f.open("users.dat", ios::binary|ios::out|ios::in);
				  while(f.read((char *)&temp, sizeof(temp)))
				  {
					pos=f.tellg();
					if(mobcompare(usr1.retmob(),temp.retmob()))
					{
						f.seekg((pos-sizeof(temp)));
						f.write((char *)&usr1, sizeof(usr1));
					}
				  }
				  f.close();
				  clrscr();
				  gotoxy(35, 12);
				  cout<<"THANKYOU!";
				  delay(3000);
			break;

		case '2': lflag=2;
			  locality_name();
			  int bfr = mumbai();
			  int tfare = 24 * bfr;
			  gotoxy(30, 19);
			  cout<<"BASE FARE : "<<tfare-10<<" to "<<tfare+5;

			  bookingmum_date:
				  clrscr();

				  gotoxy(20, 17);
				  cout<<"NOTE : ENTER THE TIME IN 24 HOUR FORMAT";
				  gotoxy(20, 18);
				  cout<<"       THE JOURNEY DATE SHOULD BE WITHIN 24 - HOURS ONLY";
				  gotoxy(30, 12);
				  cout<<"ENTER JOURNEY DATE :   /  /    ";
				  gotoxy(30, 14);
				  cout<<"ENTER PICK UP TIME (24 hr. format) :    -  ";

				  getdate(&today);

				  int da_mon = today.da_mon;
				  gotoxy(54, 12);
				  cout<<da_mon;
				  gotoxy(57, 12);
				  cout<<today.da_year;

				  gotoxy(51, 12);
				  cin>>jdate;

				  if((jdate<today.da_day) || (jdate>(today.da_day+1)))
				  {
					gotoxy(30, 16);
					cout<<"INVALID INPUT !";
					delay(1500);
					goto bookingmum_date;
				  }

				  gotoxy(67, 14);
				  jhr1 = getche();
				  jhr2 = getche();
				  jhr1 = ret_no(jhr1);
				  jhr2 = ret_no(jhr2);
				  jhr = (10 * jhr1) + jhr2;
				  gotoxy(71, 14);
				  cin>>jmin;

				  gettime(&today_time);
				  getdate(&today);

				  int ti_min, ti_hour;
				  ti_min = today_time.ti_min;
				  ti_hour = today_time.ti_hour;

				  if(jdate==(today.da_day+1))
				  {
					if((jhr>23) || (jmin>59))
					{
						gotoxy(30, 16);
						cout<<"INVALID INPUT !";
						delay(1500);
						goto bookingmum_date;
					}
					if((jhr == ti_hour))
					{
						if((jmin > ti_min))
						{
							gotoxy(30, 16);
							cout<<"INVALID INPUT !";
							delay(1500);
							goto bookingmum_date;
						}
					}
				  }
				  else if(today.da_day == jdate)
				  {
					if((jhr<ti_hour))
					{
						gotoxy(30, 16);
						cout<<"INVALID INPUT !"<<today_time.ti_hour<<" ; "<<today_time.ti_min;
						delay(1500);
						goto bookingmum_date;
					}
					else if ((jhr>23))
					{
						gotoxy(30, 16);
						cout<<"INVALID INPUT !";
						delay(1500);
						goto bookingmum_date;
					}
					else if (jmin > 60)
					{
						gotoxy(30, 16);
						cout<<"INVALID INPUT !"<<today_time.ti_hour<<" ; "<<today_time.ti_min;
						delay(1500);
						goto bookingmum_date;
					}
				  }
				  usr1.get_ride(jdate,today.da_mon,today.da_year);
				  bookmobinput(mob);
				  clrscr();
				  gotoxy(35, 12);
				  cout<<"BOOKING SUCCESSFUL!";
				  delay(2000);
				  usr1.getdvrcode();
				  fin.open("drivers.dat", ios::binary|ios::in);
				  clrscr();
				  gotoxy(20, 12);
				  while(fin.read((char *)&dvr1, sizeof(dvr1)))
					if(strcmp(dvr1.retcode(),usr1.retdvrcode())==0)
						dvr1.showuser();
				  fin.close();
				  f.open("users.dat", ios::binary|ios::out|ios::in);
				  while(f.read((char *)&temp, sizeof(temp)))
				  {
					pos=f.tellg();
					if(mobcompare(usr1.retmob(),temp.retmob()))
					{
						f.seekg((pos-sizeof(temp)));
						f.write((char *)&usr1, sizeof(usr1));
					}
				  }
				  f.close();
				  clrscr();
				  gotoxy(35, 12);
				  cout<<"THANKYOU!";
				  delay(3000);
			break;

		case 'b':

		case 'B':
			break;

		case 'q':

		case 'Q':clrscr();
			 exit(0);

		default:clrscr();
			gotoxy(30, 12);
			cout<<"INVALID INPUT";
			getch();
			goto booking;
	}

	return 'y';
}

char lastride ()
{
	clrscr();
	users temp;
	fin.open("users.dat", ios::binary|ios::in);
	while(fin.read((char *)&temp, sizeof(temp)))
	{
		if(mobcompare(usr1.retmob(),temp.retmob()))
		{
			usr1=temp;
		}
	}
	fin.close();
	if(usr1.ret_ride_flag()==1)
	{
		usr1.ret_ride();
		getch();
	}
	else
	{
		cout<<"NO BOOKINGS DONE TILL DATE.";
		getch();
	}
	return 'y';
}

void user (void)                         //USER SETTINGS FUNCTION
{
	char lastride_return, bookcab_return, chngpass_return;

			user_flag = 1;

			user_ch:clrscr();
				gotoxy(30, 10);
				cout<<"1. BOOK A CAB";
				gotoxy(30, 11);
				cout<<"2. CHECK LAST RIDE INFO";
				gotoxy(30, 12);
				cout<<"3. CHANGE PASSWORD";
				gotoxy(30, 13);
				cout<<"4. GO TO MAIN MENU";
				gotoxy(30, 14);
				cout<<"5. EXIT";
				gotoxy(30, 16);
				cout<<"ENTER YOUR CHOICE : ";
				cin>>user_choice;

				switch(user_choice)
				{
					case 1: bookcab_return=bookcab();
					break;

					case 2: lastride_return=lastride();
					break;

					case 3: clrscr();
						char testpassword[10], password[10];
						chngpass_return='y';
						gotoxy(30,12);
						cout<<"ENTER YOUR OLD PASSWORD : ";
						passwordinput(testpassword);
						if(strcmp(usr1.retpass(), testpassword)==0)
						{
							gotoxy(30,14);
							cout<<"ENTER NEW PASSWORD : ";
							passwordinput(password);
							delay(1000);
							usr1.updatepass(password);
							f.open("users.dat", ios::binary|ios::out|ios::in);
							users temp;
							int pos;
							while(f.read((char *)&temp, sizeof(temp)))
							{
								pos=f.tellg();
								if(mobcompare(usr1.retmob(),temp.retmob()))
								{
									f.seekg((pos-sizeof(temp)));
									f.write((char *)&usr1, sizeof(usr1));
									break;
								}
							}
							f.close();
							gotoxy(30,16);
							cout<<"PASSWORD RESET SUCCESSFUL";
							getch();
						}
						else
						{
							gotoxy(30,14);
							cout<<"INCORRECT PASSWORD ENTERED!";
							delay(1000);
							goto user_ch;
						}
					break;

					case 4: break;

					case 5: clrscr();
						exit(0);

					default:gotoxy(30, 18);
						cout<<"INVALID INPUT!";
						delay(2500);
						goto user_ch;
				}
				if(bookcab_return == 'y' || lastride_return == 'y' || chngpass_return == 'y')
				{
					bookcab_return = lastride_return = chngpass_return = 'n';
					goto user_ch;
				}
}

void info (int mode, int ch)
{
	if(mode == 1)              //FOR CHANGES IN EMPLOYEE SECTION
	{
		employee emp1;
		int flag;
		unsigned long long roll;

		switch(ch)
		{
			case 1:         //PRINT RECORDS OF ALL EMP.
				int ctr = 1;
				fin.open("employees.dat", ios::binary|ios::in);
				while(fin.read((char *)&emp1, sizeof(emp1)))
				{
					if((ctr+1)% 15 == 0)
					{
						getch();
						ctr++;
					}
					if(ctr%15 == 0 || ctr == 1)
					{
						clrscr();
						gotoxy(12, 1);
						cout<<"S. NO.";
						gotoxy(21, 1);
						cout<<"NAME";
						gotoxy(38, 1);
						cout<<"EMPLOYEE ID";
						if(ctr==1 || ctr%15==0)
						{
							cout<<endl;
							emp1.showtable(ctr);
							getch();
						}
					}
					else
					{
						emp1.showtable(ctr);
						getch();
					}
					ctr++;

				}
				fin.close();
				break;

			case 2: 	//MODIFY AN EMP. RECORD
				int pos;
				flag = 0;
				f.open("employees.dat", ios::binary | ios::in | ios:: out);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER EMPLOYEE CODE : ";
				cin>>roll;
				while(!f.eof())
				{
					pos = f.tellg();
					f.read((char *)&emp1, sizeof(emp1));
					if(emp1.retcode()==roll)
					{
						emp1.newemp();
						f.seekg(pos);
						flag = 1;
						f.write((char *)&emp1, sizeof(emp1));
						break;
					}
				}
				if(flag == 0)
				{
					gotoxy(30, 14);
					cout<<"NO MATCH FOUND";
					delay(2000);
				}
				f.close();
				break;

			case 3: 	//DELETE AN EMP. RECORD
				flag = 0;
				fout.open("temp.dat", ios::binary | ios::app|ios::out);
				fin.open("employees.dat", ios::binary|ios::in);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER EMPLOYEE CODE : ";
				cin>>roll;
				while(fin.read((char *)&emp1, sizeof(emp1)))
				{
					if(emp1.retcode()!=roll)
						fout.write((char *)&emp1, sizeof(emp1));
					else
						flag = 1;
				}
				if(flag == 0)
				{
					gotoxy(30, 12);
					cout<<"NO MATCH FOUND!";
					delay(2000);
				}
				fin.close();
				fout.close();
				remove("employees.dat");
				rename("temp.dat", "employees.dat");
				break;

			case 4: 	//ADD AN EMP. RECORD
				fout.open("employees.dat", ios::binary | ios::app|ios::out);
				fout.seekp(0, ios::end);
				emp1.newemp();
				fout.write((char *) &emp1, sizeof(emp1));
				fout.close();
				break;

			case 5: 	//SEARCH FOR AN EMP. RECORD
				fin.open("employees.dat", ios::binary|ios::in);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER THE EMPLOYEE CODE : ";
				cin>>roll;
				while(fin.read((char *)&emp1, sizeof(emp1)))
					if(emp1.retcode()==roll)
					{
						clrscr();
						emp1.show();
					}
				fin.close();
				getch();
				break;

			default:
				clrscr();
				gotoxy(30, 12);
				cout<<"INVALID INPUT!";
		}
	}
	else if(mode == 2)              //FOR CHANGES IN USER SECTION
	{
		users usr1;
		int flag;
		int roll[10];

		switch(ch)
		{                      //PRINT RECORDS OF ALL USERS
			case 1:
				int ctr = 1;
				fin.open("users.dat", ios::binary|ios::in);
				while(fin.read((char *)&usr1, sizeof(usr1)))
				{
					if((ctr+1)% 15 == 0)
					{
						getch();
						ctr++;
					}
					if(ctr%15 == 0 || ctr == 1)
					{
						clrscr();
						gotoxy(12, 1);
						cout<<"S. NO.";
						gotoxy(21, 1);
						cout<<"NAME";
						gotoxy(38, 1);
						cout<<"MOBILE NO.";
						if(ctr==1 || ctr%15==0)
						{
							cout<<endl;
							usr1.showtable(ctr);
							getch();
						}
					}
					else
					{
						usr1.showtable(ctr);
						getch();
					}
					ctr++;

				}
				fin.close();
				break;

			case 2: 	//MODIFY RECORD OF A USER
				int pos;
				flag = 0;
				f.open("users.dat", ios::binary | ios::in | ios:: out);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER USER'S MOBILE NUMBER : ";
				mobinput(roll);
				while(!f.eof())
				{
					pos = f.tellg();
					f.read((char *)&usr1, sizeof(usr1));
					if(mobcompare(usr1.retmob(),roll))
					{
						usr1.newuser();
						f.seekg(pos);
						flag = 1;
						f.write((char *)&usr1, sizeof(usr1));
						break;
					}
				}
				if(flag == 0)
				{
					gotoxy(30, 14);
					cout<<"NO MATCH FOUND";
					delay(2000);
				}
				f.close();
				break;

			case 3: 	//DELETE A RECORD OF A USER
				flag = 0;
				fout.open("temp.dat", ios::binary | ios::app|ios::out);
				fin.open("users.dat", ios::binary|ios::in);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER USER'S MOBILE NUMBER : ";
				mobinput(roll);
				while(fin.read((char *)&usr1, sizeof(usr1)))
				{
					if(!mobcompare(usr1.retmob(),roll))
						fout.write((char *)&usr1, sizeof(usr1));
					else
						flag = 1;
				}
				if(flag == 0)
				{
					clrscr();
					gotoxy(30, 12);
					cout<<"NO MATCH FOUND!";
					delay(2000);
				}
				fin.close();
				fout.close();
				remove("users.dat");
				rename("temp.dat", "users.dat");
				break;

			case 4: 	//MAKE A NEW USER RECORD
				fout.open("users.dat", ios::binary | ios::app|ios::out);
				fout.seekp(0, ios::end);
				usr1.newuser();
				fout.write((char *) &usr1, sizeof(usr1));
				fout.close();
			break;

			case 5: 	//SEARCH FOR A USER RECORD
				flag=0;
				fin.open("users.dat", ios::binary|ios::in);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER USER'S MOBILE NUMBER : ";
				mobinput(roll);
				while(fin.read((char *)&usr1, sizeof(usr1)))
					if(mobcompare(usr1.retmob(),roll))
					{
						usr1.show();
						flag=0;
						getch();
						break;
					}
					else
						flag=1;
				fin.close();
				if(flag==1)
				{
					clrscr();
					gotoxy(30, 12);
					cout<<"NO MATCH FOUND!";
					delay(2000);
				}
				break;
			default:
				clrscr();
				gotoxy(30, 12);
				cout<<"INVALID INPUT!";
		}
	}
	else if(mode == 3)             //FOR CHANGES IN DRIVER SECTION
	{
		driver dvr1;
		int flag;
		char roll[6];
		switch(ch)
		{
			case 1: 	//PRINT ALL DRIVER RECORDS
				int ctr = 1;
				fin.open("drivers.dat", ios::binary|ios::in);
				while(fin.read((char *)&dvr1, sizeof(dvr1)))
				{
					if((ctr+1)% 15 == 0)
					{
						getch();
						ctr++;
					}
					if(ctr%15 == 0 || ctr == 1)
					{
						clrscr();
						gotoxy(12, 1);
						cout<<"S. NO.";
						gotoxy(21, 1);
						cout<<"NAME";
						gotoxy(38, 1);
						cout<<"CAR NUMBER";
						if(ctr==1 || ctr%15==0)
						{
							cout<<endl;
							dvr1.showtable(ctr);
							getch();
						}
					}
					else
					{
						dvr1.showtable(ctr);
						getch();
					}
					ctr++;

				}
				fin.close();
				break;

			case 2: 	//MODIFY A DRIVER RECORD
				int pos;
				flag = 0;
				f.open("drivers.dat", ios::binary | ios::in | ios:: out);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER DRIVER'S ID : ";
				cin>>roll;
				while(!f.eof())
				{
					pos = f.tellg();
					f.read((char *)&dvr1, sizeof(dvr1));
					if(strcmpi(dvr1.retcode(),roll)==0)
					{
						dvr1.newdriver();
						f.seekg(pos);
						flag = 1;
						f.write((char *)&dvr1, sizeof(dvr1));
						break;
					}
				}
				if(flag == 0)
				{
					gotoxy(30, 14);
					cout<<"NO MATCH FOUND";
					delay(2000);
				}
				f.close();
				break;

			case 3: 	//DELETE A DRIVER RECORD
				flag = 0;
				fout.open("temp.dat", ios::binary | ios::app|ios::out);
				fin.open("drivers.dat", ios::binary|ios::in);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER DRIVER'S ID : ";
				cin>>roll;
				while(fin.read((char *)&dvr1, sizeof(dvr1)))
				{
					if(!strcmpi(dvr1.retcode(),roll)==0)
						fout.write((char *)&dvr1, sizeof(dvr1));
					else
						flag = 1;
				}
				if(flag == 0)
				{
					gotoxy(30, 12);
					cout<<"NO MATCH FOUND!";
					delay(2000);
				}
				fin.close();
				fout.close();
				remove("drivers.dat");
				rename("temp.dat", "drivers.dat");
				break;

			case 4: 	//CREATE A DRIVER RECORD
				fout.open("drivers.dat", ios::binary | ios::app|ios::out);
				fout.seekp(0, ios::end);
				dvr1.newdriver();
				fout.write((char *) &dvr1, sizeof(dvr1));
				fout.close();
				break;

			case 5: 	//SEARCH A DRIVER RECORD
				fin.open("drivers.dat", ios::binary|ios::in);
				clrscr();
				gotoxy(20, 12);
				cout<<"ENTER THE EMPLOYEE CODE : ";
				cin>>roll;
				while(fin.read((char *)&dvr1, sizeof(dvr1)))
					if(strcmpi(dvr1.retcode(),roll)==0)
					{
						clrscr();
						dvr1.show();
					}
				fin.close();
				getch();
				break;

			default:
				clrscr();
				gotoxy(30, 12);
				cout<<"INVALID INPUT!";
		}
	}
	else
	{
		clrscr();
		gotoxy(30, 12);
		cout<<"INVALID INPUT!";
	}
}

int ret_no (char t)
{
	int m;
	switch(t)
	{
		case '0' :m = 0;
			break;
		case '1' :m = 1;
			break;
		case '2' :m = 2;
			break;
		case '3' :m = 3;
			break;
		case '4' :m = 4;
			break;
		case '5' :m = 5;
			break;
		case '6' :m = 6;
			break;
		case '7' :m = 7;
			break;
		case '8' :m = 8;
			break;
		case '9' :m = 9;
			break;
		default:gotoxy(30, 16);
			cout<<"INVALID INPUT!";
	}
	return m;
}

void locality_name()
{
	randomize();

	char ch[4]="ab";

	if(lflag==1)		       //INITIALLIZING LOCALITIES OF DELHI
	{
		for(int i=0; i<locality_no_del; i++)
		{
			for(int j=0; j<locality_no_del; j++)
			{
				strcpy(del_city[i][j].locality, ch);
				ch[0]++;
				ch[1]++;
			}
		}

		for(int t=0; t<locality_no_del; t++)
		{
			for(int u=0; u<locality_no_del; u++)
			{
				del_city[t][u].available = random(3);
				del_city[t][u].carcd = random(3);
			}
		}
	}
	else if(lflag==2)              //INITIALLIZING LOCALITIES OF MUMBAI
	{
		for(int i=0; i<locality_no_del; i++)
		{
			for(int j=0; j<locality_no_del; j++)
			{
				strcpy(del_city[i][j].locality, ch);
				ch[0]++;
				ch[1]++;
			}
		}

		for(int t=0; t<locality_no_del; t++)
		{
			for(int u=0; u<locality_no_del; u++)
			{
				del_city[t][u].available = random(3);
				del_city[t][u].carcd = random(3);
			}
		}
	}
}

void carcd(int i, int j)
{
	if(del_city[i][j].carcd==0)
		cout<<"        MARUTI WAGON R";
	else if(del_city[i][j].carcd==1)
		cout<<"        HONDA CITY";
	else if(del_city[i][j].carcd==2)
		cout<<"        TOYOTA INNOVA";
}
					//DELHI : CITY DESIGN
int delhi()
{
	clrscr();
	lflag=1;
	flag=0;
	int i, j, pick_i, pick_j, drop_i, drop_j, ctr;
	int refflag, pick_flag, flagp, flagd;
	char test_locality[4];
	char test_destination[4];

	del_entry:
		clrscr();
		gotoxy(34, 5);
		cout<<"LOCO : DELHI";
		int y = 11;
		gotoxy(30,10);
		cout<<"DELHI LOCALITY MAP";
		gotoxy(30,11);
		cout<<"******************";
		for(int i1=0; i1<5; i1++)
		{
			gotoxy(18, ++y);
			y++;
			for(int j1=0; j1<5; j1++)
			{
				cout<<"| "<<del_city[i1][j1].locality<<"("<<del_city[i1][j1].available<<")"<<" |";
			}
			cout<<endl<<endl;
		}
		gotoxy(4,22);
		cout<<"NOTE: ab, bc, etc. ARE LOCATION CODES WHICH WILL BE ACCEPTED AS INPUT.";
		gotoxy(10,23);
		cout<<"VALUE IN BRACKETS INDICATE THE NUMBER OF CABS AVAILABLE IN THAT REGION.";
		gotoxy(30, 7);
		cout<<"ENTER YOUR PICK UP LOCATION : ";
		gotoxy(30, 8);
		cout<<"ENTER YOUR DESTINATION : ";
		gotoxy(60, 7);
		gets(test_locality);
		gotoxy(55, 8);
		gets(test_destination);

		for(i=0; i<locality_no_del; i++)
		{
			for(j=0; j<locality_no_del; j++)
			{
				if((strcmpi(del_city[i][j].locality, test_locality)==0))     //
				{
					pick_i = i;
					pick_j = j;
					flagp=1;
				}

				if((strcmpi(del_city[i][j].locality, test_destination)==0))   //
				{
					drop_i = i;
					drop_j = j;
					flagd = 1;
				}
			}
			if(flagp==1 && flagd==1)
			{
				flag=1;
				break;
			}
		}

		if(flag==0 || (strcmpi(test_locality, test_destination)==0))
		{
			gotoxy(30,9);
			cout<<"INVALID INPUT";
			delay(2500);
			goto del_entry;
		}
		else if(flag==1)
		{
			prt_pos:
			clrscr();

			usr1.getlocation(test_locality,test_destination);
			usr1.get_ride_flag(1);
			pick_flag=0;

			gotoxy(28, 11);
			cout<<"CABS    LOCATION        CAR MODEL";

			if(!((pick_i==0)||(pick_j==0)||(pick_j==locality_no_del-1)||(pick_i==locality_no_del-1)))
			{
				ctr=0;

				if(del_city[pick_i][pick_j-1].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
					carcd((pick_i), (pick_j-1));
					cout<<endl;
				}
				if(del_city[pick_i+1][pick_j].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
					carcd((pick_i+1), (pick_j));
					cout<<endl;
				}
				if(del_city[pick_i][pick_j+1].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
					carcd((pick_i), (pick_j+1));
					cout<<endl;
				}
				if(del_city[pick_i-1][pick_j].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
					carcd((pick_i-1), (pick_j));
					cout<<endl;
				}
				if(del_city[pick_i][pick_j].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
					carcd((pick_i), (pick_j));
					cout<<endl;
				}
				if(pick_flag!=1)
					cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
			}

			else
			{
				ctr = 0;
				if((pick_i==0))
				{
					if(pick_j==locality_no_del-1)
					{
						if(del_city[pick_i][pick_j-1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
							carcd((pick_i), (pick_j-1));
							cout<<endl;
						}
						if(del_city[pick_i+1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
							carcd((pick_i+1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
					else if(pick_j==0)
					{
						if(del_city[pick_i][pick_j+1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
							carcd((pick_i), (pick_j+1));
							cout<<endl;
						}
						if(del_city[pick_i+1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
							carcd((pick_i+1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
					else
					{
						if(del_city[pick_i][pick_j+1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
							carcd((pick_i), (pick_j+1));
							cout<<endl;
						}
						if(del_city[pick_i+1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
							carcd((pick_i+1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j-1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
							carcd((pick_i), (pick_j-1));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
				}
				else if((pick_i==locality_no_del-1))
				{
					if(pick_j==locality_no_del-1)
					{
						if(del_city[pick_i][pick_j-1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
							carcd((pick_i), (pick_j-1));
							cout<<endl;
						}
						if(del_city[pick_i-1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
							carcd((pick_i-1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
					else if(pick_j==0)
					{
						if(del_city[pick_i][pick_j+1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
							carcd((pick_i), (pick_j+1));
							cout<<endl;
						}
						if(del_city[pick_i-1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
							carcd((pick_i-1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
					else
					{
						if(del_city[pick_i][pick_j+1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
							carcd((pick_i), (pick_j+1));
							cout<<endl;
						}
						if(del_city[pick_i-1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
							carcd((pick_i-1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j-1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
							carcd((pick_i), (pick_j-1));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
				}
				else if(pick_j==0)
				{
					if(del_city[pick_i][pick_j+1].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
						carcd((pick_i), (pick_j+1));
						cout<<endl;
					}
					if(del_city[pick_i-1][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
						carcd((pick_i-1), (pick_j));
						cout<<endl;
					}
					if(del_city[pick_i+1][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
						carcd((pick_i+1), (pick_j));
						cout<<endl;
					}
					if(del_city[pick_i][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
						carcd((pick_i), (pick_j));
						cout<<endl;
					}
					if(pick_flag!=1)
						cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
				}
				else
				{
					if(del_city[pick_i][pick_j-1].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
						carcd((pick_i), (pick_j-1));
						cout<<endl;
					}
					if(del_city[pick_i-1][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
						carcd((pick_i-1), (pick_j));
						cout<<endl;
					}
					if(del_city[pick_i+1][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[i+1][j].locality;
						carcd((pick_i+1), (pick_j));
						cout<<endl;
					}
					if(del_city[pick_i][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
						carcd((pick_i), (pick_j));
						cout<<endl;
					}
					if(pick_flag!=1)
						cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
				}
			}
		}
		if(pick_flag != 1)
		{
			delay (3000);
			user();
		}
		gotoxy(8,10);
		cout<<"SUGGESTIONS FOR YOU:-";
		gotoxy(8, 18);
		cout<<"ENTER THE CURRENT REGION CODE FOR THE CAB TO BE BOOKED : ";
		gotoxy(25, 22);
		cout<<"ENTER Q TO EXIT.";
		gotoxy(65, 18);
		gets(bookadd);

		for(i=0; i<locality_no_del; i++)
			for(j=0; j<locality_no_del; j++)
				if(strcmpi(del_city[i][j].locality, bookadd)==0)
					refflag=1;
				else if((strcmpi("Q", bookadd)==0)||(strcmpi("q", bookadd)==0))
				{
					clrscr();
					exit(0);
				}

		if(refflag!=1)
			goto prt_pos;
		else
			refflag = 0;

		return ((drop_i-pick_i)+(drop_j-pick_j));
}
					//MUMBAI : CITY DESIGN
int mumbai()
{
	clrscr();
	lflag=2;
	flag=0;
	int i, j, pick_i, pick_j, drop_i, drop_j, ctr;
	int refflag, pick_flag, flagp, flagd;
	char test_locality[4];
	char test_destination[4];

	mum_entry:
		clrscr();
		gotoxy(34, 5);
		cout<<"LOCO : MUMBAI";
		int y = 11;
		gotoxy(30,10);
		cout<<"MUMBAI LOCALITY MAP";
		gotoxy(30,11);
		cout<<"*******************";
		for(int i1=0; i1<5; i1++)
		{
			gotoxy(18, ++y);
			y++;
			for(int j1=0; j1<5; j1++)
			{
				cout<<"| "<<del_city[i1][j1].locality<<"("<<del_city[i1][j1].available<<")"<<" |";
			}
			cout<<endl<<endl;
		}
		gotoxy(4,22);
		cout<<"NOTE: ab, bc, etc. ARE LOCATION CODES WHICH WILL BE ACCEPTED AS INPUT.";
		gotoxy(10,23);
		cout<<"VALUE IN BRACKETS INDICATE THE NUMBER OF CABS AVAILABLE IN THAT REGION.";
		gotoxy(30, 7);
		cout<<"ENTER YOUR PICK UP LOCATION : ";
		gotoxy(30, 8);
		cout<<"ENTER YOUR DESTINATION : ";
		gotoxy(60, 7);
		gets(test_locality);
		gotoxy(55, 8);
		gets(test_destination);

		for(i=0; i<locality_no_del; i++)
		{
			for(j=0; j<locality_no_del; j++)
			{
				if((strcmpi(del_city[i][j].locality, test_locality)==0))     //
				{
					pick_i = i;
					pick_j = j;
					flagp=1;
				}

				if((strcmpi(del_city[i][j].locality, test_destination)==0))   //
				{
					drop_i = i;
					drop_j = j;
					flagd = 1;
				}
			}
			if(flagp==1 && flagd==1)
			{
				flag=1;
				break;
			}
		}

		if(flag==0 || (strcmpi(test_locality, test_destination)==0))
		{
			gotoxy(30,9);
			cout<<"INVALID INPUT";
			delay(2500);
			goto mum_entry;
		}
		else if(flag==1)
		{
			prt_pos:
			clrscr();

			usr1.getlocation(test_locality,test_destination);
			usr1.get_ride_flag(1);
			pick_flag=0;

			gotoxy(28, 11);
			cout<<"CABS    LOCATION        CAR MODEL";

			if(!((pick_i==0)||(pick_j==0)||(pick_j==locality_no_del-1)||(pick_i==locality_no_del-1)))
			{
				ctr=0;

				if(del_city[pick_i][pick_j-1].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
					carcd((pick_i), (pick_j-1));
					cout<<endl;
				}
				if(del_city[pick_i+1][pick_j].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
					carcd((pick_i+1), (pick_j));
					cout<<endl;
				}
				if(del_city[pick_i][pick_j+1].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
					carcd((pick_i), (pick_j+1));
					cout<<endl;
				}
				if(del_city[pick_i-1][pick_j].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
					carcd((pick_i-1), (pick_j));
					cout<<endl;
				}
				if(del_city[pick_i][pick_j].available!=0)
				{
					pick_flag=1;
					gotoxy(30, 12+ctr);
					ctr++;
					cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
					carcd((pick_i), (pick_j));
					cout<<endl;
				}
				if(pick_flag!=1)
					cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
			}

			else
			{
				ctr = 0;
				if((pick_i==0))
				{
					if(pick_j==locality_no_del-1)
					{
						if(del_city[pick_i][pick_j-1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
							carcd((pick_i), (pick_j-1));
							cout<<endl;
						}
						if(del_city[pick_i+1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
							carcd((pick_i+1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
					else if(pick_j==0)
					{
						if(del_city[pick_i][pick_j+1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
							carcd((pick_i), (pick_j+1));
							cout<<endl;
						}
						if(del_city[pick_i+1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
							carcd((pick_i+1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
					else
					{
						if(del_city[pick_i][pick_j+1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
							carcd((pick_i), (pick_j+1));
							cout<<endl;
						}
						if(del_city[pick_i+1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
							carcd((pick_i+1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j-1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
							carcd((pick_i), (pick_j-1));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
				}
				else if((pick_i==locality_no_del-1))
				{
					if(pick_j==locality_no_del-1)
					{
						if(del_city[pick_i][pick_j-1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
							carcd((pick_i), (pick_j-1));
							cout<<endl;
						}
						if(del_city[pick_i-1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
							carcd((pick_i-1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
					else if(pick_j==0)
					{
						if(del_city[pick_i][pick_j+1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
							carcd((pick_i), (pick_j+1));
							cout<<endl;
						}
						if(del_city[pick_i-1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
							carcd((pick_i-1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
					else
					{
						if(del_city[pick_i][pick_j+1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
							carcd((pick_i), (pick_j+1));
							cout<<endl;
						}
						if(del_city[pick_i-1][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
							carcd((pick_i-1), (pick_j));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j-1].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
							carcd((pick_i), (pick_j-1));
							cout<<endl;
						}
						if(del_city[pick_i][pick_j].available!=0)
						{
							pick_flag=1;
							gotoxy(30, 12+ctr);
							ctr++;
							cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
							carcd((pick_i), (pick_j));
							cout<<endl;
						}
						if(pick_flag!=1)
							cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
					}
				}
				else if(pick_j==0)
				{
					if(del_city[pick_i][pick_j+1].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i][pick_j+1].available<<"        "<<del_city[pick_i][pick_j+1].locality;
						carcd((pick_i), (pick_j+1));
						cout<<endl;
					}
					if(del_city[pick_i-1][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
						carcd((pick_i-1), (pick_j));
						cout<<endl;
					}
					if(del_city[pick_i+1][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[pick_i+1][pick_j].locality;
						carcd((pick_i+1), (pick_j));
						cout<<endl;
					}
					if(del_city[pick_i][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
						carcd((pick_i), (pick_j));
						cout<<endl;
					}
					if(pick_flag!=1)
						cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
				}
				else
				{
					if(del_city[pick_i][pick_j-1].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i][pick_j-1].available<<"        "<<del_city[pick_i][pick_j-1].locality;
						carcd((pick_i), (pick_j-1));
						cout<<endl;
					}
					if(del_city[pick_i-1][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i-1][pick_j].available<<"        "<<del_city[pick_i-1][pick_j].locality;
						carcd((pick_i-1), (pick_j));
						cout<<endl;
					}
					if(del_city[pick_i+1][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i+1][pick_j].available<<"        "<<del_city[i+1][j].locality;
						carcd((pick_i+1), (pick_j));
						cout<<endl;
					}
					if(del_city[pick_i][pick_j].available!=0)
					{
						pick_flag=1;
						gotoxy(30, 12+ctr);
						ctr++;
						cout<<del_city[pick_i][pick_j].available<<"        "<<del_city[pick_i][pick_j].locality;
						carcd((pick_i), (pick_j));
						cout<<endl;
					}
					if(pick_flag!=1)
						cout<<"SORRY. NO CABS ARE AVAILABLE IN PROXIMITY.";
				}
			}
		}
		if(pick_flag != 1)
		{
			delay (3000);
			user();
		}
		gotoxy(8,10);
		cout<<"SUGGESTIONS FOR YOU:-";
		gotoxy(8, 18);
		cout<<"ENTER THE CURRENT REGION CODE FOR THE CAB TO BE BOOKED : ";
		gotoxy(25, 22);
		cout<<"ENTER Q TO EXIT.";
		gotoxy(65, 18);
		gets(bookadd);

		for(i=0; i<locality_no_del; i++)
			for(j=0; j<locality_no_del; j++)
				if(strcmpi(del_city[i][j].locality, bookadd)==0)
					refflag=1;
				else if((strcmpi("Q", bookadd)==0)||(strcmpi("q", bookadd)==0))
				{
					clrscr();
					exit(0);
				}
		if(refflag!=1)
			goto prt_pos;
		else
			refflag = 0;

		return ((drop_i-pick_i)+(drop_j-pick_j));
}