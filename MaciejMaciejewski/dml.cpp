/********************************************//**
* \file   dml.cpp
* \brief  DML
* \author Maciej Maciejewski (maciej.r.maciejewski@student.put.poznan.pl)
* \date   2016-04
***********************************************/

#include "stdafx.h"
#include "MaciejMaciejewski.h"
int lineInfile(string name);

void dml::CreateR() {

	int number;
	string name;
	string nameGroup;
	string raz;
	int tymp2;
	char bufor[1000];
	char tab[1000] = { 0 };
	int tmp = 0;
	int flag = 0;
	int numer;
	ddl tymp;
	tymp.ListT();
	cout << "Chose type name wich you want add (write number first):";
	cin >> numer;
	cout << "Chose type name wich you want add (write name):";
	cin >> name;
	fstream file;
	string tabstr[100];
	file.open(name + ".txt", ios::in | ios::out);
	if (file)
	{
		cout << "Open file";
	}
	cout << "noOpen file";
	//Here I read my all pagefile
	int vwhile = 0;
	int remember = 0;
	while (!file.eof()) /* EOF - 'EndOfFile' */
	{
		getline(file, raz);
		tabstr[vwhile] = raz;
		if (raz[28] == '*' && remember==0)
		{ remember = vwhile; }
		vwhile++;
	}
	file.close();
	string chanf = tabstr[remember].substr(0, 999);
	strcpy_s(bufor, chanf.c_str());
	

	if (bufor[28] != '*')
	{
		cout << "Page IS Full -> Next";//nowa strone trzeba dodac
	}
	else {
		for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
			flag = 0;
			if (bufor[i] == '*') { //I check if here is empty slot
				bufor[i] = '1';
				flag = 1;
				if (i == 780)
				{
					bufor[28] = '1'; tymp2 = 780;
				}
				int tmpstr = 0;
				for (int kk = i + 1; kk < (i + name.size() + 1); kk++)//save to system catalog main name
				{
					//cout << bufor[kk];
					bufor[kk] = static_cast <char>(name[tmpstr]);
					//cout << bufor[kk];
					tmpstr++;
				}
				ddl tek;
				number = tek.NubmerOfFields(numer);
				int temp2 = number + 1;
				cout << temp2 << endl << endl;
				for (int j = 0; j < temp2; j++) {

					cout << endl << "Insert record:" << endl;
					cin >> nameGroup;//this is no name group but record
					tmpstr = 0;
					int tempowy = (i + 20 + j * 20);
					for (int k = tempowy; k < (tempowy + nameGroup.size()); k++)//save to system catalog record table name
					{
					///	cout << bufor[k];
						bufor[k] = static_cast <char>(nameGroup[tmpstr]);
					//	cout << bufor[k];
						tmpstr++;
					}
				}
				break;
			}


		}

	}
	string str(bufor);
	tabstr[remember] = str;



	if (tymp2 == 780 && flag == 1) {
		char test[1000];
		for (int i = 0; i < 999; i++) {
					test[i] = '*';
				}
		string str2(test);
		tabstr[vwhile] = str2;
		vwhile++;
	}

		fstream smok;		
		smok.open(name + ".txt", ios::in | ios::out );
	for (int i = 0; i < vwhile; i++) {
		
smok << tabstr[i];
if (i != vwhile-1) { smok << endl; }
	}
	smok.close();

}



/*void dml::DeleteR() {

	int number;
	string name;
	string nameGroup;
	string raz;
	char bufor[1000];
	char tab[1000] = { 0 };
	int tmp = 0;
	int numer;
	int flag;
	string namekey;
	ddl tymp;
	tymp.ListT();
	cout << "Chose type name wich you want delete (write number first):";
	cin >> numer;
	cout << "Chose type name wich you want delete (write name):";
	cin >> name;
	fstream file;
	string dwa;
	fstream smok;
	int lineall = lineInfile(name);

	file.open(name + ".txt", ios::in | ios::out);
	if (file)
	{
		cout << "Open file";
	}
	
	cout << "noOpen file";
	int line=0;
	int numberi=0;
	while (!file.eof())
	{
		line++;
		getline(file, raz);
		for (int i = 0; i < 1000; i++) {

			bufor[i] = raz[i];
		}
	}

	for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
		flag = 1;
		int tempstr = 0;

		int roz = namekey.length() - 2;
		for (int kk = (i + 20); kk < (i + 20 + roz); kk++)//save to system catalog main name
		{
			numberi = i;
			if (bufor[kk] == namekey[tempstr]) {
				flag = 0;
			}
			tempstr++;
		}

		file.close();
		if (flag == 0) {
		
		
			
				for (int kk = (i ); kk < (i + 235); kk++)//save to system catalog main name
				{					
					bufor[kk] = '*';						
					}
			
				string tabstring[100];
				string test;
				fstream smok;
				int link = 0;
				smok.open(name + ".txt", ios::in);
				while (!smok.eof())
				{
					getline(smok,test);
					string str(test);
					tabstring[link] = str;
					link++;
					
				}
				smok.close();

				tabstring[line] = bufor;
				fstream ksa;
				smok.open(name + ".txt", ios::in | ios::out );
				for (int f = 0; f < lineall; f++) {
				
					smok<<tabstring[f]<<endl;
				}		
				break; // last add
		}
	}

}
*/

int lineInfile(string name) {
	string dwa;
	fstream smok;
	int lineall = 0;
	smok.open(name + ".txt", ios::in);
	while (!smok.eof())
	{
		lineall++;
		getline(smok, dwa);
	}
	smok.close();
	return lineall;
}



