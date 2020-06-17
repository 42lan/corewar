.name	"add_basic_dir_pos"
.comment	"basic use add with reg argument"

	ld	%-2, r16
	ld	%-1, r15
	sub	r16, r15, r3
	st	r3, 10
