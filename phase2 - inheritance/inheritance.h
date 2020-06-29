#ifndef __INHERITANCE_H__
#define __INHERITANCE_H__

#include <stdio.h>
#include "c2c_encapsulation_defs.h"

typedef struct Material
{
	char empty;
}Material;
typedef enum Types
{
	PLASTIC,
	METAL,
	WOOD,
	PAPER,
	OTHER
}Types;
typedef struct Material_t
{	
	Types material;
}Material_t;


typedef struct PhysicalBox
{
	Box box;
	Material_t material;
}PhysicalBox;


typedef struct WeightBox
{
	Box box;
	double weight;
}WeightBox;



void ctor_PhysicalBoxpbddd(PhysicalBox* const this,double l, double w, double h);
void ctor_PhysicalBoxpbdddmt(PhysicalBox* const this,double l, double w, double h, Types t);
void ctor_PhysicalBoxpbmt(PhysicalBox* const this,Types t);
void dctor_PhysicalBoxpb(PhysicalBox* const this);
void PhysicalBox_printp(const PhysicalBox* const this);
void ctor_WeightBoxwdddd(WeightBox* const this,double l, double w, double h, double wgt);
void copy_ctor_WeightBoxw(WeightBox* const this,const WeightBox* const other);
void dtor_WeightBoxw(WeightBox* const this);
WeightBox* const asigment_operator_WeightBoxw(WeightBox* const this,const WeightBox* const other);
void WeightBoxw_printw(const WeightBox* const this);

#endif
