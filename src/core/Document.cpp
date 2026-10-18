// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /src/core/Document.cpp
// Class for Document.

#include <cstring>
#include <pc/core/Document.hpp>

void Gap::Reset()
{
    content_.fill(std::byte{0x00});
    index_ = document::kGapFillSize;
    max_index_ = index_;
    min_index_ = index_;
}

void Gap::Load(std::byte* source)
{
    source_ = source;
    memcpy(content_.data(), source - document::kGapFillSize, document::kGapFillSize);
}

void Gap::Remove()
{
    if (index_ == 0)
    {
        index_--;
        min_index_ = std::min(index_, min_index_);
        content_[index_] = std::byte{0x00};
    } else
    {
        Fill();
        Reset();
    }
}

void Gap::Input(const std::byte& data)
{
    content_[index_] = data;
    index_++;
    max_index_ = std::max(index_, max_index_);
}

void Gap::Fill() const
{
    memcpy(source_, content_.data() + min_index_, max_index_ - min_index_);
}

void Document::Up()
{
    Update();
    if (index_ != 0)
        index_--;
}

void Document::Down()
{
    Update();
    if (index_ < lines_.size() - 1)
        index_++;
}

void Document::Update()
{
    if (changed_)
    {
        changed_ = false;
        gap_.Fill();
        gap_.Reset();
    }
}
