#include <string>
#include <iostream>
#include <stack>

std::string simplify_path(std::string A) {
    if (A.size() == 1) {
        return A;
    }

    std::stack<std::string> st;
    std::string cur = "";
    for (int i = 1; i < A.size(); i++) {
        if (cur.empty() && A[i] == '/') {
            continue;
        }
        else {
            cur.push_back(A[i]);    
        }
        if (i == A.size() - 1 && A[i] != '/') {
            cur.push_back('/');
        }

        if (cur.back() == '/' && !cur.empty() && cur.length() > 1) {
            if (cur == "../" && !st.empty() && st.top() != cur) {
                st.pop();
            }
            else if (cur != "./" && cur != "../") {
                st.push(cur);
            }
            cur = "";
        }
    }

    std::string path = "";
    while (!st.empty()) {
        path.append(std::string(st.top().rbegin(), st.top().rend()));
        st.pop();
    }
    if (path.length() > 0) {
        path = std::string(path.rbegin(), path.rend() - 1);
    }
    return "/" + path;
}

int main() {
    std::string A = "/a/./b/../../c/";
    std::cout << simplify_path(A) << std::endl;

    std::string B = "/home/";
    std::cout << simplify_path(B) << std::endl;

    std::string C = "/.";
    std::cout << simplify_path(C) << std::endl;

    std::string D = "/../";
    std::cout << simplify_path(D) << std::endl;

    std::string E = "/home//foo/";
    std::cout << simplify_path(E) << std::endl;

    std::string F = "/./.././ykt/xhp/nka/eyo/blr/emm/xxm/fuv/bjg/./qbd/./../pir/dhu/./../../wrm/grm/ach/jsy/dic/ggz/smq/mhl/./../yte/hou/ucd/vnn/fpf/cnb/ouf/hqq/upz/akr/./pzo/../llb/./tud/olc/zns/fiv/./eeu/fex/rhi/pnm/../../kke/./eng/bow/uvz/jmz/hwb/./././ids/dwj/aqu/erf/./koz/..";
    std::cout << simplify_path(F) << std::endl;
}