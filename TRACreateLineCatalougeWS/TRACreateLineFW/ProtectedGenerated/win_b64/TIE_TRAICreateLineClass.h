#ifndef __TIE_TRAICreateLineClass
#define __TIE_TRAICreateLineClass

#include <string.h>
#include "CATBaseUnknown.h"
#include "CATMetaClass.h"
#include "CATMacForTie.h"
#include "TRAICreateLineClass.h"
#include "JS0DSPA.h"


#ifdef _WINDOWS_SOURCE
#define Exported __declspec(dllexport)
#define Imported __declspec(dllimport)
#else
#define Exported 
#define Imported 
#endif


/* To link an implementation with the interface TRAICreateLineClass */
#define declare_TIE_TRAICreateLineClass(classe) \
 \
 \
class TIETRAICreateLineClass##classe : public TRAICreateLineClass \
{ \
   private: \
      CATDeclareCommonTIEMembers \
   public: \
      CATDeclareTIEMethods(TRAICreateLineClass, classe) \
      CATDeclareIUnknownMethodsForCATBaseUnknownTIE \
      CATDeclareIDispatchMethodsForCATBaseUnknownTIE \
      CATDeclareCATBaseUnknownMethodsForTIE \
      virtual HRESULT SetPoint ( int iNum , CATISpecObject *ipiSpecOnCurve ); \
      virtual HRESULT GetPoint ( int iNum , CATISpecObject **opiSpecOnCurve ) ; \
};



#define ENVTIEdeclare_TRAICreateLineClass(ENVTIEName,ENVTIETypeLetter,ENVTIELetter) \
virtual HRESULT SetPoint ( int iNum , CATISpecObject *ipiSpecOnCurve ); \
virtual HRESULT GetPoint ( int iNum , CATISpecObject **opiSpecOnCurve ) ; \


#define ENVTIEdefine_TRAICreateLineClass(ENVTIEName,ENVTIETypeLetter,ENVTIELetter) \
HRESULT  ENVTIEName::SetPoint ( int iNum , CATISpecObject *ipiSpecOnCurve ) \
{ \
return (ENVTIECALL(TRAICreateLineClass,ENVTIETypeLetter,ENVTIELetter)SetPoint (iNum ,ipiSpecOnCurve )); \
} \
HRESULT  ENVTIEName::GetPoint ( int iNum , CATISpecObject **opiSpecOnCurve )  \
{ \
return (ENVTIECALL(TRAICreateLineClass,ENVTIETypeLetter,ENVTIELetter)GetPoint (iNum ,opiSpecOnCurve )); \
} \


/* Name of the TIE class */
#define class_TIE_TRAICreateLineClass(classe)    TIETRAICreateLineClass##classe


/* Common methods inside a TIE */
#define common_TIE_TRAICreateLineClass(classe) \
 \
 \
/* Static initialization */ \
CATDefineCommonTIEMembers(TRAICreateLineClass, classe) \
 \
 \
CATImplementTIEMethods(TRAICreateLineClass, classe) \
CATImplementIUnknownMethodsForCATBaseUnknownTIE(TRAICreateLineClass, classe, 1) \
CATImplementIDispatchMethodsForCATBaseUnknownTIE(TRAICreateLineClass, classe) \
CATImplementCATBaseUnknownMethodsForTIE(TRAICreateLineClass, classe) \
 \
HRESULT  TIETRAICreateLineClass##classe::SetPoint ( int iNum , CATISpecObject *ipiSpecOnCurve ) \
{ \
   return(((classe *)Tie_Method(NecessaryData.ForTIE,ptstat))->SetPoint (iNum ,ipiSpecOnCurve )); \
} \
HRESULT  TIETRAICreateLineClass##classe::GetPoint ( int iNum , CATISpecObject **opiSpecOnCurve )  \
{ \
   return(((classe *)Tie_Method(NecessaryData.ForTIE,ptstat))->GetPoint (iNum ,opiSpecOnCurve )); \
} \



/* Macro used to link an implementation with an interface */
#define TIE_TRAICreateLineClass(classe) \
 \
 \
declare_TIE_TRAICreateLineClass(classe) \
 \
 \
CATMetaClass * __stdcall TIETRAICreateLineClass##classe::MetaObject() \
{ \
   if (!meta_object) \
   { \
      meta_object=new CATMetaClass(&IID_TRAICreateLineClass,"TRAICreateLineClass",TRAICreateLineClass::MetaObject(),classe::MetaObject(),TIE); \
   } \
   return(meta_object); \
} \
 \
 \
common_TIE_TRAICreateLineClass(classe) \
 \
 \
/* creator function of the interface */ \
/* encapsulate the new */ \
CATImplementTIECreation(TRAICreateLineClass, classe) \
 \
/* to put information into the dictionary */ \
static CATFillDictionary DicTRAICreateLineClass##classe(classe::MetaObject(),TRAICreateLineClass::MetaObject(),(void *)CreateTIETRAICreateLineClass##classe)



/* Macro used to link an implementation with an interface */
/* This TIE is chained on the implementation object */
#define TIEchain_TRAICreateLineClass(classe) \
 \
 \
declare_TIE_TRAICreateLineClass(classe) \
 \
 \
CATMetaClass * __stdcall TIETRAICreateLineClass##classe::MetaObject() \
{ \
   if (!meta_object) \
   { \
      meta_object=new CATMetaClass(&IID_TRAICreateLineClass,"TRAICreateLineClass",TRAICreateLineClass::MetaObject(),classe::MetaObject(),TIEchain); \
   } \
   return(meta_object); \
} \
 \
 \
common_TIE_TRAICreateLineClass(classe) \
 \
 \
/* creator function of the interface */ \
/* encapsulate the new */ \
CATImplementTIEchainCreation(TRAICreateLineClass, classe) \
 \
/* to put information into the dictionary */ \
static CATFillDictionary DicTRAICreateLineClass##classe(classe::MetaObject(),TRAICreateLineClass::MetaObject(),(void *)CreateTIETRAICreateLineClass##classe)


/* Macro to switch between BOA and TIE at build time */ 
#ifdef CATSYS_BOA_IS_TIE
#define BOA_TRAICreateLineClass(classe) TIE_TRAICreateLineClass(classe)
#else
#define BOA_TRAICreateLineClass(classe) CATImplementBOA(TRAICreateLineClass, classe)
#endif

#endif
