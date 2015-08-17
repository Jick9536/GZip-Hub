/**
@file crc32.cpp*/

#include <iostream>
#include <cstring>
#include "crc32.h"

using namespace std;

CRC32::CRC32()
{
	unsigned long c;
	int n;
	
	for (n=0; n < 256; n++)
	{
		c=(unsigned long) n;
		
		for( int k=0; k<8; k++)
		{
			if (c & 1)
				c=0xedb88320L ^ (c >> 1);
			else
				c=c >> 1;
		}
		tabla[n]=c;
	}
	crc32=0xFFFFFFFF;
}

CRC32::~CRC32(){}

CRC32& CRC32::operator = (const CRC32 &crc)
{
	crc32=crc.crc32;
	for (int i=0; i<256; i++)
	{
		tabla[i]=crc.tabla[i];
	}
	return *this;
}

void CRC32::CRC32_AddByte(unsigned char byte)
{
	crc32=(crc32 >> 8) ^ tabla[(crc32^byte) & 0xFF];
}
	
unsigned long CRC32::CRC32_get ()const
{	
	return crc32 ^ 0xFFFFFFFF;
}

