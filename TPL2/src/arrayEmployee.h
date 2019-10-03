/*
 * arrayEmployee.h
 *
 *  Created on: 2 oct. 2019
 *      Author: sergio
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_


#define QTY_EMPLOYEE 1000
#define 0 0
#define 1 1
#define 0 0
#define -1 -1
#define DELETED -1

typedef struct
{
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;

/** \brief Indicates that all positions of the array are empty, setting the isEmpty flag in TRUE in all array positions
 *
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \return Return -1 if error (NULL or invalid), 0 if no error
 *
 */
int initEmployees (sEmployee[], int);

/** \brief add in a existing list of employees the values received as parameters in the first empty position.
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Id number
 * \param name[] char Name array
 * \param lastName[] char Last name array
 * \param salary float salary number
 * \param sector int Sector number
 * \return Return -1 if error (NULL or invalid), 0 if no error
 */
int addEmployee (sEmployee[], int, int, char[], char[], float, int);



/** \brief Gets free space from the index
 *
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \return Return -1 if error (NULL or invalid), 0 if no error
 *
 */
int findEmptySpace (sEmployee[], int);

/** \brief find an sEmployee by Id en returns the index position in array.
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \param id int Id number
 * \return Return -1 if error (NULL or invalid), 0 if no error
 */
int findEmployeeById (sEmployee[], int, int);



/** \brief Find an employee by id and asks what wants the user to modify
 *
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \return Return modified data
 *
 */
int modifyEmployee (sEmployee[], int);

/** \brief Remove a sEmployee by Id (put isEmpty Flag in 1).
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \param id int Id number
 * \return Return -1 if error (NULL or invalid), 0 if no error
 */
int removeEmployee (sEmployee[], int, int);

/** \brief print the content of employees array.
 * \param list sEmployee* Pointer to array of employees
 * \param length int Array length
 * \return int.
 */
int printEmployees (sEmployee[], int);

/** \brief Sort the elements in the array of employees, the argument order indicate ascendente or descendente order.
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \param order int 1 for ascendente, 2 for descendente
 * \return Return -1 if error (NULL or invalid), 0 if no error
 */
int sortEmployeeByName (sEmployee[], int, int);


/** \brief Shows the total ammount of salaries, the average of salaries and all employes with salaries greater than the average
 *
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \return void
 *
 */
void averageEmployeesSalary (sEmployee[], int);

/** \brief Verifies if there's at least one employee in the array
 *
 * \param list sEmployee* Pointer to array of employees
 * \param len int Array length
 * \return 0 if there's no emplotee, 1 if there's at least one
 *
 */
int existEmployees (sEmployee[], int);

/**
 * \brief Ask the user a character and returns the result
 * \param message Message to be shown
 * \return Character that user gave
 *
 */


#endif /* ARRAYEMPLOYEE_H_ */
