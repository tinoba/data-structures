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
       int rear,front;
       osobe x[1000];
};
red *InitQ(red *Q){
     Q=new red;
     Q->front=0;
     Q->rear=999;  
     return Q;  
}
osobe FrontQ(red *Q){
      return Q->x[Q->front];
}
void EnQueueQ(osobe x, red *Q){
     Q->rear=(Q->rear+1)%1000;
     Q->x[Q->rear]=x;
}
void DeQueueQ(red *Q){
     Q->front=(Q->front+1)%1000;
}
bool IsEmptyQ(red *Q){
     if((Q->rear+1)%1000==Q->front)
                                   return true;
     else
         return false;
}
