#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

std::vector<std::string> textFile;
std::string temp;

void LoadFile()
{
    std::ifstream FILE("words_alpha.txt");
    while (std::getline(FILE, temp))
    {
        textFile.push_back(temp);
    }
    FILE.close();

    std::cout << "File Loaded" << std::endl << std::endl;
}

bool FindWord(const std::string& word)
{
    auto start = std::chrono::high_resolution_clock::now();
    bool found = false;

    int _l = 0;
    int length = textFile.size();
    while (length >= _l)
    {
        int mid = _l + (length - _l) / 2;
        if (textFile[mid] == word)
        {
            found = true;
        }
        if (textFile[mid] < word)
        {
            _l = mid + 1;
        }
        else
        {
            length = mid - 1;
        }
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = finish - start;
    std::cout << "   (Elapsed: " << elapsed.count() << ")       ";

    return found;
}

int main(int argc, char** argv)
{
    std::cout << "Loading File..." << std::endl << std::endl;

    LoadFile();

    // FOUND
    std::cout << "abacination:" << (FindWord("abacination") ? "found" : "not found") << std::endl;

    // FOUND
    std::cout << "palaeodictyopterous:" << (FindWord("palaeodictyopterous") ? "found" : "not found") << std::endl;

    // FOUND
    std::cout << "hello:" << (FindWord("hello") ? "found" : "not found") << std::endl;

    // NOT FOUND
    std::cout << "fliberty:" << (FindWord("fliberty") ? "found" : "not found") << std::endl;

    // NOT FOUND
    std::cout << "z:" << (FindWord("z") ? "found" : "not found") << std::endl;

    return 0;
}