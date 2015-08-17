/**
@file gzip.cpp*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "lz.h"
#include "tabla_LADD_DAA.h"
#include "tabla_huffman.h"
#include "tablas_huffman.h"
#include "tabla_ld.h"

using namespace std;

void Cabecera(ostream &os,char* nombre);
void Out (ostream &os,const Vector_bits &Huffman,LZ &lz);
void Algoritmo (Vector_bits &Huffman,
	        Tabla_LADD_DAA &longi,
		Tabla_LADD_DAA &distance, 
		Tabla_Huffman &h_litlong,
		Tabla_Huffman &h_distancia,
  		LZ &lz);


int main(int argc, char **argv)
{
	Vector_bits Huffman;
	LZ lz;
	Tabla_LADD_DAA longi (t_longitud,29);
	Tabla_LADD_DAA distance (t_distancia,30);
	Tabla_Huffman h_litlong (tabla_litlong,4);
	Tabla_Huffman h_distancia (tabla_dist,1);
	
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
		Cabecera(salida,argv[1]); //Metemos la cabecera entera
		cout<<"Lectura realizada"<<endl;
		lz.Read(entrada);
		cout<<"Incio de compresión de "<<argv[1]<<endl;
		Algoritmo(Huffman,longi,distance,h_litlong,h_distancia,lz);
		Out(salida,Huffman,lz);
		
		if(argc==2)
		{
			cout<<"Fin de compresión "<<aux<<endl;
		}

		if(argc==3)
		{
			cout<<"Fin de compresión "<<argv[2]<<endl;
		}
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
	
void Cabecera(ostream &os,char* nombre)
{
	char aux[10]={0x1F, 0x8B, 0x08, 0x18, 0x00, 0x00, 0x00, 0x00, 0x04, 0xFF};
	os.write(aux,10);
	os.write(nombre,strlen(nombre)+1);
	os.write("Julio Rodriguez Martinez 26241105Z",strlen("Julio Rodriguez Martinez 26241105Z")+1);
}

void Algoritmo(Vector_bits &Huffman,
	Tabla_LADD_DAA &longi,
	Tabla_LADD_DAA &distance, 
	Tabla_Huffman &h_litlong,
	Tabla_Huffman &h_distancia,
 	LZ &lz)
{
	unsigned int longitud=0, distancia;
	Huffman+=1;
	Huffman+=1;
	Huffman+=0;
	
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

}

void Out (ostream &os,const Vector_bits &Huffman, LZ &lz)
{
	Huffman.Salva(os);
	unsigned int dato= lz.Crc32();
	unsigned int dato1= lz.SizeCad();
	os.write((const char*) &dato,4);
	os.write((const char*) &dato1,4);
}
