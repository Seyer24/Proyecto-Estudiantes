#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "estudiantes.h"

static int solo_letras_espacios(const char *s) {
    if (s[0] == '\0') return 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isalpha((unsigned char)s[i]) && s[i] != ' ')
            return 0;
    }
    return 1;
}

const char *NOMBRES_MATERIAS[MAX_MATERIAS] = {
    "Metodologia",
    "Organizacion de Computadoras",
    "Lenguaje C",
    "Requerimientos",
    "Programacion Estructurada",
    "Matematicas Discretas"
};

void registrar_estudiante(Estudiante estudiantes[], int *total) {
    if (*total >= MAX_ESTUDIANTES) {
        printf("No se pueden registrar mas estudiantes.\n");
        return;
    }

    int nuevo_id;
    printf("ID del estudiante: ");
    if (scanf("%d", &nuevo_id) != 1) {
        printf("Error: el ID debe ser un numero entero.\n");
        while (getchar() != '\n');
        return;
    }
    if (nuevo_id <= 0) {
        printf("Error: el ID debe ser un numero positivo mayor a 0.\n");
        return;
    }
    if (buscar_por_id(estudiantes, *total, nuevo_id) != NULL) {
        printf("Error: ya existe un estudiante con el ID %d.\n", nuevo_id);
        return;
    }

    Estudiante *e = &estudiantes[*total];
    e->id = nuevo_id;

    printf("Nombre: ");
    scanf(" %[^\n]", e->nombre);
    if (!solo_letras_espacios(e->nombre)) {
        printf("Error: el nombre solo puede contener letras y espacios.\n");
        return;
    }

    printf("Carrera: ");
    scanf(" %[^\n]", e->carrera);
    if (!solo_letras_espacios(e->carrera)) {
        printf("Error: la carrera solo puede contener letras y espacios.\n");
        return;
    }

    for (int i = 0; i < MAX_MATERIAS; i++) {
        e->materias_inscritas[i] = 0;
        e->calificaciones[i]     = 0.0f;
    }

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
    printf("\n%-5s %-25s %-20s\n", "ID", "Nombre", "Carrera");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-5d %-25s %-20s\n",
               estudiantes[i].id,
               estudiantes[i].nombre,
               estudiantes[i].carrera);
    }
}
