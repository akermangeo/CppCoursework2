#include "pch.h"
#include "../Q6_VecLibrary/ArrVec.h"

using namespace VecLibrary;

TEST(ConstructorTest, Empty) {
    Vector empty_v0_{ };
    EXPECT_EQ(empty_v0_.size(), 0);
}

TEST(ConstructorTest, Zero0) {
    Vector zero_v0_{ 0 };
    EXPECT_EQ(zero_v0_.size(), 0);
}

TEST(ConstructorTest, Zero1) {
    Vector zero_v1_{ 10 };
    EXPECT_EQ(zero_v1_.size(), 10);

    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(zero_v1_[i], 0) << "Vectors zero_v1_ is not zero at index " << i;
    }
}

TEST(ConstructorTest, Constant0) {
    /// <summary>
    /// Test cases when v.n = 0 
    /// </summary>
    Vector const_v0_{ 0, 1 };
    EXPECT_EQ(const_v0_.size(), 0);
}

TEST(ConstructorTest, Constant1) {
    /// <summary>
    /// Test cases when constant = 1 
    /// </summary>
    Vector const_v1_{ 3, 1 };
    EXPECT_EQ(const_v1_.size(), 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(const_v1_[i], 1) << "Vectors const_v1_ is not 1 at index " << i;
    }
}

TEST(ConstructorTest, Constant2) {
    /// <summary>
    /// Test cases when constant = -1 
    /// </summary>
    Vector const_v2_{ 3, -1 };
    EXPECT_EQ(const_v2_.size(), 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(const_v2_[i], -1) << "Vectors const_v2_ is not -1 at index " << i;
    }
}

TEST(ConstructorTest, Constant3) {
    /// <summary>
    /// Test cases when constant = 1.2 
    /// </summary>
    Vector const_v3_{ 3, 1.2 };
    EXPECT_EQ(const_v3_.size(), 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(const_v3_[i], 1.2) << "Vectors const_v3_ is not 1.2 at index " << i;
    }
}

TEST(ConstructorTest, Constant4) {
    /// <summary>
    /// Test cases when constant = 0.0 
    /// </summary>
    Vector const_v4_{ 3, 0.0 };
    EXPECT_EQ(const_v4_.size(), 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(const_v4_[i], 0) << "Vectors const_v4_ is not 0 at index " << i;
    }
}

TEST(ConstructorTest, Arrary0) {
    /// <summary>
    /// Test cases when v.n = length of arrary 
    /// </summary>
    int va_len = 5;
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    Vector arr_v0_{ 5, a };

    EXPECT_EQ(arr_v0_.size(), va_len);

    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr_v0_[i], a[i]) << "Vectors arr_v0_ differs from a at index " << i;
    }
}

TEST(ConstructorTest, Arrary1) {
    /// <summary>
    /// Test cases when v.n < length of arrary 
    /// </summary>
    int va_len = 5;
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    Vector arr_v1_{ 3, a };

    EXPECT_EQ(arr_v1_.size(), 3);
    EXPECT_NE(arr_v1_.size(), va_len);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(arr_v1_[i], a[i]) << "Vectors arr_v1_ differs from a at index " << i;
    }
    for (int i = 3; i < va_len; i++) {
        EXPECT_NE(arr_v1_[i], a[i]) << "Vectors arr_v2_ should not the same as a a at index " << i;  /*TODO: What? I failed here*/
    }
}

TEST(ConstructorTest, Arrary2) {
    /// <summary>
    /// Test cases when v.n > length of arrary 
    /// </summary>
    int va_len = 5;
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    Vector arr_v2_{ 10, a };

    EXPECT_EQ(arr_v2_.size(), 10);
    EXPECT_NE(arr_v2_.size(), va_len);

    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(arr_v2_[i], a[i]) << "Vectors arr_v2_ differs from a at index " << i;
    }
}

TEST(ConstructorTest, Copy) {
    const Vector v{ 10, 1 };
    Vector u{ v };
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(v[i], u[i]) << "Vectors u differ from u at index " << i;;
    }
}

TEST(OperatorTest, Assign) {
    Vector u{ 10, 1 };
    Vector v{};
    v = u;
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(v[i], u[i]) << "Vectors u differ from u at index " << i;;
    }
}

TEST(OperatorTest, BracketModify) {
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    Vector v{ 10, a };

    v[1] = -2;

    for (int i = 0; i < 10; i++) {
        if (i == 1) {
            EXPECT_NE(v[i], a[i]) << "Vectors v equal to array va at index 1";
        }
        else {
            EXPECT_EQ(v[i], a[i]) << "Vectors v differ from array va at index " << i;
        }
    }
}

TEST(MethodTest, Resize) {
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    Vector v{ 10, a };

    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(v[i], a[i]) << "Vectors v differ from array va at index " << i;
    }

    v.resize(10);

    for (int i = 0; i < 10; i++) {
        EXPECT_NE(v[i], a[i]) << "Vectors v differ from array va at index " << i;
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(v[i], 0) << "Vectors v differ from array va at index " << i;
    }
}
