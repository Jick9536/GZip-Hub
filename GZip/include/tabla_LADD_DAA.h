/**
@file tabla_LADD_DAA.h*/

#ifndef __tabla_LADD_DAA__H__
	#define __tabla_LADD_DAA__H__

#include <iostream>
#include "vector_bits.h"


using namespace std;

class Tabla_LADD_DAA
{
	int **v;
	int fil;
	int col;
	int Elem_Ini_Rango(const int lod)
	{
	//[0]codigo
	//[1]num_bits
	//[2]long/distan_min
	//[3]long/distan_max
	
		if(Num_bits(lod)>0)
		{
			for(int j=0; j<fil; ++j)
			{
				if(v[j][2]<=lod && lod<=v[j][3])
				{
					return v[j][2];
				}
			}
			return -1;
		}
		else
		{
			return -1;
		}
	}

	public:
		/**
		@pre No puedes usar la clase sin antes construirla de esta forma
		@brief Constructor parametrizado de la clase
		@param [in] matriz de int con fil filas y con 4 columnas donde almacenamos los datos a ser procesados
		@param [out] objeto de tipo Tabla_LADD_DAA con el que trabajaremos
		*/
		Tabla_LADD_DAA(const int tabla[][4], int fil);
		/**
		@brief Constructor de copia
		@param[in] Objeto de tipo tabla ladd_daa a parir del cual crearemos el otro objeto
		@param[out] Objeto de tipo tabla ladd_daa creado a partir del anterior
		*/
		Tabla_LADD_DAA(const Tabla_LADD_DAA &t);
		/**
		@brief Destructor por defecto
		*/
		~Tabla_LADD_DAA();
		/**
		@brief Método que calcula la secuencia en bits de un dato n con un número determinado de bits
		@param[in] int n dato a ser pasado en bits
		@param[in] int num_bits número de bits a ser codificado
		@param[out] objeto vector_bits con el resultado
		*/
		Vector_bits Convert_Bin (int n, int num_bits)const;
		/**
		@brief Método asignación de la clase
		@param [in] Objeto de tipo tabla ladd_daa que va a ser asignado
		@param [out] Objeto de tipo tabla ladd_daa que se la asignado el anterior
		*/
		Tabla_LADD_DAA& operator = (const Tabla_LADD_DAA &t);
		/**
		@brief Devuelve el código asociado a una longitud o distancia x
		@param [in] lod longitud o distancia
		@param [out] Código asociado a la longitud o distancia
		*/
		int Codigo(int lod);
		/**
		@brief Devuelve el número de bits de una longitud o distancia x
		@param [in] lod longitud o distancia
		@param [out] Número de bits asociado a la longitud o distancia
		*/
		int Num_bits(int lod);
		/**
		@brief Devuelve el vector de bits adicional asociado a una longitud o distancia x
		@param [in] lod longitud o distancia
		@param [out] vector de bits adicional asociado a la longitud o distancia. Si no tiene devuelve el vector de bits por defecto es decir vacio
		*/
		Vector_bits GetAdicional(int lod);
};

#endif
