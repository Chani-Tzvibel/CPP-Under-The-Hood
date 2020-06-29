#include <stdio.h>
#include <stdbool.h> 
#include "c2c_encapsulation_defs.h"
 
extern const char* const DEF_MSG;
extern const char* message;

static Box largeBox;
static Box box99;
static Box box88;

void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n"); 
    static bool flag=true;
	if(flag)
	{	
		b7Boxbddd(&box99,99,99,99);	
		flag=false;
	}
    b14operatorMultbd(&box99,10);
}

void thatFunc()
{
	static bool flag=true;
    printf("\n--- thatFunc() ---\n\n"); 
    if(flag)
	{
		b7Boxbddd(&box88,88,88,88);
		flag=false;
	}
    b14operatorMultbd(&box88,10);
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1;
	b5Boxbd(&b1,3);
    Box b2;
	b7Boxbddd(&b2,5, 4, 6);
    
    printf("b1 volume: %f\n", b1.width*b1.length*b1.height);
    printf("b2 volume: %f\n", b2.width*b2.length*b2.height);

    b14operatorMultbd(&b1,1.5);
    b14operatorMultbd(&b2,0.5);

    printf("b1 volume: %f\n", b1.width*b1.length*b1.height);
    printf("b2 volume: %f\n", b2.width*b2.length*b2.height);

    Box b3;
	b7Boxbddd(&b3,b2.width,b2.length,b2.height);
    Box b4;
	b7Boxbddd(&b4,b2.width*3,b2.length*3,b2.height*3);
    printf("b3 %s b4\n", (b3.width==b4.width && b3.length==b4.length && b3.height==b4.height) ? "equals" : "does not equal");

    b14operatorMultbd(&b3,1.5);
    b14operatorMultbd(&b4,0.5);
    printf("Now, b3 %s b4\n", (b3.width==b4.width && b3.length==b4.length && b3.height==b4.height) ? "equals" : "does not equal");

	b10destroyBox(&b1);
	b10destroyBox(&b2);
	b10destroyBox(&b3);
	b10destroyBox(&b4);

    printf("\n--- End doBoxes() ---\n\n");
}


void doShelves()
{
   	printf("\n--- start doShelves() ---\n\n");
	
	bool flag=true;
	bool flag1=true;
    
	Box aBox;
	b5Boxbd(&aBox,5);

    Shelf aShelf;
	Box b1,b2,b3;
	b5Boxbd(&b1,1);
	b5Boxbd(&b2,1);
	b5Boxbd(&b3,1);
	aShelf.boxes[0]=b1;
	aShelf.boxes[1]=b2;
	aShelf.boxes[2]=b3;
	

    s7printfs(&aShelf);
    s9setBoxbib(&aShelf,1,largeBox);
    s9setBoxbib(&aShelf,0, aBox);

    s7printfs(&aShelf);
    message="This is the total volume on the shelf:";
    s7printfs(&aShelf);
    message="Shelf's volume:";
    s7printfs(&aShelf);
	
	b7Boxbddd(&b1,4, 6, 2);
    s9setBoxbib(&aShelf,1,b1);
		
	b5Boxbd(&b2,2);
    s9setBoxbib(&aShelf,2,b2);
    s7printfs(&aShelf);
    printf("\n--- end doShelves() ---\n\n");

	b10destroyBox(&aBox);
	b10destroyBox(&b1);
	b10destroyBox(&b2);
	b10destroyBox(&b3);
}

int main()
{
	b7Boxbddd(&largeBox,10, 20, 30);
	printf("\n--- Start main() ---\n\n");
	
	doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();

    doShelves();
   
    printf("\n--- End main() ---\n\n");

	b10destroyBox(&largeBox);
	b10destroyBox(&box99);
	b10destroyBox(&box88);  

    return 0;
}
