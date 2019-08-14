//
#ifndef ITEMGLOBALDEFINE_H
#define ITEMGLOBALDEFINE_H

#include <QTextCodec>
#include <QList>
#include <QString>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QStringBuilder>
#include <QDir>
#include <QMessageBox>
#include "windows.h"

typedef QList<qreal> QqrealList;

enum _HISINLINEDB_FLAG
{
	_HISINLINEDB_FLAG_classfy		=	0x01,
	_HISINLINEDB_FLAG_item			=	0x02,
	_HISINLINEDB_FLAG_itemsuffix1	=	0x04,
	_HISINLINEDB_FLAG_itemsuffix2	=	0x08,
	_HISINLINEDB_FLAG_key				=	0x10
};

//
union _scotherInfo{
	__int64 i64data[16];
	unsigned __int64 ui64data[16];
	int idata[32];
	unsigned int uidata[32];
	short sdata[64];
	unsigned short usdata[64];
	unsigned char ucdata[128];
	char strdata[128];
	float fldata[32];
	double dfldata[16];
	RECT stRect[8];
};

enum _execItemType{
	sensoritemtype			=	0x1,
	algorithmitemtype		=	0x2,
	equipmentitemtype		=	0x3,
	otheritemtype				=	0x4
};

enum _operateItemList{
	startpreviewitem								=	0x1,		//startpreviewitem
	stoppreviewitem								=	0x2,		//stoppreviewitem
	mtffaitem											=	0x3,		//mtffaitem
	sfrfacaitem										=	0x4,		//sfrfacaitem
	sleepitem											=	0x5,		//sleepitem(value:30)
	clearresultitem								=	0x6,		//clearresultitem
	showresultitem								=	0x7,		//showresultitem
	brightnessitem								=	0x8,		//brightnessitem(roi:200,200,400,400)(spec:50,100)
	exposureitem									=	0x9,		//setexposureitem(value:15000)
	gainitem											= 0xa,		//setgainitem(value:4)
	motoritem										= 0xb,		//setmotoritem(value:100)
	autoexposureitem							= 0xc,		//autoexposureitem(roi:200,200,400,400)(spec:115,135)(sleep:200)(database:1)
	whitepanelitem								= 0xd,		//whitepanelitem
	whitepanelitem_blemish					=	0xe,
	whitepanelitem_color						=	0xf,
	whitepanelitem_snr							=	0x10,
	whitepanelitem_oc							=	0x11, 
	whitepanelitem_line							=	0x12,
	whitepanelitem_pixel						=	0x13,
	whitepanelitem_shading					=	0x14,
	whitepanelitem_vignetting				=	0x15,
	mtffcnearitem									=	0x20,	//mtffc_nearitem
	mtffcmiddleitem								=	0x21,	//mtffc_middleitem
	mtffcinfiniteitem								=	0x22,	//mtffc_infiniteitem
	workcurrentitem								=	0x23,  //workcurrentitem
	standbycurrentitem							=	0x24,  //standbycurrentitem
	otpburnitem										=	0x25, //otpburnitem
	otpcheckitem									=	0x26,  //otpcheckitem
	getserialnumberitem						=	0x27,
	burnserialnumberitem						=	0x28,
	afburnitem										=	0x29,
	afburncheckitem								=	0x2a,
	lsctemplateitem								=	0x2d,
	saveimageitem								=	0x2e,
	blackfielditem									=	0x2f,
	funtionmovetonextitem					=	0x30,
	funtionmovetopos0item					=	0x31,
	funtioncheckpos1item						=	0x32,
	funtionkangtoposinfiniteitem			=	0x33,
	funtionkangtoposwhiteitem				=	0x34,
	funtionkangtoposnearitem				=	0x35,
	funtionkangtoposzeroitem				=	0x36,
	afbgbtoposnearitem						=	0x37,
	afbgbtoposmiddleitem						=	0x38,
	afbgbtoposinfiniteitem						=	0x39,
	afbgbtowhitepaneposlitem				=	0x3a,
	afbgbtobackfieldpositem					=	0x3b,
	funtionv3tomodulepositem				=	0x3c,
	funtionv3toinfinitepositem				=	0x3d,
	funtionv3tonearpositem					=	0x3e,
	funtionv3towhitepanelpositem			=	0x3f,
	funtionv3tozeropositem					=	0x40,
	checkcoloritem								=	0x43,
	pdafgbto15cmpositem					=	0x44,
	pdafgbto50cmpositem					=	0x45,
	pdafgbtowhitepanelpositem			=	0x46,
	pdafgbtoblackfieldpositem				=	0x47,
	pdafgbmtkwhitecaliitem					=	0x48,
	pdafgbstep2caliitem						=	0x49,
	pdafgbmtk50cmcaliitem					=	0x4a,
	pdafgbto6cmpositem						=	0x4b,
	pdafgbtonearpositem						=	0x4c,
	pdafgbtoinfinitepositem					=	0x4d,
	pdafgbmtkcheckitem						=	0x4e,
	//pdafgbmtk20cmcaliitem				=	0x76,
	jslafctoafpositem								=	0x4f,
	jslafctowhitepanelpositem				=	0x50,
	jslafctoblackpanelpositem				=	0x51,
	jslafctooriginalpositem					=	0x52,
	jslafchomeitem								=	0x53,
	jslafcautofocusitem							=	0x54,
	lpnearafcitem									=	0x5a,
	lpmiddleafcitem								=	0x5b,
	lpfarafcitem										=	0x5c,
	lpmfaitem										=	0x5e,
	jigchange2previewitem					=	0x5f,
	jigchange2captureitem					=	0x60,
	jignearfocusitem								=	0x61,
	jigfarfocusitem									=	0x62,
	openshortitem									=	0x63,
	sfrnearafcitem									=	0x64,
	sfrmiddleafcitem								=	0x65,
	sfrfarafcitem									=	0x66,
	yiouafav1tolaserpositem					=	0x67,
	yiouafav1tovisionpositem				=	0x68,
	yiouafav1toafapositem					=	0x69,
	yiouafav1towhitepanelpositem		=	0x6a,
	pdafgbmtkiocontrolitem					=	0x70,
	yiouafav1tohomeitem						=	0x71,
	yiouafav1tooriginalitem					=	0x72,
	autofageneralitem							=	0x6b,
	jslfuncv1tohome								=	0x6c,
	jslfuncv1negtive90item					=	0x6d,
	jslfuncv1moduletoleft						=	0x6e,
	jslfuncv1moduletoright					=	0x6f,
	setcustomiicitem								=	0x73,
	yiouafabvv1toafapositem				=	0x74,
	yiouafabvv1tooriginalitem				=	0x75,
	jslafcverticalmoveitem					=	0x77,
	jslafcringmoveitem							=	0x78,
	serialportitem									=	0x79,
	autorawcapture								=  0x7a,
	sunexotpmtootppositem					=	0x7b,
	sunexotpmtooriginalpositem			=	0x7c,
	sunriseafav1tolaserpositem			=	0x7d,
	sunriseafav1tovisionpositem			=	0x7e,
	sunriseafav1toafapositem				=	0x7f,
	sunriseafav1towhitepanelpositem	=	0x80,
	sunriseafav1tohomeitem				=	0x81,
	sunriseafav1tooriginalitem				=	0x82,
	sunriseafav1toblackitem					=	0x83,
	sunriseafav1tonearfcitem				=	0x84,
	manualmodebloop1						=	0x87,
	azwareafav1tohomeitem				=	0x88,
	azwareafav1tooriginalitem				=	0x89,
	mictestitem										=	0x8a,
	azwareafav1tofaitem						=	0x8b,
	ledtestitem										=	0x8c,
	messageboxitem							=	0x8d,
	fwburnitem										=	0x8e,
	dualcameracoaxialityitem				= 0x90,
	dualcameracoaxialitytiltitem			= 0x91,
	FishEyejungeitem							= 0x92,
	sonypdafSPCitem							=0x93,
	awblscgoldenselection					=0x94,
	tiltroationtestdataburnitem				=0x95,
	tiltroationtestdataburncheckitem		=0x96,
	dualcameracoaxialitytestdataburnitem =0x97,
	dualcameracoaxialitytestdataburncheckitem =0x98,
	dualcamerastereotestitem				=0x99,
	dualcamerastereoburncheckitem	=0x9a,
	playaudioitem									=	0x9b,
	imageprocessitem							=	0x9c,
	iobitoutitem										=	0x9d,
	motormoveitem								=	0x9e,
	toposwhitepanelitem						=	0x9f,
	toposblackpanelitem						=	0xa0,
	toposnearfocusitem						=	0xa1,
	toposfarfocuslitem							=	0xa2,
	chartalignlitem									=	0xa3,
	autofocusitem									=	0xa4,
	rrtcheckmacroitem							=	0xa5,
	rrtcheckfaritem								=	0xa6,
	lightsourcecheckitem						=	0xa7,
	tcpserversendresultitem              =0xa8,
	tcpsocketsimulateitem								=  0xa9,
	goldenitem                                = 0xaa,  //Golden
	sensordpcfunctionitem        =0xab,
    camdoracalibrationitem					=	0xb1,
	whitepanelitem_blemishb					=	0xb2,
	moveotpwhitepush=0xb3 ,
	moveotpwhitepop =0xb4 ,
	showcontrolpanel=0xb5 ,
	mtffocus=0xb6,
	savemtfdata=0xb7,
	bindserialnumber=0xb8,
	afc_messtatusupdate=0xb9,
	burn_messtatusupdate=0xbA,
	burncheck_messtatusupdate=0xbB,
	focus_messtatusupdate=0xbC,
	lightcal=0xbd,
	lightcheck = 0xbe,
	debugitem = 0xff
};
 
struct _TestItem_Basic_Info{
	unsigned int uiID;
	QString strSaveName;
	QString strDescripName;
	QString strType;
	QString strEditInfo;
	QString strDefineSwitch;
	QString strHelpInfo;
};

#define _CODE_GLOBALITEM_PUSHBACK(a,b,c,d,e,f,g) {stItem.uiID=a;stItem.strSaveName=b;stItem.strDescripName=c;stItem.strType=d;stItem.strEditInfo=e;stItem.strHelpInfo=f;stItem.strDefineSwitch=g; itemList.push_back(stItem);}

