#!/bin/bash
./speller texts/lalaland.txt > student.txt
~cs50/pset4/speller texts/lalaland.txt > staff.txt
diff -y student.txt staff.txt
