#include "pch.h"
#include "gmock/gmock.h"
#include "../ConsoleApplication1/ClassWeWantToTest.h"
#include "../ConsoleApplication1/Dependency.h"

using ::testing::Return;

class Mock_Dependency : public IDependency
{
public:
	MOCK_METHOD(int, should_return_2, (), (override));
};
TEST(TestCaseName, Test1) {
	std::shared_ptr<IDependency> sp_dependency = std::make_unique<Dependency>();
	ClassWeWantToTest sut(sp_dependency);
	auto value = sut.should_return_2();
	ASSERT_EQ(value, 2);
}

TEST(TestCaseName, Test2) {
	auto sp_dependency = std::make_shared<testing::StrictMock<Mock_Dependency>>();

	EXPECT_CALL(*sp_dependency, should_return_2())                         // #3
		.WillOnce(Return(2));

	ClassWeWantToTest sut(sp_dependency);
	auto value = sut.should_return_2();
	ASSERT_EQ(value, 2);
}

