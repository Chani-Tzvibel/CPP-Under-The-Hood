#include "inheritance.h"


void doMaterials()
{	
	Material_t mat1,mat2;

    printf("\n--- Start doMaterials() ---\n\n");
    
    printf("Size of Materials: %d\n", 1);
    printf("Size of mat: %d\n", 1);
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    struct MatTest {Material mat;Material_t mat_t;};
    printf("Size of Materials + Material_t: %d\n", 8);
    
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	mat1.material=OTHER;
	printf("Material created, set to %s\n", names[mat1.material]);
	mat2.material=METAL;
	printf("Material created, set to %s\n", names[mat2.material]);

    printf("\n--- End doMaterials() ---\n\n");

}

void doPhysicalBox()
{
    PhysicalBox pb1,pb2,pb3;

	printf("\n--- Start doPhysicalBox() ---\n\n");

	ctor_PhysicalBoxpbdddmt(&pb1,8, 6, 4, PLASTIC);
	ctor_PhysicalBoxpbmt(&pb2,WOOD);
	ctor_PhysicalBoxpbddd(&pb3,7, 7, 7);
    
    printf("\npb4 is copy-constructed from pb1\n");
    PhysicalBox pb4= pb1;
    PhysicalBox_printp(&pb4);
	PhysicalBox_printp(&pb1);
    printf("pb4 %s pb1\n", pb1.box.width==pb4.box.width &&  pb1.box.length==pb4.box.length &&  pb1.box.height==pb4.box.height && pb1.material.material==pb4.material.material? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    PhysicalBox_printp(&pb4);
	PhysicalBox_printp(&pb3);
    printf("pb4 %s pb3\n", pb3.box.width==pb4.box.width &&  pb3.box.length==pb4.box.length &&  pb3.box.height==pb4.box.height && pb3.material.material==pb4.material.material? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");

	dctor_PhysicalBoxpb(&pb4);
	dctor_PhysicalBoxpb(&pb3);
	dctor_PhysicalBoxpb(&pb2);
	dctor_PhysicalBoxpb(&pb1);

}

void doWeightBox()
{
    WeightBox pw1, pw2,pw3,pw4;

	printf("\n--- Start doWeightBox() ---\n\n");

	ctor_WeightBoxwdddd(&pw1,8, 6, 4, 25);
	ctor_WeightBoxwdddd(&pw2,1, 2, 3, 0.0);
	ctor_WeightBoxwdddd(&pw3,10, 20, 30, 15);
    
    printf("\npw4 is copy-constructed from pw1\n");
	copy_ctor_WeightBoxw(&pw4,&pw1);
    WeightBoxw_printw(&pw4);
    WeightBoxw_printw(&pw1);
    printf("pb4 %s pb3\n", pw3.box.width==pw4.box.width &&  pw3.box.length==pw4.box.length &&  pw3.box.height==pw4.box.height && pw3.weight==pw4.weight? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    asigment_operator_WeightBoxw(&pw4,&pw3);
    WeightBoxw_printw(&pw4);
    WeightBoxw_printw(&pw1);
    printf("pb4 %s pb3\n", pw3.box.width==pw4.box.width &&  pw3.box.length==pw4.box.length &&  pw3.box.height==pw4.box.height && pw3.weight==pw4.weight? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");


	dtor_WeightBoxw(&pw4);
	dtor_WeightBoxw(&pw3);
	dtor_WeightBoxw(&pw2);
	dtor_WeightBoxw(&pw1);

}





int main()
{
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");

}
