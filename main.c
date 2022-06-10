#include"./tobase.c"
//#include"./printfi.c"
int testtobase(int v,int base);
int ciclebase(int v,int cbase,int tbase,int);

int main(int an,char**as){
//testtobase(100,10);return 0;
for(int i=1;i<10;++i){
int v=1000*i;   //starting value
int tbase=8;//test base/starting value base
int cbase=10;//converting base
int maxdepth=100;
printf("v=%i,tbase=%i,cbase=%i,maxdepth=%i\n",v,tbase,cbase,maxdepth);
int d=ciclebase(v,cbase,tbase,maxdepth);
printf("Depth=%i\n\n",d);
}
free(_pushes);
printf("Terminated\n");
return 0;
}

int ciclebase(int v,int cbase,int tbase,int maxdepth){
//testtobase(4560,10);return 0;

int depth=-1;
triplex b=tobase(v,tbase);

//printf("Converting value of base %i into base %i while any digit of %s %i %s ",
//tbase,cbase,"converted value is of base", tbase,"starting from");

for(;depth<maxdepth;){
int*arr=(int*)b.a;
int len=*(int*)b.b;
int notintestbase=0;
for(int i=0;i<len;++i){
if(tbase<=arr[i]){
	printf("<%i>",arr[i]);
	notintestbase=1;
}else{
	printf("[%i]",arr[i]);
}
}
printf("\n");
if(notintestbase){
//printf("Last value is not in testbase, depth=%i. ",depth);
goto exit;
}
++depth;
v=basetoval(b,tbase);
b=tobase(v,cbase);
}
//printf("Value still in testbase but maxdepth=%i exceeded. ",maxdepth);
exit:
//free(b.a);
//if(depth<0)printf("Negative depth means value was already not in test base. ");
//printf("Terminated\n");
return depth;
}

int testtobase(int v,int base){
triplex b=tobase(v,base);
printf("base %i 0f %i is ",base,v);
for(int i=0;i<*(int*)b.b;++i)printf("[%i]",((int*)b.a)[i]);
//printf("%i %i %i",(*(int*)b.b),*(int*)b.c,((int*)b.a)[0]);
printf("\n");
int rv=basetoval(b,base);
printf("Reversed value is %i (%s)\n",rv,rv==v?"correct":"incorrect");
free(b.a);//triplex_flush(b);
return 0;
}
