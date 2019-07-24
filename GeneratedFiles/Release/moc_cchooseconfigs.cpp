/****************************************************************************
** Meta object code from reading C++ file 'cchooseconfigs.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cchooseconfigs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cchooseconfigs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cchooseconfigs[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      32,   15,   15,   15, 0x08,
      53,   45,   15,   15, 0x08,
      71,   45,   15,   15, 0x08,
      90,   45,   15,   15, 0x08,
     112,   45,   15,   15, 0x08,
     129,   45,   15,   15, 0x08,
     149,   45,   15,   15, 0x08,
     169,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_cchooseconfigs[] = {
    "cchooseconfigs\0\0okbuttonclick()\0"
    "slotCancel()\0checked\0allSelected(bool)\0"
    "sonySelected(bool)\0sansungSelected(bool)\0"
    "ovSelected(bool)\0hynixSelected(bool)\0"
    "otherSelected(bool)\0textSelected(QString)\0"
};

void cchooseconfigs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        cchooseconfigs *_t = static_cast<cchooseconfigs *>(_o);
        switch (_id) {
        case 0: _t->okbuttonclick(); break;
        case 1: _t->slotCancel(); break;
        case 2: _t->allSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->sonySelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->sansungSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->ovSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->hynixSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->otherSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->textSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData cchooseconfigs::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject cchooseconfigs::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_cchooseconfigs,
      qt_meta_data_cchooseconfigs, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cchooseconfigs::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cchooseconfigs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cchooseconfigs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cchooseconfigs))
        return static_cast<void*>(const_cast< cchooseconfigs*>(this));
    return QDialog::qt_metacast(_clname);
}

int cchooseconfigs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
