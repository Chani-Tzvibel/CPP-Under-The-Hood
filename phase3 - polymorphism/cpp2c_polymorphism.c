#include "cpp2c_polymorphism_defs.h"

extern MultipliervirtTable[];
extern prePostDollarFixerVirtTabl[];


void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets;
	PrePostFixer_ctorPPcc(&angleBrackets,"<<< ", " >>>");
    PrePostFixer_printPPc(&angleBrackets,"Hello World!");
    PrePostFixer_printPPlc(&angleBrackets,-777, '\0');
    PrePostFixer_printPPlc(&angleBrackets,350, '#');
    PrePostFixer_printPPlc(&angleBrackets,(long int)3.14,'\0');

    printf("\n--- end doPrePostFixer() ---\n\n");

	PrePostFixer_dtorPP(&angleBrackets);
}

void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer asterisks;
	PrePostDollarFixer_ctorPPDFcc(&asterisks,"***** ", " *****");
    PrePostDollarFixer_printPPDFic(&asterisks,-777,DOLLAR_DEFAULT_SYMBOL);
    PrePostDollarFixer_printPPDFic(&asterisks,-350,'#');
    PrePostDollarFixer_printPPDFdc(&asterisks,3.14f,DOLLAR_DEFAULT_SYMBOL);

    printf("\n--- end doPrePostDollarFixer() ---\n\n");

	PrePostDollarFixer_dtorPPDF(&asterisks);
}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
	PrePostChecker_PrePostChecker_ctorPC(&check);
    PrePostChecker_printThisSymbolUsingFuncPC(&check);
    PrePostChecker_printThisSymbolDirectlyPC(&check);
	PrePostChecker_printDollarSymbolByCastDirectlyPC(&check);
	PrePostChecker_printDollarSymbolByScopeDirectlyPC(&check);
	PrePostChecker_printDollarSymbolByCastUsingFuncPC(&check);
    PrePostChecker_printDollarSymbolByScopeUsingFuncPC(&check);



    printf("\n--- end doPrePostChecker() ---\n\n");

	PrePostChecker_PrePostChecker_dtorPC(&check);
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes;
	PrePostFloatDollarFixer_ctorPPFDFcc(&hashes,"### ", " ###");
    PrePostFloatDollarFixer_printPPFDFf(&hashes,-777);
    PrePostFloatDollarFixer_printPPFDFfc(&hashes,350, '#');
    PrePostFloatDollarFixer_printPPFDFf(&hashes,3.14f);

	PrePostDollarFixer hashes2;
	PrePostDollarFixer_ctorPPDFPPDF(&hashes2,&(hashes.prePostDollarFixer));
    PrePostDollarFixer_printPPDFdc(&hashes2,7.5,DOLLAR_DEFAULT_SYMBOL);
    PrePostDollarFixer_printPPDFic(&hashes2,100,DOLLAR_DEFAULT_SYMBOL);

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

	PrePostDollarFixer_dtorPPDF(&hashes2);
	PrePostFloatDollarFixer_dtorPPFDF(&hashes);
}

