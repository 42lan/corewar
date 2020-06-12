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
# define CW_ERROR_OPENING_OUTPUT_FILE -32
# define CW_ERROR_WRITING_OUTPUT_FILE -33

/*
** asm specific error codes:
*/

# define CW_ERROR_ASM -60
# define CW_ERROR_ASM_CREATING_OPTIONS -61
# define CW_ERROR_ASM_MISSING_SOURCE_OPTION -62
# define CW_ERROR_ASM_UNKNOWN_OPTION -63

/*
** vm specific error codes:
*/

# define CW_VM_USAGE 3
# define CW_VM_NO_ARG 5
# define CW_VM_NO_VALID_ARGUMENT_DUMP 6
# define CW_VM_ERROR_OPEN_FAILED -7
# define CW_VM_ERROR_NOT_VALID_PLAYER 8
# define CW_VM_READ_ERROR 9
# define CW_VM_ERROR_NAME_TOO_LONG 10
# define CW_VM_ERROR_CODE_LEN_TOO_LONG 11
# define CW_VM_ERRO_NOT_ENOUGH_SPACE_IN_ARENA 12

/*
** corewar specific error codes:
*/

# define CW_ERROR_BAD_DEVELOPPER -90

#endif
