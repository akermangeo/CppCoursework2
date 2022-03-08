#include "pch.h"
#include "../Q6_vecLibrary/ArrVec.h"

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
    Vector const_v0_(0, 1 );
    EXPECT_EQ(const_v0_.size(), 0);
}

TEST(ConstructorTest, Constant1) {
    /// <summary>
    /// Test cases when constant = 1 
    /// </summary>
    Vector const_v1_( 3, 1 );
    EXPECT_EQ(const_v1_.size(), 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(const_v1_[i], 1) << "Vectors const_v1_ is not 1 at index " << i;
    }
}

TEST(ConstructorTest, Constant2) {
    /// <summary>
    /// Test cases when constant = -1 
    /// </summary>
    Vector const_v2_( 3, -1 );
    EXPECT_EQ(const_v2_.size(), 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(const_v2_[i], -1) << "Vectors const_v2_ is not -1 at index " << i;
    }
}

TEST(ConstructorTest, Constant3) {
    /// <summary>
    /// Test cases when constant = 1.2 
    /// </summary>
    Vector const_v3_( 3, 1.2 );
    EXPECT_EQ(const_v3_.size(), 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(const_v3_[i], 1.2) << "Vectors const_v3_ is not 1.2 at index " << i;
    }
}

TEST(ConstructorTest, Constant4) {
    /// <summary>
    /// Test cases when constant = 0.0 
    /// </summary>
    Vector const_v4_( 3, 0.0 );
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

TEST(ConstructorTest, Copy) {
    const Vector v(10, 1 );
    Vector u{ v };
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(v[i], u[i]) << "Vectors u differ from u at index " << i;
    }
}

TEST(OperatorTest, Assign) {
    Vector u{ 10, 1 };
    Vector v{};
    v = u;
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(v[i], u[i]) << "Vectors u differ from u at index " << i;
    }
}

TEST(OperatorTest, BracketModify1) {
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    Vector v( 5, a );

    v[1] = -2;

    for (int i = 0; i < 5; i++) {
        if (i == 1) {
            EXPECT_NE(v[i], a[i]) << "Vectors v equal to array va at index 1";
        }
        else {
            EXPECT_EQ(v[i], a[i]) << "Vectors v differ from array va at index " << i;
        }
    }
}

TEST(OperatorTest, BracketModify2) {
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    Vector v(5, a);

    double& data_member = v[1];
    data_member = -2;

    for (int i = 0; i < 5; i++) {
        if (i == 1) {
            EXPECT_NE(v[i], a[i]) << "Vectors v equal to array va at index 1";
        }
        else {
            EXPECT_EQ(v[i], a[i]) << "Vectors v differ from array va at index " << i;
        }
    }
}

TEST(OperatorTest, ConstBracket) {
    int va_len = 5;
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    const Vector v(5, a);

    EXPECT_EQ(v.size(), va_len);

    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(v[i], a[i]) << "Vectors v differs from a at index " << i;
    }
}

TEST(MethodTest, Resize) {
    double va[] = { 1, 2, 3, 4, 5 };
    double* a = &va[0];
    Vector v{ 5, a };

    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(v[i], a[i]) << "Vectors v differ from array va at index " << i;
    }

    v.resize(10);

    for (int i = 0; i < 5; i++) {
        EXPECT_NE(v[i], a[i]) << "Vectors v equal to va at index " << i;
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(v[i], 0.0) << "Vectors v differ from 0 at index " << i;
    }
}
