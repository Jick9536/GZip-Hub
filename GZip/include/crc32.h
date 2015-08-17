/**
@file crc32.h */

#ifndef __CRC32__H__
	#define __CRC32__H__

#include <iostream>
#include <cstring>

using namespace std;

class CRC32
{
	unsigned long crc32;
	unsigned long tabla[256];
	
	public:
		/**
		@brief Constructor por defecto
		*/
		CRC32();
		/**
		@brief Operador de asignación
		@param[in] Parametro de tipo CRC32 a ser asignado
		@param[out] Dato tipo CRC32 asignado
		*/
		CRC32 &operator = (const CRC32 &crc);
		/**
		@brief Método que calcula el CRC32 de un byte (unsigned char)
		@param[in] Byte a calcular su crc32
		*/
		void CRC32_AddByte(unsigned char byte);
		/**
		@brief Método que devuelve el codigo CRC32 calculado
		@param[out] unsigned long con el valor del CRC32
		*/
		unsigned long CRC32_get ()const;
		/**
		@brief Destructor por defecto del Método
		*/
		~CRC32();
};

#endif


