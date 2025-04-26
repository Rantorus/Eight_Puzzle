#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char oyunTablosu[3][3]={'6','5','3','7','1','4','8','2',' '};


void tabloyuYazdir();
void hamleGiris(char hamle);
int kazancKontrol();
int hamleKontrol(int matrisSayaci,int matrisSayaciBos);


int main(void){
	char hamle;
	int sonuc=1;
	int i;
	static int yapilanHamle=0;
	
	
	while(sonuc != 0)
	{
	tabloyuYazdir();
	printf("\nhamle sayisi: %d",yapilanHamle);
	printf("\nBosluga surukleyeceginiz sayi: "); scanf("%s",&hamle);
	hamleGiris(hamle);
	sonuc=kazancKontrol();
	yapilanHamle++;
	}
	
	printf("\nBRAVO KAZANDINIZ\n");
	printf("\nyaptiginiz toplam hamle sayisi: %d",yapilanHamle);
	
	
	return 0;
}

int kazancKontrol()
{
	int i,j;
	int sonuc=1;
	
		if(strcmp(oyunTablosu , "12345678 ")==0)
		{
			sonuc=0;
		}
		
	return sonuc;
}

int hamleKontrol(int matrisSayaci,int matrisSayaciBos)
{
	int sonuc=0;
	
	if(matrisSayaciBos==9)
	{
		if(matrisSayaci==8 || matrisSayaci==6)
		sonuc=1;
	}
	
	if(matrisSayaciBos==8)
	{
		if(matrisSayaci==7 || matrisSayaci==9 || matrisSayaci==5 )
		sonuc=1;
	}
	
	if(matrisSayaciBos==7)
	{
		if(matrisSayaci==4 || matrisSayaci==8  )
		sonuc=1;
	}
	
	if(matrisSayaciBos==6)
	{
		if(matrisSayaci==5 || matrisSayaci==3 || matrisSayaci==9 )
		sonuc=1;
	}
	
	if(matrisSayaciBos==5)
	{
		if(matrisSayaci==2 || matrisSayaci==4 || matrisSayaci==6 || matrisSayaci==8 )
		sonuc=1;
	}
	
	if(matrisSayaciBos==4)
	{
		if(matrisSayaci==1 || matrisSayaci==5 || matrisSayaci==7 )
		sonuc=1;
	}
	
	if(matrisSayaciBos==3)
	{
		if(matrisSayaci==2 || matrisSayaci==6)
		sonuc=1;
	}
	
	if(matrisSayaciBos==2)
	{
		if(matrisSayaci==1 || matrisSayaci==5 || matrisSayaci==3 )
		sonuc=1;
	}
	
	if(matrisSayaciBos==1)
	{
		if(matrisSayaci==4 || matrisSayaci==2)
		sonuc=1;
	}
	
	
	return sonuc;
}

void hamleGiris(char hamle)
{
	
	char matrisHamle;
	char matrisBos;
	int i,j;
	int temp=0,matrisSayaci=0,matrisSayaciBos=0;
	
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			temp++;
			if(oyunTablosu[i][j]==hamle)
			{
				matrisHamle=hamle;
				matrisSayaci=temp;
			} 
		}
		
	}
	
	temp=0;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			temp++;
			if(oyunTablosu[i][j]==' ')
			{
				matrisBos=' ';
				matrisSayaciBos=temp;
			} 
		}
		
	}
	
	//printf("matris:%d deger:%c\n",matrisSayaci,matrisHamle);
	//printf("matris:%d deger:%c\n",matrisSayaciBos,matrisBos);
	
	int sonuc=hamleKontrol(matrisSayaci,matrisSayaciBos);
	
	
	if(sonuc==1)
	{
	char *ptr=oyunTablosu;
	*(ptr+matrisSayaciBos-1)=matrisHamle;
	*(ptr+matrisSayaci-1)=matrisBos;
	
	tabloyuYazdir();
	}
	else
	{
		printf("sadece bosluga temas eden sayilari girebilirsiniz ! ");
		sleep(2);
		tabloyuYazdir();
	}
	
	
}

void tabloyuYazdir()
{
	int i,j;
	
	system("cls");
	for(i=0;i<3;i++)
	{
		printf("\n\t") ;
		for(j=0;j<3;j++)
		{
			printf("%c\t",oyunTablosu[i][j]);
		}
		printf("\n\n");
	}
	
}
