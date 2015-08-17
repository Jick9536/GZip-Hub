/**
@file tabla_huffman*/

#ifndef __tabla_huffman__H__
	#define __tabla_huffman__H__

#include <iostream>
#include "vector_bits.h"

class Tabla_Huffman
{
	Vector_bits *vb;
	int num_elem;
	
	public:
		/**
		@brief Constructor parametrizado de la clase
		@param [in] matriz de int con fil filas y con 5 columnas donde almacenamos los datos a ser procesados
		@param [out] objeto de tipo Tabla_Huffman con el que trabajaremos
		*/
		Tabla_Huffman(const int v[][5], int fil);
		/**
		@brief Constructor de copia
		@param[in] Objeto de tipo tabla huffman a parir del cual crearemos el otro objeto
		@param[out] Objeto de tipo tabla huffman creado a partir del anterior
		*/
		Tabla_Huffman(const Tabla_Huffman &t);
		/**
		@brief Destrucor por defecto
		*/
		~Tabla_Huffman();
		/**
		@brief Método asignación de la clase
		@param [in] Objeto de tipo tabla huffman que va a ser asignado
		@param [out] Objeto de tipo tabla huffman que se la asignado el anterior
		*/
		Tabla_Huffman& operator = (const Tabla_Huffman &t);
		/**
		@brief Método que calcula la secuencia en bits de un dato n con un número determinado de bits
		@param[in] int n dato a ser pasado en bits
		@param[in] int num_bits número de bits a ser codificado
		@param[out] objeto vector_bits con el resultado
		*/
		Vector_bits Convert_Bin (int n, int num_bits)const;
		/**
		@pre Debe ser un valor correcto. Sino devolvera un mensaje y el valor de la ultima celda reservada tenga lo que tenga
		@brief Método que obtiene la codificación huffman en bits de un dato
		@param[in] Valor a ser codificado.
		@param[out] Si el valor introducido es correcto devolver la codificación huffman asociada a num en caso contrario en mensaje de error y el valor de la última celda reservada (basura)
		*/
		Vector_bits Get_VBits(int num)const;
		/**
		@brief En construción 
		*/
		int Get_num(const Vector_bits &v);	
};

#endif



