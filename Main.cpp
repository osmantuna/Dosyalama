#include <stdlib.h> 
#include <stdio.h>
#include <conio.h> 
#include <string.h> 
#include <windows.h>

void kayitMenu();
void kayitEkle();
void kayitListele();
void kayitAra();
void kayitGuncelle();
void kayitSil();
void menu();
void kirala();
bool kayitAra(char *);
bool filmAra(char *,char *,char *);
void filmEkle();
void filmMenu();
void filmListele();
void teslimEt();

int main()
{
	system("color 0e"); 
	menu(); 

	system("pause"); 
	return 0; 
}

void menu()
{
	do{ 
	system("cls");	
		
		printf("---------------------------------------------------\n");
		printf("| F1  :	Kirala                                    |\n");
		printf("|                                                 |\n");
		printf("| F2  : Teslim Et                                 |\n");
		printf("|                                                 |\n");
		printf("| F3  : Film Menu                                 |\n");
		printf("|                                                 |\n");
		printf("| F4  : Kayit Menu                                |\n");
		printf("|                                                 |\n");
		printf("| ESC : Cikis                                     |\n");
		printf("---------------------------------------------------\n");

		char sec=getche(); 
		printf("\n");
				
		if(sec == 0){
			switch(sec=getche()){
			case 59:
				kirala();
				break;
			case 60:
				teslimEt();
				break;
			case 61:
				filmMenu();
				break;
			case 62:
				kayitMenu();
				break;				
			}
		}
		else if(sec == 27)
			exit(0);
		else{
			printf("Hatali giris yaptiniz. Lutfen gecerli bir tusa basiniz.");
			Sleep(800);
		}	
	}while(1);

}

void kirala()
{
	char kayitt[30];

	system("cls");
	printf("Aranacak TC numarasini giriniz : ");
	scanf("%s", kayitt);
	if(!kayitAra(kayitt))
	{
		printf("TC No bulunamadi. Kayit olmak icin 'e|E'ye basiniz..Cikmak icin herhangi bir tusa basiniz..");
		char secim = getch();
		if(secim == 'e' || secim == 'E')
			kayitEkle();
		else
			return;
	}
	
	char idFilm[30];
	char adFilm[30];
	char sahipFilm[30];
	char bos[30] = "bos";
	printf("\nKiralanacak film id'sini giriniz giriniz giriniz : ");
	scanf("%s", idFilm);

	if(!filmAra(idFilm,adFilm,sahipFilm))
	{
		printf("\nFilm bulunamadi.Eklemek icin 'e|E'ye basiniz.. Cikmak icin herhangi bir tusa basiniz..");
		char secim = getch();
		if(secim == 'e' || secim == 'E')
			filmEkle();
		else
			return;
	}

	if(strcmp(sahipFilm,bos))
	{
		printf("\nBu film zaten baskasina kiralanmis...\n\nDevam etmek icin bir tusa basiniz..");
		getch();
		return;
	}

	FILE *filmDefteri; 
	FILE *geciciFilmDefteri;

	char geciciId[30];
	char geciciAd[30];
	char geciciSahip[30];

    if((filmDefteri=fopen("C:\\filmDefteri.txt","r")) == NULL) 
		printf("Dosya Acilamadi \n"); 
	if ((geciciFilmDefteri=fopen("C:\\geciciFilmDefteri.txt","w+"))==NULL)
		  printf("Dosya Acilamadi \n");  	

	while(!feof(filmDefteri))
	{
		fscanf(filmDefteri, "%s\t%s\t%s\n",geciciId,geciciAd,geciciSahip);
		
		if(!strcmp(idFilm,geciciId))
			fprintf(geciciFilmDefteri, "%s\t%s\t%s\n",idFilm,adFilm,kayitt); 
		else
			fprintf(geciciFilmDefteri, "%s\t%s\t%s\n",geciciId,geciciAd,geciciSahip); 
	} 
	
	printf("\n\nDevam etmek icin bir tusa basiniz...");
	getch();
	
	fclose(filmDefteri);
	fclose(geciciFilmDefteri);
	
	remove ("C:\\filmDefteri.txt"); 
	rename ("C:\\geciciFilmDefteri.txt" , "C:\\filmDefteri.txt");

}

bool filmAra(char *id, char *film, char *sahip)
  {
	  char filmId[30];
	  char filmAdi[30];
	  char kiralayaci[30];  
	  
	  FILE *filmDefteri;
	 
	  if ((filmDefteri=fopen("C:\\filmDefteri.txt","r"))==NULL)
		  printf("Dosya Acilamadi \n");    
	  
	  while(!feof(filmDefteri))
	  {
		  fscanf(filmDefteri, "%s\t%s\t%s\n",filmId,filmAdi,kiralayaci);

		  if(!strcmp(id,filmId))
		  {  
			  strcpy(sahip,kiralayaci);
			  strcpy(film,filmAdi);
			  fclose(filmDefteri);
			  return true;
		  }
	  } 
	  
	  fclose(filmDefteri);
	  return false;
  }

