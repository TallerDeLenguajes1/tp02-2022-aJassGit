#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

typedef struct compu
{
    int velocidad;//entre 1 y 3 Gherz
    int anio;//entre 2000 y 2017
    int cantidad;//entre 1 y 4
    char *tipo_cpu; //valores del arreglo tipos
}pc;


void carga_datos(pc *datospc);
void mostrar_datos(pc *datospcs);

void older(pc *dato);
void faster(pc *dato);

int main()
{
    pc array_pc[4], *p_array;
    p_array = array_pc;
    p_array = malloc(5*sizeof(pc));

    pc *tipo_cpu;
    tipo_cpu = tipos;

    carga_datos(p_array);
    mostrar_datos(p_array);

    older(p_array);
    faster(p_array);

    free(p_array);
}

void carga_datos_individual(pc *datospc)
{
    datospc->velocidad = rand() % (3-1+1) + 1;// 3=N y 1=M (N>M) == (N-M+1) + M
    datospc->anio = rand() % (2017-2000+1) + 2000;
    datospc->cantidad = rand() % (4-1+1) + 1;
    datospc->tipo_cpu = tipos[rand() % 6];
}

void carga_datos(pc *datospc)
{
    for(int i=0; i<5; i++)
    {
        carga_datos_individual(datospc);
        datospc++;
    }
}

void mostrar_datos(pc *datospcs)
{
    for(int i=0; i<5; i++)
    {
        printf("\n--      Computadora Num[%i]       --\n",i+1);
        printf("Velocidad del procesador: %i\n", datospcs->velocidad);
        printf("Año de fabricación: %i\n", datospcs->anio);
        printf("Cantidad de núcleos: %i\n", datospcs->cantidad);
        printf("Tipo de procesador: %s\n", datospcs->tipo_cpu);
        datospcs++;
    }
}

void older(pc *dato)
{
    int num_pc = 1;
    int older_pc = dato->anio;
    dato++;
    for(int i=1; i<5; i++)
    {
        if(older_pc>dato->anio)
        {
            older_pc = dato->anio;
            num_pc = i+1;
        }
        dato++;
    }
    printf("La computadora num[%i] es la más vieja\n", num_pc);
}

void faster(pc *dato)
{
    int enum_pc = 1;
    int faster_pc = dato->velocidad;
    dato++;
    for(int i=1; i<5; i++)
    {
        if(faster_pc<dato->velocidad)
        {
            faster_pc = dato->velocidad;
            enum_pc = i+1;
        }
        dato++;
    }
    printf("La computadora num[%i] es la más rápida\n", enum_pc);
}