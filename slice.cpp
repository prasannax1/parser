#include "slice.h"
#include <cstring>
#include <cstddef>

Slice::Slice(char *buf) {
    _begin = buf;
    _index = _begin;
    auto len = strlen(buf);
    _end = _begin + len;
}

Slice::Slice(char *begin, char *end) {
    if (_end < _begin) {
        throw BadSlice {};
    }

    _begin = begin;
    _end = end;
}

std::size_t Slice::len() const {
    return _end - _begin;
}

Slice Slice::operator() (int start, int stop) const {
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

char& Slice::operator[] (int i) {
    if (i < 0 || i >= len()) {
        throw BadIndex {};
    }

    return _begin[i];
}

bool Slice::operator!= (const Slice& other) const {
    return _begin != other._begin
        || _end != other._end
        || _index != _end;
}

char Slice::operator* () const {
    return *_index;
}

const Slice& Slice::operator++ () {
    ++_index;
    return *this;
}

Slice Slice::begin() {
    _index = _begin;
    return *this;
}

Slice Slice::end() {
    return *this;
}

