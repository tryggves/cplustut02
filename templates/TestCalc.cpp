/**
 * Unit test using googletest framework.
 */
//
// Created by Tryggve Sørensen on 25/11/2019.
//


//#include <gmock/gmock.h>
#include "gtest/gtest.h"
#include "Calc.h"

class TestCalc : public ::testing::Test {
protected:
    void SetUp() override {

    }

    // void TearDown () override {}

    TCalc<float> m_Calc;
};

TEST_F(TestCalc, AddZero) {
    EXPECT_EQ(m_Calc.add(0.0, 0.0), 0.0);
}

TEST_F(TestCalc, AddIntegers) {
    EXPECT_EQ(m_Calc.add(1,1), 2);
}