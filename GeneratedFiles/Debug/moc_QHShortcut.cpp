/****************************************************************************
** Meta object code from reading C++ file 'QHShortcut.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QHShortcut.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QHShortcut.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHShortcut[] = {

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
      17,   12,   11,   11, 0x0a,
      45,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
      91,   11,   11,   11, 0x0a,
     114,   11,   11,   11, 0x0a,
     135,  129,   11,   11, 0x0a,
     159,  153,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QHShortcut[] = {
    "QHShortcut\0\0text\0slotscitemchangego(QString)\0"
    "sloteditShotcutExeC1()\0sloteditShotcutExeC2()\0"
    "slotinsertShotcutExe()\0scsavebutton()\0"
    "state\0slotKeyOnOff(int)\0index\0"
    "slotsceditchange(int)\0"
};

void QHShortcut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHShortcut *_t = static_cast<QHShortcut *>(_o);
        switch (_id) {
        case 0: _t->slotscitemchangego((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sloteditShotcutExeC1(); break;
        case 2: _t->sloteditShotcutExeC2(); break;
        case 3: _t->slotinsertShotcutExe(); break;
        case 4: _t->scsavebutton(); break;
        case 5: _t->slotKeyOnOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slotsceditchange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QHShortcut::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHShortcut::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QHShortcut,
      qt_meta_data_QHShortcut, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHShortcut::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHShortcut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHShortcut::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHShortcut))
        return static_cast<void*>(const_cast< QHShortcut*>(this));
    return QDialog::qt_metacast(_clname);
}

int QHShortcut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
