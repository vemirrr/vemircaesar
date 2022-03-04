#include "vemircaesar.h"
#include <fstream>

using std::string;

CaesarCipher::CaesarCipher(const string& rpath, const string& wpath) : rpath{rpath}, wpath{wpath}{
    read.open(rpath);
    write.open(wpath);
}
CaesarCipher::~CaesarCipher(){ read.close(); write.close(); }

void CaesarCipher::change_read(const string& r){
    read.close();
    rpath = r;
    read.open(rpath);
}
void CaesarCipher::change_write(const string& w){
    write.close();
    wpath = w;
    write.open(wpath);
}

void CaesarCipher::code(){
    char tmp;

    while(true){
        tmp = read.get();
        if(tmp == EOF) break;
        if( tmp >= 'A' && tmp <= 'Z' ){
            tmp += shift;
            tmp -= 'A';
            tmp = (tmp < 0) ? ('Z' + tmp) : (tmp + 'A');
        }
        else 
        if( tmp >= 'a' && tmp <= 'z' ){
            tmp += shift;
            tmp -= 'a';
            tmp = (tmp < 0) ? ('z' + tmp) : (tmp + 'a');
        }

        write << tmp;
    }
}
void CaesarCipher::decode(){
    int dshift = 0 - shift;

    char tmp;

    while(true){
        tmp = read.get();
        if(tmp == EOF) break;
        if( tmp >= 'A' && tmp <= 'Z' ){
            tmp += dshift;
            tmp -= 'A';
            tmp = (tmp < 0) ? ('Z' + tmp) : (tmp + 'A');
        }
        else 
        if( tmp >= 'a' && tmp <= 'z' ){
            tmp += dshift;
            tmp -= 'a';
            tmp = (tmp < 0) ? ('z' + tmp) : (tmp + 'a');
        }

        write << tmp;
    }
}

void CaesarCipher::change_shift(int shift){ this->shift = shift; }