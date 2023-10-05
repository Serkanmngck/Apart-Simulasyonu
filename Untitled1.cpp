#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct kayitlar
{
	char isim[20],soyisim[20],eposta[50],cinsiyet[10],dogumtarihi[20],telefon[25];
	float id=0,tc;
	int kiraborc[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int elektirikborc[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int apartgirisgun,apartgirisay,apartgirisyil,kalinacakay,apartcikisay,apartcikisyil;
	float kirabedeli=900,elektirikbedeli=200;
	
};
int menu();
void kisikayit(struct kayitlar c1);
void borckayit(struct kayitlar c1);
void kayitsil(struct kayitlar c1);
void gunceleme(struct kayitlar c1);
void listeleme(struct kayitlar c1);
void borclistele(struct kayitlar c1);
void kiraborcuode(struct kayitlar c1);
void elektirikborcuode(struct kayitlar c1);
void cikisyap(struct kayitlar c1);
void borcguncelle(struct kayitlar c1,float id);
void borcsil(struct kayitlar c1,float id);

int main()
{
	struct kayitlar c1,c2;
	
	
	int secim=menu();
	
    	while(secim!=8)
   	 {

       	 switch(secim)
        	{
           	 case 1:kisikayit(c1);break;

           	 case 2:kayitsil(c1);break;

           	 case 3:gunceleme(c1);break;

           	 case 4:listeleme(c1);break;

           	 case 5:borclistele(c1);break;

           	 case 6:kiraborcuode(c1);break;

           	 case 7:elektirikborcuode(c1); break;

      	 }
	
      	  secim=menu();
   	 }	
	
	
	return 0;
}

void kisikayit(struct kayitlar c1)
{
	
		FILE *ptr;
		ptr=fopen("kayitlar.txt","a");
		
		printf("isim :");
		scanf(" %[^\n]s", c1.isim) ;
		printf("soyisim :");
		scanf(" %[^\n]s", c1.soyisim) ;
		printf("tc kimlik no: ");
		scanf("%f",&c1.tc);
		printf("id giriniz: ");
		scanf("%f",&c1.id);
		printf("eposta : ");
		scanf("%s",c1.eposta);
		printf("cinsiyet :");
		scanf("%s",c1.cinsiyet);
		printf("dogum tarihi: ");
		scanf("%s",c1.dogumtarihi);
		printf("telefon no:");
		scanf("%s",c1.telefon);
		printf("apart giris gunu:");
		scanf("%d",&c1.apartgirisgun);
		go:
		printf("apart giris ay:");
		scanf("%d",&c1.apartgirisay);
		if (c1.apartgirisay>12)
		{
			printf("\n\nHatali ay girisi yaptiniz.(aylar 1-12)\n\n");
			goto go;
		}
		printf("apart giris yil:");
		scanf("%d",&c1.apartgirisyil);
		go1:
		printf("apart kalinacak ay:");
		scanf("%d",&c1.kalinacakay);
			if(c1.kalinacakay+c1.apartgirisay>23)
		{
			printf("kalinacak ay max %d olabilir.\n\n",(24-c1.apartgirisay));
			goto go1;
		}
		printf("islem tmaam kisi kayit edildi\n\n");
		
		if(c1.kalinacakay+c1.apartgirisay<=12)
		{
			c1.apartcikisay=c1.kalinacakay+c1.apartgirisay;
			c1.apartcikisyil=c1.apartgirisyil;		}
		else if(c1.kalinacakay+c1.apartgirisay<=24)
		{
			c1.apartcikisay=c1.kalinacakay+c1.apartgirisay-12;
			c1.apartcikisyil=c1.apartgirisyil+1;
		}
		else
		{
			c1.apartcikisay=c1.kalinacakay+c1.apartgirisay-24;
			c1.apartcikisyil=c1.apartgirisyil+2;
		}
		
		fprintf(ptr,"%f\t%f\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",c1.id,c1.tc,c1.isim,c1.soyisim,c1.eposta,c1.cinsiyet,c1.dogumtarihi,c1.telefon,c1.apartgirisgun,c1.apartgirisay,c1.apartgirisyil,c1.kalinacakay,c1.apartcikisay,c1.apartcikisyil);
		fclose(ptr);
		borckayit(c1);
		
}

void borckayit(struct kayitlar c1)
{
	FILE *ptr1;
	ptr1=fopen("borckayit.txt","a");
	
	
	for(int i=c1.apartgirisay;i<(c1.apartgirisay+c1.kalinacakay);i++ )
	{
		c1.kiraborc[i]=1;
		c1.elektirikborc[i]=1;
	}
	fprintf(ptr1,"%f\t",c1.id);
	for(int i=0;i<24;i++)
	{
		fprintf(ptr1,"%d\t",c1.kiraborc[i]);
	}
	
	for(int i=0;i<23;i++)
	{
		fprintf(ptr1,"%d\t",c1.elektirikborc[i]);
	}
	
	fprintf(ptr1,"%d\n",c1.elektirikborc[23]);
	fclose(ptr1);
	
	
}

int menu()
{
    int sonuc;
    printf("Yeni kiraci kaydi icin 1'i seciniz.\nOgrenci kaydini silmek icin 2'i seciniz.\nOgrenci bilgilerini guncellemek icin 3'u seciniz\nOgrenci bilgilerini isim sirasi A-Z’ye olacak bicimde listelemek icin 4'u seciniz\nOgrenci borc bilgilerini listelemek icin 5'i seciniz.\nKira borcu odemek icin 6'i seciniz.\nElektrik borcu odemek icin 7'i seciniz.\nCikis yapmak icin 8'i seciniz\n");
    scanf("%d",&sonuc);
    return sonuc;

  
}

void listeleme(struct kayitlar c1)
{
	FILE *ptr;
	
	ptr=fopen("kayitlar.txt","r");
	
	printf("\n----Kayitli kisiler-----\n");
	if(ptr!=NULL)
	{
		while(!feof(ptr))
		{
			fscanf(ptr,"%f\t%f\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.tc,c1.isim,&c1.soyisim,&c1.eposta,&c1.cinsiyet,&c1.dogumtarihi,&c1.telefon,&c1.apartgirisgun,&c1.apartgirisay,&c1.apartgirisyil,&c1.kalinacakay,&c1.apartcikisay,&c1.apartcikisyil);
			printf("%.0f %.0f %s %s %s %s %s %s %d.%d.%d %d.%d.%d\n",c1.id,c1.tc,c1.isim,c1.soyisim,c1.eposta,c1.cinsiyet,c1.dogumtarihi,c1.telefon,c1.apartgirisgun,c1.apartgirisay,c1.apartgirisyil,c1.apartgirisgun,c1.apartcikisay,c1.apartcikisyil);
			
			
		}
		
		fclose(ptr);
		
	}
	printf("\n");
}
void kayitsil(struct kayitlar c1)
{
	FILE *ptr,*ptr1,*ptr2;
	float id;
	ptr1=fopen("kayitlar.txt","r");
	ptr=fopen("kayitlar.txt","r");
	ptr2=fopen("temp.txt","w");
		if(ptr1!=NULL)
	{	
		printf("----idler----\n");
		while(!feof(ptr1))
		{
			
			fscanf(ptr1,"%f\t%f\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.tc,c1.isim,&c1.soyisim,&c1.eposta,&c1.cinsiyet,&c1.dogumtarihi,&c1.telefon,&c1.apartgirisgun,&c1.apartgirisay,&c1.apartgirisyil,&c1.kalinacakay,&c1.apartcikisay,&c1.apartcikisyil);
			printf("%0.f\n",c1.id);
	
		}	
	
		fclose(ptr1);
	}
	printf("bilgilerini silmek istediginiz ogrencinin idsini giriniz :");
	scanf("%f",&id);
	if(ptr!=NULL)
	{	
		while(!feof(ptr))
		{
			
			fscanf(ptr,"%f\t%f\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.tc,c1.isim,&c1.soyisim,&c1.eposta,&c1.cinsiyet,&c1.dogumtarihi,&c1.telefon,&c1.apartgirisgun,&c1.apartgirisay,&c1.apartgirisyil,&c1.kalinacakay,&c1.apartcikisay,&c1.apartcikisyil);
			if(id!=c1.id)
			{
				fprintf(ptr2,"%f\t%f\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",c1.id,c1.tc,c1.isim,c1.soyisim,c1.eposta,c1.cinsiyet,c1.dogumtarihi,c1.telefon,c1.apartgirisgun,c1.apartgirisay,c1.apartgirisyil,c1.kalinacakay,c1.apartcikisay,c1.apartcikisyil);
			}
			
		}
			
		
	}
	
	fclose(ptr);
	fclose(ptr2);
	borcsil(c1,id);
	remove("kayitlar.txt");
	rename("temp.txt","kayitlar.txt");
	printf("\n\n ---Kaydiniz Basatiyla silindi-----\n\n");
	
}
void gunceleme(struct kayitlar c1)
{
	FILE *ptr,*ptr1,*ptr2;
	float id;
	char sorgu;
	ptr=fopen("kayitlar.txt","r");
	ptr1=fopen("kayitlar.txt","r");
	ptr2=fopen("temp.txt","w");
	if(ptr1!=NULL)
	{	
		printf("----idler----\n");
		while(!feof(ptr1))
		{
			
			fscanf(ptr1,"%f\t%f\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.tc,c1.isim,&c1.soyisim,&c1.eposta,&c1.cinsiyet,&c1.dogumtarihi,&c1.telefon,&c1.apartgirisgun,&c1.apartgirisay,&c1.apartgirisyil,&c1.kalinacakay,&c1.apartcikisay,&c1.apartcikisyil);
			printf("%0.f\n",c1.id);
	
		}	
	
		fclose(ptr1);
	}
	printf("bilgilerini istediginiz ogrencinin idsini giriniz :");
	scanf("%f",&id);
	
	if(ptr1!=NULL)
	{	
		while(!feof(ptr))
		{
			
			fscanf(ptr,"%f\t%f\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.tc,c1.isim,&c1.soyisim,&c1.eposta,&c1.cinsiyet,&c1.dogumtarihi,&c1.telefon,&c1.apartgirisgun,&c1.apartgirisay,&c1.apartgirisyil,&c1.kalinacakay,&c1.apartcikisay,&c1.apartcikisyil);
			if(c1.id==id)
			{
				printf ("ad soyad bilgisi guncellensin mi: (y/n)");
				scanf("%s",&sorgu);
				if(sorgu=='y')
				{
					printf("Yeni isim :");
					scanf(" %[^\n]s", c1.isim) ;
					printf("Yeni soyisim :");
					scanf(" %[^\n]s", c1.soyisim) ;
					
				}
					printf ("tc no bilgisi guncellensin mi: (y/n)");
					scanf("%s",&sorgu);
				if(sorgu=='y')
				{
					printf("Yeni tc kimlik no: ");
					scanf("%f",&c1.tc);
				}
				printf ("cinsiyet bilgisi guncellensin mi: (y/n)");
				scanf("%s",&sorgu);
				if(sorgu=='y')
				{
					printf("cinsiyet :");
					scanf("%s",c1.cinsiyet);
					
				}
				printf ("dogum tarihi bilgisi guncellensin mi: (y/n)");
				scanf("%s",&sorgu);
				if(sorgu=='y')
				{	
					printf("dogum tarihi: ");
					scanf("%s",c1.dogumtarihi);	
				}
				printf ("telefon no bilgisi guncellensin mi: (y/n)");
				scanf("%s",&sorgu);
				if(sorgu=='y')
				{	
					printf("telefon no:");
					scanf("%s",c1.telefon);

				}
				printf ("eposta adresi bilgisi guncellensin mi: (y/n)");
				scanf("%s",&sorgu);
				if(sorgu=='y')
				{	
					printf("eposta : ");
					scanf("%s",c1.eposta);
					
				}
				printf ("giris tarihi bilgisi ve kalinacak ay bilgisiguncellensin mi: (y/n)");
				scanf("%s",&sorgu);
				if(sorgu=='y')
				{
					printf("apart giris gunu:");
					scanf("%d",&c1.apartgirisgun);
					go:
					printf("apart giris ay:");
					scanf("%d",&c1.apartgirisay);
					if (c1.apartgirisay>12)
					{
						printf("\n\nHatali ay girisi yaptiniz.(aylar 1-12)\n");
						goto go;
					}
					printf("apart giris yil:");
					scanf("%d",&c1.apartgirisyil);
					go1:
					printf("kalinacak ay: ");
					scanf("%d",&c1.kalinacakay);
						if(c1.kalinacakay+c1.apartgirisay>23)
					{
						printf("kalinacak ay max %d olabilir.\n",(24-c1.apartgirisay));
						goto go1;
					}
					borcguncelle(c1,id);
				}
				if(c1.kalinacakay+c1.apartgirisay<=12)
				{
					c1.apartcikisay=c1.kalinacakay+c1.apartgirisay;
					c1.apartcikisyil=c1.apartgirisyil;		}
					else if(c1.kalinacakay+c1.apartgirisay<=24)
				{
						c1.apartcikisay=c1.kalinacakay+c1.apartgirisay-12;
						c1.apartcikisyil=c1.apartgirisyil+1;
				}
				else
				{
					c1.apartcikisay=c1.kalinacakay+c1.apartgirisay-24;
					c1.apartcikisyil=c1.apartgirisyil+2;
				}
				
				
				}
			
			
			fprintf(ptr2,"%f\t%f\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",c1.id,c1.tc,c1.isim,c1.soyisim,c1.eposta,c1.cinsiyet,c1.dogumtarihi,c1.telefon,c1.apartgirisgun,c1.apartgirisay,c1.apartgirisyil,c1.kalinacakay,c1.apartcikisay,c1.apartcikisyil);
	
		}

		fclose(ptr2);
		fclose(ptr);
	}
	printf("\n\n\n---Guncelleme islemi tamamlandi-----\n\n\n");
	remove("kayitlar.txt");
	rename("temp.txt","kayitlar.txt");
}

void borclistele(struct kayitlar c1)
{	
	int id_kontrol;
	FILE *ptr,*ptr1;
	ptr1=fopen("borckayit.txt","r");
	ptr=fopen("borckayit.txt","r");
	float id,borckira=0,borcelektirik=0;
	int aykira=0,ayelektirik=0;
	
	
	if(ptr1!=NULL)
	{	
		printf("----idler----\n");
		while(!feof(ptr1))
		{
			
			fscanf(ptr1,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.kiraborc[0],&c1.kiraborc[1],&c1.kiraborc[2],&c1.kiraborc[3],&c1.kiraborc[4],&c1.kiraborc[5],&c1.kiraborc[6],&c1.kiraborc[7],&c1.kiraborc[8],&c1.kiraborc[9],&c1.kiraborc[10],&c1.kiraborc[11],&c1.kiraborc[12],&c1.kiraborc[13],&c1.kiraborc[14],&c1.kiraborc[15],&c1.kiraborc[16],&c1.kiraborc[17],&c1.kiraborc[18],&c1.kiraborc[19],&c1.kiraborc[20],&c1.kiraborc[21],&c1.kiraborc[22],&c1.kiraborc[23],&c1.elektirikborc[0],&c1.elektirikborc[1],&c1.elektirikborc[2],&c1.elektirikborc[3],&c1.elektirikborc[4],&c1.elektirikborc[5],&c1.elektirikborc[6],&c1.elektirikborc[7],&c1.elektirikborc[8],&c1.elektirikborc[9],&c1.elektirikborc[10],&c1.elektirikborc[11],&c1.elektirikborc[12],&c1.elektirikborc[13],&c1.elektirikborc[14],&c1.elektirikborc[15],&c1.elektirikborc[16],&c1.elektirikborc[17],&c1.elektirikborc[18],&c1.elektirikborc[19],&c1.elektirikborc[20],&c1.elektirikborc[21],&c1.elektirikborc[22],&c1.elektirikborc[23]);
			printf("%0.f\n",c1.id);
	
		}	
	
		fclose(ptr1);
	}
	printf("borcunu goruntulemek istediginiz ogrencinin idsini giriniz :");
	scanf("%f",&id);
	
	if(ptr!=NULL)
	{
		while(!feof(ptr))
		{
			
			fscanf(ptr,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.kiraborc[0],&c1.kiraborc[1],&c1.kiraborc[2],&c1.kiraborc[3],&c1.kiraborc[4],&c1.kiraborc[5],&c1.kiraborc[6],&c1.kiraborc[7],&c1.kiraborc[8],&c1.kiraborc[9],&c1.kiraborc[10],&c1.kiraborc[11],&c1.kiraborc[12],&c1.kiraborc[13],&c1.kiraborc[14],&c1.kiraborc[15],&c1.kiraborc[16],&c1.kiraborc[17],&c1.kiraborc[18],&c1.kiraborc[19],&c1.kiraborc[20],&c1.kiraborc[21],&c1.kiraborc[22],&c1.kiraborc[23],&c1.elektirikborc[0],&c1.elektirikborc[1],&c1.elektirikborc[2],&c1.elektirikborc[3],&c1.elektirikborc[4],&c1.elektirikborc[5],&c1.elektirikborc[6],&c1.elektirikborc[7],&c1.elektirikborc[8],&c1.elektirikborc[9],&c1.elektirikborc[10],&c1.elektirikborc[11],&c1.elektirikborc[12],&c1.elektirikborc[13],&c1.elektirikborc[14],&c1.elektirikborc[15],&c1.elektirikborc[16],&c1.elektirikborc[17],&c1.elektirikborc[18],&c1.elektirikborc[19],&c1.elektirikborc[20],&c1.elektirikborc[21],&c1.elektirikborc[22],&c1.elektirikborc[23]);
			
			if(id==c1.id)
			{
				for (int i=0;i<24;i++)
				{
					if(c1.kiraborc[i]==1)
					{
						borckira+=c1.kirabedeli;
						aykira+=1;
					}
					
				}
				printf("\nodenmemis %d ay icin toplam odenmesi gereken kira tutari: %.2f\n\n",aykira,borckira);
				
				for (int i=0;i<24;i++)
				{
					if(c1.elektirikborc[i]==1)
					{
						borcelektirik+=c1.elektirikbedeli;
						ayelektirik+=1;
					}
					
				}
				printf("\nodenmemis %d ay icin toplam odenmesi gereken elektirik fatura tutari: %.2f\n\n",ayelektirik,borcelektirik);
				id_kontrol=c1.id;
				break;
			}
			
			
			
			
			//printf("\n\n%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n\n",c1.id,c1.kiraborc[0],c1.kiraborc[1],c1.kiraborc[2],c1.kiraborc[3],c1.kiraborc[4],c1.kiraborc[5],c1.kiraborc[6],c1.kiraborc[7],c1.kiraborc[8],c1.kiraborc[9],c1.kiraborc[10],c1.kiraborc[11],c1.kiraborc[12],c1.kiraborc[13],c1.kiraborc[14],c1.kiraborc[15],c1.kiraborc[16],c1.kiraborc[17],c1.kiraborc[18],c1.kiraborc[19],c1.kiraborc[20],c1.kiraborc[21],c1.kiraborc[22],c1.kiraborc[23],c1.elektirikborc[0],c1.elektirikborc[1],c1.elektirikborc[2],c1.elektirikborc[3],c1.elektirikborc[4],c1.elektirikborc[5],c1.elektirikborc[6],c1.elektirikborc[7],c1.elektirikborc[8],c1.elektirikborc[9],c1.elektirikborc[10],c1.elektirikborc[11],c1.elektirikborc[12],c1.elektirikborc[13],c1.elektirikborc[14],c1.elektirikborc[15],c1.elektirikborc[16],c1.elektirikborc[17],c1.elektirikborc[18],c1.elektirikborc[19],c1.elektirikborc[20],c1.elektirikborc[21],c1.elektirikborc[22],c1.elektirikborc[23]);
		
			
		}
		if(id_kontrol!=c1.id)
		{
		 
			
			printf("\n\nid bulunamadi\n\n\n");
			
		}
		fclose(ptr);
	}
	
}
void borcguncelle(struct kayitlar c1,float id)
{
	
	FILE *ptra,*ptrb;
	ptra=fopen("borckayit.txt","r");
	ptrb=fopen("temp1.txt","w");
	if(ptra!=NULL)
	{
		for (int i=0;i<24;i++)
				{
					c1.kiraborc[i]=0;
					c1.elektirikborc[i]=0;
				}
				for(int i=c1.apartgirisay;i<(c1.apartgirisay+c1.kalinacakay);i++ )
				{
					c1.kiraborc[i]=1;
					c1.elektirikborc[i]=1;
				}
				fprintf(ptrb,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",c1.id,c1.kiraborc[0],c1.kiraborc[1],c1.kiraborc[2],c1.kiraborc[3],c1.kiraborc[4],c1.kiraborc[5],c1.kiraborc[6],c1.kiraborc[7],c1.kiraborc[8],c1.kiraborc[9],c1.kiraborc[10],c1.kiraborc[11],c1.kiraborc[12],c1.kiraborc[13],c1.kiraborc[14],c1.kiraborc[15],c1.kiraborc[16],c1.kiraborc[17],c1.kiraborc[18],c1.kiraborc[19],c1.kiraborc[20],c1.kiraborc[21],c1.kiraborc[22],c1.kiraborc[23],c1.elektirikborc[0],c1.elektirikborc[1],c1.elektirikborc[2],c1.elektirikborc[3],c1.elektirikborc[4],c1.elektirikborc[5],c1.elektirikborc[6],c1.elektirikborc[7],c1.elektirikborc[8],c1.elektirikborc[9],c1.elektirikborc[10],c1.elektirikborc[11],c1.elektirikborc[12],c1.elektirikborc[13],c1.elektirikborc[14],c1.elektirikborc[15],c1.elektirikborc[16],c1.elektirikborc[17],c1.elektirikborc[18],c1.elektirikborc[19],c1.elektirikborc[20],c1.elektirikborc[21],c1.elektirikborc[22],c1.elektirikborc[23]);	

		while(!feof(ptra))
		{
			fscanf(ptra,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.kiraborc[0],&c1.kiraborc[1],&c1.kiraborc[2],&c1.kiraborc[3],&c1.kiraborc[4],&c1.kiraborc[5],&c1.kiraborc[6],&c1.kiraborc[7],&c1.kiraborc[8],&c1.kiraborc[9],&c1.kiraborc[10],&c1.kiraborc[11],&c1.kiraborc[12],&c1.kiraborc[13],&c1.kiraborc[14],&c1.kiraborc[15],&c1.kiraborc[16],&c1.kiraborc[17],&c1.kiraborc[18],&c1.kiraborc[19],&c1.kiraborc[20],&c1.kiraborc[21],&c1.kiraborc[22],&c1.kiraborc[23],&c1.elektirikborc[0],&c1.elektirikborc[1],&c1.elektirikborc[2],&c1.elektirikborc[3],&c1.elektirikborc[4],&c1.elektirikborc[5],&c1.elektirikborc[6],&c1.elektirikborc[7],&c1.elektirikborc[8],&c1.elektirikborc[9],&c1.elektirikborc[10],&c1.elektirikborc[11],&c1.elektirikborc[12],&c1.elektirikborc[13],&c1.elektirikborc[14],&c1.elektirikborc[15],&c1.elektirikborc[16],&c1.elektirikborc[17],&c1.elektirikborc[18],&c1.elektirikborc[19],&c1.elektirikborc[20],&c1.elektirikborc[21],&c1.elektirikborc[22],&c1.elektirikborc[23]);
			if(c1.id!=id)
			{	
				fprintf(ptrb,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",c1.id,c1.kiraborc[0],c1.kiraborc[1],c1.kiraborc[2],c1.kiraborc[3],c1.kiraborc[4],c1.kiraborc[5],c1.kiraborc[6],c1.kiraborc[7],c1.kiraborc[8],c1.kiraborc[9],c1.kiraborc[10],c1.kiraborc[11],c1.kiraborc[12],c1.kiraborc[13],c1.kiraborc[14],c1.kiraborc[15],c1.kiraborc[16],c1.kiraborc[17],c1.kiraborc[18],c1.kiraborc[19],c1.kiraborc[20],c1.kiraborc[21],c1.kiraborc[22],c1.kiraborc[23],c1.elektirikborc[0],c1.elektirikborc[1],c1.elektirikborc[2],c1.elektirikborc[3],c1.elektirikborc[4],c1.elektirikborc[5],c1.elektirikborc[6],c1.elektirikborc[7],c1.elektirikborc[8],c1.elektirikborc[9],c1.elektirikborc[10],c1.elektirikborc[11],c1.elektirikborc[12],c1.elektirikborc[13],c1.elektirikborc[14],c1.elektirikborc[15],c1.elektirikborc[16],c1.elektirikborc[17],c1.elektirikborc[18],c1.elektirikborc[19],c1.elektirikborc[20],c1.elektirikborc[21],c1.elektirikborc[22],c1.elektirikborc[23]);	
			}
		
	}
	fclose(ptra);
	fclose(ptrb);
	}
	remove("borckayit.txt");
	rename("temp1.txt","borckayit.txt");
}
void borcsil(struct kayitlar c1,float id)
{
	
	FILE *ptra,*ptrb;
	ptra=fopen("borckayit.txt","r");
	ptrb=fopen("temp1.txt","w");
	if(ptra!=NULL)
	{
		while(!feof(ptra))
		{
			fscanf(ptra,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.kiraborc[0],&c1.kiraborc[1],&c1.kiraborc[2],&c1.kiraborc[3],&c1.kiraborc[4],&c1.kiraborc[5],&c1.kiraborc[6],&c1.kiraborc[7],&c1.kiraborc[8],&c1.kiraborc[9],&c1.kiraborc[10],&c1.kiraborc[11],&c1.kiraborc[12],&c1.kiraborc[13],&c1.kiraborc[14],&c1.kiraborc[15],&c1.kiraborc[16],&c1.kiraborc[17],&c1.kiraborc[18],&c1.kiraborc[19],&c1.kiraborc[20],&c1.kiraborc[21],&c1.kiraborc[22],&c1.kiraborc[23],&c1.elektirikborc[0],&c1.elektirikborc[1],&c1.elektirikborc[2],&c1.elektirikborc[3],&c1.elektirikborc[4],&c1.elektirikborc[5],&c1.elektirikborc[6],&c1.elektirikborc[7],&c1.elektirikborc[8],&c1.elektirikborc[9],&c1.elektirikborc[10],&c1.elektirikborc[11],&c1.elektirikborc[12],&c1.elektirikborc[13],&c1.elektirikborc[14],&c1.elektirikborc[15],&c1.elektirikborc[16],&c1.elektirikborc[17],&c1.elektirikborc[18],&c1.elektirikborc[19],&c1.elektirikborc[20],&c1.elektirikborc[21],&c1.elektirikborc[22],&c1.elektirikborc[23]);
			if(c1.id!=id)
			{	
				fprintf(ptrb,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",c1.id,c1.kiraborc[0],c1.kiraborc[1],c1.kiraborc[2],c1.kiraborc[3],c1.kiraborc[4],c1.kiraborc[5],c1.kiraborc[6],c1.kiraborc[7],c1.kiraborc[8],c1.kiraborc[9],c1.kiraborc[10],c1.kiraborc[11],c1.kiraborc[12],c1.kiraborc[13],c1.kiraborc[14],c1.kiraborc[15],c1.kiraborc[16],c1.kiraborc[17],c1.kiraborc[18],c1.kiraborc[19],c1.kiraborc[20],c1.kiraborc[21],c1.kiraborc[22],c1.kiraborc[23],c1.elektirikborc[0],c1.elektirikborc[1],c1.elektirikborc[2],c1.elektirikborc[3],c1.elektirikborc[4],c1.elektirikborc[5],c1.elektirikborc[6],c1.elektirikborc[7],c1.elektirikborc[8],c1.elektirikborc[9],c1.elektirikborc[10],c1.elektirikborc[11],c1.elektirikborc[12],c1.elektirikborc[13],c1.elektirikborc[14],c1.elektirikborc[15],c1.elektirikborc[16],c1.elektirikborc[17],c1.elektirikborc[18],c1.elektirikborc[19],c1.elektirikborc[20],c1.elektirikborc[21],c1.elektirikborc[22],c1.elektirikborc[23]);	
			}
		
	}
	fclose(ptra);
	fclose(ptrb);
	}
	
	remove("borckayit.txt");
	rename("temp1.txt","borckayit.txt");
	
}
void kiraborcuode(struct kayitlar c1)
{

	
	FILE *ptr,*ptr1,*ptr2;
	ptr=fopen("borckayit.txt","r");
	ptr1=fopen("borckayit.txt","r");
	ptr2=fopen("temp.txt","w");
	int aykira=0,ayelektirik=0;
	float id;
	int ay,yil;
	if(ptr1!=NULL)
	{	
		printf("----idler----\n");
		while(!feof(ptr1))
		{
			
			fscanf(ptr1,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.kiraborc[0],&c1.kiraborc[1],&c1.kiraborc[2],&c1.kiraborc[3],&c1.kiraborc[4],&c1.kiraborc[5],&c1.kiraborc[6],&c1.kiraborc[7],&c1.kiraborc[8],&c1.kiraborc[9],&c1.kiraborc[10],&c1.kiraborc[11],&c1.kiraborc[12],&c1.kiraborc[13],&c1.kiraborc[14],&c1.kiraborc[15],&c1.kiraborc[16],&c1.kiraborc[17],&c1.kiraborc[18],&c1.kiraborc[19],&c1.kiraborc[20],&c1.kiraborc[21],&c1.kiraborc[22],&c1.kiraborc[23],&c1.elektirikborc[0],&c1.elektirikborc[1],&c1.elektirikborc[2],&c1.elektirikborc[3],&c1.elektirikborc[4],&c1.elektirikborc[5],&c1.elektirikborc[6],&c1.elektirikborc[7],&c1.elektirikborc[8],&c1.elektirikborc[9],&c1.elektirikborc[10],&c1.elektirikborc[11],&c1.elektirikborc[12],&c1.elektirikborc[13],&c1.elektirikborc[14],&c1.elektirikborc[15],&c1.elektirikborc[16],&c1.elektirikborc[17],&c1.elektirikborc[18],&c1.elektirikborc[19],&c1.elektirikborc[20],&c1.elektirikborc[21],&c1.elektirikborc[22],&c1.elektirikborc[23]);
			printf("%0.f\n",c1.id);
	
		}	
	
		fclose(ptr1);
	}
	printf("borcunu odemek istediginiz ogrencinin idsini giriniz :");
	scanf("%f",&id);
	
	if(ptr!=NULL)
	{
		while(!feof(ptr))
		{
			
			fscanf(ptr,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.kiraborc[0],&c1.kiraborc[1],&c1.kiraborc[2],&c1.kiraborc[3],&c1.kiraborc[4],&c1.kiraborc[5],&c1.kiraborc[6],&c1.kiraborc[7],&c1.kiraborc[8],&c1.kiraborc[9],&c1.kiraborc[10],&c1.kiraborc[11],&c1.kiraborc[12],&c1.kiraborc[13],&c1.kiraborc[14],&c1.kiraborc[15],&c1.kiraborc[16],&c1.kiraborc[17],&c1.kiraborc[18],&c1.kiraborc[19],&c1.kiraborc[20],&c1.kiraborc[21],&c1.kiraborc[22],&c1.kiraborc[23],&c1.elektirikborc[0],&c1.elektirikborc[1],&c1.elektirikborc[2],&c1.elektirikborc[3],&c1.elektirikborc[4],&c1.elektirikborc[5],&c1.elektirikborc[6],&c1.elektirikborc[7],&c1.elektirikborc[8],&c1.elektirikborc[9],&c1.elektirikborc[10],&c1.elektirikborc[11],&c1.elektirikborc[12],&c1.elektirikborc[13],&c1.elektirikborc[14],&c1.elektirikborc[15],&c1.elektirikborc[16],&c1.elektirikborc[17],&c1.elektirikborc[18],&c1.elektirikborc[19],&c1.elektirikborc[20],&c1.elektirikborc[21],&c1.elektirikborc[22],&c1.elektirikborc[23]);
			
			if(id==c1.id)
			{	printf("----odenmemis aylar----\n");
				for (int i=0;i<12;i++)
				{		
					if(c1.kiraborc[i]==1)
					{
						printf("1.yil %d. ay icin : %.0ftl borcunuz bulunmakta\n",i+1,c1.kirabedeli);
						
					}	
				}
				for (int i=12;i<24;i++)
				{		
					if(c1.kiraborc[i]==1)
					{
						printf("2.yil %d. ay icin : %.0ftl borcunuz bulunmakta\n",i-11,c1.kirabedeli);
						
					}	
				}
				go:
				printf("\n\nodemek istediginiz yili ve ayi sirasiyla tuslayiniz: ");
				scanf("%d",&yil);
				scanf("%d",&ay);
				if(ay>12)
				{
					printf("hatali ay girdiniz:");
					goto go;
				}
				if(yil>2)
				{
					printf("\n\nhatali yil girdiniz\n\n");
					goto go;
				}
				else if(yil==1)
				{
					ay--;
				}
				else if(yil==2)
				{
					ay=ay+12-1;
				}
				if(c1.kiraborc[ay]==1)
				{
					c1.kiraborc[ay]=0;
					printf("\nborcunuz odenmistir!\n\n");
					
				}
			
				
				else 
				{
					printf("\n\nbu zamana ait borcunuz bulunmamaktadir\n\n");
				}
				
			}
			
				fprintf(ptr2,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",c1.id,c1.kiraborc[0],c1.kiraborc[1],c1.kiraborc[2],c1.kiraborc[3],c1.kiraborc[4],c1.kiraborc[5],c1.kiraborc[6],c1.kiraborc[7],c1.kiraborc[8],c1.kiraborc[9],c1.kiraborc[10],c1.kiraborc[11],c1.kiraborc[12],c1.kiraborc[13],c1.kiraborc[14],c1.kiraborc[15],c1.kiraborc[16],c1.kiraborc[17],c1.kiraborc[18],c1.kiraborc[19],c1.kiraborc[20],c1.kiraborc[21],c1.kiraborc[22],c1.kiraborc[23],c1.elektirikborc[0],c1.elektirikborc[1],c1.elektirikborc[2],c1.elektirikborc[3],c1.elektirikborc[4],c1.elektirikborc[5],c1.elektirikborc[6],c1.elektirikborc[7],c1.elektirikborc[8],c1.elektirikborc[9],c1.elektirikborc[10],c1.elektirikborc[11],c1.elektirikborc[12],c1.elektirikborc[13],c1.elektirikborc[14],c1.elektirikborc[15],c1.elektirikborc[16],c1.elektirikborc[17],c1.elektirikborc[18],c1.elektirikborc[19],c1.elektirikborc[20],c1.elektirikborc[21],c1.elektirikborc[22],c1.elektirikborc[23]);
			
		}
		
	}
	fclose(ptr);
	fclose(ptr1);
	fclose(ptr2);
	remove("borckayit.txt");
	rename("temp.txt","borckayit.txt");
	
}
void elektirikborcuode(struct kayitlar c1)
{
	FILE *ptr,*ptr1,*ptr2;
	ptr=fopen("borckayit.txt","r");
	ptr1=fopen("borckayit.txt","r");
	ptr2=fopen("temp.txt","w");
	int aykira=0,ayelektirik=0;
	float id;
	int ay,yil;
	if(ptr1!=NULL)
	{	
		printf("----idler----\n");
		while(!feof(ptr1))
		{
			
			fscanf(ptr1,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.kiraborc[0],&c1.kiraborc[1],&c1.kiraborc[2],&c1.kiraborc[3],&c1.kiraborc[4],&c1.kiraborc[5],&c1.kiraborc[6],&c1.kiraborc[7],&c1.kiraborc[8],&c1.kiraborc[9],&c1.kiraborc[10],&c1.kiraborc[11],&c1.kiraborc[12],&c1.kiraborc[13],&c1.kiraborc[14],&c1.kiraborc[15],&c1.kiraborc[16],&c1.kiraborc[17],&c1.kiraborc[18],&c1.kiraborc[19],&c1.kiraborc[20],&c1.kiraborc[21],&c1.kiraborc[22],&c1.kiraborc[23],&c1.elektirikborc[0],&c1.elektirikborc[1],&c1.elektirikborc[2],&c1.elektirikborc[3],&c1.elektirikborc[4],&c1.elektirikborc[5],&c1.elektirikborc[6],&c1.elektirikborc[7],&c1.elektirikborc[8],&c1.elektirikborc[9],&c1.elektirikborc[10],&c1.elektirikborc[11],&c1.elektirikborc[12],&c1.elektirikborc[13],&c1.elektirikborc[14],&c1.elektirikborc[15],&c1.elektirikborc[16],&c1.elektirikborc[17],&c1.elektirikborc[18],&c1.elektirikborc[19],&c1.elektirikborc[20],&c1.elektirikborc[21],&c1.elektirikborc[22],&c1.elektirikborc[23]);
			printf("%0.f\n",c1.id);
	
		}	
	
		fclose(ptr1);
	}
	printf("borcunu odemek istediginiz ogrencinin idsini giriniz :");
	scanf("%f",&id);
	
	if(ptr!=NULL)
	{
		while(!feof(ptr))
		{
			
			fscanf(ptr,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&c1.id,&c1.kiraborc[0],&c1.kiraborc[1],&c1.kiraborc[2],&c1.kiraborc[3],&c1.kiraborc[4],&c1.kiraborc[5],&c1.kiraborc[6],&c1.kiraborc[7],&c1.kiraborc[8],&c1.kiraborc[9],&c1.kiraborc[10],&c1.kiraborc[11],&c1.kiraborc[12],&c1.kiraborc[13],&c1.kiraborc[14],&c1.kiraborc[15],&c1.kiraborc[16],&c1.kiraborc[17],&c1.kiraborc[18],&c1.kiraborc[19],&c1.kiraborc[20],&c1.kiraborc[21],&c1.kiraborc[22],&c1.kiraborc[23],&c1.elektirikborc[0],&c1.elektirikborc[1],&c1.elektirikborc[2],&c1.elektirikborc[3],&c1.elektirikborc[4],&c1.elektirikborc[5],&c1.elektirikborc[6],&c1.elektirikborc[7],&c1.elektirikborc[8],&c1.elektirikborc[9],&c1.elektirikborc[10],&c1.elektirikborc[11],&c1.elektirikborc[12],&c1.elektirikborc[13],&c1.elektirikborc[14],&c1.elektirikborc[15],&c1.elektirikborc[16],&c1.elektirikborc[17],&c1.elektirikborc[18],&c1.elektirikborc[19],&c1.elektirikborc[20],&c1.elektirikborc[21],&c1.elektirikborc[22],&c1.elektirikborc[23]);
			
			if(id==c1.id)
			{	printf("----odenmemis aylar----\n");
				for (int i=0;i<12;i++)
				{		
					if(c1.elektirikborc[i]==1)
					{
						printf("1.yil %d. ay icin : %.0ftl borcunuz bulunmakta\n",i+1,c1.elektirikbedeli);
						
					}	
				}
				for (int i=12;i<24;i++)
				{		
					if(c1.elektirikborc[i]==1)
					{
						printf("2.yil %d. ay icin : %.0ftl borcunuz bulunmakta\n",i-11,c1.elektirikbedeli);
						
					}	
				}
				go:
				printf("\n\nodemek istediginiz yili ve ayi sirasiyla tuslayiniz: ");
				scanf("%d",&yil);
				scanf("%d",&ay);
				if(ay>12)
				{
					printf("hatali ay girdiniz:");
					goto go;
				}
				if(yil>2)
				{
					printf("\n\nhatali yil girdiniz\n\n");
					goto go;
				}
				else if(yil==1)
				{
					ay--;
				}
				else if(yil==2)
				{
					ay=ay+12-1;
				}
				if(c1.elektirikborc[ay]==1)
				{
					c1.elektirikborc[ay]=0;
					printf("\nborcunuz odenmistir!\n\n");
					
				}
				else 
				{
					printf("\n\nbu zamana ait borcunuz bulunmamaktadir\n\n");
				}
				
			}
			
				fprintf(ptr2,"%f\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",c1.id,c1.kiraborc[0],c1.kiraborc[1],c1.kiraborc[2],c1.kiraborc[3],c1.kiraborc[4],c1.kiraborc[5],c1.kiraborc[6],c1.kiraborc[7],c1.kiraborc[8],c1.kiraborc[9],c1.kiraborc[10],c1.kiraborc[11],c1.kiraborc[12],c1.kiraborc[13],c1.kiraborc[14],c1.kiraborc[15],c1.kiraborc[16],c1.kiraborc[17],c1.kiraborc[18],c1.kiraborc[19],c1.kiraborc[20],c1.kiraborc[21],c1.kiraborc[22],c1.kiraborc[23],c1.elektirikborc[0],c1.elektirikborc[1],c1.elektirikborc[2],c1.elektirikborc[3],c1.elektirikborc[4],c1.elektirikborc[5],c1.elektirikborc[6],c1.elektirikborc[7],c1.elektirikborc[8],c1.elektirikborc[9],c1.elektirikborc[10],c1.elektirikborc[11],c1.elektirikborc[12],c1.elektirikborc[13],c1.elektirikborc[14],c1.elektirikborc[15],c1.elektirikborc[16],c1.elektirikborc[17],c1.elektirikborc[18],c1.elektirikborc[19],c1.elektirikborc[20],c1.elektirikborc[21],c1.elektirikborc[22],c1.elektirikborc[23]);
			
		}
		
	}
	fclose(ptr);
	fclose(ptr1);
	fclose(ptr2);
	remove("borckayit.txt");
	rename("temp.txt","borckayit.txt");
}
