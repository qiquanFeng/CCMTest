#include "cchooseconfigs.h"
#include "itemGlobalHeader.h"

cchooseconfigs::cchooseconfigs(QWidget *parent, QString currenselect)
	: QDialog(parent)
{
	ui.setupUi(this);
	strAllConfigList	=	HISDBCUSTOM::getTableList();
	strAllConfigList.sort();
	ui.comboBox->addItems(strAllConfigList);
	ui.comboBox->setCurrentIndex(ui.comboBox->findText(currenselect));
	
	strCurrenSelect	=	currenselect;

	strKeyOV.append("ov");

	strKeySony.append("sony");
	strKeySony.append("imx");

	strKeySamsung.append("3m2");
	strKeySamsung.append("4h5");
	strKeySamsung.append("5e2");
	strKeySamsung.append("5e8");
	strKeySamsung.append("s5k");
	strKeySamsung.append("samsung");
	strKeySamsung.append("sansung");

	strKeyHynix.append("hi");
	strKeyHynix.append("hy");

	connect(ui.cancelButton, SIGNAL(released()), this, SLOT(slotCancel()));
	connect(ui.okButton, SIGNAL(released()), this, SLOT(okbuttonclick()));
	connect(ui.allradioButton, SIGNAL(toggled(bool)), this, SLOT(allSelected(bool)));
	connect(ui.sonyradioButton, SIGNAL(toggled(bool)), this, SLOT(sonySelected(bool)));
	connect(ui.sansungradioButton, SIGNAL(toggled(bool)), this, SLOT(sansungSelected(bool)));
	connect(ui.ovradioButton, SIGNAL(toggled(bool)), this, SLOT(ovSelected(bool)));
	connect(ui.hynixradioButton, SIGNAL(toggled(bool)), this, SLOT(hynixSelected(bool)));
	connect(ui.otherradioButton, SIGNAL(toggled(bool)), this, SLOT(otherSelected(bool)));
	connect(ui.selectlineEdit, SIGNAL(textChanged ( const QString &) ), this, SLOT(textSelected( const QString &)));
	
	
}

cchooseconfigs::~cchooseconfigs()
{

}

void cchooseconfigs::okbuttonclick()
{
	strCurrenSelect	=	ui.comboBox->currentText();
	this->done(QDialog::Accepted);
}

void cchooseconfigs::slotCancel()
{
	this->done(QDialog::Rejected);
}

void cchooseconfigs::allSelected( bool checked)
{
	ui.comboBox->clear();
	ui.comboBox->addItems(strAllConfigList);
	ui.comboBox->setCurrentIndex(ui.comboBox->findText(strCurrenSelect));
}

void cchooseconfigs::sonySelected( bool checked)
{
	QStringList strTheList;
	for(int x=0;	x<strAllConfigList.size();	++x){
		bool bContain = false;
		for(int i=0;	i<strKeySony.size();	++i){
			if(strAllConfigList.at(x).contains(strKeySony.at(i), Qt::CaseInsensitive)){
				bContain	=	true;
				break;
			}
		}

		if(bContain)	strTheList.append(strAllConfigList.at(x));
	}

	ui.comboBox->clear();
	ui.comboBox->addItems(strTheList);
}

void cchooseconfigs::sansungSelected( bool checked)
{
	QStringList strTheList;
	for(int x=0;	x<strAllConfigList.size();	++x){
		bool bContain = false;
		for(int i=0;	i<strKeySamsung.size();	++i){
			if(strAllConfigList.at(x).contains(strKeySamsung.at(i), Qt::CaseInsensitive)){
				bContain	=	true;
				break;
			}
		}

		if(bContain)	strTheList.append(strAllConfigList.at(x));
	}

	ui.comboBox->clear();
	ui.comboBox->addItems(strTheList);
}

void cchooseconfigs::ovSelected( bool checked)
{
	QStringList strTheList;
	for(int x=0;	x<strAllConfigList.size();	++x){
		bool bContain = false;
		for(int i=0;	i<strKeyOV.size();	++i){
			if(strAllConfigList.at(x).contains(strKeyOV.at(i), Qt::CaseInsensitive)){
				bContain	=	true;
				break;
			}
		}

		if(bContain)	strTheList.append(strAllConfigList.at(x));
	}

	ui.comboBox->clear();
	ui.comboBox->addItems(strTheList);
}

void cchooseconfigs::hynixSelected( bool checked)
{
	QStringList strTheList;
	for(int x=0;	x<strAllConfigList.size();	++x){
		bool bContain = false;
		for(int i=0;	i<strKeyHynix.size();	++i){
			if(strAllConfigList.at(x).contains(strKeyHynix.at(i), Qt::CaseInsensitive)){
				bContain	=	true;
				break;
			}
		}

		if(bContain)	strTheList.append(strAllConfigList.at(x));
	}

	ui.comboBox->clear();
	ui.comboBox->addItems(strTheList);
}

void cchooseconfigs::otherSelected( bool checked)
{
	QStringList strTheList;
	for(int x=0;	x<strAllConfigList.size();	++x){
		bool bContain = false;
		for(int i=0;	i<strKeyHynix.size();	++i){
			if(strAllConfigList.at(x).contains(strKeyHynix.at(i), Qt::CaseInsensitive)){
				bContain	=	true;
				break;
			}
		}

		for(int i=0;	i<strKeyOV.size();	++i){
			if(strAllConfigList.at(x).contains(strKeyOV.at(i), Qt::CaseInsensitive)){
				bContain	=	true;
				break;
			}
		}

		for(int i=0;	i<strKeySamsung.size();	++i){
			if(strAllConfigList.at(x).contains(strKeySamsung.at(i), Qt::CaseInsensitive)){
				bContain	=	true;
				break;
			}
		}

		for(int i=0;	i<strKeySony.size();	++i){
			if(strAllConfigList.at(x).contains(strKeySony.at(i), Qt::CaseInsensitive)){
				bContain	=	true;
				break;
			}
		}

		if(!bContain)	strTheList.append(strAllConfigList.at(x));
	}

	ui.comboBox->clear();
	ui.comboBox->addItems(strTheList);
}
void cchooseconfigs::textSelected( const QString &)
{
	ui.allradioButton->setChecked(true);
	QStringList strTheList;
	for(int x=0;	x<strAllConfigList.size();	++x)
	{
		bool bContain = false;
			if(strAllConfigList.at(x).contains(ui.selectlineEdit->text(), Qt::CaseInsensitive))			{
				bContain	=	true;
				//break;
			}
		if(bContain)	
			strTheList.append(strAllConfigList.at(x));
	}
	
	ui.comboBox->clear();
	ui.comboBox->addItems(strTheList);
}