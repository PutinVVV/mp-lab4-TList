#include "TArrList.h"
#include <gtest.h>

TEST(TArrList, can_create_TArrList)
{
  ASSERT_NO_THROW(TArrList<int> temp);
}

TEST(TArrList, can_get_begin_if_nullptr)
{
  TArrList<int> temp;
  ASSERT_NO_THROW(temp.GetBegin());
}

TEST(TArrList, can_get_end_if_nullptr)
{
  TArrList<int> temp;
  ASSERT_NO_THROW(temp.GetEnd());
}

TEST(TArrList, cant_get_if_nullptr)
{
  TArrList<int> temp;
  int s = 1;
  ASSERT_ANY_THROW(temp.Get(s));
}

TEST(TArrList, cant_del_if_nullptr)
{
  TArrList<int> temp;
  int s = 1;
  ASSERT_ANY_THROW(temp.Del(s));
}

TEST(TArrList, cant_del_begin_if_nullptr)
{
  TArrList<int> temp;
  ASSERT_ANY_THROW(temp.DelBegin());
}

TEST(TArrList, cant_del_end_if_nullptr)
{
  TArrList<int> temp;
  ASSERT_ANY_THROW(temp.DelEnd());
}

TEST(TArrList, can_push)
{
  TArrList<int> temp(10);
  double a = 1;
  ASSERT_NO_THROW(temp.PushBegin(a));
}

TEST(TArrList, can_push_and_get_equal)
{
  TArrList<int> temp(10);
  double a = 1;
  temp.PushBegin(a);
  ASSERT_EQ(temp.GetBegin() , a);
}