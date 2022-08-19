#include "CATLib.h"
#include "CATSessionServices.h"
#include "CATCatalogFactoryServices.h"
#include "CATOsmSUFactory.h"

#include <iostream.h>                  
#include "CATSession.h"
#include "CATUnicodeString.h"
#include "CATICatalog.h"
#include "CATISpecObject.h"
#include "CATISpecAttribute.h"


int main (int argc, char * argv[] )
{ 

	// -1- Creating a path to the catalog.

	const char *pDirName     = argv[1];
    const char *pFileName    = "TRALineCatalog.CATfct";
    char       StorageName[200];
    
    CATMakePath( pDirName , pFileName , StorageName );

	// Creating a session.

	char       *pSessionName = "Sample_Session";
    CATSession *pSession     = NULL;
    
    HRESULT rc = Create_Session( pSessionName , pSession );

	// -2- Creating the catalog.

	CATUnicodeString LineCatalogStorageName = StorageName;
    CATICatalog      *piLineCatalog          = NULL;

	rc = CreateCatalog( &LineCatalogStorageName , &piLineCatalog );

	// -3- Adding a client identification to the catalog.

	CATUnicodeString ClientId = "SAMPLES";
    
    rc = piLineCatalog->SetClientId( &ClientId );

	// -4- Creating the new Combined Curve startup in the catalog.

	CATUnicodeString LineStartUpType = "CreateLine";   
    CATUnicodeString CatalogName = "MecMod" ;
    CATUnicodeString SuperTypeName = "GeometricalElement3D";
    CATBoolean       publicSU = FALSE ;
    CATBoolean       derivableSU = FALSE ;
    CATISpecObject *piLineStartUp = NULL;

    rc = ::CATOsmSUFactory(&piLineStartUp,
                           &LineStartUpType,
                           piLineCatalog,
                           &SuperTypeName,
                           &CatalogName,
                           publicSU,
                           derivableSU) ; 


	 //  -5- Adding attributes to this startup.

	//      StartUp        Attribute Name    Attribute type    Update
    //      ------------   --------------    --------------    ------------
    //      CreateLine      Point1            tk_specobject     IN attribute
    //                      Point2            tk_specobject     IN attribute

	// Adding first attribute : Point1

	CATUnicodeString Point1 = "Point1";
    
    CATISpecAttribute *piPoint1SpecAttribute = piLineStartUp->AddAttribute(Point1, tk_specobject, sp_IN);

    // Adding first attribute : Point1

	CATUnicodeString Point2 = "Point2";
    
    CATISpecAttribute *piPoint2SpecAttribute = piLineStartUp->AddAttribute(Point2, tk_specobject, sp_IN);

	// -6- Saving the catalog.

	rc = ::SaveCatalog(&piLineCatalog, &LineCatalogStorageName);

	piLineCatalog -> Release();
    piLineCatalog = NULL;

	// Deleting session
    //------------------
    
    rc = Delete_Session( pSessionName );

	return 0;
}








