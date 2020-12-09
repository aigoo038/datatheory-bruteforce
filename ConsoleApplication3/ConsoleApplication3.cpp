#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <fstream>
#include <windows.h>
#include <thread>
#include <vector>


void word_attack(const std::string& dct, const std::string& zpf, int& out)
{
  
    std::string key;
    std::string pass;
    std::ifstream dict_file(dct);
    int s = 0;
    auto start = std::chrono::steady_clock::now();
    while (std::getline(dict_file, pass))
    {
        s++;
        int status = system(("\"C:\\Program Files\\7-Zip\\7z.exe\" t -bse0 -bso0 -bd -p" + pass + " " + zpf).c_str());
        if (status == 0)
        {
            key = pass; 
            std::cout << "Password found: " << pass << std::endl;
            auto end = std::chrono::steady_clock::now();
            dict_file.close();
            auto elapsed_seconds = std::chrono::duration_cast <std::chrono::seconds> (end - start);
            std::cout << "Algorithm time: " << elapsed_seconds.count() << "s\n";
            out = 0;
        }
        else { continue; }
        
    };
    std::cout << std::endl<<std::this_thread::get_id()<<" thread\t" << dct <<" Password not found.." << std::endl;
    dict_file.close();
    out =  2;
};


void save_logs(const std::string dct)
{
    std::ofstream logFile;
    if (!logFile.is_open()) 
    {
        logFile.open("log.txt", std::ios::app);
        logFile << "No password in2 " + dct + " " + "\n";
        logFile.close();
    }
    else 
    {
        logFile.open("log.txt", std::ios::app);
        logFile << "No password in1 " + dct + " " +"\n";
        logFile.close();
    }
}


int main()
{
    std::string dct2 = "rockyou.txt";
    std::string dct = "temp.txt";
    std::string zpf = "ki1801.04.7z";
    std::string dct_small = "";

    //int s = 0;

    //
    //for (int i=0; i<63;i++){ 
    //    dct_small = ("word_" + std::to_string(i) + ".0.txt");
    //    std::cout << dct_small << std::endl;
    //    int output = word_attack(dct_small, zpf, output);
    //    if (output == 2) 
    //    { 
    //        save_logs(dct_small);
    //        continue; 
    //    }
    //} 

    int thread_count = 0;
    
    while (thread_count < 63) 
    {
        int out_0 = 0;
        std::string dct_small_0 = ("word_" + std::to_string(thread_count) + ".0.txt");
        std::thread thr_0(word_attack, dct_small_0, zpf, std::ref(out_0));
        std::cout <<"0\t" <<thr_0.get_id() << std::endl;
        
        if (out_0 == 2)
        {
            save_logs(dct_small_0);
            continue;
        }

        int out_1 = 0;
        std::string dct_small_1 = ("word_" + std::to_string(thread_count + 1) + ".0.txt");
        std::thread thr_1(word_attack, dct_small_1, zpf, std::ref(out_1));
        std::cout << "1\t" << thr_1.get_id() << std::endl;
        if (out_1 == 2)
        {
            save_logs(dct_small_1);
            continue;
        }

        int out_2 = 0;
        std::string dct_small_2 = ("word_" + std::to_string(thread_count + 2) + ".0.txt");
        std::thread thr_2(word_attack, dct_small_2, zpf, std::ref(out_2));
        std::cout << "2\t" << thr_2.get_id() << std::endl;
        if (out_2 == 2)
        {
            save_logs(dct_small_2);
            continue;
        }

        int out_3 = 0;
        std::string dct_small_3 = ("word_" + std::to_string(thread_count + 3) + ".0.txt");
        std::thread thr_3(word_attack, dct_small_3, zpf, std::ref(out_3));
        std::cout << "3\t" << thr_3.get_id() << std::endl;

        if (out_3 == 2)
        {
            save_logs(dct_small_3);
            continue;
        }
        thread_count += 4;
        thr_0.join();
        thr_1.join();
        thr_2.join();
        thr_3.join();

        
    }

};



