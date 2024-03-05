#ifndef __MOD_BOOL__
#define __MOD_BOOL__

#define _GNU_SOURCE

/**
 * @file bool.h
 * Tipo Booleano básico e operações sobre o mesmo
 */

/** @brief Representação em C de um tipo de Booleano, utilizando uma estrutura enum
*
*/
typedef enum { false, true } bool;

/** @brief OR lógico
*/
bool max(bool a, bool b);
/** @brief AND lógico
*/
bool min(bool a, bool b);

#endif
