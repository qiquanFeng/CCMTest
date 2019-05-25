/****************************************************************************
** Meta object code from reading C++ file 'qmanualtool.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmanualtool.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmanualtool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_thread1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_thread1[] = {
    "thread1\0"
};

void thread1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData thread1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject thread1::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_thread1,
      qt_meta_data_thread1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &thread1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *thread1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *thread1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_thread1))
        return static_cast<void*>(const_cast< thread1*>(this));
    return QThread::qt_metacast(_clname);
}

int thread1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_qmanualtool[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      58,   13,   12,   12, 0x05,
     105,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     122,   12,   12,   12, 0x0a,
     134,   12,   12,   12, 0x0a,
     152,   12,   12,   12, 0x0a,
     170,   12,   12,   12, 0x0a,
     191,   12,   12,   12, 0x0a,
     217,   12,   12,   12, 0x0a,
     242,   12,   12,   12, 0x0a,
     258,   12,   12,   12, 0x0a,
     275,   12,   12,   12, 0x0a,
     297,   12,   12,   12, 0x0a,
     318,   12,   12,   12, 0x0a,
     339,   12,   12,   12, 0x0a,
     358,   12,   12,   12, 0x0a,
     382,   12,   12,   12, 0x0a,
     405,   12,   12,   12, 0x0a,
     421,   12,   12,   12, 0x0a,
     470,  436,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qmanualtool[] = {
    "qmanualtool\0\0uiLeft,uiRight,uiTop,uiBottom,uiTimer,uiFlag\0"
    "startLuxMonitor(uint,uint,uint,uint,uint,uint)\0"
    "stopLuxMonitor()\0MotorTest()\0"
    "ClearMotorCount()\0setExposreValue()\0"
    "updateExposruetime()\0startUpdateExposruetime()\0"
    "stopUpdateExposruetime()\0setMotorValue()\0"
    "updateMotorPos()\0startUpdateMotorPos()\0"
    "stopUpdateMotorPos()\0setGlobalGainValue()\0"
    "updateGlobalGain()\0startUpdateGlobalGain()\0"
    "stopUpdateGlobalGain()\0startRealtime()\0"
    "StopRealtime()\0flY,flR,flG,flB,flR2G,flB2G,flMTF\0"
    "luxMonitorResult(float,float,float,float,float,float,float)\0"
};

void qmanualtool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qmanualtool *_t = static_cast<qmanualtool *>(_o);
        switch (_id) {
        case 0: _t->startLuxMonitor((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6]))); break;
        case 1: _t->stopLuxMonitor(); break;
        case 2: _t->MotorTest(); break;
        case 3: _t->ClearMotorCount(); break;
        case 4: _t->setExposreValue(); break;
        case 5: _t->updateExposruetime(); break;
        case 6: _t->startUpdateExposruetime(); break;
        case 7: _t->stopUpdateExposruetime(); break;
        case 8: _t->setMotorValue(); break;
        case 9: _t->updateMotorPos(); break;
        case 10: _t->startUpdateMotorPos(); break;
        case 11: _t->stopUpdateMotorPos(); break;
        case 12: _t->setGlobalGainValue(); break;
        case 13: _t->updateGlobalGain(); break;
        case 14: _t->startUpdateGlobalGain(); break;
        case 15: _t->stopUpdateGlobalGain(); break;
        case 16: _t->startRealtime(); break;
        case 17: _t->StopRealtime(); break;
        case 18: _t->luxMonitorResult((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qmanualtool::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qmanualtool::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_qmanualtool,
      qt_meta_data_qmanualtool, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qmanualtool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qmanualtool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qmanualtool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qmanualtool))
        return static_cast<void*>(const_cast< qmanualtool*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int qmanualtool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void qmanualtool::startLuxMonitor(unsigned int _t1, unsigned int _t2, unsigned int _t3, unsigned int _t4, unsigned int _t5, unsigned int _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qmanualtool::stopLuxMonitor()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
