#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>

std::string GetRoman(const int& int_number, std::map<int, std::string>& roman_map) {

    if (roman_map.find(int_number) != roman_map.end())
        return roman_map[int_number];

    if (int_number == 0)
        return "";

    int power_10 = log10(int_number);
    int val = (int)(int_number / pow(10, power_10)) * pow(10, power_10);


    auto it = roman_map.lower_bound(val);
    int diff = it->first - val;

    if (diff == 1 || diff == 10 || diff == 100)
        return roman_map[diff] + roman_map[it->first] + GetRoman(int_number - val, roman_map);

    else {
        std::string roman;
        it--;
        int count = val / it->first;
        int remainder = (val % it->first) / pow(10, power_10);

        for (size_t i = 0; i < count; i++)
            roman += roman_map[it->first];
        for (size_t i = 0; i < remainder; i++)
            roman += roman_map[pow(10, power_10)];

        return roman + GetRoman(int_number - val, roman_map);
    }

}
int main()
{
    std::cout << "Int to Roman\n";
    std::vector<std::string> roman_strings;
    std::map<int, std::string> roman_map{
        {1000,"M"},
        {500,"D"},
        {100,"C"},
        {50,"L"},
        {10,"X"},
        {5,"V"},
        {1,"I"},
    };

    std::cout<<GetRoman(893, roman_map)<<"\n";
}