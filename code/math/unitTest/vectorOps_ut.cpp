// vectorOpsTests.cpp
#include "../inc/vmaOps.h"
#include <gtest.h>
#include <gmock/gmock.h>
using namespace vmaOps;

// TESTING:: vSetZeros(double* vOut)
TEST(VectorOpsTests, setVectorToZerosFromEmpty) {
   double v1[3];
   vmaOps::vSetZeros(v1);
   ASSERT_THAT(v1, ::testing::ElementsAre(0.0, 0.0, 0.0));
}

TEST(VectorOpsTests, setVectorToZerosFromFull) {
   double v1[3] = {10.0, 20.0, 30.0};
   vmaOps::vSetZeros(v1);
   ASSERT_THAT(v1, ::testing::ElementsAre(0.0, 0.0, 0.0));
}

// TESTING:: vSetOnes(double* vOut)
TEST(VectorOpsTests, setVectorToOnesFromEmpty) {
   double v1[3];
   vmaOps::vSetOnes(v1);
   ASSERT_THAT(v1, ::testing::ElementsAre(1.0, 1.0, 1.0));
}

TEST(VectorOpsTests, setVectorToOnesFromFull) {
   double v1[3] = {10.0, 20.0, 30.0};
   vmaOps::vSetOnes(v1);
   ASSERT_THAT(v1, ::testing::ElementsAre(1.0, 1.0, 1.0));
}

// TESTING:: vSet123(double* vOut)
TEST(VectorOpsTests, setVectorTo123FromEmpty) {
   double v1[3];
   vmaOps::vSet123(v1);
   ASSERT_THAT(v1, ::testing::ElementsAre(1.0, 2.0, 3.0));
}

TEST(VectorOpsTests, setVectorTo123FromFull) {
   double v1[3] = {10.0, 20.0, 30.0};
   vmaOps::vSet123(v1);
   ASSERT_THAT(v1, ::testing::ElementsAre(1.0, 2.0, 3.0));
}

// TESTING:: vAdd(double* vOut, double* v1, double* v2)
TEST(VectorOpsTests, addVectorsReplaceInput) {
   double v1[3], v2[3];
   vmaOps::vSet123(v1);
   vmaOps::vSet123(v2);
   vmaOps::vAdd(v2, v1, v2);
   ASSERT_THAT(v2, ::testing::ElementsAre(2.0, 4.0, 6.0));
}

TEST(VectorOpsTests, addVectorsNewOutput) {
   double v1[3], v2[3], v3[3];
   vmaOps::vSet123(v1);
   vmaOps::vSetOnes(v2);
   vmaOps::vSetZeros(v3);
   vmaOps::vAdd(v3, v1, v2);
   ASSERT_THAT(v3, ::testing::ElementsAre(2.0, 3.0, 4.0));
}

// TESTING:: vSub(double* vOut, double* v1, double* v2)
TEST(VectorOpsTests, subVectorsReplaceInput) {
   double v1[3], v2[3];
   vmaOps::vSet123(v1);
   vmaOps::vSetOnes(v2);
   vmaOps::vSub(v2, v1, v2);
   ASSERT_THAT(v2, ::testing::ElementsAre(0.0, 1.0, 2.0));
}

TEST(VectorOpsTests, subVectorsNewOutput) {
   double v1[3], v2[3], v3[3];
   vmaOps::vSet123(v1);
   vmaOps::vSet123(v2);
   vmaOps::vSetOnes(v3);
   vmaOps::vSub(v3, v1, v2);
   ASSERT_THAT(v3, ::testing::ElementsAre(0.0, 0.0, 0.0));
}

// TESTING:: vMag(double* sOut, double* v1)
TEST(VectorOpsTests, vectorMagnitude) {
   double v1[3];
   double s1;
   vmaOps::vSet123(v1);
   vmaOps::vMag(&s1, v1);
   ASSERT_EQ(s1, sqrt(14));
   vmaOps::vSetOnes(v1);
   vmaOps::vMag(&s1, v1);
   ASSERT_EQ(s1, sqrt(3));
}

// TESTING:: vUnit(double* vOut, double* v1)
TEST(VectorOpsTests, vectorMagnitudeReplaceInput) {
   double v1[3];
   vmaOps::vSet123(v1);
   vmaOps::vUnit(v1, v1);
   ASSERT_THAT(v1, ::testing::ElementsAre(1.0/sqrt(14), 2.0/sqrt(14), 3.0/sqrt(14)));
}

TEST(VectorOpsTests, vectorMagnitudeNewOutput) {
   double v1[3], v2[3];
   vmaOps::vSet123(v1);
   vmaOps::vSetOnes(v2);
   vmaOps::vUnit(v2, v1);
   ASSERT_THAT(v2, ::testing::ElementsAre(1.0/sqrt(14), 2.0/sqrt(14), 3.0/sqrt(14)));
}

// TESTING:: crossProduct(double* vOut, double* v1, double* v2)
TEST(VectorOpsTests, vectorCrossProduct) {
   double v1[3], v2[3], v3[3];
   vmaOps::vSet123(v1);
   vmaOps::vSetOnes(v2);
   vmaOps::vSetZeros(v3);
   vmaOps::crossProduct(v3, v1, v2);
   ASSERT_THAT(v3, ::testing::ElementsAre(-1.0, 2.0, -1.0));
}

// TESTING:: dotProduct(double* sOut, double* v1, double* v2)
TEST(VectorOpsTests, vectorDotProduct) {
   double v1[3], v2[3];
   double s1;
   vmaOps::vSetOnes(v1);
   vmaOps::vSet123(v2);
   vmaOps::dotProduct(&s1, v1, v2);
   ASSERT_EQ(6, s1);
}

// TESTING:: vIsEqual(bool* isEqual, double* v1, double* v2)
TEST(VectorOpsTests, vectorIsEqualExpectTrue) {
   double v1[3], v2[3];
   bool isEqual;
   vmaOps::vSet123(v1);
   vmaOps::vSet123(v2);
   vmaOps::vIsEqual(&isEqual, v1, v2);
   EXPECT_TRUE(isEqual);
}

TEST(VectorOpsTests, vectorIsEqualExpectFalse) {
   double v1[3], v2[3];
   bool isEqual;
   vmaOps::vSet123(v1);
   vmaOps::vSetOnes(v2);
   vmaOps::vIsEqual(&isEqual, v1, v2);
   EXPECT_FALSE(isEqual);
}

// TESTING:: ScaXVec(double* vOut, double s1, double* v1)
TEST(VectorOpsTests, scalarTimesVectorReplaceInput) {
   double v1[3];
   double s1 = 2.5;
   vmaOps::vSet123(v1);
   vmaOps::ScaXVec(v1, s1, v1);
   ASSERT_THAT(v1, ::testing::ElementsAre(2.5, 5.0, 7.5));
}

TEST(VectorOpsTests, scalarTimesVectorNewOutput) {
   double v1[3], v2[3];
   double s1 = 2.5;
   vmaOps::vSet123(v1);
   vmaOps::vSetZeros(v2);
   vmaOps::ScaXVec(v2, s1, v1);
   ASSERT_THAT(v2, ::testing::ElementsAre(2.5, 5.0, 7.5));
}
 
 
int main(int argc, char **argv) {

   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
