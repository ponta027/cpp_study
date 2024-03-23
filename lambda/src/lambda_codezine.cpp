
/**
 * @brief
 * Lamdaに関する記事があったため、そのサンプルプログラムを作成する
 * https://codezine.jp/article/detail/19112?utm_source=seid_regular_20240321
 * * 関数ポインタについて
 *
 */

#include <cstdlib>
#include <iostream>

using namespace std;
/**
 * @brief
 *
 * @param a
 * @param b
 *
 * @return
 */
int func(int a, int b)
{
  return a + b;
}
/**
 * @brief comparetor
 *
 * @param a
 * @param b
 *
 * @return
 */
int compare_func(const void *a, const void *b)
{
  //  return -1;
  return *(int *)a - *(int *)b;
}

/**
 * @brief
 */
class LamdaSample
{
public:
  void execute(void)
  {
    sample_function_ptr();
    sample_quick_sort();
    sample_simple_lambda();
    sample_capture_lambda();
    sample_reference_capture_lambda();
    sample_mutable_capture_lambda();
  };

private:
  void sample_mutable_capture_lambda(void);
  void sample_reference_capture_lambda(void);
  /**
   * @brief
   */
  void sample_function_ptr(void);

  /**
   * @brief
   */
  void sample_quick_sort();
  void sample_simple_lambda();
  void sample_capture_lambda();
};

void LamdaSample::sample_function_ptr(void)
{
  cout << "# start " << __func__ << endl;
  cout << "```" << endl;
  int (*fp)(int, int) = &func;
  std::cout << fp(2, 3) << std::endl;

  cout << "```" << endl;
  return;
}

void LamdaSample::sample_quick_sort(void)
{
  cout << "# start " << __func__ << endl;
  cout << "```" << endl;
  int array[] = {9, 6, 5, 3, 7, 10};

  qsort(array, sizeof(array) / sizeof(array[0]), sizeof(int), compare_func);

  for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
  {
    cout << array[i] << endl;
  }

  cout << "```" << endl;
  return;
}
/**
 * @brief
 * [キャプチャ句](パラメータリスト) -> 戻り値の型 { ラムダ式の本体 }
 */
void LamdaSample::sample_simple_lambda(void)
{
  cout << "# start " << __func__ << endl;
  cout << "```" << endl;
  auto func = [](int x, int y) { return x * y; };
  cout << func(2, 3) << endl;

  return;
}

/**
 * @brief
 */
void LamdaSample::sample_capture_lambda(void)
{
  cout << "# start " << __func__ << endl;
  cout << "```" << endl;
  int i = 100;
  auto func = [i]() { return i; };
  cout << func() << endl;
  i = 200;
  cout << func() << endl;

  cout << "```" << endl;
  return;
}

/**
 * @brief
 */
void LamdaSample::sample_reference_capture_lambda(void)
{
  cout << "# start " << __func__ << endl;
  cout << "```" << endl;
  int j = 100;
  auto func = [&j]() { return j; };
  cout << func() << endl;
  j = 200;
  cout << func() << endl;
  cout << "```" << endl;
  return;
}

/**
 * @brief
 */
void LamdaSample::sample_mutable_capture_lambda(void)
{
  cout << "# start " << __func__ << endl;
  cout << "```" << endl;
  int j = 100;
  auto func = [j]() mutable {
    j++;
    return j;
  };
  cout << func() << endl;
  cout << "```" << endl;
  return;
}
/**
 * @brief
 *
 * @param argc
 * @param argv[]
 *
 * @return
 */
int main(int argc, char *argv[])
{
  LamdaSample().execute();
  return 0;
}

