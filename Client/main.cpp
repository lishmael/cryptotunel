#include <QCoreApplication>


#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	Client *client = new Client();
    QObject::connect(client, SIGNAL(signal_done()), &a, SLOT(quit()));

	return a.exec();
}
