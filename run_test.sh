#!/bin/bash

rm -f output.txt
touch output.txt

./a.out units/capt.json units/hulk.json >> output.txt
./a.out units/capt.json units/ironman.json >> output.txt
./a.out units/hulk.json units/capt.json >> output.txt
./a.out units/hulk.json units/ironman.json >> output.txt
./a.out units/ironman.json units/hulk.json >> output.txt
./a.out units/ironman.json units/capt.json >> output.txt

diff output.txt units/results.txt

if [ $? -eq 0 ]
then
echo "No differences. The test was OK!"
else
echo "Test failed."
fi
