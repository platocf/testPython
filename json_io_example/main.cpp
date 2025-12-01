#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // 创建一个JSON对象
    json j;
    j["name"] = "John Doe";
    j["age"] = 30;
    j["city"] = "New York";
    j["is_student"] = false;
    j["grades"] = {85, 90, 78, 92};
    j["address"] = {
        {"street", "123 Main St"},
        {"zipcode", "10001"}
    };

    // 将JSON写入文件
    std::ofstream file("data.json");
    if (file.is_open()) {
        file << j.dump(4); // 4表示缩进空格数
        file.close();
        std::cout << "JSON数据已写入 data.json 文件" << std::endl;
    } else {
        std::cerr << "无法打开文件进行写入" << std::endl;
        return 1;
    }

    // 从文件读取JSON
    std::ifstream input_file("data.json");
    if (input_file.is_open()) {
        json loaded_json;
        input_file >> loaded_json;
        input_file.close();

        std::cout << "\n从文件读取的JSON数据:" << std::endl;
        std::cout << loaded_json.dump(4) << std::endl;

        // 访问特定字段
        std::cout << "\n特定字段信息:" << std::endl;
        std::cout << "姓名: " << loaded_json["name"] << std::endl;
        std::cout << "年龄: " << loaded_json["age"] << std::endl;
        std::cout << "城市: " << loaded_json["city"] << std::endl;
        std::cout << "是否学生: " << std::boolalpha << loaded_json["is_student"] << std::endl;
        
        std::cout << "成绩: ";
        for (const auto& grade : loaded_json["grades"]) {
            std::cout << grade << " ";
        }
        std::cout << std::endl;
    } else {
        std::cerr << "无法打开文件进行读取" << std::endl;
        return 1;
    }

    return 0;
}