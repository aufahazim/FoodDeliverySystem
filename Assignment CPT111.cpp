#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


// functions Declaration
void menu(string menuName[], double menuprice[], int quantity[]);
void createMenu();
void addMenu();
void updatePrices();
void restProfit();
void deliveryTimes();
void foodmenu(string menuName[], double menuprice[], string foodCode[], int menuStock[]);
void deliveryOrder(string menuName[],double menuprice[], string foodCode[], int quantity[], int menuStock[]);
void custorder(string menuName[], double menuprice[], string foodCode[], int quantity[],int menuStock[]);


int main () 
{
	// variable declaration
	const int size = 5;
	int v; 
	int phone_num;
	string cust_Name;
	string menuName[size];
	double menuprice[size];
	string foodCode[size];
	int quantity[size];
	int menuStock[size];

	// Main Menu
	cout << "\t\t\t\t\t" <<" ________________________________"  << endl;
	cout << "\t\t\t\t\t" <<"|                                |" << endl;
	cout << "\t\t\t\t\t" <<"|     Food Delivering System     |" << endl;
	cout << "\t\t\t\t\t" <<"|          * MAIN MENU *         |" << endl;
	cout << "\t\t\t\t\t" <<"|________________________________|" << endl << endl;
	cout  <<"* --------------------------------------------------- WELCOME -------------------------------------------------------- *" << endl << endl;
	
	do
	{
		// user can choose to exectue between customer menu and manager menu 
		cout << "----- Welcome to the Food Delivering System -----"<< endl << endl;
	 	cout << "*Press '(1)' for the Restaurant Manager " << endl;
		cout << "Press  '(2)' for the Customer " << endl;
		cout << "Press  '(3)' to exit the program " << endl;
		cout << "Enter your choice here : ";
		cin >> v;
	 	
		switch(v) //user input will be verify and execute according to the input
		{
	
			case 1: // if the user input is 1 so the program will execute the menu functions
				cout << endl << endl;
				cout << "********** Welcome To The Manager Menu **********" << endl << endl;
				menu(menuName, menuprice, quantity);
				break;
			case 2: // if the user input is  so the program will execute the order functions
				cout << endl << endl;
				cout << "********** Welcome To The Customer Menu **********" << endl << endl;
				cin.ignore();
				cout << "PLease Enter your Name: ";
				getline(cin, cust_Name);
				cout << "Please Enter Your Phone Number: ";
				cin >> phone_num;
				cout << endl;
				foodmenu(menuName, menuprice, foodCode, menuStock);
				break;
			case 3: // if the user input is 0 so the program will exit the program
				cout << "\t Exit.....";
				break;
			default: // if the input is wrong the program will display error and execute the menu again
				cout << endl;
				cout << "--------- ERROR ----------" << endl;
				cout << "Please Enter Your Choice Again"<< endl << endl;
				continue;
		}
	}while (!(v==1 ||v==2 || v==0));
	
	
	
	return 0;
}	
void menu(string menuName[], double menuprice[], int quantity[]) // this is the manager menu
{
	int choice;
	
	do
	{
		// this program will ask user(manager) to enter the choice
		cout << endl;
		cout << "Press '1' if you want to create your Menu" << endl;
		cout << "Press '2' if you want to update your Menu" << endl;
		cout << "Press '3' to update your Food Price" << endl;
		cout << "Press '4' to Accept orders and Delivery Times" << endl;
		cout << "Press '5' to Calculate total sales for the day" << endl;
		cout << "Please Enter: ";
		 
		cin >> choice;
	
		if(choice==1) // if the user enter 1 the program will execute createMenu function
		{
			createMenu();
			break;
		}
		else if(choice==2) // if the user enter 1 the program will execute addMenu function
		{
			addMenu();
			break;
		}
		else if (choice==3) // if the user enter 1 the program will execute updatePrices function
		{
			updatePrices();
			break;
		}
		else if (choice==4) // if the user enter 1 the program will execute deliveryTimes function
		{
			deliveryTimes();
			break;
		}
		else if (choice==5) // if the user enter 1 the program will execute restProfit function
		{
			restProfit();
			break;
		}
		else if(choice!=1 || choice!=2 || choice!=3 || choice!=4 || choice!=5) // if the user not enter either 1,2,3 or 4 the program will display error and ask user to enter the input again
		{
			cout << endl;
	 		cout << "---------- Error ----------"<< endl;
	 		cout << "Please enter your choice again" << endl << endl;
	 		continue;
		}
	}while(!(choice == 1 || choice == 2 || choice == 3 || choice == 4));
}
void createMenu() // this is the createMenu function for user to enter new food into the menu
{
	int size;
	cout << endl;
	remove("MenuFile.txt");  // this will clear all the existing data in the file to create the new data
	cout << "*--------------- Create menu --------------* " << endl << endl;
	do
	{
		cout << "Please enter your Menu Size : ";  // program will ask user to enter the size of the menu intended
		cin >> size;
		if(size < 0)
		{
			cout << endl;
			cout << "\tError..." << endl; // if the user enter wrong input the program will display error
			cout << "Please enter the size again." << endl << endl; 
		}	
	}while(size <0); // if the user enter wrong input the program will ask user to enter the input again
	for( int i=0; i<size; i++)
	{
	ofstream myFile;
	string foodname;
	double foodprice;
	string foodcode;
	int foodStock;
	
	myFile.open("MenuFile.txt",ios::app);  // open the file 
		
		cout << endl;
		cout << "Enter the Food Code :"; // user enter the foodcode
		cin >> foodcode;
		
		cout << "Enter your Food Name :";  // user enter the food name
		cin.ignore();
		getline (cin, foodname);

		cout << "Enter your Food Price :";  // user enter the food price
		cin >> foodprice;
		
		cout << "Enter the Food Stock :";
		cin >> foodStock;
		
		// these line will save all the data entered by user into the file
		myFile << foodcode << "\t"; 
		myFile << foodname << "\t";
		myFile << foodprice << "\t";
		myFile << foodStock << endl;
		myFile.close();
	}
}
void addMenu() // this is the createMenu function for user to add new food into the menu
{
	int sz;
	
	cout << endl;
	cout << "*--------------- Add menu --------------* " << endl << endl;
do
	{
		cout << "Please enter your Menu Size : ";  // program will ask user to enter the size of the menu intended
		cin >> sz;
		if(sz < 0)
		{
			cout << endl;
			cout << "\tError..." << endl; // if the user enter wrong input the program will display error 
			cout << "Please enter the size again." << endl << endl;
		}	
	}while(sz <0); // if the user enter wrong input the program will ask user to enter the input again
	for( int i=0; i<sz; i++)
	{
		// variable declaration
	ofstream myFile;
	string foodname;
	double foodprice;
	string foodcode;
	int foodStock;
	
	myFile.open("MenuFile.txt",ios::app); // open the file
		
		cout << endl;
		cout << "Enter the Food Code :"; // user enter the foodcode
		cin >> foodcode;
	
		cout << "Enter your Food Name : "; // user enter the food name
		cin.ignore();
		getline (cin, foodname);

		cout << "Enter your Food Price : "; // user enter the food price
		cin >> foodprice;
		
		cout << "Enter the Food Stock :";
		cin >> foodStock;
		
		// these line will save all the new data entered by user into the file
		myFile << foodcode << "\t";
		myFile << foodname << "\t";
		myFile << foodprice << "\t";
		myFile << foodStock << endl;
		myFile.close();
	}
}
void updatePrices()
{	
	// variable declaration
	int size = 5;
	string foodCode[size];
	string menuName[size];
	double menuprice[size];
	int menuStock[size];
	string choice;
	double newprice;
	char repeat;
	do
	{
		ifstream MyFile;
		MyFile.open("MenuFile.txt"); // open the file
		cout << endl;
		cout << "---------- Update Price ----------" << endl << endl;
		for (int i=0; i <size; i++)
		{
			
			getline (MyFile, foodCode[i],  '\t'); // the program will read the food code from the file
			getline (MyFile, menuName[i], '\t'); // the program will read the food name from the file
			MyFile >> menuprice[i], '\t'; // the program will read the food price from the file
			MyFile >> menuStock[i]; // the program will read the food stock from the file
			MyFile.ignore();
		}
			MyFile.close();
			
			jump:
			cout << "Which Menu do you want to update the prices. " << endl; // program ask user the menu that they want to update the price
			cout << "Please enter the foodcode of the Menu :"; // program ask user to eenter foodcode
			cin >> choice;
			
			jump2:
			for (int i=0; i<size; i++)
			{
				if (choice == foodCode[i]) // program validate the user input
				{
					goto jump3;
				}
			}
			cout << "\tInvalid input..." << endl; // if the input wrong program will ask again
			cout << "Please re-enter the foodcode of the Menu :";
			cin >> choice;
			goto jump2;
			
			jump3:
			int j=-1;
			do
			{
				j++;
			}while (choice != foodCode[j]);
			
			cout << "Enter the new price for the food :"; // program ask user to enter the new prices for the food
			cin >> newprice;
			menuprice[j] = newprice; // price will be add into the array
			cout << endl;
			cout << " ----> New Prices for " << " " << menuName[j] << " is Rm" <<menuprice[j] << endl; // program will display the food that user just update the new price
			
			ofstream myFile;
			myFile.open("MenuFile.txt"); //open the menu file 
			
			for (int i=0; i <size; i++)
			{
				// program will save and update the new proces in the file 
				myFile << foodCode[i] << "\t";
				myFile << menuName[i] << "\t";
				myFile << menuprice[i] << "\t";
				myFile << menuStock[i] << endl;
				
			}
			myFile.close();
		cout << endl;
		cout <<"Do you want to update more prices?" << endl; // program will ask user if they want update another food price
		cin >> repeat;
		
	}while ( repeat=='y' || repeat =='Y');// program will validate the user input

}
void foodmenu(string menuName[],double menuprice[], string foodCode[], int menuStock[]) // this is the order function for the customer
{
	// variable declaration
	string foodname;
	int size=5;
	double foodprice;
	char shouldContinue;
	int quantity [size];
	double sum;
	int i;
	double custSum =0;
	int deliverytime;
	

	ifstream MyFile;
	MyFile.open("MenuFile.txt"); // open the file
	
	
	cout << "|*--------------- Menu ---------------*|"<< endl;// menu that will display the food menu from the file
	cout << "| (Code)    (Name)      (Price)        |"<<endl;
	cout << "|--------------------------------------|"<< endl;
	for ( int i=0; i<size; i++)
	{
		getline (MyFile, foodCode[i],  '\t'); // the program will read the foodcode from the file
		getline (MyFile, menuName[i], '\t'); // the program will read the foodcode from the file
		MyFile >> menuprice[i], '\t'; // the program will read the foodcode from the file
		MyFile >> menuStock[i];
		
		// this will display the read data from the file
		cout << "  (" << foodCode[i] << ")" << "\t";
		cout << menuName[i]  << "\t $" << menuprice[i] << " only " << endl;
		MyFile.ignore();
	}
	cout << "|*-----------------------------------------*|"<< endl;
	cout << endl << endl;
	deliveryOrder(menuName, menuprice, foodCode, quantity, menuStock);
}
void deliveryOrder(string menuName[],double menuprice[], string foodCode[], int quantity[], int menuStock[])
{
	int deltimes;
	do 
	{
		cout << "Delivery system only available from 1100 am to 2200 pm only." << endl; // display the delivery time
		cout << "PLease enter the delivery times in 24 hour system." << endl << endl; // delivery times must be neter in 24 hour system
		cout << "Please Enter your delivery Time: "; // enter the delivery times 
		cin >> deltimes;
		if( deltimes >= 1100 && deltimes <2200 ) // if the input user enter still in delivery times program will proceed to custorder
		{
			custorder(menuName, menuprice, foodCode, quantity, menuStock); // function call for the custOrder function
		}
		else if( deltimes < 1100 && deltimes > 2200) // if the user enter wrong input it the program will ask user again
		{
			cout << "\tinvalid Times....." << endl << endl;
		}
		//cout << "\tinvalid Times....." << endl << endl;
	}while(!(deltimes > 1100 || deltimes < 2200));
}
void custorder(string menuName[], double menuprice[], string foodCode[], int quantity[], int menuStock[]) //this is the custOrder function
{
	// variable declaration
	string custCode;
	int size=5;
	double sum;
	char shouldContinue;
	double totalSum = 0;
	int foodTotal=0;
	cout << endl << endl;
	cout <<"     *------------- Order Please -------------*" << endl << endl;
	cout <<"----- Please Enter the Code according to the Menu ----- " << endl << endl;
	do
	{	
			
			cout << "Enter the Food Code : "; // program will ask user to enter the food code from the menu
			cin >> custCode;
			
			for (int i=0; i<size; i++)
			{
				if (custCode == foodCode[i]) // program will verify if the foodcode is right or not
				{
					cout << endl;
					cout << "You Choose :" << menuName[i] << endl; //program will display the food that the user entered 
					do
					{
						cout << "Enter the Quantity : "; // progarm will ask user to enter the quantity of the food that tey want
						cin >> quantity[i];
						if(quantity[i] < 0) //input validation
						{
							cout << "\tError....." << endl;
							cout << "Please enter the right Code" << endl << endl;
						}
					}while(!(quantity[i] > 0)); // repeat the loop if the input is wrong
					if(quantity[i] < menuStock[i])
					{
						cout << menuName[i] << " Still in stock" << endl;
						sum = quantity[i] * menuprice[i]; // this line will calculate the food price
						cout << "Sum : " << sum << endl;// this line will display the food price
					}
					else if(quantity[i] > menuStock[i])
					{
						cout << "\t-->" << menuName[i] << " is out of stock" << endl;
						quantity[i] = 0;
						continue;
					}
				}
		
			}

	
		totalSum += sum; // this line will sum all the food price that user entered
		cout << endl << "would you like to add other Food ? (Y/N) : "; //this program will ask user either they want to add another food or not
		cin >> shouldContinue;
		cout << endl;
		
	}while (shouldContinue == 'Y' || shouldContinue == 'y');
	
	
	
	cout << "---------- Customer Receipt ----------" << endl; // this will display the food that customer ordered
	cout << endl;
	for (int i=0; i<size; i++)
	{
		
		cout <<"You have Ordered : " << menuName[i] << " x " << quantity[i] << endl;
	}
	cout << "--------------------------------" << endl;
	cout << "Total Payment : " << totalSum << endl;
	for(int i=0; i<size; i++)
	{
		foodTotal += quantity[i];
	}
	cout << "Total Food Ordered :" << foodTotal << endl; // This will display the total payment that cusmoter must pay
	
	// display the food delivery times based on the total food ordered by the customer
	if(foodTotal > 0 && foodTotal <= 10)// if the food less than 10 the delivery will be in 1 hours 30 minutes
	{
		cout << "The Delivery Times is 30 minutes from the order confirmation. ";
	}
	else if(foodTotal > 10 && foodTotal <=20) // if the food  more than 10 less than 20 the delivery will be in 1 hours 
	{
		cout << "The Delivery times is 1 hour from the order confirmation. ";
	}
	else if (foodTotal > 20) // if the food more than 20 the delivery will be in 1 hours 30 minutes
	{
		cout << "The Delivery times is 1 hour 30 minutes from the order confirmation. ";
	}
	else 
	{
		cout << "Order Unsuccessful";
	}
	ofstream MyFile;
	{
		
		MyFile.open("Profit.txt", ios::app); // open the file
		MyFile << totalSum << endl; // program will save the totalSum into the file
		MyFile.close();
	}
	{
		MyFile.open("Food ordered.txt"); // open the file
		MyFile << foodTotal << endl; // program will save foodtotal into the file
		MyFile << totalSum << endl; // program will save totalsum into the file
		for (int i=0; i<size; i++)
		{
			MyFile << menuName[i] << "\t"; // program will save menuName into the file
			MyFile << quantity[i] << endl; // program will save quantity into the file
		}
		MyFile.close();
	}
	
}
void restProfit ()
{
	

	int size=30;
	double orderSum[size];
	double dayProfit=0;
	ifstream MyFile;
	MyFile.open("Profit.txt"); // open the file 
	
	cout << endl;
	cout << "*---------- Total Profit ----------*" << endl << endl;
	for(int i=0; i< size; i++)
	{
		MyFile >> orderSum[i]; // read all the sales from the file 
		dayProfit += orderSum[i];	
	}
	cout << "The Total Profit of the Day is :" << dayProfit; // display total sales of the day
}
void deliveryTimes()
{
	// variable delaration
	int foodorder;
	int deltimes;
	double totalSum;
	int size = 5;
	string foodname[size];
	int quantity[size];
	ifstream MyFile;
	MyFile.open("Food Ordered.txt"); // open the file
	
	cout << endl;
	cout << "*---------- Order Confirmation ----------*" << endl << endl;
	cout << "Food Orderded :"; // display the total food ordered by the customer
	
		MyFile >> foodorder, '\n';
		MyFile >> totalSum, '\n';
		if(foodorder > 0)
			{
				for (int i=0; i<size; i++)
			{
				getline(MyFile,foodname[i], '\t'); 
				MyFile >> quantity[i], '\n';
				cout  << foodname[i] << " x " << quantity[i] << endl; // display the quantity per food that customer order
			}
			cout << "-------------------------" << endl;
			cout << "Total Payments :Rm " << totalSum << endl << endl;// display total price for the food customer order
			cout <<"\t Order Accepted..." << endl << endl;
			cout << "Total Food Ordered :" << foodorder << endl;
			
			// display the food delivery times based on the total food ordered by the customer
			if(foodorder > 0 && foodorder < 10) // if the food less than 10 the delivery will be in 30 minutes
			{
				cout << "The Delivery Times is 30 minutes from the order confirmation. ";
			}
			else if(foodorder > 10 && foodorder <20) // if the food more than 10 and less than 20 the delivery will be in 1 hour
			{
				cout << "The Delivery times is 1 hour from the order confirmation. ";
			}
			else if (foodorder > 20) // if the food more than 20 the delivery will be in 1 hours 30 minutes
			{
				cout << "The Delivery times is 1 hour 30 minutes from the order confirmation. ";
			}
		}
		else if(foodorder < 0)
		{
			cout << " Order Unsuccessful" << endl;
			cout << " The Food are Out of Stock" << endl;
		}
}
