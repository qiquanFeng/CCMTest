#ifndef QHTABLECONTENT_H
#define QHTABLECONTENT_H

#include <QDialog>
#include "ui_QHTableContent.h"
#include "globaldefine.h"
#include <QSqlTableModel>

struct _HisConfigRecord 
{
	int id;
	QVariant classfy;
	QVariant item;
	QVariant itemsuffix1;
	QVariant itemsuffix2;
	QVariant key;
	QVariant value1;
	QVariant reserve;
	QVariant note;
};

class QHTableContent : public QDialog
{
	Q_OBJECT

public:
	QHTableContent(QWidget *parent = 0, QString strTable = QString());
	~QHTableContent();

public:
	Ui::QHTableContent ui;
	QSqlTableModel *custommodel;
	_HisConfigRecord* copyrecords;
	int copyrecordscount;
	QString runtablename;

public slots:
	void customMenuRequested(QPoint pos);
	void changeCustomTableSelect(const QString& tablename);
	void deleteRows(); 
	void insertRows();
	void copycustomrecords();
	void parserrecords();
	void savecustomchange();
	void updatecustomdata();
};

#endif // QHTABLECONTENT_H