void runAsPrePostFixerRef(const PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

	pp->defaultTextFormatter.textfor.vptr[2](pp,123,'\0');
	
    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    PrePostDollarFixer_printPPDFic(pp,123,DOLLAR_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    PrePostDollarFixer newpp;
	PrePostDollarFixer_ctorPPDFPPDF(&newpp,&pp);
	newpp.prePostFixerDollar.defaultTextFormatter.textfor.vptr=prePostDollarFixerVirtTabl;
	printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    PrePostDollarFixer_printPPDFic(&newpp,123,DOLLAR_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
	
	PrePostDollarFixer_dtorPPDF(&newpp);
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    PrePostHashFixer_printPPHFic(pp,123,HASH_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1;
	DefaultTextFormatter_CtorDTF(&m1);
	m1.defaultTextFormatter.textfor.vptr=MultipliervirtTable;
	m1.times=3;
	printf("--- Multiplier CTOR: times = %d\n", m1.times);
    Multiplier m2;
	DefaultTextFormatter_CtorDTF(&m2);
	m2.defaultTextFormatter.textfor.vptr=MultipliervirtTable;
	m2.times=5;
	printf("--- Multiplier CTOR: times = %d\n", m2.times);


    Multiplier m3;
	DefaultTextFormatter_CtorDTFDTF(&m3,&m1);
	m3.times = m1.times;
    Multiplier m4;
	DefaultTextFormatter_CtorDTFDTF(&m4,&m2);
	m4.times = m2.times;

    Multiplier_printMc(&m4,"abc ");
    Multiplier_printMc(&m3,"abc ");
    Multiplier_printMc(&m2,"abc ");
    Multiplier_printMc(&m1,"abc ");

    printf("\n--- start doMultiplier() ---\n\n");


	Multiplier_dtorM(&m4);
	Multiplier_dtorM(&m3);
	Multiplier_dtorM(&m2);
	Multiplier_dtorM(&m1);
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");


    PrePostDollarFixer p1;
	PrePostFloatDollarFixer_ctorPPFDFcc(&p1,"!!! ", " !!!");
	DefaultTextFormatter d1;
	DefaultTextFormatter_CtorDTFDTF(&d1,&(p1.prePostFixerDollar.defaultTextFormatter));
	PrePostDollarFixer_dtorPPDF(&p1);
    Multiplier m1;
	DefaultTextFormatter_CtorDTF(&(m1.defaultTextFormatter));
	m1.defaultTextFormatter.textfor.vptr=MultipliervirtTable;
	m1.times=4;
	printf("--- Multiplier CTOR: times = %d\n", m1.times);
	DefaultTextFormatter d2;
	DefaultTextFormatter_CtorDTFDTF(&d2,&(m1.defaultTextFormatter));
	Multiplier_dtorM(&m1);
    PrePostChecker pr1;
	PrePostChecker_PrePostChecker_ctorPC(&pr1);
	DefaultTextFormatter d3;
	DefaultTextFormatter_CtorDTFDTF(&d3,&(pr1.prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.defaultTextFormatter));
	PrePostChecker_PrePostChecker_dtorPC(&pr1);
	DefaultTextFormatter formatters[] ={d1,d2,d3};

    for (int i = 0; i < 3; ++i)
	{
     	defaultTextFormatter_printDTFc(&formatters[i],"Hello World!");
	}

    printf("\n--- end doFormatterArray() ---\n\n");
}

void doFormatterPtrs()
{
    

	printf("\n--- start doFormatterPtrs() ---\n\n");
    
    PrePostDollarFixer p1;
	PrePostDollarFixer_ctorPPDFcc(&p1,"!!! ", " !!!");
    Multiplier m1;
	DefaultTextFormatter_CtorDTF(&(m1.defaultTextFormatter));
	m1.defaultTextFormatter.textfor.vptr=MultipliervirtTable;
	m1.times=4;
	printf("--- Multiplier CTOR: times = %d\n", m1.times);
    PrePostChecker pr1;
	PrePostChecker_PrePostChecker_ctorPC(&pr1);
    DefaultTextFormatter* pfmt[]={(DefaultTextFormatter*)&p1,(DefaultTextFormatter*)&m1,(DefaultTextFormatter*)&pr1}; 

	for(int i=0; i<3; i++)
	{
    	pfmt[i]->textfor.vptr[1](pfmt[i],"Hello World!");
	}

	for(int i=2; i>=0; i--)
	{
    	pfmt[i]->textfor.vptr[0](pfmt[i]);
	}

    printf("\n--- end doFormatterPtrs() ---\n\n");

}

void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();
    
    for (int i = 0; i < 3; ++i)
        formatters[i].textfor.vptr[1](&formatters[i],"Hello World!");

    for (int i = 0; i < 3; ++i)
	{
        formatters[i].textfor.vptr[0](&formatters[i]);
	}
	free(formatters);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

   	PrePostHashFixer hfix;
	PrePostHashFixer_ctorPPHFi(&hfix ,4);
    runAsPrePostFixerRef((PrePostFixer*)&hfix);
    runAsPrePostDollarFixerRef((PrePostDollarFixer*)&hfix);
    runAsPrePostDollarFixerObj(hfix.prehashdollar);
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");

	PrePostHashFixer_dtorPPHF(&hfix);
	
    return 0;
}



