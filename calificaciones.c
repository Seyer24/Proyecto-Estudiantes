#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calificaciones.h"

static float leer_calificacion() {
    char buf[32];
    float val;
    while (1) {
        if (scanf("%31s", buf) != 1) {
            while (getchar() != '\n');
            printf("     Ingrese solo numeros (ej: 0 o 9.99): ");
            continue;
        }
        /* Validar: solo digitos y a lo mas un punto con maximo 2 decimales */
        int puntos = 0, decimales = 0, pos_punto = -1, valido = 1;
        int len = strlen(buf);
        for (int j = 0; j < len; j++) {
            if (buf[j] == '.') {
                puntos++;
                pos_punto = j;
                if (puntos > 1) { valido = 0; break; }
            } else if (!isdigit((unsigned char)buf[j])) {
                valido = 0; break;
            }
        }
        if (pos_punto != -1)
            decimales = len - pos_punto - 1;
        if (!valido || puntos > 1 || decimales > 2 || len == 0) {
            printf("     Solo numeros con hasta 2 decimales (ej: 85 o 9.75): ");
            continue;
        }
        sscanf(buf, "%f", &val);
        return val;
    }
}

void capturar_calificaciones(Estudiante *e) {
    printf("\nMaterias y calificaciones para %s:\n", e->nombre);
    printf("(Para cada materia: 1 = cursa, 0 = no cursa)\n\n");
    for (int i = 0; i < MAX_MATERIAS; i++) {
        int sel;
        printf("  %d. %-32s cursa (1/0): ", i + 1, NOMBRES_MATERIAS[i]);
        while (scanf("%d", &sel) != 1 || (sel != 0 && sel != 1)) {
            while (getchar() != '\n');
            printf("     Solo ingrese 1 (cursa) o 0 (no cursa): ");
        }
        e->materias_inscritas[i] = (sel == 1) ? 1 : 0;
        if (e->materias_inscritas[i]) {
            printf("     Calificacion: ");
            e->calificaciones[i] = leer_calificacion();
        }
    }
}

float calcular_promedio(Estudiante *e) {
    float suma = 0.0f;
    int count = 0;
    for (int i = 0; i < MAX_MATERIAS; i++) {
        if (e->materias_inscritas[i]) {
            suma += e->calificaciones[i];
            count++;
        }
    }
    return count > 0 ? suma / count : 0.0f;
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
    printf("Promedio general del grupo: %.2f\n", suma / total);
    printf("Promedio mas alto:          %.2f\n", max);
    printf("Promedio mas bajo:          %.2f\n", min);

    printf("\n--- Promedio por materia ---\n");
    for (int m = 0; m < MAX_MATERIAS; m++) {
        float s = 0.0f;
        int count = 0;
        for (int i = 0; i < total; i++) {
            if (estudiantes[i].materias_inscritas[m]) {
                s += estudiantes[i].calificaciones[m];
                count++;
            }
        }
        if (count > 0)
            printf("  %-32s %.2f  (%d alumno%s)\n",
                   NOMBRES_MATERIAS[m], s / count, count, count == 1 ? "" : "s");
        else
            printf("  %-32s Sin inscritos\n", NOMBRES_MATERIAS[m]);
    }
}
