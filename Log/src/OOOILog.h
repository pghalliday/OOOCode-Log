#ifndef OOOILog_H
#define OOOILog_H

#include "OOOCode.h"

#define OOOInterface OOOILog
OOOVirtuals
	OOOVirtual(void, print, char * szMessage, ...)
OOOVirtualsEnd
#undef OOOInterface

#endif
