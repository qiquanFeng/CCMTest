/****************************************************************************
** Meta object code from reading C++ file 'QHManualModeA.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QHManualModeA.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QHManualModeA.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHManualModeA[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      28,   14,   14,   14, 0x0a,
      46,   14,   14,   14, 0x0a,
      67,   14,   14,   14, 0x0a,
      93,   14,   14,   14, 0x0a,
     125,  118,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QHManualModeA[] = {
    "QHManualModeA\0\0saveConfig()\0"
    "setExposreValue()\0updateExposruetime()\0"
    "startUpdateExposruetime()\0"
    "stopUpdateExposruetime()\0iIndex\0"
    "slotSceneChanged(int)\0"
};

void QHManualModeA::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHManualModeA *_t = static_cast<QHManualModeA *>(_o);
        switch (_id) {
        case 0: _t->saveConfig(); break;
        case 1: _t->setExposreValue(); break;
        case 2: _t->updateExposruetime(); break;
        case 3: _t->startUpdateExposruetime(); break;
        case 4: _t->stopUpdateExposruetime(); break;
        case 5: _t->slotSceneChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QHManualModeA::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHManualModeA::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QHManualModeA,
      qt_meta_data_QHManualModeA, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHManualModeA::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHManualModeA::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHManualModeA::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHManualModeA))
        return static_cast<void*>(const_cast< QHManualModeA*>(this));
    return QDialog::qt_metacast(_clname);
}

int QHManualModeA::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
