#include <string>
#include <sstream>
#include <iostream>

#ifndef __splitIter_H
#define __splitIter_H
class splitIter {
    public:
        splitIter(std::string s, char c)
            : _sep(c) {
            _f = new std::istringstream(s);
        }

        bool operator!= (const splitIter& other) const {
            return ! _f->eof();
        }

        std::string operator* () {
            return std::string(_s);
        }

        const splitIter& operator++ () {
            getline(*_f, _s, _sep);
            return *this;
        }

        splitIter begin() {
            return *this;
        }

        splitIter end() {
            return *this;
        }

    private:
        char _sep;
        std::istringstream *_f;
        std::string _s;
};
#endif
