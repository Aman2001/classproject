// C++ Project- Stocks
#include<fstream>
#include<iosteam>
#include<string>
using namespace std;
void create();
void display();
void search();
void modify();


// C++ Project- Stocks
#include<fstream>
#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;
void create();
void display();
void search();
void modify();
void del_rec();
void tot_rec();
void sort();


class customer
{
	int tot_stocks;
	int regno;
	char name[10];
	float tot_investment;
	public: 
	void read();
	void output();
	int returnstocks()
	{ 
	return(tot_stocks);
	}
	int regreturn()
	{
		return(regno);
	}
	char* returnname()
	{
		return(name);
	}
};
customer s;

void customer::read()
{ 
cout<<"\n Enter Name\n";
gets(s.name);
cout<<"\n Enter Number Of Stocks purchased\n ";
cin>>s.tot_stocks;
cout<<"\n Enter the amount of rupees invested\n";
cin>>s.tot_investment;
}
void customer::output()
{
	cout<<"Name - \t"<<s.name;
	cout<<"Number of Stocks held -\t "<<s.tot_stocks;
	cout<<"Investment(Rupees) -\t"<<s.tot_investment;
	
}
void create()
{ ofstream fout("cust.dat",ios::binary|ios::out);
char rep;
do
{
	s.read();
	fout.write((char*)&s,sizeof(s));
	cout<<"\n Do you want to continue?\n";
	cin>>rep;
} while((rep=='Y')||(rep=='y'));
  fout.close();
}
void display()
{ ifstream fin("cust.dat",ios::binary|ios::in);
   fin.seekg(0);
   while(fin.read((char*)&s,sizeof(s)))
{ s.output();
	} fin.close();	
	}
void search()
{   ifstream fin("cust.dat",ios::binary|ios::in);
    int x, choice;
    char str[10];
    cout<<"1- Search by Name\n";
    cout<<"2- Search by Total Stocks Held\n";
    cin>>choice;
    switch(choice)
    { case 1: cout<<"\n Enter Name \n";
              cin>> str;
              fin.seekg(0);
              while(fin.read((char*)&s,sizeof(s)))
              { 
			  if(strcmp(s.returnname(),str)==0)
               { 
               cout<<"\nRecord Found\n";
               s.output();
			   }
		}
		fin.close();
		break;
		case 2: cout<<"Enter Number of Socks Held- ";
		         cin>>x;
		         fin.seekg(0);
		         while(fin.read((char*)&s,sizeof(s)))
		         {
		         	if(s.returnstocks()==x)
		         	{ 
		         	cout<<"\nRecord Found\n";
		         	s.output();
					 }
					 }
					 fin.close();
					 break;
					 default: cout<<"\nRecord Not Found\n";
			          }
			  }
			  void modify()
			  { 
			  ifstream fin;
			  ofstream fout;
			  fin.open("cust.dat",ios::binary);
			  fout.out("cust.dat",ios::binary);
			  int x;
			  cout<<"Enter registration number to be changed\n ";
			  cin>>x;
			  fin.seekg(0);
			  while(fin.read((char*)&s,sizeof(s)))
			  { if(s.regreturn()==x)
			  {
			  	s.read();
			  	fout.write((char*)&s,sizeof(s));
			  	}
			  else
			  fout.write((char*)&s,sizeof(s));
	          }
			  remove("cust.dat");
			  rename("new.dat","cust.dat");
			  fin.close();
			  fout.close();
	         }
	         void del_rec()
	         {
	         	 ifstream fin;
			  ofstream temp;
			  fin.open("cust.dat", ios::binary);
			  temp.out("cust.dat", ios::binary);
			  int x,choice;
			  char str[10];
			  cout<<"\n1) Delete by Registration Number\n";
			  cout<<"\n2) Delete by Customer Number\n";
			  cout<<"\nEnter your choice\n";
			  cin>>choice;
			  switch(choice)
			   {
			   	case 1: cout<<"\nEnter Registration Number to be Deleted\n";
                        cin>>x;
						fin.seekg(0);
						while(fin.read((char*)&s,sizeof(s)))
						{
							if(s.regreturn()!=x)
							fout.write((char*)&s,sizeof(s));
							
						}
						remove("cust.dat");
						rename("new.dat","cust.dat");
						fin.close();
						fout.close();
						break;
			    case 2: cout<<"\nEnter Customer Name to be Deleted\n";
                        gets(str);
						fin.seekg(0);
						while(fin.read((char*)&s,sizeof(s)))
						{
							if(s.returnname()!=str)
							temp.write((char*)&s,sizeof(s));
							
						}
						remove("cust.dat");
						rename("new.dat","cust.dat");
						fin.close();
						temp.close();
						break;
						 			   
			   }
		}
			   void tot_rec()
			   {
			   	ifstream fin("cust.dat",ios::binary);
				   fin.seekg(0);
				   int count=0;
				   while(fin.read((char*)&s,sizeof(s)))
				   count++;
				   cout<<"The Total Number of Records - "<<count;
				   fin.close();
				   
				}
				void sort()
				{
					fstream f;
					int nr;
					f.open("cust.dat",ios::binary|ios::in|ios::out)
					f.seekg(0,ios::end);
					nr=f.tellg()/sizeof("cust.dat");
					customer c2,c3;
					for(int i=0;i<nr-1;i++)
					for(int j=0;j<nr-i-1;j++)
					{
						f.seekg(j*sizeof("cust.dat"));
						
						int p;
						cout<<"\n 1) Sort records in ascending order of registration number\n";
						cout<<"\n 2) Sort records in decending order of registration number\n";
						cout<<"\nEnter you choice\n";
						cin>>p;
						switch(p){
-							case 1 : f.read((char*)&c2,sizeof(c2));
						             f.read((char*)&c3,sizeof(c3));

                                     if(c2.regreturn()>c3.regreturn())
                                     break;
                            
							case 2 : f.read((char*)&c2,sizeof(c2));
						             f.read((char*)&c3,sizeof(c3));
                                     if(c2.regreturn()<c3.regreturn())
                                     break;
						    default: cout<<"\n Wrong Choice! Try again\n";				      
					  
					  }                
						{f.seekg(j*sizeof("cust.dat"));
						f.write((char*)&c3,sizeof(c3));
						f.write((char*)&c2,sizeof(c2));
							
						}
						
					}
					f.close();
					
				}
			    int main()
			    { 
				 do{
				    int choice;
			        char ch;
			    	cout<<"\nMain Menu\n";
			    	cout<<"\n1) Enter Records\n";
			    	cout<<"\n2) Display Records\n";
			    	cout<<"\n3) Search Records\n";
			    	cout<<"\n4) Modify Records\n";
			    	cout<<"\n5) Delete Records\n";
			    	cout<<"\n6) Sort Records\n";
			    	cout<<"\nEnter your choice\n";
			    	cin>>choice;
			    	switch(choice)
			    	{ 
			    	 case 1: create();
			    	         break;
					 case 2: display();
			    	         break;
			    	 case 3: search();
			    	         break;
			    	 case 4: modify();
					         break;         
			    	 case 5: del_rec();
			    	         break;
			    	 case 6: sort();
			    	         break;
			    	default: cout<<"\n Wrong choice!Try Again\n";
					}
					cout<<"Do you want to continue the program(y\n)\n";
					cin>>ch;
				}while((ch=='Y')||(ch=='y'));
				return 0;
			}
	         
		}
	}
}}

				
  
