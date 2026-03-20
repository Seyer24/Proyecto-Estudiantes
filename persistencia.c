#include <stdio.h>
#include "persistencia.h"

void guardar_salon(Estudiante estudiantes[], int total) {
    FILE *f = fopen(ARCHIVO_DAT, "wb");
    if (!f) {
        printf("Error: no se pudo guardar el archivo %s\n", ARCHIVO_DAT);
        return;
    }
    fwrite(&total, sizeof(int), 1, f);
    fwrite(estudiantes, sizeof(Estudiante), total, f);
    fclose(f);
    printf("Datos guardados en %s\n", ARCHIVO_DAT);
}

int cargar_salon(Estudiante estudiantes[]) {
    FILE *f = fopen(ARCHIVO_DAT, "rb");
    if (!f) return 0;  // Si no existe el archivo, empieza vacio

    int total = 0;
    fread(&total, sizeof(int), 1, f);
    fread(estudiantes, sizeof(Estudiante), total, f);
    fclose(f);
    printf("Datos cargados: %d estudiante(s) en memoria.\n", total);
    return total;
}
