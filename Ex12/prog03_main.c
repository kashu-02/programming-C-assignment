#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prog03.h"

int main() {
  int i;
  Planet psolsys[NPLANETS];

  if( input_planet( psolsys ) != 0 ){
    fprintf(stderr, "Input Error!\n");
    exit(3);
  }

  for (i = 0; i < NPLANETS; i++) {
    printf("Name: %s\n", psolsys[i].name);
    printf("  Radius: %.0f [km]\n", psolsys[i].radius);          /* 半径 */
    printf("  Density: %.2f [g/cm3]\n", psolsys[i].density);     /* 密度 */
    printf("  Orbital Radius: %.3e [km]\n", psolsys[i].orbital_radius);   /* 軌道半径 */
  }
		  
  return 0;
}

#ifdef TEST0 /* 単体テスト用 input_planet 正常動作（戻り値 0 ）の場合 */
int input_planet(Planet *planet) {
  int i;
  for (i = 0; i < NPLANETS; i++) {
    strcpy(planet[i].name, "Sample");     /* テスト用のサンプルデータ */
    planet[i].radius = 1000;
    planet[i].density = 1.00;
    planet[i].orbital_radius = 100000000;
  }
  return 0;
}
#elif TEST1 /* 単体テスト用 input_planet 異常動作（戻り値 -1 ）の場合 */
int input_planet(Planet *planet) {
    return -1;
}
#endif