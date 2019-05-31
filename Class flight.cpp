#include<iostream>
using namespace std;
class flight
{
	private:
	int flight_no;
	char destination[20];
	float distance;
	float fuel;
	void calfuel();
	public:
    void feed_info();
    void show_fuel();
	 
	
};
void flight :: calfuel()
{
	if (distance<=1000)
	 fuel=500;
	 else if (distance<=2000)
	 fuel=1100;
	 else 
	 fuel = 2200;
}
void flight :: feed_info()
{
	cout<<"Enter flight no.\n";
	cin>>flight_no;
	cout<<"Enter destination\n";
	cin>>destination;
	cout<<"Enter distace\n";
	cin>>distance;
	calfuel();
}
void flight :: show_fuel()
{
	cout<<" The flight no. is " << flight_no;
	cout<<"\n The destination is ";
	cout<<destination; cout<<"\n";
	cout<<" \nThe distance is " << distance;
    cout<<"\nThe fuel required is "<< fuel;
    
}
int main()
{
	flight f;
	int choice;
	char ch;
	do{
		cout<<"Main menu\n";
		cout<<"1-Enter details\n";
		cout<<"2- Display details\n";
		cout<<"Enter your choice(1/2)\n";
		cin>>choice;
		switch (choice)
		{
			case 1: f.feed_info();
		            break;
		    case 2: f.show_fuel();
			        break;
			default: cout<<"Wrong choice!\n";
			        break;
							       
		}
	   cout<<"Do you want to continue?\n";
	   cin>>ch;	
		
	}
	while ((ch=='Y')||(ch=='y'));
	return 0;
}