class customer
{
	int tot_stocks;
	int regno;
	char name[10];
	float tot_investments;
	public: 
	void read();
	void output();
	int returnstocks()
	{ 
	return(tot_stocks);
	}
	int regreturn()
	{
		return(regno);
	}
	char* returnname()
	{
		return(name);
	}
};
customer s;

void customer::read()
{ 
cout<<"\n Enter Name\n";
gets(s.name);
cout<<"\n Enter Number Of Stocks purchased\n ";
cin>>s.tot_stocks;
cout<<"\n Enter the amount of rupees invested\n";
cin>>s.tot_investment;
}
void customer::output()
{
	cout<<"Name - \t"<<s.name;
	cout<<"Number of Stocks held -\t "<<s.tot_stocks;
	cout<<"Investment(Rupees) -\t"<<s.tot_investment;
	
}
void create()
{ ofstream fout("cust.dat",ios::binary|ios::out);
char rep;
do
{
	s.read();
	fout.write((char*)&s,sizeof(s));
	cout<<"\n Do you want to continue?\n";
	cin>>rep;
} while((rep=='Y')||(rep=='y'));
  fout.close();
}
void display()
{ ifstream fin("cust.dat",ios::binary|ios::in);
   fin.seekg(0);
   while(fin.read((char*)&s,sizeof(s)))
{ s.output();
	} fin.close();	
	}
void search()
{   ifstream fin("cust.dat",ios::binary|ios::in);
    int x, choice;
    char str[r];
    cout<<"1- Search by Name\n";
    cout<<"2- Search by Total Stocks Held\n";
    cin>>choice;
    switch(choice)
    { case 1: cout<<"\n Enter Name \n";
              cin>> str;
              fin.seekg(0);
              while(fin.read((char*)&s,sizeof(s)))
              { 
			  if(strcmp(s.returnname(),str)==0)
               { 
               cout<<"\nRecord Found\n";
               s.output();
			   }
		}
		fin.close();
		break;
		case 2: cout<<"Enter Number of Socks Held- "
		         cin>>x;
		         fin.seekg(0);
		         while(fin.read((char*)&s,sizeof(s)))
		         {
		         	if(s.returnstocks()==x)
		         	{ 
		         	cout<<"\nRecord Found\n";
		         	s.output();
					 }
					 }
					 fin.close();
					 break;
					 default: cout<<"\nRecord Not Found\n";
			          }
			  }
			  void modify()
			  { 
			  ifstream fin;
			  ofstream temp;
			  fin.open("cust.dat", ios::binary|ios::in);
			  temp.out("cust.dat", ios::binary|ios::out);
			  int x;
			  cout<<"Enter registration number to be changed\n ";
			  cin>>x;
			  fin.seekg(0);
			  while(fin.read((char*)&s,sizeof(s)))
			  { if(s.regreturn()==x)
			  {
			  	s.read();
			  	temp.write((char*)&s,sizeof(s));
			  	}
			  else
			  temp.write((char*)&s,sizeof(s));
	          }
			  remove("cust.dat");
			  rename("new.dat","cust.dat");
			  fin.close();
			  temp.close();
	         }
	         
		}		

				
 } 
