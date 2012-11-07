#include "OOOBufferedLog.h"
#include "OOOCode.h"
#include "OOO_vprintf.h"
#include "stdarg.h"

#define OOOClass OOOBufferedLog

OOOPrivateData
	char * szBuffer;
OOOPrivateDataEnd

OOODestructor
{
	if (OOOF(szBuffer))
	{
		O_free(OOOF(szBuffer));
	}
}
OOODestructorEnd

OOOMethod(void, append, char * szText)
{
	size_t uNewLength = O_strlen(szText);
	if (OOOF(szBuffer))
	{
		uNewLength += O_strlen(OOOF(szBuffer));
		OOOF(szBuffer) = O_realloc(OOOF(szBuffer), uNewLength + 1);
	}
	else
	{
		OOOF(szBuffer) = O_calloc(uNewLength + 1, sizeof(char));
	}
	O_strcat(OOOF(szBuffer), szText);
}
OOOMethodEnd

OOOMethod(void, print, char * szMessage, ...)
{
	va_list aArgs;
	assert(szMessage);

	va_start(aArgs, szMessage);
	OOO_vprintf(szMessage, aArgs);
	va_end(aArgs);

	OOOC(append, OOO_vprintf_szBuffer);
}
OOOMethodEnd

OOOMethod(bool, check, char * szCompare, ...)
{
	bool bCorrect = (szCompare == NULL);
	if (OOOF(szBuffer))
	{
		if (szCompare)
		{
			va_list aArgs;

			va_start(aArgs, szCompare);
			OOO_vprintf(szCompare, aArgs);
			va_end(aArgs);

			bCorrect = (O_strcmp(OOO_vprintf_szBuffer, OOOF(szBuffer)) == 0);
		}
		else
		{
			bCorrect = FALSE;
		}
		O_free(OOOF(szBuffer));
		OOOF(szBuffer) = NULL;
	}
	return bCorrect;
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
		OOOMapMethod(check)
	OOOMapMethodsEnd
}
OOOConstructorEnd

#undef OOOClass
