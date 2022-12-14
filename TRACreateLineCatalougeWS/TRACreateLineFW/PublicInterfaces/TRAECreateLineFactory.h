// COPYRIGHT Dassault Systemes 2022
//===================================================================
//
// TRAECreateLineFactory.h
// Provide implementation to interface
//    TRAICreateLineFactory

//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//EXTENSION:	CATPrtCont
//EXTENSIONTYPE:	DataExtension

//    TIE: TRAICreateLineFactory

//End CAA2 Wizard Generation Report
//
//  Jan 2022  Creation: Code generated by the CAA wizard  Dell
//===================================================================
#ifndef TRAECreateLineFactory_H
#define TRAECreateLineFactory_H

#include "TRACreateLineMod.h"
#include "CATBaseUnknown.h"
#include "CATISpecObject.h"


//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* It implements the interfaces :
*  <ol>
*  <li>@href TRAICreateLineFactory
*  </ol>
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByTRACreateLineMod TRAECreateLineFactory: public CATBaseUnknown

{
  CATDeclareClass;

  public:

  // Standard constructors and destructors for an implementation class
  // -----------------------------------------------------------------
     TRAECreateLineFactory ();
     virtual ~TRAECreateLineFactory ();

    /**
     * Implements a function from an interface.
     * @href TRAICreateLineFactory#CreateLine
     */
     HRESULT CreateLine (CATISpecObject * ipPoint1   , CATISpecObject * ipPoint2   , CATISpecObject ** opLine  ) ;


  private:
  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  TRAECreateLineFactory (TRAECreateLineFactory &);
  TRAECreateLineFactory& operator=(TRAECreateLineFactory&);

};

//-----------------------------------------------------------------------

#endif
