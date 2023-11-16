#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};
//Here we will start the program and for login.
void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t_________________________________________________\n";
	cout<<"\t\t\t\t                                   \n";
	cout<<"\t\t				My Market Main Menu		  \n";
	cout<<"\t\t\t\t                                   \n";
	cout<<"\t\t\t\t_________________________________________________\n";
	cout<<"\t\t\t\t									  \n";
	cout<<"\t\t\t\t|  1) Administrator		\t\t|\n";
	cout<<"\t\t\t\t|  						|\n";
	cout<<"\t\t\t\t|  2) Buyer				\t|\n";
	cout<<"\t\t\t\t|  						|\n";
	cout<<"\t\t\t\t|  3) Exit				\t|\n";
	cout<<"\t\t\t\t|  						|\n";
	cout<<"\n\t\t\t Please select : ";
	cin>>choice;
	switch (choice)
	{
		case 1:
			cout<<"\n\t\t\t\t\t\t Please Login. \n\n";
			cout <<"\t\t\t Enter Email : ";
			cin >>email;
			cout<<"\t\t\t Enter Password : ";
			cin>>password;
			
			if(email=="sharyarkhan@gmail.com" && password=="cped")
			{
				administrator();
			}
			else 
			{
				cout <<"\nInvalid email/password\n";
			}
			break;
		case 2:
			{
				buyer();
			}
			break;
		case 3:
			{
				exit(0);
			}
			break;
		default:
			cout<<"Please select from the given numbers";
	}
	goto m;
}

//Here is all the settings for the Administators.
void shopping::administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t\t\t Administrator menu\n";
	cout<<"\n\t\t\t\t|____1) Add the product______|";
	cout<<"\n\t\t\t\t|			     |";
	cout<<"\n\t\t\t\t|____2) Modify the product___|";
	cout<<"\n\t\t\t\t|			     |";
	cout<<"\n\t\t\t\t|____3) Delete the product___|";
	cout<<"\n\t\t\t\t|			     |";
	cout<<"\n\t\t\t\t|____4) Back to main menu____|";
	cout<<endl;
	cout<<"\n\n Please enter your choice : ";
	cin>>choice;
	
		switch (choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"Invalid choice!";
	}
	goto m;
}


//Here is all the settings for the buyers.
void shopping:: buyer()
{
	m:
	int choice;
	cout<<"\n\t\t\t\t|      Buyer      |";
	cout<<"\n\t\t\t\t|_________________|";
	cout<<"\n\t\t\t\t| 1) Buy product  |";
	cout<<"\n\t\t\t\t| 2) Go back	  |";
	cout<<"\n\n\t\t\t Enter you choice : ";
	cin>>choice;
	
		switch (choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
			cout<<"Invalid choice!";
	}
	goto m;
}


//for 1. Add the product.
void shopping::add()
{
	m:
	fstream data;
	int c,a;
	int token=0;
	float p, d;
	string n;
	
	cout<<"\n\t\t\t Add new product";
	cout<<"\n\n Code of the product:";
	cin>>pcode;
	cout<<" Name of the product:";
	cin>>pname;
	cout<<" Price of the product:";
	cin>>price;
	cout<<" Discount on the product:";
	cin >>dis;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		data.open("database.txt", ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if (c==pcode)
			{
				token++;
			}
			data>>a>>c>>n>>d;
		}
		data.close();
	if(token==1)
	goto m;
	else
	{
		data.open("database.txt", ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();	
	}
	}
		cout<<"\n\t\t\t Record inserted.";
}

//Here we can edited the excessting product.
void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p,d;
	string n;
	cout<<"\n\t\t\t Modify the recorded products.";
	cout<<"\n Product code:";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	cout<<"\n\nFile doesn't exist!";
	else
	{
		data1.open("database.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while (!data.eof())
		{
			if (pkey==pcode)
			{
		     cout<<" Product new code:";
		 	 cin>>c;
		 	 cout<<" Name of the product:";
		 	 cin>>n;
		 	 cout<<" Price:";
		 	 cin>>p;
		 	 cout<<" Disount:";
		 	 cin>>d;
		 	 data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" "<<"\n";
		 	 cout<<"\n\n\t\t\t Record edited.";
		  	 token++;
			}
		 else
		 {
		  data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		 }
		 data>>pcode>>pname>>price>>dis;	
		 }
	data.close();
	data1.close();
	
	remove("database.txt");
	rename("database1.txt","database.txt");
	
	if(token==0)
	cout<<"\n\n Record not found sorry!";	
	}	
}

//this code is to remove products
void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\t\t\t Delete product";
	cout<<"\n\n\t Product code:";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"File doesn't exist.";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
			 cout<<"\n\n\t Product deleted successfully";
			 token++;
			}
			else
			{
			 data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
		 cout<<"\n\n Record not found";
		}
	}
}

//this code is for listing
void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n__________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

//This code is for recipt
void shopping::receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t Available Products ";
	data.open("database.txt",ios::in);
	if(!data)
	{
	 cout<<"\n Enter database";
	}
	else
	{
	 data.close();
	 
	 list();
	 cout<<"\n\t\t\t\t _________________________________________________________\n";	
	 cout<<"\t\t\t\t|		Please place the order			  |";
	 cout<<"\n\t\t\t\t|_________________________________________________________|\n";
	 do
	 {
	 	m:
	 	cout<<"\n Enter product code:";
	 	cin>>arrc[c];
	 	cout<<" Enter the product quantity:";
	 	cin>>arrq[c];
	 	for(int i=0; i<c; i++)
	 	{
	 		if(arrc[c]==arrc[i])
			 {
			 	cout<<"\n Duplicate product code. Please try again!";
			 	goto m;
			 }	
		}
		c++;
		cout<<"\n Do you want to buy another product? if yes then press y else n : ";
		cin>>choice;
	 }
	 while (choice =='y');
	 
	 cout<<"\n\n\n\t\t_____________________RECIPT_________________________\n";
	 cout<<"\nProduct no\tPtoduct name\tproduct qunt\tPrice\tAmount\t\tWith disc\n";
	 for (int i=0; i<c; i++)
	 {
	 	data.open("database.txt",ios::in);
	 	data>>pcode>>pname>>price>>dis;
	 	while(!data.eof())
	 	{
	 		if(pcode==arrc[i])
			 {
			 	amount=price*arrq[i];
			 	dis=amount-(amount*dis/100);
			 	total=total+dis;
			 	cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
			 }	
			 data>>pcode>>pname>>price>>dis;
		}
	 }
	 data.close();
	}	
	cout<<"\n_________________________________________________________________________________\n";
	cout<<"Total Amount:"<<total<<"\n" ;
}

int main(){
	shopping s;
	s.menu();
}
