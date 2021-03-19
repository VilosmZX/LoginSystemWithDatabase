#include <iostream>
#include <windows.h>
#include <istream>
#include <fstream>
using namespace std;

class LoginSystem {
public:
	string newUser, newPass;
	string User, Pass;
	string u, p;
	int Exist = 0, Choose;

	/*Menu*/
	void Menu()
	{
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Close Program" << endl;
		cout << "Choose: ";
		cin >> Choose;
		switch (Choose)
		{
		case 1:
			Login();
			break;
		case 2:
			Register();
			break;
		case 3:
			system("cls");
			cout << "System Down In 3 Seconds from now!" << endl;
			Sleep(1000);
			system("clear"); cout << "1" << endl;
			Sleep(1000);
			system("clear"); cout << "2" << endl;
			Sleep(1000);
			system("clear"); cout << "3" << endl;
			system("clear");
			cout << "Program CLosed!";
			abort();
			break;
		}
	}

	void Register()
	{
		system("clear");
		cout << "New Username: ";
		cin >> newUser;

		cout << "New Password: ";
		cin >> newPass;

		ofstream reg("database.txt", ios::app);
		reg << newUser << " " << newPass << endl;
		system("clear");
		Menu();
	}
	
	
	void Login()
	{
		system("clear");
		cout << "Username: ";
		cin >> User;

		cout << "Password: ";
		cin >> Pass;

		ifstream log("database.txt");
		while (log >> u >> p)
		{
			if (u == User && p == Pass)
			{
				Exist = 1;
			}
		}
		log.close();
		if (Exist == 1)
		{
			cout << "Login suceeded!";
			cin.get();
			cin.get();
			system("clear");
			Menu();
		}
		else
		{
			cout << "User not found on the database.txt, pres enter to register. " << endl;
			cin.get();
			cin.get();
			system("clear");
			Register();
		}
	}
};


int main()
{
	LoginSystem sys;
	sys.Menu();

	return 0;
}
