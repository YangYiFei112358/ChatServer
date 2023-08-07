#include "json.hpp"
using nlohmann::json;

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// 需要讲解独立字段、容器序列化

string func1() {
  json js;
  js["msg_type"] = 2;
  js["from"] = "zhang san";
  js["to"] = "li si";
  js["msg"] = "hello, lalala";
  cout << js << endl;

  // zhu
  string sendbuf = js.dump();       // 输出 的意思
  cout << sendbuf.c_str() << endl;  // 转 char*
  return sendbuf;
}

string func2() {
  json js;
  // 添加数组
  js["id"] = {1, 2, 3, 4, 5};
  // 添加key-value
  js["name"] = "zhang san";
  // 添加json对象
  js["msg"]["zhang san"] = "hello world";
  js["msg"]["li si"] = "hello a";
  // 上面等同于这样添加
  // js["msg"] = {{"zhang san", "hello wor"}, {"liu shuo", "hello hi"}};
  cout << js << endl;
  string sendbuf = js.dump();
  return sendbuf;
}
string func3() {
  json js;
  // 直接序列化一个vector容器
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(5);
  js["list"] = vec;
  // 直接序列化一个map容器
  map<int, string> m;
  m.insert({1, "黄山"});
  m.insert({2, "华山"});
  m.insert({3, "泰山"});
  js["path"] = m;
  cout << js << endl;
  string sendbuf = js.dump();
  return sendbuf;
}
int main() {
  //   func3();
  //   string recvString = func1();
  //   json jsbuf = json::parse(recvString);
  //   cout << jsbuf["msg_type"] << endl;
  //   cout << jsbuf["from"] << endl;
  //   cout << jsbuf["to"] << endl;
  //   cout << jsbuf["msg"] << endl;

  //   string recvString = func2();
  //   json jsbuf = json::parse(recvString);
  //   cout << jsbuf["id"] << endl;
  //   auto arr = jsbuf["id"];
  //   cout << arr[0] << endl;
  //   cout << jsbuf["name"] << endl;
  //   cout << jsbuf["msg"] << endl;

  string recvString = func3();
  json jsbuf = json::parse(recvString);
  vector<int> vec = jsbuf["list"];
  for (auto& c : vec) {
    cout << c << " ";
  }
  return 0;
}