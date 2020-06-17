.name	"fork_basic_dir_pos"
.comment	"basic use fork wit argument dir and print the value of register"

	ld	%5831, r2
	fork	%6
	fork	%-5
	st	r2, 0
