#!/bin/bash
echo "Compiling..."
g++ -o Main Main.cpp libs/*.cpp
echo "Compile done!"
xfn()
{
	trap SIGINT
	echo
	rm ./Main
	exit
}
trap "xfn" INT
./Main
trap SIGINT
echo "Finished running"
rm ./Main
echo "Removed Main"
