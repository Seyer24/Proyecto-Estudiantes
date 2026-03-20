#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#define MAX_ESTUDIANTES 50
#define MAX_MATERIAS 6

extern const char *NOMBRES_MATERIAS[MAX_MATERIAS];

typedef struct {
    int id;
    char nombre[50];
    char carrera[50];
    float calificaciones[MAX_MATERIAS];   // indice fijo por materia (0-5)
    int   materias_inscritas[MAX_MATERIAS]; // 1 = cursa, 0 = no cursa
} Estudiante;

void registrar_estudiante(Estudiante estudiantes[], int *total);
Estudiante* buscar_por_id(Estudiante estudiantes[], int total, int id);
Estudiante* buscar_por_nombre(Estudiante estudiantes[], int total, const char *nombre);
void mostrar_lista(Estudiante estudiantes[], int total);

#endif
