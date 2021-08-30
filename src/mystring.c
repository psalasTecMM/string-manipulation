#include <stdlib.h>
#include <stdio.h>
#include "mystring.h"

int len(char* w){
    int i = 0;
    while((*w++)!='\0'){
        i++;
    }
    return i;
}

char* alphabet(char* string){
	int* dict = (int*)malloc(255);
	char c;
	int n = len(string);
	char* temp = (char*)malloc((n+1)*sizeof(char));
	char* result = temp;
	while((c=*(string++))){
		int* memoryDictDirection = dict+c;
		if(*(memoryDictDirection) != 1){ 			
			*(memoryDictDirection) = 1;
			*(temp++) = c; 
		}
	}
	*temp='\0';
	return result;
}

char* concat(char* string, char* string2){
	int ls1 = len(string); 
	int ls2 = len(string2); 
	char* result = (char*)malloc(sizeof(char)*(ls1+ls2+1));
	char* temp = result;
	char c;
	while((c=*(string++))){
		*(temp++) = c;
	}
	while((c=*(string2++))){
		*(temp++) = c;
	}
	*temp = '\0';
	return result;
}

char* spow(char* string, int n){
    if(n==0) return "";
	return concat(string,spow(string,n-1));
}

char* inverse(char* string){
	int n = len(string); 
	char* result = (char*)malloc((n+1)*sizeof(char));
	char* temp = result; 
	char* tempString = string + n;
	while(tempString!=string){ 
		*(temp++) = *(--tempString);	
	}
	*temp='\0';
	return result;
}

int ocurrences(char symbol, char* string ){
	int counter = 0;
	char c;
	while((c=*(string++))!='\0') 
		if(c == symbol) 
			counter++;
	return counter;
}

int equal(char* string1, char* string2){	
	
	while(*string1!='\0' || *string2!='\0'){
		if(*(string1++)!=*(string2++)) return 0;
	}

	if((*string1 == '\0' && *string2 != '\0') || (*string1 != '\0' && *string2 == '\0')){
		return 0;
	}
	return 1;
}
