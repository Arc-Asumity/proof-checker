// ==============================================================
// Copyright (c) 2026 Arc Asumity
// Licensed under the MIT.
// https://github.com/Arc-Asumity/proof-checker
// ==============================================================
// Path /include/pc/core/Document.hpp
// Header file for Document class.

#pragma once

#include <list>
#include <vector>
#include <array>
#include <pc/Definition.hpp>

using namespace std;

class Gap
{
public:
    explicit Gap(byte* source) : source_{source} {};

    void reset();
    void load(byte* source);

    void remove();
    void input(const byte& data);

    void fill() const;

private:
    array<byte, document::kGapSize> content_{};

    size_t index_ = document::kGapFillSize;
    size_t max_index_{}, min_index_{};
    byte* source_{};
};

class Line
{
public:
    Line() = default;

private:
    vector<byte> content_{};
};

class Document
{
public:
    Document() = default;

    void up();
    void down();

private:
    list<Line> lines_{};

    Gap gap_ = Gap(nullptr);

    size_t index_{};
    vector<Line*> lines_index_{};
    vector<Line*> lines_cache_{};

    bool changed_{false};

    void update();
};
