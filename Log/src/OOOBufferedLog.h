#ifndef OOOBufferedLog_H
#define OOOBufferedLog_H

#include "OOOCode.h"
#include "OOOILog.h"

#define OOOClass OOOBufferedLog
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
