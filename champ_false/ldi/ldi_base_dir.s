.name	"Ldi_basic_dir_pos"
.comment	"basic use ldi wit argument dir and print the value of register"

	ldi	%6, %13, r16
	ldi	%-6, r16, r5
	ldi	10, %123, r3
	ldi	-5, r3, r6
	ldi	r4, r3, r7
	ldi	r4, %5, r8
	st	r16, 70
	st	r5, 75
	st	r3, 80
	st	r4, 85
	st	r6, 90
	st	r7, 95
	st	r8, 100
