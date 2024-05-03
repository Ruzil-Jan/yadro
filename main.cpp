#include <iostream>
#include "filetape.h"
#include "sorter.h"
 

void helper()
{
    std::cout<<"It's a surrogate mt"<<std::endl;
    std::cout<<"You can use it however you like "<<std::endl;
    std::cout<<"-h ,--help ,help "<<std::endl;
    std::cout<<"Use smt <input file> <output file>"<<std::endl;
}

int main(int argc, char** argv) {

    if (argc>1)
    {
        std::string msg =argv[1];
        if(msg=="-h"||msg=="--help"||msg=="help"){
            helper();
            return 0;
        }
    }
    if (argc < 3) {
        std::cerr << "Usee: " << argv[0] << " < call --help or -h for assistance. >\n\a";
        return 1;
    }
    std::string inputFilename = argv[1];
    std::string outputFilename = argv[2];
    //тк в линуксе почти все файлы создаем на вхлд и на выход 
    FileTape inputTape(inputFilename, "input.tmp");
    FileTape outputTape("output.tmp", outputFilename);
    // Создаем сортировщик и выполняем сортировку
    int maxMemory = 1024 * 1024;  // Огрнаичитель в байтах 
    std::string tmpDirectory = "/tmp";
    //можно попробовать std::experimental::filesystem::temp_directory_path();
    Sorter sorter(maxMemory, tmpDirectory);
    sorter.sort(inputTape, outputTape);
    std::cout << "Sorting completed. Output written to :" << outputFilename << std::endl;
    return 0;
}


