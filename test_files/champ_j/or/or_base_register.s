.name	"or_basic_reg_pos"
.comment	"basic use or with reg argument"

	ld	%382015, r2
	or	r2, r1, r16
	or	-7, r16, r12
	st	r16, 20
	st	r12, 50
