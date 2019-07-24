/****************************************************************************
** Meta object code from reading C++ file 'QHMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QHMainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QHMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHthreadShortcut[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      41,   29,   17,   17, 0x05,
      81,   29,   17,   17, 0x05,
     133,  121,   17,   17, 0x05,
     177,  121,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     221,   17,   17,   17, 0x0a,
     230,   17,   17,   17, 0x0a,
     250,  121,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QHthreadShortcut[] = {
    "QHthreadShortcut\0\0finished()\0currentitem\0"
    "signalNativeItemExecC1(_shoutCutDetail)\0"
    "signalNativeItemExecC2(_shoutCutDetail)\0"
    "key,uctimer\0signalExecKeyshortcutC1(char,unsigned char)\0"
    "signalExecKeyshortcutC2(char,unsigned char)\0"
    "finish()\0slotHotPlugInLoop()\0"
    "slotExecKeyshortcut(char,unsigned char)\0"
};

void QHthreadShortcut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHthreadShortcut *_t = static_cast<QHthreadShortcut *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->signalNativeItemExecC1((*reinterpret_cast< const _shoutCutDetail(*)>(_a[1]))); break;
        case 2: _t->signalNativeItemExecC2((*reinterpret_cast< const _shoutCutDetail(*)>(_a[1]))); break;
        case 3: _t->signalExecKeyshortcutC1((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 4: _t->signalExecKeyshortcutC2((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 5: _t->finish(); break;
        case 6: _t->slotHotPlugInLoop(); break;
        case 7: _t->slotExecKeyshortcut((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QHthreadShortcut::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHthreadShortcut::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QHthreadShortcut,
      qt_meta_data_QHthreadShortcut, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHthreadShortcut::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHthreadShortcut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHthreadShortcut::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHthreadShortcut))
        return static_cast<void*>(const_cast< QHthreadShortcut*>(this));
    return QObject::qt_metacast(_clname);
}

int QHthreadShortcut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QHthreadShortcut::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QHthreadShortcut::signalNativeItemExecC1(const _shoutCutDetail & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QHthreadShortcut::signalNativeItemExecC2(const _shoutCutDetail & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QHthreadShortcut::signalExecKeyshortcutC1(char _t1, unsigned char _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QHthreadShortcut::signalExecKeyshortcutC2(char _t1, unsigned char _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
static const uint qt_meta_data_QHMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      28,   23,   13,   13, 0x05,
      61,   49,   13,   13, 0x05,
     105,   49,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     158,  149,   13,   13, 0x0a,
     182,   13,   13,   13, 0x0a,
     198,   13,   13,   13, 0x0a,
     212,   13,   13,   13, 0x0a,
     227,   13,   13,   13, 0x0a,
     243,   13,   13,   13, 0x0a,
     260,   13,   13,   13, 0x0a,
     277,   13,   13,   13, 0x0a,
     289,   13,   13,   13, 0x0a,
     307,   13,   13,   13, 0x0a,
     322,   13,   13,   13, 0x0a,
     343,   13,   13,   13, 0x0a,
     361,   13,   13,   13, 0x0a,
     392,   13,   13,   13, 0x0a,
     416,   13,   13,  408, 0x0a,
     430,   13,   13,  408, 0x0a,
     441,   13,   13,   13, 0x0a,
     468,  460,   13,   13, 0x0a,
     491,  460,   13,   13, 0x0a,
     514,  149,   13,   13, 0x0a,
     536,  149,   13,   13, 0x0a,
     566,   13,   13,   13, 0x0a,
     589,   13,   13,   13, 0x0a,
     606,   13,   13,   13, 0x0a,
     631,   13,   13,   13, 0x0a,
     656,   13,   13,   13, 0x0a,
     675,   13,   13,   13, 0x0a,
     693,  149,   13,   13, 0x0a,
     724,  149,   13,   13, 0x0a,
     756,   13,   13,   13, 0x0a,
     774,   13,   13,   13, 0x0a,
     794,   13,   13,   13, 0x0a,
     816,   13,   13,   13, 0x0a,
     834,   13,   13,   13, 0x0a,
     853,  149,   13,   13, 0x0a,
     880,  149,   13,   13, 0x0a,
     900,   13,   13,   13, 0x0a,
     915,   13,   13,   13, 0x0a,
     936,   13,   13,   13, 0x0a,
     987,  959,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QHMainWindow[] = {
    "QHMainWindow\0\0finish()\0info\0"
    "information(QString)\0key,uctimer\0"
    "signalExecKeyshortcutC1(char,unsigned char)\0"
    "signalExecKeyshortcutC2(char,unsigned char)\0"
    "bChecked\0slotPanelMoveable(bool)\0"
    "registerEvent()\0openfx3slot()\0"
    "closefx3slot()\0closefx3slot2()\0"
    "currentSelfCal()\0voltageSelfCal()\0"
    "OSSelfCal()\0FX3DeviceConfig()\0"
    "UpdateFPGAFW()\0slotShortcutConfig()\0"
    "slotVersionShow()\0slotCompterCompatibilityTest()\0"
    "slotJsvDecode()\0_inline\0slotShowSOP()\0"
    "slotExit()\0slotExecHelpFile()\0checked\0"
    "slotShowChannel1(bool)\0slotShowChannel2(bool)\0"
    "DebugModeSwitch(bool)\0"
    "slotSaveTextInfoToLocal(bool)\0"
    "DisableConfigSetting()\0changePassword()\0"
    "ShowConfigManageDialog()\0"
    "slotConfigContentTable()\0slotChooseOpMode()\0"
    "slotFontSetting()\0showItem2EndResultRegion(bool)\0"
    "showEndResult2ImageRegion(bool)\0"
    "slotSave_LockUI()\0slotResetUILayout()\0"
    "slotImageShowDialog()\0CoorConvertTool()\0"
    "slotRepeatedTest()\0chooseSimpleChinenes(bool)\0"
    "chooseEnglish(bool)\0slotCloseExe()\0"
    "slotPDAF50cmFinish()\0slotSlaveShortcutExe()\0"
    "usItem,ucItemIndex,u8Status\0"
    "slotMasterExeFinish(unsigned short,unsigned char,quint8)\0"
};

void QHMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHMainWindow *_t = static_cast<QHMainWindow *>(_o);
        switch (_id) {
        case 0: _t->finish(); break;
        case 1: _t->information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalExecKeyshortcutC1((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 3: _t->signalExecKeyshortcutC2((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 4: _t->slotPanelMoveable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->registerEvent(); break;
        case 6: _t->openfx3slot(); break;
        case 7: _t->closefx3slot(); break;
        case 8: _t->closefx3slot2(); break;
        case 9: _t->currentSelfCal(); break;
        case 10: _t->voltageSelfCal(); break;
        case 11: _t->OSSelfCal(); break;
        case 12: _t->FX3DeviceConfig(); break;
        case 13: _t->UpdateFPGAFW(); break;
        case 14: _t->slotShortcutConfig(); break;
        case 15: _t->slotVersionShow(); break;
        case 16: _t->slotCompterCompatibilityTest(); break;
        case 17: _t->slotJsvDecode(); break;
        case 18: _t->slotShowSOP(); break;
        case 19: _t->slotExit(); break;
        case 20: _t->slotExecHelpFile(); break;
        case 21: _t->slotShowChannel1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->slotShowChannel2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->DebugModeSwitch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->slotSaveTextInfoToLocal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->DisableConfigSetting(); break;
        case 26: _t->changePassword(); break;
        case 27: _t->ShowConfigManageDialog(); break;
        case 28: _t->slotConfigContentTable(); break;
        case 29: _t->slotChooseOpMode(); break;
        case 30: _t->slotFontSetting(); break;
        case 31: _t->showItem2EndResultRegion((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->showEndResult2ImageRegion((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->slotSave_LockUI(); break;
        case 34: _t->slotResetUILayout(); break;
        case 35: _t->slotImageShowDialog(); break;
        case 36: _t->CoorConvertTool(); break;
        case 37: _t->slotRepeatedTest(); break;
        case 38: _t->chooseSimpleChinenes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->chooseEnglish((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->slotCloseExe(); break;
        case 41: _t->slotPDAF50cmFinish(); break;
        case 42: _t->slotSlaveShortcutExe(); break;
        case 43: _t->slotMasterExeFinish((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QHMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QHMainWindow,
      qt_meta_data_QHMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHMainWindow))
        return static_cast<void*>(const_cast< QHMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QHMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void QHMainWindow::finish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QHMainWindow::information(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QHMainWindow::signalExecKeyshortcutC1(char _t1, unsigned char _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QHMainWindow::signalExecKeyshortcutC2(char _t1, unsigned char _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
