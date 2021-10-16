/*
 * Reports.c
 *
 *  Created on: 15 oct. 2021
 *      Author: quisp
 */

#include "Reports.h"



int printListSortedEmployee(Employee* list, int len, int order)
{
	int state = -1;


	{
		if(sortEmployees(list, len, order) == 0)
		{
			if(printEmployees(list, len) == 0)
			{
				state = 0;
			}
		}

	}
	return state;
}

int reportsSalary(Employee* list, int len)
{
	int state;
	float totSalary;
	int cantEmp;
	float prom;
	int cantEmpUp;

	state = -1;
	if (list != NULL && len > 0)
	{
		if(allSalary(list, len, &totSalary) == 0)
		{
			cantEmp = cantEmployee(list, len);
			if (cantEmp > 0)
			{
				prom = totSalary/cantEmp;
				cantEmpUp = cantEmployeeUp(list, len, prom);
				printf("\n\tEl Total es %f\n\tEl promedio de los salarios es %f\n\tLos empleados que superan el salario promedio son %d", totSalary, prom, cantEmpUp);
				state = 0;
			}
		}
	}
	return state;
}
