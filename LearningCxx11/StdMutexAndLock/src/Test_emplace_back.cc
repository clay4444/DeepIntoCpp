#include <vector>  
#include <string>  
#include <iostream>  

/*
 * 引入右值引用之后 和 转移构造函数，push_back()右值时就会调用构造函数和转移构造函数。
 * emplace_back 相比是省去了内次转移构造。 只有一次构造函数
 */
struct President  
{  
    std::string name;  
    std::string country;  
    int year;  

    President(std::string p_name, std::string p_country, int p_year)  
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)  
    {  
        std::cout << "I am being constructed.\n";  
    }
    President(const President& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being copy constructed.\n";
    }
    President(President&& other)  
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)  
    {  
        std::cout << "I am being moved.\n";  
    }  
    President& operator=(const President& other);  
};  

int main()  
{  
    std::vector<President> elections;  
    std::cout << "emplace_back:\n";  
    
    elections.emplace_back("Nelson Mandela", "South Africa", 1994); //没有类的创建  

    std::vector<President> reElections;  
    std::cout << "\npush_back:\n";  
    
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));  

    std::cout << "\nContents:\n";

    for (President const& president: elections) {  
       std::cout << president.name << " was elected president of "  
            << president.country << " in " << president.year << ".\n";  
    }  

    for (President const& president: reElections) {  
        std::cout << president.name << " was re-elected president of "  
            << president.country << " in " << president.year << ".\n";  
    }

}