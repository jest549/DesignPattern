#include "Expression.h"
int main() {
    vector<string> expStr;
    unordered_map<string, double> var;
    getExpStr(expStr);
    getValue(var, expStr);

    Calculator* calcutor = new Calculator(expStr);

    cout << "运算结果：" << vector_to_string(expStr) 
         << " = " << calcutor->run(var) << endl;
}
