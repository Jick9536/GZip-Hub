/**
@file tabla_Huffman.cpp*/

#include "tabla_huffman.h"

	/*[0] Inicio rango codigo
	[1] Final rango codigo
	[2] nº bits
	[3] incio tango v_b
	[4] final v_b
	*/

Tabla_Huffman::Tabla_Huffman(const int v[][5], int fil)
{
	int aux=0;//Valor a guardar
	num_elem=v[fil-1][1]+1;
	vb=new Vector_bits [num_elem];
	
	for(int i=0; i<fil; ++i)
	{
		aux=v[i][3];
		
		for(int j=v[i][0]; j<=v[i][1]; ++j)
		{
			vb[j]=Convert_Bin(aux,v[i][2]);
			aux++;
		}
	}	
}

Vector_bits Tabla_Huffman::Convert_Bin (int n, int num_bits)const
{
	Vector_bits v;
	int i;
	for (i=0; i<num_bits; ++i)
	{
		if (n&1==1)
			v+=true;
		else
			v+=false;
				
		n=(n>>1);
		
	}

  	v.Invertir_todo();
	return v;
}
	

		
	
Tabla_Huffman::Tabla_Huffman(const Tabla_Huffman &t)
{
	if(t.num_elem>0)
	{
		num_elem=t.num_elem;
		vb=new Vector_bits[num_elem];
	
		for(int i=0; i<num_elem; ++i)
		{
			vb[i]=t.vb[i];
		}
	}
	else
	{
		vb=0;
		num_elem=0;
	}
}

Tabla_Huffman::~Tabla_Huffman()
{
	delete[]vb;
}

Tabla_Huffman& Tabla_Huffman::operator = (const Tabla_Huffman &t)
{
	if(this!=&t)
	{
		if(num_elem>0)
		{
			delete[]vb;
		}
		else
		{
			if(t.num_elem>0)
			{
				num_elem=t.num_elem;
				vb=new Vector_bits[num_elem];
	
				for(int i=0; i<num_elem; ++i)
				{
					vb[i]=t.vb[i];
				}
			}
			
			else
			{
				vb=0;
				num_elem=0;
			}
		}
	}
	return *this;
}

Vector_bits Tabla_Huffman::Get_VBits(int num)const
{
	if(num>num_elem)
	{
		//Las posiciones 287 y 31 nunca se usan por eso las devuelvo
		cerr << "No se puede obtener dicho vector de bits. Valor obtenido no valido"<<endl;
		return vb[num_elem-1];
	}
	
	return vb[num];
}

int Tabla_Huffman::Get_num(const Vector_bits &v) //Para decodifciar si hago el extra
{
	cerr <<"En construcción"<<endl;
	return 0;
}
