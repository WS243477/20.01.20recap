// 20.01.20recap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class clsUser
{
private:
	string m_sName;
	int m_iAge;
public:
	clsUser();
	clsUser(string, int);
	~clsUser();
	void SetDetails(string, int);
	void SetName(string);
	string GetName();
};

clsUser::clsUser() 
{
	m_sName = "Defualt";
	m_iAge = 0;
}

clsUser::clsUser(string sName, int iAge)
{
	m_sName = sName;
	m_iAge = iAge;
}

clsUser::~clsUser() 
{

}

void clsUser::SetDetails(string sName, int iAge)
{
	m_sName = sName;
	m_iAge = iAge;
}

void clsUser::SetName(string sName)
{
	m_sName = sName;
}

string clsUser::GetName()
{
	return m_sName;
}

class clsAdmin : public clsUser
{
private:
	bool m_bIsAdmin = true;
public:
	bool ReturnIsAdmin();

};

bool clsAdmin::ReturnIsAdmin()
{
	return m_bIsAdmin;
}

void Welcome(clsUser *objUser)
{
	string sName = "";
	cout << "Welcom " << objUser->GetName();

	cout << "\nEnter name: \n";
	cin >> sName;

	objUser->SetName(sName);

	cout << "\n you have updated you name to " << objUser->GetName();
}

void Menu(clsAdmin* objUser)
{
	int iChoice = 0;
	string sName = "";

	do
	{
		cout << "\nMake Selection\n";
		cout << "1) Change Name\n";
		cout << "2) Change Age\n";

		if (objUser->ReturnIsAdmin())
		{
			cout << "3) Change all details\n";
		}

		cout << "0) Exit\n";

		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			cout << "Enter new name:\n";
			cin >> sName;
			objUser->SetName(sName);
			cout << "you have updated you name to " << objUser->GetName() << "\n";
			break;
		case 2:
			cout << "\nindev\n";
			break;
		case 0:
		{
			cout << "Goodbye " << objUser->GetName();
			break;
		}
		case 3:
			if (objUser->ReturnIsAdmin())
			{
				objUser->SetDetails("Frank", 37);
				break;
			}
		default:
			cout << "\nInvaild entry\n";
			break;
		}
	} while (iChoice != 0);
}

int main()
{
	clsAdmin objAdmin;

	Welcome(&objAdmin);
	Menu(&objAdmin);

	return 0;
}