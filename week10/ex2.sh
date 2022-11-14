link ../week01/file.txt _ex2.txt
ls -i ../week01/file.txt
find .. -inum 1052174
find .. -inum 1052174 -exec rm {} \;
