#include <stdio.h>
//kalp �ekli ��karan c program�
void bas(int sayi)
{
	int j;
	for( j=0 ; j<sayi ; j++ )//bosluk bas
		putchar(' ');
	putchar('*');//d�ng�den sonra * koy
}
int kalp_bas(void){
	int i,bosluk;
	for( i=3 ; i<15 ; i++ )//normalde deltoid oldu�u i�in
 	{
   		if( (i<7) || (i==14) )//ba� bo�luk i�in
   	 		bosluk = 7-(i%7);
   	 	else
   	    	bosluk = i%7;
	 	bas(bosluk); //bosluk bas
	 	bosluk = 2*(7-bosluk)-1; //son bosluk i�in
    	if((i>6) || (i==3)){//ara bosluklar i�in
    	
	         if(i!=14)
   	         bas(bosluk);
   	    }
   	 	else{
  	 		bas(2*i-7);//ilk ara bosluk
   	    	if(i!=6)//i=6'y� hari� tut
   	    		bas((2*i-1)%4);//orta ara bosluk 
   	 		bas(2*i-7);//son ara bosluk
 	 	}
   	 	printf("\n");//alt sat�ra ge�
 	}
}
int main( ){ 
	kalp_bas();
	return 0;
}

