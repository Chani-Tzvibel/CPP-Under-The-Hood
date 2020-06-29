#include "inheritance.h"


void ctor_PhysicalBoxpbddd(PhysicalBox* const this,double l, double w, double h)
{
	b7Boxbddd(&(this->box),l,w,h);
	this->material.material=OTHER;
	printf("Material created, set to %s\n","Other");
	PhysicalBox_printp(this);
}
void ctor_PhysicalBoxpbdddmt(PhysicalBox* const this,double l, double w, double h,Types t)
{
	b7Boxbddd(&(this->box),l,w,h);
	this->material.material=t;
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("Material created, set to %s\n",names[t]);
	PhysicalBox_printp(this);

}
void ctor_PhysicalBoxpbmt(PhysicalBox* const this,Types t)
{
	b5Boxbd(&(this->box),1);
	this->material.material=t;
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("Material created, set to %s\n",names[t]);
	PhysicalBox_printp(this);
}
void dctor_PhysicalBoxpb(PhysicalBox* const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->box.length, this->box.width,this->box.height, names[this->material.material]);
	b10destroyBox(&(this->box));
}

void PhysicalBox_printp(const PhysicalBox* const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("PhysicalBox, made of %s; ", names[this->material.material]);
    b7printfb(&(this->box));
}

void ctor_WeightBoxwdddd(WeightBox* const this,double l, double w, double h, double wgt)
{
	b7Boxbddd(&(this->box),l,w,h);
	this->weight=wgt;
	WeightBoxw_printw(this);
}
void copy_ctor_WeightBoxw(WeightBox* const this,const WeightBox* const other)
{
	b5Boxbd(&(this->box),1);
	this->weight=other->weight;
	WeightBoxw_printw(this);
}
void dtor_WeightBoxw(WeightBox* const this)
{
	printf("Destructing WeightBox; ");
    WeightBoxw_printw(this);
	b10destroyBox(&(this->box));
}
WeightBox* const asigment_operator_WeightBoxw(WeightBox* const this,const WeightBox* const other)
{
	this->weight=other->weight;
	return this;

}
void WeightBoxw_printw(const WeightBox* const this)
{
	printf("WeightBox, weight: %f; ", this->weight);
	b7printfb(&(this->box));
}

