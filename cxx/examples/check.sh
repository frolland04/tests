for f in `ls *.cpp` ; do echo "-> "$f ; g++ -std=c++2b -o $f.exe $f ; done
