// C++ Project- Stocks
#include<fstream>
#include<iosteam>
#include<string>
using namespace std;
void create();
void display();
void search();
void modify();



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
