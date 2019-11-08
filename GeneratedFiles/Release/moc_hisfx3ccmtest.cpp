/****************************************************************************
** Meta object code from reading C++ file 'hisfx3ccmtest.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hisfx3ccmtest.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hisfx3ccmtest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_renderframe[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      29,   24,   12,   12, 0x05,
      56,   50,   12,   12, 0x05,
     109,   71,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     143,   12,   12,   12, 0x0a,
     158,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_renderframe[] = {
    "renderframe\0\0finished()\0info\0"
    "information(QString)\0itype\0drawframe(int)\0"
    "fpsSensor,fpsUpload,fpsDisplay,uiFlag\0"
    "updatefps(float,float,float,uint)\0"
    "startpreview()\0finish()\0"
};

void renderframe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        renderframe *_t = static_cast<renderframe *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->drawframe((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updatefps((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 4: _t->startpreview(); break;
        case 5: _t->finish(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData renderframe::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject renderframe::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_renderframe,
      qt_meta_data_renderframe, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &renderframe::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *renderframe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *renderframe::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_renderframe))
        return static_cast<void*>(const_cast< renderframe*>(this));
    return QObject::qt_metacast(_clname);
}

int renderframe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void renderframe::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void renderframe::information(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void renderframe::drawframe(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void renderframe::updatefps(float _t1, float _t2, float _t3, unsigned int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
static const uint qt_meta_data_improveraw[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      28,   23,   11,   11, 0x05,
      87,   49,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,   11,   11,   11, 0x0a,
     136,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_improveraw[] = {
    "improveraw\0\0finished()\0info\0"
    "information(QString)\0"
    "fpsSensor,fpsUpload,fpsDisplay,uiFlag\0"
    "updatefps(float,float,float,uint)\0"
    "startpreview()\0finish()\0"
};

void improveraw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        improveraw *_t = static_cast<improveraw *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updatefps((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 3: _t->startpreview(); break;
        case 4: _t->finish(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData improveraw::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject improveraw::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_improveraw,
      qt_meta_data_improveraw, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &improveraw::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *improveraw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *improveraw::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_improveraw))
        return static_cast<void*>(const_cast< improveraw*>(this));
    return QObject::qt_metacast(_clname);
}

int improveraw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void improveraw::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void improveraw::information(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void improveraw::updatefps(float _t1, float _t2, float _t3, unsigned int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
static const uint qt_meta_data_improvergb24[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      30,   25,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   13,   13,   13, 0x0a,
      66,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_improvergb24[] = {
    "improvergb24\0\0finished()\0info\0"
    "information(QString)\0startpreview()\0"
    "finish()\0"
};

void improvergb24::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        improvergb24 *_t = static_cast<improvergb24 *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->startpreview(); break;
        case 3: _t->finish(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData improvergb24::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject improvergb24::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_improvergb24,
      qt_meta_data_improvergb24, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &improvergb24::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *improvergb24::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *improvergb24::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_improvergb24))
        return static_cast<void*>(const_cast< improvergb24*>(this));
    return QObject::qt_metacast(_clname);
}

int improvergb24::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void improvergb24::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void improvergb24::information(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_HisFX3CCMTest[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      58,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x05,
      53,   41,   14,   14, 0x05,
      90,   14,   14,   14, 0x05,
     133,   99,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     211,  193,   14,   14, 0x0a,
     249,   14,   14,   14, 0x0a,
     265,  263,   14,   14, 0x0a,
     300,   14,   14,   14, 0x0a,
     318,   14,   14,   14, 0x0a,
     344,  335,   14,   14, 0x0a,
     366,  335,   14,   14, 0x0a,
     395,  389,   14,   14, 0x0a,
     415,   14,   14,   14, 0x08,
     434,   14,   14,   14, 0x08,
     453,   14,   14,   14, 0x08,
     481,  473,   14,   14, 0x08,
     523,  500,   14,   14, 0x08,
     591,  583,   14,   14, 0x08,
     617,  610,   14,   14, 0x08,
     635,   14,   14,   14, 0x08,
     652,   14,   14,   14, 0x08,
     710,  670,   14,   14, 0x08,
     769,   14,   14,   14, 0x08,
     789,  785,   14,   14, 0x08,
     817,   14,   14,   14, 0x08,
     833,   14,   14,   14, 0x08,
     852,   14,   14,   14, 0x08,
     870,   14,   14,   14, 0x08,
     901,  894,   14,   14, 0x08,
     923,   14,   14,   14, 0x08,
     943,  938,   14,   14, 0x08,
     973,   14,   14,   14, 0x08,
     990,   14,   14,   14, 0x08,
    1017, 1008,   14,   14, 0x08,
    1041, 1008,   14,   14, 0x08,
    1059, 1008,   14,   14, 0x08,
    1078,   14,   14,   14, 0x08,
    1100, 1095,   14,   14, 0x08,
    1146, 1140,   14,   14, 0x08,
    1177,   14,   14,   14, 0x08,
    1201,   14,   14,   14, 0x08,
    1218,   14,   14,   14, 0x08,
    1233,   14,   14,   14, 0x08,
    1256,   14,   14,   14, 0x08,
    1275,   14,   14,   14, 0x08,
    1293,   14,   14,   14, 0x08,
    1353, 1315,   14,   14, 0x08,
    1387,   14,   14,   14, 0x08,
    1454, 1409,   14,   14, 0x08,
    1501,   14,   14,   14, 0x08,
    1518,   14,   14,   14, 0x08,
    1543,   14,   14,   14, 0x08,
    1563,   14,   14,   14, 0x08,
    1583,   14,   14,   14, 0x08,
    1605,   14,   14,   14, 0x08,
    1620,   14,   14,   14, 0x08,
    1641,   14,   14,   14, 0x08,
    1660,  263,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HisFX3CCMTest[] = {
    "HisFX3CCMTest\0\0info\0information(QString)\0"
    "key,uctimer\0keyshortcutPress(char,unsigned char)\0"
    "finish()\0flY,flR,flG,flB,flR2G,flB2G,flMTF\0"
    "luxMonitorResult(float,float,float,float,float,float,float)\0"
    "usItem,strAddInfo\0"
    "itemdebugslot(unsigned short,QString)\0"
    "drawproject()\0,\0testsignalslot(char,unsigned char)\0"
    "ClickExecbutton()\0slotImageDebug()\0"
    "bConnect\0updateCOMstatus(bool)\0"
    "updateCOM2status(bool)\0iInfo\0"
    "slotMessageBox(int)\0ShowConfigDialog()\0"
    "EnableConfigMenu()\0slotWheelVCMTimer()\0"
    "benable\0enablebutton(bool)\0"
    "usitem,ucstatus,ustime\0"
    "showItemStatus2EndResult(unsigned short,unsigned char,uint)\0"
    "istatus\0showEndresult(int)\0uiType\0"
    "painterplot(uint)\0manulsaveImage()\0"
    "EnableSaveImage()\0"
    "strdir,strname,ucimageformat,ucimagesrc\0"
    "execsaveimage(QString,QString,unsigned char,unsigned char)\0"
    "chooseconfigs()\0pos\0customMenuRequested(QPoint)\0"
    "adddebugpoint()\0removedebugpoint()\0"
    "HardwareSetting()\0slotBlemishTuningTool()\0"
    "uiflag\0enableinfotimer(uint)\0"
    "loopshowinfo()\0text\0serialNumtextChanged(QString)\0"
    "ShowManualTool()\0showItemExeTool()\0"
    "bChecked\0offlineModeSwitch(bool)\0"
    "slotoffline(bool)\0slotofflineb(bool)\0"
    "offlineSetPath()\0item\0"
    "TextInfoDoubleClicked(QListWidgetItem*)\0"
    "index\0slotImageShowPolicyChange(int)\0"
    "slotManualModeAConfig()\0slotTcpConnect()\0"
    "slotButtonFA()\0slotButtonWhiteField()\0"
    "slotButtonNearFC()\0slotButtonFarFC()\0"
    "slotTcpIpDisconnect()\0"
    "fpsSensor,fpsUpload,fpsDisplay,uiFlag\0"
    "updatefps(float,float,float,uint)\0"
    "calculateLuxMonitor()\0"
    "uiLeft,uiRight,uiTop,uiBottom,uiTimer,uiFlag\0"
    "startLuxMonitor(uint,uint,uint,uint,uint,uint)\0"
    "stopLuxMonitor()\0slotShowOperationPanel()\0"
    "slotShowInfoPanel()\0slotShowTextPanel()\0"
    "slotShowStatisPanel()\0slotTestItem()\0"
    "showBindWid(QString)\0showDebugBurnWid()\0"
    "updateSN(QString,QString)\0"
};

void HisFX3CCMTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HisFX3CCMTest *_t = static_cast<HisFX3CCMTest *>(_o);
        switch (_id) {
        case 0: _t->information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->keyshortcutPress((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 2: _t->finish(); break;
        case 3: _t->luxMonitorResult((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7]))); break;
        case 4: _t->itemdebugslot((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->drawproject(); break;
        case 6: _t->testsignalslot((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 7: _t->ClickExecbutton(); break;
        case 8: _t->slotImageDebug(); break;
        case 9: _t->updateCOMstatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->updateCOM2status((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->slotMessageBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->ShowConfigDialog(); break;
        case 13: _t->EnableConfigMenu(); break;
        case 14: _t->slotWheelVCMTimer(); break;
        case 15: _t->enablebutton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->showItemStatus2EndResult((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 17: _t->showEndresult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->painterplot((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 19: _t->manulsaveImage(); break;
        case 20: _t->EnableSaveImage(); break;
        case 21: _t->execsaveimage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< unsigned char(*)>(_a[3])),(*reinterpret_cast< unsigned char(*)>(_a[4]))); break;
        case 22: _t->chooseconfigs(); break;
        case 23: _t->customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 24: _t->adddebugpoint(); break;
        case 25: _t->removedebugpoint(); break;
        case 26: _t->HardwareSetting(); break;
        case 27: _t->slotBlemishTuningTool(); break;
        case 28: _t->enableinfotimer((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 29: _t->loopshowinfo(); break;
        case 30: _t->serialNumtextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->ShowManualTool(); break;
        case 32: _t->showItemExeTool(); break;
        case 33: _t->offlineModeSwitch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->slotoffline((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->slotofflineb((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->offlineSetPath(); break;
        case 37: _t->TextInfoDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 38: _t->slotImageShowPolicyChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->slotManualModeAConfig(); break;
        case 40: _t->slotTcpConnect(); break;
        case 41: _t->slotButtonFA(); break;
        case 42: _t->slotButtonWhiteField(); break;
        case 43: _t->slotButtonNearFC(); break;
        case 44: _t->slotButtonFarFC(); break;
        case 45: _t->slotTcpIpDisconnect(); break;
        case 46: _t->updatefps((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 47: _t->calculateLuxMonitor(); break;
        case 48: _t->startLuxMonitor((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6]))); break;
        case 49: _t->stopLuxMonitor(); break;
        case 50: _t->slotShowOperationPanel(); break;
        case 51: _t->slotShowInfoPanel(); break;
        case 52: _t->slotShowTextPanel(); break;
        case 53: _t->slotShowStatisPanel(); break;
        case 54: _t->slotTestItem(); break;
        case 55: _t->showBindWid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 56: _t->showDebugBurnWid(); break;
        case 57: _t->updateSN((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HisFX3CCMTest::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HisFX3CCMTest::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HisFX3CCMTest,
      qt_meta_data_HisFX3CCMTest, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HisFX3CCMTest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HisFX3CCMTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HisFX3CCMTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HisFX3CCMTest))
        return static_cast<void*>(const_cast< HisFX3CCMTest*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HisFX3CCMTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 58)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 58;
    }
    return _id;
}

// SIGNAL 0
void HisFX3CCMTest::information(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HisFX3CCMTest::keyshortcutPress(char _t1, unsigned char _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HisFX3CCMTest::finish()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void HisFX3CCMTest::luxMonitorResult(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6, float _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
