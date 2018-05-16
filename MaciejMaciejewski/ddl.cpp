/********************************************//**
* \file   dll.cpp
* \brief  DLL
* \author Maciej Maciejewski (maciej.r.maciejewski@student.put.poznan.pl)
* \date   2016-04
***********************************************/


#include "stdafx.h"
#include "MaciejMaciejewski.h"
#include <fstream>
#include <sstream>
void newRecord(string name);

void ddl::CreateT() {

	int number;
	string name;
	string nameGroup;
	char bufor[1000];
	char tab[1000];
	int tmp = 0;

	//	while (!liczby.eof())
	//		liczby >> tablica[tmp++];
		//liczby.close();

	cout << "Insert name of Type:" << endl;
	cin >> name;
	cout << "Insert number of fields: (min 1 max 10)" << endl;
	cin >> number;


	fstream file;
	file.open("SystemCatalog.txt", ios::in | ios::_Nocreate);
	file.close();
	if (file)
	{
		cout << "Load System Catalog Complete!" << endl;



	}
	else {
		cout << "Create new System Catalog!" << endl;
		file.open("SystemCatalog.txt", ios::app);


		for (int i = 0; i < 1000; i++) {
			tab[i] = '*';
		}

		for (int i = 0; i < 1000; i++) {
			file << tab[i];

		}
		file.close();
	//	cout << "Fill System Catalog Done!" << endl;
	}

	cout << "Done" << endl;
	file.open("SystemCatalog.txt", ios::in | ios::out);
	if (file)
	{
		cout << "Open file";
	}

	//Here I read my all pagefile
	file.read(bufor, 1000);
	cout << "adresbufora" << bufor[28];
	if (bufor[28] != '*')
	{
		cout << "System Catalog IS Full";
	}
	else {
		newRecord(name);
		for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
			if (bufor[i] == '*') { //I check if here is empty slot
				bufor[i] = '1';
				int tmpstr = 0;

				for (int kk = i + 1; kk < (i + name.size() + 1); kk++)//save to system catalog main name
				{
					//cout << bufor[kk];
					bufor[kk] = static_cast <char>(name[tmpstr]);
					//cout << bufor[kk];
					tmpstr++;
				}
				int temp;
				//temp=static_cast<int> (bufor[i + 16]); //I get how 
				bufor[i + 16] = number - 1; // I give number of fields +16 tyle potrzeba
				//cout << endl << endl << bufor[i + 16] << endl << endl;
				int temp2 = bufor[i + 16];
				//cout << temp2 << endl << endl;
				for (int j = 0; j < number; j++) {

					cout << endl << "Insert name of groups:" << endl;
					cin >> nameGroup;
					tmpstr = 0;
					int tempowy = (i + 20 + j * 20);
					for (int k = tempowy; k < (tempowy + nameGroup.size()); k++)//save to system catalog record table name
					{
					//	cout << bufor[k];
						bufor[k] = static_cast <char>(nameGroup[tmpstr]);
						//cout << bufor[k];
						tmpstr++;
					}
					file.close();
					file.open("SystemCatalog.txt", ios::in | ios::out);//save file
					//cout << bufor;
					file << bufor;
					file.close();
				}
				break;
			}
			else {
				if (i == 780) { cout << "End of Space"; }
			}
		}
	}
	file.close();
}

void ddl::DeleteT() {
	int number;
	char bufor[1000];
	char tab[1000];
	int tmp = 0;
	string das;
	string dupa;

	fstream smok;
	smok.open("SystemCatalog.txt", ios::in | ios::out);
	ListT();
	cout << "Chose what you want delete from this list:" << endl;
	cin >> number;
	if (smok)
	{
		smok.getline(bufor, 1000);

		int temp = 0;

		for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
			temp++;
			if (number == temp) {
				for (int kk = i; kk < (i + 220); kk++)//write name of the type
				{
					bufor[kk] = '*';
				}
			}
			cout << endl;
		}
		smok.close();
		//cout << bufor;
		smok.open("SystemCatalog.txt", ios::in | ios::out);//save file
		smok << bufor;
		smok.close();
		cout << endl << "If you ready press any key!";
		system("PAUSE");
	}
}

int ddl::NubmerOfFields(int number) {


	char bufor[1000];
	char tab[1000];
	int tmp = 0;
	string das;
	string dupa;
	fstream smok;
	int numer;
	smok.open("SystemCatalog.txt", ios::in | ios::out);
	if (smok)
	{
		smok.getline(bufor, 1000);

		int temp = 0;

		for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
			temp++;
			if (number == temp) {
				numer = bufor[i + 16];
			}
			cout << endl;
		}
		smok.close();
		return numer;
	}
}

void ddl::ListT() {

	int number;
	char bufor[1000];
	char tab[1000];
	int tmp = 0;
	string das;
	string dupa;

	fstream smok;
	smok.open("SystemCatalog.txt", ios::in | ios::out);

	if (smok)
	{
		cout << "Load System Catalog Complete!" << endl << endl;
		smok.getline(bufor, 1000);
		int temp = 0;
		for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
			temp++;
			cout << temp << ":";
			for (int kk = i + 1; kk < (i + 15); kk++)//write name of the type
			{
				if (bufor[kk] != '*') {
					cout << bufor[kk];
				}
			}
			cout << endl;
		}
		smok.close();
		cout << endl << "If you ready press any key!";
		system("PAUSE");
	}
}


void newRecord(string name) {

	char bufor[1000];
	char tab[1000];

	fstream file;
	file.open(name + ".txt", ios::in | ios::_Nocreate);
	file.close();
	if (file)
	{
		cout << "Exist page!" << endl;
	}
	else {
		cout << "Create new Record Page!" << endl;
		file.open(name + ".txt", ios::app);


		for (int i = 0; i < 1000; i++) {
			tab[i] = '*';
		}

		for (int i = 0; i < 1000; i++) {
			file << tab[i];
		}
		file.close();
		cout << "Page File Done!" << endl;
	}
	cout << "Done" << endl;

}






void ddl::IsSystemCatalog() {// I check 
	ofstream file;
	file.open("SystemCatalog.csv", ios::in | ios::_Nocreate);
	if (file)
	{
		cout << "Load System Catalog Complete!" << endl;
		//tu operacje na pliku
		file.close();
	}
	else {
		cout << "Create new System Catalog!" << endl;
		file.open("SystemCatalog.csv");
		file.close();


	}
}
