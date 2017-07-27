#include "LeetCodeDataStructure.h"

// 数组
namespace LeetCode {

	class LEETCODE_EXP LCArray {
	public:
		// 构造：输入 "[1, 2, 3, 4]" 类型的字符串
		LCArray() = default;
		LCArray(std::string strInput);
		LCArray(const char* strInput);

		// 析构
		~LCArray();

		// 获取：std::vector<int> 类型的数组
		std::vector<int> GetArray() const;

		// 打印：数组内容
		void PrintArray() const;

	private:
		// 构造：将字符串输入转化为 std::vector<int> 内置类型
		bool _ConstructArray(std::string strInput);

	private:
		std::vector<int> m_vecArray;
	};

}