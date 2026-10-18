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

class Gap
{
public:
    explicit Gap(std::byte* source) : source_{source} {};

    void Reset();
    void Load(std::byte* source);

    void Remove();
    void Input(const std::byte& data);

    void Fill() const;

private:
    std::array<std::byte, document::kGapSize> content_{};

    size_t index_ = document::kGapFillSize;
    size_t max_index_{}, min_index_{};
    std::byte* source_{};
};

class Line
{
public:
    Line() = default;

private:
    std::vector<std::byte> content_{};
};

class Document
{
public:
    Document() = default;

    void Up();
    void Down();

private:
    std::list<Line> lines_{};

    Gap gap_ = Gap(nullptr);

    size_t index_{};
    std::vector<Line*> lines_index_{};
    std::vector<Line*> lines_cache_{};

    bool changed_{false};

    void Update();
};
