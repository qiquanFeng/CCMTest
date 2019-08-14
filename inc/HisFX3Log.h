#ifndef HISFX3LOG_H
#define HISFX3LOG_H

#ifndef HISFX3LOG_GLOBAL_H
#define HISFX3LOG_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QVariant>
#include <vector>
//
#ifdef HISFX3LOG_LIB
# define HISFX3LOG_EXPORT Q_DECL_EXPORT
#else
# define HISFX3LOG_EXPORT Q_DECL_IMPORT
#endif

#endif // HISFX3LOG_GLOBAL_H
#include "inc/HisGlobalDefine.h"

struct _HisLog_Item{
	unsigned int itemtype;
	QString itemkey;
	QVariant itemvalue;
};

class HISFX3LOG_EXPORT HisFX3Log
{
public:
	HisFX3Log();
	~HisFX3Log();

	void clear();
	int save(QString& projectname, bool blocal = true, bool bserver = false);
	void push_back(_HisLog_Item& logitem);
	int getserialnumber(QString& strSerialNumber);
	unsigned int getmaxtypeindex(unsigned int uistart);
	void addserialnumber();

private:
	std::vector<_HisLog_Item> logItemVector;
	 
	 int localsave(QString& projectname);
	 int serversave(QString& projectname);

	 unsigned int uiNumIndex;
};

#endif // HISFX3LOG_H