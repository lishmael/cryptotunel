/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created: Thu Jan 10 14:50:28 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Server/server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Thread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Thread[] = {
    "Thread\0"
};

void Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Thread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Thread,
      qt_meta_data_Thread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Thread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Thread))
        return static_cast<void*>(const_cast< Thread*>(this));
    return QThread::qt_metacast(_clname);
}

int Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_Server[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      41,    7,    7,    7, 0x05,
      74,   65,    7,    7, 0x05,
     109,   99,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     146,    7,    7,    7, 0x08,
     167,    7,    7,    7, 0x08,
     184,    7,    7,    7, 0x08,
     204,    7,    7,    7, 0x08,
     230,    7,    7,    7, 0x08,
     252,    7,    7,    7, 0x08,
     303,  271,    7,    7, 0x0a,
     342,    7,    7,    7, 0x0a,
     360,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Server[] = {
    "Server\0\0signal_startServerError(QString)\0"
    "signal_display(QString)\0isOnline\0"
    "signal_serverStaus(bool)\0mesSender\0"
    "singal_messageDataError(QTcpSocket*)\0"
    "slot_newConnection()\0slot_readCient()\0"
    "slot_readDatabase()\0slot_clientDisconnected()\0"
    "slot_dbDisconnected()\0slot_socketError()\0"
    "externalPort,localPort,serverIP\0"
    "slot_startServer(int,int,QHostAddress)\0"
    "slot_stopServer()\0slot_needResendData()\0"
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Server *_t = static_cast<Server *>(_o);
        switch (_id) {
        case 0: _t->signal_startServerError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signal_display((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signal_serverStaus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->singal_messageDataError((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 4: _t->slot_newConnection(); break;
        case 5: _t->slot_readCient(); break;
        case 6: _t->slot_readDatabase(); break;
        case 7: _t->slot_clientDisconnected(); break;
        case 8: _t->slot_dbDisconnected(); break;
        case 9: _t->slot_socketError(); break;
        case 10: _t->slot_startServer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QHostAddress(*)>(_a[3]))); break;
        case 11: _t->slot_stopServer(); break;
        case 12: _t->slot_needResendData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Server::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Server::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Server,
      qt_meta_data_Server, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Server::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Server))
        return static_cast<void*>(const_cast< Server*>(this));
    return QWidget::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Server::signal_startServerError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::signal_display(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::signal_serverStaus(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Server::singal_messageDataError(QTcpSocket * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
