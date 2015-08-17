/**
@file tabla_LADD_DAA.cpp*/

#include "tabla_LADD_DAA.h"

Tabla_LADD_DAA::Tabla_LADD_DAA(const int tabla[][4], int fil)
{
	this->fil=fil;
	this->col=4;
	v=new int* [fil];
	for(int i=0; i<fil;++i)
	{
		v[i]=new int [4];
	}
	
	for(int i=0; i<fil; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			v[i][j]=tabla[i][j];
			
		}
	}
	
}

Tabla_LADD_DAA::Tabla_LADD_DAA(const Tabla_LADD_DAA &t)
{
	this->fil=t.fil;
	this->col=t.col;
	for(int i=0; i<t.fil; ++i)
	{
		for(int j=0; j<t.col; ++j)
		{
			v[i][j]=t.v[i][j];
		}
	}

	
}

Tabla_LADD_DAA& Tabla_LADD_DAA::operator = (const Tabla_LADD_DAA &t)
{
	if(this!=&t)
	{
		if(fil!=0 || col!=0)
		{
			for(int i=0; i<fil; ++i)
			{
				delete []v[i];
			}
			delete[]v;
		}
		else
		{
			this->fil=t.fil;
			this->col=t.col;
			for(int i=0; i<t.fil; ++i)
			{
				for(int j=0; j<t.col; ++j)
				{
					v[i][j]=t.v[i][j];
				}
			}
		}
	}
	return *this;
}


Tabla_LADD_DAA::~Tabla_LADD_DAA()
{
	for(int i=0; i<fil; ++i)
	{
		delete []v[i];
	}
	delete[]v;
}

int Tabla_LADD_DAA::Codigo(int lod)
{
	//[0]codigo
	//[1]num_bits
	//[2]long/distan_min
	//[3]long/distan_max
	
	for(int j=0; j<fil; ++j)
	{
		if(v[j][3]==0)
		{
			if(v[j][2]==lod)
			{
				return v[j][0];
			}
		}
		else
		{
			if(v[j][2]<=lod && lod<=v[j][3])
			{
				return v[j][0];
			}
		}
	}
	return -1;
}

int Tabla_LADD_DAA::Num_bits(int lod)
{
	//[0]codigo
	//[1]num_bits
	//[2]long/distan_min
	//[3]long/distan_max
	
	for(int j=0; j<fil; ++j)
	{
		if(v[j][3]==0)
		{
			if(v[j][2]==lod)
			{
				return v[j][1];
			}
		}
		else
		{
			if(v[j][2]<=lod && lod<=v[j][3])
			{
				return v[j][1];
			}
		}
	}
	return -1;
}

Vector_bits Tabla_LADD_DAA::Convert_Bin (int n, int num_bits)const
{
	Vector_bits v;
	for (int i=0; i<num_bits; ++i)
	{
		if (n&1==1)
			v+=true;
		else
			v+=false;
				
		n=(n>>1);
	}

// 	v.Invertir_todo();
	return v;
}

Vector_bits Tabla_LADD_DAA::GetAdicional (int lod)
{
	int ad_aux;
	Vector_bits add;
// 	cout<<"Inicio rango "<<Elem_Ini_Rango(lod)<<endl;
	ad_aux=lod-(Elem_Ini_Rango(lod));
// 	cout<<"ad "<<ad_aux<<endl;
 				
	add=Convert_Bin(ad_aux,Num_bits(lod));
// 	add.Invertir_todo();
	return add;
}

