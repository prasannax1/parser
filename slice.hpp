#ifndef __SLICE_HPP
#define __SLICE_HPP
#include <cstddef>
#include <cstring>
#include <string>
class BadSlice {};
class BadIndex {};
class SliceIterator;

class Slice {
    public:
        Slice(std::string s) {
            auto l = s.length();
            _begin = new char [l + 1];
            _allocated = true;
            _end = _begin + l;
        }

        ~Slice() {
            if (_allocated) delete[] _begin;
            _allocated = false;
        }

        Slice operator() (int start, int stop) const {
            if (stop < 0) {
                stop += len();
            }
        
            if (start < 0) {
                start += len();
            }
        
            if (stop < 0 || start < 0 || stop < start || (unsigned)stop > len()) {
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

        SliceIterator begin();
        SliceIterator end();
        operator std::string() {
            return std::string(_begin, len());
        }

    private:
        char *_begin;
        char *_end;
        bool _allocated;

        Slice(char *begin, char *end) {
            if (_end < _begin) {
                throw BadSlice {};
            }
        
            _begin = begin;
            _end = end;
            _allocated = false;
        }
};

class SliceIterator {
    public:
        bool operator!=(const SliceIterator& other) const {
            return _index != other._index && _index <= _max;
        }

        char operator* () const {
            return _buf[_index];
        }

        const SliceIterator& operator++ () {
            ++_index;
            return *this;
        }

        SliceIterator(const Slice& s, char *p) {
            _max = s.len();
            _index = 0;
            _buf = p;
        }

    private:
        size_t _index;
        char* _buf;
        size_t _max;
};

SliceIterator Slice::begin() {
    return SliceIterator(*this, _begin);
}

SliceIterator Slice::end() {
    return SliceIterator(*this, _end);
}

#endif
