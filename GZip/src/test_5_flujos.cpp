/**
@file test_5_flujos.cpp*/


#include <iostream>
#include <fstream>
#include "lz.h"
#include "tablas_huffman.h"
#include "tabla_ld.h"
#include "tabla_LADD_DAA.h"
#include "tabla_huffman.h"

using namespace std;

int main(int argc, char **argv)
{
	char *aux;
	ifstream entrada;
	ofstream salida;
	entrada.open(argv[1],ios::in|ios::binary);
	
	if(argc==2)
	{
		aux=new char[strlen(argv[1])+strlen(".gz")+1];
		strcpy(aux,argv[1]);
		strcat(aux,".gz");
		aux[strlen(argv[1])+strlen(".gz")]='\0';
		salida.open(aux,ios::out|ios::binary);
	}
	
	else
	{
		salida.open(argv[2],ios::out|ios::binary);
	}	


	if(entrada && salida)
	{
		Tabla_LADD_DAA longi (t_longitud,29);
		Tabla_LADD_DAA distance (t_distancia,30);
		Tabla_Huffman h_litlong (tabla_litlong,4);
		Tabla_Huffman h_distancia (tabla_dist,1);

		LZ lz;
		lz.Read(entrada);
		unsigned int longitud=0, distancia;
		

		Vector_bits Huffman;
		Huffman+=1;
	 	cout<<Huffman<<endl;
		Huffman+=1;
	 	cout<<Huffman<<endl;
		Huffman+=0;
	 	cout<<Huffman<<endl;
		cout<<lz.SizeCad()<<endl;
	
		while(longitud!=256)
		{
			lz.Next(longitud,distancia);
		
			if(longitud>256)
			{
				cout<<"Bandera 1"<<endl;
				Huffman+=(h_litlong.Get_VBits(longi.Codigo(longitud-256)));
				Huffman+=(longi.GetAdicional(longitud-256));
				
				cout<<"LONGITUD "<<longitud-256<<endl;
				cout<<"Vector de bits "<<h_litlong.Get_VBits(longi.Codigo(longitud-256))<<endl;
				
				cout<<"Adicionales ";
				cout<<longi.GetAdicional(longitud-256)<<endl<<endl;
				
				Huffman+=(h_distancia.Get_VBits(distance.Codigo(distancia)));
				Huffman+=(distance.GetAdicional(distancia));
				
				cout<<"DISTANCIA "<<distancia<<endl;
				cout<<"Codigo "<<(distance.Codigo(distancia))<<endl;
				cout <<"Vector de bits "<<h_distancia.Get_VBits(distance.Codigo(distancia))<<endl;
				
				cout<<"Adicionales ";
				cout << distance.GetAdicional(distancia)<<endl;
				cout<<endl;
				
			}
			else
			{
				if(longitud<256)
				{
					cout<<"Bandera 2"<<endl;
					cout<< "CARACTER "<<(char) longitud<<' '<<longitud<<endl;
					Huffman+=(h_litlong.Get_VBits(longitud));
					cout<<endl;
 	
					
				}
			}
		}

 		Huffman+=(h_litlong.Convert_Bin(256,7));
		cout<<Huffman<<endl;
		Huffman.Salva(salida);
		entrada.close();
		salida.close();
		salida.clear();
	}
	else
	{
		cerr<<"Error leer archivos y crear el archivo"<<endl;
		entrada.close();
		salida.close();
	}	
}	
