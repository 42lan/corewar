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
COR=$(echo $S | sed "s/\.s/\.cor/")

# Prerequistes
if [ -z "$(ls -1 . | grep 'oasm$')" ]; then
	printf "\e[31mMissing oasm, this should be the official compiler.\e[0m\n"
	exit 1
fi

# Test

echo "$TITLE testing $S -> $COR $RESET"

echo "${TITLE}EXPECTED: ${RESET}$C1"
./oasm $S
hd $COR > expected.hd

echo "${TITLE}RESULT: ${RESET}$C2"
./asm $1
hd $COR > result.hd
diff expected.hd result.hd

echo "$RESET diff:"
