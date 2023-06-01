clear
if ! [[ -e build ]]; then
  mkdir build
fi

./conf_yacc_lex.sh

cd build
cmake ..
make -j8 && echo done