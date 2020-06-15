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
# define CW_ERROR_OPENING_INPUT_FILE -34
# define CW_ERROR_READING_INPUT_FILE -35

/*
** asm specific error codes:
*/

# define CW_ERROR_ASM -60
# define CW_ERROR_ASM_CREATING_OPTIONS -61
# define CW_ERROR_ASM_MISSING_SOURCE_OPTION -62
# define CW_ERROR_ASM_UNKNOWN_OPTION -63
# define CW_ASM_ERROR_MALFORMED_FILE -69
# define CW_ASM_WARNING_NAME_TRUNCATED 70
# define CW_ASM_WARNING_NAME_MISSING 71
# define CW_ASM_WARNING_COMMENT_TRUNCATED 72
# define CW_ASM_WARNING_CODE_TOO_LONG 73
# define CW_ASM_ERROR_SYNTAX 80
# define CW_ASM_ERROR_DUPLICATE_LABEL 81
# define CW_ASM_ERROR_MISSING_LABEL 82
# define CW_ASM_ERROR_ARGUMENT_COUNT 83
# define CW_ASM_ERROR_ARGUMENT_TYPE 84

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
