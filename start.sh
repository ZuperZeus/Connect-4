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
echo "Running"
./Main
echo "Finished running"
trap SIGINT
echo "Removing Main"
rm ./Main
echo "Removed Main"
