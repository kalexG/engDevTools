// tests.cpp
#include "..//inc/vmaOps.h"
#include <gtest.h>
 

TEST(VectorOpsTests, DotProductSizeException) {
   vmaOps vmaOps;
   double v1[3], v2[3];
   double s1=0;
   vmaOps.vSetOnes(v1);
   vmaOps.vSet123(v2);
   vmaOps.dotProduct(&s1,v1,v2);
   ASSERT_EQ(6, s1);
}

TEST(VectorOpsTests, DotProductOperationCheck) {
   vmaOps vmaOps;
   double v1[3], v2[3];
   double s1=0;
   vmaOps.vSetOnes(v1);
   vmaOps.vSet123(v2);
   vmaOps.dotProduct(&s1,v1,v2);
   ASSERT_EQ(6, s1);
}
 
/*TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}*/
 
int main(int argc, char **argv) {

   // Creating vmaOps object
   vmaOps vmaOps;

   double v1[3], v2[3], v3[3], v4[3];
   vmaOps.vSetOnes(v1);
   vmaOps.vSetOnes(v2);
   vmaOps.vSetOnes(v3);
   vmaOps.vSet123(v4); 
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
