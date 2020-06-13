.name	"and_basic_reg_pos"
.comment	"basic use and with reg argument"

	ld	%382015, r2
	and	r2, r1, r16
	and	-7, r16, r12
	st	r16, 20
	st	r12, 50
