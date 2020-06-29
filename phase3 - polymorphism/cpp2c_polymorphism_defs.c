#include <malloc.h>
#include <string.h>
#include "cpp2c_polymorphism_defs.h"

myfunction textFormatterVirtTable[]={(myfunction)TextFormatter_dtorTF,(myfunction)NULL};
myfunction defaultTextFormatterVirtTable[]={(myfunction)defaultTextFormatter_dtorDTF,(myfunction)defaultTextFormatter_printDTFc};
myfunction prePostFixerVirtTabl[]={(myfunction)PrePostFixer_dtorPP,(myfunction)PrePostFixer_printPPc,(myfunction)PrePostFixer_printPPlc,(myfunction) PrePostFixer_getDefaultSymbolPP};
myfunction prePostDollarFixerVirtTabl[]={(myfunction)PrePostDollarFixer_dtorPPDF,(myfunction)PrePostFixer_printPPc,(myfunction)PrePostDollarFixer_printPPDFlc,(myfunction)PrePostDollarFixer_getDefaultSymbolPPDF};
myfunction PrePostHashFixerVirtTabl[]={(myfunction)PrePostHashFixer_dtorPPHF,(myfunction)PrePostFixer_printPPc,(myfunction)PrePostHashFixer_printPPHFlc,(myfunction)PrePostHashFixer_getDefaultSymbolPPHF};
myfunction PrePostFloatDollarFixervirtTable[]={(myfunction)PrePostFloatDollarFixer_dtorPPFDF,(myfunction)PrePostFixer_printPPc,(myfunction)PrePostDollarFixer_printPPDFlc,(myfunction)PrePostFloatDollarFixer_getDefaultSymbolPPFDF};
myfunction PrePostCheckercirtTable[]={(myfunction)PrePostChecker_PrePostChecker_dtorPC,(myfunction)PrePostFixer_printPPc,(myfunction)PrePostDollarFixer_printPPDFlc,(myfunction)PrePostFloatDollarFixer_getDefaultSymbolPPFDF};
myfunction MultipliervirtTable[]={(myfunction)Multiplier_dtorM,(myfunction)Multiplier_printMc};




int ider_next_id=0;

void TextFormatter_dtorTF(TextFormatter *this){}

void defaultTextFormatter_dtorDTF(DefaultTextFormatter *this)
{
	printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
	this->textfor.vptr=textFormatterVirtTable;
	TextFormatter_dtorTF(&(this->textfor));
}

void DefaultTextFormatter_CtorDTF(DefaultTextFormatter *this)
{
	this->textfor.vptr=defaultTextFormatterVirtTable;
	this->id=ider_next_id++;
	printf("--- DefaultTextFormatter CTOR\n########## C %d ##########\n", this->id);
}

void DefaultTextFormatter_CtorDTFDTF(DefaultTextFormatter *this,const DefaultTextFormatter* other)
{
	this->textfor.vptr=other->textfor.vptr;
	this->id=ider_next_id++;
	 printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}

DefaultTextFormatter* asigmentOperatorDTFDTF(DefaultTextFormatter *this,const DefaultTextFormatter* other)
{
	printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}

void defaultTextFormatter_printDTFc(const DefaultTextFormatter const *this,const char* text)
{
	printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
	printf("%s\n", text); 
}

DefaultTextFormatter* generateFormatterArray()
{
	DefaultTextFormatter* arr=malloc(sizeof(DefaultTextFormatter)*3);
	DefaultTextFormatter d1,d2,d3;
	DefaultTextFormatter_CtorDTF(&d1);
	DefaultTextFormatter_CtorDTF(&d2);
	DefaultTextFormatter_CtorDTF(&d3);
	arr[0]=d1;
	arr[1]=d2;
	arr[2]=d3;
	return arr;
	
}

