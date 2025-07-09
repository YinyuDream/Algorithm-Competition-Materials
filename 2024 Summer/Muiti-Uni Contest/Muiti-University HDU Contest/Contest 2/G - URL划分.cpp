#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// 函数：解析 URL
void parse_url(const string& url, string& protocol, string& network_location, vector<pair<string,string>>& env_vars) {
    // 提取传输协议
    size_t protocol_end = url.find("://");
    protocol = url.substr(0, protocol_end);

    // 提取网络位置
    size_t network_location_start = protocol_end + 3;
    size_t network_location_end = url.find('/', network_location_start);
    network_location = url.substr(network_location_start, network_location_end - network_location_start);

    // 提取路径字符串
    string path = url.substr(network_location_end + 1);

    // 解析环境变量
    env_vars.clear();
    stringstream path_stream(path);
    string part;
    while (getline(path_stream, part, '/')) {
        size_t equal_pos = part.find('=');
        if (equal_pos != string::npos) {
            string key = part.substr(0, equal_pos);
            string value = part.substr(equal_pos + 1);
            env_vars.push_back({key, value});
        }
    }
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // 忽略换行符

    for (int i = 0; i < T; ++i) {
        string url;
        getline(cin, url);

        string protocol;
        string network_location;
        vector<pair<string,string>> env_vars;

        parse_url(url, protocol, network_location, env_vars);

        cout << protocol << endl;
        cout << network_location << endl;
        for (const auto& kv : env_vars) {
            cout << kv.first << "=" << kv.second << endl;
        }
    }

    return 0;
}
