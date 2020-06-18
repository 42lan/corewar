.name		"ZorkHasBeenSlain"
.comment	"Zork Use live it's not very effective"

		fork	%:next
return:
		st		r1, 6
		live	%0
		xor		r14, r15, r16
		zjmp	%-10

next:		
		ld		-18, r2
		ld		-19, r3
		live	%1
		st		r2, 350
		st		r3, 349
		ld		-15, r4
		ld		-16, r5
		ld		-17, r6
		ld		-18, r7
		st		r4, 330
		st		r5, 329
		st		r6, 328
		st		r7, 327
