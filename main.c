#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define ESC 27
#define CR 13       /* CR sembolunu 13 olarak tanimlar */
#define LF 10       /* LF sembolunu 10 olarak tanimlar */
#define BS 8
#define DEL 127
#define M 77
#define  P 80
#define  H 72
#define K 75
#include <locale.h>
//Harun Karahan * Emil Mammadov
FILE *dosya ;

char dosya_ismi[40] = "";
int b = 0 ; int k=0 ; int c ; int g=0; int c2 =0 ; int b2 ; int i_gecici ; int j_gecici ; int g2=0; int k2=0 ;
int i2 , j2 ,i3,j3 ; int i_gecici2 , j_gecici2 ; int a ;
char dizi2[49][80][10] ;
char dizi[49][80] [10] ; int i ; int j ;
char dizi3[49][80][10] ;
char dizi_kopyala[49][80] [10] ;
char d;
int imlecin_yeri_i[10] ;
int imlecin_yeri_j[10] ;

int main()


{
gotoxy(45,50);
printf("Sayfa %d",k+1) ;
gotoxy(0,0) ;
yazdir();
}
void yazdir()
{

  for(i=0;i<=48;i++)
    {for(j=0;j<=79;j++)
  { a :


 imlec();
 islemler() ;


     if(dizi[i][j][k]==BS)
     {
        printf(" ",dizi[i][j-1][k]) ;
        dizi[i][j-1] [k] = NULL ;
        printf("%c",BS) ;
        j=j-2 ;
        if(j<0)
        { i=i-1 ; j=80 ;
         if(i<0) i=0 ;
        gotoxy(j,i) ;

            goto a ;

            }

     }

     if (dizi[i][j][k] == ESC)
         exit(-1) ;

     if(dizi[i][j][k]==13 && i<=48)
     {
         j=0 ; i=i+1; gotoxy(j,i) ;
     }


  } printf("\n");
    }
}

void islemler()
{
 if(dizi[i][j][k]==43 || (i==48) ) { sonraki_sayfa()  ;dizi[i][j][k]=NULL; }
 if(dizi[i][j][k]==45) { onceki_sayfa(); dizi[i][j][k]=NULL; }

if(dizi[i][j][k]==24 )
{

      if(g2==0)
     {
         i_gecici=i ; j_gecici=j ;
     dizi[i][j+1][k]=dizi2[i][j+1][k]; g2=1 ;

     }
     else
     {dizi[i][j+1][k]=dizi2[i][j+1][k] ;
     i2 = i ; j2=j; g2=2;
     i_gecici2 =i ; j_gecici2=j ;

      }

      if(g2==2)
      {
      i3=i2 ; j3=j2 ;
      gotoxy(j2-1,i2);
      for(i2,j2;(i2<i_gecici || j2<=j_gecici);i2,j2++)
     { if(j2>80){j2=1 ; i2++ ; printf("\n");}
       if(j>79){j=0;i++;}
      printf(" ") ;

      j++ ;

     } i2=i3; j2=j3;
       k2=k;
      }

     c=68 ;
}if (dizi[i][j][k]==3)
 {
     if(g2==0)
     {
         i_gecici=i ; j_gecici=j ;
     dizi[i][j+1][k]=dizi2[i][j+1][k]; g2=1 ;

     }
     else
     {dizi[i][j+1][k]=dizi2[i][j+1][k] ;
     i2 = i ; j2=j; g2=0 ;c=3;
     k2=k ;
     i_gecici2 =i ; j_gecici2=j ;
      }

 }
 if(dizi[i][j][k]==22 && c==3  )
  yapistir() ;
 if(dizi[i][j][k]==22 && c==68)
    kes_yapistir() ;
  if (dizi[i][j][k]==19){dosyaya_kaydetme(); i2=i ; j2=j ;}
    if (dizi[i][j][k]==15)
    { dosyadan_ac() ; i2=i ; j2=j ;}
}
void imlec()
{
dizi[i][j][k]= getch();
if((dizi[i][j][k]>0 || dizi[i][j][k]<-80) && dizi[i][j][k]!=3 && dizi[i][j][k]!=24 && dizi[i][j][k]!=22 )
    {dizi2[i][j][k]=dizi[i][j][k] ; dizi3[i][j][k] = dizi[i][j][k] ;  }

if(dizi[i][j][k]==-32 )
      {
 dizi[i][j][k]= getch() ;
    if (dizi[i][j][k]==80 )
    { i=i+1 ; j=j-1; if(i>=48) i-- ;  gotoxy(j,i) ; }


   else if (dizi[i][j][k]==72 )
    {i=i-1 ; j=j-1 ; if(i<0) i++ ;   gotoxy(j,i) ;  }
    else if(dizi[i][j][k]==75  )
  {  dizi [i][j][k]=NULL; j=j-2; gotoxy(j,i) ;if(j<0) j++; }
     else if ( dizi [i][j][k]==77  )
        {dizi [i][j][k]=NULL;  gotoxy(j,i) ;  if(j>78) j--; }
      else j-- ;
      }


     else
     {    if(dizi[i][j][k]!=3 && dizi[i][j][k]!=22 && dizi[i][j][k] != 24 && dizi[i][j][k]!=19 && dizi[i][j][k]!=15 && dizi[i][j][k]!=43 &&dizi[i][j][k]!=45  )

          putchar(dizi[i][j][k]) ;
     }


}

