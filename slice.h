#ifndef __SLICE_H
#define __SLICE_H
#include <cstddef>
#include <string>

class Slice {
    public:
        Slice(char *buf);
        Slice(char *begin, char *end);
        Slice operator() (int start, int stop) const;
        std::size_t len() const;
        char& operator[] (int i);
        bool operator!= (const Slice& other) const;
        char operator* () const;
        const Slice& operator++ ();
        Slice begin();
        Slice end();
        operator std::string();

    private:
        char *_begin;
        char *_end;
        char *_index;
};

class BadSlice {};
class BadIndex {};
#endif
