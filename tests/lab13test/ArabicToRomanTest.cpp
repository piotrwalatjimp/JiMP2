//
// Created by mwypych on 01.06.17.
//

#include <string>
#include <gtest/gtest.h>
#include <ArabicRoman.h>

using ::std::string;

TEST(arabic_to_roman, converOfArabic1ReturnString) {
    EXPECT_EQ("I", ArabicToRoman(1));
}

TEST(arabic_to_roman, converOfArabic5ReturnString) {
    EXPECT_EQ("V", ArabicToRoman(5));
}

TEST(arabic_to_roman, converOfArabic10ReturnString) {
    EXPECT_EQ("X", ArabicToRoman(10));
}

TEST(arabic_to_roman, converOfArabic50ReturnString) {
    EXPECT_EQ("L", ArabicToRoman(50));
}

TEST(arabic_to_roman, converOfArabic100ReturnString) {
    EXPECT_EQ("C", ArabicToRoman(100));
}

TEST(arabic_to_roman, converOfArabic500ReturnString) {
    EXPECT_EQ("D", ArabicToRoman(500));
}

TEST(arabic_to_roman, converOfArabic1000ReturnString) {
    EXPECT_EQ("M", ArabicToRoman(1000));
}


