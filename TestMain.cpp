#include "gtest/gtest.h"

int
main (int argc, char **argv)
{
  chdir ("data/iris");
	::testing::InitGoogleTest (&argc, argv);
	return RUN_ALL_TESTS ();
}
