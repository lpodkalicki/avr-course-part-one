#!/bin/sh

for chapter in `ls`
do
	if [ -d $chapter ]; then
		for exercise in `ls ${chapter}`
		do
			if [ -d "$chapter/$exercise" ]; then
				echo "Cleaning exercise ${exercise} from chapter ${chapter}"
				cd ${chapter}/${exercise} && make clean 1> /dev/null || echo "[ ERROR ] Compilation failed!"
				cd ../..
			fi
		done
	fi
done
