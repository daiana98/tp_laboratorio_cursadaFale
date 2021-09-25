/*
 ============================================================================
 Name        : TP_01.c
 Author      : Daiana Violeta Quispe - H
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	int numeroUno;
	int numeroDos;
	int ingresadoNumUno=-1;
	int ingresadoNumDos=-1;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorialUno;
	int resultadoFactorialDos;
	int operacionesRealizadas=-1;
	int banderaMostrar=-1;

	do
	{
		menuOpciones(&opcion,ingresadoNumUno,ingresadoNumDos,numeroUno,numeroDos);

		switch (opcion) {
			case 1:
				ingresarNumero(&numeroUno,&ingresadoNumUno);
				banderaMostrar=-1;
				break;
			case 2:
				ingresarNumero(&numeroDos,&ingresadoNumDos);
				banderaMostrar=-1;
				break;
			case 3:
				if(validarIngresoDeDatos(ingresadoNumUno,ingresadoNumDos)==1)//true=1 hay datos correctos
				{
					calcularOperaciones(numeroUno,numeroDos,&operacionesRealizadas,&resultadoSuma,&resultadoResta,&resultadoMultiplicacion,&resultadoDivision,&resultadoFactorialUno,&resultadoFactorialDos);//funcion que calcula todas las operaciones
					banderaMostrar=1;
				}else
				{
					printf("\nPor favor ingrese los números\n");
				}
				break;
			case 4:
				if(validarOperacionesRealizadas(operacionesRealizadas)==1 && banderaMostrar==1)//true=1, las operaciones estan hechas
				{
					mostrarResultados(numeroUno,numeroDos,resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision,resultadoFactorialUno,resultadoFactorialDos);//muestra los resultados de todas las operaciones
				}else
				{
					printf("\nPor favor realice las operaciones\n");
				}
				break;
			case 5:
				printf("\nHasta Luego!!\n");
				break;
			default:
				printf("\nPor favor seleccione una opcion valida\n");
				break;
		}

	} while (opcion!=5);

	return EXIT_SUCCESS;
}
