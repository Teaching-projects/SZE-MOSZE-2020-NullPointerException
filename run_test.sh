#!/bin/bash

rm units/output.txt
touch output.txt

./a.out units/hulk.json units/capt.json >> units/output.txt
