// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/core/Document.cpp
// Class for Document.

#include <cstring>
#include <pc/core/Document.hpp>

using namespace std;

void Gap::reset()
{
    content_.fill(byte{0x00});
    index_ = document::kGapFillSize;
    max_index_ = index_;
    min_index_ = index_;
}

void Gap::load(byte* source)
{
    source_ = source;
    memcpy(content_.data(), source - document::kGapFillSize, document::kGapFillSize);
}

void Gap::remove()
{
    if (index_ == 0)
    {
        index_--;
        min_index_ = min(index_, min_index_);
        content_[index_] = byte{0x00};
    } else
    {
        fill();
        reset();
    }
}

void Gap::input(const byte& data)
{
    content_[index_] = data;
    index_++;
    max_index_ = max(index_, max_index_);
}

void Gap::fill() const
{
    memcpy(source_, content_.data() + min_index_, max_index_ - min_index_);
}

void Document::up()
{
    update();
    if (index_ != 0)
        index_--;
}

void Document::down()
{
    update();
    if (index_ < lines_.size() - 1)
        index_++;
}

void Document::update()
{
    if (changed_)
    {
        changed_ = false;
        gap_.fill();
        gap_.reset();
    }
}
