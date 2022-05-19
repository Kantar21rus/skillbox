#include <iostream>
#include <filesystem>


namespace fs = std::filesystem;

int main() {
    std::string pathStr, extension;
    std::cin >> pathStr >> extension;
    fs::path path(pathStr);
    [](fs::path path, const std::string extension){
        for (auto p : fs::recursive_directory_iterator(path)) {
            if (fs::is_regular_file(p.path())) {
                if (p.path().extension() == extension) {
                    std::cout << p.path() << "\n";
                }
            }
        }
        return true;
    }(path, extension);
}
