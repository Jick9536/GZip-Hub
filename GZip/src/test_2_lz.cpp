/**
@file test_2_lz.cpp*/

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
	unsigned int longitud=0;
	unsigned int distancia;
	
	 
	
	while(longitud!=256)
	{
		lz.Next(longitud,distancia);
		
		if(longitud>256)
		{
			cout<<"#REF("<<longitud-256<<","<<longi.GetAdicional(longitud-256)<<","<<distancia<<","<<distance.GetAdicional(distancia)<<")";
		}
		else
		{
			if(longitud<256)
			{
				cout <<(char) longitud;
			}
		}
	}
	cout <<longitud<<endl;
}	

