#include <stdio.h>
#include "mystring.h"

int main(){
    printf("%d\n", len("686f6c61")); //(2^31)
	printf("%s\n", alphabet("686f6c61")); 
	printf("%s\n", concat("hola", "mun0d\n\t o"));
	printf("%d\n", len(concat("hola", "mun0d\n\t o")));
	printf("%s\n",spow("asd",3));
	printf("%d\n",len(spow("asd",3)));
	printf("%s\n", inverse("evausabarimel"));
	printf("%d\n", len(inverse("evausabarimel")));
	printf("%d\n", ocurrences('6', "686f6c61"));
	printf("%d\n", equal("Hola", "hola"));
	printf("%d\n", equal("hola", "hola"));
	printf("%d\n", equal("holas", "hola"));
    return 0;
}