void kayitMenu()
{
	do{ 
	system("cls");	
		
		printf("---------------------------------------------------\n");
		printf("| F1  : Kayit Ekle                                |\n");
		printf("|                                                 |\n");
		printf("| F2  : Kayit Listele                             |\n");
		printf("|                                                 |\n");
		printf("| F3  : Kayit Ara                                 |\n");
		printf("|                                                 |\n");
		printf("| F4  : Kayit Guncelle                            |\n");
		printf("|                                                 |\n");
		printf("| F5  : Kayit Sil                                 |\n");
		printf("|                                                 |\n");
		printf("| F6  : Ana Menuye Don                            |\n");
		printf("|                                                 |\n");
		printf("| ESC : Cikis                                     |\n");
		printf("---------------------------------------------------\n");

		char sec=getche(); 
		printf("\n");
				
		if(sec == 0){
			switch(sec=getche()){
			case 59:
				kayitEkle();
				break;
			case 60:
				kayitListele();
				break;
			case 61:
				kayitAra();
				break;
			case 62:
				kayitGuncelle();
				break;
			case 63:
				kayitSil();
				break;	
			case 64:
				menu();
				break;	
			}
		}
		else if(sec == 27)
			exit(0);
		else{
			printf("Hatali giris yaptiniz. Lutfen gecerli bir tusa basiniz.");
			Sleep(800);
		}	
	}while(1);
}

void kayitEkle()
{
	system("cls");

	char ad[30];
	char soyad[30];
	char tel[30];

    FILE *kayitDefteri; 
    if((kayitDefteri=fopen("C:\\kayitDefteri.txt","a")) == NULL) 
		printf("Dosya Acilamadi \n"); 

	printf("Ad giriniz : ");
	scanf("%s",ad);
	
	printf("Soyad giriniz : ");
	scanf("%s",soyad);
	
	printf("Tel Numarasi giriniz : ");
	scanf("%s",tel);	
	
	fprintf(kayitDefteri, "%s\t%s\t%s\n",ad,soyad,tel); 

	printf("\n\nDevam etmek icin bir tusa basiniz...");
	getch();

	fclose(kayitDefteri); 
}

void filmEkle()
{
	system("cls");

	char film[30];
	char id[30];
	char bos[30] = "bos";

    FILE *filmDefteri; 
    if((filmDefteri=fopen("C:\\filmDefteri.txt","a")) == NULL) 
		printf("Dosya Acilamadi \n"); 

	printf("Film id'sini giriniz : ");
	scanf("%s",id);

	printf("Film adini giriniz : ");
	scanf("%s",film);
	
	fprintf(filmDefteri, "%s\t%s\t%s\n",id,film,bos); 

	printf("\n\nDevam etmek icin bir tusa basiniz...");
	getch();

	fclose(filmDefteri); 
}

void kayitListele()
  {
	  system("cls");
	  printf("Dosyadaki Kayitlar\n\n");
	  
	  FILE *kayitDefteri;
	  
	  char ad[30];
	  char soyad[30];
	  char tc[30];
	 
	  if ((kayitDefteri=fopen("C:\\kayitDefteri.txt","r"))==NULL)
		  printf("Dosya Acilamadi \n");    
	  
	  while(!feof(kayitDefteri)) 
	  {
		  fscanf(kayitDefteri, "%s\t%s\t%s\n",ad,soyad,tc); 
		  printf("%s\t", ad);
		  printf("%s\t", soyad);
		  printf("%s\n", tc);
	  }

	  printf("\n\nDevam etmek icin bir tusa basiniz...");
	  getch();
	  
	  fclose(kayitDefteri);
  }

void filmListele()
  {
	  system("cls");
	  printf("Dosyadaki Filmler\n\n");
	  
	  FILE *filmDefteri;
	  
	  char id[30];
	  char film[30];
	  char sahip[30];
	 
	  if ((filmDefteri=fopen("C:\\filmDefteri.txt","r"))==NULL)
		  printf("Dosya Acilamadi \n");    
	  
	  while(!feof(filmDefteri)) 
	  {
		  fscanf(filmDefteri, "%s\t%s\t%s\n",id,film,sahip); 
		  printf("%s\t", id);
		  printf("%s\t", film);
		  printf("%s\n", sahip);
	  }

	  printf("\n\nDevam etmek icin bir tusa basiniz...");
	  getch();
	  
	  fclose(filmDefteri);
  }

