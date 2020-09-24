#!/bin/bash

rm output.txt
touch output.txt

./a.out units/capt.json units/hulk.json >> output.txt
./a.out units/capt.json units/ironman.json >> output.txt
./a.out units/hulk.json units/capt.json >> output.txt
./a.out units/hulk.json units/ironman.json >> output.txt
./a.out units/ironman.json units/hulk.json >> output.txt
./a.out units/ironman.json units/capt.json >> output.txt
