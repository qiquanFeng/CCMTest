/****************************************************************************
** Meta object code from reading C++ file 'savedebuginfo.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../savedebuginfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'savedebuginfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_savedebuginfo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   15,   14,   14, 0x08,
      38,   15,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_savedebuginfo[] = {
    "savedebuginfo\0\0bchecked\0finddir(bool)\0"
    "savebutton(bool)\0"
};

void savedebuginfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        savedebuginfo *_t = static_cast<savedebuginfo *>(_o);
        switch (_id) {
        case 0: _t->finddir((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->savebutton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData savedebuginfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject savedebuginfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_savedebuginfo,
      qt_meta_data_savedebuginfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &savedebuginfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *savedebuginfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *savedebuginfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_savedebuginfo))
        return static_cast<void*>(const_cast< savedebuginfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int savedebuginfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
