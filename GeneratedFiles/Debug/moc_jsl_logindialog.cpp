/****************************************************************************
** Meta object code from reading C++ file 'jsl_logindialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../jsl_logindialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jsl_logindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_jsl_loginDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   16,   16,   16, 0x0a,
      47,   16,   16,   16, 0x0a,
      70,   16,   16,   61, 0x0a,
      88,   16,   16,   61, 0x0a,
     106,   16,   16,   61, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_jsl_loginDialog[] = {
    "jsl_loginDialog\0\0sig_reLotSN()\0"
    "slot_onCommit()\0slot_onQuit()\0__inline\0"
    "slot_changePos1()\0slot_changePos2()\0"
    "slot_changePos3()\0"
};

void jsl_loginDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        jsl_loginDialog *_t = static_cast<jsl_loginDialog *>(_o);
        switch (_id) {
        case 0: _t->sig_reLotSN(); break;
        case 1: _t->slot_onCommit(); break;
        case 2: _t->slot_onQuit(); break;
        case 3: _t->slot_changePos1(); break;
        case 4: _t->slot_changePos2(); break;
        case 5: _t->slot_changePos3(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData jsl_loginDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject jsl_loginDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_jsl_loginDialog,
      qt_meta_data_jsl_loginDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &jsl_loginDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *jsl_loginDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *jsl_loginDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_jsl_loginDialog))
        return static_cast<void*>(const_cast< jsl_loginDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int jsl_loginDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void jsl_loginDialog::sig_reLotSN()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_jsl_bindSerialNumber[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_jsl_bindSerialNumber[] = {
    "jsl_bindSerialNumber\0\0info\0"
    "information(QString)\0slotReturn()\0"
};

void jsl_bindSerialNumber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        jsl_bindSerialNumber *_t = static_cast<jsl_bindSerialNumber *>(_o);
        switch (_id) {
        case 0: _t->information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotReturn(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData jsl_bindSerialNumber::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject jsl_bindSerialNumber::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_jsl_bindSerialNumber,
      qt_meta_data_jsl_bindSerialNumber, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &jsl_bindSerialNumber::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *jsl_bindSerialNumber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *jsl_bindSerialNumber::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_jsl_bindSerialNumber))
        return static_cast<void*>(const_cast< jsl_bindSerialNumber*>(this));
    return QDialog::qt_metacast(_clname);
}

int jsl_bindSerialNumber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void jsl_bindSerialNumber::information(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_jsl_debugBurn[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_jsl_debugBurn[] = {
    "jsl_debugBurn\0\0slot_onCommit()\0"
};

void jsl_debugBurn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        jsl_debugBurn *_t = static_cast<jsl_debugBurn *>(_o);
        switch (_id) {
        case 0: _t->slot_onCommit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData jsl_debugBurn::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject jsl_debugBurn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_jsl_debugBurn,
      qt_meta_data_jsl_debugBurn, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &jsl_debugBurn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *jsl_debugBurn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *jsl_debugBurn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_jsl_debugBurn))
        return static_cast<void*>(const_cast< jsl_debugBurn*>(this));
    return QDialog::qt_metacast(_clname);
}

int jsl_debugBurn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
