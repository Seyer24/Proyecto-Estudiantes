#ifndef REPORTES_H
#define REPORTES_H

#include "estudiantes.h"

#define CALIFICACION_APROBATORIA 6.0f

void reporte_aprobados_reprobados(Estudiante estudiantes[], int total);
void ranking_mejores(Estudiante estudiantes[], int total);
void estadisticas_generales(Estudiante estudiantes[], int total);

#endif
