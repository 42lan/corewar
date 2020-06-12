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

# define CW_VM_USAGE 3
# define CW_VM_NO_ARG 5
# define CW_VM_NO_VALID_ARGUMENT_DUMP 6
# define CW_VM_ERROR_OPEN_FAILED -7
# define CW_VM_ERROR_NOT_VALID_PLAYER 8
# define CW_VM_READ_ERROR 9
# define CW_VM_ERROR_NAME_TOO_LONG 10
# define CW_VM_ERROR_CODE_LEN_TOO_LONG 11
# define CW_VM_ERRO_NOT_ENOUGH_SPACE_IN_ARENA 12

# define CW_VM_FILE_EXPECTED 244
# define CW_VM_FILE_EXTENSION 245
# define CW_VM_DUMP_NUM 246
# define CW_VM_CYCLE_LIMITS 247
# define CW_VM_ID_LIMITS 248
# define CW_VM_ID_EXPECTED 249
# define CW_VM_MAX_PLAYERS 250
# define CW_VM_NO_PLAYERS 251

/*
** corewar specific error codes:
*/

# define CW_ERROR_BAD_DEVELOPPER -90

#endif
