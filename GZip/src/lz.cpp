/**
@file lz.cpp*/

#include "lz.h"

LZ::LZ()
{
	i=0;
}

LZ::LZ (const LZ &lz)
{
	cad=lz.cad;
	i=lz.i;
}

LZ::~LZ()
{
	
}

unsigned long LZ::Crc32 ()
{
	for(int i=0; i<cad.Size(); ++i)
	{
		crc.CRC32_AddByte(cad.Get(i));
	}
	return crc.CRC32_get();
}

void LZ::Read(istream &is)
{
	cad.Leer(is);
}

void LZ::Next(unsigned int &longitud,unsigned int &distancia)
{
	int cont;
	bool stop=false;
	
	if(i==cad.Size())
	{
		longitud=256;
	}
	else
	{
		for (int j=i-1; j>=0 && stop==false && (i-j)<=32768; --j) //Desde aqui se controla la distancia
		{
			cont=0;
			if (cad.Get(i)==cad.Get(j))
			{
				int k=i;
				int l=j;
				
				while (k<cad.Size() && cad.Get(k)==cad.Get(l) && cont<258) //Desde aqui se controla longitud max
				{
					cont++;
					k++;
					l++;
				}
				
				if(cont>=3 && cont<=258)
				{
					longitud=cont+256;
					distancia=i-j;
					stop=true;
					i=i+cont;
				}
			}
		}
	}
	
	if(stop==false && i<cad.Size())
	{
		longitud=(unsigned char) cad.Get(i);
		distancia=0;
		++i;
	}
}


int LZ::SizeCad()const
{
	return cad.Size ();
}
