# Login System using c++

### **You can change database.txt to Example.dat**


### **Header**

```c++
#include <iostream>
#include <windows.h>
#include <istream>
#include <fstream>
using namespace std;
```

### **Class**
```c++
class LoginSystem {
public: /* make sure it's public, if you use private you will definitely get an error */
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
```


### **Main**
```c++
int main()
{
	LoginSystem sys;
	sys.Menu();

	return 0;
}
```

#### **MIT License**
```txt
MIT License

Copyright (c) 2021 JoshuaRVL

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
