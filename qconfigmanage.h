#ifndef QCONFIGMANAGE_H
#define QCONFIGMANAGE_H

#include <QDialog>
#include <QVector>
#include <QCheckBox>
#include "ui_qconfigmanage.h"
#include <QElapsedTimer>
#include <QTimer>

class qconfigmanage : public QDialog
{
	Q_OBJECT

public:
	qconfigmanage(QWidget *parent = 0);
	~qconfigmanage();

private slots:
	void seletALL(int state){
		if(state == Qt::Checked)
		{
			for(unsigned int x=0;	x<vectorList.size(); ++x)
				vectorList.at(x)->setChecked(true);
			if (ui.selectALL_checkBox->isChecked() && ui.selectNone_checkBox->isChecked())
			{
				ui.selectNone_checkBox->setChecked(false);
			}
		}

	}

	void seletNone(int state){
		if(state == Qt::Checked)
		{
			for(unsigned int x=0;	x<vectorList.size(); ++x)
				vectorList.at(x)->setChecked(false);		
			if (ui.selectALL_checkBox->isChecked() && ui.selectNone_checkBox->isChecked())
			{
				ui.selectALL_checkBox->setChecked(false);
			}
		}

	}

	void exportConfig();
	void importConfig();
	void renameConfig();
	void createConfig();
	void deleteConfig();
	void textSelected( const QString &);
	void slotSearchText();

private:
	Ui::qconfigmanage ui;
	QLayout *scrollLay;
	QString strDefaultCSVDir;

	void freshConfigList();
	void toCSV(QString strTableName, QString strCSVDir);
	void toXML(QString strTableName, QString strCSVDir);
	bool isDatabase(QString strPath);
	bool isSameFile(QString strPath);
	void toDataBase(QString strDesPath, QString strTableName);
	bool isTableExist(QString strTableName, QString strDataBase = QString());
	bool isTableConflic(QString strTableName, QString str3rdBasePath);
	bool deleteTable(QString strTableName, QString strDataBase);
	void createAndCopyTable(QString strDesDataBase, QString strSrcDatabase, QString strTableName);
	bool isTheCSV(QString strPath);
	bool isTheXML(QString strPath);
	void fromCSV(QString strCSV);
	void fromXML(QString strCSV);

	QTimer timerSearch;
	QElapsedTimer classTime;
	QString strOrignalText;

	QVector<QCheckBox*> vectorList;
};

#endif // QCONFIGMANAGE_H
