#include <iostream>
#include <string>
#include <gtest/gtest.h>
using namespace std;

bool contained(const string& small, const string& big) {
	size_t j=0;
	for(size_t i=0; i< small.size(); ++i ) {
		size_t k=j;
		while(true) {
			if(k >= big.size()) {
				return false;
			}
			if(small[i]==big[k++]){
				j=k;
				break;
			}
		}
	}
	return true;
}

TEST(CONTAINED, 1)
{
	string small("book");
	string big("aeebefo24ola;sdkf");
	EXPECT_EQ(true, contained(small,big));
}

TEST(CONTAINED, 2)
{
	string small("foe");
	string big("aeebefo24ola;sdkf");
	EXPECT_EQ(false, contained(small,big));
}

TEST(CONTAINED, 3)
{
	string small("fold");
	string big("aeebefo24ola;sdkf");
	EXPECT_EQ(true, contained(small,big));
}