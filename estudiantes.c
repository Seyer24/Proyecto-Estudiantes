#include <stdio.h>
#include <string.h>
#include "estudiantes.h"

void registrar_estudiante(Estudiante estudiantes[], int *total) {
    if (*total >= MAX_ESTUDIANTES) {
        printf("No se pueden registrar mas estudiantes.\n");
        return;
    }

    Estudiante *e = &estudiantes[*total];

    printf("ID del estudiante: ");
    scanf("%d", &e->id);
    printf("Nombre: ");
    scanf(" %[^\n]", e->nombre);
    printf("Carrera: ");
    scanf(" %[^\n]", e->carrera);
    e->num_materias = 0;

    (*total)++;
    printf("Estudiante registrado correctamente.\n");
}

Estudiante* buscar_por_id(Estudiante estudiantes[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (estudiantes[i].id == id)
            return &estudiantes[i];
    }
    return NULL;
}

Estudiante* buscar_por_nombre(Estudiante estudiantes[], int total, const char *nombre) {
    for (int i = 0; i < total; i++) {
        if (strcmp(estudiantes[i].nombre, nombre) == 0)
            return &estudiantes[i];
    }
    return NULL;
}

void mostrar_lista(Estudiante estudiantes[], int total) {
    if (total == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }
    printf("\n%-5s %-30s %-20s\n", "ID", "Nombre", "Carrera");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-5d %-30s %-20s\n",
               estudiantes[i].id,
               estudiantes[i].nombre,
               estudiantes[i].carrera);
    }
}
