#include <iostream>
#include <string>

// 抽象基类
class DataProcessor
{
public:
    virtual ~DataProcessor() = default;

    // 模板方法，定义算法框架
    void process()
    {
        readData();
        processData();
        saveData();
    }

protected:
    // 基本方法（可以由子类实现）
    virtual void readData() = 0;
    virtual void processData() = 0;

    // 钩子方法（提供默认实现，可由子类重写）
    virtual void saveData() { std::cout << "Saving data to default location." << std::endl; }
};

// 具体类：处理CSV文件
class CSVDataProcessor : public DataProcessor
{
protected:
    void readData() override { std::cout << "Reading data from CSV file." << std::endl; }

    void processData() override { std::cout << "Processing data from CSV file." << std::endl; }

    void saveData() override { std::cout << "Saving processed data to CSV file." << std::endl; }
};

// 具体类：处理JSON文件
class JSONDataProcessor : public DataProcessor
{
protected:
    void readData() override { std::cout << "Reading data from JSON file." << std::endl; }

    void processData() override { std::cout << "Processing data from JSON file." << std::endl; }

    void saveData() override { std::cout << "Saving processed data to JSON file." << std::endl; }
};

int main()
{
    // 使用 CSV 数据处理器
    std::cout << "Using CSVDataProcessor:" << std::endl;
    CSVDataProcessor csvProcessor;
    csvProcessor.process();

    std::cout << std::endl;

    // 使用 JSON 数据处理器
    std::cout << "Using JSONDataProcessor:" << std::endl;
    JSONDataProcessor jsonProcessor;
    jsonProcessor.process();

    return 0;
}