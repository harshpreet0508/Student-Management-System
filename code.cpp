/*****************************************
* PROJECT ON DATABASE MANAGEMENT OF SCHOOL *
  BY:- AMAN MAHAJAN
       HARSHPREET KAUR
  *****************************************/

		/*************************
	       *     HEADER FILES USED    *
		 *************************/

#include<fstream.h>            // For input/output stream funtions etc.
#include<conio.h>              // For functions like getch(), clrscr(), etc.
#include<string.h>             // For functions like strcmp(), etc.
#include<stdio.h>              // For function like gets().
#include<process.h>            // For exit(0) function.
#include<dos.h>                // For delay() function.
		/***************************
	       * STRUCTURE FOR STORING DATE *
		 ****************************/
   struct DATE
      {
	int dd,mm,yy;
      };

		/**********************************
	       * CLASS FOR STORING STUDENT RECORDS *
		 **********************************/

   class student

      {
	 int ano,rno,d,cls,amt,tfee,tpfee,dfee,total,sfee;  // input variables
	 char name[30],fname[30],stream[30],emp,p,sec;
	 DATE d1,d2;                                        // date type variables

	     public:

	    void in1();               // Input of student details
	    void bill_details();      // Input for Fee bill dates
	    void fee_output();        // Output for Fee bill dates
	    void out1();              // Output of student details
	    void out2();              // Output of particular student details
	    int rano()                // For returning admission number
		{
		   return ano;
		}
	    char rpaid()              // For returning paid details
		{
		   return p;
		}
	    int rcls()                // For returning class
		{
		   return cls;
		}
	    char remp()              // For returning if employee or not
		{
		   return emp;
		}
	    char rsec()              // For returning section
		{
		   return sec;
		}
	    int rrno()               // For returning roll number
		{
		   return rno;
		}

	    void update()            // For updating Section
		{
		   cout<<" Enter new section "<<endl;
		   cin>>sec;
		}

	    void update1()           // For updating Name
		{
		   cout<<" Enter new name "<<endl;
		   gets(name);
		}

	    void update2()           // For updating Roll No.
		{
		   cout<<"Enter new roll number "<<endl;
		   cin>>rno;
		}

	    void update3()           // For updating Class
	      {
		  int clas;
		  char str[30];
		  cout<<"Enter new class "<<endl;
		  cin>>clas;
		  cls=clas;
		  if(clas==1||clas==2||clas==3||clas==4||clas==5)
		    {
		      sfee=0;
		      dfee=500;
		      tfee=2000;
		    }

		  else if(clas==5||clas==6||clas==7||clas==8||clas==9||clas==10)
		    {
		      sfee=0;
		      dfee=1000;
		      tfee=4000;
		    }

		  else if(clas==11)
		      {
			  cout<<" Stream ? "<<endl;
			  gets(str);
			  if(strcmpi(str,"science")==0)
			      {

				  sfee=1500;
				  total=total+sfee;
			      }
			  else
			      {
				  sfee=0;
				  total=total-1500;
			      }
			  dfee=1200;
			  tfee=6000;
		      }

		  else if(clas==12)
		    {
			  cout<<" Stream ? "<<endl;
			  gets(str);
			  if(strcmpi(str,"science")==0)
			      {
				  sfee=1500;
				  total=total+sfee;
			      }
			  else
			      {
				  sfee=0;
				  total=total-1500;
			      }

			 dfee=1200;
			 tfee=7000;
		    }

	      }

	    void update4()           // For updating Stream
		{
			cout<<"Enter new stream "<<endl;
			gets(stream);
			if(strcmpi(stream,"science")==0)
			  {
				sfee=1500;
				total=total+sfee;
			  }
			else
			  {
				sfee=0;
				total=total-1500;
			  }
		}

	    void update5()           // For updating if employee
		{
		  char empl;
		  cout<<"Employee's child (y/n) "<<endl;
		  cin>>empl;
		  emp=empl;
		  if(empl=='y')
		      {
			tfee=0;
			if(cls==1||cls==2||cls==3||cls==4||cls==5)
			   total=total-2000;
			else if(cls==6||cls==7||cls==8||cls==9||cls==10)
			   total=total-4000;
			else if(cls==11)
			   total=total-6000;
			else if(cls==12)
			   total=total-7000;
		      }
		  else if(empl=='n'&&cls==1||cls==2||cls==3||cls==4||cls==5)
		      {
		      tfee=2000;
		      total=total+2000;
		      }
		  else if(empl=='n'&&cls==6||cls==7||cls==8||cls==9||cls==10)
		      {
		      tfee=4000;
		      total=total+4000;
		      }
		  else if(empl=='n'&&cls==11)
		      {
		      tfee=6000;
		      total=total+6000;
		      }
		  else if(empl=='n'&&cls==12)
		      {
		      tfee=7000;
		      total+=7000;
		      }
		}

	    void update6()           // For updating pay
		{
		  cout<<"Paid or not (y/n) "<<endl;
		  cin>>p;
		}


      };

   student s;            //object of class STUDENT

		/********************************
	       * CLASS FUNCTION FOR GENERAL INPUT *
		 ********************************/

   void student::in1()

     {

      cout<<"Enter admission no"<<endl;
      cin>>ano;
      cout<<"Enter name"<<endl;
      cin>>name;
      cout<<"Enter father name"<<endl;
      cin>>fname;
      cout<<"Enter class,section"<<endl;
      cin>>cls>>sec;
      cout<<"Enter roll no"<<endl;
      cin>>rno;
      cout<<"Enter if employee(y/n)"<<endl;
      cin>>emp;
	 if(cls==11||cls==12)
	   {
	      cout<<"Enter stream"<<endl;
	      gets(stream);
		if((cls==11||cls==12 )&& strcmpi(stream,"science")==0) //science stream
			{
			    dfee=1200;
			    sfee=1500;
			}
		else
			{
			    dfee=1000;
			    sfee=0;
			}

		if(emp=='n'&&cls==11)
			tfee= 6000;
		else if(emp=='n'&&cls==12)
			tfee=7000;
		else if(emp=='y')
			tfee=0;
	   }

	 else
	   {
		sfee=0;

		    if(emp=='y')
			{
			  if(cls==1||cls==2||cls==3||cls==4||cls==5)
			{
			    tfee=0;
			    dfee=500;
			}
		   else if(cls==6||cls==7||cls==8||cls==9||cls==10)
			{
			    dfee=1000;
			    tfee=0;
			}
		}

	    else
		{
		   if(cls==1||cls==2||cls==3||cls==4||cls==5)
			{
			    dfee=500;
			    tfee=2000;
			}
		   else if(cls==6||cls==7||cls==8||cls==9||cls==10)
			{
			    dfee=1000;
			    tfee=4000;
			}
		 }

	   }



     char k;
     cout<<"Do you avail transport(y/n) "<<endl;
     cin>>k;
      if(k=='y')
	 {
	   cout<<"Enter distance you travel(in km) "<<endl;
	   cin>>d;
	   if(d>=2&&d<3)
	   tpfee=800;
	   else if(d>=3)
	   tpfee=1200;

	 }

      else

	 {
	   tpfee=0;
	 }
	total=tfee+dfee+sfee+tpfee;

     }

		/*********************************
	       * CLASS FUNCTION FOR GENERAL OUTPUT *
		 *********************************/

   void student::out1()

	{
		cout<<endl<<ano<<"  |  "<<name<<"  |  "<<cls<<"  |  "<<sec;
		cout<<"  |  "<<tfee<<"   |   "<<dfee<<"   |   "<<sfee<<"   |   ";
		cout<<tpfee<<"    |   "<<total<<endl;
	}


		/****************************************
	       * CLASS FUNCTION FOR SINGLE STUDENT DETAIL *
		 ****************************************/


   void student::out2()
	{
		clrscr();

		 cout<<endl<<"Name:         "<<name;
		 cout<<endl<<"Class:        "<<cls<<'-'<<sec;
		 cout<<endl<<"Admission no: "<<ano;
		 cout<<endl<<"Father name:  "<<fname;
		 cout<<endl;
		 cout<<" Fee Bill of Student: "<<name<<endl;
		 cout<<"-------------------------------------"<<endl;
		 cout<<"FEE HEAD                      AMOUNT  "<<endl;
		 cout<<"-------------------------------------";
		 cout<<endl<<"Tuition fee     "<<"	       "<<tfee;
		 cout<<endl<<"Development fee "<<"               "<<dfee;
		 cout<<endl<<"Science fee     "<<"               "<<sfee;
		 cout<<endl<<"Transport fee   "<<"               "<<tpfee<<endl;
		 cout<<"-------------------------------------";
		 cout<<endl<<"Total:           "<<"             "<<total<<endl;
		 cout<<"-------------------------------------"<<endl;
		}

		/*****************************
	       * FUNCTION FOR CREATING RECORD *
		 *****************************/


   void create1()

	{
		 ofstream f1;
		 f1.open("student",ios::out|ios::app);
		 if(!f1)			       
		 {
		 cout<<"file cant opened "<<endl;
		 exit(0);
		 }
		 else
		 {
		 s.in1();
		 f1.write((char*)&s,sizeof(s));
		 }
		 f1.close();
	}

		/******************************
	       * FUNCTION FOR CREATING FEE BILL *
		 ******************************/


   void create2()

	{
		int x;
		ofstream f1;
		f1.open("student",ios::in|ios::app);
		cout<<"Enter the admission number of student "<<endl;
		cin>>x;

		if(s.rano()==x)
		   {
			s.bill_details();
			f1.write((char*)&s,sizeof(s));
		   }


		else
		   {
			cout<<"No data found! ";
		   }

		 f1.close();
	}

		/********************************
	       * CLASS FUNCTION FOR ENTERING DATE *
		 ********************************/


   void student::bill_details()

      {
	   cout<<"Enter the bill date (dd/mm/yy) "<<endl;
	   cin>>d1.dd>>d1.mm>>d1.yy;
	   cout<<"Enter the due date (dd/mm/yy) "<<endl;
	   cin>>d2.dd>>d2.mm>>d2.yy;
	   cout<<"Enter fee paid or not (y/n) "<<endl;
	   cin>>p;
      }

		/*********************************
	       * CLASS FUNCTION FOR DISPLAYING FEE *
		 *********************************/


   void student::fee_output()

      {

	cout<<ano<<"   |   "<<total<<"   |   "<<d1.dd<<"/"<<d1.mm<<"/"<<d1.yy<<"    |    "<<d2.dd<<"/"<<d2.mm<<"/"<<d2.yy<<"  |  "<<p<<endl;

      }

		/***************************************
	       * FUNCTION FOR DISPLAYING STUDENT RECORDS *
		 ***************************************/


   void display1()   		      //Display student records

      {
	 ifstream f1;
	 f1.open("student",ios::in);
	 cout<<endl<<"Admno"<<" | "<<"Name"<<" | "<<"Class"<<" | "<<"Sec"<<" | ";
	 cout<<"T fee"<<" | "<<"D fee"<<"  |  "<<"S fee"<<" | "<<"Tp fee"<<" | "<<"Total"<<endl;

	 while(f1.read((char*)&s,sizeof(s)))
	     {
		s.out1();
	     }
		f1.close();
      }

		/********************************
	       * FUNCTION FOR DISPLAYING FEE BILL*
		 ********************************/


   void display2() 		      //Display Fee bill
	{
		int q,f=0;
		ifstream f1;
		f1.open("student",ios::in);
		cout<<"Enter admission number whose fee bill you want "<<endl;
		cin>>q;
		while(f1.read((char*)&s,sizeof(s)))

		   {
		       if(s.rano()==q)
			  {
			       cout<<"Admno"<<"  |  "<<" Amount "<<"   |   "<<"Bill date"<<"   |   "<<"Due date"<<"  |  "<<"Paid"<<endl;
			       s.fee_output();
			       f=1;
			  }
		   }
		       if(f==0)

			  {
			       cout<<"No data Found ! "<<endl;
			  }


		f1.close();
		return;

	}
		/****************************************
	       * FUNCTION FOR DISPLAYING UNPAID FEE BILLS *
		 ****************************************/


   void paid()

	{
		ifstream f1;
		f1.open("student",ios::in);

		while(f1.read((char*)&s,sizeof(s)))

		   {

			if(s.rpaid()=='n')

			  {
				cout<<"\n\n";
				cout<<"Admno"<<"  |  "<<"Amount"<<"  |  "<<"Bill date"<<"  |  "<<"Due date"<<"  |  "<<"Paid"<<endl;
				s.fee_output();
				cout<<endl;
			  }
		   }
		f1.close();
	}


		/********************************
	       *      FUNCTION FOR SEARCHING      *
		 ********************************/


   void searcha()     		      //search record on basis of admno

	{
		 int a;
		 cout<<"Enter  the admission no. you want to search "<<endl;
		 cin>>a;

		 ifstream f1;
		 f1.open("student",ios::in);

		 while(f1.read((char*)&s,sizeof(s)))

		   {
		      if(s.rano()==a)

			s.out2();

		      else

			cout<<"No record found ";

		   }

		 f1.close();

	}

		/********************************
	       *      FUNCTION FOR SEARCHING      *
		 ********************************/


   void searchc()     		      //search record on basis of class

	{
		int c;
		cout<<"Enter  the class you want to search "<<endl;
		cin>>c;
		ifstream f1;
		f1.open("student",ios::in);

		while(f1.read((char*)&s,sizeof(s)))

		   {
		       if(s.rcls()==c)

			  s.out2();

		       else

		cout<<"No record found ";

		   }

		f1.close();

	}

		/********************************
	       *      FUNCTION FOR SEARCHING      *
		 ********************************/


   void searchcs()  		      //search record on basis of class and section
	{
		int cs;
		char S;
		cout<<"Enter  the class and section you want to search "<<endl;
		cin>>cs>>S;
		ifstream f1;
		f1.open("student",ios::in);

		while(f1.read((char*)&s,sizeof(s)))

		   {
			if((s.rcls()==cs)&&(s.rsec()==S))

			s.out2();

			else

			cout<<"No record found ";

		   }

		f1.close();

	}

		/********************************
	       *      FUNCTION FOR SEARCHING      *
		 ********************************/


   void searchr()     		      //search record on basis of roll no
	{

		int r;
		cout<<" Enter  the roll number you want to search "<<endl;
		cin>>r;
		ifstream f1;
		f1.open("student",ios::in);

		while(f1.read((char*)&s,sizeof(s)))
		   {
			if(s.rrno()==r)

			s.out2();

			else

			cout<<"No record found ";

		   }

		f1.close();

	}
		/********************************
	       *      FUNCTION FOR MODIFICATION      *
		 ********************************/


				      // For modifying section
   void modify_sec()
	{
		int n,f=0;
		fstream f1;
		f1.open("student",ios::in|ios::out);
		long p=f1.tellg();
		cout<<"Enter admission number "<<endl;
		cin>>n;

		while(f1.read((char*)&s,sizeof(s)))
		   {

			if(s.rano()==n)
			   {
				f=1;
				s.update();
				f1.seekg(p);
				f1.write((char*)&s,sizeof(s));
				cout<<"Record Modified ! "<<endl;
				break;
			   }
			p=f1.tellg();
		   }
		if(f==0)
		   {
			cout<<"No data found! ";
		   }

		f1.close();

	}

		/********************************
	       *      FUNCTION FOR MODIFICATION      *
		 ********************************/


   void modify_name()                 // For modifying name
	{
		int n,f=0;
		fstream f1;
		f1.open("student",ios::in|ios::out);
		long p=f1.tellg();
		cout<<"Enter admission number "<<endl;
		cin>>n;

		while(f1.read((char*)&s,sizeof(s)))
		   {
			if(s.rano()==n)
			   {
				f=1;
				s.update1();
				f1.seekg(p);
				f1.write((char*)&s,sizeof(s));
				cout<<"Record Modified ! "<<endl;
				break;
			   }
			p=f1.tellg();
		   }

		if(f==0)
		   {
			cout<<"No data found! ";
		   }

		f1.close();
	}

		/********************************
	       *      FUNCTION FOR MODIFICATION      *
		 ********************************/


   void modify_rno()                  // For modifying roll number
	{
		int n,f=0;
		fstream f1;
		f1.open("student",ios::in|ios::out);
		long p=f1.tellg();
		cout<<"Enter admission number "<<endl;
		cin>>n;

		while(f1.read((char*)&s,sizeof(s)))
		   {

			if(s.rano()==n)
			   {
				f=1;
				 s.update2();
				 f1.seekg(p);
				 f1.write((char*)&s,sizeof(s));
				 cout<<"Record Modified ! "<<endl;
				 break;
			   }

			p=f1.tellg();
		   }

		if(f==0)
		   {
			cout<<"No data found! ";
		   }

		f1.close();
	}

		/********************************
	       *      FUNCTION FOR MODIFICATION      *
		 ********************************/


   void modify_class()                // For modifying class
	{
		int n,f=0;
		fstream f1;
		f1.open("student",ios::in|ios::out);
		long p=f1.tellg();
		cout<<"Enter admission number "<<endl;
		cin>>n;

		while(f1.read((char*)&s,sizeof(s)))
		   {
			if(s.rano()==n)
			  {
				f=1;
				s.update3();
				f1.seekg(p);
				f1.write((char*)&s,sizeof(s));
				cout<<"Record Modified ! "<<endl;
				break;
			  }
				p=f1.tellg();
		   }

		if(f==0)
		   {
			cout<<"No data found! ";
		   }

		f1.close();
	}

		/********************************
	       *      FUNCTION FOR MODIFICATION      *
		 ********************************/


   void modify_stream()               // For modifying stream
	{
		int n,f=0;
		fstream f1;
		f1.open("student",ios::in|ios::out);
		long p=f1.tellg();
		cout<<"Enter admission number "<<endl;
		cin>>n;

		while(f1.read((char*)&s,sizeof(s)))
		   {
			if(s.rano()==n)
			  {
				if(s.rcls()==11||s.rcls()==12)
				  {
					f=1;
					s.update4();
					f1.seekg(p);
					f1.write((char*)&s,sizeof(s));
					cout<<"Record Modified ! "<<endl;
					break;
				  }
				else
				  {
					f=1;
					cout<<"Stream can't be alloted"<<endl;
				  }
			   }
			p=f1.tellg();
		   }

		if(f==0)
		   {
			cout<<"No data found! ";
		   }

		f1.close();
	}

		/********************************
	       *      FUNCTION FOR MODIFICATION      *
		 ********************************/


   void modify_emp()                  // For modifying if employee
	{
		int n,f=0;
		fstream f1;
		f1.open("student",ios::in|ios::out);
		long p=f1.tellg();
		cout<<"Enter admission number "<<endl;
		cin>>n;

		while(f1.read((char*)&s,sizeof(s)))
		   {
			if(s.rano()==n)
			  {
				f=1;
				s.update5();
				f1.seekg(p);
				f1.write((char*)&s,sizeof(s));
				cout<<"Record Modified ! "<<endl;
				break;
			  }
			 p=f1.tellg();
		   }

		if(f==0)
		   {
			cout<<"No data found! ";
		   }

		f1.close();
	}

		/********************************
	       *      FUNCTION FOR MODIFICATION      *
		 ********************************/


   void modify_feepay()               // For modifying pay fee
	{
		int n,f=0;
		fstream f1;
		f1.open("student",ios::in|ios::out);
		long p=f1.tellg();
		cout<<"Enter admission number "<<endl;
		cin>>n;

		while(f1.read((char*)&s,sizeof(s)))
		   {
			if(s.rano()==n)
			  {
				f=1;
				s.update6();
				f1.seekg(p);
				f1.write((char*)&s,sizeof(s));
				cout<<"Record Modified ! "<<endl;
				break;
			  }
			p=f1.tellg();
		   }

		if(f==0)
		   {
			cout<<"No data found! ";
		   }

		f1.close();
	}

		/********************************
	       *      FUNCTION FOR DELETION       *
		 ********************************/


   void erase()  		      //for deleting a record
	{
		int z,f=0;
		ifstream f1 ("student",ios::in);
		ofstream f2("temp",ios::out);
		cout<<"Enter the admn. number whose record you want to delete"<<endl;
		cin>>z;


		while(f1.read((char*)&s,sizeof(s)))
		   {
			if(s.rano()==z)

				f=1;

			if(s.rano()!=z)

				f2.write((char*)&s,sizeof(s));

		   }

		f1.close();
		f2.close();
		if(f==1)
		   {
			cout<<"Record Deleted!";
			remove("student");
			rename("temp","student");

		   }

	}

	       /********************
	       *    MAIN FUNCTION    *
		 ********************/

   void main()

	{
		clrscr();
		char num=0,num1=0,opt1=0;
		cout<<"\n\n\n\n\n";
		cout<<" ###         ### #####  **     ::::::::   !!!!!!!!  ###    ### ######  \n";
		cout<<"  ###   #   ###  #____  **     ::         !!    !!  ## #  # ## #_____  \n";
		cout<<"   ### ### ###   #      **     ::         !!    !!  ##  ##  ## #       \n";
		cout<<"    ###  ###     #####  ****** ::::::::   !!!!!!!!  ##   #  ## ######  \n";
		cout<<"\n\n\n\n\n";

		delay(1000);
		clrscr();
cout<<"\t		____________________            "<<endl ;
cout<<"\t		|  MOTHER'S GLOBAL |            "<<endl ;
cout<<"\t		|      SCHOOL      |            "<<endl ;
cout<<"\t		|                  |            "<<endl ;
cout<<"\t		|                  |            "<<endl ;
cout<<"\t		|                  |            "<<endl ;
cout<<"\t		|                  |            "<<endl ;
cout<<"\t		|                  |            "<<endl ;
cout<<"\t		|                  |            "<<endl ;
cout<<"\t		|                  |            "<<endl ;
cout<<"\t		|                  |            "<<endl ;
cout<<"\t    ____________|                  |____________"<<endl ;
cout<<"	    |  SENIOR	|                  |  JUNIOR   |"<<endl ;
cout<<"	    |    WING	|__________________|   WING    |"<<endl ;
cout<<"	    |      	|                  |           |"<<endl ;
cout<<"	    |	        |    RECEPTION     |           |"<<endl ;
cout<<"	    |		|__________________|           |"<<endl ;
cout<<"	    |		|                  |           |"<<endl ;
cout<<"	    |		|                  |           |"<<endl ;
cout<<"	    |		|                  |           |"<<endl ;
cout<<"	    |		|      ######      |           |"<<endl ;
cout<<"	    |	!!!!    |      #    #      |   !!!!    |"<<endl ;
cout<<"	    |	!. !    |      #.   #      |   !. !    |"<<endl ;
cout<<"	    |___!__!____|______#____#______|___!__!____|"<<endl ;


		delay(2000);
		clrscr();
		cout<<"\n\t\t\tMOTHER'S GLOBAL SCHOOL";
		cout<<"\n\n\n\t 1. DATABASE MANAGEMENT 			2. EXIT"<<endl;
		num=getch();
		clrscr();

	if(num=='1')
	    {

		bm:    //bookmark

		clrscr();

		cout<<"\n\t\t\t MAIN MENU"<<endl;
		cout<<"\n\n\n\t1.Create		4.Search"<<endl;
		cout<<"\n\n\n\t2.Display		5.Delete"<<endl;
		cout<<"\n\n\n\t3.Modify		6.Exit"<<endl;
		num1=getch();
		clrscr();
	switch(num1)
		  {

		case '1': cout<<"\n1.Create Record";
			  cout<<"\n\n2.Generate Fee bill"<<endl;
			  opt1=getch();
			  clrscr();

			switch(opt1)
			  {

			    case '1': create1();
				      getch();
				      goto bm;

			    case '2': create2();
				      getch();
				      goto bm;

			     default: goto bm;

			  }
		case '2': cout<<"\n1.Display Record";
			  cout<<"\n\n2.Display Fee details";
			  cout<<"\n\n3.Display unpaid fee records"<<endl;
			  opt1=getch();
			  clrscr();
			  switch(opt1)
			   {

			    case '1': display1();
				      getch();
				      goto bm;

			    case '2': display2();
				      getch();
				      goto bm;

			    case '3': paid();
				      getch();
				      goto bm;

			     default: goto bm;

			   }
		case '3': cout<<"\n1.Name";
			  cout<<"\n\n2.Stream";
			  cout<<"\n\n3.employee's child or not";
			  cout<<"\n\n4.Class";
			  cout<<"\n\n5.Sec";
			  cout<<"\n\n6.Roll number";
			  cout<<"\n\n7.Fee "<<endl;
			  opt1=getch();
			  clrscr();

			  switch(opt1)
			   {

			    case '1': modify_name();
				      getch();
				      goto bm;

			    case '2': modify_stream();
				      getch();
				      goto bm;

			    case '3': modify_emp();
				      getch();
				      goto bm;

			    case '4': modify_class();
				      getch();
				      goto bm;

			    case '5': modify_sec();
				      getch();
				      goto bm;

			    case '6': modify_rno();
				      getch();
				      goto bm;

			    case '7': modify_feepay();
				      getch();
				      goto bm;

			     default: goto bm;

			   }


		case '4': cout<<"\n\t\t\t ON THE BASIS OF "<<endl ;
			  cout<<"\n1.Admission number";
			  cout<<"\n\n2.Class";
			  cout<<"\n\n3.Class & Section";
			  cout<<"\n\n4.Roll number"<<endl;
			  opt1=getch();
			  clrscr();

			  switch(opt1)
			   {

			    case '1': searcha();
				      getch();
				      goto bm;

			    case '2': searchc();
				      getch();
				      goto bm;

			    case '3': searchcs();
				      getch();
				      goto bm;

			    case '4': searchr();
				      getch();
				      goto bm;

			     default: goto bm;

			    }


		case '5': cout<<"\n1.Erase record"<<endl;
			  cout<<"\n\n2.Return to MAIN MENU "<<endl;
			  opt1=getch();
			  clrscr();

			  switch(opt1)
			   {

			    case '1': erase();
				      getch();
				      goto bm;

			    case '2': goto bm;
			   }

		case '6': exit(0);

		  }
	    }

  else
       exit(0);

   getch();

}
