#include <stdio.h>

int main(){
  char c;
  short s;
  int i;
  long l;
  float f;
  double d;

  char cc[10];
  short ss[10];
  int ii[10];
  long ll[10];
  float ff[10];
  double dd[10];

  printf("sizeof(char  ) : %d\n",sizeof(c));
  printf("sizeof(short ) : %d\n",sizeof(s));
  printf("sizeof(int   ) : %d\n",sizeof(i));
  printf("sizeof(long  ) : %d\n",sizeof(l));
  printf("sizeof(float ) : %d\n",sizeof(f));
  printf("sizeof(double) : %d\n",sizeof(d));

  printf("sizeof(char[10]  ) : %d\n",sizeof(cc));
  printf("sizeof(short[10] ) : %d\n",sizeof(ss));
  printf("sizeof(int[10]   ) : %d\n",sizeof(ii));
  printf("sizeof(long[10]  ) : %d\n",sizeof(ll));
  printf("sizeof(float[10] ) : %d\n",sizeof(ff));
  printf("sizeof(double[10]) : %d\n",sizeof(dd));
  
  return 0;
}