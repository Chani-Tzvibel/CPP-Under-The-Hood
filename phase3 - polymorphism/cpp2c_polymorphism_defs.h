#include <stdio.h>
#define DOLLAR_DEFAULT_SYMBOL '$'
#define HASH_DEFAULT_SYMBOL  '#'
#define FLOAT_DEFAULT_SYMBOL  '@'

typedef void (*myfunction)(void*,...);

typedef struct
{ 
	myfunction* vptr;
}TextFormatter;

typedef struct
{
	TextFormatter textfor;
	int id;
}DefaultTextFormatter;

typedef struct
{
	DefaultTextFormatter defaultTextFormatter;
	char* pre;
    char* post;

}PrePostFixer;


typedef struct
{
	PrePostFixer prePostFixerDollar;
} PrePostDollarFixer;

typedef struct
{
	PrePostDollarFixer prehashdollar;
	int precision;
}PrePostHashFixer;


typedef struct 
{
	PrePostDollarFixer prePostDollarFixer;

}PrePostFloatDollarFixer;

typedef struct 
{
	PrePostFloatDollarFixer prePostFloatDollarFixer;
}PrePostChecker;

typedef struct 
{
	DefaultTextFormatter defaultTextFormatter;
	int times;
}Multiplier;

void TextFormatter_dtorTF(TextFormatter *this);

void DefaultTextFormatter_CtorDTF(DefaultTextFormatter *this);
void DefaultTextFormatter_CtorDTFDTF(DefaultTextFormatter *this,const DefaultTextFormatter* other);
DefaultTextFormatter* asigmentOperatorDTFDTF (DefaultTextFormatter *this,const DefaultTextFormatter* other);
void defaultTextFormatter_dtorDTF(DefaultTextFormatter *this);
void defaultTextFormatter_printDTFc(const DefaultTextFormatter const *this,const char* text);

DefaultTextFormatter* generateFormatterArray();

void PrePostFixer_ctorPPcc(PrePostFixer *this,const char* prefix, const char* postfix);
void PrePostFixer_dtorPP(PrePostFixer *this);
void PrePostFixer_printPPc(const PrePostFixer const *this,const char* text);
void PrePostFixer_printPPlc(const PrePostFixer const *this,long num, char symbol);
char PrePostFixer_getDefaultSymbolPP(const PrePostFixer const *this);

void PrePostDollarFixer_ctorPPDFcc(PrePostDollarFixer *this,const char* prefix, const char* postfix);
void PrePostDollarFixer_ctorPPDFPPDF(PrePostDollarFixer *this,const PrePostDollarFixer* other);
void PrePostDollarFixer_dtorPPDF(PrePostDollarFixer *this);
void PrePostDollarFixer_printPPDFic(const PrePostDollarFixer const *this,int num, char symbol);
void PrePostDollarFixer_printPPDFlc(const PrePostDollarFixer const *this,long num, char symbol);
void PrePostDollarFixer_printPPDFdc(const PrePostDollarFixer const *this,double num, char symbol);
char PrePostDollarFixer_getDefaultSymbolPPDF(const PrePostDollarFixer const *this);

void PrePostHashFixer_ctorPPHFi(PrePostHashFixer* this ,int prc);
void PrePostHashFixer_dtorPPHF(PrePostHashFixer* this);
void PrePostHashFixer_printPPHFic(const PrePostHashFixer* const this,int num, char symbol);
void PrePostHashFixer_printPPHFlc(const PrePostHashFixer* const this,long num,char symbol);
char PrePostHashFixer_getDefaultSymbolPPHF(const PrePostHashFixer* const this);

void PrePostFloatDollarFixer_ctorPPFDFcc(PrePostFloatDollarFixer *this, const char* prefix, const char* postfix);
void PrePostFloatDollarFixer_dtorPPFDF(PrePostFloatDollarFixer  *this);
void PrePostFloatDollarFixer_printPPFDFf(const PrePostFloatDollarFixer const *this,float num);
void PrePostFloatDollarFixer_printPPFDFfc(const PrePostFloatDollarFixer const *this,float num, char symbol);
char PrePostFloatDollarFixer_getDefaultSymbolPPFDF(const PrePostFloatDollarFixer const *this);

void PrePostChecker_PrePostChecker_ctorPC(PrePostChecker* this);
void PrePostChecker_PrePostChecker_dtorPC(PrePostChecker* this);
void PrePostChecker_printThisSymbolUsingFuncPC(const PrePostChecker* const this);
void PrePostChecker_printThisSymbolDirectlyPC(const PrePostChecker* const this) ;    
void PrePostChecker_printDollarSymbolByCastUsingFuncPC(PrePostChecker* this);
void PrePostChecker_printDollarSymbolByScopeUsingFuncPC(const PrePostChecker* const this);
void PrePostChecker_printDollarSymbolByCastDirectlyPC(const PrePostChecker* const this);
void PrePostChecker_printDollarSymbolByScopeDirectlyPC(const PrePostChecker* const this);



void Multiplier_dtorM(Multiplier* this);
void Multiplier_printMc(const Multiplier* const this,const char*);
