using namespace std;
struct osobe{
       char ime[30];
       char prezime[30];
       bool broj;
       char spol;
       int dan;   
       int mjesec;
       int godina; 
       int ai;
       int bi;
       int ci;
       int di;        
};
struct red{
       red *rear;
       red *front;
       red *sljedeci;
       osobe x;
};
red *InitQ(red *Q){
     Q=new red;
     Q->rear=Q;
     Q->front=Q;
     Q->sljedeci=NULL;
     return Q;
}
osobe FrontQ(red *Q){
      red *trenutni=Q->front;
      trenutni=trenutni->sljedeci;
      return trenutni->x;
}
void EnQueueQ(osobe x, red *Q){
     red *trenutni=Q->rear;
     red *novi = new red;
     novi->x=x;
     novi->sljedeci=NULL;
     trenutni->sljedeci=novi;
     Q->rear=novi;
}
void DeQueueQ(red *Q){
     if(Q->sljedeci==NULL){
                           cout<<"Red ne sadrzi elemente"<<endl;
                           return;
     }
     red *trenutni=Q->sljedeci;
     Q->sljedeci=trenutni->sljedeci;
     delete trenutni;
     if(Q->sljedeci==NULL)
                          Q->rear=Q;
}
bool IsEmptyQ(red *Q){
     if(Q->rear==Q->front)
                          return true;
     else
         return false;
}

