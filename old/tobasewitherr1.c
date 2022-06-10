// so https://78bbm3rv7ks4b6i8j3cuklc1-wpengine.netdna-ssl.com/wp-content/uploads/tutoring/handouts/Change-of-Number-Bases.pdf
#include<stdio.h>
#include<stdlib.h>
//#define DEPRINTF
#include"deprintf.c"
int powof(int,int);
int*_pushes;
int _pushescap=0;
int _pusheslen=0;
int push(int);

int main(){
//printf("hello\n");deprintf("world\n");return 0;
//step 1-3.
_pusheslen=0;
int v=326;
int base=8;
//printf("%i\n",powof(2,3));return 0;
int i=0;
for(;;++i){
int p=powof(base,i);
//printf("%i\n",p);if(i>4)return 0;
if(p>=v){
deprintf("i=%i p=%i\n",i,p);
break;}
if(p<0){printf("%i ** %i is too big for sizeof %li. Terminated\n",
v,i,sizeof(int));goto exit;}
}
//step 4-9.
for(--i;i>=0;--i){
int p=powof(base,i);
if(p>=v){
deprintf("zero\n");
if(push(0)<0)goto exit;
continue;
}
int t=v/p;
if(push(t)<0)goto exit;
v%=p;
deprintf("t=%i p=%i i=%i new v=%i\n",t,p,i,v);
}
//output
for(int i=0;i<_pusheslen;++i)printf("%i ",_pushes[i]);
printf("\n");
//done
exit:
free(_pushes);
return 0;
}

int powof(int v,int by){//positive power of
if(by==0)return 1;
int r=v;
for(int i=1;i<by;++i)r*=v;
return r;
}

int push(int v){
const int capacc=4;//capacity accumulator
if(_pusheslen>=_pushescap){
deprintf("'push' resized %i+%i\n",_pusheslen,capacc);
_pushescap+=capacc;
void*ptr=realloc(_pushes,_pushescap*sizeof(int));
if(!ptr){printf("Reallocation error. Terminated\n");return-1;}
_pushes=ptr;
}
_pushes[_pusheslen]=v;
++_pusheslen;
return 0;
}
