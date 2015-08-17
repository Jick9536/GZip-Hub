/**
@file test_2_huffman.cpp*/

#include <iostream>
#include "lz.h"
#include "tablas_huffman.h"
#include "tabla_ld.h"
#include "tabla_LADD_DAA.h"
#include "tabla_huffman.h"
using namespace std;

int main()
{
	Tabla_LADD_DAA longi (t_longitud,29);
	Tabla_LADD_DAA distance (t_distancia,30);
	Tabla_Huffman h_litlong (tabla_litlong,4);
	Tabla_Huffman h_distancia (tabla_dist,1);
 	
	LZ lz;
	lz.Read(cin);
	unsigned int longitud=0, distancia;

	Vector_bits Huffman;
	
	Huffman+=1;
	Huffman+=0;
	Huffman+=1;

	while(longitud!=256)
	{
		lz.Next(longitud,distancia);
		
		if(longitud>256)
		{
			Huffman+=(h_litlong.Get_VBits(longi.Codigo(longitud-256)));
			Huffman+=(longi.GetAdicional(longitud-256));

			Huffman+=(h_distancia.Get_VBits(distance.Codigo(distancia)));
			Huffman+=(distance.GetAdicional(distancia));
		}
		else
		{
			if(longitud<256)
			{
				Huffman+=(h_litlong.Get_VBits(longitud));
			}
		}
	}
	Huffman+=(h_litlong.Convert_Bin(256,7));
	cout<<'\n'<<Huffman<<endl<<endl;
}	

