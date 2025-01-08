#ifdef _DEBUG

template <typename T> 
void dbg_out_with_name(string var_name, const T &value) {
    // 前後の空白をトリムする
    var_name.erase(var_name.begin(), find_if(var_name.begin(), var_name.end(), [](unsigned char ch) { return !isspace(ch); }));
    var_name.erase(find_if(var_name.rbegin(), var_name.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), var_name.end());
    cerr << var_name << " = " << value << endl;
}

template <typename T, typename... Args>
void dbg_out_with_name(string var_name, const T &value, const Args &...args) {
    int pos = -1;
    var_name.erase(var_name.begin(), find_if(var_name.begin(), var_name.end(), [](unsigned char ch) { return !isspace(ch); }));
    
    int bracket_count = 0;
    for (size_t i = 0; i < var_name.size(); i++) {
        if (var_name[i] == '(') {
            bracket_count++;
        } else if (var_name[i] == ')') {
            bracket_count--;
        }
        
        // カンマがネストされた括弧の外で見つかる場合のみ分割
        if (var_name[i] == ',' && bracket_count == 0) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) pos = var_name.size();
    cerr << var_name.substr(0, pos) << " = " << value << endl;
    if (pos + 1 < var_name.size()) {
        dbg_out_with_name(var_name.substr(pos + 1), args...);
    }
}

template <typename T> 
void dbg_out(const T &value) { 
    cerr << value << endl; 
}

template <typename T, typename... Args>
void dbg_out(const T &value, const Args &...args) {
    cerr << value << endl;
    dbg_out(args...);
}

#define DBG(...)                       \
    cerr << __LINE__ << " : " << endl; \
    dbg_out(__VA_ARGS__)

#define dbg(...)                       \
    cerr << __LINE__ << " : " << endl; \
    dbg_out_with_name(#__VA_ARGS__, __VA_ARGS__)

#else
#define dbg(...) true
#define DBG(...) true
#endif