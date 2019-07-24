/****************************************************************************
** Meta object code from reading C++ file 'itemprocess.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../itemprocess.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'itemprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_itemprocess[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      31,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      32,   24,   12,   12, 0x05,
      51,   12,   12,   12, 0x05,
      66,   12,   12,   12, 0x05,
      89,   81,   12,   12, 0x05,
     128,  105,   12,   12, 0x05,
     193,  188,   12,   12, 0x05,
     221,  214,   12,   12, 0x05,
     239,   12,   12,   12, 0x05,
     256,   12,   12,   12, 0x05,
     278,  271,   12,   12, 0x05,
     300,   12,   12,   12, 0x05,
     352,  312,   12,   12, 0x05,
     417,  411,   12,   12, 0x05,
     461,  438,   12,   12, 0x05,
     509,  499,   12,   12, 0x05,
     546,  537,   12,   12, 0x05,
     570,  537,   12,   12, 0x05,
     595,   12,   12,   12, 0x05,
     633,  616,   12,   12, 0x05,
     670,   12,   12,   12, 0x05,
     702,  695,   12,   12, 0x05,
     734,  728,   12,   12, 0x05,
     782,  756,   12,   12, 0x05,
     871,  832,   12,   12, 0x05,
     947,  939,   12,   12, 0x05,
     978,   12,   12,   12, 0x05,
     995,  993,   12,   12, 0x05,
    1036,   12,   12,   12, 0x05,
    1057,   12,   12,   12, 0x05,
    1087,  993,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
    1136, 1124,   12,   12, 0x0a,
    1172,   12,   12,   12, 0x0a,
    1228, 1181,   12,   12, 0x0a,
    1292, 1280,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_itemprocess[] = {
    "itemprocess\0\0finished()\0benable\0"
    "enablebutton(bool)\0updateresult()\0"
    "startpreview()\0istatus\0showresult(int)\0"
    "usitem,ucstatus,ustime\0"
    "signalshowitem2endresult(unsigned short,unsigned char,uint)\0"
    "info\0information(QString)\0uiType\0"
    "plotpainter(uint)\0drawTactistics()\0"
    "getSNRBuffer()\0uiflag\0enableinfotimer(uint)\0"
    "getuiinfo()\0strdir,strname,ucimageformat,ucimagesrc\0"
    "execsaveimage(QString,QString,unsigned char,unsigned char)\0"
    "itype\0signaldrawframe(int)\0"
    "u64ID,u8TestItemResult\0"
    "signalwriteItemResult(quint64,quint8)\0"
    "u8Channel\0signalWritePDAF50cm(quint8)\0"
    "bChecked\0signalopenoffline(bool)\0"
    "signalopenofflineb(bool)\0signalPlugInDetect()\0"
    "image1,uiTimeOut\0signalDrawAnotherSingle(QImage,uint)\0"
    "signalBackToNormalMode()\0uiTime\0"
    "signalTotalTestTime(uint)\0iInfo\0"
    "signalMessageBox(int)\0usItem,u8Status,bChannel1\0"
    "signalwriteItemResult(unsigned short,quint8,bool)\0"
    "usItem,ucItemIndex,u8AddInfo,bChannel1\0"
    "signalwriteMasterItemExec(unsigned short,unsigned char,quint8,bool)\0"
    "dataVar\0signalTCPMessageSend(QVariant)\0"
    "sigBurnCount()\0,\0"
    "sigCountToPanel(QStringList,QStringList)\0"
    "sig_test(QqrealList)\0sig_serialnumberbind(QString)\0"
    "sig_messtatusupdate(QString,QString)\0"
    "key,uctimer\0ExecKeyshortcut(char,unsigned char)\0"
    "finish()\0u8Channel,usItem,strOtherInfo,u64ID,u8LoopTime\0"
    "slotItemExec(quint8,quint16,QString,quint64,quint8)\0"
    "currentitem\0slotNativeItemExec(_shoutCutDetail&)\0"
};

void itemprocess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        itemprocess *_t = static_cast<itemprocess *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->enablebutton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->updateresult(); break;
        case 3: _t->startpreview(); break;
        case 4: _t->showresult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->signalshowitem2endresult((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 6: _t->information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->plotpainter((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 8: _t->drawTactistics(); break;
        case 9: _t->getSNRBuffer(); break;
        case 10: _t->enableinfotimer((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 11: _t->getuiinfo(); break;
        case 12: _t->execsaveimage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< unsigned char(*)>(_a[3])),(*reinterpret_cast< unsigned char(*)>(_a[4]))); break;
        case 13: _t->signaldrawframe((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->signalwriteItemResult((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 15: _t->signalWritePDAF50cm((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 16: _t->signalopenoffline((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->signalopenofflineb((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->signalPlugInDetect(); break;
        case 19: _t->signalDrawAnotherSingle((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 20: _t->signalBackToNormalMode(); break;
        case 21: _t->signalTotalTestTime((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 22: _t->signalMessageBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->signalwriteItemResult((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 24: _t->signalwriteMasterItemExec((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 25: _t->signalTCPMessageSend((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 26: _t->sigBurnCount(); break;
        case 27: _t->sigCountToPanel((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 28: _t->sig_test((*reinterpret_cast< QqrealList(*)>(_a[1]))); break;
        case 29: _t->sig_serialnumberbind((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->sig_messtatusupdate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 31: _t->ExecKeyshortcut((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 32: _t->finish(); break;
        case 33: _t->slotItemExec((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< quint64(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 34: _t->slotNativeItemExec((*reinterpret_cast< _shoutCutDetail(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData itemprocess::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject itemprocess::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_itemprocess,
      qt_meta_data_itemprocess, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &itemprocess::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *itemprocess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *itemprocess::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_itemprocess))
        return static_cast<void*>(const_cast< itemprocess*>(this));
    return QObject::qt_metacast(_clname);
}

int itemprocess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void itemprocess::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void itemprocess::enablebutton(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void itemprocess::updateresult()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void itemprocess::startpreview()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void itemprocess::showresult(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void itemprocess::signalshowitem2endresult(unsigned short _t1, unsigned char _t2, unsigned int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void itemprocess::information(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void itemprocess::plotpainter(unsigned int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void itemprocess::drawTactistics()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void itemprocess::getSNRBuffer()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void itemprocess::enableinfotimer(unsigned int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void itemprocess::getuiinfo()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void itemprocess::execsaveimage(QString _t1, QString _t2, unsigned char _t3, unsigned char _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void itemprocess::signaldrawframe(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void itemprocess::signalwriteItemResult(quint64 _t1, quint8 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void itemprocess::signalWritePDAF50cm(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void itemprocess::signalopenoffline(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void itemprocess::signalopenofflineb(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void itemprocess::signalPlugInDetect()
{
    QMetaObject::activate(this, &staticMetaObject, 18, 0);
}

// SIGNAL 19
void itemprocess::signalDrawAnotherSingle(QImage _t1, unsigned int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void itemprocess::signalBackToNormalMode()
{
    QMetaObject::activate(this, &staticMetaObject, 20, 0);
}

// SIGNAL 21
void itemprocess::signalTotalTestTime(unsigned int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void itemprocess::signalMessageBox(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void itemprocess::signalwriteItemResult(unsigned short _t1, quint8 _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void itemprocess::signalwriteMasterItemExec(unsigned short _t1, unsigned char _t2, quint8 _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void itemprocess::signalTCPMessageSend(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void itemprocess::sigBurnCount()
{
    QMetaObject::activate(this, &staticMetaObject, 26, 0);
}

// SIGNAL 27
void itemprocess::sigCountToPanel(QStringList _t1, QStringList _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void itemprocess::sig_test(QqrealList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void itemprocess::sig_serialnumberbind(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void itemprocess::sig_messtatusupdate(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}
QT_END_MOC_NAMESPACE
