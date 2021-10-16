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

	Employee employeeList[LEN_EMP];
	initEmployees(employeeList, LEN_EMP);
	do {

		printf("\nMenu de opciones: \n\t1- ALTAS\n\t2- MODIFICAR\n\t3- BAJA\n\t4- INFORMAR\n\t5- SALIR");
		utn_getInt(&option, "\nPor favor ingrese una opcion", "\nError.", 1, 5, 1);


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

				}
				break;
			case 3:
				if(cantEmployee(employeeList, LEN_EMP) > 0)
				{
					if(printEmployees(employeeList, LEN_EMP) == 0)
					{
						if(utn_getNatu(&idEmp, "Ingrese el id del empleado que desea eliminar. ", "Error ", 1, 3) == 0)
						{
							if(removeEmployee(employeeList, LEN_EMP, idEmp) == 0)
							{
								printf("El empleado se ha eliminado correctamente");
							}else
								printf("La baja Fallo");
						}
						else
							printf("Error ingreso mal el id del empleado");
					}
					printf("Error");
				}
				else
					printf("La opcion no se puede realizar, no tiene ningun empleado");
				break;
			case 4:
				if(cantEmployee(employeeList, LEN_EMP) > 0)
				{
					if (utn_getInt(&subOption, "\n\t1- Listado de los empleados ordenados alfabéticamente por Apellido y Sectorn\n\t2- Total y promedio de los salarios, y cuántos empleados superan el salario promedio", "Error", 1, 2, 2) == 0)
					{
						switch (subOption) {
							case 1:
								if(utn_getInt(&order, "\nIngrese el orden que desea(ascendente->0, descendente->1)", "Error", 0, 1, 2) == 0)
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
