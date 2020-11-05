#!/bin/bash

rm -f output.txt
touch output.txt

./a.out scenario1.json >> output.txt
./a.out scenario2.json >> output.txt
./a.out units/test_scenario1.json >> output.txt
./a.out units/test_scenario2.json >> output.txt
./a.out units/test_scenario3.json >> output.txt

diff output.txt units/results.txt

if [ $? -eq 0 ]
then
echo "No differences. The test was OK!"
else
echo "Test failed."
fi
