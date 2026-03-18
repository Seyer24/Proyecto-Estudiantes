#include <stdio.h>
#include "reportes.h"
#include "calificaciones.h"

void reporte_aprobados_reprobados(Estudiante estudiantes[], int total) {
    printf("\n--- Aprobados ---\n");
    int aprobados = 0;
    for (int i = 0; i < total; i++) {
        if (calcular_promedio(&estudiantes[i]) >= CALIFICACION_APROBATORIA) {
            printf("  %s (%.2f)\n", estudiantes[i].nombre, calcular_promedio(&estudiantes[i]));
            aprobados++;
        }
    }

    printf("\n--- Reprobados ---\n");
    for (int i = 0; i < total; i++) {
        if (calcular_promedio(&estudiantes[i]) < CALIFICACION_APROBATORIA) {
            printf("  %s (%.2f)\n", estudiantes[i].nombre, calcular_promedio(&estudiantes[i]));
        }
    }

    printf("\nTotal aprobados: %d / %d\n", aprobados, total);
}

void ranking_mejores(Estudiante estudiantes[], int total) {
    /* Ordenamiento burbuja por promedio descendente (copia local de indices) */
    int orden[MAX_ESTUDIANTES];
    for (int i = 0; i < total; i++) orden[i] = i;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (calcular_promedio(&estudiantes[orden[j]]) >
                calcular_promedio(&estudiantes[orden[i]])) {
                int tmp = orden[i];
                orden[i] = orden[j];
                orden[j] = tmp;
            }
        }
    }

    printf("\n--- Ranking de mejores estudiantes ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d. %s - %.2f\n", i + 1,
               estudiantes[orden[i]].nombre,
               calcular_promedio(&estudiantes[orden[i]]));
    }
}

void estadisticas_generales(Estudiante estudiantes[], int total) {
    printf("\n--- Estadisticas Generales ---\n");
    printf("Total de estudiantes: %d\n", total);
    reporte_aprobados_reprobados(estudiantes, total);
    ranking_mejores(estudiantes, total);
}
