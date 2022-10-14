 #  Connect-4, a terminal GUI with a min-max AI for the classic board game of the same name.
 #  Copyright (C) 2022 ZuperZeus
 #
 #  This program is free software: you can redistribute it and/or modify
 #  it under the terms of the GNU General Public License as published by
 #  the Free Software Foundation, either version 3 of the License, or
 #  (at your option) any later version.
 #
 #  This program is distributed in the hope that it will be useful,
 #  but WITHOUT ANY WARRANTY; without even the implied warranty of
 #  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #  GNU General Public License for more details.
 #
 #  You should have received a copy of the GNU General Public License
 #  along with this program.  If not, see <https://www.gnu.org/licenses/>.

#!/bin/bash
xfn()
{
	tput cvvis
	printf "\e[?1049l"
	printf "\e[31mINTERRUPTED\e[0m\n"
	if [[ -e ./Main ]]
	then
		echo "Removing Main"
		rm ./Main
		echo "Removed Main"
	fi
	exit
}
trap "xfn" INT
echo "Compiling"
g++ -o Main Main.cpp libs/*.cpp &
tput civis
lbar=".................................................."
cont=0
while [[ -e /proc/$! ]]
do
	if [[ $cont -le 50 ]]
	then
		printf "\r[" # $cont%%"
		#lbar=""
		for (( i = 0; i<= $cont; i++ ))
		do
			printf "#"
		done
		for (( i = 50; i> $cont; i-- ))
		do
			printf "."
		done
		printf "] $(($cont*2))%%"
		cont=$(($cont+1))
		sleep .1
	fi
done
printf "\r[##################################################] 100%%\n"
tput cvvis
if [[ -e ./Main ]]
then
	echo "Compile done!"
	echo "Running"
	./Main
	echo "Finished running"
	echo "Removing Main"
	rm ./Main
	echo "Removed Main"
fi
