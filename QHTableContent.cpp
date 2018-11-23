#include "QHTableContent.h"
#include <QItemSelection>
#include <QSqlError>
#include <QMenu>

QHTableContent::QHTableContent(QWidget *parent, QString strTable)
	: QDialog(parent), runtablename(strTable)
{
	ui.setupUi(this);

// 	ui.customcomboBox->setVisible(false);

	copyrecords			=	0;
	copyrecordscount	=	0;
	custommodel			=	0;

	QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
	customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

	if (!customdb.open()){
		QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与HisFX3Custom.s3db的连接"), (customdb.lastError()).text());
		return;
	}

	ui.customcomboBox->addItems(customdb.tables());

	custommodel		= new QSqlTableModel(this, customdb);

	if(ui.customcomboBox->count()){
		custommodel->setTable(ui.customcomboBox->currentText());
		custommodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
		custommodel->setSort(0, Qt::AscendingOrder);
		custommodel->select();
	}

	ui.customtableView->setModel(custommodel);
	ui.customtableView->setSortingEnabled(false);

	// 	ui.customtableView->hideColumn(0);

	ui.customtableView->setColumnWidth(1,50);
	ui.customtableView->setColumnWidth(2,50);
	ui.customtableView->setColumnWidth(3,70);
	ui.customtableView->setColumnWidth(4,70);
	ui.customtableView->setColumnWidth(5,70);
	ui.customtableView->setColumnWidth(6,170);
	ui.customtableView->setColumnWidth(7,50);
	ui.customtableView->setColumnWidth(8,70);

	connect(ui.customtableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customMenuRequested(QPoint)));
	connect(ui.customcomboBox, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(changeCustomTableSelect(const QString&)));
	connect(ui.customsavepushButton, SIGNAL(released()), this, SLOT(savecustomchange()));
	connect(ui.customfreshpushButton, SIGNAL(released()), this, SLOT(updatecustomdata()));

	if(runtablename != ui.customcomboBox->currentText()) ui.customcomboBox->setCurrentIndex(ui.customcomboBox->findText(runtablename));
}

QHTableContent::~QHTableContent()
{
	QStringList strlistName	=	 QSqlDatabase::connectionNames();
	bool bmove	=	false;
	if(custommodel)
	{
		delete custommodel;
		custommodel = 0;
	}

	if (strlistName.contains("custom"))
	{
		QSqlDatabase customdb = QSqlDatabase::database("custom", false);
		if(customdb.isOpen())
			customdb.close();
		bmove	=	true;
	}

	if(bmove)
		QSqlDatabase::removeDatabase("custom");

	if (copyrecords)
	{
		delete[] copyrecords;
		copyrecords	=	0;
	}
}

void QHTableContent::customMenuRequested(QPoint pos)
{
	QMenu menu(this);

	QAction* deleterowsAct = new QAction(QTextCodec::codecForName( "GBK")->toUnicode("&删除行"), this);
	connect(deleterowsAct, SIGNAL(triggered()), this, SLOT(deleteRows()));

	QAction* insertrowAct = new QAction(QTextCodec::codecForName( "GBK")->toUnicode("&添加行"), this);
	connect(insertrowAct, SIGNAL(triggered()), this, SLOT(insertRows()));

	QAction* copyrecordAct = new QAction(QTextCodec::codecForName( "GBK")->toUnicode("&复制行数据"), this);
	connect(copyrecordAct, SIGNAL(triggered()), this, SLOT(copycustomrecords()));

	QAction* insertrecordAct = new QAction(QTextCodec::codecForName( "GBK")->toUnicode("&插入行数据"), this);
	connect(insertrecordAct, SIGNAL(triggered()), this, SLOT(parserrecords()));

	// 	insertrecordAct->setEnabled(false);

	menu.addAction(deleterowsAct);
	menu.addSeparator();
	menu.addAction(insertrowAct);
	menu.addSeparator();
	menu.addAction(copyrecordAct);
	menu.addSeparator();
	menu.addAction(insertrecordAct);

	menu.exec(mapToGlobal(pos));
}

void QHTableContent::copycustomrecords()
{
	QItemSelection selection(ui.customtableView->selectionModel()->selection() );

	QList<int> rows;
	foreach( const QModelIndex & index, selection.indexes() ){
		rows.append(index.row());
	}

	qSort( rows );

	if (!rows.count())
	{
		ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("没有选中要复制的行数据"));
		return;
	}

	int prev = -1, current;
	copyrecordscount	=	0;
	for( int i = 0; i < rows.count(); ++i) {
		current = rows[i];
		if( current != prev ) {
			prev = current;
			++copyrecordscount;
		}
	}

	if (copyrecords)
	{
		delete[] copyrecords;
		copyrecords	=	NULL;
	}

	copyrecords	=	new _HisConfigRecord[copyrecordscount];
	prev = -1;
	int iCount = 0;
	for( int i = 0; i < rows.count(); ++i) {
		current = rows[i];
		if( current != prev ) {
			prev = current;
			copyrecords[iCount].id				=	(custommodel->data(custommodel->index(current, 0))).toInt();
			copyrecords[iCount].classfy		=	custommodel->data(custommodel->index(current, 1));
			copyrecords[iCount].item			=	custommodel->data(custommodel->index(current, 2));
			copyrecords[iCount].itemsuffix1	=	custommodel->data(custommodel->index(current, 3));
			copyrecords[iCount].itemsuffix2	=	custommodel->data(custommodel->index(current, 4));
			copyrecords[iCount].key				=	custommodel->data(custommodel->index(current, 5));
			copyrecords[iCount].value1		=	custommodel->data(custommodel->index(current, 6));
			copyrecords[iCount].reserve		=	custommodel->data(custommodel->index(current, 7));
			copyrecords[iCount].note			=	custommodel->data(custommodel->index(current, 8));
			++iCount;
		}
	}

	// 	insertrecordAct->setEnabled(true);
	ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("复制完选中行数据行数据"));
}

