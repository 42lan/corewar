.name	"xor_basic_reg_pos"
.comment	"basic use xor with reg argument"

	ld	%382015, r2
	xor	r2, r1, r16
	xor	-7, r16, r12
	st	r16, 20
	st	r12, 50