__inline void globalgetListAllTestItem(QList<_TestItem_Basic_Info>& itemList) //0-CCMTest 1-CCMConsole
{
	itemList.clear(); itemList.reserve(200);
	_TestItem_Basic_Info stItem;

	//*******************  2019.08.12 feng Add ****************
	_CODE_GLOBALITEM_PUSHBACK(lightcheck, "lightcal", QTextCodec::codecForName( "GBK")->toUnicode("��¼��Դ���"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ���¼��Դ��飡"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(lightcal, "lightcheck", QTextCodec::codecForName( "GBK")->toUnicode("��¼��ԴУ��"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ���¼��ԴУ�����ӹ�Դϵ����!"), \
		"HisFX3CCMTest");

	//*******************  2018.05.23 feng Add ****************
#if (defined USE_EQUIPMENT_AFM_JSL_V2)
	_CODE_GLOBALITEM_PUSHBACK(showcontrolpanel, "showcontrolpanel", QTextCodec::codecForName( "GBK")->toUnicode("��ʾIO���"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ���ʾIO���"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(mtffocus, "mtffocus", QTextCodec::codecForName( "GBK")->toUnicode("MTF����2"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�MTF����"), \
		"HisFX3CCMTest");
#endif

	_CODE_GLOBALITEM_PUSHBACK(focus_messtatusupdate, "focus_messtatusupdate", QTextCodec::codecForName( "GBK")->toUnicode("����focus��MES"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ����µ���վλ��Ϣ��MES������"), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(burncheck_messtatusupdate, "burncheck_messtatusupdate", QTextCodec::codecForName( "GBK")->toUnicode("����OTP Check��MES"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�������¼���վλ��Ϣ��MES������"), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(burn_messtatusupdate, "burn_messtatusupdate", QTextCodec::codecForName( "GBK")->toUnicode("����OTP ��MES"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�������¼վλ��Ϣ��MES������"), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(afc_messtatusupdate, "afc_messtatusupdate", QTextCodec::codecForName( "GBK")->toUnicode("����AFC ��MES"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����AFCվλ��Ϣ��MES������"), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(bindserialnumber, "bindserialnumber", QTextCodec::codecForName( "GBK")->toUnicode("оƬID���ά���"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�оƬID���ά���"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(savemtfdata, "savemtfdata", QTextCodec::codecForName( "GBK")->toUnicode("�������MTF����"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ������ֶ�����MTF����"), \
		"HisFX3CCMTest");

	//**********************************************************
	_CODE_GLOBALITEM_PUSHBACK(clearresultitem, "clearresultitem", QTextCodec::codecForName( "GBK")->toUnicode("������"), "other", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�������е�״̬(�������Խ�������ݵ�)\nһ��ʹ���ڲ��Եĵ�һ���߼������ϣ�����һ�е�ָ��"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(showresultitem, "showresultitem", QTextCodec::codecForName( "GBK")->toUnicode("��ʾ���"), "other", "(notsavelog:false)(notshowtotalresult:false)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ���ʾǰ���������ܲ��Խ���������ʾ������Ҳ�OK/NG��ʾ��\nһ��ʹ���ڲ��Ե����һ���߼������ϣ������һ�е�ָ��"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(getserialnumberitem, "getserialnumberitem", QTextCodec::codecForName( "GBK")->toUnicode("��ȡ��Ʒ���"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ���ȡ��Ʒ��ά�롢CHIP ID�ȹ���\nһ�����ڿ�ʼ��ͼ֮��ֻ�м����˴˴β�����Ż���'��ʾ���'��ʱ�򱣴��������"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(burnserialnumberitem, "burnserialnumberitem", QTextCodec::codecForName( "GBK")->toUnicode("��¼��Ʒ���"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ������к�д��OTP����EEPROM\n��ͨ�ù��ܣ���Ҫд���룬��ͬOTP��¼"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(startpreviewitem, "startpreviewitem", QTextCodec::codecForName( "GBK")->toUnicode("��ʼ��ͼ"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����ͼ��"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(stoppreviewitem, "stoppreviewitem", QTextCodec::codecForName( "GBK")->toUnicode("ֹͣ��ͼ"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ��ر�ͼ��"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(mtffaitem, "mtffaitem", QTextCodec::codecForName( "GBK")->toUnicode("MTF����"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ����õ�����MTF����\nһ��ʹ���ڵ������򣬶Ե���ʱ�Ķ�̬MTF�����ж�"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(sfrfacaitem, "sfrfacaitem", QTextCodec::codecForName( "GBK")->toUnicode("SFR����A"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");


	_CODE_GLOBALITEM_PUSHBACK(imageprocessitem, "imageprocessitem", QTextCodec::codecForName( "GBK")->toUnicode("ͼ����"), "algorithm", \
		"(blemishenhance:0)(lsc:0)(awb:0)(awbrate:5)(gainr:1.0)(gainb:1.0)(blacklevel:0)(mirror:0)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�ͼ����"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(mtffcnearitem, "mtffc_nearitem", QTextCodec::codecForName( "GBK")->toUnicode("MTF����"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ����ý���AF��MTF������VCM�Ĳ���"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(mtffcmiddleitem, "mtffc_middleitem", QTextCodec::codecForName( "GBK")->toUnicode("MTF�н�"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ������н�AF��MTF������VCM�Ĳ��������߲���VCMֻ����MTF"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(mtffcinfiniteitem, "mtffc_infiniteitem", QTextCodec::codecForName( "GBK")->toUnicode("MTFԶ��"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����Զ��AF��MTF������VCM�Ĳ��������߲���VCMֻ����MTF"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(sfrnearafcitem, "sfrnearafcitem", QTextCodec::codecForName( "GBK")->toUnicode("SFR�Խ�"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(sfrmiddleafcitem, "sfrmiddleafcitem", QTextCodec::codecForName( "GBK")->toUnicode("SFR�н�A"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(sfrfarafcitem, "sfrfarafcitem", QTextCodec::codecForName( "GBK")->toUnicode("SFRԶ��A"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�TV Line����"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(lpmfaitem, "lpmfaitem", QTextCodec::codecForName( "GBK")->toUnicode("�߶Ե���"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(lpnearafcitem, "lpnearafcitem", QTextCodec::codecForName( "GBK")->toUnicode("�߶�AFC����"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(lpmiddleafcitem, "lpmiddleafcitem", QTextCodec::codecForName( "GBK")->toUnicode("�߶�AFC�н�"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(lpfarafcitem, "lpfarafcitem", QTextCodec::codecForName( "GBK")->toUnicode("�߶�AFCԶ��"), "algorithm", "(tactics:255)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");


	_CODE_GLOBALITEM_PUSHBACK(brightnessitem, "brightnessitem", QTextCodec::codecForName( "GBK")->toUnicode("�������"), "algorithm", "(roi:1000,1000,1200,1200)(spec:150,160)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�������������Yƽ������ֵ\n rio��left��top��right��bottom \n ��spec��min��max��"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(checkcoloritem, "checkcoloritem", QTextCodec::codecForName( "GBK")->toUnicode("ͼ���ƽ��ܿ�"), "algorithm", \
		"(roi:1000,1000,1200,1200)(r/gr:0.45,0.75)(b/gr:0.45,0.75)" , \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ������������İ�ƽ��ֵ\n (rio��left��top��right��bottom) \n ��r/gr��min��max�� \n ��b/gr��min��max��"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(autoexposureitem, "autoexposureitem", QTextCodec::codecForName( "GBK")->toUnicode("�Զ��ع�"), "algorithm", \
		"(roi:1000,1000,1200,1200)(spec:150,160)(sleep:650)(database:1)(channel_gr:false)(white:false)(imagecenter:true)(centerroiratio:0.1)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ������������ڵ����ȣ��Զ�AE������ķ�Χ\n (rio��left��top��right��bottom) \n (spec:min,max) \n (sleep:650):ÿ����ʱʱ�� \n (database:1):�Զ��ع��õ������ݿ⣬1~45��ѡ��ͬһ�����Ӳ�Ҫ�ظ�ʹ����ͬ�����ݿ� \n (channel_gr:false): true:��Gͨ�����Զ��ع�  false:��Yͨ�����Զ��ع�\n (white:false): false:����Դ����װ�  true:�ڰ׿飬��PDAF CHART, SFR CHART, ROI��Ҫ�㹻���ܹ������㹻��ĺ�ɫ�Ͱ�ɫ�������ʹ��Gͨ�����ع�"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(exposureitem, "setexposureitem", QTextCodec::codecForName( "GBK")->toUnicode("���ع�ʱ��"), "sensor", "(value:1000)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ����������趨\n��value��x��,xΪ�ع�ʱ��\nһ����Ҫ�ڴ���֮�����'��ʱ',��ʱʱ�����֡�ʶ�����һ��3~5֡��ʱ��"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(gainitem, "setgainitem", QTextCodec::codecForName( "GBK")->toUnicode("��Gainֵ"), "sensor", "(value:1.0)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(motoritem, "setmotoritem", QTextCodec::codecForName( "GBK")->toUnicode("�����ֵ"), "sensor", "(value:100)(otp:no)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�ʹVCM�����˶�����Ӧcodeλ��\n (value:motor dec value)\n otp:no��ָ�������ֵ   near���Ѿ���¼�Ľ���ֵ  middle���Ѿ���¼���н�ֵ   far���Ѿ���¼��Զ��ֵ"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(setcustomiicitem, "setcustomiicitem", QTextCodec::codecForName( "GBK")->toUnicode("��Ĵ���"), "sensor", "(group:1)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����д���Զ���Ĵ���ֵ\n��group��x��,xΪGroup(1~4��ѡ)\n ����������������Ĵ浵/IIC�����������"), \
		"HisFX3CCMTest");

// 	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem, "whitepanelitem", QTextCodec::codecForName( "GBK")->toUnicode("�װ����"), "algorithm", "", \
// 		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ����ð׳����ԵĲ���\nĿǰ�׳������ò�����۵㡢��ѧ���ġ����㡢��������ɫ��SHADING��Vignetting"), \
// 		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_blemish, "whitepanelitem_blemish", QTextCodec::codecForName( "GBK")->toUnicode("�װ�����A"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ���������"), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_blemishb, "whitepanelitem_blemishb", QTextCodec::codecForName( "GBK")->toUnicode("�װ�����B"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ���������"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_color, "whitepanelitem_color", QTextCodec::codecForName( "GBK")->toUnicode("�װ���ɫ"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ��װ���ɫ"), \
		"HisFX3CCMTest");

// 	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_snr, "whitepanelitem_snr", QTextCodec::codecForName( "GBK")->toUnicode("�װ�SNR"), "algorithm", "", \
// 		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ��װ�SNR"), \
// 		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_oc, "whitepanelitem_oc", QTextCodec::codecForName( "GBK")->toUnicode("�װ����"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ��װ����"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_line, "whitepanelitem_line", QTextCodec::codecForName( "GBK")->toUnicode("�װ�����"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ��װ�����"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_pixel, "whitepanelitem_pixel", QTextCodec::codecForName( "GBK")->toUnicode("�װ廵��"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_shading, "whitepanelitem_shading", QTextCodec::codecForName( "GBK")->toUnicode("�װ尵��"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�Shading"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(whitepanelitem_vignetting, "whitepanelitem_vignetting", QTextCodec::codecForName( "GBK")->toUnicode("�װ����"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�Vignetting"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(blackfielditem, "blackfielditem", QTextCodec::codecForName( "GBK")->toUnicode("�ڳ�����"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ����úڳ����ԵĲ���\n�ɲ���ȫ��̬�µĲ������ʵ㡢�׵㡢��㡢�̵㡢����ȣ�"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(workcurrentitem, "workcurrentitem", QTextCodec::codecForName( "GBK")->toUnicode("��������"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����senser����ʱ�ĸ�·����ֵ"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(standbycurrentitem, "standbycurrentitem", QTextCodec::codecForName( "GBK")->toUnicode("��̬����"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����senser����power downģʽ�µĸ�·����ֵ"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(openshortitem, "openshortitem", QTextCodec::codecForName( "GBK")->toUnicode("����·"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");


	_CODE_GLOBALITEM_PUSHBACK(autofocusitem, "autofocusitem", QTextCodec::codecForName( "GBK")->toUnicode("�Զ��Խ�"), "algorithm", \
		"(alg:0)(chart:0)(timeout:120)(left:1590)(top:1178)(right:1690)(bottom:1278)(startpos:0)(pedestal:0)(sleep:300)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ��Զ��Խ�"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(autorawcapture, "autorawcapture", QTextCodec::codecForName( "GBK")->toUnicode("�Զ���ͼ"), "algorithm", \
		"(FileName:Register.sset)(roi:400,400)(RAWCaptureCount:120)(CaptureRawDelay:1000)(Savelog:true)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(awblscgoldenselection, "awblscgoldenselection", QTextCodec::codecForName( "GBK")->toUnicode("��ͨAWBLSC"), "algorithm", \
		"(modulecount:200)(blacklevel:16)(awbroidivisor:10)(spec:190,210)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(lightsourcecheckitem, "lightsourcecheckitem", QTextCodec::codecForName( "GBK")->toUnicode("��Դ���"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ���Դ���"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(otpburnitem, "otpburnitem", QTextCodec::codecForName( "GBK")->toUnicode("OTP��¼"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(otpcheckitem, "otpcheckitem", QTextCodec::codecForName( "GBK")->toUnicode("OTP���"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(afburnitem, "afburnitem", QTextCodec::codecForName( "GBK")->toUnicode("AF��¼"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(afburncheckitem, "afburncheckitem", QTextCodec::codecForName( "GBK")->toUnicode("AF��¼���"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(serialportitem, "serialportitem", QTextCodec::codecForName( "GBK")->toUnicode("���ڷ���"), "equipment", "(serialport:4)(ebaud:2)(epar:2)(estop:0)(strinfo:A)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(playaudioitem, "playaudioitem", QTextCodec::codecForName( "GBK")->toUnicode("������Ƶ"), "other", \
		"(source:0)(time:5000)(samplerate:1.0)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�������Ƶ"), \
		"HisFX3CCMTest");


	_CODE_GLOBALITEM_PUSHBACK(camdoracalibrationitem, "camdoracalibrationitem", QTextCodec::codecForName( "GBK")->toUnicode("˫��У��"), "equipment", \
		"(left:0)(top:0)(right:100)(bottom:100)(minarea:10000)(left2:0)(top2:0)(right2:100)(bottom2:100)(ysmax:100)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(lsctemplateitem, "lsctemplateitem", QTextCodec::codecForName( "GBK")->toUnicode("����LSCģ��"), "sensor", \
		"(replace:false)(type:1)(shading:80)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����LSCģ�壬����LSCģ������ʹͼ���Ľ������������������ȵĹ̶�����\n (replace:false)  true:�滻ԭ����ģ��  false:����Ѿ���ģ�����������,���û��ģ��������ģ��\n (shading:Ŀ��ֵ) "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(saveimageitem, "saveimageitem", QTextCodec::codecForName( "GBK")->toUnicode("����ͼƬ"), "sensor", \
		"(source:sensor)(format:jpeg)(original:false)(savefail:false)(sleep:0)", \
		QTextCodec::codecForName( "GBK")->toUnicode("���ܣ�����ͼƬ������\n (source:sensor) ͼ����Դ senosr:ģ�������ͼ�� display:ͼ�������ͼ program:��������ͼ desktop:�����ͼ\n (format:jpeg) �����ʽ raw:RAWͼ��(source:sensor)����Ч png:png��ʽ jpeg:JPEG��ʽ bmp:BMP��ʽ\n (original:false) ��δ֧��"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(sleepitem, "sleepitem", QTextCodec::codecForName( "GBK")->toUnicode("��ʱ"), "other", "(value:100)", \
		QTextCodec::codecForName( "GBK")->toUnicode("��ʱ"), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(jigchange2previewitem, "jigchange2previewitem", QTextCodec::codecForName( "GBK")->toUnicode("JIGԤ��"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"_HisFX3_Platform_Jigboard");
	_CODE_GLOBALITEM_PUSHBACK(jigchange2captureitem, "jigchange2captureitem", QTextCodec::codecForName( "GBK")->toUnicode("JIGȫ����"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"_HisFX3_Platform_Jigboard");
	_CODE_GLOBALITEM_PUSHBACK(jignearfocusitem, "jignearfocusitem", QTextCodec::codecForName( "GBK")->toUnicode("JIG�����Խ�"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"_HisFX3_Platform_Jigboard");
	_CODE_GLOBALITEM_PUSHBACK(jigfarfocusitem, "jigfarfocusitem", QTextCodec::codecForName( "GBK")->toUnicode("JIGԶ���Խ�"), "sensor", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"_HisFX3_Platform_Jigboard");


	_CODE_GLOBALITEM_PUSHBACK(afbgbtoposnearitem, "afbgbtoposnearitem", QTextCodec::codecForName( "GBK")->toUnicode("�˶�������"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_AFBURN");
	_CODE_GLOBALITEM_PUSHBACK(afbgbtoposmiddleitem, "afbgbtoposmiddleitem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����н�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_AFBURN");
	_CODE_GLOBALITEM_PUSHBACK(afbgbtoposinfiniteitem, "afbgbtoposinfiniteitem", QTextCodec::codecForName( "GBK")->toUnicode("�˶���Զ��"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_AFBURN");
	_CODE_GLOBALITEM_PUSHBACK(afbgbtowhitepaneposlitem, "afbgbtowhitepaneposlitem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����װ�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_AFBURN");
	_CODE_GLOBALITEM_PUSHBACK(afbgbtobackfieldpositem, "afbgbtobackfieldpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����ڳ�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_AFBURN");

	_CODE_GLOBALITEM_PUSHBACK(pdafgbto6cmpositem, "pdafgbto6cmpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶���6CM"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_PDAF");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbto15cmpositem, "pdafgbto15cmpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶���Step2"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_PDAF");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbto50cmpositem, "pdafgbto50cmpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶���Step3"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_PDAF");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbtonearpositem, "pdafgbtonearpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶�������"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_PDAF");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbtoinfinitepositem, "pdafgbtoinfinitepositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶���Զ��"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_PDAF");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbtowhitepanelpositem, "pdafgbtowhitepanelpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����װ�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_PDAF");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbtoblackfieldpositem, "pdafgbtoblackfieldpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����ڳ�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_GB_PDAF");


	_CODE_GLOBALITEM_PUSHBACK(debugitem, "debugitem", QTextCodec::codecForName( "GBK")->toUnicode("����"), "other", "(testtype:0)", \
		QTextCodec::codecForName( "GBK")->toUnicode("�����ǳ��򿪷���Ա�����¹���ʹ��"), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbmtkwhitecaliitem, "pdafgbmtkwhitecaliitem", QTextCodec::codecForName( "GBK")->toUnicode("PDAF STEP1"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbstep2caliitem, "pdafgbstep2caliitem", "PDAF STEP2", "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbmtk50cmcaliitem, "pdafgbmtk50cmcaliitem", "PDAF 50CM", "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(pdafgbmtkcheckitem, "pdafgbmtkcheckitem", QTextCodec::codecForName( "GBK")->toUnicode("PDAF ���"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(sonypdafSPCitem, "sonypdafSPCitem", QTextCodec::codecForName( "GBK")->toUnicode("PDAF SONY SPC"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");


	_CODE_GLOBALITEM_PUSHBACK(messageboxitem, "messageboxitem", QTextCodec::codecForName( "GBK")->toUnicode("�Ի���"), "equipment", "(info:0)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(iobitoutitem, "iobitoutitem", QTextCodec::codecForName( "GBK")->toUnicode("IO���"), "equipment", "(card:0)(port:0)(bit:0)(out:1)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisGerneralMotion");
	_CODE_GLOBALITEM_PUSHBACK(motormoveitem, "motormoveitem", QTextCodec::codecForName( "GBK")->toUnicode("����˶�"), "equipment", "(card:0)(axis:0)(abs:0)(dis:0.0)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisGerneralMotion");

	_CODE_GLOBALITEM_PUSHBACK(chartalignlitem, "chartalignlitem", QTextCodec::codecForName( "GBK")->toUnicode("ChartУ׼"), "equipment", "(scalex:200.0)(scaley:200.0)(times:20)(charttype:0)(markmin:60)(markmax:180)(diff:150)(fov:0.3)(angle:30)(spec:20)(sleep:300)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_RRT_V1");
	_CODE_GLOBALITEM_PUSHBACK(rrtcheckmacroitem, "rrtcheckmacroitem", QTextCodec::codecForName( "GBK")->toUnicode("RRT����"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_RRT_V1");
	_CODE_GLOBALITEM_PUSHBACK(rrtcheckfaritem, "rrtcheckfaritem", QTextCodec::codecForName( "GBK")->toUnicode("RRTԶ��"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_RRT_V1");
	_CODE_GLOBALITEM_PUSHBACK(toposwhitepanelitem, "toposwhitepanelitem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����׳�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_RRT_V1");
	_CODE_GLOBALITEM_PUSHBACK(toposblackpanelitem, "toposblackpanelitem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����ڳ�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_RRT_V1");
	_CODE_GLOBALITEM_PUSHBACK(toposnearfocusitem, "toposnearfocusitem", QTextCodec::codecForName( "GBK")->toUnicode("�˶�������"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_RRT_V1");
	_CODE_GLOBALITEM_PUSHBACK(toposfarfocuslitem, "toposfarfocuslitem", QTextCodec::codecForName( "GBK")->toUnicode("�˶���Զ��"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_RRT_V1");

	_CODE_GLOBALITEM_PUSHBACK(jslafctoafpositem, "jslafctoafpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶�������"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_AFM_JSL_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslafctowhitepanelpositem, "jslafctowhitepanelpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����װ�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_AFM_JSL_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslafctoblackpanelpositem, "jslafctoblackpanelpositem", QTextCodec::codecForName( "GBK")->toUnicode("�˶����ڰ�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_AFM_JSL_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslafctooriginalpositem, "jslafctooriginalpositem", QTextCodec::codecForName( "GBK")->toUnicode("�ص���ʼλ��"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_AFM_JSL_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslafchomeitem, "jslafchomeitem", QTextCodec::codecForName( "GBK")->toUnicode("����У��"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_AFM_JSL_V1");
	_CODE_GLOBALITEM_PUSHBACK(autofageneralitem, "autofageneralitem", QTextCodec::codecForName( "GBK")->toUnicode("�Զ�����"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_AFM_JSL_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslafcverticalmoveitem, "jslafcverticalmoveitem", QTextCodec::codecForName( "GBK")->toUnicode("��ֱ�˶�"), "equipment", "(abs:false)(plus:100)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_AFM_JSL_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslafcringmoveitem, "jslafcringmoveitem", QTextCodec::codecForName( "GBK")->toUnicode("ת������"), "equipment", "(angle:1.0)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_AFM_JSL_V1");

	

	_CODE_GLOBALITEM_PUSHBACK(jslfuncv1tohome, "jslfuncv1tohome", QTextCodec::codecForName( "GBK")->toUnicode("��ԭ��"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_FUNCTION_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslfuncv1negtive90item, "jslfuncv1negtive90item", QTextCodec::codecForName( "GBK")->toUnicode("��ת"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_FUNCTION_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslfuncv1moduletoleft, "jslfuncv1moduletoleft", QTextCodec::codecForName( "GBK")->toUnicode("���׽�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_FUNCTION_V1");
	_CODE_GLOBALITEM_PUSHBACK(jslfuncv1moduletoright, "jslfuncv1moduletoright", QTextCodec::codecForName( "GBK")->toUnicode("���׳�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"USE_EQUIPMENT_JSL_FUNCTION_V1");

	_CODE_GLOBALITEM_PUSHBACK(sunexotpmtootppositem, "sunexotpmtootppositem", QTextCodec::codecForName( "GBK")->toUnicode("���׽�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"_SUNRISE_OTPBURN_MACHINE_V1");
	_CODE_GLOBALITEM_PUSHBACK(sunexotpmtooriginalpositem, "sunexotpmtooriginalpositem", QTextCodec::codecForName( "GBK")->toUnicode("���׳�"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"_SUNRISE_OTPBURN_MACHINE_V1");


	_CODE_GLOBALITEM_PUSHBACK(dualcameracoaxialityitem, "dualcameracoaxialityitem", QTextCodec::codecForName( "GBK")->toUnicode("˫��ͬ�����"), "algorithm", \
		"(dualcmcenterdistance:5)(squarehorizontaldistance:360)(squareverticaldistance:280)(dualcmtesdistance:500)(maincameracolorsensor:true)(subcameracolorsensor:true)(dualcameracoaxialityitemspecx:5)(dualcameracoaxialityitemspecy:5)(dualcameracoaxialityitemspecpixelx:50)(dualcameracoaxialityitemspecpixely:50)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(dualcameracoaxialitytiltitem, "dualcameracoaxialitytiltitem", QTextCodec::codecForName( "GBK")->toUnicode("tilt����"), "algorithm","(dualcameracoaxialitytiltitemspecx:5)(dualcameracoaxialitytiltitemspecy:5)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(FishEyejungeitem, "FishEyejungeitem", QTextCodec::codecForName( "GBK")->toUnicode("���۰��ǲ���"), "algorithm","(FishEyejungeitemspec:5)", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(tiltroationtestdataburnitem, "tiltroationtestdataburnitem", QTextCodec::codecForName( "GBK")->toUnicode("Tilt_Rotation������¼"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(tiltroationtestdataburncheckitem, "tiltroationtestdataburncheckitem", QTextCodec::codecForName( "GBK")->toUnicode("Tilt_Rotation��¼���"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(dualcameracoaxialitytestdataburnitem, "dualcameracoaxialitytestdataburnitem", QTextCodec::codecForName( "GBK")->toUnicode("ͬ���������¼"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(dualcameracoaxialitytestdataburncheckitem, "dualcameracoaxialitytestdataburncheckitem", QTextCodec::codecForName( "GBK")->toUnicode("ͬ�����¼���"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(dualcamerastereotestitem, "dualcamerastereotestitem", QTextCodec::codecForName( "GBK")->toUnicode("˫����ȼ��/��¼"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
	_CODE_GLOBALITEM_PUSHBACK(dualcamerastereoburncheckitem, "dualcamerastereoburncheckitem", QTextCodec::codecForName( "GBK")->toUnicode("˫�������¼���ݼ��"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");
		
	_CODE_GLOBALITEM_PUSHBACK(goldenitem , "goldenitem ", QTextCodec::codecForName( "GBK")->toUnicode("��ȡGoldenֵ"), "equipment", "", \
		QTextCodec::codecForName( "GBK")->toUnicode(" "), \
		"HisFX3CCMTest");

	_CODE_GLOBALITEM_PUSHBACK(sensordpcfunctionitem , "sensordpcfunctionitem ", QTextCodec::codecForName( "GBK")->toUnicode("���㲹��"), "algorithm", "", \
		QTextCodec::codecForName( "GBK")->toUnicode("Sensor�ڲ�ISP���ܣ���Ҫ����OTP��ʹ�� "), \
		"HisFX3CCMTest");







}

__inline void globalTestItemKeyPushBack(QStringList& listKey, QString strKey)
{
	if(!listKey.contains(strKey, Qt::CaseSensitive)) listKey.push_back(strKey);
}

__inline void globalgetListWantedTestItem(QList<_TestItem_Basic_Info>& itemList, QStringList& listKey)
{
	itemList.clear(); itemList.reserve(200);
	QList<_TestItem_Basic_Info> itemALL;
	globalgetListAllTestItem(itemALL);
	bool bIs;
	for(QList<_TestItem_Basic_Info>::iterator theiterator = itemALL.begin(); theiterator != itemALL.end(); theiterator++)
	{
		bIs = false;
		for(int x=0; x<listKey.size(); ++x){
			if(theiterator->strDefineSwitch == listKey.at(x)){
				bIs = true;
				break;
			}
		}

		if(bIs){
			itemList.push_back(*theiterator);
		}
	}

}

__inline void golbalItempatchconfigstring(QString& strsrc, QStringList& strname, QStringList& strvalue)
{
	strname.clear();	strvalue.clear();
	strsrc	=	strsrc.trimmed();
	strsrc	=	strsrc.remove(" ");
	if(strsrc.isEmpty() || !strsrc.contains("(") || !strsrc.contains(")") || !strsrc.contains(":"))	return;
	QString strkey, strdata;
	int iindex	=	strsrc.indexOf(")");
	while(iindex > 0){
		strdata		=	strsrc.left(iindex);
		strsrc		=	strsrc.right(strsrc.size() -iindex -1);
		strdata		=	strdata.remove("(");
		if(strdata.count(":") >= 1){
			iindex	=	strdata.indexOf(":");
			strkey	=	strdata.left(iindex);
			strdata	=	strdata.right(strdata.size() -iindex -1);
			if(!(strkey.isEmpty() || strdata.isEmpty())){
				strname.append(strkey);
				strvalue.append(strdata);
			}
		}
		iindex	=	strsrc.indexOf(")");
	}
}

__inline void golbalItemjoinconfigstring(QString& strsrc, QStringList& strname, QStringList& strvalue)
{
	strsrc.clear();
	for(int x=0;	x<strname.size(); ++x){
		strsrc	=	strsrc % "(" % strname.at(x) % ":" % strvalue.at(x) % ")";
	}
}

__inline void globalgetShortcutAddInfoUnion(unsigned short usitem, QString strData, _scotherInfo& otherInfo)
{
	QStringList strlistname, strlistvalue;
	memset(&otherInfo, 0, sizeof(_scotherInfo));
	switch (usitem)
	{
	case showresultitem: //showresultitem(notsavelog:false)(notshowtotalresult:false)
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "notsavelog")	otherInfo.uidata[0] = (strlistvalue.at(x) == "true")?(1):(0);
			else if(strlistname.at(x) == "notshowtotalresult")	otherInfo.uidata[1] = (strlistvalue.at(x) == "true")?(1):(0);
		}
		break;
	case debugitem: //debugitem(testtype:0)
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "testtype")	otherInfo.uidata[0] = strlistvalue.at(x).toUInt();
		}
		break;
	case sleepitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "value")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case messageboxitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "info")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case brightnessitem: //brightnessitem(roi:2200,1570,2400,1770)(spec:50,100)
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "roi")	{
				QStringList strlist				=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.stRect[0].left			=	strlist.at(0).toInt();
				otherInfo.stRect[0].top			=	strlist.at(1).toInt();
				otherInfo.stRect[0].right		=	strlist.at(2).toInt();
				otherInfo.stRect[0].bottom	=	strlist.at(3).toInt();
			}
			else if(strlistname.at(x) == "spec"){
				QStringList strlist	=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.idata[4]	=	strlist.at(0).toInt();
				otherInfo.idata[5]	=	strlist.at(1).toInt();
			}
		}
		break;
	case checkcoloritem: //checkcoloritem(roi:2200,1570,2400,1770)(r/gr:0.45,0.75)(b/gr:0.45,0.75)
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "roi")	{
				QStringList strlist				=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.stRect[0].left			=	strlist.at(0).toInt();
				otherInfo.stRect[0].top			=	strlist.at(1).toInt();
				otherInfo.stRect[0].right		=	strlist.at(2).toInt();
				otherInfo.stRect[0].bottom	=	strlist.at(3).toInt();
			}
			else if(strlistname.at(x) == "r/gr"){
				QStringList strlist	=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.fldata[4]		=	strlist.at(0).toFloat();
				otherInfo.fldata[5]		=	strlist.at(1).toFloat();
			}
			else if(strlistname.at(x) == "b/gr"){
				QStringList strlist	=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.fldata[6]		=	strlist.at(0).toFloat();
				otherInfo.fldata[7]		=	strlist.at(1).toFloat();
			}
		}
		break; 
	case exposureitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "value")	otherInfo.uidata[0] = strlistvalue.at(x).toUInt();
		}
		break;
	case gainitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "value")	otherInfo.fldata[0] = strlistvalue.at(x).toFloat();
		}
		break;
	case motoritem:
		otherInfo.idata[1]	=	0x10;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "value")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
			else if(strlistname.at(x) == "otp"){
				if(strlistvalue.at(x) == "near") otherInfo.idata[1]	=	0;
				else if(strlistvalue.at(x) == "middle") otherInfo.idata[1]	=	1;
				else if(strlistvalue.at(x) == "far") otherInfo.idata[1]	=	2;
			}
		}
		break;
	case autoexposureitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "roi"){
				QStringList strlist		=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.stRect[0].left			=	strlist.at(0).toInt();
				otherInfo.stRect[0].top			=	strlist.at(1).toInt();
				otherInfo.stRect[0].right		=	strlist.at(2).toInt();
				otherInfo.stRect[0].bottom	=	strlist.at(3).toInt();
			}
			else if(strlistname.at(x) == "spec"){
				QStringList strlist		=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.uidata[4]	=	strlist.at(0).toUInt();
				otherInfo.uidata[5]	=	strlist.at(1).toUInt();
			}
			else if(strlistname.at(x) == "sleep") otherInfo.uidata[6]	=	strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "database") otherInfo.uidata[7] |= strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "channel_gr" && strlistvalue.at(x) == "true") otherInfo.uidata[7] |= 0xFF000000;
			else if(strlistname.at(x) == "white" && strlistvalue.at(x) == "true") otherInfo.uidata[7] |= 0x00FF0000;
			else if(strlistname.at(x) == "imagecenter" && strlistvalue.at(x) == "true") otherInfo.uidata[7] |= 0x0000FF00;
			else if(strlistname.at(x) == "centerroiratio") otherInfo.fldata[8]= strlistvalue.at(x).toFloat();
		}
		break;
	case autofocusitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "alg")					otherInfo.ucdata[0]	=	strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "chart")			otherInfo.ucdata[1]	=	strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "timeout")		otherInfo.usdata[1]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "left")			otherInfo.usdata[2]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "top")			otherInfo.usdata[3]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "right")			otherInfo.usdata[4]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "bottom")		otherInfo.usdata[5]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "startpos")	otherInfo.usdata[6]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "pedestal")	otherInfo.usdata[7]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "sleep")		otherInfo.usdata[8]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
		}
		break;
	case playaudioitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "source")		otherInfo.uidata[0]	=	strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "time")	otherInfo.uidata[1]	= strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "samplerate")	otherInfo.fldata[2]	= strlistvalue.at(x).toFloat();
		}
		break;
	case imageprocessitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "blemishenhance")		otherInfo.ucdata[0]	=	strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "lsc")			otherInfo.ucdata[1]	= strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "awb")			otherInfo.ucdata[2]	= strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "awbrate")	otherInfo.ucdata[3]	= strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "gainr")			otherInfo.fldata[1]		= strlistvalue.at(x).toFloat();
			else if(strlistname.at(x) == "gainb")		otherInfo.fldata[2]		= strlistvalue.at(x).toFloat();
			else if(strlistname.at(x) == "blacklevel")	otherInfo.ucdata[12]	=	strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "mirror")		otherInfo.ucdata[13]	=	strlistvalue.at(x).toUInt() & 0xFF;
		}
		break;
	case iobitoutitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "card")				otherInfo.uidata[0]	=	strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "port")		otherInfo.uidata[1]	=	strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "bit")			otherInfo.uidata[2]	=	strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "out")		otherInfo.uidata[3]	=	strlistvalue.at(x).toUInt();
		}
		break;
	case motormoveitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "card")				otherInfo.uidata[0]	=	strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "axis")		otherInfo.uidata[1]	=	strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "abs")		otherInfo.uidata[2]	=	strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "dis")		otherInfo.dfldata[2]	=	strlistvalue.at(x).toDouble();
		}
		break;
	case chartalignlitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "charttype")				otherInfo.ucdata[0]	=	strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "angle")			otherInfo.ucdata[1]	=	strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "times")			otherInfo.ucdata[2]	=	strlistvalue.at(x).toUInt() & 0xFF;
			else if(strlistname.at(x) == "markmin")		otherInfo.usdata[2]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "markmax")		otherInfo.usdata[3]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "diff")				otherInfo.usdata[4]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "spec")				otherInfo.usdata[5]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x) == "fov")				otherInfo.fldata[3]		=	strlistvalue.at(x).toFloat();
			else if(strlistname.at(x) == "scalex")			otherInfo.fldata[4]		=	strlistvalue.at(x).toFloat();
			else if(strlistname.at(x) == "scaley")			otherInfo.fldata[5]		=	strlistvalue.at(x).toFloat();
			else if(strlistname.at(x) == "sleep")			otherInfo.usdata[12]	=	strlistvalue.at(x).toUInt() & 0xFFFF;
		}
		break;
	case autorawcapture:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "FileName"){
				memset(otherInfo.strdata,0,32);
				strcpy_s(otherInfo.strdata,32,strlistvalue.at(0).toLatin1().data());
			}
			else if(strlistname.at(x) == "roi"){
				QStringList strlist		=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.uidata[0]	=	strlist.at(0).toUInt(); //ROIW
				otherInfo.uidata[1]	=	strlist.at(1).toUInt(); //ROH
			}
			else if(strlistname.at(x) == "CaptureRawDelay")
			{
				otherInfo.uidata[2]=strlistvalue.at(x).toUInt(); 
			}
			else if(strlistname.at(x) == "Savelog")
			{
				otherInfo.uidata[3]=0;
				if(strlistvalue.at(x) == "true") otherInfo.uidata[3]=1;
			}
		}
		break;
	case awblscgoldenselection:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x)	==	"modulecount")	
				otherInfo.uidata[0] =strlistvalue.at(x).toUInt();
			else if(strlistname.at(x)	==	"blacklevel")	
				otherInfo.uidata[1] = strlistvalue.at(x).toUInt();
			else if(strlistname.at(x)	==	"awbroidivisor")	
				otherInfo.uidata[2] = strlistvalue.at(x).toUInt();
			else if(strlistname.at(x) == "spec")
			{
				QStringList strlist		=	strlistvalue.at(x).split(",", QString::SkipEmptyParts);
				otherInfo.uidata[3]	=	strlist.at(0).toUInt(); //min
				otherInfo.uidata[4]	=	strlist.at(1).toUInt(); //max
			}	
		}
		break;
	case serialportitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x)	==	"serialport")	
				otherInfo.ucdata[0] =(unsigned char)(strlistvalue.at(x).toUInt() & 0xFF);
			else if(strlistname.at(x)	==	"ebaud")	
				otherInfo.ucdata[1] = (unsigned char)(strlistvalue.at(x).toUInt() & 0xFF);
			else if(strlistname.at(x)	==	"epar")	
				otherInfo.ucdata[2] = (unsigned char)(strlistvalue.at(x).toUInt() & 0xFF);
			else if(strlistname.at(x)	==	"estop")	
				otherInfo.ucdata[3] = (unsigned char)(strlistvalue.at(x).toUInt() & 0xFF);
			else if(strlistname.at(x)	==	"strinfo")	
				sprintf_s(&otherInfo.strdata[4], 26, "%s", strlistvalue.at(x).toAscii().data());
		}
		break;
	case camdoracalibrationitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x)
		{
			if(strlistname.at(x)=="left")						otherInfo.usdata[0] =strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x)=="top")				otherInfo.usdata[1] =strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x)=="right")			otherInfo.usdata[2] =strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x)=="bottom")		otherInfo.usdata[3] =strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x)=="minarea")		otherInfo.uidata[2] =strlistvalue.at(x).toUInt();
			else if(strlistname.at(x)=="left2")			otherInfo.usdata[6] =strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x)=="top2")			otherInfo.usdata[7] =strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x)=="right2")			otherInfo.usdata[8] =strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x)=="bottom2")		otherInfo.usdata[9] =strlistvalue.at(x).toUInt() & 0xFFFF;
			else if(strlistname.at(x)=="ysmax")		otherInfo.usdata[10] =strlistvalue.at(x).toUInt() & 0xFFFF;
		}
		break;
	case setcustomiicitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "group") otherInfo.uidata[0] = strlistvalue.at(x).toUInt();
		}
		break;
	case lsctemplateitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x)	==	"replace") 	otherInfo.uidata[0] = (strlistvalue.at(x)=="true")?(1):(0);
			else if(strlistname.at(x)	==	"type")	otherInfo.uidata[1] = strlistvalue.at(x).toUInt();
			else if(strlistname.at(x)	==	"shading")	otherInfo.uidata[2] = strlistvalue.at(x).toUInt();
		}
		break;
	case saveimageitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x)	==	"source"){
				if(strlistvalue.at(x) == "display")
					otherInfo.ucdata[0] = 1;
				else if(strlistvalue.at(x) == "program")
					otherInfo.ucdata[0] = 2;
				else if(strlistvalue.at(x) == "desktop")
					otherInfo.ucdata[0] = 3;
				else //sensor
					otherInfo.ucdata[0] = 0;
			}		
			else if(strlistname.at(x)	==	"format"){
				if(strlistvalue.at(x) == "raw8")
					otherInfo.ucdata[1] = 0;
				else if(strlistvalue.at(x) == "raw10")
					otherInfo.ucdata[1] = 1;
				else if(strlistvalue.at(x) == "bmp")
					otherInfo.ucdata[1] = 2;
				else if(strlistvalue.at(x) == "jpeg")
					otherInfo.ucdata[1] = 3;
				else //png
					otherInfo.ucdata[1] = 4;
			}
			else if(strlistname.at(x)	==	"original")
				otherInfo.ucdata[2] = (strlistvalue.at(x)=="true")?(1):(0);
			else if(strlistname.at(x)	==	"savefail")
				otherInfo.ucdata[3] = (strlistvalue.at(x)=="true")?(1):(0);
			else if(strlistname.at(x)	==	"sleep") otherInfo.usdata[2] = strlistvalue.at(x).toUShort();
		}
		break;
	case mtffcnearitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case mtffcmiddleitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case mtffcinfiniteitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case sfrnearafcitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case sfrmiddleafcitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case sfrfarafcitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case lpnearafcitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case lpmiddleafcitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case lpfarafcitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "tactics")	otherInfo.idata[0] = strlistvalue.at(x).toInt();
		}
		break;
	case jslafcringmoveitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x)	==	"angle")	otherInfo.dfldata[0] = strlistvalue.at(x).toDouble();
		}
		break;
	case jslafcverticalmoveitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x)	==	"abs")	otherInfo.idata[0] = (strlistvalue.at(x)=="true")?(1):(0);
			else if(strlistname.at(x)	==	"plus")	otherInfo.idata[1] = strlistvalue.at(x).toInt();
		}
		break;
	case dualcameracoaxialitytiltitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "dualcameracoaxialitytiltitemspecx")	
				otherInfo.dfldata[0]=strlistvalue.at(x).toDouble();
			else if (strlistname.at(x) == "dualcameracoaxialitytiltitemspecy")
			{
				otherInfo.dfldata[1]=strlistvalue.at(x).toDouble();
			}
		}
		break;
	case FishEyejungeitem:
		otherInfo.idata[0]	=	255;
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x){
			if(strlistname.at(x) == "FishEyejungeitemspec")	
				otherInfo.dfldata[0]=strlistvalue.at(x).toDouble();
		}
		break;
	case dualcameracoaxialityitem:
		golbalItempatchconfigstring(strData, strlistname, strlistvalue);
		for(unsigned int x=0;	x<strlistname.size();	++x)
		{
			if(strlistname.at(x) == "dualcmcenterdistance")
			{
				otherInfo.dfldata[0]=strlistvalue.at(x).toDouble(); 
			}
			else if(strlistname.at(x) == "squarehorizontaldistance")
			{
				otherInfo.dfldata[1]=strlistvalue.at(x).toDouble(); 
			}
			else if(strlistname.at(x) == "squareverticaldistance")
			{
				otherInfo.dfldata[2]=strlistvalue.at(x).toDouble(); 
			}
			else if(strlistname.at(x) == "dualcmtesdistance")
			{
				otherInfo.dfldata[3]=strlistvalue.at(x).toDouble(); 
			}
			else if(strlistname.at(x) == "dualcameracoaxialityitemspecx")
			{
				otherInfo.dfldata[4]=strlistvalue.at(x).toDouble();

			}
			else if(strlistname.at(x) == "dualcameracoaxialityitemspecy")
			{
				otherInfo.dfldata[5]=strlistvalue.at(x).toDouble();

			}
		
			else if(strlistname.at(x) == "maincameracolorsensor")
			{
				otherInfo.uidata[0]=0;
				if(strlistvalue.at(x) == "true") otherInfo.uidata[0]=1;
			}
			else if(strlistname.at(x) == "subcameracolorsensor")
			{
				otherInfo.uidata[1]=0;
				if(strlistvalue.at(x) == "true") otherInfo.uidata[1]=1;
			}
 			else if(strlistname.at(x) == "dualcameracoaxialityitemspecpixelx")
 			{
 				otherInfo.dfldata[6]=strlistvalue.at(x).toUInt();
 
 			}
 			else if(strlistname.at(x) == "dualcameracoaxialityitemspecpixely")
 			{
 				otherInfo.dfldata[7]=strlistvalue.at(x).toDouble();
 
 			}

		}
		break;

	default:
		break;
	}
}

