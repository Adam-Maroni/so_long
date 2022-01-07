#!/bin/bash

SO_LONG_PATH="/home/user42/cursus_42/so_long"
SO_LONG_EXE="so_long"

(cd $SO_LONG_PATH && make)
cp $SO_LONG_PATH/$SO_LONG_EXE $PWD

echo TEST OF INVALID MAPS
echo -n "invalid0.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid0.ber
echo -n "invalid1.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid1.ber
echo -n "invalid2.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid2.ber
echo -n "invalid3.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid3.ber
echo -n "invalid4.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid4.ber
echo -n "invalid5.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid5.ber
echo -n "invalid6.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid6.ber
echo -n "invalid7.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid7.ber
echo -n "invalid8.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE invalid_maps/invalid8.ber
echo TEST VALID MAPS
echo -n "valid0.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE valid_maps/valid0.ber
echo -n "valid1.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE valid_maps/valid1.ber
echo -n "valid2.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE valid_maps/valid2.ber
echo -n "valid3.ber -> " && valgrind --leak-check=full --show-leak-kinds=all -q ./$SO_LONG_EXE valid_maps/valid3.ber
rm $SO_LONG_EXE
