Firstly, i had not explored much on files using C++ except the basics, i found an approach using MMAP on the internet , it uses mmap to map the file into memory and process it as a large string. This can be efficient for random access and large files.
But, its biggest downside is it requires a Unix based machine also  requires special handling for large files, and can cause excessive memory usage if the file is too large.
Pro: Faster for reading large files since it avoids system calls for each read operation.
Con: Not portable to Windows and the special handling for large files.

Final Approach: 
It Uses C++’s ifstream to read the file line by line, checking each line’s timestamp and writing matching lines to an output file.
It Works on both Linux and Windows.
Low memory usage since only one line is loaded into memory at a time.
Simpler to implement and debug.
Cons: Slightly slower than mmap due to repeated system calls but negligible for our use case.


Steps To Run:
1) Install a C++ Compiler (If Not Installed)
2)compile the code by  : g++ -O2 -std=c++17 extract_logs.cpp -o extract_logs.exe
3)run the program by :extract_logs.exe test_logs.log 2024-12-01
4)The extracted logs will be saved in "output/output_2024-12-01.txt"
