// so https://78bbm3rv7ks4b6i8j3cuklc1-wpengine.netdna-ssl.com/wp-content/uploads/tutoring/handouts/Change-of-Number-Bases.pdf
#pragma once
#include<stdio.h>
#include<stdlib.h>
//#define DEPRINTF
//#include"deprintf.c"
int powof(int,int);
int*_pushes;
int _pushescap=0;
int _pusheslen=0;
int push(int);
typedef struct{void*a;void*b;void*c;}triplex;

triplex tobase(int v,int base){
//printf("hello\n");deprintf("world\n");return 0;
//step 1-3.
_pusheslen=0;
//int v=326;int base=8;
//printf("%i\n",powof(2,3));return 0;
int i=0;
for(;;++i){
int p=powof(base,i);
//printf("%i\n",p);if(i>4)return 0;
if(p>=v){
//printf("i=%i p=%i\n",i,p);
break;}
if(p<0){printf("%i ** %i is too big for sizeof %li. Terminated\n",
v,i,sizeof(int));goto exit;}
}
//step 4-9.
for(--i;i>=0;--i){
int p=powof(base,i);
if(p>=v){
//printf("zero\n");
if(push(0)<0)goto exit;
continue;
}
int t=v/p;
// t can be eq. to base somehow. If so, pushing these to values instead
if(t==base){
	if(push(1)<0)goto exit;
	if(push(0)<0)goto exit;
}
else
{
	if(push(t)<0)goto exit;
}
v%=p;
//printf("t=%i p=%i i=%i new v=%i\n",t,p,i,v);
}
//output
//printf("tobase output: ");
//for(int i=0;i<_pusheslen;++i)printf("%i ",_pushes[i]);
//printf("\n");
//done
exit:
//free(_pushes);
return (triplex){_pushes,&_pusheslen,&_pushescap};
}

// utils

int powof(int v,int by){//positive power of
if(by==0)return 1;
int r=v;
for(int i=1;i<by;++i)r*=v;
return r;
}

int push(int v){
const int capacc=4;//capacity accumulator
if(_pusheslen>=_pushescap){
//printf("_push resized %i+%i\n",_pusheslen,capacc);
_pushescap+=capacc;
void*ptr=realloc(_pushes,_pushescap*sizeof(int));
if(!ptr){printf("Reallocation error. Terminated\n");return-1;}
_pushes=ptr;
}
_pushes[_pusheslen]=v;
++_pusheslen;
return 0;
}

// tail

void triplex_flush(triplex t){
free(t.a);
free(t.b);
free(t.c);
}

int basetoval(triplex b,int base){
int len=*(int*)b.b;
int*arr=(int*)b.a;
int v=0;
for(int i=0;i<len;++i)v+=arr[i]*powof(base,len-i-1);
return v;
}
