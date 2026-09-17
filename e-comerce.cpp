#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct product
{
	int id;
	string name;
	float price;
	int stock;
};
struct cart
{
	int id;
	string name;
	int quantity;
	float totalprice;
};
int main()
{
	product p[5]={
	{1, "Rice", 150, 20},
	{2, "Sugar", 120, 15},
	{3, "Oil", 450, 10},
	{4, "Flour", 100, 25},
	{5, "Milk", 80, 30}
	};
	cart c[20];
	int ccount=0;
	int choice;
	do
	{
		cout<<"\n==========GROCERY STORE==========\n";
		cout<<"1. View product\n";
		cout<<"2. Add to cart\n";
		cout<<"3. Veiw Cart\n";
		cout<<"4. Checkout\n";
		cout<<"5. Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		if(choice==1)
		{
			cout<<"\nID\tName\tPrice\tStock";
			for(int i=0;i<5;i++)
			{
				cout<<"\n"<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].price<<"\t"<<p[i].stock<<endl;
			}
		}
		else if (choice==2)
		{
			int id,qty,name;
		cout<<"Enter product ID: ";
		cin>>id;
		cout<<"Enter quantity: ";
		cin>>qty;
		bool found=false;
		for(int i=0;i<5;i++)
		{
			if(p[i].id==id)
			{
				found=true;
				if(p[i].stock>=qty)
				{
					c[ccount].id=id;
					c[ccount].name=name;
					c[ccount].quantity=qty;
					c[ccount].totalprice=qty*p[i].price;
					p[i].stock-=qty;
					ccount++;
					cout<<"Item added to cart!\n";
				}
				else 
				{cout<<"Not enough stock!\n";}
				break;
			}	
		}
	if(!found)
	{
		cout<<"Product not found!\n";
	}
}
else if(choice==3)
{
	float total=0;
	cout<<"=========CART==========";
	for(int i=0;i<ccount;i++)
	{
		cout<<c[i].name<<"\n Qty: "<<c[i].quantity<<"\nPrice: "<<c[i].totalprice<<endl;
		total+=c[i].totalprice;
	}
	cout<<"Total bill: "<<total;
}
else if(choice==4)
{
	float total=0;
	for(int i=0;i<ccount;i++)
	total+=c[i].totalprice;
	cout<<"\nTotal bill: "<<total<<endl;
	cout<<"\nThanks for shopping..........\n";
	ccount=0;
}
else if (choice==5)
{
	cout<<"Exiting program......\n";
}
else 
{
	cout<<"Invalid choice!\n";
}
}
while(choice!=5);
return 0;
}
