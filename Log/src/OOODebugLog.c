#include "OOODebugLog.h"
#include "OOOCode.h"
#include "OOO_vprintf.h"
#include "stdarg.h"

#define OOOClass OOODebugLog

OOOPrivateData
OOOPrivateDataEnd

OOODestructor
{
}
OOODestructorEnd

OOOMethod(void, print, char * szMessage, ...)
{
	va_list aArgs;

	va_start(aArgs, szMessage);
	OOO_vprintf(szMessage, aArgs);
	va_end(aArgs);

	O_debug(OOO_vprintf_szBuffer);
}
OOOMethodEnd

OOOConstructor()
{
	#define OOOInterface OOOILog
	OOOMapVirtuals
		OOOMapVirtual(print)
	OOOMapVirtualsEnd
	#undef OOOInterface

	OOOMapMethods
	OOOMapMethodsEnd
}
OOOConstructorEnd

#undef OOOClass
