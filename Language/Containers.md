## vector

```cpp
std::vector<int> arr {1, 2, 3, 4};
arr.push_back(5);
arr.pop_back();

// 清空 arr
std::vector<int>().swap(arr);

// 逆序
std::reverse(nums.begin(), nums.end());

// 排序 + 去重
std::sort(arr.begin(), arr.end());
std::erase(std::unique(arr.begin(), arr.end()), arr.end());
```

## string

```cpp
std::string s1(3, 'a'); // "aaa"

std::string s2 = "abcdefg";
auto p = s2.find("c");
if (p != string::npos) {
  p = p + 1;
}

auto p = s2.find_first_not_of(" "); // skip all whitespaces
// TODO: more APIs
```

## list

```cpp
std::list<int> lst;
lst.push_back(1);
lst.pop_back();
lst.sort();  // more efficient than std::sort
lst.front();
lst.back();
lst.erase(it);
```

## stack

```cpp
std::stack<int> st;
st.push(1);
while (!q.empty()) {
  auto x = q.top();
  q.pop();
  
  if (do_something) {
    q.push(y);
  }
}
```

## queue

```cpp
std::queue<int> q;
q.push(1);
while (!q.empty()) {
  auto x = q.front();
  q.pop();
  
  if (do_something) {
    q.push(y);
  }
}
```

## deque

```cpp
std::deque<int> dq;
dq.push_front(1);
// [1]
dq.push_back(2);
// [1, 2]
dq.pop_front();
// [2]
dq.pop_back();
// []
```

## priority_queue

```cpp
using pii = std::pair<int, int>;
// 最小堆
std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap;

// 最大堆（默认）
// std::priority_queue<pii, std::vector<pii>, std::less<>> min_heap;
std::priority_queue<pii> max_heap;

while (!min_heap.empty()) {
  auto [x, y] = min_heap.top();
  min_heap.pop();
  
  if (do_something) {
    min_heap.emplace(nx, ny);  // more efficient than push
    // min_heap.push({nx, ny});
  }
}
```

## map (nlogn)

```cpp
std::vector<std::string> occurs {"a", "a", "b", "a", "c", "b"};
std::map<string, int> cnt;
for (auto& x : occurs) {
  ++cnt[x];
}

for (auto [x, c] : cnt) {
  std::cout << x << " -> " << c << std::endl;
}

for (auto it = cnt.find(x); it != cnt.end()) {
  // found x
  int c = it->second;
  // ...
}

// the difference from unordered_map
for (auto it = cnt.lower_bound("b"); it != cnt.end(); ++it) {
  std::cout << it->first << " -> " << it->second << "\n";
}
```

## unordered_map (O(1))

no `lower_bound` or `upper_bound`

## set (nlogn)

```cpp
std::vector<std::string> occurs {"a", "a", "b", "a", "c", "b"};
std::set<std::string> s(occurs.begin(), occurs.end());
std::string x = "b";
if (s.count(x)) {
  std::cout << "find x" << std::endl;
}

// iterate over all items that greater than or equal to x
for (auto it = s.lower_bound(x); it != s.end(); ++it) {
  // ...
}
```

## unordered_set

no `lower_bound` or `upper_bound`