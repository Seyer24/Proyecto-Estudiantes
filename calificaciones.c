#include <stdio.h>
#include "calificaciones.h"

void capturar_calificaciones(Estudiante *e) {
    printf("Numero de materias (max %d): ", MAX_MATERIAS);
    scanf("%d", &e->num_materias);
    if (e->num_materias > MAX_MATERIAS) e->num_materias = MAX_MATERIAS;

    for (int i = 0; i < e->num_materias; i++) {
        printf("Calificacion materia %d: ", i + 1);
        scanf("%f", &e->calificaciones[i]);
    }
}

float calcular_promedio(Estudiante *e) {
    if (e->num_materias == 0) return 0.0f;
    float suma = 0.0f;
    for (int i = 0; i < e->num_materias; i++)
        suma += e->calificaciones[i];
    return suma / e->num_materias;
}

void estadisticas_grupo(Estudiante estudiantes[], int total) {
    if (total == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    float suma = 0.0f, max = -1.0f, min = 101.0f;
    for (int i = 0; i < total; i++) {
        float prom = calcular_promedio(&estudiantes[i]);
        suma += prom;
        if (prom > max) max = prom;
        if (prom < min) min = prom;
    }

    printf("\n--- Estadisticas del grupo ---\n");
    printf("Promedio general: %.2f\n", suma / total);
    printf("Promedio mas alto: %.2f\n", max);
    printf("Promedio mas bajo: %.2f\n", min);
}
