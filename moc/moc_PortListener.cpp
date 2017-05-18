/****************************************************************************
** Meta object code from reading C++ file 'PortListener.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PortListener.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PortListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PortListener[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   14,   13,   13, 0x05,
      70,   52,   13,   13, 0x05,
     106,   98,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,   13,   13,   13, 0x0a,
     144,  138,   13,   13, 0x0a,
     166,   13,   13,   13, 0x0a,
     187,  180,   13,   13, 0x0a,
     203,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PortListener[] = {
    "PortListener\0\0threshold\0"
    "reportThreshold(Threshold*)\0"
    "volt1,volt2,linkq\0reportVolts(char,char,char)\0"
    ",length\0reportData(char*,int)\0receive()\0"
    "bytes\0reportWritten(qint64)\0reportClose()\0"
    "status\0reportDsr(bool)\0timeToReport()\0"
};

void PortListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PortListener *_t = static_cast<PortListener *>(_o);
        switch (_id) {
        case 0: _t->reportThreshold((*reinterpret_cast< Threshold*(*)>(_a[1]))); break;
        case 1: _t->reportVolts((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2])),(*reinterpret_cast< char(*)>(_a[3]))); break;
        case 2: _t->reportData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->receive(); break;
        case 4: _t->reportWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->reportClose(); break;
        case 6: _t->reportDsr((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->timeToReport(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PortListener::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PortListener::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PortListener,
      qt_meta_data_PortListener, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PortListener::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PortListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PortListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PortListener))
        return static_cast<void*>(const_cast< PortListener*>(this));
    return QObject::qt_metacast(_clname);
}

int PortListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PortListener::reportThreshold(Threshold * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PortListener::reportVolts(char _t1, char _t2, char _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PortListener::reportData(char * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
