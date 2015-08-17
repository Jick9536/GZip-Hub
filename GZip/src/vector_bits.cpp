/**
@file vector_bits.cpp*/

#include "vector_bits.h"
#include <assert.h>

Vector_bits ::Vector_bits (int n)
{
	if(n==0)
	{
		cad=0;
		num_bits=0;
		max_size=0;
		cad=0;
	}
	else
	{
		cad=new unsigned char [n];
		for(int i=0; i<n;++i)
		{
			cad[i]=0;
		}
		num_bits=0;
		max_size=n;
	}
}

Vector_bits::Vector_bits (const Vector_bits & v)
{
	if(v.max_size>0)
	{
		max_size=v.max_size;
		num_bits=v.num_bits;
		cad=new unsigned char[max_size];
		
		for (int i=0; i<max_size; ++i)
		{
			cad[i]=v.cad[i];
		}
	}
	else
	{
		cad=0;
		num_bits=0;
		max_size=0;
	}
}


Vector_bits::~Vector_bits ()
{
	delete []cad;
	max_size=0;
	num_bits=0;
}

Vector_bits& Vector_bits::operator = (const Vector_bits &v)
{
	if (this!=&v)
	{
		if(max_size>0)
		{
			delete[]cad;
		}
		
		if(v.max_size>0)
		{
			num_bits=v.num_bits;
			max_size=v.max_size;
			cad=new unsigned char[max_size];
		
			for (int i=0; i<max_size; ++i)
			{
				cad[i]=v.cad[i];
			}
		}
		else
		{
			cad=0;
			num_bits=0;
			max_size=0;
		}
	}
	
	return *this;
}


void Vector_bits::Set_bit (int i,bool bit)
{
	int i2, n;
	i2=i/8;
	n=i%8;
	
	if(bit==true)
	{
		cad[i2]=cad[i2]|(1<<n);
	}
	else
	{
		cad[i2]=cad[i2]&~(1<<n);
	}
}

bool Vector_bits::Get_bit (int i)const
{
	bool bit;
	int i2, n;
	i2=i/8;
	n=i%8;
	
	bit=cad[i2]&(1<<n);
	return bit;
}


int Vector_bits::Size_bits()const
{
	return num_bits;
}

void Vector_bits::Resize(int n)
{
	if(n!=max_size)
	{
		if(n!=0)
		{
			unsigned char *aux=new unsigned char [n];
			if(max_size>0)
			{
				int aux_num;
				if (max_size<n)
				{
					aux_num=max_size;
				}
				else
				{
					aux_num=n;
				}
				
				for(int i=0; i<aux_num; ++i)
				{
					aux[i]=0;
				}
				
				for (int i=0; i<aux_num; ++i)
				{
					aux[i]=cad[i];
				}
				
				delete []cad;
			}
			max_size=n;
			cad=aux;
		}
		else
		{
			if(max_size>0)
			{
				delete[]cad;
			}
			
			cad=0;
			num_bits=0;
			max_size=0;
		}
	}
}

void Vector_bits::Invertir_todo()
{
	Vector_bits aux;
		
	for(int i=Size_bits()-1; i>=0; --i)
	{
		aux+=Get_bit(i);
	}
	*this=aux;
}

void Vector_bits::Invetir_byteabyte()
{
	Vector_bits aux;
	
	for(int i=0; i<=(Size_bits()/8); ++i)
	{
		for(int j=7; j>=0; --j)
		{
			aux+=Get_bit((8*i)+j);
		}
	}
	*this=aux;
}


void Vector_bits::operator += (bool bit)
{
	if(max_size==0)
	{
		Resize(1);
	}
	
	if(num_bits >= max_size*8)
	{
		Resize(max_size*2);
		Set_bit(num_bits,bit);
	}
	else
	{
		Set_bit(num_bits,bit);
	}
	num_bits++;
}

void Vector_bits::operator += (const Vector_bits &v)
{
	if(max_size==0)
	{
		Resize(1);
	}
	
	if((num_bits+v.num_bits)>=max_size*8)
	{
		Resize((num_bits+v.num_bits/8)*2);
	}
	
	int j=0;
	for(int i=num_bits; i<(num_bits+v.num_bits); ++i)
	{
		Set_bit(i,v.Get_bit(j));
		++j;
	}
	num_bits=num_bits+v.num_bits;
}

bool Vector_bits::operator == (const Vector_bits &v)
{
	if(num_bits!=v.Size_bits()) 
		return false;
	
	for (int i=0; i<Size_bits(); ++i)
	{
		if(Get_bit(i)!=v.Get_bit(i))
		{
			return false;
		}
	}
	
	return true;
}

bool Vector_bits::operator != (const Vector_bits &v)
{
	if(*this==v)
	{
		return false;
	}
	else
	{
		return true;
	}
}

istream& operator >> (istream &is, Vector_bits &v)
{
	bool get;
	char c;
	while (is.peek()=='0'|| is.peek()=='1')
	{
		is.get(c);
		if(c=='0')
		{
			get=false;
			v+=get;
		}
		else
		{
			get=true;
			v+=get;
		}
	}
	return is;
}

void Vector_bits::Salva(ostream &os)const
{
	os.write((const char*) this->cad,(Size_bits()+7)/8);
}

ostream& operator << (ostream &os, const Vector_bits &v)
{
	for(int i=0; i<v.num_bits; ++i)
	{
		os<<v.Get_bit(i);
	}
	return os;
}
