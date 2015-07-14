#!/bin/sh

cnt=0
for chapter in `ls`
do
	if [ -d $chapter ]; then
		for exercise in `ls ${chapter}`
		do
			cnt=`expr $cnt + 1`
			if [ -d "$chapter/$exercise" ]; then
				echo "[ $cnt ] Compiling exercise ${exercise} from chapter ${chapter}"
				cd ${chapter}/${exercise} && make 1> /dev/null || echo "[ ERROR ] Compilation failed!"
				cd ../..
			fi
		done
	fi
done
