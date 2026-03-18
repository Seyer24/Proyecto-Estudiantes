/*
Sistema de Gestión Académica
Descripción del Proyecto: Desarrollar un sistema completo para gestionar información de estudiantes,
incluyendo calificaciones, promedios, y generar reportes.

Requerimientos Funcionales:

    Gestión de Estudiantes:
        Registrar estudiante (nombre, ID, carrera)
        Buscar estudiante por ID o nombre
        Mostrar lista de estudiantes

    Gestión de Calificaciones:
        Capturar calificaciones de materias
        Calcular promedios individuales
        Calcular estadísticas del grupo

    Reportes:
        Lista de estudiantes aprobados/reprobados
        Ranking de mejores estudiantes
        Estadísticas generales del grupo

///////////////////////////////////////////////////////////////
        Reyes Gonzalez Arath
        1293182
        Organizacion de Computadoras
        Parcial 2
///////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include "estudiantes.h"
#include "calificaciones.h"
#include "reportes.h"

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int total = 0;
    int opcion;

    do {
        printf("\n====== Sistema de Gestion Academica ======\n");
        printf("1. Registrar estudiante\n");
        printf("2. Buscar estudiante por ID\n");
        printf("3. Mostrar lista de estudiantes\n");
        printf("4. Capturar calificaciones\n");
        printf("5. Ver estadisticas del grupo\n");
        printf("6. Reporte aprobados/reprobados\n");
        printf("7. Ranking de mejores estudiantes\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrar_estudiante(estudiantes, &total);
                break;
            case 2: {
                int id;
                printf("ID a buscar: ");
                scanf("%d", &id);
                Estudiante *e = buscar_por_id(estudiantes, total, id);
                if (e) printf("Encontrado: %s - %s\n", e->nombre, e->carrera);
                else    printf("Estudiante no encontrado.\n");
                break;
            }
            case 3:
                mostrar_lista(estudiantes, total);
                break;
            case 4: {
                int id;
                printf("ID del estudiante: ");
                scanf("%d", &id);
                Estudiante *e = buscar_por_id(estudiantes, total, id);
                if (e) capturar_calificaciones(e);
                else   printf("Estudiante no encontrado.\n");
                break;
            }
            case 5:
                estadisticas_grupo(estudiantes, total);
                break;
            case 6:
                reporte_aprobados_reprobados(estudiantes, total);
                break;
            case 7:
                ranking_mejores(estudiantes, total);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}