void PrePostFixer_ctorPPcc(PrePostFixer *this,const char* prefix, const char* postfix)
{
	DefaultTextFormatter_CtorDTF(&(this->defaultTextFormatter));
	this->defaultTextFormatter.textfor.vptr=prePostFixerVirtTabl;
	this->pre=prefix;
    this->post=postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void PrePostFixer_dtorPP(PrePostFixer *this)
{
	printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	this->defaultTextFormatter.textfor.vptr=defaultTextFormatterVirtTable;
	defaultTextFormatter_dtorDTF(&(this->defaultTextFormatter));
}

void PrePostFixer_printPPc(const PrePostFixer const *this,const char* text)
{
	printf("%-60s | ", "[PrePostFixer::print(const char*)]");
	
	printf("%s%s%s\n",this->pre,text,this->post);
}

void PrePostFixer_printPPlc(const PrePostFixer const *this,long num, char symbol)
{
	printf("%-60s | ", "[PrePostFixer::print(long, char)]");
	printf("-->\n");
    
    if (symbol)
	{		    
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");  
    	printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
	}
    else
	{
        printf("%-60s | ", "[PrePostFixer::print_num(long)]"); 
    	printf("%s%ld%s\n", this->pre, num, this->post);
	}
}

char PrePostFixer_getDefaultSymbolPP(const PrePostFixer const *this)
{
	return '\0';
}


void PrePostDollarFixer_ctorPPDFcc(PrePostDollarFixer *this,const char* prefix, const char* postfix)
{
	PrePostFixer_ctorPPcc(&(this->prePostFixerDollar),prefix,postfix);
	this->prePostFixerDollar.defaultTextFormatter.textfor.vptr=prePostDollarFixerVirtTabl;
	printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->prePostFixerDollar.pre, this->prePostFixerDollar.post);
}
void PrePostDollarFixer_ctorPPDFPPDF(PrePostDollarFixer *this,const PrePostDollarFixer* other)
{
	DefaultTextFormatter_CtorDTFDTF(&(this->prePostFixerDollar.defaultTextFormatter),&(other->prePostFixerDollar.defaultTextFormatter));
	this->prePostFixerDollar.defaultTextFormatter.textfor.vptr=prePostFixerVirtTabl;
	this->prePostFixerDollar.pre=other->prePostFixerDollar.pre;
	this->prePostFixerDollar.post=other->prePostFixerDollar.post;
	this->prePostFixerDollar.defaultTextFormatter.textfor.vptr=other->prePostFixerDollar.defaultTextFormatter.textfor.vptr;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->prePostFixerDollar.pre, this->prePostFixerDollar.post);
}

void PrePostDollarFixer_dtorPPDF(PrePostDollarFixer *this)
{
	    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->prePostFixerDollar.pre, this->prePostFixerDollar.post);
		this->prePostFixerDollar.defaultTextFormatter.textfor.vptr=prePostFixerVirtTabl;
		PrePostFixer_dtorPP(&(this->prePostFixerDollar));
}

void PrePostDollarFixer_printPPDFic(const PrePostDollarFixer const *this,int num, char symbol)
{
	printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    this->prePostFixerDollar.defaultTextFormatter.textfor.vptr[2](this,(long)num,symbol);
}


void PrePostDollarFixer_printPPDFlc(const PrePostDollarFixer const *this,long num, char symbol)
{
	printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
	PrePostFixer_printPPlc(&(this->prePostFixerDollar),num,symbol);

}

void PrePostDollarFixer_printPPDFdc(const PrePostDollarFixer const *this,double num, char symbol)
{
	printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", this->prePostFixerDollar.pre, symbol, num, this->prePostFixerDollar.post);

}

char PrePostDollarFixer_getDefaultSymbolPPDF(const PrePostDollarFixer const *this)
{
	return DOLLAR_DEFAULT_SYMBOL;
}


void PrePostHashFixer_ctorPPHFi(PrePostHashFixer* this ,int prc)
{
	PrePostDollarFixer_ctorPPDFcc((PrePostDollarFixer*)this,"===> ", " <===");
	this->prehashdollar.prePostFixerDollar.defaultTextFormatter.textfor.vptr=PrePostHashFixerVirtTabl;
	this->precision=prc;
	printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n",this->prehashdollar.prePostFixerDollar.pre, this->prehashdollar.prePostFixerDollar.post, this->precision);   
	
	printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->prehashdollar.prePostFixerDollar.pre, HASH_DEFAULT_SYMBOL, this->precision, 9999.9999, this->prehashdollar.prePostFixerDollar.post);

}
void PrePostHashFixer_dtorPPHF(PrePostHashFixer* this)
{
	printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->prehashdollar.prePostFixerDollar.pre, this->prehashdollar.prePostFixerDollar.post);
	this->prehashdollar.prePostFixerDollar.defaultTextFormatter.textfor.vptr=prePostDollarFixerVirtTabl;
	PrePostDollarFixer_dtorPPDF((PrePostDollarFixer*)this);
}
void PrePostHashFixer_printPPHFic(const PrePostHashFixer* const this,int num, char symbol)
{
	printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->prehashdollar.prePostFixerDollar.pre, symbol, this->precision,(double)num, this->prehashdollar.prePostFixerDollar.post);

}
void PrePostHashFixer_printPPHFlc(const PrePostHashFixer* const this,long num, char symbol)
{
	printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");
	
	printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->prehashdollar.prePostFixerDollar.pre, symbol, this->precision,(double)num, this->prehashdollar.prePostFixerDollar.post);
   
}
char PrePostHashFixer_getDefaultSymbolPPHF(const PrePostHashFixer* const this)
{
	return HASH_DEFAULT_SYMBOL;
}

