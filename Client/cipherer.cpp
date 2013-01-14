#include "cipherer.h"

#define SERVER

int The_Crypt::to_the_crypt(QByteArray &mes)
{
	size_t b = sizeof(long);
	char *data = mes.data();
    char *enc_data = new char[mes.count() + 8];
    memset(enc_data, 0, mes.count()+8);
    int cou = 0;
	long *enc = new long[2];
    long Keys[] = {1340881873, -22314421, -33987271, 7754793};
    char *tmp= new char[b*2];
    int k = mes.count();
    for (int n = k / (b*2); n >= 0; --n)
    {
		memset(enc, 0, 2*sizeof(long));
		if (data + b*2 > mes.data() + mes.count())
		{
			int z = b*2;
			while (data + --z > mes.data() + mes.count());
            memcpy(enc, data, z);
		}
		else
		{
			memcpy(enc, data, b*2);
		}
		The_Crypt::eliptic_encryptor(enc, 32, Keys);
        memset(tmp, 0, b*2);
		memcpy(tmp, enc, b*2);

        memcpy(enc_data + cou, tmp, b*2);
        cou += b*2;
		data += b*2;
	}
	mes.clear();
    mes = mes.append(enc_data, cou);
	return 0;

}
int The_Crypt::from_the_crypt(QByteArray &mes)
{
	size_t b = sizeof(long);
    char *dec_data = new char[mes.count() + 8];
    memset(dec_data, 0, mes.count() + 8);
    int cou = 0;
	char *data = mes.data();
	long *dec = new long[2];
    long Keys[] = {1340881873, -22314421, -33987271, 7754793};
    for (int n = mes.count() / (b*2); n >= 0; --n)
	{
		memset(dec, 0, 2*sizeof(long));
		if (data + b*2 > mes.data() + mes.count())
		{
			int z = b*2;
			while (data + --z > mes.data() + mes.count());
            if (z <= 0) break;
            memcpy(dec, data, z);
		}
		else
		{
			memcpy(dec, data, b*2);
		}
		The_Crypt::eliptic_encryptor(dec, -32, Keys);
        memcpy(dec_data + cou, dec, b*2);
        cou += b*2;
		data += b*2;

	}

	mes.clear();
	mes = dec_data;

	return 0;
}

bool The_Crypt::eliptic_encryptor(long* v, long n, long *k)
{
    if (n > 0)
    {
         The_Crypt::encrypt(v, k);
    }
    else
    {
         The_Crypt::decrypt(v, k);
    }
    return true;
}
void  The_Crypt::encrypt (long* v, long* k)
{
    long v0=v[0], v1=v[1], sum=0, i;           /* set up */
    long delta=0x9e3779b9;                     /* a key schedule constant */
    long k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    for (i=0; i < 32; i++) {                       /* basic cycle start */
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
}
void  The_Crypt::decrypt (long* v, long* k)
{
    long v0=v[0], v1=v[1], sum=0xC6EF3720, i;       /* set up */
    long delta=0x9e3779b9;                          /* a key schedule constant */
    long k0=k[0], k1=k[1], k2=k[2], k3=k[3];        /* cache key */
    for (i=0; i<32; i++) {                              /* basic cycle start */
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }                                                   /* end cycle */
    v[0]=v0; v[1]=v1;
}
