#ifndef QITEMEXETOOL_H
#define QITEMEXETOOL_H

#include <QDockWidget>
#include "ui_qitemexetool.h"
#include <QList>
#include <QMessageBox>
#include <QLineEdit>
#include "QHTextItemEdit.h"

struct _QItemToolItemTestInfo{
	unsigned short usItem;
	QString strItem;
	QString strItemShowText;
	QString strType;
	QString strAddInfo;
	QString strHelpInfo;
	QLineEdit* pstEdit;
}; 

class qitemexetool : public QDockWidget
{
	Q_OBJECT

public:
	qitemexetool(QWidget *parent, QStringList& listKey2);
	~qitemexetool();

	void itemtheexe(int iindex);
	void helptheexe(int iindex);
	void edittheexe(int iindex);

	QStringList listKey;

signals:
	void itemdebugsignal(unsigned short usItem, QString strAddInfo);

private:
	Ui::qitemexetool ui;
	QList<_QItemToolItemTestInfo> listitem;
	void initAllItem();
	void createItemTable();
	void testitem_pushback(unsigned short usItem, QString strItem, QString strItemShowText, QString strType, QString strAddInfo = "", QString strHelpInfo = "");
	int index;
public slots:
	void itemexe0() { itemtheexe(0); }
	void itemexe1() { itemtheexe(1); }
	void itemexe2() { itemtheexe(2); }
	void itemexe3() { itemtheexe(3); }
	void itemexe4() { itemtheexe(4); }
	void itemexe5() { itemtheexe(5); }
	void itemexe6() { itemtheexe(6); }
	void itemexe7() { itemtheexe(7); }
	void itemexe8() { itemtheexe(8); }
	void itemexe9() { itemtheexe(9); }
	void itemexe10() { itemtheexe(10); }
	void itemexe11() { itemtheexe(11); }
	void itemexe12() { itemtheexe(12); }
	void itemexe13() { itemtheexe(13); }
	void itemexe14() { itemtheexe(14); }
	void itemexe15() { itemtheexe(15); }
	void itemexe16() { itemtheexe(16); }
	void itemexe17() { itemtheexe(17); }
	void itemexe18() { itemtheexe(18); }
	void itemexe19() { itemtheexe(19); }
	void itemexe20() { itemtheexe(20); }
	void itemexe21() { itemtheexe(21); }
	void itemexe22() { itemtheexe(22); }
	void itemexe23() { itemtheexe(23); }
	void itemexe24() { itemtheexe(24); }
	void itemexe25() { itemtheexe(25); }
	void itemexe26() { itemtheexe(26); }
	void itemexe27() { itemtheexe(27); }
	void itemexe28() { itemtheexe(28); }
	void itemexe29() { itemtheexe(29); }
	void itemexe30() { itemtheexe(30); }
	void itemexe31() { itemtheexe(31); }
	void itemexe32() { itemtheexe(32); }
	void itemexe33() { itemtheexe(33); }
	void itemexe34() { itemtheexe(34); }
	void itemexe35() { itemtheexe(35); }
	void itemexe36() { itemtheexe(36); }
	void itemexe37() { itemtheexe(37); }
	void itemexe38() { itemtheexe(38); }
	void itemexe39() { itemtheexe(39); }
	void itemexe40() { itemtheexe(40); }
	void itemexe41() { itemtheexe(41); }
	void itemexe42() { itemtheexe(42); }
	void itemexe43() { itemtheexe(43); }
	void itemexe44() { itemtheexe(44); }
	void itemexe45() { itemtheexe(45); }
	void itemexe46() { itemtheexe(46); }
	void itemexe47() { itemtheexe(47); }
	void itemexe48() { itemtheexe(48); }
	void itemexe49() { itemtheexe(49); }
	void itemexe50() { itemtheexe(50); }
	void itemexe51() { itemtheexe(51); }
	void itemexe52() { itemtheexe(52); }
	void itemexe53() { itemtheexe(53); }
	void itemexe54() { itemtheexe(54); }
	void itemexe55() { itemtheexe(55); }
	void itemexe56() { itemtheexe(56); }
	void itemexe57() { itemtheexe(57); }
	void itemexe58() { itemtheexe(58); }
	void itemexe59() { itemtheexe(59); }
	void itemexe60() { itemtheexe(60); }
	void itemexe61() { itemtheexe(61); }
	void itemexe62() { itemtheexe(62); }
	void itemexe63() { itemtheexe(63); }
	void itemexe64() { itemtheexe(64); }
	void itemexe65() { itemtheexe(65); }
	void itemexe66() { itemtheexe(66); }
	void itemexe67() { itemtheexe(67); }
	void itemexe68() { itemtheexe(68); }
	void itemexe69() { itemtheexe(69); }
	void itemexe70() { itemtheexe(70); }
	void itemexe71() { itemtheexe(71); }
	void itemexe72() { itemtheexe(72); }
	void itemexe73() { itemtheexe(73); }
	void itemexe74() { itemtheexe(74); }
	void itemexe75() { itemtheexe(75); }
	void itemexe76() { itemtheexe(76); }
	void itemexe77() { itemtheexe(77); }
	void itemexe78() { itemtheexe(78); }
	void itemexe79() { itemtheexe(79); }
	void itemexe80() { itemtheexe(80); }
	void itemexe81() { itemtheexe(81); }
	void itemexe82() { itemtheexe(82); }
	void itemexe83() { itemtheexe(83); }
	void itemexe84() { itemtheexe(84); }
	void itemexe85() { itemtheexe(85); }
	void itemexe86() { itemtheexe(86); }
	void itemexe87() { itemtheexe(87); }
	void itemexe88() { itemtheexe(88); }
	void itemexe89() { itemtheexe(89); }
	void itemexe90() { itemtheexe(90); }
	void itemexe91() { itemtheexe(91); }
	void itemexe92() { itemtheexe(92); }
	void itemexe93() { itemtheexe(93); }
	void itemexe94() { itemtheexe(94); }
	void itemexe95() { itemtheexe(95); }
	void itemexe96() { itemtheexe(96); }
	void itemexe97() { itemtheexe(97); }
	void itemexe99() { itemtheexe(98); }
	void itemexe100() { itemtheexe(100); }
	void itemexe101() { itemtheexe(101); }
	void itemexe102() { itemtheexe(102); }
	void itemexe103() { itemtheexe(103); }
	void itemexe104() { itemtheexe(104); }
	void itemexe105() { itemtheexe(105); }
	void itemexe106() { itemtheexe(106); }
	void itemexe107() { itemtheexe(107); }
	void itemexe108() { itemtheexe(108); }
	void itemexe109() { itemtheexe(109); }
	void itemexe110() { itemtheexe(110); }
	void itemexe111() { itemtheexe(111); }
	void itemexe112() { itemtheexe(112); }
	void itemexe113() { itemtheexe(113); }
	void itemexe114() { itemtheexe(114); }
	void itemexe115() { itemtheexe(115); }
	void itemexe116() { itemtheexe(116); }
	void itemexe117() { itemtheexe(117); }
	void itemexe118() { itemtheexe(118); }
	void itemexe119() { itemtheexe(119); }
	void itemexe120() { itemtheexe(120); }
	void itemexe121() { itemtheexe(121); }
	void itemexe122() { itemtheexe(122); }
	void itemexe123() { itemtheexe(123); }
	void itemexe124() { itemtheexe(124); }
	void itemexe125() { itemtheexe(125); }
	void itemexe126() { itemtheexe(126); }
	void itemexe127() { itemtheexe(127); }
	void itemexe128() { itemtheexe(128); }
	void itemexe129() { itemtheexe(129); }
	void itemexe130() { itemtheexe(130); }
	void itemexe131() { itemtheexe(131); }
	void itemexe132() { itemtheexe(132); }
	void itemexe133() { itemtheexe(133); }
	void itemexe134() { itemtheexe(134); }
	void itemexe135() { itemtheexe(135); }
	void itemexe136() { itemtheexe(136); }
	void itemexe137() { itemtheexe(137); }
	void itemexe138() { itemtheexe(138); }
	void itemexe139() { itemtheexe(139); }
	void itemexe140() { itemtheexe(140); }
	void itemexe141() { itemtheexe(141); }
	void itemexe142() { itemtheexe(142); }
	void itemexe143() { itemtheexe(143); }
	void itemexe144() { itemtheexe(144); }
	void itemexe145() { itemtheexe(145); }
	void itemexe146() { itemtheexe(146); }
	void itemexe147() { itemtheexe(147); }
	void itemexe148() { itemtheexe(148); }
	void itemexe149() { itemtheexe(149); }


