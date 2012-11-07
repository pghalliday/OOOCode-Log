#include "opentv.h"
#include "assert.h"
#include "OOODebugLog.h"
#include "OOOLogReporter.h"
#include "OOOUnitTestsRun.h"


void main(void)
{
	/* run the tests first */
	OOODebugLog * pDebugLog = OOOConstruct(OOODebugLog);
	OOOLogReporter * pReporter = OOOConstruct(OOOLogReporter, OOOCast(OOOILog, pDebugLog));
	OOOUnitTestsRun(OOOCast(OOOIReporter, pReporter));
	OOODestroy(pReporter);
	OOODestroy(pDebugLog);

	while (TRUE) {
		// Do nothing
	}
}
