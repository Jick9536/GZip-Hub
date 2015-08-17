/**
@file vector_bits.h */

#ifndef __VECTOR_BITS__H__
	#define __VECTOR_BITS__H__

#include <iostream>
using namespace std;

class Vector_bits
{
	unsigned char* cad;
	int num_bits;
	int max_size;
	
	public:
		/**
		@brief Constructor por defecto
		@param [in] Si es cero crea un vector de bits vacio. En caso contrario reserva n bits
		*/
		Vector_bits (int n=0);
		/**
		@brief Constructor de copia
		@param [in] Objeto referenciado de copia
		@param [out] Objeto construido apartir del anteriormente citado
		*/
		Vector_bits (const Vector_bits &v);
		/**
		@brief Destructor por defecto
		*/
		~Vector_bits();
		/**
		@brief Operador de asignación
		@param [in] Objeto referenciado
		@param [out] Objeto asginado
		*/
		Vector_bits& operator = (const Vector_bits &v);
		/**
		@brief Devuelve el numero de bits alamacenados
		@param [in] Numero de bits almacenados
		*/
		int Size_bits()const;
		/**
		@pre No puedes salirte de lo que este reservado
		@brief Fija el bit en la posición i
		@param [in] i numero de bit a fijar
		@param [in] bit bit a fijar
		*/
		void Set_bit (int i,bool bit);
		/**
		@pre No puedes devolver un bit que no este creado
		@brief Devuelve el bit usado i
		@param [in] int i numero de bit usado
		*/
		bool Get_bit (int i)const;
		/**
		@brief Redimensiona el vector de bits a n bits
		@param[in] int n nuevo tamaño
		*/
		void Resize(int n);
		/**
		@brief Invierte el vector de bits
		*/
		void Invertir_todo();
		/**
		@brief Invierte el vector de bits byte a byte. No llega usarse nunca.
		*/
		void Invetir_byteabyte();
		/**
		@brief Sobrecarga del operador += para añadir bit a bit
		@param[in] bool bit. Bit a añadir
		*/
		void operator += (bool bit);
		/**
		@brief Sobrecarga del operador += para concatera vector de bits
		@param [in] const Vector_bits &v vector de bits a concatenar
		*/
		void operator += (const Vector_bits &v);
		/**
		@brief Operador de igualadad
		*/
		bool operator == (const Vector_bits &v);
		/**
		@brief Operador de desiagualda
		*/
		bool operator != (const Vector_bits &v);
		/**
		@brief Sobrecarga del operador de entrada de datos
		@param[in] istream is. Flujo de entrada
		@param[in] Vector_bits &v. Datos a modificar
		@param[out] Flujo de entrada nuevo
		*/
		friend istream& operator >> (istream &is, Vector_bits &v);
		/**
		@brief Guarda en el flujo un vector de bitd
		@param [in] flujo a salida donde meter el vector de bits
		*/
		void Salva(ostream &os)const;
		/**
		@brief Sobrecarga del operador de salida de datos
		@param[in] ostream os. Flujo de salida
		@param[in] Vector_bits &v. Datos a modificar
		@param[out] Flujo de salida modificado
		 */
		friend ostream& operator << (ostream &os,const Vector_bits &v);
		
};

#endif

