#include<stdio.h>
#include<stdarg.h>
#ifdef DEPRINTF
int deprintf(char*s,...){
va_list v;
va_start(v, s);
vprintf(s, v);
va_end(v);
return 0;
}
#else
int deprintf(char*_,...){return 0;}
#endif
