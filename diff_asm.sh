#!/usr/bin/env sh

# Config
RESET="\e[0m"
TITLE="${RESET}\e[46m"
C1="\e[32m"
C2="\e[33m"

# Args
S=$1
if [ -z "$S" ]; then
	printf "\e[31mYou must specify champion source file!\e[0m\n"
	exit 1
fi
COR=$(echo $S | sed "s/\.s$/\.cor/")
if [ "$S" = "$COR" ]; then
	printf "\e[31mThe champion source must be a .s!\e[0m\n"
	exit 1
fi

# Prerequistes
if [ -z "$(ls -1 . | grep 'oasm$')" ]; then
	printf "\e[31mMissing oasm, this should be the official compiler.\e[0m\n"
	exit 1
fi

# Test

echo "$TITLE testing $S -> $COR $RESET"

echo "${TITLE}EXPECTED: ${RESET}$C1"
rm -f $COR
./oasm $S
hd $COR > expected.hd 2>/dev/null

echo "${TITLE}RESULT: ${RESET}$C2"
rm -f $COR
./asm $S
hd $COR > result.hd 2>/dev/null

echo "$RESET diff:"
diff expected.hd result.hd
