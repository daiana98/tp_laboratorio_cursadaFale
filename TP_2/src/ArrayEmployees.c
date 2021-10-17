/*
 * ArrayEmployees.c
 *
 *  Created on: 11 oct. 2021
 *      Author: quispe
 */

#include "ArrayEmployees.h"




static int findFreeSpace(Employee* list, int len);
static void sortAsc(Employee* list, int len);
static void sortDesc(Employee* list, int len);
static void swap(Employee* list, int prev, int next);


int initEmployees(Employee* list, int len)
{
    int state;

    state = -1;
    if(list != NULL && len>0)
    {
    	state = 0;//OK
        for (int i=0; i<len ;i++)
        {
        	list[i].isEmpty = EMPTY;
        }
    }
    return state;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int state;
	int position;

	state = -1;

	if(list != NULL && len>0)
	{
		position = findFreeSpace(list, len);
		if (position != -1) {
			state = 0;
			list[position].id = id;
			strcpy(list[position].name, name);
			strcpy(list[position].lastName, lastName);
		    list[position].salary = salary;
		    list[position].sector = sector;
			list[position].isEmpty = FULL;
		}
	}
	return state;
}


int getId(void)
{
	static int contador = 0;
	contador++;

	return contador;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int position;

	position = -1;

	if(list != NULL && len>0)
	{
		for (int i = 0;  i < len; ++ i)
		{
			if (list[i].id == id && list[i].isEmpty == FULL)
			{
				position = i;
				break;
			}
		}
	}
	return position;
}

int removeEmployee(Employee* list, int len, int id)
{
	int state;
	int position;

	state = -1;

	if(list != NULL && len>0)
	{
		position = findEmployeeById(list, len, id);
		if(position != -1)
		{
			state = 0;
			list[position].isEmpty = EMPTY;
		}
	}
	return state;
}

int sortEmployees(Employee* list, int len, int order)
{
	int state;
	state = -1;
	if(list != NULL && len>0)
	{
		state = 0;
		if (order == 0)
		{
			sortAsc(list, len);
		}else
		{
			sortDesc(list, len);
		}
	}
	return state;
}

int printEmployees(Employee* list, int len)
{
	int state;
	state = -1;

	if(list != NULL && len>0)
	{
		printf("Id\t Name\t Last Name\t Salary\t Sector\t\n");
		for (int i = 0; i < len; ++i) {
			if(list[i].isEmpty == FULL)
			{
				state = 0;
				printf("%d\t %s\t %s\t\t %.2f\t %d\t \n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
			}
		}
	}
	return state;
}


static void sortAsc(Employee* list, int len)
{
	int statusCmp;

	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			statusCmp = strcmp(list[i].lastName,list[j].lastName);
			if(statusCmp>0)
			{
				swap(list, i, j);
			}else
			{
				if(statusCmp == 0)
				{
					if(list[i].sector > list[j].sector)
					{
						swap(list, i, j);
					}
				}
			}
		}
	}
}

static void sortDesc(Employee* list, int len)
{
	int statusCmp;

	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			statusCmp = strcmp(list[j].lastName,list[i].lastName);
			if(statusCmp>0)
			{
				swap(list, i, j);
			}else
			{
				if(statusCmp == 0)
				{
					if(list[j].sector > list[i].sector)
					{
						swap(list, i, j);
					}
				}
			}
		}
	}
}

static void swap(Employee* list, int prev, int next)
{
	Employee auxEmployee;
	auxEmployee = list[prev];
	list[prev] = list[next];
	list[next] = auxEmployee;
}

static int findFreeSpace(Employee* list, int len)
{
	int position;
	position = -1;

	for (int i = 0;  i < len; ++ i)
	{
		if (list[i].isEmpty == EMPTY)
		{
			position = i;
			break;
		}
	}
	return position;
}

int cantEmployee(Employee* list, int len)
{
	int state;
	int i;

	state = -1;
	if(list != NULL && len>0)
	{
		state = 0;
		for (i = 0; i < len; ++i)
		{
			if (list[i].isEmpty == FULL) {
				state++;
			}
		}
	}
	return state;
}

int cantEmployeeUp(Employee* list, int len, float prom)
{
	int state;
	int i;

	state = -1;

	if(list != NULL && len>0)
	{
		state = 0;
		for (i = 0; i < len; ++i) {
			if(list[i].isEmpty == FULL && list[i].salary > prom)
			{
				state++;
			}
		}
	}
	return state;
}

int allSalary(Employee* list, int len, float* tot)
{
	int state;
	int i;

	state = -1;
	*tot = 0.0;
	if(list != NULL && len>0)
	{
		state = 0;
		for (i = 0; i < len; ++i) {
			if (list[i].isEmpty == FULL)
			{
				*tot = *tot + list[i].salary;
			}
		}
	}
	return state;
}

int modifyEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int state;
	int position;

	state = -1;

	if(list != NULL && len>0)
	{
		position = findEmployeeById(list, len, id);
		if (position != -1) {
			state = 0;
			strcpy(list[position].name, name);
			strcpy(list[position].lastName, lastName);
			list[position].salary = salary;
			list[position].sector = sector;
		}
	}
	return state;
}
