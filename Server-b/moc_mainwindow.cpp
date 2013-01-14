/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jan 10 14:21:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Server/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      39,   12,   11,   11, 0x05,
      80,   11,   11,   11, 0x05,
     100,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     114,   11,   11,   11, 0x08,
     137,   11,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     268,   11,   11,   11, 0x08,
     297,   11,   11,   11, 0x08,
     323,   11,   11,   11, 0x08,
     349,   11,   11,   11, 0x08,
     375,   11,   11,   11, 0x08,
     407,  402,   11,   11, 0x0a,
     447,  437,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0external,internal,serverIP\0"
    "signal_startServer(int,int,QHostAddress)\0"
    "signal_stopServer()\0signal_quit()\0"
    "on_buttonRun_clicked()\0on_buttonStop_clicked()\0"
    "on_buttonRestart_clicked()\0"
    "on_actionRun_triggered()\0"
    "on_actionStop_triggered()\0"
    "on_actionRestart_triggered()\0"
    "on_actionSaveCfg_triggered()\0"
    "on_actionLoad_triggered()\0"
    "on_actionQuit_triggered()\0"
    "on_actionHelp_triggered()\0"
    "on_actionAbout_triggered()\0disp\0"
    "slot_serverMessenger(QString)\0isStarted\0"
    "slot_serverStarted(bool)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->signal_startServer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QHostAddress(*)>(_a[3]))); break;
        case 1: _t->signal_stopServer(); break;
        case 2: _t->signal_quit(); break;
        case 3: _t->on_buttonRun_clicked(); break;
        case 4: _t->on_buttonStop_clicked(); break;
        case 5: _t->on_buttonRestart_clicked(); break;
        case 6: _t->on_actionRun_triggered(); break;
        case 7: _t->on_actionStop_triggered(); break;
        case 8: _t->on_actionRestart_triggered(); break;
        case 9: _t->on_actionSaveCfg_triggered(); break;
        case 10: _t->on_actionLoad_triggered(); break;
        case 11: _t->on_actionQuit_triggered(); break;
        case 12: _t->on_actionHelp_triggered(); break;
        case 13: _t->on_actionAbout_triggered(); break;
        case 14: _t->slot_serverMessenger((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->slot_serverStarted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_startServer(int _t1, int _t2, QHostAddress _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signal_stopServer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::signal_quit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