void PrePostFloatDollarFixer_ctorPPFDFcc(PrePostFloatDollarFixer *this, const char* prefix, const char* postfix)
{
	PrePostDollarFixer_ctorPPDFcc(&(this->prePostDollarFixer),prefix,postfix);
	this->prePostDollarFixer.prePostFixerDollar.defaultTextFormatter.textfor.vptr=PrePostFloatDollarFixervirtTable;
	printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n",this->prePostDollarFixer.prePostFixerDollar.pre, this->prePostDollarFixer.prePostFixerDollar.post);
}
void PrePostFloatDollarFixer_dtorPPFDF(PrePostFloatDollarFixer *this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->prePostDollarFixer.prePostFixerDollar.pre,this->prePostDollarFixer.prePostFixerDollar.post);
	this->prePostDollarFixer.prePostFixerDollar.defaultTextFormatter.textfor.vptr=prePostDollarFixerVirtTabl;
	PrePostDollarFixer_dtorPPDF(&(this->prePostDollarFixer));

}
void PrePostFloatDollarFixer_printPPFDFf(const PrePostFloatDollarFixer const *this,float num)
{
	printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    PrePostFloatDollarFixer_printPPFDFfc(this,num,FLOAT_DEFAULT_SYMBOL);

}
void PrePostFloatDollarFixer_printPPFDFfc(const PrePostFloatDollarFixer const *this,float num, char symbol)
{
	printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");
    printf("%s%c%.2f%s\n", this->prePostDollarFixer.prePostFixerDollar.pre, symbol, num, this->prePostDollarFixer.prePostFixerDollar.post);

}
char PrePostFloatDollarFixer_getDefaultSymbolPPFDF(const PrePostFloatDollarFixer const *this)
{
	return FLOAT_DEFAULT_SYMBOL;

}


void PrePostChecker_PrePostChecker_ctorPC(PrePostChecker* this)
{
	PrePostFloatDollarFixer_ctorPPFDFcc((PrePostFloatDollarFixer*)this,"[[[[ ", " ]]]]");
	this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.defaultTextFormatter.textfor.vptr=PrePostCheckercirtTable;    
	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.pre, this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.post);
}
void PrePostChecker_PrePostChecker_dtorPC(PrePostChecker* this)
{
	    printf("--- PrePostChecker DTOR: \"%s\"...\"%s\"\n", this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.pre, this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.post);
	this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.defaultTextFormatter.textfor.vptr=PrePostFloatDollarFixervirtTable;    
	PrePostFloatDollarFixer_dtorPPFDF((PrePostFloatDollarFixer*)this);
}
void PrePostChecker_printThisSymbolUsingFuncPC(const PrePostChecker* const this)
{

	printf("%-60s | ","[PrePostChecker::printThisSymbolUsingFunc()]");
	printf("Default symbol is %c\n",((char(*)(const void* const))(this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.defaultTextFormatter.textfor.vptr[3]))(this));

}
void PrePostChecker_printThisSymbolDirectlyPC(const PrePostChecker* const this)
{
	printf("%-60s | ","[PrePostChecker::printThisSymbolDirectly()]");
	
    printf("Default symbol is %c\n", FLOAT_DEFAULT_SYMBOL);
}
   
void PrePostChecker_printDollarSymbolByCastUsingFuncPC(PrePostChecker* this)
{
	printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
	this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.defaultTextFormatter.textfor.vptr=PrePostFloatDollarFixervirtTable;
    printf("Default symbol is %c\n", ((char(*)(const void* const))(this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.defaultTextFormatter.textfor.vptr[3]))(this));
	this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixerDollar.defaultTextFormatter.textfor.vptr=PrePostCheckercirtTable;

}
void PrePostChecker_printDollarSymbolByScopeUsingFuncPC(const PrePostChecker* const this)
{
	printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
	
    printf("Default symbol is %c\n", PrePostDollarFixer_getDefaultSymbolPPDF(&(this->prePostFloatDollarFixer.prePostDollarFixer)));

}
void PrePostChecker_printDollarSymbolByCastDirectlyPC(const PrePostChecker* const this)
{
	printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");
	
    printf("Default symbol is %c\n", DOLLAR_DEFAULT_SYMBOL);
}

void PrePostChecker_printDollarSymbolByScopeDirectlyPC(const PrePostChecker* const this)
{
	printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeDirectly()]");
	
    printf("Default symbol is %c\n", DOLLAR_DEFAULT_SYMBOL);
}


void Multiplier_dtorM(Multiplier* this)
{
	    printf("--- Multiplier DTOR: times = %d\n", this->times);
		this->defaultTextFormatter.textfor.vptr=defaultTextFormatterVirtTable;
		defaultTextFormatter_dtorDTF(&(this->defaultTextFormatter));
}
void Multiplier_printMc(const Multiplier* const this,const char* text)
{
    printf("%-60s | ","[Multiplier::print(const char*)]");
	
    for (int i = 0; i < this->times; ++i)
	{
        printf("%s", text);
	}
    printf("\n");
}

