#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

void FuncHex() {
    int tmp[] = {0x01, 0x11, 0x2, 0xaa, 0x0f};
    for (auto& e : tmp)
        std::cout << std::setw(2) << std::setfill('0') << std::hex << e << " ";
    std::cout << std::endl;
}

void FuncVal() {
    short s = 123;
    int i = 777;
    char str[16] = {0};

    memcpy(str, &s, 2);
    memcpy(str + 2, &i, 4);
    float d = 0.0;
    d = static_cast<float>((str[0] | (str[1] << 8)) / 2.0);
    int ii = 0;
    ii = static_cast<int>(str[2] | (str[3] << 8) | (str[4] << 16) |
                          (str[5] << 24));
    int iii = 0;
    memcpy(&iii, str + 2, 4);

    std::cout << d << std::endl;
}

template <typename T>
void TestTemplate(T& t) {
    auto size = sizeof(t);
    std::cout << "size of t is: " << size << std::endl;
}

void FuncSize() {
    int tmp[4] = {0};
    tmp[0] = 1;
    std::cout << "size of tmp is: " << sizeof(tmp) << std::endl;
    TestTemplate(tmp);

    char str[9] = {0};
    str[0] = 'a';
    str[1] = 'b';
    std::cout << "size of str is: " << sizeof(str) << std::endl;
    TestTemplate(str);

    // TestTemplate(nullptr);
    return;
}

template <class T>
void ToString(string& result, const T& t) {
    ostringstream oss;
    oss.precision(std::numeric_limits<double>::digits10);
    oss << t;
    result = oss.str();
}
void FuncDoubleToString() {
    double d = 11378462.1;
    std::string s;
    ToString(s, d);
    auto len = s.length();

    char tmp[48] = {0};
    // sprintf(tmp, "%0.12f", d);
    sprintf_s(tmp, 16, "%08.2f", d);
    int x = 0;
}

void FuncSizeof() {
    int arr[32] = {0};
    int size = 0;
    size = sizeof(arr);
    return;
}

int main() {
    std::cout << "hello..." << std::endl;
    // FuncSolution();
    // FuncHex();
    // FuncVal();
    // FuncSize();
    FuncDoubleToString();
    // FuncSizeof();
    return 0;
}