constexpr bool debug = false;

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

constexpr int SYNTAX_ERROR = 1000;
constexpr int DUPLICATE_NAME = 1001;
constexpr int OUT_OF_MEMORY = 1002;
constexpr int SEGMENTATION_FAULT = 1003;

constexpr int INT_OVERFLOW = 2001;
constexpr int FLOAT_OVERFLOW = 2002;

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::string_view;

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using i8 = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long long;
using i128 = signed __int128;

template <typename T> class make_unsigned {};
template <> class make_unsigned<i128> {
public:
    using type = u128;
};
template <> class make_unsigned<i64> {
public:
    using type = u64;
};
template <> class make_unsigned<i32> {
public:
    using type = u32;
};
template <> class make_unsigned<i16> {
public:
    using type = u16;
};
template <> class make_unsigned<i8> {
public:
    using type = u8;
};

using f32 = float;
using f64 = double;

const double u128_upper_bound = std::pow(2, 128);

u128 safe_add(u128 x, u128 y) {
    if (double(x) + double(y) >= u128_upper_bound)
        throw INT_OVERFLOW;
    return x + y;
}

u128 safe_mul(u128 x, u128 y) {
    if (double(x) * double(y) >= u128_upper_bound)
        throw INT_OVERFLOW;
    return x * y;
}

u128 safe_shl(u128 x, int y) {
    assert(y >= 0 && y <= 128);
    u128 bound_mask = (u128(1) << (128 - y)) - 1;
    if ((x & bound_mask) != 0)
        throw INT_OVERFLOW;
    return x << y;
}

u128 round_up(u128 x, u128 y) {
    assert(y != 0);
    return (x + y - 1) / y * y;
}

bool ends_with(const std::string_view& str, const std::string_view& suffix) {
    size_t len1 = str.length(), len2 = suffix.length();
    if (len1 < len2) return false;
    return str.compare(len1 - len2, len2, suffix) == 0;
}

bool ends_with(const std::string_view& str, char suffix) {
    if (str.length() == 0) return false;
    return str.back() == suffix;
}

bool starts_with(const std::string_view& str, const std::string_view& prefix) {
    size_t len1 = str.length(), len2 = prefix.length();
    if (len1 < len2) return false;
    return str.compare(0, len2, prefix) == 0;
}

bool starts_with(const std::string_view& str, char prefix) {
    if (str.length() == 0) return false;
    return str.front() == prefix;
}
namespace io {

std::string_view getline() {
    static std::string line;
    std::getline(cin, line);
    if (debug) cerr << "io::getline: >>" << line << "<<" << endl;
    if (!ends_with(line, ';')) throw SYNTAX_ERROR;
    line.pop_back();
    return line;
}

int __parse_digit(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else
        throw SYNTAX_ERROR;
}

char __to_digit(int x) {
    if (x >= 0 && x <= 9)
        return '0' + x;
    else if (x >= 10 && x <= 35)
        return 'A' + x - 10;
    else
        throw SYNTAX_ERROR;
}

enum NumberBase : int {
    oct = 8,
    dec = 10,
    hex = 16
};

template <NumberBase> std::string prefix();
template <> std::string prefix<oct>() { return "0"; }
template <> std::string prefix<dec>() { return ""; }
template <> std::string prefix<hex>() { return "0x"; }

template <NumberBase base = NumberBase::dec, typename T>
std::ostream& print_unsigned_integer(std::ostream& os, T x) {
    std::string s;
    if (x == 0) s.push_back('0');
    while (x != 0) s.push_back(__to_digit(x % base)), x /= base;
    std::reverse(s.begin(), s.end());
    return os << prefix<base>() << s;
}

template <NumberBase base = NumberBase::dec, typename T>
std::ostream& print_signed_integer(std::ostream& os, T x) {
    using uT = typename make_unsigned<T>::type;
    return x < 0 ? print_unsigned_integer<base, uT>(os << '-', -x) : print_unsigned_integer<base, uT>(os, x);
}

template <NumberBase base, typename T>
T __parse_unsigned_integer(std::string_view view) {
    T x = 0;
    for (auto c : view) {
        auto digit = __parse_digit(c);
        if (digit >= base) throw SYNTAX_ERROR;
        x = x * base + digit;
    }
    return x;
}

template <typename T = u128>
T parse_unsigned_integer(std::string_view view) {
    if (debug) cerr << "parse_unsigned_number: >>" << view << "<<" << endl;
    if (view.empty()) throw SYNTAX_ERROR;
    if (view == "0") return 0;
    if (starts_with(view, "0x")) {
        return __parse_unsigned_integer<NumberBase::hex, T>(view.substr(2));
    } else if (starts_with(view, '0')) {
        return __parse_unsigned_integer<NumberBase::oct, T>(view.substr(1));
    } else {
        return __parse_unsigned_integer<NumberBase::dec, T>(view);
    }
}

template <typename T>
T parse_signed_integer(std::string_view view) {
    if (debug) cerr << "parse_signed_number: >>" << view << "<<" << endl;
    using uT = typename make_unsigned<T>::type;
    return starts_with(view, '-') ? -parse_unsigned_integer<uT>(view.substr(1)) : parse_unsigned_integer<uT>(view);
}
} // namespace io

