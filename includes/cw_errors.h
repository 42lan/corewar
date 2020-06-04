#ifndef CW_ERRORS_H
# define CW_ERRORS_H

/*
** This file define possible runtime errors.
** These codes are used by function's returns.
** The main will also return with the last error code.
*/

/*
** Common error codes:
*/

# define CW_ERROR		-1
# define CW_SUCCESS		0
# define CW_FAILURE		1

# define CW_ERROR_DEFAULT -1
# define CW_ERROR_MALLOC_FAILED -30
# define CW_ERROR_NOT_IMPLEMENTED -31

/*
** asm specific error codes:
*/

# define CW_ERROR_ASM -60

/*
** vm specific error codes:
*/

# define CW_VM_NO_ARG 5
# define CW_VM_NO_VALID_ARGUMENT_DUMP 6

/*
** corewar specific error codes:
*/

# define CW_ERROR_BAD_DEVELOPPER -90

#endif
