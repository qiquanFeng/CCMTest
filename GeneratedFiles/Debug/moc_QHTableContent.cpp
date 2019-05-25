/****************************************************************************
** Meta object code from reading C++ file 'QHTableContent.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QHTableContent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QHTableContent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHTableContent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   16,   15,   15, 0x0a,
      58,   48,   15,   15, 0x0a,
      91,   15,   15,   15, 0x0a,
     104,   15,   15,   15, 0x0a,
     117,   15,   15,   15, 0x0a,
     137,   15,   15,   15, 0x0a,
     153,   15,   15,   15, 0x0a,
     172,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QHTableContent[] = {
    "QHTableContent\0\0pos\0customMenuRequested(QPoint)\0"
    "tablename\0changeCustomTableSelect(QString)\0"
    "deleteRows()\0insertRows()\0copycustomrecords()\0"
    "parserrecords()\0savecustomchange()\0"
    "updatecustomdata()\0"
};

void QHTableContent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHTableContent *_t = static_cast<QHTableContent *>(_o);
        switch (_id) {
        case 0: _t->customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->changeCustomTableSelect((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->deleteRows(); break;
        case 3: _t->insertRows(); break;
        case 4: _t->copycustomrecords(); break;
        case 5: _t->parserrecords(); break;
        case 6: _t->savecustomchange(); break;
        case 7: _t->updatecustomdata(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QHTableContent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHTableContent::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QHTableContent,
      qt_meta_data_QHTableContent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHTableContent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHTableContent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHTableContent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHTableContent))
        return static_cast<void*>(const_cast< QHTableContent*>(this));
    return QDialog::qt_metacast(_clname);
}

int QHTableContent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
