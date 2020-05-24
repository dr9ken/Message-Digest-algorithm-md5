#ifndef HASH_MD5_H
#define HASH_MD5_H

#include <fstream>
#include <string>
#include "queue.cpp"
#include "stack.cpp"

using namespace std;
typedef unsigned int UI32;
typedef unsigned long  long int UI64;

class md5
{
private:
    struct Buffer{
        Buffer() :
                A(0x67452301), // 01 23 45 67
                B(0xefcdab89), // 89 AB CD EF
                C(0x98badcfe), // FE DC BA 98
                D(0x10325476)  // 76 54 32 10
        { };

        UI32 A;	UI32 B;
        UI32 C;	UI32 D;
    };

    string final_hash;
    Buffer words;
    UI64 sizeFile;
    queue <int> bit_file;
    UI32 array_white_noise[64];

    //-------------------------------------> HASH <-------------------------------------//

    // function ranslates file into bits
    void file_in_bits(int);

    // function create array "white noise"
    void wt_noise();

    // function create array of 16  elements with 32-bit words
    void create_array_flow(UI32*);

    // function
    void hash_to_string(UI32);

    // cyclic shift "<<<"
    UI32 cyclic_shift(UI32, int);
    void reverse_word(UI32);

public:
    // constructor --> runs algorithm
    md5(string);

    // destructor --> he exist
    ~md5(){};

    // function flow aligment
    void flow_alignment();

    // function adding message length
    void add_msg_length();

    // function generate hash
    void create_hash();

    // function output hash
    string output_hash();
};
#endif //HASH_MD5_H
inline  string MD5(string path) {
    md5 hash(path);

    hash.flow_alignment();

    hash.add_msg_length();

    hash.create_hash();

    return hash.output_hash();
}