void dml::ListR() {

	int number;
	string name;
	string nameGroup;
	string raz;
	char bufor[1000];
	char tab[1000] = { 0 };
	int tmp = 0;
	int numer;
	ddl tymp;
	int flag = 0;
	tymp.ListT();
	cout << "Chose type name wich you want list tupe record (write name):";
	cin >> name;
	fstream file;

	file.open(name + ".txt", ios::in | ios::out);
	if (file)
	{
		cout << "Open file"<<endl;
		int tmpstr = 0;
		while (!file.eof()) /* - 'EndOfFile' */
		{
			getline(file, raz);
			for (int i = 0; i < 1000; i++) {
				bufor[i] = raz[i];
			}
			for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
				for (int kk = i + 1; kk < (i + 220); kk++)//save to system catalog main name
				{
					if (bufor[kk] != '*') {
						cout << bufor[kk];
						flag = 1;
					}
					if (flag == 1 && bufor[kk] == '*') {
						cout << "; ";
						flag = 0;
						
					}
					
				}
				cout << endl;
			}
			cout << endl;
		}
		file.close();
		system("PAUSE");
	}
	cout << "noOpen file";
	//Here I read my all pagefile	
}

void dml::SearchR(){ //search key 
	int number;
	string name;
	string namekey;
	string nameGroup;

	string raz;
	char bufor[1000];
	char tab[1000] = { 0 };
	int tmp = 0;
	int numer;
	ddl tymp;
	int flag = 3;
	tymp.ListT();
	cout << "Chose type name wich you want list type record (write name):";
	cin >> name;
	cout << "Write key name:";
	cin >> namekey;
	namekey = namekey + "*";
	fstream file;
	file.open(name + ".txt", ios::in | ios::out);
	if (file)
	{
		cout << "Open file" << endl;
		int tmpstr = 0;
		while (!file.eof()) /* EOF - 'EndOfFile' */
		{
			getline(file, raz);
			for (int i = 0; i < 1000; i++) {
				bufor[i] = raz[i];
			}
			int ktorei=0;
			for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
				flag = 1;
				ktorei = 0;
				int tempstr = 0;
				int roz = namekey.length() - 1;
				for (int kk = (i+20); kk < (i+20+roz); kk++)//save to system catalog main name
				{		
					flag = 1;
					if (bufor[kk] != namekey[tempstr]) {
						flag = 0;
					}
					else { ktorei = i; }
						
					tempstr++;
				}

				if (flag != 0) {
					int ff=0;
					for (int kk = i + 20; kk < (i + 200); kk++)//save to system catalog main name
					{
						ff = 1;
						if (bufor[kk] != '*' && ktorei==i) {
							cout << bufor[kk];
							flag = 1;
						}
						if (flag == 1 && bufor[kk] == '*') {
							cout << "; ";
							flag = 0;
						}
					}
		//			if (ff = 1)break;
				}
			}
			cout << endl;
		}
		file.close();
		system("PAUSE");
	}
	cout << "noOpen file";
	//Here I read my all pagefile
}



void dml::DeleteR() { //deleteR 
	int number;
	string name;
	string nameGroup;
	string raz;
	int tymp2;
	char bufor[1000];
	char tab[1000] = { 0 };
	int tmp = 0;
	int flag = 0;
	int numer;
	ddl tymp;
	string namekey;
	tymp.ListT();
	cout << "Chose type name wich you want add (write number first):";
	cin >> numer;
	cout << "Chose type name wich you want add (write name):";
	cin >> name;
	cout << "Chose name record wich you want delete(write name):";
	cin >> namekey;
	fstream file;
	string tabstr[100];
	file.open(name + ".txt", ios::in | ios::out);
	if (file)
	{
		cout << "Open file";
	}
	cout << "noOpen file";
	//Here I read my all pagefile
	int vwhile = 0;
	int remember = 0;
	while (!file.eof()) /* EOF - 'EndOfFile' */
	{
		getline(file, raz);
		tabstr[vwhile] = raz;
		if ( remember == 0)
		{
			string chanf = tabstr[vwhile].substr(0, 999);
			strcpy_s(bufor, chanf.c_str()); 
			int ktorei = 0;
			for (int i = 75; i < 781; i = i + 235) { //75+235+235+235= 780
				flag = 1;
				ktorei = 0;
				int tempstr = 0;
				int roz = namekey.length() - 1;
				for (int kk = (i + 20); kk < (i + 20 + roz); kk++)//save to system catalog main name
				{
					flag = 1;
					if (bufor[kk] != namekey[tempstr]) {
						flag = 0;
					}
					else { ktorei = i; }

					tempstr++;
				}

				if (flag != 0) {
					int ff = 0;
					for (int kk = i + 20; kk < (i + 200); kk++)//save to system catalog main name
					{
						ff = 1;
						if (bufor[kk] != '*' && ktorei == i) {
							bufor[kk] ='*';
							flag = 1;
						}
						
					}
				}
			}
			remember = vwhile;
			string str(bufor);
			tabstr[remember] = str;
		}

			
vwhile++;
	
		}
		

	file.close();


	fstream smok;
	smok.open(name + ".txt", ios::in | ios::out);
	for (int i = 0; i < vwhile; i++) {

		smok << tabstr[i];
		if (i != vwhile - 1) { smok << endl; }
	}
	smok.close();

}