void gotoxy(int sutun,int satir)
{

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD position ={sutun,satir};
    SetConsoleCursorPosition(h,position);
}

void sonraki_sayfa()
{

   imlecin_yeri_i[k] = i ;
   imlecin_yeri_j[k] = j ;
   dizi2[imlecin_yeri_i[k]][imlecin_yeri_j[k] ] [k] = NULL;
   k++ ; if(k>9) k=9 ;
  if(imlecin_yeri_j[k]!=0)  imlecin_yeri_j[k]-- ;
  system("CLS") ;
  gotoxy(45,48);
  printf("Sayfa %d",k+1) ;

 for(i=0;i<=47;i++)
    for(j=0;j<=79;j++)
    {
        {   if(dizi2[i][j][k] !=-32 && dizi2[i][j][k]!=22 && dizi2[i][j][k]!=3 && dizi2[i][j][k]!=24 && dizi[i][j][k]!=19  && dizi[i][j][k]!=15)
            {gotoxy(j,i); putchar(dizi2[i][j][k]) ;
             if(j==79) printf("\n") ; }
        }
    }
   i=imlecin_yeri_i[k] ;
   j=imlecin_yeri_j[k] ;
gotoxy(j,i) ;

}
void onceki_sayfa()
{

   imlecin_yeri_i[k] = i ;
   imlecin_yeri_j[k] = j ;
   dizi2[imlecin_yeri_i[k]][imlecin_yeri_j[k] ] [k]=NULL ;
   k-- ; if(k<0) k=0 ;
   if(imlecin_yeri_j[k]!=0) imlecin_yeri_j[k]-- ;
   system("CLS") ;
    gotoxy(45,48);
  printf("Sayfa %d",k+1) ;

   for(i=0;i<=47;i++)
    for(j=0;j<=79;j++)
    {
        {  if(dizi2[i][j][k] !=-32&&dizi2[i][j][k]!=22 && dizi2[i][j][k]!=3 && dizi2[i][j][k]!=24 && dizi[i][j][k]!=19  && dizi[i][j][k]!=15 )
            {gotoxy(j,i); putchar(dizi2[i][j][k]) ;
            if(j==79) printf("\n") ; }
         }
    }
   i=imlecin_yeri_i[k] ;
   j=imlecin_yeri_j[k] ;
  gotoxy(j,i) ;
}


