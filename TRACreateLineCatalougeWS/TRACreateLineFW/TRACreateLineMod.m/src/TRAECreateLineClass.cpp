// COPYRIGHT Dassault Systemes 2022
//===================================================================
//
// TRAECreateLineClass.cpp
// Provide implementation to interface
//    TRAICreateLineClass
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Jan 2022  Creation: Code generated by the CAA wizard  Dell
//===================================================================
#include "TRAECreateLineClass.h"

// ObjectSpecsModeler
#include "CATIDescendants.h"

// MecModInterfaces Framework
#include "CATIMfBRep.h"

// ObjectSpecsModeler Framework
#include "CATISpecObject.h"     // needed to manage/query features
#include "CATISpecAttrAccess.h" // needed to access feature attributes
#include "CATISpecAttrKey.h"    // needed to access to the feature attribute values
 
CATImplementClass(TRAECreateLineClass,
                  DataExtension,
                  CATBaseUnknown,
                  CreateLine );
 

//-----------------------------------------------------------------------------
// TRAECreateLineClass : constructor
//-----------------------------------------------------------------------------
TRAECreateLineClass::TRAECreateLineClass():
    CATBaseUnknown()
{
}

//-----------------------------------------------------------------------------
// TRAECreateLineClass : destructor
//-----------------------------------------------------------------------------
TRAECreateLineClass::~TRAECreateLineClass()
{
}
 
// Link the implementation to its interface
// ---------------------------------------



//TIE or TIEchain definitions
#include "TIE_TRAICreateLineClass.h"
TIE_TRAICreateLineClass( TRAECreateLineClass);


//Methods implementation

//-----------------------------------------------------------------------------
// Implements TRAICreateLineClass::SetPoint
//-----------------------------------------------------------------------------
HRESULT TRAECreateLineClass::SetPoint (int  iNum  , CATISpecObject * ipiSpecOnCurve )
{

	CATISpecAttrAccess * piSpecAttrAccessOnCC = NULL; 
    HRESULT rc = QueryInterface(IID_CATISpecAttrAccess, (void**) & piSpecAttrAccessOnCC);
    if ( SUCCEEDED(rc) ) 
    {
		CATISpecAttrKey * piSpecAttrKeyOnInputCurve = NULL;
       if ( 1 == iNum )
       {
          piSpecAttrKeyOnInputCurve = piSpecAttrAccessOnCC->GetAttrKey("Point1");
       }
	   else
       {
          piSpecAttrKeyOnInputCurve = piSpecAttrAccessOnCC->GetAttrKey("Point2");
       }

	   if ( NULL == piSpecAttrKeyOnInputCurve )
       {
           rc = E_FAIL ;
       }else
       {
      
          CATISpecObject_var spiSpecOnCurve(ipiSpecOnCurve);
            
          if ( NULL_var != spiSpecOnCurve )
          {
            // If the feature is a Feature BRep it must be aggregated by the CC
            CATIMfBRep *pIMfBRep = NULL ;
            rc = spiSpecOnCurve->QueryInterface(IID_CATIMfBRep, (void**) & pIMfBRep);
            if ( SUCCEEDED(rc) )
            {
               CATISpecObject * pFather = spiSpecOnCurve->GetFather() ;
               if ( NULL == pFather )
               {
                  CATIDescendants * pIDescendantsOnCC = NULL ;
                  rc = QueryInterface( IID_CATIDescendants , (void**) &pIDescendantsOnCC );
                                                
                  if ( SUCCEEDED(rc) )
                  {
                     pIDescendantsOnCC->Append(spiSpecOnCurve) ;

                     pIDescendantsOnCC->Release();
                     pIDescendantsOnCC = NULL ;
                  }
               }else 
               {
                  pFather->Release();
                  pFather = NULL ;
                  rc = E_FAIL ;
               }

               pIMfBRep->Release();
               pIMfBRep = NULL ;
       
            }else rc = S_OK ; // it's not an error 

            // Sets the curve as input of the CC



	    if ( SUCCEEDED(rc) )
            {
               piSpecAttrAccessOnCC->SetSpecObject(piSpecAttrKeyOnInputCurve,spiSpecOnCurve);
            }

          }else
          {
              // The input curve pointer is null 
              piSpecAttrAccessOnCC->UnsetAttributeValue (piSpecAttrKeyOnInputCurve);
          }

          piSpecAttrKeyOnInputCurve->Release();
          piSpecAttrKeyOnInputCurve = NULL ;

		   
}
	}
	return rc ;

   
}

//-----------------------------------------------------------------------------
// Implements TRAICreateLineClass::GetPoint
//-----------------------------------------------------------------------------
HRESULT TRAECreateLineClass::GetPoint (int  iNum  , CATISpecObject ** opiSpecOnCurve )
{

	HRESULT rc = E_FAIL;

    if ( NULL == opiSpecOnCurve )
       return E_FAIL ;

    // Gets a pointer on CATISpecObject
    CATISpecAttrAccess *piSpecAttrAccessOnCC = NULL;
    rc = QueryInterface( IID_CATISpecAttrAccess , (void**) &piSpecAttrAccessOnCC );
    if ( SUCCEEDED(rc) )
    {
       CATISpecAttrKey * piSpecAttrKeyOnInputCurve = NULL;
       if ( 1 == iNum )
       {
          piSpecAttrKeyOnInputCurve = piSpecAttrAccessOnCC->GetAttrKey("Point1");
       }
       else
       {
          piSpecAttrKeyOnInputCurve = piSpecAttrAccessOnCC->GetAttrKey("Point2");
       }

       rc = E_FAIL;
       
       if ( NULL != piSpecAttrKeyOnInputCurve )
       {
          // Gets the curve
          *opiSpecOnCurve = piSpecAttrAccessOnCC->GetSpecObject(piSpecAttrKeyOnInputCurve);

          if ( NULL != *opiSpecOnCurve )
          {
              rc = S_OK ;
          } 

          piSpecAttrKeyOnInputCurve->Release();
          piSpecAttrKeyOnInputCurve = NULL ; 
       }
       
       piSpecAttrAccessOnCC->Release();
       piSpecAttrAccessOnCC = NULL ;

    }

    return rc ;

}

