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
#include "persistencia.h"

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int total = 0;
    int opcion;

    total = cargar_salon(estudiantes);

    do {
        printf("\n-------- Sistema de Gestion Academica --------\n");
        printf("No1. Registrar estudiante\n");
        printf("No2. Buscar estudiante por ID\n");
        printf("No3. Mostrar lista de estudiantes\n");
        printf("No4. Capturar calificaciones\n");
        printf("No5. Ver estadisticas del grupo\n");
        printf("No6. Reporte aprobados/reprobados\n");
        printf("No7. Ranking de mejores estudiantes\n");
        printf("No0. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            opcion = -1;
            while (getchar() != '\n');
        }

        switch (opcion) {
            case 1:
                registrar_estudiante(estudiantes, &total);
                break;
            case 2: {
                int id;
                printf("ID a buscar: ");
                scanf("%d", &id);
                Estudiante *e = buscar_por_id(estudiantes, total, id);
                if (e) printf("Encontrado: %s - %s | Promedio: %.2f\n", e->nombre, e->carrera, calcular_promedio(e));
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
                guardar_salon(estudiantes, total);
                printf("Saliendo...\n");
                break;
            default:
                printf("Error: opcion invalida. Introduzca de nuevo.\n");
                break;
        }




    } while (opcion != 0);

    return 0;
}

/*

cd "/home/seyer/Documents/UABC/Organizacion de Computadoras"
./sistema 

gcc parcial2.c estudiantes.c calificaciones.c reportes.c persistencia.c -o sistema && ./sistema

*/

