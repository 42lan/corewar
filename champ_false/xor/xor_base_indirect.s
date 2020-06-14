.name	"xor_basic_indir_pos"
.comment	"basic use xor with indirect argument"

	ld	%102313210, r3
	st	r3, -5
	xor	-10, 0, r16
	xor	%84920323, 0, r12
	st	r16, 20
	st	r12, 50
