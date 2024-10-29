#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    char nombre [5][20];
    int opc;
     int opc1;
    int est;
    int edad=5;


nombres(nombre);
printf("En el siguiente menu podra\n 1. buscar por estado civil\n 2. Buscar por edad\n");
scanf("%d",&opc);
switch (opc)
{
case 1:
    estado_c(est);
    cont_est_c(est);
    break;
case 2:
edades(edad);
cont_edad(edad);

printf("desea otra opcion:\n 1. Si \n2.No");
if (opc1=1)
{
 return 1;
}else 
default:
    break;
}
}