namespace types {
enum TypeIdentifier : u8 {
    INT8 = 0,
    INT16 = 1,
    INT32 = 2,
    INT64 = 3,
    INT128 = 4,
    UINT8 = 5,
    UINT16 = 6,
    UINT32 = 7,
    UINT64 = 8,
    UINT128 = 9,
    FLOAT16 = 10,
    FLOAT32 = 11,
    FLOAT64 = 12,
    FLOAT128 = 13,
    POINTER = 14,
    ARRAY = 15,
    STRUCT = 16,
    UNION = 17,
    ADDRIMM = 18,
    UNKNOWN = 19,
};

enum TypeSize : int {
    byte = 1,
    word = 2,
    dword = 4,
    qword = 8,
    oword = 16,
};

template <TypeSize, bool> constexpr TypeIdentifier IntIdentifier();
template <TypeSize> constexpr TypeIdentifier FloatIdentifier();

template <> constexpr TypeIdentifier IntIdentifier<TypeSize::byte, true>() { return INT8; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::byte, false>() { return UINT8; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::word, true>() { return INT16; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::word, false>() { return UINT16; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::dword, true>() { return INT32; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::dword, false>() { return UINT32; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::qword, true>() { return INT64; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::qword, false>() { return UINT64; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::oword, true>() { return INT128; }
template <> constexpr TypeIdentifier IntIdentifier<TypeSize::oword, false>() { return UINT128; }

template <> constexpr TypeIdentifier FloatIdentifier<TypeSize::word>() { return FLOAT16; }
template <> constexpr TypeIdentifier FloatIdentifier<TypeSize::dword>() { return FLOAT32; }
template <> constexpr TypeIdentifier FloatIdentifier<TypeSize::qword>() { return FLOAT64; }
template <> constexpr TypeIdentifier FloatIdentifier<TypeSize::oword>() { return FLOAT128; }

class TypeBase {
public:
    u128 size;
    int offset;
    TypeIdentifier idnt;
    bool complete;
    bool defined;

    virtual std::ostream& output(std::ostream& os, bool nested = false) const = 0;
};

std::ostream& operator<<(std::ostream& os, const TypeBase* type) {
    return type->output(os);
}

template <TypeSize Size, bool Signed>
class Int : public TypeBase {
public:
    Int() {
        size = Size, offset = Size;
        idnt = IntIdentifier<Size, Signed>();
        defined = complete = true;
    }

    std::ostream& output(std::ostream& os, bool _nested) const {
        return os << (Signed ? 'i' : 'u') << int(Size) * 8;
    }
};

template <TypeSize Size>
class Float : public TypeBase {
public:
    Float() {
        size = Size, offset = Size;
        idnt = FloatIdentifier<Size>();
        defined = complete = true;
    }

    std::ostream& output(std::ostream& os, bool _nested) const {
        return os << 'f' << int(Size) * 8;
    }
};

std::map<std::string, TypeBase*> primitive_types;
void init_primitive_types() {
    primitive_types["i8"] = new Int<TypeSize::byte, true>(), primitive_types["u8"] = new Int<TypeSize::byte, false>();
    primitive_types["i16"] = new Int<TypeSize::word, true>(), primitive_types["u16"] = new Int<TypeSize::word, false>();
    primitive_types["i32"] = new Int<TypeSize::dword, true>(), primitive_types["u32"] = new Int<TypeSize::dword, false>();
    primitive_types["i64"] = new Int<TypeSize::qword, true>(), primitive_types["u64"] = new Int<TypeSize::qword, false>();
    primitive_types["i128"] = new Int<TypeSize::oword, true>(), primitive_types["u128"] = new Int<TypeSize::oword, false>();
    primitive_types["f16"] = new Float<TypeSize::word>(), primitive_types["f32"] = new Float<TypeSize::dword>();
    primitive_types["f64"] = new Float<TypeSize::qword>(), primitive_types["f128"] = new Float<TypeSize::oword>();
}

bool check_identifier(const std::string& str) {
    if (debug) cerr << "check_identifier: >>" << str << "<<" << endl;
    auto len = str.length();
    if (len == 0) return false;
    // first character must be a letter or '_'
    if (!(isalpha(str[0]) || str[0] == '_')) return false;
    // other characters must be letters or digits or '_'
    for (size_t i = 1; i < len; i++)
        if (!(isalnum(str[i]) || str[i] == '_')) return false;
    if (primitive_types.find(str) != primitive_types.end()) return false;
    return true;
}

class Pointer : public TypeBase {
public:
    TypeBase* ref_type;
    Pointer(TypeBase* ref_type) : ref_type(ref_type) {
        size = 16, offset = 16;
        idnt = TypeIdentifier::POINTER;
        defined = complete = true;
    }

    std::ostream& output(std::ostream& os, bool _nested) const {
        return ref_type->output(os, true) << '*';
    }
};

class AddrImm : public TypeBase {
public:
    TypeBase* ref_type;
    AddrImm(TypeBase* ref_type) : ref_type(ref_type) {
        size = 16, offset = 16;
        idnt = TypeIdentifier::ADDRIMM;
        defined = complete = true;
    }

    std::ostream& output(std::ostream& os, bool _nested) const {
        return ref_type->output(os << '&', true);
    }
};

void mark_parent_type(TypeBase* parent, TypeBase* child);

class Array : public TypeBase {
public:
    u128 length;
    TypeBase* item_type;
    TypeBase* parent_type;
    Array(TypeBase* item_type, u128 length) : item_type(item_type), length(length) {
        idnt = TypeIdentifier::ARRAY;
        defined = true;
        parent_type = nullptr;
        if (item_type->complete) {
            size = safe_mul(item_type->size, length);
            offset = item_type->offset;
            complete = true;
        } else {
            size = 0, offset = 0;
            complete = false;
            mark_parent_type(this, item_type);
        }
    }

    void mark_parent(TypeBase* parent) {
        if (parent_type != nullptr) throw SYNTAX_ERROR;
        parent_type = parent;
    }

    void lazy_init() {
        if (complete || !item_type->complete) throw SYNTAX_ERROR;
        size = safe_mul(item_type->size, length);
        offset = item_type->offset;
        complete = true;
    }

    std::ostream& output(std::ostream& os, bool _nested) const {
        return io::print_unsigned_integer(item_type->output(os, true) << '[', length) << ']';
    }
};

class Group : public TypeBase {
protected:
    std::map<std::string, int> member_keys;
    std::vector<TypeBase*> member_types;
    std::vector<std::string> member_names;
    std::vector<u128> member_offsets;

    virtual std::string group_name() const = 0;

public:
    std::string name;
    std::vector<TypeBase*> parent_types;
    int imcomplete_member_count;
    Group(const std::string& name) : name(name) {
        size = 0, offset = 0;
        defined = complete = false;
        imcomplete_member_count = 0;
    }
    void add_member(std::string_view name_view, TypeBase* type) {
        auto name = std::string(name_view);
        if (!check_identifier(name)) throw SYNTAX_ERROR;
        if (member_keys.find(name) != member_keys.end())
            throw SYNTAX_ERROR;
        member_keys[name] = member_types.size();
        member_types.push_back(type);
        member_names.push_back(name);
        if (!type->complete) {
            mark_parent_type(this, type);
            ++imcomplete_member_count;
        }
    }
    std::pair<TypeBase*, u128> get_member(const string_view& name_view) const {
        if (debug) cerr << "get_member: >>" << name_view << "<<" << endl;
        auto name = std::string(name_view);
        if (member_keys.find(name) == member_keys.end()) throw SYNTAX_ERROR;
        auto index = member_keys.at(name);
        return {member_types[index], member_offsets[index]};
    }

    void append_parent(TypeBase* parent) {
        parent_types.push_back(parent);
    }
    virtual void lazy_init() = 0;

    std::ostream& output(std::ostream& os, bool nested) const override {
        if (nested) return os << name;
        if (!complete) os << "[incomplete, ref = " << imcomplete_member_count << "] ";
        os << group_name() << ' ' << name;
        if (defined) {
            os << " { ";
            for (size_t i = 0, n = member_types.size(); i < n; i++) {
                if (i != 0) os << ", ";
                member_types[i]->output(os, true) << ' ' << member_names[i];
            }
            os << " }";
        }
        return os;
    }
};

class Struct : public Group {
protected:
    std::string group_name() const override { return "struct"; }

public:
    Struct(const std::string& name) : Group(name) { idnt = TypeIdentifier::STRUCT; }
    void lazy_init() override {
        if (complete) throw SYNTAX_ERROR;
        size = 0, offset = 0;
        member_offsets.reserve(member_types.size());
        for (auto type : member_types) {
            if (!type->complete) throw SYNTAX_ERROR;
            size = round_up(size, type->offset);
            offset = std::max(offset, type->offset);
            member_offsets.push_back(size);
            size = safe_add(size, type->size);
        }
        size = round_up(size, offset);
        complete = true;
    }
};

class Union : public Group {
protected:
    std::string group_name() const override { return "union"; }

public:
    Union(const std::string& name) : Group(name) { idnt = TypeIdentifier::UNION; }
    void lazy_init() override {
        if (complete) throw SYNTAX_ERROR;
        size = 0, offset = 0;
        member_offsets.reserve(member_types.size());
        for (auto type : member_types) {
            if (!type->complete) throw SYNTAX_ERROR;
            size = std::max(size, type->size);
            offset = std::max(offset, type->offset);
            member_offsets.push_back(0);
        }
        size = round_up(size, offset);
        complete = true;
    }
};

constexpr bool is_group(const TypeBase* type) {
    return type->idnt == TypeIdentifier::STRUCT || type->idnt == TypeIdentifier::UNION;
}

constexpr bool is_array(const TypeBase* type) {
    return type->idnt == TypeIdentifier::ARRAY;
}

constexpr bool is_pointer(const TypeBase* type) {
    return type->idnt == TypeIdentifier::POINTER;
}

constexpr bool is_addrimm(const TypeBase* type) {
    return type->idnt == TypeIdentifier::ADDRIMM;
}

constexpr bool is_integer(const TypeBase* type) {
    return type->idnt >= TypeIdentifier::INT8 && type->idnt <= TypeIdentifier::UINT128;
}

constexpr bool is_signed(const TypeBase* type) {
    return type->idnt >= TypeIdentifier::INT8 && type->idnt <= TypeIdentifier::INT128;
}

constexpr bool is_float(const TypeBase* type) {
    return type->idnt >= TypeIdentifier::FLOAT16 && type->idnt <= TypeIdentifier::FLOAT128;
}

constexpr bool is_primitive(const TypeBase* type) {
    return type->idnt >= TypeIdentifier::INT8 && type->idnt <= TypeIdentifier::FLOAT128;
}

std::map<std::string, int> group_keys;
std::vector<Group*> groups;

void mark_parent_type(TypeBase* parent, TypeBase* child) {
    switch (child->idnt) {
        case TypeIdentifier::ARRAY: {
            static_cast<Array*>(child)->mark_parent(parent);
            break;
        }
        case TypeIdentifier::STRUCT:
        case TypeIdentifier::UNION: {
            static_cast<Group*>(child)->append_parent(parent);
            break;
        }
        default:
            throw SYNTAX_ERROR;
    }
}
} // namespace types

namespace floating {
using namespace types;

template <typename T>
union bitview {
public:
    T value;
    u8 bytes[sizeof(T)];
    bitview(T value) : value(value) {}
    bool operator[](int i) const {
        if (debug) assert(i >= 0 && i < sizeof(T) * 8);
        return (bytes[i >> 3] >> (i & 7)) & 1;
    }
    bool get(int i) {
        if (i < 0 || i >= sizeof(T) * 8) return false;
        return (bytes[i >> 3] >> (i & 7)) & 1;
    }
    void set(int i) {
        if (debug) assert(i >= 0 && i < sizeof(T) * 8);
        bytes[i >> 3] |= 1 << (i & 7);
    }
    void reset(int i) {
        if (debug) assert(i >= 0 && i < sizeof(T) * 8);
        bytes[i >> 3] &= ~(1 << (i & 7));
    }
    void flip(int i) {
        if (debug) assert(i >= 0 && i < sizeof(T) * 8);
        bytes[i >> 3] ^= 1 << (i & 7);
    }
#define For(i, l, r) for (int i = (l); i < (r); ++i)
    void set(int l, int r) { For(i, l, r) set(i); }
    void reset(int l, int r) { For(i, l, r) reset(i); }
    void flip(int l, int r) { For(i, l, r) flip(i); }
#undef For
};

template <TypeSize> constexpr int exponent_bits = 0;
template <> constexpr int exponent_bits<TypeSize::word> = 5;
template <> constexpr int exponent_bits<TypeSize::dword> = 8;
template <> constexpr int exponent_bits<TypeSize::qword> = 11;
template <> constexpr int exponent_bits<TypeSize::oword> = 15;
template <TypeSize Size> constexpr int mantissa_bits = int(Size) * 8 - 1 - exponent_bits<Size>;
template <TypeSize Size> constexpr int exponent_bias = (1 << (exponent_bits<Size> - 1)) - 1;
template <TypeSize Size> constexpr int exponent_bound = (1 << exponent_bits<Size>)-1;

template <TypeSize Size> constexpr int mantissa_begin = 0;
template <TypeSize Size> constexpr int mantissa_end = mantissa_begin<Size> + mantissa_bits<Size>;
template <TypeSize Size> constexpr int exponent_begin = mantissa_end<Size>;
template <TypeSize Size> constexpr int exponent_end = exponent_begin<Size> + exponent_bits<Size>;
template <TypeSize Size> constexpr int sign_pos = exponent_end<Size>;

template <typename T>
T parse(string_view view) {
    const auto Size = TypeSize(sizeof(T));
    if (debug) cerr << "parse float >>" << view << "<<" << endl;
    bitview<T> result(0);

    if (starts_with(view, '-')) result.set(sizeof(T) * 8 - 1), view.remove_prefix(1);
    if (starts_with(view, '+')) view.remove_prefix(1);
    if (view == "nan" || view == "NaN" || view == "NAN") {
        result.set(exponent_begin<Size>, exponent_end<Size>);
        result.set(mantissa_begin<Size>, mantissa_end<Size>);
        return result.value; // NaN
    }
    if (view == "inf" || view == "Inf" || view == "INF") {
        result.set(exponent_begin<Size>, exponent_end<Size>);
        return result.value; // Inf
    }

    if (!starts_with(view, "0x")) throw SYNTAX_ERROR;
    view.remove_prefix(2);

    auto delim_pos = view.rfind('p');
    if (delim_pos == string_view::npos) throw SYNTAX_ERROR;

    auto mantissa = view.substr(0, delim_pos);
    auto exponent = view.substr(delim_pos + 1);
    if (debug) cerr << "mantissa >>" << mantissa << "<<" << endl;
    if (debug) cerr << "exponent >>" << exponent << "<<" << endl;
    if (starts_with(mantissa, '0')) {
        if (mantissa != "0" || exponent != "0") throw SYNTAX_ERROR;
        return result.value; // 0
    }

    if (debug) cerr << "expoent_bias: " << exponent_bias<Size> << endl;
    auto exp = io::parse_signed_integer<i32>(exponent) * 4 + exponent_bias<Size>;
    std::vector<bool> frac_bits;
    delim_pos = mantissa.find('.');

    auto main_part = delim_pos == string_view::npos ? mantissa : mantissa.substr(0, delim_pos);
    auto frac_part = delim_pos == string_view::npos ? "" : mantissa.substr(delim_pos + 1);
    if (debug) cerr << "main_part >>" << main_part << "<<" << endl;
    if (debug) cerr << "frac_part >>" << frac_part << "<<" << endl;

    if (main_part.length() < 1) throw SYNTAX_ERROR;
    for (auto v = io::__parse_digit(main_part[0]); v > 0; v >>= 1) frac_bits.push_back(v & 1);
    std::reverse(frac_bits.begin(), frac_bits.end());
    main_part.remove_prefix(1);
    for (auto c : main_part)
        for (auto v = io::__parse_digit(c), i = 3; i >= 0; --i) frac_bits.push_back((v >> i) & 1);
    exp += frac_bits.size() - 1;
    for (auto c : frac_part)
        for (auto v = io::__parse_digit(c), i = 3; i >= 0; --i) frac_bits.push_back((v >> i) & 1);
    while (frac_bits.back() == false) frac_bits.pop_back();

    if (debug) cerr << "exp: " << int(exp) << endl;
    if (debug) {
        cerr << "frac_bits: ";
        for (auto b : frac_bits) cerr << b;
        cerr << endl;
    }
    if (exp >= exponent_bound<Size>) throw FLOAT_OVERFLOW;
    if (exp > 0) {
        if (frac_bits.size() - 1 > mantissa_bits<Size>) throw FLOAT_OVERFLOW;
        // regular form
        for (int i = exponent_begin<Size>; exp; ++i, exp >>= 1)
            if (exp & 1) result.set(i);
        for (int j = 1; j < frac_bits.size(); ++j)
            if (frac_bits[j]) result.set(mantissa_end<Size> - j);
    } else {
        // irregular form
        if (frac_bits.size() - exp > mantissa_bits<Size>) throw FLOAT_OVERFLOW;
        for (int j = 0, i = mantissa_end<Size> - 1 + exp; j < frac_bits.size(); ++j, --i)
            if (frac_bits[j]) result.set(i);
    }

    return result.value;
}

template <typename T>
std::ostream& print(std::ostream& os, T value) {
    const auto Size = TypeSize(sizeof(T));
    bitview<T> view(value);

    int exponent = 0;
    for (int i = exponent_end<Size> - 1; i >= exponent_begin<Size>; --i) exponent = exponent << 1 | int(view[i]);
    if (debug) cerr << "expoent: " << exponent << endl;
    if (view[sign_pos<Size>]) os << '-';
    if (exponent == exponent_bound<Size>) {
        bool isNaN = false;
        for (int i = mantissa_begin<Size>; i < mantissa_end<Size>; ++i) isNaN |= view[i];
        return os << (isNaN ? "nan" : "inf");
    }

    exponent -= exponent_bias<Size>;
    os << "0x";
    int i = mantissa_end<Size> - 1;
    if (exponent == -exponent_bias<Size>) {
        // irregular form
        while (i >= mantissa_begin<Size> && !view[i]) --i, --exponent;
        if (i < mantissa_begin<Size>) return os << "0p0";
        --i;
    }
    // regular form
    int v = 1;
    while (exponent % 4) v = v << 1 | int(view.get(i--)), --exponent;
    os << io::__to_digit(v);
    string frac_str;
    for (; i >= mantissa_begin<Size>; i -= 4) {
        v = 0;
        for (int j = 0; j < 4; ++j) v = v << 1 | (i - j >= 0 ? int(view.get(i - j)) : 0);
        frac_str.push_back(io::__to_digit(v));
    }
    while (!frac_str.empty() && frac_str.back() == '0') frac_str.pop_back();
    if (!frac_str.empty()) os << '.' << frac_str;
    return io::print_signed_integer<io::NumberBase::dec>(os << 'p', exponent / 4);
}
} // namespace floating

namespace heap {
using types::TypeBase;
using types::TypeSize;

const u128 heap_bound = u128(1) << 100;
u128 heap_size = 0;
std::set<u128> fragments[16];

u128 alloc(u128 size, int offset) {
    if (debug) io::print_unsigned_integer(cerr << "alloc size = ", size) << " offset = " << offset << endl;
    // try alloc in fragments
    if (size < 16) {
        u128 min_addr = heap_bound;
        int fragment_size = 0;
        for (int s = size; s < 16; ++s) {
            if (!fragments[s].empty()) {
                auto candidate = *fragments[s].begin();
                if (candidate < min_addr) min_addr = candidate, fragment_size = s;
            }
        }
        if (min_addr != heap_bound) {
            fragments[fragment_size].erase(min_addr);
            auto actual_addr = round_up(min_addr, offset);
            if (actual_addr != min_addr) fragments[actual_addr - min_addr].insert(min_addr);
            auto actual_end = actual_addr + size;
            auto fragment_end = min_addr + fragment_size;
            if (actual_end != fragment_end) fragments[fragment_end - actual_end].insert(actual_end);
            return actual_addr;
        }
    }
    auto actual_addr = round_up(heap_size, offset);
    auto tmp_heap_size = safe_add(actual_addr, size);
    if (tmp_heap_size > heap_bound) throw OUT_OF_MEMORY;

    if (actual_addr != heap_size)
        fragments[actual_addr - heap_size].insert(heap_size);
    heap_size = tmp_heap_size;
    return actual_addr;
}

std::map<std::string, int> var_keys;
std::vector<TypeBase*> var_types;
std::vector<u128> var_addrs;
std::vector<std::string> var_names;

bool check_var_name(const std::string& name) {
    if (!types::check_identifier(name)) return false;
    if (types::group_keys.count(name)) return false;
    return var_keys.find(name) == var_keys.end();
}

void insert_var(TypeBase* type, const string& name, u128 addr) {
    var_keys[name] = var_types.size();
    var_types.push_back(type);
    var_addrs.push_back(addr);
    var_names.push_back(name);
}

std::pair<TypeBase*, u128> get_var(const string& name) {
    auto found = var_keys.find(name);
    if (found == var_keys.end()) throw SYNTAX_ERROR;
    return {var_types[found->second], var_addrs[found->second]};
}

std::map<u128, u8> data;

u8 __read(u128 addr) {
    auto found = data.find(addr);
    if (found == data.end()) return 0;
    return found->second;
}

template <TypeSize Size>
void read(u128 addr, u8 res[Size]) {
    if (addr % Size != 0 || addr + Size > heap_bound) throw SEGMENTATION_FAULT;
    for (int i = 0; i < Size; ++i)
        res[i] = __read(addr + i);
}

template <TypeSize Size>
void write(u128 addr, const u8 src[Size]) {
    if (addr % Size != 0 || addr + Size > heap_bound) throw SEGMENTATION_FAULT;
    for (int i = 0; i < Size; ++i)
        data[addr + i] = src[i];
}

template <typename T>
void write_value(u128 addr, T value) {
    union {
        u8 bytes[sizeof(T)];
        T value;
    } buf;
    buf.value = value;
    write<TypeSize(sizeof(T))>(addr, buf.bytes);
}

template <typename T>
T read_value(u128 addr) {
    union {
        u8 bytes[sizeof(T)];
        T value;
    } buf;
    read<TypeSize(sizeof(T))>(addr, buf.bytes);
    return buf.value;
}

auto read_u128 = read_value<u128>;

std::ostream& read_integer(std::ostream& os, u128 addr, TypeBase* type) {
    using io::print_signed_integer;
    using io::print_unsigned_integer;
    auto is_signed = types::is_signed(type);
    auto size = type->size;
    switch (size) {
        case TypeSize::byte: return is_signed ? print_signed_integer(os, read_value<i8>(addr)) : print_unsigned_integer(os, read_value<u8>(addr));
        case TypeSize::word: return is_signed ? print_signed_integer(os, read_value<i16>(addr)) : print_unsigned_integer(os, read_value<u16>(addr));
        case TypeSize::dword: return is_signed ? print_signed_integer(os, read_value<i32>(addr)) : print_unsigned_integer(os, read_value<u32>(addr));
        case TypeSize::qword: return is_signed ? print_signed_integer(os, read_value<i64>(addr)) : print_unsigned_integer(os, read_value<u64>(addr));
        case TypeSize::oword: return is_signed ? print_signed_integer(os, read_value<i128>(addr)) : print_unsigned_integer(os, read_value<u128>(addr));
        default: throw SYNTAX_ERROR;
    }
}

void write_integer(u128 addr, TypeBase* type, string_view value_view) {
    using io::parse_signed_integer;
    using io::parse_unsigned_integer;
    auto is_signed = types::is_signed(type);
    auto size = type->size;
    switch (size) {
        case TypeSize::byte: return is_signed ? write_value(addr, parse_signed_integer<i8>(value_view)) : write_value(addr, parse_unsigned_integer<u8>(value_view));
        case TypeSize::word: return is_signed ? write_value(addr, parse_signed_integer<i16>(value_view)) : write_value(addr, parse_unsigned_integer<u16>(value_view));
        case TypeSize::dword: return is_signed ? write_value(addr, parse_signed_integer<i32>(value_view)) : write_value(addr, parse_unsigned_integer<u32>(value_view));
        case TypeSize::qword: return is_signed ? write_value(addr, parse_signed_integer<i64>(value_view)) : write_value(addr, parse_unsigned_integer<u64>(value_view));
        case TypeSize::oword: return is_signed ? write_value(addr, parse_signed_integer<i128>(value_view)) : write_value(addr, parse_unsigned_integer<u128>(value_view));
    }
}

std::ostream& read_float(std::ostream& os, u128 addr, TypeBase* type) {
    switch (type->size) {
        case TypeSize::word:
            return floating::print(os, read_value<u16>(addr));
        case TypeSize::dword:
            return floating::print(os, read_value<u32>(addr));
        case TypeSize::qword:
            return floating::print(os, read_value<u64>(addr));
        case TypeSize::oword:
            return floating::print(os, read_value<u128>(addr));
    }
    throw SYNTAX_ERROR;
}

void write_float(u128 addr, TypeBase* type, string_view value) {
    switch (type->size) {
        case TypeSize::word:
            return write_value(addr, floating::parse<u16>(value));
        case TypeSize::dword:
            return write_value(addr, floating::parse<u32>(value));
        case TypeSize::qword:
            return write_value(addr, floating::parse<u64>(value));
        case TypeSize::oword:
            return write_value(addr, floating::parse<u128>(value));
    }
    throw SYNTAX_ERROR;
}
} // namespace heap

namespace stage1 {
void main(int n, int start);
} // namespace stage1
namespace stage2 {
void main(int n, int start);
} // namespace stage2
namespace stage3 {
void main(int n, int start);
} // namespace stage3

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;
    std::cin.ignore(); // ignore the newline
    stage1::main(n1, 2);
    stage2::main(n2, n1 + 2);
    stage3::main(n3, n1 + n2 + 2);
    return 0;
}

namespace stage1 {
using namespace types;

Group* declare(const string_view& line) {
    Group* group = nullptr;
    if (starts_with(line, "union ")) {
        auto group_name = string(line.substr(6));
        if (!check_identifier(group_name)) throw SYNTAX_ERROR;
        auto found = group_keys.find(group_name);
        if (found == group_keys.end()) {
            group_keys[group_name] = groups.size();
            groups.push_back(group = new Union(group_name));
        } else {
            group = groups[found->second];
            if (group->idnt != TypeIdentifier::UNION)
                throw SYNTAX_ERROR;
        }
    } else if (starts_with(line, "struct ")) {
        auto group_name = string(line.substr(7));
        if (!check_identifier(group_name)) throw SYNTAX_ERROR;
        auto found = group_keys.find(group_name);
        if (found == group_keys.end()) {
            group_keys[group_name] = groups.size();
            groups.push_back(group = new Struct(group_name));
        } else {
            group = groups[found->second];
            if (group->idnt != TypeIdentifier::STRUCT)
                throw SYNTAX_ERROR;
        }
    } else
        throw SYNTAX_ERROR;

    return group;
}

TypeBase* parse_type_name(const string_view& view) {
    if (debug) cerr << "stage1::parse_type_name: >>" << view << "<<" << endl;
    auto name = string(view);
    if (primitive_types.count(name)) return primitive_types[name];
    auto found = group_keys.find(name);
    if (found == group_keys.end()) throw SYNTAX_ERROR;
    return groups[found->second];
}

TypeBase* parse_type(const string_view& view) {
    if (debug) cerr << "stage1::parse_type: >>" << view << "<<" << endl;
    auto delim_pos1 = view.find('['), delim_pos2 = view.find('*');
    size_t reached_pos = 0;

    // step 1: parse main typename
    if (delim_pos1 == string_view::npos) {
        reached_pos = (delim_pos2 == string_view::npos) ? view.length() : delim_pos2;
    } else {
        reached_pos = (delim_pos2 == string_view::npos) ? delim_pos1 : std::min(delim_pos1, delim_pos2);
    }
    TypeBase* type = parse_type_name(view.substr(0, reached_pos));

    // step 2: parse array or pointer
    while (delim_pos1 != string_view::npos || delim_pos2 != string_view::npos) {
        if (delim_pos2 == string_view::npos || (delim_pos1 != string_view::npos && delim_pos1 < delim_pos2)) {
            // parse array
            auto right_pos = view.find(']', delim_pos1 + 1);
            auto length = io::parse_unsigned_integer(view.substr(delim_pos1 + 1, right_pos - delim_pos1 - 1));
            type = new Array(type, length);
            delim_pos1 = view.find('[', reached_pos = right_pos + 1);
        } else {
            // parse pointer
            type = new Pointer(type);
            delim_pos2 = view.find('*', reached_pos = delim_pos2 + 1);
        }
    }
    if (reached_pos != view.length()) throw SYNTAX_ERROR;

    return type;
}

void add_member(Group* group, const string_view& view) {
    if (debug) cerr << "stage1::add_member: >>" << view << "<<" << endl;
    auto delim_pos = view.find(' ');
    if (delim_pos == string_view::npos) throw SYNTAX_ERROR;
    auto type = parse_type(view.substr(0, delim_pos));
    auto name = view.substr(delim_pos + 1);
    group->add_member(name, type);
}

Group* define(const string_view& line) {
    auto head_pos = line.find('{');
    if (head_pos == string_view::npos) throw SYNTAX_ERROR;
    auto group = declare(line.substr(0, head_pos - 1));
    if (group->defined) throw SYNTAX_ERROR;

    auto tail_pos = line.find(',', head_pos + 1);
    for (; tail_pos != string_view::npos; head_pos = tail_pos, tail_pos = line.find(',', head_pos + 1))
        add_member(group, line.substr(head_pos + 2, tail_pos - head_pos - 2));
    if (line.length() <= head_pos + 4) throw SYNTAX_ERROR; // no member
    add_member(group, line.substr(head_pos + 2, line.length() - head_pos - 4));
    group->defined = true;
    return group;
}

std::queue<TypeBase*> que;
void check_enqueue(TypeBase* type) {
    switch (type->idnt) {
        case TypeIdentifier::ARRAY: {
            que.push(type);
            break;
        }
        case TypeIdentifier::UNION:
        case TypeIdentifier::STRUCT: {
            auto group = static_cast<Group*>(type);
            if (--group->imcomplete_member_count == 0) que.push(group);
            break;
        }
        default:
            throw SYNTAX_ERROR;
    }
}

void check_completeness() {
    for (auto group : groups) {
        if (debug) cerr << group << ";" << endl;
        if (group->imcomplete_member_count == 0 && group->defined) que.push(group);
    }

    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        if (debug) cerr << "top = " << top << endl;
        switch (top->idnt) {
            case TypeIdentifier::ARRAY: {
                auto array = static_cast<Array*>(top);
                array->lazy_init();
                if (array->parent_type != nullptr) check_enqueue(array->parent_type);
                break;
            }
            case TypeIdentifier::UNION:
            case TypeIdentifier::STRUCT: {
                auto group = static_cast<Group*>(top);
                group->lazy_init();
                for (auto parent : group->parent_types) check_enqueue(parent);
                group->parent_types.clear();
                break;
            }
            default:
                throw SYNTAX_ERROR;
        }
    }

    for (auto group : groups) {
        if (debug) cerr << group << ";" << endl;
        if (debug) io::print_unsigned_integer(cerr << "\tsize = ", group->size);
        if (debug) io::print_unsigned_integer(cerr << "\toffset = ", group->offset) << endl;
        if (!(group->complete && group->defined)) {
            cout << "incomplete type " << group->name << endl;
            exit(0);
        }
    }

    for (auto group : groups) {
        cout << group->name << ' ';
        io::print_unsigned_integer(cout, group->size) << ' ';
        io::print_unsigned_integer(cout, group->offset) << '\n';
    }
}
void main(int n, int start) {
    init_primitive_types();
    for (int i = 0; i < n; i++) {
        try {
            auto line = io::getline();
            if (ends_with(line, "}"))
                define(line);
            else
                declare(line);
        } catch (int err) {
            switch (err) {
                case SYNTAX_ERROR:
                    cout << "syntax error on line " << i + start << endl;
                    exit(0);
                default: {
                    cerr << "unknown error, code: " << err << endl;
                    exit(1);
                }
            }
        }
    }
    check_completeness();
}
} // namespace stage1

namespace stage2 {
void alloc(const string_view& line) {
    auto delim_pos = line.find(' ');
    if (delim_pos == string_view::npos) throw SYNTAX_ERROR;
    auto type = stage1::parse_type(line.substr(0, delim_pos));
    auto name = string(line.substr(delim_pos + 1));
    if (!heap::check_var_name(name)) throw SYNTAX_ERROR;
    try {
        auto addr = heap::alloc(type->size, type->offset);
        heap::insert_var(type, name, addr);
        io::print_unsigned_integer<io::NumberBase::hex>(cout, addr) << '\n';
    } catch (int err) {
        if (err == OUT_OF_MEMORY)
            cout << "memory allocation failed for " << name << '\n';
        else
            throw err;
    }
}

void main(int n, int start) {
    for (int i = 0; i < n; i++) {
        try {
            auto line = io::getline();
            if (starts_with(line, "alloc"))
                alloc(line.substr(6));
            else
                throw SYNTAX_ERROR;
        } catch (int err) {
            switch (err) {
                case SYNTAX_ERROR:
                    cout << "syntax error on line " << i + start << '\n';
                    break;
                default: {
                    cerr << "unknown error, code: " << err << endl;
                    exit(1);
                }
            }
        }
    }
}
} // namespace stage2

namespace stage3 {
using namespace types;

using WalkResult = std::pair<TypeBase*, u128>;

void check_pointer(const WalkResult& child) {
    if (is_pointer(child.first)) {
        auto pointer = static_cast<Pointer*>(child.first);
        auto ref_type = pointer->ref_type;
        auto ref_addr = heap::read_u128(child.second);
        if (ref_addr % ref_type->offset != 0) throw SEGMENTATION_FAULT;
        if (safe_add(ref_addr, ref_type->size) > heap::heap_bound) throw SEGMENTATION_FAULT;
    }
}

WalkResult build_array(const WalkResult& child, u128 index) {
    if (!is_array(child.first)) throw SYNTAX_ERROR;
    auto array = static_cast<Array*>(child.first);
    if (index >= array->length) throw SEGMENTATION_FAULT;
    return {array->item_type, child.second + array->item_type->size * index};
}

WalkResult build_star(const WalkResult& child) {
    if (is_pointer(child.first)) {
        auto pointer = static_cast<Pointer*>(child.first);
        auto ref_type = pointer->ref_type;
        auto ref_addr = heap::read_u128(child.second);
        return {ref_type, ref_addr};
    } else if (is_addrimm(child.first)) {
        auto addrImm = static_cast<AddrImm*>(child.first);
        auto ref_type = addrImm->ref_type;
        delete addrImm;
        return {ref_type, child.second};
    } else
        throw SYNTAX_ERROR;
}

WalkResult build_ref(const WalkResult& child) {
    if (is_addrimm(child.first)) throw SYNTAX_ERROR;
    return {new AddrImm(child.first), child.second};
}

WalkResult build_member(const WalkResult& child, const string_view& member_name) {
    if (!is_group(child.first)) throw SYNTAX_ERROR;
    auto group = static_cast<Group*>(child.first);
    auto member = group->get_member(member_name);
    return {member.first, child.second + member.second};
}

WalkResult walk(string_view view) {
    if (debug) cerr << "stage2::walk: >>" << view << "<<" << endl;
    WalkResult res = {nullptr, 0};

    std::stack<char> left;
    while (starts_with(view, '*') || starts_with(view, '&')) left.push(view[0]), view.remove_prefix(1);
    if (view.empty()) throw SYNTAX_ERROR;

    if (debug) cerr << "stage2::walk(1): >>" << view << "<<" << endl;

    if (starts_with(view, '(')) {
        auto rpos = view.rfind(')');
        if (rpos == string_view::npos) throw SYNTAX_ERROR;
        res = walk(view.substr(1, rpos - 1));
        view.remove_prefix(rpos + 1);
    } else {
        size_t idx = 0;
        while (idx < view.length() && view[idx] != '[' && view[idx] != '.') ++idx;
        check_pointer(res = heap::get_var(string(view.substr(0, idx))));
        view.remove_prefix(idx);
    }

    if (debug) cerr << "stage2::walk(2): >>" << view << "<<" << endl;

    while (starts_with(view, '[')) {
        auto rpos = view.find(']');
        if (rpos == string_view::npos) throw SYNTAX_ERROR;
        check_pointer(res = build_array(res, io::parse_unsigned_integer(view.substr(1, rpos - 1))));
        view.remove_prefix(rpos + 1);
    }

    if (debug) cerr << "stage2::walk(3): >>" << view << "<<" << endl;

    while (!left.empty()) {
        if (left.top() == '*')
            check_pointer(res = build_star(res));
        else
            res = build_ref(res);
        left.pop();
    }

    while (!view.empty()) {
        if (starts_with(view, '.')) {
            size_t idx = 1;
            while (idx < view.length() && view[idx] != '[' && view[idx] != '.') ++idx;
            check_pointer(res = build_member(res, view.substr(1, idx - 1)));
            view.remove_prefix(idx);
        } else if (starts_with(view, '[')) {
            auto rpos = view.find(']');
            if (rpos == string_view::npos) throw SYNTAX_ERROR;
            check_pointer(res = build_array(res, io::parse_unsigned_integer(view.substr(1, rpos - 1))));
            view.remove_prefix(rpos + 1);
        } else
            throw SYNTAX_ERROR;
        if (debug) cerr << "stage2::walk(4): >>" << view << "<<" << endl;
    }

    return res;
}

void read(const string_view& line) {
    auto [type, addr] = walk(line);
    switch (type->idnt) {
        case TypeIdentifier::ARRAY: {
            auto array = static_cast<Array*>(type);
            io::print_unsigned_integer<io::NumberBase::dec>(cout << "array[", array->length) << "] at ";
            io::print_unsigned_integer<io::NumberBase::hex>(cout, addr) << '\n';
            break;
        }
        case TypeIdentifier::UNION:
        case TypeIdentifier::STRUCT: {
            auto group = static_cast<Group*>(type);
            cout << group->name << " at ";
            io::print_unsigned_integer<io::NumberBase::hex>(cout, addr) << '\n';
            break;
        }
        case TypeIdentifier::ADDRIMM: {
            auto addrImm = static_cast<AddrImm*>(type);
            cout << "pointer to ";
            io::print_unsigned_integer<io::NumberBase::hex>(cout, addr) << '\n';
            break;
        }
        case TypeIdentifier::POINTER: {
            auto pointer = static_cast<Pointer*>(type);
            cout << "pointer to ";
            io::print_unsigned_integer<io::NumberBase::hex>(cout, heap::read_u128(addr)) << '\n';
            break;
        }
        default: {
            if (!is_primitive(type)) throw SYNTAX_ERROR;
            is_integer(type) ? heap::read_integer(cout, addr, type) : heap::read_float(cout, addr, type);
            cout << '\n';
        }
    }
}

void write(const string_view& line) {
    auto delim_pos = line.find(' ');
    if (delim_pos == string_view::npos || line.substr(delim_pos, 3) != " = ") throw SYNTAX_ERROR;
    auto [type, addr] = walk(line.substr(0, delim_pos));
    auto value = line.substr(delim_pos + 3);
    if (!is_primitive(type)) {
        cout << "cannot write to nonprimitive type\n";
        return;
    }
    is_integer(type) ? heap::write_integer(addr, type, value) : heap::write_float(addr, type, value);
}

void main(int n, int start) {
    for (int i = 0; i < n; i++) {
        try {
            auto line = io::getline();
            if (starts_with(line, "read"))
                read(line.substr(5));
            else if (starts_with(line, "write"))
                write(line.substr(6));
            else
                throw SYNTAX_ERROR;
        } catch (int err) {
            switch (err) {
                case SYNTAX_ERROR:
                case SEGMENTATION_FAULT:
                    cout << "syntax error on line " << i + start << '\n';
                    break;
                default: {
                    cerr << "unknown error, code: " << err << endl;
                    exit(1);
                }
            }
        }
    }
}
} // namespace stage3
