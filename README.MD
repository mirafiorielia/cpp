# C++
 C++ labs and exercises by Elia Mirafiori

1- g++ -c main.cpp //compile program and link all projects file, then generate obj file
2- g++ -o main main.o //generate exe file from obj file
3- ./main //run the exe file

##g++ main.cpp
This compiles and links main.cpp to produce a default target executable file a.out in present working directory.
To run this program, type ./a.out where ./ represents present working directory and a.out is the executable target file.
Ex. g++ main.cpp

##g++ -S file_name
This is used to only compile the file_name and not assembling or linking.
It will generate a file_name.s assembly source file.
Ex. g++ -S main.cpp

##g++ -c file_name
This is used to only compile and assemble the file_name and not link the object code to produce executable file.
It will generate a file_name.o object code file in present working directory.
Ex. g++ -c main.cpp

##g++ -o target_name file_name
This compiles and links file_name and generates executable target file with target_name (or a.out by default).
Ex. g++ -o main.exe main.cpp
