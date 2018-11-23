#ifndef QHSHORTCUT_H
#define QHSHORTCUT_H

#include <QDialog>
#include "ui_QHShortcut.h"
#include "globaldefine.h"
#include "qoplow.h"

#define _His_ConfigSetting_MaxShortcut		37
#define _His_ConfigSetting_MaxClickItems	40

class QHShortcut : public QDialog
{
	Q_OBJECT

public:
	QHShortcut(QWidget *parent=0, int iMode = 0, QString tableName1 = QString(), QString tableName2 = QString());
	~QHShortcut();

	void fillUIPointer();
	void fillouttestitem();
	void saveshortcutinfo(); 
	void shortcutinfotointerface(int iChannel, char cKey, int iClickTime);
	void iterfacetoshortcutinfo(int iChannel, char cKey, int iClickTime);
	void listShortcutKey(int iChannel);
	void freshValidKeyComboBox(char* key, unsigned int uiCount, char prekey = '[');
	bool isKeyChecked(char key);

	char str2Key(QString strText)
	{
		if(strText.size() > 1) { return '=' ; }
		else { return strText.toLower().at(0).toAscii(); }
		return '[';
	}

	QString key2Str(char key)
	{
		if(key == '=') return tr("Button");
		else if(key >= '0' && key <= '9') return QString::fromAscii(&key, 1);
		else if(key >= 'a' && key <= 'z') { key -=	32; return QString::fromAscii(&key, 1);}
		return QString();
	}

protected:
	void closeEvent(QCloseEvent *event);

private:
	Ui::QHShortcut ui;
	QCheckBox* sccheckBox[_His_ConfigSetting_MaxShortcut];
	QPushButton* scitemAddpushButton[_His_ConfigSetting_MaxClickItems-1];
	QCheckBox* scitemcheckBox[_His_ConfigSetting_MaxClickItems];
	QComboBox* scitemcomboBox[_His_ConfigSetting_MaxClickItems];
	QCheckBox* c1itemcheckBox[_His_ConfigSetting_MaxClickItems];
	QLineEdit* c1itemlineEdit[_His_ConfigSetting_MaxClickItems];
	QPushButton* c1editpushButton[_His_ConfigSetting_MaxClickItems];
	QCheckBox* c2itemcheckBox[_His_ConfigSetting_MaxClickItems];
	QLineEdit* c2itemlineEdit[_His_ConfigSetting_MaxClickItems];
	QPushButton* c2editpushButton[_His_ConfigSetting_MaxClickItems];
	QSpinBox* scitemspinBox[_His_ConfigSetting_MaxClickItems];
	QComboBox* scitemngcomboBox[_His_ConfigSetting_MaxClickItems];
	QShortcutList listShortcutC1;
	QShortcutList listShortcutC2;
	const QString tableNameC1;
	const QString tableNameC2; 
	QList<_TestItem_Basic_Info> allitemList;
	const int ciModeChannel;

public slots:
	void slotscitemchangego(const QString& text);
	void sloteditShotcutExeC1();
	void sloteditShotcutExeC2();
	void slotinsertShotcutExe();
	void scsavebutton();
	void slotKeyOnOff(int state);
	void slotsceditchange(int index);


};

#endif // QHSHORTCUT_H
