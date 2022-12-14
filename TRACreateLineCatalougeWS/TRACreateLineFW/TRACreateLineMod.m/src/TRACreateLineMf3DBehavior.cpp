// COPYRIGHT Dassault Systemes 2022
//===================================================================
//
// TRACreateLineMf3DBehavior.cpp
// Provide implementation to interface
//    CATIMf3DBehavior
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Feb 2022  Creation: Code generated by the CAA wizard  Dell
//===================================================================
#include "TRACreateLineMf3DBehavior.h"
 
CATImplementClass(TRACreateLineMf3DBehavior,
                  DataExtension,
                  CATBaseUnknown,
                  CreateLine );
 

//-----------------------------------------------------------------------------
// TRACreateLineMf3DBehavior : constructor
//-----------------------------------------------------------------------------
TRACreateLineMf3DBehavior::TRACreateLineMf3DBehavior():
    CATBaseUnknown()
{
}

//-----------------------------------------------------------------------------
// TRACreateLineMf3DBehavior : destructor
//-----------------------------------------------------------------------------
TRACreateLineMf3DBehavior::~TRACreateLineMf3DBehavior()
{
}
 
// Link the implementation to its interface
// ---------------------------------------



//TIE or TIEchain definitions
#include "TIE_CATIMf3DBehavior.h"
TIE_CATIMf3DBehavior( TRACreateLineMf3DBehavior);


//Methods implementation

//-----------------------------------------------------------------------------
// Implements CATIMf3DBehavior::IsASolid
//-----------------------------------------------------------------------------
HRESULT TRACreateLineMf3DBehavior::IsASolid () const
{

   return E_FAIL;
}

//-----------------------------------------------------------------------------
// Implements CATIMf3DBehavior::IsAShape
//-----------------------------------------------------------------------------
HRESULT TRACreateLineMf3DBehavior::IsAShape () const
{

   return S_OK;
}

//-----------------------------------------------------------------------------
// Implements CATIMf3DBehavior::IsADatum
//-----------------------------------------------------------------------------
HRESULT TRACreateLineMf3DBehavior::IsADatum () const
{

   return E_FAIL;
}