void QHTableContent::parserrecords()
{
	// 	insertrecordAct->setEnabled(false);
	if(!copyrecordscount)
		return;

	QItemSelection selection(ui.customtableView->selectionModel()->selection());

	QList<int> rows;
	foreach( const QModelIndex & index, selection.indexes() ){
		rows.append( index.row() );
	}

	if(rows.count()){
		qSort( rows );
		int iIndex	=	rows[0];
		for(int i=0;	i<copyrecordscount;	++i){
			custommodel->insertRows(iIndex,1);
			custommodel->setData(custommodel->index(iIndex, 0),QVariant(iIndex));
			custommodel->setData(custommodel->index(iIndex, 1),copyrecords[i].classfy);
			custommodel->setData(custommodel->index(iIndex, 2),copyrecords[i].item);
			custommodel->setData(custommodel->index(iIndex, 3),copyrecords[i].itemsuffix1);
			custommodel->setData(custommodel->index(iIndex, 4),copyrecords[i].itemsuffix2);
			custommodel->setData(custommodel->index(iIndex, 5),copyrecords[i].key);
			custommodel->setData(custommodel->index(iIndex, 6),copyrecords[i].value1);
			custommodel->setData(custommodel->index(iIndex, 7),copyrecords[i].reserve);
			custommodel->setData(custommodel->index(iIndex, 8),copyrecords[i].note);
			++iIndex;
		}

		// 		for (int i=iIndex; i<custommodel->rowCount();	++i)
		// 		{
		// 			custommodel->setData(custommodel->index(i, 0),QVariant(i));
		// 		}
	}
	else{
		int iIndex;
		for(int i=0;	i<copyrecordscount;	++i)
		{
			iIndex	=	custommodel->rowCount();
			custommodel->insertRows(iIndex, 1);
			custommodel->setData(custommodel->index(iIndex, 0),QVariant(iIndex));
			custommodel->setData(custommodel->index(iIndex, 1),copyrecords[i].classfy);
			custommodel->setData(custommodel->index(iIndex, 2),copyrecords[i].item);
			custommodel->setData(custommodel->index(iIndex, 3),copyrecords[i].itemsuffix1);
			custommodel->setData(custommodel->index(iIndex, 4),copyrecords[i].itemsuffix2);
			custommodel->setData(custommodel->index(iIndex, 5),copyrecords[i].key);
			custommodel->setData(custommodel->index(iIndex, 6),copyrecords[i].value1);
			custommodel->setData(custommodel->index(iIndex, 7),copyrecords[i].reserve);
			custommodel->setData(custommodel->index(iIndex, 8),copyrecords[i].note);
		}
	}

	// 	custommodel->sort(0, Qt::AscendingOrder);
	ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("插入复制行数据"));
}

void QHTableContent::changeCustomTableSelect(const QString& tablename)
{
	custommodel->setTable(ui.customcomboBox->currentText());
	custommodel->setSort(0, Qt::AscendingOrder);
	custommodel->select();
	while(custommodel->canFetchMore())
		custommodel->fetchMore();
}

void QHTableContent::deleteRows()
{
	QItemSelection selection(ui.customtableView->selectionModel()->selection() );

	QList<int> rows;
	foreach( const QModelIndex & index, selection.indexes() ){
		rows.append(index.row());
	}

	qSort( rows );

	if (!rows.count())
	{
		return;
	}

	int prev = -1, current, iIndex;
	for( int i = rows.count() - 1; i >= 0; --i) {
		current = rows[i];
		if( current != prev ) {
			custommodel->removeRows(current, 1 );
			iIndex = prev = current;
			ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("删除行：") % QString::number(current));
		}
	}

	// 	for (int i=iIndex; i<custommodel->rowCount();	++i)
	// 	{
	// 		custommodel->setData(custommodel->index(i, 0),QVariant(i));
	// 	}
}

void QHTableContent::insertRows()
{
	QItemSelection selection(ui.customtableView->selectionModel()->selection());

	QList<int> rows;
	foreach( const QModelIndex & index, selection.indexes() ){
		rows.append( index.row() );
	}

	if(rows.count()){
		qSort( rows );
		int iIndex = rows[0];
		custommodel->insertRows(iIndex,1);
		custommodel->setData(custommodel->index(iIndex, 0),QVariant(iIndex));
		// 		for (int i=iIndex+1; i<custommodel->rowCount();	++i)
		// 		{
		// 			custommodel->setData(custommodel->index(i, 0),QVariant(i));
		// 		}
	}
	else{
		int iIndex = custommodel->rowCount();
		custommodel->insertRows(iIndex,1);
		custommodel->setData(custommodel->index(iIndex, 0),QVariant(iIndex));
	}

	ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("插入行"));
}

void QHTableContent::savecustomchange()
{
	if(custommodel->database().transaction()){
		if(custommodel->submitAll()){
			custommodel->database().commit();
			ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("保存成功"));
		}
		else
			ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("保存失败"));
	}
	else
		ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("保存失败"));
	while(custommodel->canFetchMore())
		custommodel->fetchMore();
}

void QHTableContent::updatecustomdata()
{
	custommodel->revertAll();
	ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("恢复到改变前"));
}