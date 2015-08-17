/**
@file vd.cpp */

#include "vd.h"
#include <assert.h>

VD::VD(int n)
{
	if(n==0)
	{
		cad=0;
		num_elem=0;
		max_size=0;
	}
	else
	{
		cad=new char [n];
		num_elem=0;
		max_size=n;
	}
}

VD::VD (const VD& v)
{
	if(v.max_size>0)
	{
		max_size=v.max_size;
		num_elem=v.num_elem;
		cad=new char[max_size];
		
		for (int i=0; i<num_elem; ++i)
		{
			cad[i]=v.cad[i];
		}
	}
	else
	{
		cad=0;
		num_elem=0;
		max_size=0;
	}
}


VD::~VD()
{
	delete []cad;
}

VD& VD::operator = (const VD &v)
{
	if (this!=&v)
	{
		if(max_size>0)
		{
			delete[]cad;
		}
		
		if(v.max_size>0)
		{
			num_elem=v.num_elem;
			max_size=v.max_size;
			cad=new char[max_size];
		
			for (int i=0; i<num_elem; ++i)
			{
				cad[i]=v.cad[i];
			}
		}
		else
		{
			cad=0;
			num_elem=0;
			max_size=0;
		}
	}
	
	return *this;
}


void VD::Set (int i, char c)
{
	cad[i]=c;
}

char VD::Get (int i)
{
	return cad[i];
}

int VD::Size ()const
{
	return num_elem;
}


void VD::Resize(int n)
{
	if(n!=max_size)
	{
		if(n!=0)
		{
			char *aux=new char [n];
			if(num_elem>0)
			{
				int aux_num;
				if (num_elem<n)
				{
					aux_num=num_elem;
				}
				else
				{
					aux_num=n;
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
			if(num_elem>0)
			{
				delete[]cad;
			}
			
			cad=0;
			num_elem=0;
			max_size=0;
		}
	}
}

void VD::Add(char c)
{
	assert(num_elem<=max_size);
	
	if(num_elem<max_size)
	{
		Set(Size(),c);
		num_elem++;
	}
	else
	{
		if(num_elem==0)
		{
			Resize(1);
		}
		else
		{
			Resize(num_elem*2);
		}
		
		Set(Size(),c);
		num_elem++;
	}
}


void VD::Leer(istream &is)
{
	char c;
	while (is.get(c))
	{
		Add(c);
	}
}

