#include "cw_linst.h"					

/*
** Set the internal state of a linst to default.
** This does not free anything inside.
**
** Note: this function may not be used as t_array set all fields to 0.
*/

void						cw_linst_default(t_cw_linst *linst)
{
	linst->type = CW_LINST_TYPE_RAW;
	linst->raw = NULL;
	linst->literal = NULL;
	linst->label = NULL;
	linst->inst = NULL;
	linst->offset = 0;
}

/*
** Free the internal contents of a linst without freeing it,
** also reseting it to default.
*/

void						cw_linst_clean(t_cw_linst *linst)
{
	if (linst->type == CW_LINST_TYPE_RAW)
		free(linst->raw);
	if (linst->type == CW_LINST_TYPE_LITERAL)
		cw_literal_destroy(&(linst->literal));
	if (linst->type == CW_LINST_TYPE_LABEL)
		cw_label_destroy(&(linst->label));
	if (linst->type == CW_LINST_TYPE_INST)
		free(linst->inst);
	cw_linst_default(linst);
}

/*
** Get the size needed to write this linst as binary code.
*/

int				cw_linst_size(t_cw_linst *linst)
{
	if (linst->type == CW_LINST_TYPE_INST)
		return (cw_inst_size(linst->inst));
	if (linst->type == CW_LINST_TYPE_LITERAL)
		return (cw_literal_size(linst->literal));
	return (0);
}

/*
** Write this linst to a char array.
** The linst's offset is not accounted.
*/

void			cw_linst_write(t_cw_linst *linst, unsigned char *out)
{
	if (linst->type == CW_LINST_TYPE_INST)
		cw_inst_write(linst->inst, out);
	if (linst->type == CW_LINST_TYPE_LITERAL)
		cw_literal_write(linst->literal, out);
}

