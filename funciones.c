#include <stdio.h>
#include "funciones.h"
void nombres(char nombre[5][20]){
printf("Ingrese su nombre: \n");
scanf("%c",&nombre);
}

void edades(int edad){
printf("Ingrese su edad:\n 1.Si esta entres los 0-18 años\n 2. si esta entre 19-50\n 3.Si pasa de los 50");
scanf("%d",&edad);
}

void estado_c(int est){
   printf("Ingrese su estado civil: \n 1.soltero\n 2.Casado\n");
   scanf("%d",&est); 
}

void cont_est_c(int est){
for (int i = 0; i < 5; i++)
{

if (est=1)
{
   printf("Los solteros son %d",est);
}
if (est=2)
{
    printf("Los casados son %d",est);
}
if(est>= 3 || est <= 0)
{
    printf("No existe esa opcion");
} 
}
}


void cont_edad(int edad){
for (int i = 0; i < 5; i++)
{
if (edad=1)
{
  printf("Los que tienen un rango de edad de 0-18 años son: %d",edad);

}
if (edad=2)
{
  printf("Los que tienen un rango de edad de 19-21 años son: %d",edad);

}
if (edad=3)
{
  printf("Los que tienen un rango de edad mayor a los 50 años son: %d",edad);

}if (edad<=4 || edad>0)
{
 printf("Numero incorrecto");
}
}
}
