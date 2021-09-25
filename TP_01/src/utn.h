/*
 * utn.h
 *
 *  Created on: 24 sept 2021
 *      Author: daiana
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>

/*
 *\brief almacena el numero ingresado por el usuario
 *\param pNumero (el puntero donde voy a guardar el valor ingresado)
 *\param pIngresadoNum (es el estado del numero si se ingreso o no el numero)
 *\return no retorna nada es una funcion void
 * */
void ingresarNumero(int* pNumero,int* pIngresadoNum);
/*
 *\brief muestra el menu de opciones y almacena la opcion seleccionada por el usuario
 *\param pOpcion (puntero donde guardo la opcion seleccionada del usuario)
 *\param ingresadoNumUno (es el estado del numero si se ingreso o no el numero)
 *\param ingresadoNumDos (es el estado del numero si se ingreso o no el numero)
 *\param numUno (valor del 1er numero ingresado)
 *\param numDos (valor del segundo numero ingresado)
 *\return no retorna nada es una funcion void
 * */
void menuOpciones(int* pOpcion,int ingresadoNumUno,int ingresadoNumDos,int numUno,int numDos);
/*
 *\brief valida si se ingresaron los numeros
 *\param ingresadoNumUno (es el estado del numero si se ingreso o no el numero)
 *\param ingresadoNumDos (es el estado del numero si se ingreso o no el numero)
 *\return devuelve 1 si se ingresaron los 2 numeros y devuelve -1 caso contrario
 * */
int validarIngresoDeDatos(int ingresadoNumUno,int ingresadoNumDos);
/*
 *\brief realiza todas las operaciones
 *\param numeroUno (valor del 1er numero ingresado)
 *\param numeroDos (valor del 2do numero ingresado)
 *\param pOpRealizadas (estado de si la operacion esta realizada o no)
 *\param pRes-(punteros donde se guardara el resultado de las operaciones)
 *\return no retorna nada es una funcion void
 * */
void calcularOperaciones(int numeroUno,int numeroDos,int* pOpRealizadas,int* pResSuma,int* pResResta,int* pResMultiplicacion,float* pResDivision,int* pResFacUno,int* pResFactDos);
/*
 *\brief verfica si se realizaron las operaciones
 *\param opRealizadas (estado de si la operacion esta realizada o no)
 *\return devuelve 1 si se realizaron las operaciones y devuelve -1 caso contrario
 * */
int validarOperacionesRealizadas(int opRealizadas);
/*
 *\brief muestra los resultados de las operaciones
 *\param numUno (valor del 1er numero ingresado)
 *\param numDos (valor del 2do numero ingresado)
 *\param res- (valores de los resultados de las operaciones)
 *\return no retorna nada es una funcion void
 * */
void mostrarResultados(int numUno,int numDos,int resSuma,int resResta,int resMultiplicacion,float resDivision,int resFactorialUno,int resFactorialDos);

#endif /* UTN_H_ */
