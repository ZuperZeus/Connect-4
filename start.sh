#!/bin/bash
g++ -o Main Main.cpp libs/*.cpp
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
rm ./Main
