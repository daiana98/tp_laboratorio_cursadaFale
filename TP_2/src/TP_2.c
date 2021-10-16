/*
 ============================================================================
 Name        : TP_2.c
 Author      : Quispe Daiana Violeta
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn_inputs.h"
#include "Reports.h"

#define LEN_EMP 1000

int main(void) {
	setbuf(stdout, NULL);

	int option;
	int subOption;
	int idEmp;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int order;
	int position;

	Employee employeeList[LEN_EMP];
	initEmployees(employeeList, LEN_EMP);
	do {

		printf("\nMenu de opciones: \n\t1- ALTAS\n\t2- MODIFICAR\n\t3- BAJA\n\t4- INFORMAR\n\t5- SALIR\n");
		utn_getInt(&option, "\nPor favor ingrese una opcion", "\nError.", 1, 5, CANT_TRY);


		switch (option) {
			case 1:
				if(getEmployee(name, lastName, &salary, &sector) == 0)
				{
					idEmp = getId();
					if(addEmployee(employeeList, LEN_EMP, idEmp, name, lastName, salary, sector) == 0)
					{
						printf("\nEl empleado se ha agregado correctamente ");
					}else
						printf("\nError en el alta del empleado");
				}
				else
					printf("\nError en el ingreso de datos");
				break;
			case 2:
				if(cantEmployee(employeeList, LEN_EMP) > 0)
				{
					printEmployees(employeeList, LEN_EMP);
					if(utn_getNatu(&idEmp, "\nIngrese el id del empleado que desea modificar\n", "\nError", 1, CANT_TRY) == 0)
					{
						position = findEmployeeById(employeeList, LEN_EMP, idEmp);
						if(position != -1)
						{
							printf("ingrese la opcion que desea modificar");
							if(utn_getInt(&subOption, "\n\t1- Nombre\n\t2- Apellido\n\t3- Salario\n\t4- Sector", "Error", 1, 4, CANT_TRY) == 0)
							{
								switch (subOption) {
									case 1:
										if(utn_getText(name, 51, "\nIngrese el nombre ", "Error ", CANT_TRY) == 0)
										{
											if(modifyEmployee(employeeList, LEN_EMP, idEmp, name, employeeList[position].lastName, employeeList[position].salary, employeeList[position].sector) == 0)
											{
												printf("\nEl empleado se ha modificado correctamente");
											}
											else
												printf("\nError al modificar ");
										}
										else
											printf("\nError al ingresar el nombre");
										break;
									case 2:
										if(utn_getText(lastName, 51, "\nIngrese el apellido ", "Error ", CANT_TRY) == 0)
										{
											if(modifyEmployee(employeeList, LEN_EMP, idEmp, employeeList[position].name, lastName, employeeList[position].salary, employeeList[position].sector) == 0)
											{
												printf("El empleado se ha modificado correctamente");
											}
											else
												printf("\nError al modificar ");
										}
										else
											printf("\nError al ingresar el apellido");
										break;
									case 3:
										if(utn_getFloat(&salary, "\nIngrese el salario ", "Error ", 1, 1000000000, CANT_TRY) == 0)
										{
											if(modifyEmployee(employeeList, LEN_EMP, idEmp, employeeList[position].name, employeeList[position].lastName, salary, employeeList[position].sector) == 0)
											{
												printf("El empleado se ha modificado correctamente");
											}
											else
												printf("\nError al modificar ");
										}
										else
												printf("\nError al ingresar el salario");
										break;
									case 4:
										if(utn_getNatu(&sector, "\nIngrese el sector ", "Error ", 1, CANT_TRY) == 0)
										{
											if(modifyEmployee(employeeList, LEN_EMP, idEmp, employeeList[position].name, employeeList[position].lastName, employeeList[position].salary, sector) == 0)
											{
												printf("El empleado se ha modificado correctamente");
											}
											else
												printf("\nError al modificar ");
										}
										else
												printf("\nError al ingresar el sector");
										break;
									default:
										printf("\nError al ingresar la opcion a modificar");
										break;
								}
							}
						}
						else
							printf("\nEl id ingresado no existe\n ");
					}
					else
						printf("\nEl valor ingresado es incorrecto\n");
				}
				else
					printf("\nLa opcion no se puede realizar, no tiene ningun empleado\n");
				break;
			case 3:
				if(cantEmployee(employeeList, LEN_EMP) > 0)
				{
					if(printEmployees(employeeList, LEN_EMP) == 0)
					{
						if(utn_getNatu(&idEmp, "Ingrese el id del empleado que desea eliminar. ", "Error ", 1, CANT_TRY) == 0)
						{
							if(removeEmployee(employeeList, LEN_EMP, idEmp) == 0)
							{
								printf("\nEl empleado se ha eliminado correctamente");
							}else
								printf("\nLa baja Fallo");
						}
						else
							printf("\nError ingreso mal el id del empleado");
					}
					else
						printf("\nError");
				}
				else
					printf("\nLa opcion no se puede realizar, no tiene ningun empleado");
				break;
			case 4:
				if(cantEmployee(employeeList, LEN_EMP) > 0)
				{
					if (utn_getInt(&subOption, "\n\t1- Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n\t2- Total y promedio de los salarios, y cuántos empleados superan el salario promedio", "Error", 1, 2, CANT_TRY) == 0)
					{
						switch (subOption) {
							case 1:
								if(utn_getInt(&order, "\nIngrese el orden que desea(ascendente->0, descendente->1)", "Error", 0, 1, CANT_TRY) == 0)
								{
									if(printListSortedEmployee(employeeList, LEN_EMP, order) == -1)
									{
										printf("\nError ");
									}
								}
								else
									printf("\nError al ingresar el orden");

								break;
							case 2:
								if(reportsSalary(employeeList, LEN_EMP) == -1)
								{
									printf("Error");
								}
								break;
							default:
								printf("Ingreso la opcion invalida");
								break;
						}
					}
				}
				else
					printf("La opcion no se puede realizar, no tiene ningun empleado");
				break;

			case 5:
				printf("\nGracias por usar nuestros servicios, hasta luego..");
				break;
			default:
				printf("Ingreso una opcion invalida, por favor reingrese la opcion");
				break;
		}
	} while (option != 5);
	return EXIT_SUCCESS;
}