	void helpexe0() { helptheexe(0); }
	void helpexe1() { helptheexe(1); }
	void helpexe2() { helptheexe(2); }
	void helpexe3() { helptheexe(3); }
	void helpexe4() { helptheexe(4); }
	void helpexe5() { helptheexe(5); }
	void helpexe6() { helptheexe(6); }
	void helpexe7() { helptheexe(7); }
	void helpexe8() { helptheexe(8); }
	void helpexe9() { helptheexe(9); }
	void helpexe10() { helptheexe(10); }
	void helpexe11() { helptheexe(11); }
	void helpexe12() { helptheexe(12); }
	void helpexe13() { helptheexe(13); }
	void helpexe14() { helptheexe(14); }
	void helpexe15() { helptheexe(15); }
	void helpexe16() { helptheexe(16); }
	void helpexe17() { helptheexe(17); }
	void helpexe18() { helptheexe(18); }
	void helpexe19() { helptheexe(19); }
	void helpexe20() { helptheexe(20); }
	void helpexe21() { helptheexe(21); }
	void helpexe22() { helptheexe(22); }
	void helpexe23() { helptheexe(23); }
	void helpexe24() { helptheexe(24); }
	void helpexe25() { helptheexe(25); }
	void helpexe26() { helptheexe(26); }
	void helpexe27() { helptheexe(27); }
	void helpexe28() { helptheexe(28); }
	void helpexe29() { helptheexe(29); }
	void helpexe30() { helptheexe(30); }
	void helpexe31() { helptheexe(31); }
	void helpexe32() { helptheexe(32); }
	void helpexe33() { helptheexe(33); }
	void helpexe34() { helptheexe(34); }
	void helpexe35() { helptheexe(35); }
	void helpexe36() { helptheexe(36); }
	void helpexe37() { helptheexe(37); }
	void helpexe38() { helptheexe(38); }
	void helpexe39() { helptheexe(39); }
	void helpexe40() { helptheexe(40); }
	void helpexe41() { helptheexe(41); }
	void helpexe42() { helptheexe(42); }
	void helpexe43() { helptheexe(43); }
	void helpexe44() { helptheexe(44); }
	void helpexe45() { helptheexe(45); }
	void helpexe46() { helptheexe(46); }
	void helpexe47() { helptheexe(47); }
	void helpexe48() { helptheexe(48); }
	void helpexe49() { helptheexe(49); }
	void helpexe50() { helptheexe(50); }
	void helpexe51() { helptheexe(51); }
	void helpexe52() { helptheexe(52); }
	void helpexe53() { helptheexe(53); }
	void helpexe54() { helptheexe(54); }
	void helpexe55() { helptheexe(55); }
	void helpexe56() { helptheexe(56); }
	void helpexe57() { helptheexe(57); }
	void helpexe58() { helptheexe(58); }
	void helpexe59() { helptheexe(59); }
	void helpexe60() { helptheexe(60); }
	void helpexe61() { helptheexe(61); }
	void helpexe62() { helptheexe(62); }
	void helpexe63() { helptheexe(63); }
	void helpexe64() { helptheexe(64); }
	void helpexe65() { helptheexe(65); }
	void helpexe66() { helptheexe(66); }
	void helpexe67() { helptheexe(67); }
	void helpexe68() { helptheexe(68); }
	void helpexe69() { helptheexe(69); }
	void helpexe70() { helptheexe(70); }
	void helpexe71() { helptheexe(71); }
	void helpexe72() { helptheexe(72); }
	void helpexe73() { helptheexe(73); }
	void helpexe74() { helptheexe(74); }
	void helpexe75() { helptheexe(75); }
	void helpexe76() { helptheexe(76); }
	void helpexe77() { helptheexe(77); }
	void helpexe78() { helptheexe(78); }
	void helpexe79() { helptheexe(79); }
	void helpexe80() { helptheexe(80); }
	void helpexe81() { helptheexe(81); }
	void helpexe82() { helptheexe(82); }
	void helpexe83() { helptheexe(83); }
	void helpexe84() { helptheexe(84); }
	void helpexe85() { helptheexe(85); }
	void helpexe86() { helptheexe(86); }
	void helpexe87() { helptheexe(87); }
	void helpexe88() { helptheexe(88); }
	void helpexe89() { helptheexe(89); }
	void helpexe90() { helptheexe(90); }
	void helpexe91() { helptheexe(91); }
	void helpexe92() { helptheexe(92); }
	void helpexe93() { helptheexe(93); }
	void helpexe94() { helptheexe(94); }
	void helpexe95() { helptheexe(95); }
	void helpexe96() { helptheexe(96); }
	void helpexe97() { helptheexe(97); }
	void helpexe99() { helptheexe(98); }
	void helpexe100() { helptheexe(100); }
	void helpexe101() { helptheexe(101); }
	void helpexe102() { helptheexe(102); }
	void helpexe103() { helptheexe(103); }
	void helpexe104() { helptheexe(104); }
	void helpexe105() { helptheexe(105); }
	void helpexe106() { helptheexe(106); }
	void helpexe107() { helptheexe(107); }
	void helpexe108() { helptheexe(108); }
	void helpexe109() { helptheexe(109); }
	void helpexe110() { helptheexe(110); }
	void helpexe111() { helptheexe(111); }
	void helpexe112() { helptheexe(112); }
	void helpexe113() { helptheexe(113); }
	void helpexe114() { helptheexe(114); }
	void helpexe115() { helptheexe(115); }
	void helpexe116() { helptheexe(116); }
	void helpexe117() { helptheexe(117); }
	void helpexe118() { helptheexe(118); }
	void helpexe119() { helptheexe(119); }
	void helpexe120() { helptheexe(120); }
	void helpexe121() { helptheexe(121); }
	void helpexe122() { helptheexe(122); }
	void helpexe123() { helptheexe(123); }
	void helpexe124() { helptheexe(124); }
	void helpexe125() { helptheexe(125); }
	void helpexe126() { helptheexe(126); }
	void helpexe127() { helptheexe(127); }
	void helpexe128() { helptheexe(128); }
	void helpexe129() { helptheexe(129); }
	void helpexe130() { helptheexe(130); }
	void helpexe131() { helptheexe(131); }
	void helpexe132() { helptheexe(132); }
	void helpexe133() { helptheexe(133); }
	void helpexe134() { helptheexe(134); }
	void helpexe135() { helptheexe(135); }
	void helpexe136() { helptheexe(136); }
	void helpexe137() { helptheexe(137); }
	void helpexe138() { helptheexe(138); }
	void helpexe139() { helptheexe(139); }
	void helpexe140() { helptheexe(140); }
	void helpexe141() { helptheexe(141); }
	void helpexe142() { helptheexe(142); }
	void helpexe143() { helptheexe(143); }
	void helpexe144() { helptheexe(144); }
	void helpexe145() { helptheexe(145); }
	void helpexe146() { helptheexe(146); }
	void helpexe147() { helptheexe(147); }
	void helpexe148() { helptheexe(148); }
	void helpexe149() { helptheexe(149); }

