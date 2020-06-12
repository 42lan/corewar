# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ops_checker.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/12 16:27:16 by amalsago          #+#    #+#              #
#    Updated: 2020/06/12 17:53:12 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NC='[0m'
GREY='[1;30m'
RED='[1;31m'
GREEN='[1;32m'
YELLOW='[1;33m'
BLUE='[1;34m'
MAGENTA='[1;35m'
CYAN='[1;36m'
WHITE='[1;37m'

function header
{
clear
echo "
	${RED}   ______                                                           
	  / ____/___  ________ _      ______ ______                         
	 / /   / __ \/ ___/ _ \ | /| / / __ \`/ ___/                         
	/ /___/ /_/ / /  /  __/ |/ |/ / /_/ / /                             
	\____/\____/_/   \___/|__/|__/\__,_/_/${NC}${BLUE} __              __            
	             ____  ____  _____   _____/ /_  ___  _____/ /_____  _____
	            / __ \/ __ \/ ___/  / ___/ __ \/ _ \/ ___/ //_/ _ \/ ___/
	           / /_/ / /_/ (__  )  / /__/ / / /  __/ /__/ ,< /  __/ /    
	           \____/ .___/____/   \___/_/ /_/\___/\___/_/|_|\___/_/     
	               /_/${NC}                     ${WHITE} 61 6D 61 6C 73 61 67 6F 
${NC}"
}

function clear_line()
{
	tput cuu $1
	tput el
}

function get_executables()
{
	while [ -z ${asm} ]; do
		read -p "Give path to your asm binary:       " asm
		if [ ! -x ${asm} ]; then
			clear_line 1
			asm=""
		fi
	done
}

function generate_op_ld
{
	mkdir -p op_ld
	declare -a list_ld=("ld %-2147483647, r16\nst r16, 10"
						"ld %2147483648, r15\nst r15, 10")	

	len_list_ld=${#list_ld[@]}
	i=0

	while [[ i -lt ${len_list_ld} ]]
	do
		echo ".name\t\"Op ld\"\n.comment\t\"Test OP ld\"\n" >> op_ld/${i}.s
		echo ${list_ld[i]} >> op_ld/${i}.s
		${asm} op_ld/${i}.s
		(( i = i + 1 ))
	done
}

header
get_executables
generate_op_ld
