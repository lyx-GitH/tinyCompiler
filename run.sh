if ! [[ -e build ]]; then
  mkdir build
fi


cd lexer
flex --header-file=base_lexer.h -t Lexer.l  > base_lexer.cpp
cd ..

cd build
cmake ..
make
cd ..

./build/tinyCompiler