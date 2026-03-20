#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "estudiantes.h"

#define ARCHIVO_DAT "salon.dat"

void guardar_salon(Estudiante estudiantes[], int total);
int  cargar_salon(Estudiante estudiantes[]);

#endif
