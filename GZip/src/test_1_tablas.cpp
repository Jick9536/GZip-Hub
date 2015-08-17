/**
@file test_1_tablas*/

#include <iostream>
#include "tablas_huffman.h"
#include "tabla_ld.h"
#include "tabla_LADD_DAA.h"
#include "tabla_huffman.h"

using namespace std;

int main()
{
	Tabla_LADD_DAA longi (t_longitud,29);
	
	Tabla_LADD_DAA distancia (t_distancia,30);
	
	Tabla_Huffman h_litlong (tabla_litlong,4);
	
	Tabla_Huffman h_distancia (tabla_dist,1);
	
}


