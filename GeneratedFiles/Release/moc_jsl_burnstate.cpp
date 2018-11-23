/****************************************************************************
** Meta object code from reading C++ file 'jsl_burnstate.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../jsl_burnstate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jsl_burnstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_jsl_burnState[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      39,   31,   14,   14, 0x0a,
      66,   64,   14,   14, 0x0a,
     104,   14,   14,   14, 0x0a,
     126,   14,   14,   14, 0x0a,
     161,   14,   14,   14, 0x0a,
     186,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_jsl_burnState[] = {
    "jsl_burnState\0\0slotBurnCount()\0row,col\0"
    "slot_UpdatePlot(int,int)\0,\0"
    "slot_ToPanel(QStringList,QStringList)\0"
    "slot_test(QqrealList)\0"
    "slot_ShowNgData(QTableWidgetItem*)\0"
    "slot_ShowNgTableSelect()\0slot_BurnDataExport()\0"
};

void jsl_burnState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        jsl_burnState *_t = static_cast<jsl_burnState *>(_o);
        switch (_id) {
        case 0: _t->slotBurnCount(); break;
        case 1: _t->slot_UpdatePlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->slot_ToPanel((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 3: _t->slot_test((*reinterpret_cast< QqrealList(*)>(_a[1]))); break;
        case 4: _t->slot_ShowNgData((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->slot_ShowNgTableSelect(); break;
        case 6: _t->slot_BurnDataExport(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData jsl_burnState::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject jsl_burnState::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_jsl_burnState,
      qt_meta_data_jsl_burnState, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &jsl_burnState::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *jsl_burnState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *jsl_burnState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_jsl_burnState))
        return static_cast<void*>(const_cast< jsl_burnState*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int jsl_burnState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
