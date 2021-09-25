/*
 * utn.c
 *
 *  Created on: 24 sept 2021
 *      Author: daiana
 */
#include "utn.h"

int opSuma(int numUno,int numDos);
int opResta(int numUno,int numDos);
int opMultiplicacion(int numUno,int numDos);
float opDivision(int numUno,int numDos);
int opFactorial(int numero);
void validarMensajeAMostrar(int numUno,int numDos,float resDivision,int resFactorialUno,int resFactorialDos);

void ingresarNumero(int* pNumero,int* pIngresadoNum)
{
	printf("Por favor ingrese un numero");
	scanf("%d",pNumero);
	*pIngresadoNum=1;
}

void menuOpciones(int* pOpcion,int ingresadoNumUno,int ingresadoNumDos,int numUno,int numDos)
{
		printf("\nMenú de Opciones: \n\t1. Ingresar 1er operando(%d)\n\t2. Ingresar 2do operando(%d)\n\t3. Calcular todas las operaciones\n\t4. Informar resultados\n\t5. Salir",numUno,numDos);
		printf("\nSeleccione una opcion");
		scanf("%d",pOpcion);
}

int validarIngresoDeDatos(int ingresadoNumUno,int ingresadoNumDos)
{
	int estado=-1;
	if(ingresadoNumUno == 1 && ingresadoNumDos == 1)
	{
		estado=1;
	}
	return estado;
}

int validarOperacionesRealizadas(int opRealizadas)
{
	int estado=-1;
	if(opRealizadas == 1)
	{
		estado=1;
	}
	return estado;
}
void calcularOperaciones(int numeroUno,int numeroDos,int* pOpRealizadas,int* pResSuma,int* pResResta,int* pResMultiplicacion,float* pResDivision,int* pResFacUno,int* pResFactDos)
{
	*pResSuma=opSuma(numeroUno,numeroDos);
	*pResResta=opResta(numeroUno,numeroDos);
	*pResMultiplicacion=opMultiplicacion(numeroUno,numeroDos);
	*pOpRealizadas=1;

	if(numeroDos != 0)
	{
		*pResDivision=opDivision(numeroUno,numeroDos);
	}
	if(numeroUno >= 0)
	{
		*pResFacUno=opFactorial(numeroUno);
	}
	if(numeroDos >= 0)
	{
		*pResFactDos=opFactorial(numeroDos);
	}
}
void mostrarResultados(int numUno,int numDos,int resSuma,int resResta,int resMultiplicacion,float resDivision,int resFactorialUno,int resFactorialDos)
{
	validarMensajeAMostrar(numUno,numDos,resDivision,resFactorialUno,resFactorialDos);
	printf("\n\tSuma: %d",resSuma);
	printf("\n\tResta: %d",resResta);
	printf("\n\tMultiplicación: %d",resMultiplicacion);
}
void validarMensajeAMostrar(int numUno,int numDos,float resDivision,int resFactorialUno,int resFactorialDos)
{
	printf("Los resultados de las operaciones son:");
	if(numDos == 0)
	{
		printf("\n\tEl 2do número es cero, la división no se puede realizar");
	}else
	{
		printf("\n\tdivisión: %f",resDivision);
	}
	if(numDos < 0 && numUno < 0)
	{
		printf("\n\tNo se puede realizar el factorial de los numeros.");
	}else if(numUno < 0)
	{
		printf("\n\tNo se puede realizar el factorial del 1er número y el factorial del 2do número es: %d",resFactorialDos);
	}else
	{
		printf("\n\tNo se puede realizar el factorial del 2do número y el factorial del 1er número es: %d",resFactorialUno);
	}
}
int opSuma(int numUno,int numDos)
{
	int respuesta;

	respuesta=numUno + numDos;

	return respuesta;
}

int opResta(int numUno,int numDos)
{
	int respuesta;

	respuesta=numUno - numDos;

	return respuesta;
}

int opMultiplicacion(int numUno,int numDos)
{
	int respuesta;

	respuesta=numUno * numDos;

	return respuesta;
}
//1-> ok, o->mal
float opDivision(int numUno,int numDos)
{
	float respuesta;

	respuesta=(float)numUno / numDos;

	return respuesta;
}

int opFactorial(int numero)
{
	int respuesta;

	if(numero == 1 || numero == 0)
	{
		return 1;
	}
	respuesta=numero * opFactorial(numero-1);
	return respuesta;
}
