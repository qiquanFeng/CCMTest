/****************************************************************************
** Meta object code from reading C++ file 'QHBlemishHC.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QHBlemishHC.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QHBlemishHC.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHBlemishHC[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      24,   12,   12,   12, 0x0a,
      39,   12,   12,   12, 0x0a,
      56,   12,   12,   12, 0x0a,
      72,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QHBlemishHC[] = {
    "QHBlemishHC\0\0slotSave()\0slotGetImage()\0"
    "slotNormalTest()\0slotDebugTest()\0"
    "slotLoopBlemish()\0"
};

void QHBlemishHC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHBlemishHC *_t = static_cast<QHBlemishHC *>(_o);
        switch (_id) {
        case 0: _t->slotSave(); break;
        case 1: _t->slotGetImage(); break;
        case 2: _t->slotNormalTest(); break;
        case 3: _t->slotDebugTest(); break;
        case 4: _t->slotLoopBlemish(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QHBlemishHC::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHBlemishHC::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_QHBlemishHC,
      qt_meta_data_QHBlemishHC, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHBlemishHC::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHBlemishHC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHBlemishHC::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHBlemishHC))
        return static_cast<void*>(const_cast< QHBlemishHC*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int QHBlemishHC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
