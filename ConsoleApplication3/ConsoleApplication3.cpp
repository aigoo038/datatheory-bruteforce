#include <iostream>
#include <fstream>
#include <string>
#include <vector>



void word_attack(const std::string& dct, const std::string& zpf)
{
    std::string pass;
    std::vector <std::string> pwds;
    std::ifstream dict_file(dct);
    while (std::getline(dict_file, pass))
    {
        if (pass.length() < 6) {
            int status = system(("\"C:\\Program Files\\7-Zip\\7z.exe\"  x -bse0 -bso0 -oC:\\Users\\Toxicity\\PycharmProjects\\inf -p" + pass + " " + zpf).c_str());
            std::cout << "|" << pass << "|" << std::endl;
            if (status == 0)
            {
                std::cout << "Password found: " << pass << std::endl;
            }
        }
    };
    dict_file.close();
};



int main()
{
    /*std::cout << "How to crack the archive?" << std::endl;
    std::cout << "1. By wordlist. \n2. By guess." << std::endl;
    int i;
    std::cin >> i;*/

    std::string dct = "rockyou.txt";
    std::string zpf = "ki1801.04.7z";
    //switch (i) {
    //case 1:
    //    word_attack(dct, zpf);
    //case 2:
    //    break; 
    //    //brute(dct, zpf);
    //
    //}

    word_attack(dct, zpf);
};



