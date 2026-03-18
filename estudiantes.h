#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#define MAX_ESTUDIANTES 50
#define MAX_MATERIAS 6

typedef struct {
    int id;
    char nombre[50];
    char carrera[50];
    float calificaciones[MAX_MATERIAS];
    int num_materias;
} Estudiante;

void registrar_estudiante(Estudiante estudiantes[], int *total);
Estudiante* buscar_por_id(Estudiante estudiantes[], int total, int id);
Estudiante* buscar_por_nombre(Estudiante estudiantes[], int total, const char *nombre);
void mostrar_lista(Estudiante estudiantes[], int total);

#endif
