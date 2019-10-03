/*
 * utn.h
 *
 *  Created on: 2 oct. 2019
 *      Author: sergio
 */

#ifndef UTN_H_
#define UTN_H_

char getChar(char[]);

/**
 * \brief Verifies if value is numeric and can get floats
 * \param str Array with string to be initialized
 * \return 1 if it's numeric, 0 if is not
 *
 */
int isNumericFloat(char[]);

/**
 * \brief Verifies if entered value is a number
 * \param str Array with string to be initialized
 * \return 1 if it's numeric, 0 if is not
 *
 */
int isNumeric(char[]);

/**
 * \brief Verifies if entered value only contains letters
 * \param str Array with string to be initialized
 * \return 1 If it only contains ' ' and letters, 0 if is not
 *
 */
int isOnlyLetters(char[]);

/**
 * \brief Asks the user for a text and returns it
 * \param message Message to be shown
 * \param input Array where entered text is charged
 * \return void
 */
void getString(char [],char []);

/**
 * \brief Asks the user for a text and returns it
 * \param message Message to be shown
 * \param input Array where entered text is charged
 * \return 1 if text is only letters
 */
int getStringLetters(char [],char[]);

/**
 * \brief Ask the user for a numbered text and returns it
 * \param message Message to be shown
 * \param input Array where entered text is charged
 * \return 1 if text is only numbers
 */
int getStringNumbers(char [],char[]);

/**
 * \brief Ask the user for a numbered text and returns it (accepts float)
 * \param message Message to be shown
 * \param input Array where entered text is charged
 * \return 1 if text is only numbers
 */
int getStringFloatNumbers(char[],char[]);

/**
 * \brief Ask for an integer number
 * \param requestMessage Message to be shown to ask for the number
 * \param requestMessage Message to be shown in case of error
 * \return Number entered by the user
 *
 */
int getValidInt(char[],char[], int, int);

/**
 * \brief Asks fot a float number and verifies it
 * \param requestMessage Message to be shown to ask for the number
 * \param requestMessage Message to be shown in case of error
 * \return Number entered by the user
 *
 */
int getValidFloat(char[],char [], int, int);

/**
 * \brief Asks for a string
 * \param requestMessage Message to be shown to ask for the number
 * \param requestMessage Message to be shown in case of error
 * \param input Array where entered text is charged
 * \return -
 *
 */
void getValidString(char[],char[], char[]);

/**
 * \brief Cleans the stdin, similar to fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);





#endif /* UTN_H_ */
