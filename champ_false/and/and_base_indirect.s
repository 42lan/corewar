.name	"and_basic_indir_pos"
.comment	"basic use and with indirect argument"

	ld	%102313210, r3
	st	r3, -5
	and	-10, 0, r16
	and	%84920323, 0, r12
	st	r16, 20
	st	r12, 50
