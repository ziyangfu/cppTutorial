/**
 * \brief: sample05, string的使用 */

#include <iostream>
#include <string>
#include <algorithm>  /** for transform */
#include <cstring>    /** C标准库字符串处理函数 */
#include <cstdlib>    /** 字符串与数据相互转换 */
using namespace std;
/** C风格字符串的处理， C标准库函数， C++支持，但不推荐使用 */
void CStyleString() {
    char* str1 = "hello";
    char* str2 = "a123456";
    /** 字符串长度 */
    cout << "C style, str length = " << strlen(str1) << endl;
    cout << "C style, str length = " << strnlen(str1, 10) << endl;
    /** 字符串比较 */
    cout << strcmp(str1, str2) << endl;  /** 7，str1中的h比str2中的g大7 */
    char* str3 = "her";
    cout << strncmp(str1, str3, 2) << endl;  /** 0，前两个字符相同 */
    /** 字符串拷贝 */
    char* str4 = new char[20];  /** 字符串在堆区 */
    strcpy(str4, str1);
    printf("str4 = %s\n", str4);  /** hello */
    delete[] str4;

    char str5[20];
    memset(str5, 0, sizeof(str5));
    strncpy(str5, str1, 2);
    printf("str5 = %s\n", str5);  /** he */
    /** 子字符串提取 */
    memset(str5, 0, sizeof(str5));
    strncpy(str5, str1 + 1, 3);
    printf("str5 = %s\n", str5);   /** ell */
    /** 字符串拼接 */
    strcat(str5, str2);
    printf("str5 = %s\n", str5); /** ella123456 */
    strncat(str5, str2, 3);
    printf("str5 = %s\n", str5);   /** ella123456a12 */
    memset(str5, 0, sizeof(str5));
    snprintf(str5, sizeof(str5), "%s.%s", str1, str2);
    printf("str5 = %s\n", str5);    /** hello.a123456 */
    /** 返回指向字符串str中字符ch第一次出现的位置的指针，如果str中不包含ch，则返回NULL */
    char* p = strchr(str1, 'l');
    if (p) {
        printf("p = %p, *p = %c\n", p, *p);  /** *p = l */
    }
    /** 字符串转化为数字 */
    char str6[5] = "100";
    char str7[10] = "200abc345";
    char* endptr;
    int var = atoi(str6);
    int var2 = static_cast<int>(strtol(str7, &endptr, 10));  /** 100， 200， abc345 */
    printf("var = %d, var2 = %d, endptr = %s \n", var, var2, endptr);
    /** 数字转化为字符串 */
    int var3 = 10;
    char str8[5];
    memset(str8, 0, sizeof(str8));
    sprintf(str8, "%d", var3);
    printf("str8 = %s\n", str8);  /** 10 */
}

void CppStyleString() {
    /** string的构造 */
    string str1("hello"); /** 生成一个字符串 */
    string str2 = str1;  /** 复制字符串 */
    cout << "str2 = " << str2 << endl;
    string str3("123456", 0, 3); /** 结果为 123 */
    cout << "str3 = " << str3 << endl;
    /** string的大小和容量 */
    cout << "str1 size = " << str1.size() << endl;  /** size = 5 */
    cout << "str1 length = " << str1.length() << endl; /** length = 5 */
    cout << "str1 capacity = " << str1.capacity() << endl; /** capacity = 15 */
    /** 字符串的比较 */
    if (str3 < str1)
        cout << "str3 < str1" << endl;  /** 根据 ASCII码比较，数字小于字母 */
    if (str1.compare(str3))
        cout << "str3 < str1" << endl;  /** 根据 ASCII码比较，数字小于字母 */
    /** 插入 */
    str1.push_back('c');
    str1.insert(str1.end(), 'p');
    cout << "str1 = " << str1 << endl;  /** hellocp */
    /** 拼接 */
    str1.append("world");
    str1 += "SAIC";
    cout << "str1 = " << str1 << endl;  /** hellocpworldSAIC */
    /** 删除 */
    str1.erase(str1.end() - 4, str1.end());
    cout << "str1 = " << str1 << endl; /** hellocpworld， 删除了 SAIC */
    /** 查找 */
    cout << str1.find("cp") << endl;  /** c的位置5，即第六个位置 */
    /** 截断 */
    string str4 = str1.substr(0, 5); /** str1 = hellocpworld str4 = hello */
    cout << "str1 = " << str1  << " str4 = " << str4 << endl;
    /** 元素访问 */
    cout << "str1第三个位置字符是：" << str1.at(2) << endl;  /** l */
    cout << "str1第三个位置字符是：" << str1[2] << endl;  /** l */
    cout << "str1最后字符是：" << str1.back() << endl;  /** d */
    /** 替换 */
    str1.replace(5,2, "ap");  /** 从第6个位置开始，删除2个位置(cp)，然后原位置替换为 ap */
    /** 清除与分配 */
    str3.clear();
    // str3.assign(str1);
    cout << str3.assign(str1, 0, 5) << endl;  /** hello */
    /** 判空 */
    cout << str1.empty() << endl;  /** 0， 非空 */
    /** 大小写转换, 以下采用了STL中的算法 */
    transform(str1.begin(), str1.end(),str1.begin(), ::toupper);
    cout << "str1 = " << str1 << endl; /** 转为大写，HELLOAPWORLD */
    /** 数值转为字符串 */
    int var = 100;
    string str5 = to_string(var);  /** C++11 */
    int var2 = stoi(str5);  /** C++11 */
    cout << "str5 = " << str5 << " var2 = " << var2 <<  endl; /** "100", 100 */
    /** 转换为C风格字符串 */
    const char* p = str1.c_str();
    printf("C 风格字符串： %s\n", p);
    while (*p != '\0') {
        cout << *p;
        p++;
    }
}

int main() {
    CStyleString();
    CppStyleString();
    return 0;
}
