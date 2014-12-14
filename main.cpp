#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<ctime>
//#include"red_polje.h"
#include"red_pokazivac.h"
using namespace std;
red *Q;
red *A;
red *B;
red *C;
red *D;
red *E;
red *brza;
int brojac1=0;
int brojac2=0;
int brojac3=0;
int brojac4=0;
int brojac5=0;
bool zadatak1=false;
bool zadatak2=false;
bool zadatak3=false;
bool zadatak4=false;
osobe *polje;
osobe *polje1;
osobe *polje2;
osobe *polje3;
osobe *polje4;
osobe *polje5;
osobe *poljebrza;
int broj;
osobe pomocna2;
osobe pomocna;
void cetvorke(){
     cout<<"Unesite broj cetvorki koje zelite generirati, minimalno 125"<<endl;
     do{
        cin>>broj;
     }while(broj<125);
     polje=new osobe[125+broj];
     polje1=new osobe[125+broj];
     polje2=new osobe[125+broj];
     polje3=new osobe[125+broj];
     polje4=new osobe[125+broj];
     polje5=new osobe[125+broj];
     poljebrza=new osobe[125+broj];
     char imena_m[20][300]={"Matija","Marko","Josip","Danijel","Igor","Denis","Ivan","Dean"
                            ,"Elvis","Zlatko","Tino","Filip","Tihomir","Mihael","Karlo","Ivo"
                            ,"Tomislav","Alen","Jadranko","Kresimir"};
     char imena_z[20][300]={"Anita","Mateja","Iva","Ana","Josipa","Andreja","Vanesa","Marta","Vlatka","Ines"
                                 ,"Magdalena","Manuela","Barbara","Petra","Natasa","Katarina","Matea","Rahela",
                                 "Dora","Valentina"};
     char prezimena[20][300]={"Anic","Ivic","Masic","Josipovic","Grabar","Martic","Kovac","Maric","Baric"
                                    ,"Svrakic","Bozic","Horvat","Gledic","Jaric","Beric","Stolic","Misic","Medved"
                                    ,"Mehic","Baric"};
     int brojac=0;
     bool ponovo;
     int ukupno=125;
     int kriterij[5][5];
     int ljudi=5;
     bool broj_ljudi;
     int spol,pom3;
     bool izadi=false;
     for(int i=0;i<5;i++)
             for(int j=0;j<5;j++)
                     kriterij[i][j]=5;
     for(int i=0;i<125;i++){
                             ponovo=false;
                             broj_ljudi=true;
                             spol=rand()%2;
                             if(spol==1){
                                        polje[brojac].spol='m';
                                        strcpy(polje[brojac].ime,imena_m[rand()%20]);
                                        strcpy(polje[brojac].prezime,prezimena[rand()%20]);
                             }
                             else{
                                 polje[brojac].spol='z';
                                 strcpy(polje[brojac].ime,imena_z[rand()%20]);
                                 strcpy(polje[brojac].prezime,prezimena[rand()%20]);
                             }
                             polje[brojac].dan=(rand()%31)+1;
                             polje[brojac].mjesec=(rand()%12)+1;
                             polje[brojac].godina=(rand()%80)+1935;
                             polje[brojac].ai=(rand()%491)+10;
                             polje[brojac].bi=(rand()%721)+80;
                             pom3=(rand()%5)+1;
                             if(pom3==3 && polje[brojac].spol=='m'){
                                        i--;
                                        continue;
                             }
                             if(pom3==5 && polje[brojac].godina>1954){
                                i--;
                                continue;
                             }
                             if(pom3==3 && polje[brojac].godina<1969){
                                        i--;
                                        continue;
                             }
                             polje[brojac].ci=pom3;
                             polje[brojac].di=(rand()%5)+1;
                             kriterij[polje[brojac].ci-1][polje[brojac].di-1]--;
                             for(int a=0;a<5;a++)
                                     for(int b=0;b<5;b++){
                                              if(kriterij[a][b]==-1)
                                                                    ponovo=true;
                                              if(kriterij[a][b]!=0)
                                                                   broj_ljudi=false; 
                                     }                       
                             if(ponovo){
                                        kriterij[polje[brojac].ci-1][polje[brojac].di-1]++;
                                        i--;
                                        continue;
                             }
                             if(broj_ljudi){
                                           ljudi--;
                                           i=0;
                                           for(int a=0;a<5;a++)
                                                   for(int b=0;b<5;b++)
                                                           kriterij[a][b]=5;
                             }
                             if(ljudi==0){
                                          izadi=true;
                                          break;
                             }
                                         
                             brojac++;                              
     }
     for(int i=125;i<broj;i++){
             spol=rand()%2;
             if(spol==1){
                         polje[i].spol='m';
                         strcpy(polje[i].ime,imena_m[rand()%20]);
                         strcpy(polje[i].prezime,prezimena[rand()%20]);
             }
             else{
                  polje[i].spol='z';
                  strcpy(polje[i].ime,imena_z[rand()%20]);
                  strcpy(polje[i].prezime,prezimena[rand()%20]);
             }
             polje[i].dan=(rand()%31)+1;
             polje[i].mjesec=(rand()%12)+1;
             polje[i].godina=(rand()%80)+1935;
             polje[i].ai=(rand()%491)+10;
             polje[i].bi=(rand()%721)+80;
             pom3=(rand()%5)+1;
             if(pom3==3 && polje[i].spol=='m'){
                        i--;
                        continue;
             }
             if(pom3==5 && polje[i].godina>1954){
                        i--;
                        continue;
             }
             if(pom3==3 && polje[i].godina<1969){
                        i--;
                        continue;
             }
             polje[i].ci=pom3;
             polje[i].di=(rand()%5)+1;
     
     }
     cout<<"-----------------------------------"<<endl;
     cout<<"Ljudi koji su dosli u postu"<<endl;
     for(int i=0;i<broj;i++){
             cout<<"-----------------------------------"<<endl;
             cout<<"spol:\t\t\t "<<polje[i].spol<<endl;
             cout<<"Ime:\t\t\t "<<polje[i].ime<<endl;
             cout<<"Prezime:\t\t "<<polje[i].prezime<<endl;
             cout<<"Prioritet cekanja:\t "<<polje[i].ci<<endl;
             cout<<"Vrijeme obrade:\t\t "<<polje[i].bi<<endl;
             cout<<"Datum rodenja:\t\t "<<polje[i].dan<<"."<<polje[i].mjesec<<"."<<polje[i].godina<<endl;
             
     }
     zadatak1=true;
}
void dodaj_u_red(){
     int salter=0;
     int salter1=0;
     int salter2=0;
     int salter3=0;
     int salter4=0;
     int salter5=0;
     int ukupno=0;
     int ukupno1=0;
     int ukupno2=0;
     int ukupno3=0;
     int ukupno4=0;
     int ukupno5=0;
     if(!zadatak1){
                   cout<<"-----------------------------------"<<endl;
                   cout<<"Prvo treba unijeti broj cetvorki"<<endl;
                   return;
     }
     if(zadatak3){
                  return;
     }
     for(int i=0;i<broj;i++){
             EnQueueQ(polje[i],Q);
             if(polje[i].di==1){
                                ukupno1+=polje[i].ai;
                                salter1+=polje[i].bi;
             }
             if(polje[i].di==2){
                                ukupno2+=polje[i].ai;
                                salter2+=polje[i].bi;
             }
             if(polje[i].di==3){
                                ukupno3+=polje[i].ai;
                                salter3+=polje[i].bi;
             }
             if(polje[i].di==4){
                                ukupno4+=polje[i].ai;
                                salter4+=polje[i].bi;
             }
             if(polje[i].di==5){
                                ukupno5+=polje[i].ai;
                                salter5+=polje[i].bi;
             }
     }
     
     for(int i=0;i<broj;i++){
             pomocna=FrontQ(Q);
             pomocna.broj=true;  
             DeQueueQ(Q);
             if(pomocna.di==1){
                               polje1[brojac1]=pomocna;
                               brojac1++;                                    
             }
             if(pomocna.di==2){
                               polje2[brojac2]=pomocna;
                               brojac2++;                                    
             }
             if(pomocna.di==3){
                               polje3[brojac3]=pomocna;
                               brojac3++;                                    
             }
             if(pomocna.di==4){
                               polje4[brojac4]=pomocna;
                               brojac4++;                                    
             }
             if(pomocna.di==5){
                               polje5[brojac5]=pomocna;
                               brojac5++;                                    
             }
     }
     polje1[0].broj=false;
     polje2[0].broj=false;
     polje3[0].broj=false;
     polje4[0].broj=false;
     polje5[0].broj=false;
     ukupno1-=polje1[0].bi;
     ukupno2-=polje2[0].bi;
     ukupno3-=polje3[0].bi;
     ukupno4-=polje4[0].bi;
     ukupno5-=polje5[0].bi;
     bool izadi=false;
     while(ukupno1>0){
                      for(int i=1;i<brojac1;i++){
                              if(polje1[i].broj && polje1[i].ci==1){                                                
                                                polje1[i].broj=false;
                                                ukupno1-=polje1[i].bi;
                                                if(ukupno1<0){
                                                             polje1[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac1;i++){
                              if(polje1[i].broj && polje1[i].ci==2){                                               
                                                polje1[i].broj=false;
                                                ukupno1-=polje1[i].bi;
                                                if(ukupno1<0){
                                                             polje1[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac1;i++){
                              if(polje1[i].broj && polje1[i].ci==3){                                             
                                                polje1[i].broj=false;
                                                ukupno1-=polje1[i].bi;
                                                if(ukupno1<0){
                                                             polje1[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac1;i++){
                              if(polje1[i].broj && polje1[i].ci==4){
                                                polje1[i].broj=false;
                                                ukupno1-=polje1[i].bi;
                                                if(ukupno1<0){
                                                             polje1[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac1;i++){
                              if(polje1[i].broj && polje1[i].ci==5){
                                                polje1[i].broj=false;
                                                ukupno1-=polje1[i].bi;
                                                if(ukupno1<0){
                                                             polje1[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
     }
     for(int j=0;j<brojac1;j++){
             if(polje1[j].broj)
                               EnQueueQ(polje1[j],A);
     }
     izadi=false;
     while(ukupno2>0){
                      for(int i=1;i<brojac2;i++){
                              if(polje2[i].broj && polje2[i].ci==1){                                                
                                                polje2[i].broj=false;
                                                ukupno2-=polje2[i].bi;
                                                if(ukupno2<0){
                                                             polje2[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac2;i++){
                              if(polje2[i].broj && polje2[i].ci==2){                                               
                                                polje2[i].broj=false;
                                                ukupno2-=polje2[i].bi;
                                                if(ukupno2<0){
                                                             polje2[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac2;i++){
                              if(polje2[i].broj && polje2[i].ci==3){                                             
                                                polje2[i].broj=false;
                                                ukupno2-=polje2[i].bi;
                                                if(ukupno2<0){
                                                             polje2[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac2;i++){
                              if(polje2[i].broj && polje2[i].ci==4){
                                                polje2[i].broj=false;
                                                ukupno2-=polje2[i].bi;
                                                if(ukupno2<0){
                                                             polje2[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac2;i++){
                              if(polje2[i].broj && polje2[i].ci==5){
                                                polje2[i].broj=false;
                                                ukupno2-=polje2[i].bi;
                                                if(ukupno2<0){
                                                             polje2[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
     }
     for(int j=0;j<brojac2;j++){
             if(polje2[j].broj)
                               EnQueueQ(polje2[j],B);
     }
     izadi=false;
     while(ukupno3>0){
                      for(int i=1;i<brojac3;i++){
                              if(polje3[i].broj && polje3[i].ci==1){                                                
                                                polje3[i].broj=false;
                                                ukupno3-=polje3[i].bi;
                                                if(ukupno3<0){
                                                             polje3[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac3;i++){
                              if(polje3[i].broj && polje3[i].ci==2){                                               
                                                polje3[i].broj=false;
                                                ukupno3-=polje3[i].bi;
                                                if(ukupno3<0){
                                                             polje3[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac3;i++){
                              if(polje3[i].broj && polje3[i].ci==3){                                             
                                                polje3[i].broj=false;
                                                ukupno3-=polje3[i].bi;
                                                if(ukupno3<0){
                                                             polje3[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac3;i++){
                              if(polje3[i].broj && polje3[i].ci==4){
                                                polje3[i].broj=false;
                                                ukupno3-=polje3[i].bi;
                                                if(ukupno3<0){
                                                             polje3[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac3;i++){
                              if(polje3[i].broj && polje3[i].ci==5){
                                                polje3[i].broj=false;
                                                ukupno3-=polje3[i].bi;
                                                if(ukupno3<0){
                                                             polje3[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
     }
     for(int j=0;j<brojac3;j++){
             if(polje3[j].broj)
                               EnQueueQ(polje3[j],C);
     }
     izadi=false;
     while(ukupno4>0){
                      for(int i=1;i<brojac4;i++){
                              if(polje4[i].broj && polje4[i].ci==1){                                                
                                                polje4[i].broj=false;
                                                ukupno4-=polje4[i].bi;
                                                if(ukupno4<0){
                                                             polje4[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac4;i++){
                              if(polje4[i].broj && polje4[i].ci==2){                                               
                                                polje4[i].broj=false;
                                                ukupno4-=polje4[i].bi;
                                                if(ukupno4<0){
                                                             polje4[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac4;i++){
                              if(polje4[i].broj && polje4[i].ci==3){                                             
                                                polje4[i].broj=false;
                                                ukupno4-=polje4[i].bi;
                                                if(ukupno4<0){
                                                             polje4[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac4;i++){
                              if(polje4[i].broj && polje4[i].ci==4){
                                                polje4[i].broj=false;
                                                ukupno4-=polje4[i].bi;
                                                if(ukupno4<0){
                                                             polje4[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac4;i++){
                              if(polje4[i].broj && polje4[i].ci==5){
                                                polje4[i].broj=false;
                                                ukupno4-=polje4[i].bi;
                                                if(ukupno4<0){
                                                             polje4[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
     }
     for(int j=0;j<brojac4;j++){
             if(polje4[j].broj)
                               EnQueueQ(polje4[j],D);
     }
     izadi=false;
     while(ukupno5>0){
                      for(int i=1;i<brojac5;i++){
                              if(polje5[i].broj && polje5[i].ci==1){                                                
                                                polje5[i].broj=false;
                                                ukupno5-=polje5[i].bi;
                                                if(ukupno5<0){
                                                             polje5[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac5;i++){
                              if(polje5[i].broj && polje5[i].ci==2){                                               
                                                polje5[i].broj=false;
                                                ukupno5-=polje5[i].bi;
                                                if(ukupno<0){
                                                             polje5[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac5;i++){
                              if(polje5[i].broj && polje5[i].ci==3){                                             
                                                polje5[i].broj=false;
                                                ukupno5-=polje5[i].bi;
                                                if(ukupno5<0){
                                                             polje5[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac5;i++){
                              if(polje5[i].broj && polje5[i].ci==4){
                                                polje5[i].broj=false;
                                                ukupno5-=polje5[i].bi;
                                                if(ukupno5<0){
                                                             polje5[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
                      for(int i=1;i<brojac5;i++){
                              if(polje5[i].broj && polje5[i].ci==5){
                                                polje5[i].broj=false;
                                                ukupno5-=polje5[i].bi;
                                                if(ukupno5<0){
                                                             polje5[i].broj=true;
                                                             izadi=true;
                                                             break;
                                                }
                              }
                      }
                      if(izadi) break;
     }
     for(int j=0;j<brojac5;j++){
             if(polje5[j].broj)
                               EnQueueQ(polje5[j],E);
     }
     cout<<"Osobe koje cekaju u redu za uplatu lutrije, mlade od 40 i po horoskopskom znaku su jarac"<<endl;
     for(int i=0;i<brojac3;i++){
             if(polje3[i].broj && polje3[i].godina<1974 && ((polje3[i].mjesec==12 && polje3[i].dan>=22) || (polje3[i].mjesec==11 && polje3[i].dan<=20))){
                               cout<<"-----------------------------------"<<endl;
                               cout<<"spol:\t\t\t "<<polje3[i].spol<<endl;
                               cout<<"Ime:\t\t\t "<<polje3[i].ime<<endl;
                               cout<<"Prezime:\t\t "<<polje3[i].prezime<<endl;
                               cout<<"Prioritet cekanja:\t "<<polje3[i].ci<<endl;
                               cout<<"Vrijeme obrade:\t\t "<<polje3[i].bi<<endl;
                               cout<<"Datum rodenja:\t\t "<<polje3[i].dan<<"."<<polje3[i].mjesec<<"."<<polje3[i].godina<<endl;                  
             }
     }
     zadatak2=true;
          
}
void trudnice(){
     if(!zadatak2){
                   cout<<"-----------------------------------"<<endl;
                   cout<<"Prvo pozovite funkciju za dodavanje zapisa u red"<<endl;
                   return;
     }
     for(int i=0;i<brojac5;i++){
             if(polje5[i].broj)
                               DeQueueQ(E);
     }
     for(int i=0;i<brojac5;i++){
             if(polje5[i].ci==3)
                                polje5[i].broj=false;
     }
     for(int i=0;i<brojac5;i++){
             if(polje5[i].broj)
                               EnQueueQ(polje5[i],E);       
     }
     zadatak3=true;
     for(int i=0;i<brojac1;i++){
             if(polje1[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje1[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje1[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje1[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje1[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje1[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje1[i].dan<<"."<<polje1[i].mjesec<<"."<<polje1[i].godina<<endl;
             }
     }
     for(int i=0;i<brojac2;i++){
             if(polje2[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje2[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje2[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje2[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje2[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje2[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje2[i].dan<<"."<<polje2[i].mjesec<<"."<<polje2[i].godina<<endl;
             }
     }
     for(int i=0;i<brojac3;i++){
             if(polje3[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje3[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje3[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje3[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje3[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje3[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje3[i].dan<<"."<<polje3[i].mjesec<<"."<<polje3[i].godina<<endl;
             }
     }
     for(int i=0;i<brojac4;i++){
             if(polje4[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje4[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje4[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje4[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje4[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje4[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje4[i].dan<<"."<<polje4[i].mjesec<<"."<<polje4[i].godina<<endl;
             }
     }
     for(int i=0;i<brojac5;i++){
             if(polje5[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje5[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje5[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje5[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje5[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje5[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje5[i].dan<<"."<<polje5[i].mjesec<<"."<<polje5[i].godina<<endl;
             }
     }
}
int rek1=0;
int rek2=0;
int rek3=0;
int rek4=0;
int rek5=0;
int brzabrojac=0;
void rekurzija1(){
     if(IsEmptyQ(E)){
                    return;
     }
     osobe pom=FrontQ(E);
     DeQueueQ(E);
     rekurzija1();
     if(pom.ci==4){
                   poljebrza[brzabrojac]=pom;
                   brzabrojac++;
     }
     
}
void rekurzija2(){
     if(IsEmptyQ(D)){
                    return;
     }
     osobe pom=FrontQ(D);
     DeQueueQ(D);
     rekurzija2();
     if(pom.ci==4){
                   poljebrza[brzabrojac]=pom;
                   brzabrojac++;
     }
     
}
void rekurzija3(){
     if(IsEmptyQ(C)){
                    return;
     }
     osobe pom=FrontQ(C);
     DeQueueQ(C);
     rekurzija3();
     if(pom.ci==4){
                   poljebrza[brzabrojac]=pom;
                   brzabrojac++;
     }
     
}
void rekurzija4(){
     if(IsEmptyQ(B)){
                    return;
     }
     osobe pom=FrontQ(B);
     DeQueueQ(B);
     rekurzija4();
     if(pom.ci==4){
                   poljebrza[brzabrojac]=pom;
                   brzabrojac++;
     }
     
}
void rekurzija5(){
     if(IsEmptyQ(A)){
                    return;
     }
     osobe pom=FrontQ(A);
     DeQueueQ(A);
     rekurzija5();
     if(pom.ci==4){
                   poljebrza[brzabrojac]=pom;
                   brzabrojac++;
     }
     
}
void brza_linija(){
     if(!zadatak1 || !zadatak2 || !zadatak3){
                 cout<<"-----------------------------------"<<endl;
                 cout<<"Prvo pozovite ostale funkcije"<<endl;
                 return;
     }
     if(zadatak4){
                  cout<<"-----------------------------------"<<endl;
                  cout<<"Ne mozete otvoriti novu brzu liniju"<<endl;
                  return;
     }
     zadatak4=true;
     poljebrza[brzabrojac]=FrontQ(E);
     DeQueueQ(E);
     brzabrojac++;
     poljebrza[brzabrojac]=FrontQ(E);
     DeQueueQ(E);
     brzabrojac++; 
     rekurzija1();
     reverse(poljebrza+2,poljebrza+brzabrojac);
     int pocetak=brzabrojac;
     poljebrza[brzabrojac]=FrontQ(D);
     DeQueueQ(D);
     brzabrojac++;
     poljebrza[brzabrojac]=FrontQ(D);
     DeQueueQ(D);
     brzabrojac++;  
     rekurzija2();
     reverse(poljebrza+pocetak+2,poljebrza+brzabrojac);
     pocetak=brzabrojac;
     poljebrza[brzabrojac]=FrontQ(C);
     DeQueueQ(C);
     brzabrojac++;
     poljebrza[brzabrojac]=FrontQ(C);
     DeQueueQ(C);
     brzabrojac++;
     rekurzija3();
     reverse(poljebrza+pocetak+2,poljebrza+brzabrojac);
     pocetak=brzabrojac;
     poljebrza[brzabrojac]=FrontQ(B);
     DeQueueQ(B);
     brzabrojac++;
     poljebrza[brzabrojac]=FrontQ(B);
     DeQueueQ(B);
     brzabrojac++;
     rekurzija4();
     reverse(poljebrza+pocetak+2,poljebrza+brzabrojac);
     pocetak=brzabrojac;
     poljebrza[brzabrojac]=FrontQ(A);
     DeQueueQ(A);
     brzabrojac++;
     poljebrza[brzabrojac]=FrontQ(A);
     DeQueueQ(A);
     brzabrojac++;
     rekurzija5();
     reverse(poljebrza+pocetak+2,poljebrza+brzabrojac);  
     polje1[0].broj=false;
     polje1[1].broj=false;
     for(int i=0;i<brojac1;i++){
             if(polje1[i].ci==4)
                                polje1[i].broj=false;        
     }
     polje2[0].broj=false;
     polje2[1].broj=false;
     for(int i=0;i<brojac2;i++){
             if(polje2[i].ci==4)
                                polje2[i].broj=false;        
     }
     polje3[0].broj=false;
     polje3[1].broj=false;
     for(int i=0;i<brojac3;i++){
             if(polje3[i].ci==4)
                                polje3[i].broj=false;        
     }
     polje4[0].broj=false;
     polje4[1].broj=false;
     for(int i=0;i<brojac4;i++){
             if(polje4[i].ci==4)
                                polje4[i].broj=false;        
     }
     polje5[0].broj=false;
     polje5[1].broj=false;
     for(int i=0;i<brojac5;i++){
             if(polje5[i].ci==4)
                                polje5[i].broj=false;        
     }
     for(int i=0;i<brojac1;i++){
             if(polje1[i].broj)
                               EnQueueQ(polje1[i],A);
     }
     for(int i=0;i<brojac2;i++){
             if(polje2[i].broj)
                               EnQueueQ(polje2[i],B);
     }
     for(int i=0;i<brojac3;i++){
             if(polje3[i].broj)
                               EnQueueQ(polje3[i],C);
     }
     for(int i=0;i<brojac4;i++){
             if(polje4[i].broj)
                               EnQueueQ(polje4[i],D);
     }
     for(int i=0;i<brojac5;i++){
             if(polje5[i].broj)
                               EnQueueQ(polje5[i],E);
     }
     cout<<"-----------------------------------"<<endl;
     cout<<"Stanje na salteru za preuzimanje posiljke je: "<<endl;
     for(int i=0;i<brojac1;i++){
             if(polje1[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje1[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje1[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje1[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje1[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje1[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje1[i].dan<<"."<<polje1[i].mjesec<<"."<<polje1[i].godina<<endl;
             }
     }
     cout<<"-----------------------------------"<<endl;
     cout<<"Stanje na salteru za placanje racuna je: "<<endl;
     for(int i=0;i<brojac2;i++){
             if(polje2[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje2[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje2[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje2[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje2[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje2[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje2[i].dan<<"."<<polje2[i].mjesec<<"."<<polje2[i].godina<<endl;
             }
     }
     cout<<"-----------------------------------"<<endl;
     cout<<"Stanje na salteru za uplatu lutrije je: "<<endl;
     for(int i=0;i<brojac3;i++){
             if(polje3[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje3[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje3[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje3[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje3[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje3[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje3[i].dan<<"."<<polje3[i].mjesec<<"."<<polje3[i].godina<<endl;
             }
     }
     cout<<"-----------------------------------"<<endl;
     cout<<"Stanje na salteru za Westren Union je: "<<endl;
     for(int i=0;i<brojac4;i++){
             if(polje4[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje4[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje4[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje4[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje4[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje4[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje4[i].dan<<"."<<polje4[i].mjesec<<"."<<polje4[i].godina<<endl;
             }
     }
     cout<<"-----------------------------------"<<endl;
     cout<<"Stanje na salteru za EvoTV je: "<<endl;
     for(int i=0;i<brojac5;i++){
             if(polje5[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<polje5[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<polje5[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<polje5[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<polje5[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<polje5[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<polje5[i].dan<<"."<<polje5[i].mjesec<<"."<<polje5[i].godina<<endl;
             }
     }
     cout<<"-----------------------------------"<<endl;
     cout<<"Stanje na salteru za brzu liniju je: "<<endl;
     for(int i=0;i<brzabrojac;i++){
             if(poljebrza[i].broj){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"spol:\t\t\t "<<poljebrza[i].spol<<endl;
                                cout<<"Ime:\t\t\t "<<poljebrza[i].ime<<endl;
                                cout<<"Prezime:\t\t "<<poljebrza[i].prezime<<endl;
                                cout<<"Prioritet cekanja:\t "<<poljebrza[i].ci<<endl;
                                cout<<"Vrijeme obrade:\t\t "<<poljebrza[i].bi<<endl;
                                cout<<"Datum rodenja:\t\t "<<poljebrza[i].dan<<"."<<poljebrza[i].mjesec<<"."<<poljebrza[i].godina<<endl;
             }
     }
     
}
int main(){
    Q=InitQ(Q);
    A=InitQ(A);
    B=InitQ(B);
    C=InitQ(C);
    D=InitQ(D);
    E=InitQ(E);
    brza=InitQ(brza);
    srand(time(0));
    rand();
    int x;
    do{
        cout<<"-----------------------------------"<<endl;
        cout<<"Unesite 1 za generiranje n cetvorki"<<endl;
        cout<<"Unesite 2 za dodavanje zapisa u red"<<endl;
        cout<<"Unesite 3 za izbacivanje trudnica koje su dolse na red za EvoTv"<<endl;
        cout<<"Unesite 4 za uvodenje brze linije"<<endl;
        cin>>x;
        switch(x){
                  case 1:cetvorke();break;
                  case 2:dodaj_u_red();break;
                  case 3:trudnice();break;
                  case 4:brza_linija();break;
        }
    }while(x!=9);
}