void kes_yapistir()
{
j=j+1;
 gotoxy(j-1,i);
  for(i2,j2;(i2<i_gecici || j2<=j_gecici);i2,j2++)
     { if(j2>79){j2=1 ; i2++ ; }
       if(j>80){j=1;i++;printf("\n");}
      putchar(dizi3[i2][j2-1][k2]) ;
      dizi[i][j-1][k]=dizi3[i2][j2-1][k2];
      dizi2[i][j-1][k]=dizi3[i2][j2-1][k2];
      dizi3[i][j-1][k]=dizi3[i2][j2-1][k2];
      dizi2[i2][j2-1][k]=NULL ;

      j++ ;
     if(i==47 && j==79) {sonraki_sayfa();i=0;j=1;gotoxy(j,i);}
     } i2=i_gecici2 ; j2=j_gecici2 ;


j--;
j--;
  g2=0;

}

void yapistir()
{  gotoxy(0,0);
j++ ;
gotoxy(j-1,i);
  for(i2,j2;(i2<i_gecici || j2<=j_gecici);i2,j2++)
     { if(j2>80){j2=1 ; i2++ ; }
       if(j>80){j=1;i++;printf("\n");}

      putchar(dizi3[i2][j2-1][k2]) ;
      dizi[i][j-1][k]=dizi3[i2][j2-1][k2];
      dizi2[i][j-1][k]=dizi3[i2][j2-1][k2];
      dizi3[i][j-1][k]=dizi3[i2][j2-1][k2];
      j++ ;
    if(i==47 && j==79) {sonraki_sayfa();i=0;j=1;gotoxy(j,i);}
     }
 j--;
 j--;
i2=i_gecici2 ; j2=j_gecici2 ;

}


void dosyadan_ac()
{dizi[i][j][k]=NULL ;
k2=k;
    gotoxy(65,47) ; printf("dosyanizin ismi : ") ; scanf("%s",dosya_ismi);
int t=0 ;
while(dosya_ismi[t]!=NULL)
    t++ ;
dosya_ismi[t]='.' ; dosya_ismi[t+1]='t' ;  dosya_ismi[t+2]='x' ; dosya_ismi[t+3]='t' ;
gotoxy(65,47) ; printf("                  \t \t") ; gotoxy(0,0) ;
dosya=fopen(dosya_ismi,"r+") ;
if(dosya==NULL)
    printf("dosya bulunamadi");
else
{
    system("CLS");
 for(k=0;k<10;k++)
 { for(i=0;i<=46;i++)
    for(j=0;j<=80;j++)
    {
        {
           dizi2[i][j][k]= fgetc(dosya) ;

        }
    } gotoxy(0,0);
 }
k=k2;

}
fclose(dosya) ;
i2=i ;j2=j ;
}
void dosyaya_kaydetme()
{ dizi[i][j][k]=NULL ;
    gotoxy(65,47) ; printf("dosyanizin ismi : ") ; scanf("%s",dosya_ismi);
int t=0 ;
while(dosya_ismi[t]!=NULL)
    t++ ;
dosya_ismi[t]='.' ; dosya_ismi[t+1]='t' ;  dosya_ismi[t+2]='x' ; dosya_ismi[t+3]='t' ;
gotoxy(65,47) ; printf("                  \t \t") ;
dosya=fopen(dosya_ismi,"w+") ;
char j = 'a' ;
 for(k=0;k<10;k++)
 for(i=0;i<=48;i++)
   {
     for(j=0;j<=79;j++)
    {
        {

            if(dizi2[i][j][k]!=22 && dizi2[i][j][k]!=19 && dizi2[i][j][k]!=24 && dizi2[i][j][k]!=3 && dizi2[i][j][k]!=15  )
            { fprintf(dosya,"%c",dizi2[i][j][k]) ;

             }
        }
    }fprintf(dosya,"%c",'\n');
   }

fclose(dosya) ;
i=i2 ;  ;j=j2 ;
}

