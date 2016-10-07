#include <stdio.h>
#include <stdlib.h> //system() i�in
#include <windows.h> // isimlendirme icin
#include <locale.h> // turkce dili icin
#include <conio.h> // getch icin
/* tab = 4 bosluk olarak yazilmistir.*/

// GEL�ST�R�LECEKLER
// $$ sadece getch fonksiyonu kullanilarak performans arttirilacak
// $$ firewall ayarlari konusu tartisilacak 

void UYARI( int tur ){
		system("@cls");
	switch(tur){
		case 'b': // baglantiyla alakali
			printf("\n\n\n\n%8s->Kablolu ba�lant� i�in:","");
				printf(" Ba�lant�lar� kontrol ediniz...");
			printf("\n\n%8s->Kablosuz ba�lant� i�in:","");
				printf(" Kablosuz ayarlar�n�z� kontrol ediniz...","");
			printf("\n\n\n\n%8s->Ba�lant�n�z� kontrol ettikten sonra sorun devam ederse,","");
			printf("\n\n%10s program� tekrar �al��t�r�n�z...","");
			break;
		case 's': // surucuyle alakali
			printf("\n\n\n\n%8sL�tfen internet s�r�c�lerini","");
			printf(" g�ncelleyiniz veya y�kleyiniz...\n");
	}
}
void devam_mi(void){
	char cevap = 0;
	printf("\n\n\n%8sDevam etmek i�in bir tu�a bas�n�z...","");
	cevap=getch();
}
int evet_hayir(void){
	int elcevap = 0;
	printf("(e/h)");
	do{
		elcevap=getch();
	}while((elcevap!='e')&&(elcevap!='E')&&(elcevap!='h')&&(elcevap!='H'));
		printf("%c\n", elcevap );
	if(elcevap == 'E')
		elcevap ='e';
	else if(elcevap == 'H')
		elcevap = 'h';
	return (elcevap=='e')?'e':'h';
}
int kontrol(void){
	int cevap = 0;
	system("@cls");
	printf("\n\n\n\n\n\n%12sL�tfen birka� dakika bekledikten sonra cevap veriniz...","");
	printf("\n\n\n%12sAyarlar sonucunda internet ba�lant�n�z geldi mi?","");
	cevap = evet_hayir();
	return cevap;
}
int analiz_et(void){
	int cevap = 0;
	system("@cls");
	printf("\n\n\n\n\n%8s�nternet ba�lant�n�z var m�?","");
	if(evet_hayir()=='h'){
		printf("\n\n\n\n\n%8sDaha �nceden internet ba�lant�n�z var m�yd�?","");
		if(evet_hayir()=='e'){
				cevap = basitNetCozumu(); // cozmeye ugras	
			if( cevap ){
				UYARI('b'); // baglantiyla alakali problem oldugunu bildir
			}
			else{
				cevap = kontrol(); // islemin dogrulugunu kontrol et
				if(cevap == 'h'){ // sorun cozulmediyse diger cozumu dene
						cevap = karisikNetCozumu(); // cozmeye ugras
					cevap = cevap?kontrol():0; 
				}
				else
					cevap = 0;
			}
		}
		else{
			UYARI('b'); // baglantiyla alakali problem oldugunu bildir
			cevap = 0;
			devam_mi();
		}
	}
	else{
		cevap = 0;
		UYARI('s');
		devam_mi();
	}
	return cevap;
}
int basitNetCozumu(void){
	system("@cls");
	printf("\n%s->  L�tfen bekleyiniz...\n\n","");
	printf("\n\n%s--->  �nbellek temizleniyor...\n\n","");
		system("ipconfig /flushdns");
	printf("\n\n%s----->  Ge�ersiz ip siliniyor...\n\n","");
		system("ipconfig /release");
	printf("\n\n%s------->  Yeni ip al�n�yor...\n\n","");
		system("ipconfig /renew");
	devam_mi();
	return 0;
}
int karisikNetCozumu(void){
	system("@cls");
	printf("\n%s->  L�tfen bekleyiniz...\n\n","");
	printf("\n\n%s--->  Arabirim s�f�rlan�yor...\n\n","");
		system("netsh int ip reset a.txt");
	printf("\n\n%s--->  Winsock katalo�u s�f�rlan�yor...\n\n","");
		system("netsh winsock reset");
	printf("\n\n%s--->  Proxy ayarlar� s�f�rlan�yor...\n\n","");
		system("netsh winhttp reset proxy");
//	printf("\n\n%s----->  G�venlik duvar� ayarlar� s�f�rlan�yor...\n\n","");
//		system("netsh advfirewall reset");
	printf("\n\n%s------->  �nbellek temizleniyor...\n\n","");	
		system("ipconfig /flushdns");
	printf("\n\n%s--------->  Ge�ersiz ip siliniyor...\n\n","");
		system("ipconfig /release");
	printf("\n\n%s----------->  Yeni ip al�n�yor...\n\n","");
		system("ipconfig /renew");
	devam_mi();
	return 0;
}
int main(){
	system("COLOR 57");// konsol rengini degistir
	setlocale(LC_ALL,"Turkish"); //turkce karakterler icin
	SetConsoleTitle("Internet Sorun Cozucu v1.0");
	int cevap;
	cevap=analiz_et();
	system("@cls"); // ekrani temizle
	printf("\n\n\n\n\n\n\n");
	switch( cevap ){
		case 'h': case 1: // analiz_et hata parametreli donerse
			printf("\n\n\n\n%8sProgram ba�ar�l� sonland�r�lamad�!..","");
			break;
		case 'e': case 0: // analiz_et hatasiz donerse
			printf("\n\n%8sProgram ba�ar� �ekilde sonland�r�ld�!..","");
			printf("\n\n%8sE�er internete eri�emezseniz,","");
			printf(" bilgisayar�n�z� yeniden ba�lat�n�z...");
	}
	if( cevap == 'h' )
		printf("\n\n\n\n%8sProgramdan ��kmak i�in bir tu�a bas�n�z...","");
	cevap = getch();
	return 0;
}
// Programin her hakki �ahsima(Taha Yasir Kiroglu) aittir. 
// Program sonucunda olusabilecek aksakliklardan dolayi sorumluluk kabul etmiyorum.
// Ticari olarak bana danisilmasi kaydiyla kullanilabilir.
// Ticari olmayan kullanimlarda kod istenilen sekilde alip kullanilabilir.
