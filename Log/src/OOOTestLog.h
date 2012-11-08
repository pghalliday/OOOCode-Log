#ifndef OOOTestLog_H
#define OOOTestLog_H

#include "OOOCode.h"
#include "OOOILog.h"

#define OOOClass OOOTestLog
OOODeclare()
	OOOImplements
		OOOImplement(OOOILog)
	OOOImplementsEnd
	OOOExports
		OOOExport(bool, check, char * szCompare, ...)
	OOOExportsEnd
OOODeclareEnd
#undef OOOClass

#endif
