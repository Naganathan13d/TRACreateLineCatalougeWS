#ifndef __TIE_TRAICreateLineFactory
#define __TIE_TRAICreateLineFactory

#include <string.h>
#include "CATBaseUnknown.h"
#include "CATMetaClass.h"
#include "CATMacForTie.h"
#include "TRAICreateLineFactory.h"
#include "JS0DSPA.h"


#ifdef _WINDOWS_SOURCE
#define Exported __declspec(dllexport)
#define Imported __declspec(dllimport)
#else
#define Exported 
#define Imported 
#endif


/* To link an implementation with the interface TRAICreateLineFactory */
#define declare_TIE_TRAICreateLineFactory(classe) \
 \
 \
class TIETRAICreateLineFactory##classe : public TRAICreateLineFactory \
{ \
   private: \
      CATDeclareCommonTIEMembers \
   public: \
      CATDeclareTIEMethods(TRAICreateLineFactory, classe) \
      CATDeclareIUnknownMethodsForCATBaseUnknownTIE \
      CATDeclareIDispatchMethodsForCATBaseUnknownTIE \
      CATDeclareCATBaseUnknownMethodsForTIE \
      virtual HRESULT CreateLine (  CATISpecObject *ipPoint1 , CATISpecObject *ipPoint2 , CATISpecObject **opLine ) ; \
};



#define ENVTIEdeclare_TRAICreateLineFactory(ENVTIEName,ENVTIETypeLetter,ENVTIELetter) \
virtual HRESULT CreateLine (  CATISpecObject *ipPoint1 , CATISpecObject *ipPoint2 , CATISpecObject **opLine ) ; \


#define ENVTIEdefine_TRAICreateLineFactory(ENVTIEName,ENVTIETypeLetter,ENVTIELetter) \
HRESULT  ENVTIEName::CreateLine (  CATISpecObject *ipPoint1 , CATISpecObject *ipPoint2 , CATISpecObject **opLine )  \
{ \
return (ENVTIECALL(TRAICreateLineFactory,ENVTIETypeLetter,ENVTIELetter)CreateLine (ipPoint1 ,ipPoint2 ,opLine )); \
} \


/* Name of the TIE class */
#define class_TIE_TRAICreateLineFactory(classe)    TIETRAICreateLineFactory##classe


/* Common methods inside a TIE */
#define common_TIE_TRAICreateLineFactory(classe) \
 \
 \
/* Static initialization */ \
CATDefineCommonTIEMembers(TRAICreateLineFactory, classe) \
 \
 \
CATImplementTIEMethods(TRAICreateLineFactory, classe) \
CATImplementIUnknownMethodsForCATBaseUnknownTIE(TRAICreateLineFactory, classe, 1) \
CATImplementIDispatchMethodsForCATBaseUnknownTIE(TRAICreateLineFactory, classe) \
CATImplementCATBaseUnknownMethodsForTIE(TRAICreateLineFactory, classe) \
 \
HRESULT  TIETRAICreateLineFactory##classe::CreateLine (  CATISpecObject *ipPoint1 , CATISpecObject *ipPoint2 , CATISpecObject **opLine )  \
{ \
   return(((classe *)Tie_Method(NecessaryData.ForTIE,ptstat))->CreateLine (ipPoint1 ,ipPoint2 ,opLine )); \
} \



/* Macro used to link an implementation with an interface */
#define TIE_TRAICreateLineFactory(classe) \
 \
 \
declare_TIE_TRAICreateLineFactory(classe) \
 \
 \
CATMetaClass * __stdcall TIETRAICreateLineFactory##classe::MetaObject() \
{ \
   if (!meta_object) \
   { \
      meta_object=new CATMetaClass(&IID_TRAICreateLineFactory,"TRAICreateLineFactory",TRAICreateLineFactory::MetaObject(),classe::MetaObject(),TIE); \
   } \
   return(meta_object); \
} \
 \
 \
common_TIE_TRAICreateLineFactory(classe) \
 \
 \
/* creator function of the interface */ \
/* encapsulate the new */ \
CATImplementTIECreation(TRAICreateLineFactory, classe) \
 \
/* to put information into the dictionary */ \
static CATFillDictionary DicTRAICreateLineFactory##classe(classe::MetaObject(),TRAICreateLineFactory::MetaObject(),(void *)CreateTIETRAICreateLineFactory##classe)



/* Macro used to link an implementation with an interface */
/* This TIE is chained on the implementation object */
#define TIEchain_TRAICreateLineFactory(classe) \
 \
 \
declare_TIE_TRAICreateLineFactory(classe) \
 \
 \
CATMetaClass * __stdcall TIETRAICreateLineFactory##classe::MetaObject() \
{ \
   if (!meta_object) \
   { \
      meta_object=new CATMetaClass(&IID_TRAICreateLineFactory,"TRAICreateLineFactory",TRAICreateLineFactory::MetaObject(),classe::MetaObject(),TIEchain); \
   } \
   return(meta_object); \
} \
 \
 \
common_TIE_TRAICreateLineFactory(classe) \
 \
 \
/* creator function of the interface */ \
/* encapsulate the new */ \
CATImplementTIEchainCreation(TRAICreateLineFactory, classe) \
 \
/* to put information into the dictionary */ \
static CATFillDictionary DicTRAICreateLineFactory##classe(classe::MetaObject(),TRAICreateLineFactory::MetaObject(),(void *)CreateTIETRAICreateLineFactory##classe)


/* Macro to switch between BOA and TIE at build time */ 
#ifdef CATSYS_BOA_IS_TIE
#define BOA_TRAICreateLineFactory(classe) TIE_TRAICreateLineFactory(classe)
#else
#define BOA_TRAICreateLineFactory(classe) CATImplementBOA(TRAICreateLineFactory, classe)
#endif

#endif
