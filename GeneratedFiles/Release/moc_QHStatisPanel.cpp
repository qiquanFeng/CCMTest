/****************************************************************************
** Meta object code from reading C++ file 'QHStatisPanel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QHStatisPanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QHStatisPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHStatisPanel[] = {

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
      15,   14,   14,   14, 0x0a,
      37,   14,   14,   14, 0x0a,
      61,   14,   14,   14, 0x0a,
      89,   14,   14,   14, 0x0a,
     114,   14,   14,   14, 0x0a,
     143,   14,   14,   14, 0x0a,
     168,   14,   14,   14, 0x0a,
     187,   14,   14,   14, 0x0a,
     211,  207,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QHStatisPanel[] = {
    "QHStatisPanel\0\0drawStatisticsImage()\0"
    "showNowTactisticsData()\0"
    "showHistoryTactisticsData()\0"
    "clearNowTactisticsData()\0"
    "clearHistoryTactisticsData()\0"
    "clearALLTactisticsData()\0enableTactistics()\0"
    "disableTactistics()\0pos\0"
    "tactistics_customMenuRequested(QPoint)\0"
};

void QHStatisPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QHStatisPanel *_t = static_cast<QHStatisPanel *>(_o);
        switch (_id) {
        case 0: _t->drawStatisticsImage(); break;
        case 1: _t->showNowTactisticsData(); break;
        case 2: _t->showHistoryTactisticsData(); break;
        case 3: _t->clearNowTactisticsData(); break;
        case 4: _t->clearHistoryTactisticsData(); break;
        case 5: _t->clearALLTactisticsData(); break;
        case 6: _t->enableTactistics(); break;
        case 7: _t->disableTactistics(); break;
        case 8: _t->tactistics_customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QHStatisPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QHStatisPanel::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_QHStatisPanel,
      qt_meta_data_QHStatisPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHStatisPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHStatisPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHStatisPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHStatisPanel))
        return static_cast<void*>(const_cast< QHStatisPanel*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int QHStatisPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
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
