/********************************************//**
* \file   dml.h
* \brief  DML Header
* \author Maciej Maciejewski (maciej.r.maciejewski@student.put.poznan.pl)
* \date   2016-04
***********************************************/
#pragma once
#ifndef DML_H
#define DML_H
class dml
{
public:
	//! Create Record
	void CreateR();
	//! Delete Record
	void DeleteR();
	//! List All record from one type
	void ListR();
	//! List record from one record key
	void SearchR();

private:

};
/////////////////////////////////////////////////
//***********************************************

#endif /*DML_H*/