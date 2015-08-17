/**
@file LZ.h*/
#ifndef __LZ__H__
	#define __LZ__H__

#include <iostream>
#include "vd.h"
#include "crc32.h"

using namespace std;

class LZ
{
	VD cad;
	CRC32 crc;
	int i;
	
	public:
	
	/**
	@brief Constructor por defecto
	*/
	LZ();
	/**
	@brief Constructo de copia del método
	@param[in] Objeto tipo LZ a partir del cual se va construir el nuevo objeto
	@param [out] Nuevo objeto LZ creado
	*/
	LZ (const LZ &lz);
	/**
	@brief Destructor por defecto
	*/
	~LZ();
	/**
	@brief Método que lee atraves de un flujo la información a procesora por el alogoritmo
	@param[in] istream &is flujo de entrada
	*/
	void Read(istream &is);
	unsigned long Crc32 ();
	/**
	@brief Metódo que calcula el LZ y devuelve por parametros longitud y distancia a la cadena de referencia en caso de que no haya coincidencia devuelve por longitud el valor del caracter correspondiente y distancia igual a 0.
	@param [in][out] Datos int longitud y distancia. Longitud devuelve la longitud de la cadena comprimida y distancia devuelve la distancia a la cadena orignal. En caso de que la longitud de repetición de cadena sea menor que tres. Distancia devuelve 0 y longitud el valor en decimal del caracter correspondiente. Si hemos acabado el algoritmo longitud devuelve el valor 256.
	*/
	void Next(unsigned int &longitud,unsigned int &distancia);
	/**
	@brief Devuelve la longitud orignal del objeto a codificar
	@param [out] int con dicho valor
	*/
	int SizeCad()const;
};

#endif

