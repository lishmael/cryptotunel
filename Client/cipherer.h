#ifndef CIPHERER_H
#define CIPHERER_H

#include "debugmode.h"

#include "stdafx.h"
#include <QByteArray>
#include <QString>
#include <stdint.h>

namespace The_Crypt
	{
		int to_the_crypt(QByteArray &mes);
		int from_the_crypt(QByteArray &message);
        bool eliptic_encryptor(long* v, long n, long *k);
        void encrypt(long *v, long *k);
        void decrypt(long *v, long *k);
	}
#endif // CIPHERER_H
