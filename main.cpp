/*
** SIDE PROJECT, 2021
** cipher
** File description:
** main
*/

#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>

void print_help()
{
    std::cout << "Usage:\n\t./cipher [textToEncrypt] [-f 'pathToFileToEncrypt'] [-n 'sizeOfShift']" << std::endl;
}

std::string caesar_cipher(std::string *text, int shift)
{
    for (size_t i = 0; i < text->length(); i++)
        text->at(i) += shift;
    return *text;
}

std::string readFile(std::string filename)
{
    std::ifstream input(filename, std::ios_base::in);
    std::string buffer;
    std::string content;

    while (std::getline(input, buffer))
        content += buffer;
    return content;
}

int main(int ac, char **av)
{
    int c = 0;
    std::string text, filename, remaining;
    bool fileMode = false;
    int shift = 3;
    while ((c = getopt(ac, av, "f:n:h")) != -1) {
        switch (c) {
            case 'f':
                if (optarg) {
                    filename = optarg;
                    fileMode = true;
                }
                break;
            case 'n':
                if (optarg)
                    shift = atoi(optarg);
                break;
            case 'h':
                print_help();
                break;
        }
    }
    if (optind != ac)
        text = av[optind];
    if (fileMode) {
        text = readFile(filename);
    }
    caesar_cipher(&text, shift);
    std::cout << text << std::endl;
    return 0;
}