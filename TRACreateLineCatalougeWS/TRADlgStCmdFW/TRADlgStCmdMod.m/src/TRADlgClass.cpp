// TRADlgClass.cpp

// Header Files


#include "TRADlgClass.h"
#include "CATApplicationFrame.h"
#include "CATDlgGridConstraints.h"
#include "CATMsgCatalog.h"
#ifdef TRADlgClass_ParameterEditorInclude
#include "CATIParameterEditorFactory.h"
#include "CATIParameterEditor.h"
#include "CATICkeParm.h"
#endif

// Constructor

TRADlgClass::TRADlgClass() : CATDlgDialog ((CATApplicationFrame::GetApplicationFrame())->GetMainWindow(),"TRADlgClass",CATDlgWndBtnOKCancel|CATDlgGridLayout)

{

 _pFrame = NULL;
 _Point1Label = NULL;
 _Point2Label = NULL;
 _Point1SelectorList = NULL;
 _Point2SelectorList = NULL;

}

// Destructor
//-------------------------------------------------------------------------
TRADlgClass::~TRADlgClass()
{
 _pFrame = NULL;
 _Point1Label = NULL;
 _Point2Label = NULL;
 _Point1SelectorList = NULL;
 _Point2SelectorList = NULL;

}

void TRADlgClass::Build()
{
	
 _Point1Label = new CATDlgLabel(this, "Point1");
 _Point1Label -> SetGridConstraints(0, 0, 1, 1, CATGRID_4SIDES);

 _Point2Label = new CATDlgLabel(this, "Point2");
 _Point2Label -> SetGridConstraints(1, 0, 1, 1, CATGRID_4SIDES);

 _Point1SelectorList = new CATDlgSelectorList(this, "Point1SelectorList");
 _Point1SelectorList -> SetVisibleTextHeight(1);
 _Point1SelectorList -> SetVisibleTextWidth(10);
 _Point1SelectorList -> SetGridConstraints(0, 1, 1, 1, CATGRID_4SIDES);
 
 _Point2SelectorList = new CATDlgSelectorList(this, "Point2SelectorList");
 _Point2SelectorList -> SetVisibleTextHeight(1);
 _Point2SelectorList -> SetVisibleTextWidth(10);
 _Point2SelectorList -> SetGridConstraints(1, 1, 1, 1, CATGRID_4SIDES);
 
 _Point1SelectorList->SetLine("No Selection");
 _Point2SelectorList->SetLine("No Selection");
 
}


void TRADlgClass::SetPoint1SelectorList(const CATUnicodeString &Name)
{

	_Point1SelectorList->ClearLine();
	_Point1SelectorList->SetLine(Name);
	ClearSelectForPoint1SelectorList();
	//SetSelectForPoint1SelelctorList();
	int TableRow = 0;
	_Point1SelectorList->SetSelect(&TableRow, 1,0);
	ClearSelectForPoint2SelectorList();

}

void TRADlgClass::SetPoint2SelectorList(const CATUnicodeString &Name)
{

	_Point2SelectorList->ClearLine();
	_Point2SelectorList->SetLine(Name);
	ClearSelectForPoint2SelectorList();
	//SetSelectForPoint2SelelctorList();
	int TableRow = 0;
	_Point2SelectorList->SetSelect(&TableRow, 1,0);
	ClearSelectForPoint1SelectorList();

}

void TRADlgClass::SetSelectForPoint1SelelctorList()
{
	int TableRow = 0;
	_Point1SelectorList->SetSelect(&TableRow, 1,1);
}

void TRADlgClass::SetSelectForPoint2SelelctorList()
{
	int TableRow = 0;
	_Point2SelectorList->SetSelect(&TableRow, 1,1);
}

void TRADlgClass::ClearSelectForPoint1SelectorList()
{
	
	_Point1SelectorList->ClearSelect();
}

void TRADlgClass::ClearSelectForPoint2SelectorList()
{
	
	_Point2SelectorList->ClearSelect();
}

CATDlgSelectorList * TRADlgClass::GetPoint1SelectorList()
{
    return _Point1SelectorList;
}

CATDlgSelectorList * TRADlgClass::GetPoint2SelectorList()
{
    return _Point2SelectorList;
}

void TRADlgClass::SetName(int iFieldNumber , CATUnicodeString iName )
{
    // Writes the name of the selected objet in the active field.
    // Replaces it if the object was already selected.
    
    switch (iFieldNumber )
    {
    case 1 : { _Point1SelectorList -> SetLine ( iName , 0 , CATDlgDataModify ); return; }
    case 2 : { _Point2SelectorList   -> SetLine ( iName , 0 , CATDlgDataModify ); return; }
    
    }
    return ;
}
