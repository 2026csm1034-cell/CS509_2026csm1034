#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

inline void pouseProgram(){
    std::cout<<"\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

inline vector<string> getTestFiles(const string &folder){
    vector<string> files;

    for(const auto &entry : fs::directory_iterator(folder))
    {
        if(entry.path().extension() == ".txt")
            files.push_back(entry.path().string());
    }

    sort(files.begin(), files.end());

    return files;
}

inline void showFiles(const vector<string> &files)
{
    cout << "\nAvailable Test Files\n\n";

    for(int i = 0; i < files.size(); i++)
    {
        cout << i + 1 << ". "
             << fs::path(files[i]).filename().string()
             << endl;
    }
}

inline string chooseTestFile(const string &folder)
{
    vector<string> files = getTestFiles(folder);

    showFiles(files);

    int choice;

    cout << "\nSelect File : ";
    cin >> choice;

    while(choice < 1 || choice > files.size())
    {
        cout << "Invalid choice. Enter again : ";
        cin >> choice;
    }

    return files[choice - 1];
}

inline string createOutputFile(const string &inputFile, const string &algorithm){
    //create outputs directory of it dosn't exits
    fs::create_directories("assignment_01/outputs");

    string filename = fs::path(inputFile).stem().string();

    string outputFile = "assignment_01/outputs/" + filename + "_" + algorithm + ".txt";

    return outputFile;
}

#endif // UTILITY_H