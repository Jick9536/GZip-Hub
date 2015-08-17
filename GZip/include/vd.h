/**
@file vd.h */
#ifndef __VD__H__
	#define __VD__H__

#include <iostream>
using namespace std;

class VD
{
	char* cad;
	int num_elem;
	int max_size;
	
	public:
		/**
		@brief Constructor por defecto
		@param[in] int n si no le pasa este valor crea un vector dinamico vacio, en caso contrario n>=0 crea un vector dinamico de n reservado
		*/
		VD (int n=0);
		/**
		@brief Constructor de copias
		@param[in] Objeto tipo VD a partir del cual se va construir el nuevo objeto
		@param [out] Nuevo objeto VD creado
		*/
		VD (const VD &v);
		/**
		@brief Destructor por defecto
		*/
		~VD();
		/**
		@brief Lector de flujo de entrada
		@param[in] istream &is refrencia al flujo donde volcamos el VD
		*/
		void Leer(istream &is);
		/**
		@brief Operador de asignación de VD
		@param [in] Objeto de tipo tabla huffman que va a ser asignado
		@param [out] Objeto de tipo tabla huffman que se la asignado el anterior
		*/
		VD& operator = (const VD &v);
		/**
		@brief Devuelve la longitud del vector dinamico
		@param[out] int con longitud
		*/
		int Size ()const;
		/**
		@brief Fija el caracter c en la posición i-ésima
		@param[in] int i posción i-ésima
		@param[in] char c caracter a fijar
		*/
		void Set (int i, char c);
		/**
		@brief Devuelve el caracter i-ésimo del vd
		@param[in] int i posiciónb i-ésima
		@param[out] char de la posición i-ésima
		*/
		char Get (int i);
		/**
		@brief Redimensionador del VD
		@param[in] int n numero a redimensionar
		*/
		void Resize(int n);
		/**
		@brief Añade a la cadena el char c
		@param[in] char c caracter a añadir
		*/
		void Add(char c);
		
};

#endif

