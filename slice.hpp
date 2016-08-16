#ifndef __SLICE_HPP
#define __SLICE_HPP
#include <cstddef>
#include <cstring>
#include <string>
class BadSlice {};
class BadIndex {};

class Slice {
    public:
        Slice(char *buf) {
            _begin = buf;
            _index = _begin;
            auto len = strlen(buf);
            _end = _begin + len;
        }

        Slice(char *begin, char *end) {
            if (_end < _begin) {
                throw BadSlice {};
            }
        
            _begin = begin;
            _end = end;
        }

        Slice operator() (int start, int stop) const {
            if (stop < 0) {
                stop += len();
            }
        
            if (start < 0) {
                start += len();
            }
        
            if (stop < start) {
                throw BadSlice {};
            }
        
            return Slice{_begin + start, _begin + stop};
        }

        std::size_t len() const {
            return _end - _begin;
        }

        char& operator[] (int i) {
            if (i < 0 || (unsigned)i >= len()) {
                throw BadIndex {};
            }
        
            return _begin[i];
        }

        bool operator!= (const Slice& other) const {
            return _begin != other._begin
                || _end != other._end
                || (_index != _begin && _index != _end);
        }

        char operator* () const {
            return *_index;
        }

        const Slice& operator++ () {
            ++_index;
            return *this;
        }

        Slice begin() {
            _index = _begin;
            return *this;
        }

        Slice end() {
            return *this;
        }

        operator std::string() {
            return std::string(_begin, len());
        }

    private:
        char *_begin;
        char *_end;
        char *_index;
};

#endif













