/****************************************************************************
** Meta object code from reading C++ file 'frskyupdate.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../frskyupdate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frskyupdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_frskyUpdate[] = {

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
      13,   12,   12,   12, 0x08,
      58,   12,   12,   12, 0x08,
      90,   12,   12,   12, 0x08,
     120,   12,   12,   12, 0x08,
     146,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_frskyUpdate[] = {
    "frskyUpdate\0\0on_comboBoxPort_currentIndexChanged(QString)\0"
    "on_pushButtonDownload_clicked()\0"
    "on_pushButtonCancel_clicked()\0"
    "on_pushButtonOK_clicked()\0receive()\0"
};

void frskyUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        frskyUpdate *_t = static_cast<frskyUpdate *>(_o);
        switch (_id) {
        case 0: _t->on_comboBoxPort_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonDownload_clicked(); break;
        case 2: _t->on_pushButtonCancel_clicked(); break;
        case 3: _t->on_pushButtonOK_clicked(); break;
        case 4: _t->receive(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData frskyUpdate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject frskyUpdate::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frskyUpdate,
      qt_meta_data_frskyUpdate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frskyUpdate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frskyUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frskyUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frskyUpdate))
        return static_cast<void*>(const_cast< frskyUpdate*>(this));
    return QDialog::qt_metacast(_clname);
}

int frskyUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
