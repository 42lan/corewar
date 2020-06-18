#!/usr/bin/env sh

# Args
DIR=$1
if [ -z "$DIR" ]; then
	printf "\e[31mYou must specify a folder!\e[0m\n"
	exit 1
fi

# Prerequistes
if [ -z "$(ls -1 . | grep 'oasm$')" ]; then
	printf "\e[31mMissing oasm, this should be the official compiler.\e[0m\n"
	exit 1
fi

# Test
for f in $DIR/*.s ; do
	./diff_asm.sh $f
	echo "\e[0m"
done
