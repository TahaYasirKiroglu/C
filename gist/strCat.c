#include "stdio.h"

void strCat(const char *hedef ,char *kaynak)
{
	char * pH  ;
    for ( pH = hedef ; (*pH) != '\0'; pH++);//p eofu bulana kadar d�ns�n

	for( ; (* pH = * kaynak) != '\0' ; kaynak++, pH++);//kaynak'�n de�erini pH'e ata
	//e�er ph eof a e�it de�ilse ph ve kaynak adreslerinibir artt�r    
}
int main(void)
{
    char hedef[]={"19Mayis"}, kaynak[]={"Univertesi"};
    strCat(hedef,kaynak);
    printf("%s",hedef);
    
	return 0;
}