void kayitAra()
  {
	  char aranacakTC[30];

	  system("cls");
	  printf("Aranacak tel numarasini giriniz : ");
	  scanf("%s", aranacakTC);
	  
	  FILE *kayitDefteri;
	  
	  char ad[30];
	  char soyad[30];
	  char tc[30];
	 
	  if ((kayitDefteri=fopen("C:\\kayitDefteri.txt","r"))==NULL)
		  printf("Dosya Acilamadi \n");    
	  
	  while(!feof(kayitDefteri))
	  {
		  fscanf(kayitDefteri, "%s\t%s\t%s\n",ad,soyad,tc);

		  if(!strcmp(aranacakTC,tc))
		  {    
			   printf("\n%s\t", ad);
			   printf("%s\t", soyad);
			   printf("%s\n", tc);
			   
			   printf("\nKiraladigi filmler\n");

			   char filmId[30];
			   char filmAdi[30];
			   char kiralayaci[30];  
	  
			   FILE *filmDefteri;
	 
			   if ((filmDefteri=fopen("C:\\filmDefteri.txt","r"))==NULL)
				   printf("Dosya Acilamadi \n");    
	  
			   while(!feof(filmDefteri))
			   {
				   fscanf(filmDefteri, "%s\t%s\t%s\n",filmId,filmAdi,kiralayaci);
					  
				   if(!strcmp(kiralayaci,tc))
				   {  
					   printf("\n%s\t", filmId);
					   printf("%s\n", filmAdi);
				   }
			   } 			   
			   fclose(filmDefteri);
		  }
	  } 

	  printf("\n\nDevam etmek icin bir tusa basiniz...");
	  getch();
	  
	  fclose(kayitDefteri);
  }

bool kayitAra(char *kayit)
  {
	  char aranacakTel[30];

	  strcpy(aranacakTel,kayit);

	  FILE *kayitDefteri;
	  
	  char ad[30];
	  char soyad[30];
	  char tel[30];
	 
	  if ((kayitDefteri=fopen("C:\\kayitDefteri.txt","r"))==NULL)
		  printf("Dosya Acilamadi \n");    
	  
	  while(!feof(kayitDefteri))
	  {
		  fscanf(kayitDefteri, "%s\t%s\t%s\n",ad,soyad,tel);

		  if(!strcmp(aranacakTel,tel))
		  {    
			   printf("\n%s\t", ad);
			   printf("%s\t", soyad);
			   printf("%s\n", tel);
			   fclose(kayitDefteri);
			   return true;
		  }
	  } 
	  
	  fclose(kayitDefteri);
	  return false;
  }

void kayitGuncelle()
  {
	  char aranacakTel[30];

	  system("cls");
	  printf("Degistirmek istediginiz kayidin tel numarasini giriniz : ");
	  scanf("%s", aranacakTel);
	  
	  FILE *kayitDefteri;
	  FILE *geciciKayitDefteri; 
	  
	  char ad[30];
	  char soyad[30];
	  char tel[30];

	  char geciciAd[30];
	  char geciciSoyad[30];
	 
	  if ((kayitDefteri=fopen("C:\\kayitDefteri.txt","r"))==NULL)
		  printf("Dosya Acilamadi \n");    
	   if ((geciciKayitDefteri=fopen("C:\\geciciKayitDefteri.txt","w+"))==NULL)
		  printf("Dosya Acilamadi \n");  
	  
	  while(!feof(kayitDefteri))
	  {
		  fscanf(kayitDefteri, "%s\t%s\t%s\n",ad,soyad,tel);

		  if(!strcmp(aranacakTel,tel))
		  {    
			   printf("\n%s\t", ad);
			   printf("%s\t", soyad);
			   printf("%s\n", tel);

			   printf("\nYeni isim giriniz : ");
			   scanf("%s",&geciciAd);
			   
			   printf("Yeni soyisim giriniz : ");
			   scanf("%s",&geciciSoyad);			   

			   fprintf(geciciKayitDefteri, "%s\t%s\t%s\n",geciciAd,geciciSoyad,tel); 
		  }
		  else
			  fprintf(geciciKayitDefteri, "%s\t%s\t%s\n",ad,soyad,tel); 
	  } 

	  printf("\n\nDevam etmek icin bir tusa basiniz...");
	  getch();
	  
	  fclose(kayitDefteri);
	  fclose(geciciKayitDefteri);

	  remove ("C:\\kayitDefteri.txt"); 
	  rename ("C:\\geciciKayitDefteri.txt" , "C:\\kayitDefteri.txt");
  }