__inline void globalgetShortcutAddInfoString(unsigned short usitem, QString& strData, _scotherInfo& otherInfo)
{
	QStringList strlistname, strlistvalue, listRect;
	strData.clear();
	switch (usitem)
	{
	case showresultitem: //showresultitem(notsavelog:false)(notshowtotalresult:false)
		strlistname.append("notsavelog");				strlistname.append((otherInfo.uidata[0])?("true"):("false"));
		strlistname.append("notshowtotalresult");	strlistname.append((otherInfo.uidata[1])?("true"):("false"));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case debugitem: //debugitem(testtype:0)
		strlistname.append("testtype");				strlistname.append(QString::number(otherInfo.uidata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case sleepitem:
		strlistname.append("value");	strlistname.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case messageboxitem:
		strlistname.append("info");	strlistname.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case brightnessitem: //brightnessitem(roi:2200,1570,2400,1770)(spec:50,100)
		listRect.append(QString::number(otherInfo.stRect[0].left));
		listRect.append(QString::number(otherInfo.stRect[0].top));
		listRect.append(QString::number(otherInfo.stRect[0].right));
		listRect.append(QString::number(otherInfo.stRect[0].bottom));
		strlistname.append("roi"); strlistvalue.append(listRect.join(","));

		listRect.clear();
		listRect.append(QString::number(otherInfo.idata[4]));
		listRect.append(QString::number(otherInfo.idata[5]));
		strlistname.append("spec"); strlistvalue.append(listRect.join(","));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case checkcoloritem: //checkcoloritem(roi:2200,1570,2400,1770)(r/gr:0.45,0.75)(b/gr:0.45,0.75)
		listRect.append(QString::number(otherInfo.stRect[0].left));
		listRect.append(QString::number(otherInfo.stRect[0].top));
		listRect.append(QString::number(otherInfo.stRect[0].right));
		listRect.append(QString::number(otherInfo.stRect[0].bottom));
		strlistname.append("roi"); strlistvalue.append(listRect.join(","));

		listRect.clear();
		listRect.append(QString::number(otherInfo.fldata[4]));
		listRect.append(QString::number(otherInfo.fldata[5]));
		strlistname.append("r/gr"); strlistvalue.append(listRect.join(","));

		listRect.clear();
		listRect.append(QString::number(otherInfo.fldata[6]));
		listRect.append(QString::number(otherInfo.fldata[7]));
		strlistname.append("b/gr"); strlistvalue.append(listRect.join(","));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break; 
	case exposureitem:
		strlistname.append("value"); strlistvalue.append(QString::number(otherInfo.uidata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case gainitem:
		strlistname.append("value"); strlistvalue.append(QString::number(otherInfo.fldata[0], 'f', 3));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case motoritem:
		strlistname.append("value"); strlistvalue.append(QString::number(otherInfo.idata[0]));
		strlistname.append("otp");
		if(otherInfo.idata[1] == 0)	strlistvalue.append("near");
		else if(otherInfo.idata[1] == 1)	strlistvalue.append("middle");
		else if(otherInfo.idata[1] == 2)	strlistvalue.append("far");
		else	strlistvalue.append("no");
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case autoexposureitem:
		listRect.append(QString::number(otherInfo.stRect[0].left));
		listRect.append(QString::number(otherInfo.stRect[0].top));
		listRect.append(QString::number(otherInfo.stRect[0].right));
		listRect.append(QString::number(otherInfo.stRect[0].bottom));
		strlistname.append("roi"); strlistvalue.append(listRect.join(","));

		listRect.clear();
		listRect.append(QString::number(otherInfo.uidata[4]));
		listRect.append(QString::number(otherInfo.uidata[5]));
		strlistname.append("spec"); strlistvalue.append(listRect.join(","));
		strlistname.append("sleep"); strlistvalue.append(QString::number(otherInfo.uidata[6]));
		strlistname.append("database"); strlistvalue.append(QString::number(otherInfo.uidata[7] & 0xFF));
		strlistname.append("channel_gr"); strlistvalue.append((otherInfo.uidata[7] & 0xFF000000)?("true"):("false"));
		strlistname.append("white"); strlistvalue.append((otherInfo.uidata[7] & 0x00FF0000)?("true"):("false"));
		strlistname.append("imagecenter"); strlistvalue.append((otherInfo.uidata[7] & 0x0000FF00)?("true"):("false"));
		strlistname.append("centerroiratio"); strlistvalue.append(QString::number(otherInfo.fldata[8]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case autofocusitem:
		strlistname.append("alg");				strlistvalue.append(QString::number(otherInfo.ucdata[0]));
		strlistname.append("chart");			strlistvalue.append(QString::number(otherInfo.ucdata[1]));
		strlistname.append("timeout");		strlistvalue.append(QString::number(otherInfo.usdata[1]));
		strlistname.append("left");				strlistvalue.append(QString::number(otherInfo.usdata[2]));
		strlistname.append("top");				strlistvalue.append(QString::number(otherInfo.usdata[3]));
		strlistname.append("right");			strlistvalue.append(QString::number(otherInfo.usdata[4]));
		strlistname.append("bottom");		strlistvalue.append(QString::number(otherInfo.usdata[5]));
		strlistname.append("startpos");		strlistvalue.append(QString::number(otherInfo.usdata[6]));
		strlistname.append("pedestal");		strlistvalue.append(QString::number(otherInfo.usdata[7]));
		strlistname.append("sleep");			strlistvalue.append(QString::number(otherInfo.usdata[8]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case playaudioitem:
		strlistname.append("source");	strlistvalue.append(QString::number(otherInfo.uidata[0]));
		strlistname.append("time");		strlistvalue.append(QString::number(otherInfo.uidata[1]));
		strlistname.append("samplerate");		strlistvalue.append(QString::number(otherInfo.fldata[2]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case iobitoutitem:
		strlistname.append("card");		strlistvalue.append(QString::number(otherInfo.uidata[0]));
		strlistname.append("port");			strlistvalue.append(QString::number(otherInfo.uidata[1]));
		strlistname.append("bit");			strlistvalue.append(QString::number(otherInfo.uidata[2]));
		strlistname.append("out");			strlistvalue.append(QString::number(otherInfo.uidata[3]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case motormoveitem:
		strlistname.append("card");		strlistvalue.append(QString::number(otherInfo.uidata[0]));
		strlistname.append("axis");			strlistvalue.append(QString::number(otherInfo.uidata[1]));
		strlistname.append("abs");			strlistvalue.append(QString::number(otherInfo.uidata[2]));
		strlistname.append("dis");			strlistvalue.append(QString::number(otherInfo.dfldata[2], 'f', 6));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case chartalignlitem:
		strlistname.append("charttype");		strlistvalue.append(QString::number(otherInfo.ucdata[0]));
		strlistname.append("angle");				strlistvalue.append(QString::number(otherInfo.ucdata[1]));
		strlistname.append("times");				strlistvalue.append(QString::number(otherInfo.ucdata[2]));
		strlistname.append("markmin");			strlistvalue.append(QString::number(otherInfo.usdata[2]));
		strlistname.append("markmax");		strlistvalue.append(QString::number(otherInfo.usdata[3]));
		strlistname.append("diff");					strlistvalue.append(QString::number(otherInfo.usdata[4]));
		strlistname.append("spec");				strlistvalue.append(QString::number(otherInfo.usdata[5]));
		strlistname.append("fov");				strlistvalue.append(QString::number(otherInfo.fldata[3], 'f', 2));
		strlistname.append("scalex");			strlistvalue.append(QString::number(otherInfo.fldata[4], 'f', 2));
		strlistname.append("scaley");			strlistvalue.append(QString::number(otherInfo.fldata[5], 'f', 2));
		strlistname.append("sleep");				strlistvalue.append(QString::number(otherInfo.usdata[12]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case imageprocessitem:
		strlistname.append("blemishenhance");		strlistvalue.append(QString::number(otherInfo.ucdata[0]));
		strlistname.append("lsc");							strlistvalue.append(QString::number(otherInfo.ucdata[1]));
		strlistname.append("awb");							strlistvalue.append(QString::number(otherInfo.ucdata[2]));
		strlistname.append("awbrate");					strlistvalue.append(QString::number(otherInfo.ucdata[3]));
		strlistname.append("gainr");						strlistvalue.append(QString::number(otherInfo.fldata[1], 'f', 4));
		strlistname.append("gainb");						strlistvalue.append(QString::number(otherInfo.fldata[2], 'f', 4));
		strlistname.append("blacklevel");				strlistvalue.append(QString::number(otherInfo.ucdata[12]));
		strlistname.append("mirror");						strlistvalue.append(QString::number(otherInfo.ucdata[13]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case autorawcapture:
		break;
	case serialportitem:
		strlistname.append("serialport");		strlistvalue.append(QString::number(otherInfo.ucdata[0]));
		strlistname.append("ebaud");				strlistvalue.append(QString::number(otherInfo.ucdata[1]));
		strlistname.append("epar");				strlistvalue.append(QString::number(otherInfo.ucdata[2]));
		strlistname.append("estop");				strlistvalue.append(QString::number(otherInfo.ucdata[3]));
		strlistname.append("strinfo");				strlistvalue.append(QString::fromAscii(&otherInfo.strdata[4]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case camdoracalibrationitem:
		strlistname.append("left");		strlistvalue.append(QString::number(otherInfo.usdata[0]));
		strlistname.append("top");		strlistvalue.append(QString::number(otherInfo.usdata[1]));
		strlistname.append("right");	strlistvalue.append(QString::number(otherInfo.usdata[2]));
		strlistname.append("bottom");strlistvalue.append(QString::number(otherInfo.usdata[3]));
		strlistname.append("minarea");	strlistvalue.append(QString::number(otherInfo.uidata[2]));
		strlistname.append("left2");			strlistvalue.append(QString::number(otherInfo.usdata[6]));
		strlistname.append("top2");		strlistvalue.append(QString::number(otherInfo.usdata[7]));
		strlistname.append("right2");		strlistvalue.append(QString::number(otherInfo.usdata[8]));
		strlistname.append("bottom2");	strlistvalue.append(QString::number(otherInfo.usdata[9]));
		strlistname.append("ysmax");	strlistvalue.append(QString::number(otherInfo.usdata[10]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case setcustomiicitem:
		strlistname.append("group");		strlistvalue.append(QString::number(otherInfo.uidata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case lsctemplateitem:
		strlistname.append("replace");		strlistvalue.append((otherInfo.uidata[0])?("true"):("false"));
		strlistname.append("type");		strlistvalue.append(QString::number(otherInfo.uidata[1]));
		strlistname.append("shading");		strlistvalue.append(QString::number(otherInfo.uidata[2]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);
		break;
	case saveimageitem:
		strlistname.append("source");
		if(otherInfo.ucdata[0] == 1) strlistvalue.append("display");
		else if(otherInfo.ucdata[0] == 2) strlistvalue.append("program");
		else if(otherInfo.ucdata[0] == 3) strlistvalue.append("desktop");
		else strlistvalue.append("sensor");

		strlistname.append("format");
		if(otherInfo.ucdata[1] == 0)	strlistvalue.append("raw8");
		else if(otherInfo.ucdata[1] == 1)	strlistvalue.append("raw10");
		else if(otherInfo.ucdata[1] == 2)	strlistvalue.append("bmp");
		else if(otherInfo.ucdata[1] == 3)	strlistvalue.append("jpeg");
		else	strlistvalue.append("png");

		strlistname.append("original");	strlistvalue.append((otherInfo.ucdata[2])?("true"):("false"));
		strlistname.append("savefail");	strlistvalue.append((otherInfo.ucdata[3])?("true"):("false"));
		strlistname.append("sleep");	strlistvalue.append(QString::number(otherInfo.usdata[2]));

		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case mtffcnearitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case mtffcmiddleitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case mtffcinfiniteitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case sfrnearafcitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case sfrmiddleafcitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case sfrfarafcitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case lpnearafcitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case lpmiddleafcitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case lpfarafcitem:
		strlistname.append("tactics");	strlistvalue.append(QString::number(otherInfo.idata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case jslafcringmoveitem:
		strlistname.append("angle");	strlistvalue.append(QString::number(otherInfo.dfldata[0]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case jslafcverticalmoveitem:
		strlistname.append("abs"); strlistvalue.append((otherInfo.idata[0])?("true"):("false"));
		strlistname.append("plus");	strlistvalue.append(QString::number(otherInfo.idata[1]));
		golbalItemjoinconfigstring(strData, strlistname, strlistvalue);	
		break;
	case dualcameracoaxialityitem:
		break;
	default:
		break;
	}
}

namespace HISDBTEMPLATE
{

	__inline bool addDB(QSqlDatabase& templatedb)
	{
		templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open())
		{
			QMessageBox::critical(0, QObject::tr("ERROR"), QObject::tr("Open the HisFX3Template DB fail"));
			return false;
		}
		return true;
	}

	__inline void removeDB()
	{
		QSqlDatabase::removeDatabase("querytemplate");
	}

	__inline void deleteItem(QSqlDatabase& stSqlDB, QString strTableName, unsigned int uiFlag=0, QVariant classfy=QVariant(), QVariant item=QVariant(), QVariant itemsuffix1=QVariant(), QVariant itemsuffix2=QVariant(), QVariant key=QVariant())
	{		
		QString strCommand = "DELETE FROM " % strTableName % " WHERE";
		bool bInit = false;
		if(uiFlag & _HISINLINEDB_FLAG_classfy) { strCommand = strCommand % " classfy=:classfy"; bInit = true; }
		if(uiFlag & _HISINLINEDB_FLAG_item) {strCommand = (bInit)?(strCommand = strCommand % " AND item=:item"):(strCommand = strCommand % " item=:item"); bInit = true; }
		if(uiFlag & _HISINLINEDB_FLAG_itemsuffix1) {strCommand = (bInit)?(strCommand = strCommand % " AND itemsuffix1=:itemsuffix1"):(strCommand = strCommand % " itemsuffix1=:itemsuffix1"); bInit = true; }
		if(uiFlag & _HISINLINEDB_FLAG_itemsuffix2) {strCommand = (bInit)?(strCommand = strCommand % " AND itemsuffix2=:itemsuffix2"):(strCommand = strCommand % " itemsuffix2=:itemsuffix2"); bInit = true; }
		if(uiFlag & _HISINLINEDB_FLAG_key) {strCommand = (bInit)?(strCommand = strCommand % " AND key=:key"):(strCommand = strCommand % " key=:key"); bInit = true; }
		QSqlQuery query(stSqlDB);
		query.prepare(strCommand);
		if(uiFlag & _HISINLINEDB_FLAG_classfy) query.bindValue(":classfy", classfy);
		if(uiFlag & _HISINLINEDB_FLAG_item) query.bindValue(":item", item);
		if(uiFlag & _HISINLINEDB_FLAG_itemsuffix1) query.bindValue(":itemsuffix1", itemsuffix1);
		if(uiFlag & _HISINLINEDB_FLAG_itemsuffix2) query.bindValue(":itemsuffix2", itemsuffix2);
		if(uiFlag & _HISINLINEDB_FLAG_key) query.bindValue(":key", key);
		query.exec();
	}

	__inline void insertItem(QSqlDatabase& stSqlDB, QString strTableName, int id=0, QVariant classfy=QVariant(), QVariant item=QVariant(), QVariant itemsuffix1=QVariant(), \
		QVariant itemsuffix2=QVariant(), QVariant key=QVariant(), QVariant value1=QVariant(), QVariant reserve=QVariant(), QVariant note=QVariant())
	{
		QSqlQuery query(stSqlDB);
		query.prepare("INSERT INTO " % strTableName % "(id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve,note) VALUES(:id,:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve,:note)");
		query.bindValue(":id", id);
		query.bindValue(":classfy", classfy);
		query.bindValue(":item", item);
		query.bindValue(":itemsuffix1", itemsuffix1);
		query.bindValue(":itemsuffix2", itemsuffix2);
		query.bindValue(":key", key);
		query.bindValue(":value", value1);
		query.bindValue(":reserve", reserve);
		query.bindValue(":note", note);
		query.exec();
	}

}

namespace HISDBCUSTOM
{
	__inline bool addDB(QSqlDatabase& templatedb)
	{
		templatedb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!templatedb.open())
		{
			QMessageBox::critical(0, QObject::tr("ERROR"), QObject::tr("Open the HisFX3Custom DB fail"));
			return false;
		}
		return true;
	}

	__inline void removeDB()
	{
		QSqlDatabase::removeDatabase("querycustom");
	}

	__inline void deleteItem(QSqlDatabase& stSqlDB, QString strTableName, unsigned int uiFlag=0, QVariant classfy=QVariant(), QVariant item=QVariant(), QVariant itemsuffix1=QVariant(), QVariant itemsuffix2=QVariant(), QVariant key=QVariant())
	{		
		QString strCommand = "DELETE FROM " % strTableName % " WHERE";
		bool bInit = false;
		if(uiFlag & _HISINLINEDB_FLAG_classfy) { strCommand = strCommand % " classfy=:classfy"; bInit = true; }
		if(uiFlag & _HISINLINEDB_FLAG_item) {strCommand = (bInit)?(strCommand = strCommand % " AND item=:item"):(strCommand = strCommand % " item=:item"); bInit = true; }
		if(uiFlag & _HISINLINEDB_FLAG_itemsuffix1) {strCommand = (bInit)?(strCommand = strCommand % " AND itemsuffix1=:itemsuffix1"):(strCommand = strCommand % " itemsuffix1=:itemsuffix1"); bInit = true; }
		if(uiFlag & _HISINLINEDB_FLAG_itemsuffix2) {strCommand = (bInit)?(strCommand = strCommand % " AND itemsuffix2=:itemsuffix2"):(strCommand = strCommand % " itemsuffix2=:itemsuffix2"); bInit = true; }
		if(uiFlag & _HISINLINEDB_FLAG_key) {strCommand = (bInit)?(strCommand = strCommand % " AND key=:key"):(strCommand = strCommand % " key=:key"); bInit = true; }
		QSqlQuery query(stSqlDB);
		query.prepare(strCommand);
		if(uiFlag & _HISINLINEDB_FLAG_classfy) query.bindValue(":classfy", classfy);
		if(uiFlag & _HISINLINEDB_FLAG_item) query.bindValue(":item", item);
		if(uiFlag & _HISINLINEDB_FLAG_itemsuffix1) query.bindValue(":itemsuffix1", itemsuffix1);
		if(uiFlag & _HISINLINEDB_FLAG_itemsuffix2) query.bindValue(":itemsuffix2", itemsuffix2);
		if(uiFlag & _HISINLINEDB_FLAG_key) query.bindValue(":key", key);
		query.exec();
	}

	__inline void insertItem(QSqlDatabase& stSqlDB, QString strTableName, int id=0, QVariant classfy=QVariant(), QVariant item=QVariant(), QVariant itemsuffix1=QVariant(), \
		QVariant itemsuffix2=QVariant(), QVariant key=QVariant(), QVariant value1=QVariant(), QVariant reserve=QVariant(), QVariant note=QVariant())
	{
		QSqlQuery query(stSqlDB);
		query.prepare("INSERT INTO " % strTableName % "(id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve,note) VALUES(:id,:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve,:note)");
		query.bindValue(":id", id);
		query.bindValue(":classfy", classfy);
		query.bindValue(":item", item);
		query.bindValue(":itemsuffix1", itemsuffix1);
		query.bindValue(":itemsuffix2", itemsuffix2);
		query.bindValue(":key", key);
		query.bindValue(":value", value1);
		query.bindValue(":reserve", reserve);
		query.bindValue(":note", note);
		query.exec();
	}

	__inline bool isTableExist(const QString&  strTableName)
	{
		if(strTableName.isEmpty()) return false;

		bool bExist;
		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
			if (!templatedb.open())
			{
				QMessageBox::critical(0, QObject::tr("ERROR"), QObject::tr("Open the HisFX3Custom DB fail"));
				return false;
			}

			QStringList tableList	=	templatedb.tables();
			templatedb.close();

			bExist	=	tableList.contains(strTableName);
		}

		QSqlDatabase::removeDatabase("querycustom");
		return bExist;
	}

	__inline bool isCustomCanOpen()
	{
		bool bIs = true;
		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
			if (!templatedb.open())
			{
				bIs	=	false;
				QMessageBox::critical(0, QObject::tr("ERROR"), QObject::tr("Open the HisFX3Custom DB fail"));			
			}
		}

		QSqlDatabase::removeDatabase("querycustom");
		return bIs;
	}

	__inline QStringList getTableList()
	{
		QStringList tableList;
		{
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
			if (!customdb.open()){
				QMessageBox::critical(0, QObject::tr("ERROR"), QObject::tr("Open the HisFX3Custom DB fail"));
				return tableList;
			}

			tableList	=	customdb.tables();
			customdb.close();
		}
		QSqlDatabase::removeDatabase("querycustom");
		return tableList;
	}
}

namespace HISDBROLONGO
{
	__inline bool isTableExist(const QString&  strTableName)
	{
		if(strTableName.isEmpty()) return false;

		bool bExist;
		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!templatedb.open())
			{
				QMessageBox::critical(0, QObject::tr("ERROR"), QObject::tr("Open the HisFX3Rolongo DB fail"));
				return false;
			}

			QStringList tableList	=	templatedb.tables();
			templatedb.close();

			bExist	=	tableList.contains(strTableName);
		}

		QSqlDatabase::removeDatabase("queryrolongo");
		return bExist;
	}

	__inline bool isCustomCanOpen()
	{
		bool bIs = true;
		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!templatedb.open())
			{
				bIs	=	false;
				QMessageBox::critical(0, QObject::tr("ERROR"), QObject::tr("Open the HisFX3Rolongo DB fail"));			
			}
		}

		QSqlDatabase::removeDatabase("queryrolongo");
		return bIs;
	}

	__inline bool createNewTable(QString strCommand)
	{
		bool bExist;
		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!templatedb.open())
			{
				QMessageBox::critical(0, QObject::tr("ERROR"), QObject::tr("Open the HisFX3Rolongo DB fail"));
				return false;
			}

			QSqlQuery query(templatedb);
			query.exec("create table " % strCommand);

			templatedb.close();

			bExist	=	true;
		}

		QSqlDatabase::removeDatabase("queryrolongo");
		return bExist;
	}
}

namespace HISGLOBALSHORTCUT
{

	__inline unsigned short getIdFromSaveName(QList<_TestItem_Basic_Info>& itemList, QString& strData)
	{
		for(QList<_TestItem_Basic_Info>::iterator theiterator = itemList.begin(); theiterator != itemList.end(); theiterator++)
		{
			if(theiterator->strSaveName == strData) return theiterator->uiID;
		}
		return 0;
	}

	__inline unsigned short getIdFromDescripeName(QList<_TestItem_Basic_Info>& itemList, QString& strData)
	{
		for(QList<_TestItem_Basic_Info>::iterator theiterator = itemList.begin(); theiterator != itemList.end(); theiterator++)
		{
			if(theiterator->strDescripName == strData) return theiterator->uiID;
		}
		return 0;
	}
	 
	__inline QString getEditInfoFromDescripeName(QList<_TestItem_Basic_Info>& itemList, QString& strData)
	{
		for(QList<_TestItem_Basic_Info>::iterator theiterator = itemList.begin(); theiterator != itemList.end(); theiterator++)
		{
			if(theiterator->strDescripName == strData) return theiterator->strEditInfo;
		}
		return QString();
	}

	__inline QString getSaveNameFromDescripeName(QList<_TestItem_Basic_Info>& itemList, QString& strData)
	{
		for(QList<_TestItem_Basic_Info>::iterator theiterator = itemList.begin(); theiterator != itemList.end(); theiterator++)
		{
			if(theiterator->strDescripName == strData) return theiterator->strSaveName;
		}
		return QString();
	}

	__inline QString getSaveNameFromId(QList<_TestItem_Basic_Info>& itemList, unsigned int uiID)
	{
		for(QList<_TestItem_Basic_Info>::iterator theiterator = itemList.begin(); theiterator != itemList.end(); theiterator++)
		{
			if(theiterator->uiID == uiID) return theiterator->strSaveName;
		}
		return QString();
	}

	__inline QString getDecripeNameFromId(QList<_TestItem_Basic_Info>& itemList, unsigned int uiID)
	{
		for(QList<_TestItem_Basic_Info>::iterator theiterator = itemList.begin(); theiterator != itemList.end(); theiterator++)
		{
			if(theiterator->uiID == uiID) return theiterator->strDescripName;
		}
		return QString();
	}
}

#endif
