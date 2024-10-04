#include <stdio.h>
#include <string.h>

#define NUM_ESTUDIANTES 5
#define NUM_ASIGNATURAS 3
#define MAX_NOMBRE 50

int main(int argc, char *argv[]) {
    double calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS];
    double prom_estudiantes[NUM_ESTUDIANTES] = {0};
    double prom_asignaturas[NUM_ASIGNATURAS] = {0};

    double max_estudiantes[NUM_ESTUDIANTES] = {0};
    double min_estudiantes[NUM_ESTUDIANTES] = {10};
    double max_asignatura[NUM_ASIGNATURAS] = {0};
    double min_asignatura[NUM_ASIGNATURAS] = {10};

    int apro_asig[NUM_ASIGNATURAS] = {0};
    int repro_asig[NUM_ASIGNATURAS] = {0};     

    char nombres_estudiantes[NUM_ESTUDIANTES][MAX_NOMBRE];
    char nombres_asignaturas[NUM_ASIGNATURAS][MAX_NOMBRE];

    // Ingreso de nombres de estudiantes
    printf("Ingrese los nombres de los estudiantes:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Estudiante %d: ", i + 1);
        fgets(nombres_estudiantes[i], MAX_NOMBRE, stdin);
        nombres_estudiantes[i][strcspn(nombres_estudiantes[i], "\n")] = '\0';  
    }

    // Ingreso de nombres de asignaturas
    printf("\nIngrese los nombres de las asignaturas:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("Asignatura %d: ", j + 1);
        fgets(nombres_asignaturas[j], MAX_NOMBRE, stdin);
        nombres_asignaturas[j][strcspn(nombres_asignaturas[j], "\n")] = '\0';  
    }

    // Entrada de calificaciones
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("\n-- Estudiante %s ---\n", nombres_estudiantes[i]);
        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            do {
                printf("Ingrese la calificacion para %s: ", nombres_asignaturas[j]);
                scanf("%lf", &calificaciones[i][j]);
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);

            // Actualización de promedios
            prom_estudiantes[i] += calificaciones[i][j];
            prom_asignaturas[j] += calificaciones[i][j];

            // Actualización de máximos y mínimos por estudiante
            if (calificaciones[i][j] > max_estudiantes[i]) {
                max_estudiantes[i] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < min_estudiantes[i]) {
                min_estudiantes[i] = calificaciones[i][j];
            }

            // Actualización de máximos y mínimos por asignatura
            if (calificaciones[i][j] > max_asignatura[j]) {
                max_asignatura[j] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < min_asignatura[j]) {
                min_asignatura[j] = calificaciones[i][j];
            }

            // Conteo de aprobados y reprobados por asignatura
            if (calificaciones[i][j] >= 6) {
                apro_asig[j]++;
            } else {
                repro_asig[j]++;
            }
        }
    }

    // Cálculo de promedios
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        prom_estudiantes[i] /= NUM_ASIGNATURAS;
    }
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        prom_asignaturas[j] /= NUM_ESTUDIANTES;
    }

    // Impresión de resultados en forma de matriz
    printf("\n---- RESULTADOS ----\n");

    // Resultados por estudiante
    printf("\nResultados por estudiante:\n");
    printf("Estudiante  \tPromedio  \tMaximo   \tMinimo\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", nombres_estudiantes[i], prom_estudiantes[i], max_estudiantes[i], min_estudiantes[i]);
    }

    // Resultados por asignatura
      printf("\nResultados por asignatura:\n");
    printf("Asignatura\tPromedio\tMaximot\t\tMinimo\t\tAprobados\tReprobados\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%-15s\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%d\t\t%d\n", 
               nombres_asignaturas[j], 
               prom_asignaturas[j], 
               max_asignatura[j], 
               min_asignatura[j], 
               apro_asig[j], 
               repro_asig[j]);
    }
    return 0;
}
