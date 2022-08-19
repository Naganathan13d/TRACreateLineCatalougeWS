#ifndef TRADlgClass_H
#define TRADlgClass_H

#include "CATDlgDialog.h"
#include "CATDlgInclude.h"

class TRADlgClass: public CATDlgDialog
{


  DeclareResource( TRADlgClass, CATDlgDialog )

  public:

  TRADlgClass();
  virtual ~TRADlgClass();

  void Build ();

  void SetPoint1SelectorList(const CATUnicodeString &Name);

  void SetPoint2SelectorList(const CATUnicodeString &Name);

  void SetSelectForPoint1SelelctorList();
  void SetSelectForPoint2SelelctorList();

  void ClearSelectForPoint1SelectorList();
  void ClearSelectForPoint2SelectorList();

  CATDlgSelectorList * GetPoint1SelectorList();
  CATDlgSelectorList * GetPoint2SelectorList();

  void SetName(int iFieldNumber , CATUnicodeString iName );


  protected:

  private:



 CATDlgFrame*      _pFrame;
 CATDlgLabel*      _Point1Label;
 CATDlgLabel*      _Point2Label;
 CATDlgSelectorList*      _Point1SelectorList;
 CATDlgSelectorList*      _Point2SelectorList;

};

//----------------------------------------------------------------------

#endif