	void editexe0() { edittheexe(0); }
	void editexe1() { edittheexe(1); }
	void editexe2() { edittheexe(2); }
	void editexe3() { edittheexe(3); }
	void editexe4() { edittheexe(4); }
	void editexe5() { edittheexe(5); }
	void editexe6() { edittheexe(6); }
	void editexe7() { edittheexe(7); }
	void editexe8() { edittheexe(8); }
	void editexe9() { edittheexe(9); }
	void editexe10() { edittheexe(10); }
	void editexe11() { edittheexe(11); }
	void editexe12() { edittheexe(12); }
	void editexe13() { edittheexe(13); }
	void editexe14() { edittheexe(14); }
	void editexe15() { edittheexe(15); }
	void editexe16() { edittheexe(16); }
	void editexe17() { edittheexe(17); }
	void editexe18() { edittheexe(18); }
	void editexe19() { edittheexe(19); }
	void editexe20() { edittheexe(20); }
	void editexe21() { edittheexe(21); }
	void editexe22() { edittheexe(22); }
	void editexe23() { edittheexe(23); }
	void editexe24() { edittheexe(24); }
	void editexe25() { edittheexe(25); }
	void editexe26() { edittheexe(26); }
	void editexe27() { edittheexe(27); }
	void editexe28() { edittheexe(28); }
	void editexe29() { edittheexe(29); }
	void editexe30() { edittheexe(30); }
	void editexe31() { edittheexe(31); }
	void editexe32() { edittheexe(32); }
	void editexe33() { edittheexe(33); }
	void editexe34() { edittheexe(34); }
	void editexe35() { edittheexe(35); }
	void editexe36() { edittheexe(36); }
	void editexe37() { edittheexe(37); }
	void editexe38() { edittheexe(38); }
	void editexe39() { edittheexe(39); }
	void editexe40() { edittheexe(40); }
	void editexe41() { edittheexe(41); }
	void editexe42() { edittheexe(42); }
	void editexe43() { edittheexe(43); }
	void editexe44() { edittheexe(44); }
	void editexe45() { edittheexe(45); }
	void editexe46() { edittheexe(46); }
	void editexe47() { edittheexe(47); }
	void editexe48() { edittheexe(48); }
	void editexe49() { edittheexe(49); }
	void editexe50() { edittheexe(50); }
	void editexe51() { edittheexe(51); }
	void editexe52() { edittheexe(52); }
	void editexe53() { edittheexe(53); }
	void editexe54() { edittheexe(54); }
	void editexe55() { edittheexe(55); }
	void editexe56() { edittheexe(56); }
	void editexe57() { edittheexe(57); }
	void editexe58() { edittheexe(58); }
	void editexe59() { edittheexe(59); }
	void editexe60() { edittheexe(60); }
	void editexe61() { edittheexe(61); }
	void editexe62() { edittheexe(62); }
	void editexe63() { edittheexe(63); }
	void editexe64() { edittheexe(64); }
	void editexe65() { edittheexe(65); }
	void editexe66() { edittheexe(66); }
	void editexe67() { edittheexe(67); }
	void editexe68() { edittheexe(68); }
	void editexe69() { edittheexe(69); }
	void editexe70() { edittheexe(70); }
	void editexe71() { edittheexe(71); }
	void editexe72() { edittheexe(72); }
	void editexe73() { edittheexe(73); }
	void editexe74() { edittheexe(74); }
	void editexe75() { edittheexe(75); }
	void editexe76() { edittheexe(76); }
	void editexe77() { edittheexe(77); }
	void editexe78() { edittheexe(78); }
	void editexe79() { edittheexe(79); }
	void editexe80() { edittheexe(80); }
	void editexe81() { edittheexe(81); }
	void editexe82() { edittheexe(82); }
	void editexe83() { edittheexe(83); }
	void editexe84() { edittheexe(84); }
	void editexe85() { edittheexe(85); }
	void editexe86() { edittheexe(86); }
	void editexe87() { edittheexe(87); }
	void editexe88() { edittheexe(88); }
	void editexe89() { edittheexe(89); }
	void editexe90() { edittheexe(90); }
	void editexe91() { edittheexe(91); }
	void editexe92() { edittheexe(92); }
	void editexe93() { edittheexe(93); }
	void editexe94() { edittheexe(94); }
	void editexe95() { edittheexe(95); }
	void editexe96() { edittheexe(96); }
	void editexe97() { edittheexe(97); }
	void editexe99() { edittheexe(98); }
	void editexe100() { edittheexe(100); }
	void editexe101() { edittheexe(101); }
	void editexe102() { edittheexe(102); }
	void editexe103() { edittheexe(103); }
	void editexe104() { edittheexe(104); }
	void editexe105() { edittheexe(105); }
	void editexe106() { edittheexe(106); }
	void editexe107() { edittheexe(107); }
	void editexe108() { edittheexe(108); }
	void editexe109() { edittheexe(109); }
	void editexe110() { edittheexe(110); }
	void editexe111() { edittheexe(111); }
	void editexe112() { edittheexe(112); }
	void editexe113() { edittheexe(113); }
	void editexe114() { edittheexe(114); }
	void editexe115() { edittheexe(115); }
	void editexe116() { edittheexe(116); }
	void editexe117() { edittheexe(117); }
	void editexe118() { edittheexe(118); }
	void editexe119() { edittheexe(119); }
	void editexe120() { edittheexe(120); }
	void editexe121() { edittheexe(121); }
	void editexe122() { edittheexe(122); }
	void editexe123() { edittheexe(123); }
	void editexe124() { edittheexe(124); }
	void editexe125() { edittheexe(125); }
	void editexe126() { edittheexe(126); }
	void editexe127() { edittheexe(127); }
	void editexe128() { edittheexe(128); }
	void editexe129() { edittheexe(129); }
	void editexe130() { edittheexe(130); }
	void editexe131() { edittheexe(131); }
	void editexe132() { edittheexe(132); }
	void editexe133() { edittheexe(133); }
	void editexe134() { edittheexe(134); }
	void editexe135() { edittheexe(135); }
	void editexe136() { edittheexe(136); }
	void editexe137() { edittheexe(137); }
	void editexe138() { edittheexe(138); }
	void editexe139() { edittheexe(139); }
	void editexe140() { edittheexe(140); }
	void editexe141() { edittheexe(141); }
	void editexe142() { edittheexe(142); }
	void editexe143() { edittheexe(143); }
	void editexe144() { edittheexe(144); }
	void editexe145() { edittheexe(145); }
	void editexe146() { edittheexe(146); }
	void editexe147() { edittheexe(147); }
	void editexe148() { edittheexe(148); }
	void editexe149() { edittheexe(149); }

};



#endif // QITEMEXETOOL_H
