#pragma once
#include <cstdint>
#include <string>

namespace {

    struct Point {
        double x_;
        double y_;

        Point(double x, double y) : x_(x), y_(y) {}
    };

    struct Rgb {
        int8_t red_;
        int8_t green_;
        int8_t blue_;

        Rgb(int8_t red, int8_t green, int8_t blue) : red_(red), green_(green), blue_(blue) {}
    };

    struct Color {
        std::string color_;

        Color() : color_("none") {}
        Color(const std::string& color) : color_(color) {}
        Color (const Rgb& rgb) : color_("rgb(" + std::to_string(rgb.red_) + "," 
                                               + std::to_string(rgb.green_) + "," 
                                               + std::to_string(rgb.blue_) + ")") {}
    };

    struct Document {

    };
}