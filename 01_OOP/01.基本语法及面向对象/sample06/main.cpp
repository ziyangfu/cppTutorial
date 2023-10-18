/**
 * \brief sample06, vector容器的使用 */

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {
    /** 传统C++方式 */
   // for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
   //     cout << *it << " ";
   // }
    /** C++11，基于范围的for循环*/
    for(auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    /** 构造函数 */
    vector<int> v1; /** 无参构造 */
    for (int i = 0; i < 5; i++){
        v1.push_back(i);   /** 尾部插入数据 */
    }
    {
        printVector(v1);  /** 0 1 2 3 4 */
        /** 将v1[begin(), end())区间中的元素拷贝给v2 */
        vector<int> v2(v1.begin(), v1.end());
        printVector(v2);   /** 0 1 2 3 4 */

        vector<int> v3(3, 100);
        printVector(v3);  /** 100 100 100  */
        /** 拷贝构造 */
        vector<int> v4(v3);
        printVector(v4);  /** 100 100 100  */
    }

    /** 赋值 */
    {
        vector<int>v2;
        v2 = v1;  /** 赋值构造 */
        printVector(v2);  /** 0 1 2 3 4 */

        vector<int>v3;
        /** 将v1[begin(), end())区间中的元素拷贝给v3 */
        v3.assign(v1.begin(), v1.end());
        printVector(v3);  /** 0 1 2 3 4 */

        vector<int>v4;
        v4.assign(3, 100);
        printVector(v4);  /** 100 100 100 */
    }
    /** 容量与大小 */
    {
        if (v1.empty())
        {
            cout << "v1为空" << endl;
        }
        else
        {
            cout << "v1不为空" << endl;
            cout << "v1的容量 = " << v1.capacity() << endl;  /** 8 */
            cout << "v1的大小 = " << v1.size() << endl;      /** 5 */
        }

        /** resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充 */
        v1.resize(8,10);
        printVector(v1);  /** 0 1 2 3 4 10 10 10 */

        /** resize 重新指定大小 ，若指定的更小，超出部分元素被删除 */
        v1.resize(5);
        printVector(v1);  /** 0 1 2 3 4 */
    }
    /** 插入与删除 */
    {
        v1.pop_back();  /** 从尾部删除数据，这里删除了4 */
        printVector(v1); /** 0 1 2 3 */
        /** 插入 */
        v1.insert(v1.begin(), 100);
        printVector(v1);  /** 100 0 1 2 3  */

        v1.insert(v1.begin(), 2, 1000);
        printVector(v1);  /** 1000 1000 100 0 1 2 3 */

        /** 删除 */
        v1.erase(v1.begin());  /** 删除了第一个元素 */
        printVector(v1);  /** 1000 100 0 1 2 3 */

        /** 清空 */
        v1.erase(v1.begin(), v1.end());
        //v1.clear();
        cout << v1.empty() << endl;  /** 1 */
    }
    /** 数据存取 */
    {
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
            cout << v1.at(i) << " ";
        }
        cout << endl;
        cout << "v1的第一个元素为： " << v1.front() << endl;
        cout << "v1的最后一个元素为： " << v1.back() << endl;
    }
    /** 互换容器 */
    {
        vector v2{ 4, 3, 2, 1, 0 };
        vector v3{ 0, 1, 2, 3, 4 };
        printVector(v1);
        printVector(v2);
        cout << "互换后" << endl;
        v1.swap(v2);
        printVector(v1);
        printVector(v2);
    }
    /** 编程技法： 善用swap */
    {
        vector<int> v;
        for (int i = 0; i < 100000; i++) {
            v.push_back(i);
        }
        cout << "v的容量为：" << v.capacity() << endl; /** 131072 */
        cout << "v的大小为：" << v.size() << endl; /** 100000 */
        v.resize(3);
        /** 只有三个有效元素了，但是还占据了 131072 的空间 */
        cout << "v的容量为：" << v.capacity() << endl;
        cout << "v的大小为：" << v.size() << endl;  /** 3*/
        /** 收缩内存 */
        vector<int>(v).swap(v); /** 匿名对象 */
        cout << "v的容量为：" << v.capacity() << endl;  /** 3 */
        cout << "v的大小为：" << v.size() << endl;   /** 3 */
    }
    /** 预留空间 */
    {
        vector<int> v;
        /** 提前预留100000，避免频繁扩容 */
        v.reserve(100000);

        int num = 0;
        int* p = nullptr;
        for (int i = 0; i < 100000; i++) {
            v.push_back(i);
            /** 涉及到vector的底层原理 */
            if (p != &v[0]) {
                p = &v[0];
                num++;
            }
        }
        cout << "num:" << num << endl;  /** 1 */
    }
    return 0;
}
