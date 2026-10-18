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

    void Reset();
    void Load(byte* source);

    void Remove();
    void Input(const byte& data);

    void Fill() const;

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

    void Up();
    void Down();

private:
    list<Line> lines_{};

    Gap gap_ = Gap(nullptr);

    size_t index_{};
    vector<Line*> lines_index_{};
    vector<Line*> lines_cache_{};

    bool changed_{false};

    void Update();
};
