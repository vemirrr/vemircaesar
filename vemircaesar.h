#include <fstream>
#include <string>

using std::string;

class CaesarCipher{
    private:
        string rpath{};
        string wpath{};
        std::ifstream read;
        std::ofstream write;
        int shift{-3};
    public:
        CaesarCipher(const string&, const string&);
        ~CaesarCipher();

        void change_read(const string&);
        void change_write(const string&);

        void change_shift(int shift);

        void code();
        void decode();
};