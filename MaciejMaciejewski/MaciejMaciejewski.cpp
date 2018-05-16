#include "stdafx.h"

#include "MaciejMaciejewski.h"

/********************************************//**
* \file   MaciejMaciejewski.cpp
* \brief  MainPage
* \author Maciej Maciejewski (maciej.r.maciejewski@student.put.poznan.pl)
* \date   2016-04
***********************************************/

int main()
{

//-------------------------------------------
// Menu block:
//-------------------------------------------
	int menu;
	int DDLmenu;
	int DLLmenu;
	ddl CreateDDL;
	dml CreateDML;

	cout << "DBMS START" << endl;
	while (true)
	{
		cout << "Chose menu:" << endl;
		cout << "1. DDL" << endl;
		cout << "2. DML:" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			{
				cout << "DDL MENU" << endl;
				cout << "Chose operation:" << endl;
				cout << "1. Create a type:" << endl;
				cout << "2. Delete a type:" << endl;
				cout << "3. List all types:" << endl;
				cin >> menu;

				switch (menu)
				{
				case 1:
				{
					cout << "1. Create a type:" << endl;
					CreateDDL.CreateT();
				}
				break;
				case 2:
				{
					cout << "2. Delete a type:" << endl;
					CreateDDL.DeleteT();
				}
				break;
				case 3:
				{
					cout << "3. List all types:" << endl;
					CreateDDL.ListT();
				}
				break;
				default:
					break;
				}
		}
			break;
		case 2:
		{
			cout << "DML MENU" << endl;
			cout << "Chose operation:" << endl;
			cout << "1. Create a record:" << endl;
			cout << "2. Delete a record:" << endl;
			cout << "3. Search for a record (by primary key):" << endl;
			cout << "4. List all types of a record:" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1:
			{
				cout << "1. Create a record:" << endl;
				CreateDML.CreateR();
			}
			break;
			case 2:
			{
				cout << "2. Delete a record:" << endl;
				CreateDML.DeleteR();
			}
			break;
			case 3:
			{
				cout << "3. Search for a record (by primary key):" << endl;
				CreateDML.SearchR();
			}
			break;
			case 4:
			{
				cout << "4. List all types of a record:" << endl;
				CreateDML.ListR();
			}
			break;
			default:
				break;
			}
		}
			break;

		default:
			break;
		}
		system("cls");
	}
	cout << "The end of DBMS" << endl;
}

