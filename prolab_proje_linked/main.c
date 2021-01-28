#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



struct node
{
    char kelime[200];
    int kelimesayisi;
    struct node *next;


};

struct node *start=NULL;
struct node *end=NULL;


void SonaEkle(int sayi, char *keyword)
{
    struct node *eklenecek = (struct node*) malloc(sizeof(struct node));
    eklenecek->kelimesayisi=sayi;
    strcpy(eklenecek->kelime,keyword);
    if(start==NULL)
    {
        start=eklenecek;
        end=eklenecek;
        end->next=NULL;
    }
    else
    {
        end->next=eklenecek;
        end=eklenecek;
        end->next=NULL;
    }
}
void BasaEkle(int sayi, char *keyword)
{
    struct node *eklenecek = (struct node*) malloc(sizeof(struct node));
    eklenecek->kelimesayisi=sayi;
    strcpy(eklenecek->kelime,keyword);
    if(start==NULL)
    {
        start=eklenecek;
        start->next=NULL;
        end=start;
    }
    else
    {
        eklenecek->next=start;
        start=eklenecek;
    }
}

void ArayaEkle(int sayi, char *keyword)
{

    struct node *eklenecek = (struct node*) malloc(sizeof(struct node));
    eklenecek->kelimesayisi=sayi;
    strcpy(eklenecek->kelime,keyword);
    if(start==NULL)
    {
        start=eklenecek;
        end=eklenecek;
        end->next=NULL;
    }
    else
    {
        if(eklenecek->kelimesayisi > start->kelimesayisi)
            BasaEkle(eklenecek->kelimesayisi,eklenecek->kelime);
        else if(eklenecek->kelimesayisi <= end->kelimesayisi)
            SonaEkle(eklenecek->kelimesayisi,eklenecek->kelime);
        else
        {

            struct node *sira=start;
            while(sira->next->kelimesayisi > eklenecek->kelimesayisi)
                sira=sira->next;
            eklenecek->next=sira->next;
            sira->next=eklenecek;
        }
    }
}

//BasaEkle,SoneEkle ve Arayaekle fonksiyonlarinin yazilmasinda Veri Yapilari ve Algoritmalari dersinde Onur Gok
// hocanin anlattigi orneklerden  yararlanilmistir.

void yazdir()
{

    struct node* yazilacak = start;
    int i= 1;
    while(yazilacak->next != NULL)
    {

        printf("%d.%s:%d \n",i,yazilacak->kelime,yazilacak->kelimesayisi);
        yazilacak= yazilacak->next;
        i++;
    }
}

int kontrol(char *keyword)
{
    struct node* controlNode = start;
    if(controlNode!=NULL)
    {
        while(controlNode->next != NULL)
        {

            if(strcmp(controlNode->kelime,keyword)==0)
            {

                return 0;
            }
            controlNode = controlNode->next;

        }
    }
    return 1;
}
void ListeyeEkle(char *keyword)
{
    int kelimeadet=0;
    FILE *tempdosya;
    tempdosya =fopen("okunacaktext.txt","r");

    while(!feof(tempdosya))
    {
        char tempkelime[200] ;
        fscanf(tempdosya,"%s",tempkelime);
        if(strcmp(tempkelime,keyword)==0)
        {
            kelimeadet++;
        }

    }
    ArayaEkle(kelimeadet,keyword);
}

int main()
{
    setlocale(LC_ALL, "Turkish");
    FILE *dosya;
    dosya =fopen("okunacaktext.txt","r");

    if(dosya!=NULL)
    {
        while(!feof(dosya))
        {

            char keyword[200];

            fscanf(dosya,"%s",keyword);

            int tempControl = kontrol(keyword);
            if(tempControl)
            {
                ListeyeEkle(keyword);
            }
        }

    }
    else
    {
        printf("Okunacak bir dosya bulunamadi !!!!");
    }
    yazdir();





    return 0;
}