void kayitSil()
  {
	  char aranacakTC[30];

	  system("cls");
	  printf("Silmek istediginiz kayidin TC numarasini giriniz : ");
	  scanf("%s", aranacakTC);
	  
	  FILE *kayitDefteri;
	  FILE *geciciKayitDefteri;
	  
	  char ad[30];
	  char soyad[30];
	  char tc[30];	 
	 
	  if ((kayitDefteri=fopen("C:\\kayitDefteri.txt","r"))==NULL)
		  printf("Dosya Acilamadi \n");    
	   if ((geciciKayitDefteri=fopen("C:\\geciciKayitDefteri.txt","w+"))==NULL)
		  printf("Dosya Acilamadi \n");  
	  
	  while(!feof(kayitDefteri))
	  {
		  fscanf(kayitDefteri, "%s\t%s\t%s\n",ad,soyad,tc);

		  if(!strcmp(aranacakTC,tc))
		  {    
			   printf("\n%s\t", ad);
			   printf("%s\t", soyad);
			   printf("%s\n", tc);
		  }
		  else
			  fprintf(geciciKayitDefteri, "%s\t%s\t%s\n",ad,soyad,tc);
	  } 

	  printf("\nSilmek istediginize emin misiniz ? ( Evet: e|E )");

	  char secim = getch();

	  if(secim == 'e' || secim == 'E')
	  {
		  fclose(kayitDefteri);
		  fclose(geciciKayitDefteri);

	      remove ("C:\\kayitDefteri.txt");
		  rename ("C:\\geciciKayitDefteri.txt" , "C:\\kayitDefteri.txt");
	  }
	  else
	  {
		  fclose(kayitDefteri);
		  fclose(geciciKayitDefteri);

		  remove ("C:\\geciciKayitDefteri.txt");
	  }

	  printf("\n\nDevam etmek icin bir tusa basiniz...");
	  getch();   
	  
  }

void filmMenu()
{
	do{ 
	system("cls");	
		
		printf("---------------------------------------------------\n");
		printf("| F1  : Film Ekle                                 |\n");
		printf("|                                                 |\n");
		printf("| F2  : Film Listele                              |\n");
		printf("|                                                 |\n");
		printf("| F3  : Ana Menuye Don                            |\n");
		printf("|                                                 |\n");
		printf("| ESC : Cikis                                     |\n");
		printf("---------------------------------------------------\n");

		char sec=getche(); 
		printf("\n");
				
		if(sec == 0){
			switch(sec=getche()){
			case 59:
				filmEkle();
				break;
			case 60:
				filmListele();
				break;
			case 61:
				menu();
				break;		
			}
		}
		else if(sec == 27)
			exit(0);
		else{
			printf("Hatali giris yaptiniz. Lutfen gecerli bir tusa basiniz.");
			Sleep(800);
		}	
	}while(1);
}

void teslimEt()
{
	char idFilm[30];
	char adFilm[30];
	char sahipFilm[30];
	char bos[30] = "bos";

	system("cls");
	printf("Teslim etmek istediginiz kitabin id'sini giriniz : ");
	scanf("%s", idFilm);	

	if(!filmAra(idFilm,adFilm,sahipFilm))
	{
		printf("\nFilm bulunamadi.Eklemek icin 'e|E'ye basiniz.. Cikmak icin herhangi bir tusa basiniz..");
		char secim = getch();
		if(secim == 'e' || secim == 'E')
			filmEkle();
		else
			return;
	}

	if(!strcmp(sahipFilm,bos))
	{
		printf("\nBu film zaten rafta...\n\nDevam etmek icin bir tusa basiniz..");
		getch();
		return;
	}

	FILE *filmDefteri; 
	FILE *geciciFilmDefteri;

	char geciciId[30];
	char geciciAd[30];
	char geciciSahip[30];

    if((filmDefteri=fopen("C:\\filmDefteri.txt","r")) == NULL) 
		printf("Dosya Acilamadi \n"); 
	if ((geciciFilmDefteri=fopen("C:\\geciciFilmDefteri.txt","w+"))==NULL)
		  printf("Dosya Acilamadi \n");  	

	while(!feof(filmDefteri))
	{
		fscanf(filmDefteri, "%s\t%s\t%s\n",geciciId,geciciAd,geciciSahip);
		
		if(!strcmp(idFilm,geciciId))
			fprintf(geciciFilmDefteri, "%s\t%s\t%s\n",idFilm,adFilm,bos); 
		else
			fprintf(geciciFilmDefteri, "%s\t%s\t%s\n",geciciId,geciciAd,geciciSahip); 
	} 
	
	printf("\n\nDevam etmek icin bir tusa basiniz...");
	getch();
	
	fclose(filmDefteri);
	fclose(geciciFilmDefteri);
	
	remove ("C:\\filmDefteri.txt"); 
	rename ("C:\\geciciFilmDefteri.txt" , "C:\\filmDefteri.txt");
}