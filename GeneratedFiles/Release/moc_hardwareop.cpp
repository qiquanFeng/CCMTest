/****************************************************************************
** Meta object code from reading C++ file 'hardwareop.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hardwareop.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hardwareop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_hardwareop[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      27,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      52,   11,   11,   11, 0x0a,
      63,   11,   11,   11, 0x0a,
      74,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     106,   11,   11,   11, 0x0a,
     118,   11,   11,   11, 0x0a,
     128,   11,   11,   11, 0x0a,
     138,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     165,   11,   11,   11, 0x0a,
     186,  180,   11,   11, 0x0a,
     202,  180,   11,   11, 0x0a,
     218,  180,   11,   11, 0x0a,
     234,  180,   11,   11, 0x0a,
     250,   11,   11,   11, 0x0a,
     267,   11,   11,   11, 0x0a,
     281,   11,   11,   11, 0x0a,
     291,   11,   11,   11, 0x0a,
     301,   11,   11,   11, 0x0a,
     312,   11,   11,   11, 0x0a,
     322,   11,   11,   11, 0x0a,
     338,   11,   11,   11, 0x0a,
     355,   11,   11,   11, 0x0a,
     375,   11,   11,   11, 0x0a,
     391,   11,   11,   11, 0x0a,
     415,  409,   11,   11, 0x0a,
     445,  440,   11,   11, 0x0a,
     478,  409,   11,   11, 0x0a,
     506,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_hardwareop[] = {
    "hardwareop\0\0freshVoltage()\0setVoltage()\0"
    "resethigh()\0resetlow()\0pwndhigh()\0"
    "pwndlow()\0freshmclk()\0setmclk()\0"
    "freshlane()\0setlane()\0readi2c()\0"
    "writei2c()\0batchwritei2c()\0batchreadi2c()\0"
    "state\0changgpio0(int)\0changgpio1(int)\0"
    "changgpio2(int)\0changgpio3(int)\0"
    "readGPIOStatus()\0searchSlave()\0openBIN()\0"
    "saveBIN()\0writeBIN()\0readBIN()\0"
    "binDataCreate()\0binDataCreate0()\0"
    "binDataCreate0xFF()\0slotBatchTest()\0"
    "slotMeasureVolt()\0index\0"
    "changeMIPILaneCombo(int)\0text\0"
    "slotChangeCommuProtocal(QString)\0"
    "slotBatchIICModeChange(int)\0"
    "slotBatchFormat()\0"
};

void hardwareop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        hardwareop *_t = static_cast<hardwareop *>(_o);
        switch (_id) {
        case 0: _t->freshVoltage(); break;
        case 1: _t->setVoltage(); break;
        case 2: _t->resethigh(); break;
        case 3: _t->resetlow(); break;
        case 4: _t->pwndhigh(); break;
        case 5: _t->pwndlow(); break;
        case 6: _t->freshmclk(); break;
        case 7: _t->setmclk(); break;
        case 8: _t->freshlane(); break;
        case 9: _t->setlane(); break;
        case 10: _t->readi2c(); break;
        case 11: _t->writei2c(); break;
        case 12: _t->batchwritei2c(); break;
        case 13: _t->batchreadi2c(); break;
        case 14: _t->changgpio0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->changgpio1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->changgpio2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->changgpio3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->readGPIOStatus(); break;
        case 19: _t->searchSlave(); break;
        case 20: _t->openBIN(); break;
        case 21: _t->saveBIN(); break;
        case 22: _t->writeBIN(); break;
        case 23: _t->readBIN(); break;
        case 24: _t->binDataCreate(); break;
        case 25: _t->binDataCreate0(); break;
        case 26: _t->binDataCreate0xFF(); break;
        case 27: _t->slotBatchTest(); break;
        case 28: _t->slotMeasureVolt(); break;
        case 29: _t->changeMIPILaneCombo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->slotChangeCommuProtocal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->slotBatchIICModeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->slotBatchFormat(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData hardwareop::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject hardwareop::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_hardwareop,
      qt_meta_data_hardwareop, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &hardwareop::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *hardwareop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *hardwareop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_hardwareop))
        return static_cast<void*>(const_cast< hardwareop*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int hardwareop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
