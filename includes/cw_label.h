#ifndef CW_LABEL_H
# define CW_LABEL_H

/*
** t_cw_label
**
** A label is a string representing an offset in the code.
** It is just a string, but its index in the linsts list represent its id.
*/

typedef char	*t_cw_label;

void			cw_label_destroy(t_cw_label **label);

#endif
