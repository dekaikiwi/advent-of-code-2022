#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <bits/stdc++.h>


int main() {
    std::ifstream Data("calories.txt");
    std::string line;
    int32_t elfNumber = 0;
    int32_t total = 0;
    std::vector<int> weights;

    if (!Data.is_open()) {
        std::cout << "unable to open file" << std::endl;
        exit(1);
    }

    while (std::getline (Data, line)) {
       /* if(total > std::get<1>(elfWithMaxWeight)) { */
       /*     std::cout << "New Record: Elf number: " << elfNumber << " total: " << total << std::endl; */
       /*     elfWithMaxWeight = std::make_tuple(elfNumber, total); */
       /* } */

       if(line == "") {
            weights.push_back(total);
            elfNumber += 1;
            total = 0;
            continue;
       }

       total += std::stoi(line); 
    }

    std::sort(weights.begin(), weights.end(), std::greater<int>()); 

    std::cout << weights[0] + weights[1] + weights[2] << std::endl;

    Data.close();
}

