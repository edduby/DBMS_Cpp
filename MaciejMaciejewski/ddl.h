/********************************************//**
* \file   ddl.cpp
 * \brief  DDL header
* \author Maciej Maciejewski (maciej.r.maciejewski@student.put.poznan.pl)
* \date   2016-04
***********************************************/

#include "MaciejMaciejewski.h"
#pragma once

#ifndef DDL_H
#define DDL_H

class ddl
{
public:
	//! Create a type
	void CreateT();
	//! Delete type
	void DeleteT();
	//!  List All type
	void ListT();
	//! Check if is SystemCatalog. If not, create it.
	void IsSystemCatalog();
	//! Create NewFile for record
	//	void newRecord(string name);
	//! Number of fields
	int NubmerOfFields(int number);	
private:

};
/////////////////////////////////////////////////
//***********************************************


#endif /*DDL_H*/