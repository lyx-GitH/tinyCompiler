clear
if ! [[ -e build ]]; then
  mkdir build
fi

./conf_yacc_lex.sh

cd build
cmake ..
make -j8 && echo done
cd ..

pwd

ln -sf ./build/tinyCompiler ./tcc
figlet -f slant "TCC" | lolcat
