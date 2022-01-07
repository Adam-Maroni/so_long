#!/bin/bash

SO_LONG_PATH="/home/user42/cursus_42/so_long"
SO_LONG_EXE="so_long"

(cd $SO_LONG_PATH && make)
cp $SO_LONG_PATH/$SO_LONG_EXE $PWD
#TEST OF INVALID MAPS
valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid0.ber
valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid1.ber
#TEST VALID MAPS
valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE valid_maps/valid0.ber
rm $SO_LONG_EXE
